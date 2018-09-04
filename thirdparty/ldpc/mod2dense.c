/* MOD2DENSE.C - Procedures for handling dense mod2 matrices. */

/* Copyright (c) 1995-2012 by Radford M. Neal.
 *
 * Permission is granted for anyone to copy, use, modify, and distribute
 * these programs and accompanying documents for any purpose, provided
 * this copyright notice is retained and prominently displayed, and note
 * is made of any changes made to these programs.  These programs and
 * documents are distributed without any warranty, express or implied.
 * As the programs were written for research purposes only, they have not
 * been tested to the degree that would be advisable in any important
 * application.  All use of these programs is entirely at the user's own
 * risk.
 */


/* NOTE:  See mod2dense.html for documentation on these procedures. */


#include "boxing/platform/memory.h"

#include <stdio.h>
#include <math.h>

#include "alloc.h"
#include "intio.h"
#include "mod2dense.h"


/**
 * @brief ALLOCATE SPACE FOR A DENSE MOD2 MATRIX.
 *
 * @param n_rows   Number of rows in matrix
 * @param n_cols   Number of columns in matrix
 * @return alloacted spase mod2 matrix
 */

mod2dense *mod2dense_allocate(int n_rows, int n_cols)
{
    mod2dense *m;
    int j;

    if (n_rows <= 0 || n_cols <= 0)
    {
        fprintf(stderr, "mod2dense_allocate: Invalid number of rows or columns\n");
        exit(1);
    }

    m = chk_alloc(1, sizeof *m);

    m->n_rows = n_rows;
    m->n_cols = n_cols;

    m->n_words = (n_rows + mod2_wordsize - 1) >> mod2_wordsize_shift;

    m->col = chk_alloc(m->n_cols, sizeof *m->col);

    m->bits = chk_alloc(m->n_words*m->n_cols, sizeof *m->bits);

    for (j = 0; j < m->n_cols; j++)
    {
        m->col[j] = m->bits + j*m->n_words;
    }

    return m;
}


/**
 * FREE SPACE OCCUPIED BY A DENSE MOD2 MATRIX. 
 * 
 * @param m    matrix to free
 */

void mod2dense_free(mod2dense *m)
{
    boxing_memory_free(m->bits);
    boxing_memory_free(m->col);
    boxing_memory_free(m);
}


/**
 * @brief CLEAR A DENSE MOD2 MATRIX.
 *
 * @param r         matrix to clear
 */

void mod2dense_clear(mod2dense *r)
{
    int k, j;

    for (j = 0; j<mod2dense_cols(r); j++)
    {
        for (k = 0; k < r->n_words; k++)
        {
            r->col[j][k] = 0;
        }
    }

}


/**
 * @brief COPY A DENSE MOD2 MATRIX.
 *
 * m     Matrix to copy
 * r     Place to store copy of matrix
 */

void mod2dense_copy(mod2dense *m, mod2dense *r)
{
    int k, j;

    if (mod2dense_rows(m) > mod2dense_rows(r)
        || mod2dense_cols(m) > mod2dense_cols(r))
    {
        fprintf(stderr, "mod2dense_copy: Destination matrix is too small\n");
        exit(1);
    }

    for (j = 0; j < mod2dense_cols(m); j++)
    {
        for (k = 0; k < m->n_words; k++)
        {
            r->col[j][k] = m->col[j][k];
        }
        for (; k < r->n_words; k++)
        {
            r->col[j][k] = 0;
        }
    }

    for (; j < mod2dense_cols(r); j++)
    {
        for (k = 0; k < r->n_words; k++)
        {
            r->col[j][k] = 0;
        }
    }
}


/**
 * @brief COPY ROWS OF A DENSE MOD2 MATRIX.
 *
 * @param m       Matrix to copy
 * @param r       Place to store copy of matrix
 * @param rows    Indexes of rows to copy, from 0
 */

void mod2dense_copyrows(mod2dense *m, mod2dense *r, int *rows)
{
    int i, j;

    if (mod2dense_cols(m) > mod2dense_cols(r))
    {
        fprintf(stderr,
            "mod2dense_copyrows: Destination matrix has fewer columns than source\n");
        exit(1);
    }

    mod2dense_clear(r);

    for (i = 0; i < mod2dense_rows(r); i++)
    {
        if (rows[i] < 0 || rows[i] >= mod2dense_rows(m))
        {
            fprintf(stderr, "mod2dense_copyrows: Row index out of range\n");
            exit(1);
        }
        for (j = 0; j < mod2dense_cols(m); j++)
        {
            mod2dense_set(r, i, j, mod2dense_get(m, rows[i], j));
        }
    }
}


/**
 * @brief COPY COLUMNS OF A DENSE MOD2 MATRIX.
 *
 * @param m        Matrix to copy
 * @param r        Place to store copy of matrix
 * @param cols     Indexes of columns to copy, from 0
 */

void mod2dense_copycols(mod2dense *m, mod2dense *r, int *cols)
{
    int k, j;

    if (mod2dense_rows(m) > mod2dense_rows(r))
    {
        fprintf(stderr,
            "mod2dense_copycols: Destination matrix has fewer rows than source\n");
        exit(1);
    }

    for (j = 0; j < mod2dense_cols(r); j++)
    {
        if (cols[j] < 0 || cols[j] >= mod2dense_cols(m))
        {
            fprintf(stderr, "mod2dense_copycols: Column index out of range\n");
            exit(1);
        }
        for (k = 0; k < m->n_words; k++)
        {
            r->col[j][k] = m->col[cols[j]][k];
        }
        for (; k < r->n_words; k++)
        {
            r->col[j][k] = 0;
        }
    }
}


/**
 * @brief PRINT A DENSE MOD2 MATRIX IN HUMAN-READABLE FORM.
 *
 *
 * @param f    file handle to print to
 * @param m    matrix to print
 */

void mod2dense_print(FILE *f, mod2dense *m)
{
    int i, j;

    for (i = 0; i < mod2dense_rows(m); i++)
    {
        for (j = 0; j < mod2dense_cols(m); j++)
        {
            fprintf(f, " %d", mod2dense_get(m, i, j));
        }
        fprintf(f, "\n");
    }
}


/**
 * @brief WRITE A DENSE MOD2 MATRIX TO A FILE IN MACHINE-READABLE FORM.
 *
 * Data is written using intio_write, so that it will be readable on a machine
 * with a different byte-ordering.  At present, this assumes that the words
 * used to pack bits into are no longer than 32 bits. 
 *
 * @param f     file handle to write to
 * @param m     matrix to write
 * @return 1 on success or 0 on error
 */

int mod2dense_write(FILE *f, mod2dense *m)
{
    int j, k;

    intio_write(f, m->n_rows);
    if (ferror(f)) return 0;

    intio_write(f, m->n_cols);
    if (ferror(f)) return 0;

    for (j = 0; j < mod2dense_cols(m); j++)
    {
        for (k = 0; k < m->n_words; k++)
        {
            intio_write(f, m->col[j][k]);
            if (ferror(f)) return 0;
        }
    }

    return 1;
}


/**
 * @brief READ A DENSE MOD2 MATRIX STORED IN MACHINE-READABLE FORM FROM A FILE. 
 *
 * @param f   file handle to read from
 * @retuirn dense mod2 matrix on success or NULL on error
 */

mod2dense *mod2dense_read(FILE *f)
{
    int n_rows, n_cols;
    mod2dense *m;
    int j, k;

    n_rows = intio_read(f);
    if (feof(f) || ferror(f) || n_rows <= 0) return 0;

    n_cols = intio_read(f);
    if (feof(f) || ferror(f) || n_cols <= 0) return 0;

    m = mod2dense_allocate(n_rows, n_cols);

    for (j = 0; j < mod2dense_cols(m); j++)
    {
        for (k = 0; k < m->n_words; k++)
        {
            m->col[j][k] = intio_read(f);
            if (feof(f) || ferror(f))
            {
                mod2dense_free(m);
                return 0;
            }
        }
    }

    return m;
}


/**
 * @brief GET AN ELEMENT FROM A DENSE MOD2 MATRIX.
 *
 * @param m     Matrix to get element from
 * @param row   Row of element (starting with zero)
 * @param col   Column of element (starting with zero)
 * @return the element value
 */

int mod2dense_get(mod2dense *m, int row, int col)
{
    if (row < 0 || row >= mod2dense_rows(m) || col < 0 || col >= mod2dense_cols(m))
    {
        fprintf(stderr, "mod2dense_get: row or column index out of bounds\n");
        exit(1);
    }

    return mod2_getbit(m->col[col][row >> mod2_wordsize_shift],
        row&mod2_wordsize_mask);
}


/**
 * @brief SET AN ELEMENT IN A DENSE MOD2 MATRIX.
 *
 * @param m         Matrix to modify element of
 * @param row       Row of element (starting with zero)
 * @param col       Column of element (starting with zero)
 * @param value     New value of element (0 or 1)
 */

void mod2dense_set(mod2dense *m, int row, int col, int value)
{
    mod2word *w;

    if (row < 0 || row >= mod2dense_rows(m) || col < 0 || col >= mod2dense_cols(m))
    {
        fprintf(stderr, "mod2dense_set: row or column index out of bounds\n");
        exit(1);
    }

    w = &m->col[col][row >> mod2_wordsize_shift];

    *w = value ? mod2_setbit1(*w, row&mod2_wordsize_mask)
        : mod2_setbit0(*w, row&mod2_wordsize_mask);
}


/**
 * @brief FLIP AN ELEMENT OF A DENSE MOD2 MATRIX.
 *
 * @param m       Matrix to flip element in
 * @param row     Row of element (starting with zero)
 * @param col     Column of element (starting with zero)
 * @return the element's old value
 */

int mod2dense_flip(mod2dense *m, int row, int col)
{
    mod2word *w;
    int b;

    if (row < 0 || row >= mod2dense_rows(m) || col < 0 || col >= mod2dense_cols(m))
    {
        fprintf(stderr, "mod2dense_flip: row or column index out of bounds\n");
        exit(1);
    }

    b = 1 ^ mod2_getbit(m->col[col][row >> mod2_wordsize_shift],
        row&mod2_wordsize_mask);

    w = &m->col[col][row >> mod2_wordsize_shift];

    *w = b ? mod2_setbit1(*w, row&mod2_wordsize_mask)
        : mod2_setbit0(*w, row&mod2_wordsize_mask);

    return b;
}


/**
 * @brief COMPUTE THE TRANSPOSE OF A DENSE MOD2 MATRIX.
 *
 * @param m          Matrix to compute transpose of (left unchanged)
 * @param r          Result of transpose operation
 */

void mod2dense_transpose(mod2dense *m, mod2dense *r)
{
    mod2word w, v, *p;
    int k1, j1, i2, j2;

    if (mod2dense_rows(m) != mod2dense_cols(r)
        || mod2dense_cols(m) != mod2dense_rows(r))
    {
        fprintf(stderr,
            "mod2dense_transpose: Matrices have incompatible dimensions\n");
        exit(1);
    }

    if (r == m)
    {
        fprintf(stderr,
            "mod2dense_transpose: Result matrix is the same as the operand\n");
        exit(1);
    }

    mod2dense_clear(r);

    for (j1 = 0; j1 < mod2dense_cols(m); j1++)
    {
        i2 = j1 >> mod2_wordsize_shift;
        v = 1 << (j1 & mod2_wordsize_mask);

        p = m->col[j1];
        k1 = 0;
        w = 0;
        for (j2 = 0; j2 < mod2dense_cols(r); j2++)
        {
            if (k1 == 0)
            {
                w = *p++;
                k1 = mod2_wordsize;
            }
            if (w & 1)
            {
                r->col[j2][i2] |= v;
            }
            w >>= 1;
            k1 -= 1;
        }
    }
}


/**
 * @brief ADD TWO DENSE MOD2 MATRICES. 
 *
 * @param m1    Left operand of add
 * @param m2    Right operand of add
 * @param r     Place to store result of add
 */

void mod2dense_add(mod2dense *m1, mod2dense *m2, mod2dense *r)
{
    int j, k;

    if (mod2dense_rows(m1) != mod2dense_rows(r)
        || mod2dense_cols(m1) != mod2dense_cols(r)
        || mod2dense_rows(m2) != mod2dense_rows(r)
        || mod2dense_cols(m2) != mod2dense_cols(r))
    {
        fprintf(stderr, "mod2dense_add: Matrices have different dimensions\n");
        exit(1);
    }

    for (j = 0; j < mod2dense_cols(r); j++)
    {
        for (k = 0; k < r->n_words; k++)
        {
            r->col[j][k] = m1->col[j][k] ^ m2->col[j][k];
        }
    }
}


/**
 * @brief MULTIPLY TWO DENSE MOD2 MATRICES.
 *
 * The algorithm used runs faster if the second matrix (right operand of the
 * multiply) is sparse, but it is also appropriate for dense matrices.  This
 * procedure could be speeded up a bit by replacing the call of mod2dense_get
 * with in-line code that avoids division, but this doesn't seem worthwhile
 * at the moment.
 *
 * @param m1      Left operand of multiply
 * @param m2      Right operand of multiply
 * @param r       Place to store result of multiply
 */

void mod2dense_multiply(mod2dense *m1, mod2dense *m2, mod2dense *r)
{
    int i, j, k;

    if (mod2dense_cols(m1) != mod2dense_rows(m2)
        || mod2dense_rows(m1) != mod2dense_rows(r)
        || mod2dense_cols(m2) != mod2dense_cols(r))
    {
        fprintf(stderr,
            "mod2dense_multiply: Matrices have incompatible dimensions\n");
        exit(1);
    }

    if (r == m1 || r == m2)
    {
        fprintf(stderr,
            "mod2dense_multiply: Result matrix is the same as one of the operands\n");
        exit(1);
    }

    mod2dense_clear(r);

    for (j = 0; j < mod2dense_cols(r); j++)
    {
        for (i = 0; i < mod2dense_rows(m2); i++)
        {
            if (mod2dense_get(m2, i, j))
            {
                for (k = 0; k < r->n_words; k++)
                {
                    r->col[j][k] ^= m1->col[i][k];
                }
            }
        }
    }
}


/**
 * @brief SEE WHETHER TWO DENSE MOD2 MATRICES ARE EQUAL.
 *
 * @param m1 matrix to compare
 * @param m2 matrix to compare
 * @return 1 if they are equal, othervise 0 is returned
 */

int mod2dense_equal(mod2dense *m1, mod2dense *m2)
{
    int k, j, w;
    mod2word m;

    if (mod2dense_rows(m1) != mod2dense_rows(m2)
        || mod2dense_cols(m1) != mod2dense_cols(m2))
    {
        fprintf(stderr, "mod2dense_equal: Matrices have different dimensions\n");
        exit(1);
    }

    w = m1->n_words;

    /* Form a mask that has 1s in the lower bit positions corresponding to
       bits that contain information in the last word of a matrix column. */

    m = (1 << (mod2_wordsize - (w*mod2_wordsize - m1->n_rows))) - 1;

    for (j = 0; j < mod2dense_cols(m1); j++)
    {
        for (k = 0; k < w - 1; k++)
        {
            if (m1->col[j][k] != m2->col[j][k]) return 0;
        }

        if ((m1->col[j][k] & m) != (m2->col[j][k] & m)) return 0;
    }

    return 1;
}


/**
 * @brief INVERT A DENSE MOD2 MATRIX.
 *
 * @param m         The matrix to find the inverse of (destroyed)
 * @param r         Place to store the inverse
 * @return 1 on success, othervise 0 is returned
 */

int mod2dense_invert(mod2dense *m, mod2dense *r)
{
    mod2word *s, *t;
    int i, j, k, n, w, k0, b0;

    if (mod2dense_rows(m) != mod2dense_cols(m))
    {
        fprintf(stderr, "mod2dense_invert: Matrix to invert is not square\n");
        exit(1);
    }

    if (r == m)
    {
        fprintf(stderr,
            "mod2dense_invert: Result matrix is the same as the operand\n");
        exit(1);
    }

    n = mod2dense_rows(m);
    w = m->n_words;

    if (mod2dense_rows(r) != n || mod2dense_cols(r) != n)
    {
        fprintf(stderr,
            "mod2dense_invert: Matrix to receive inverse has wrong dimensions\n");
        exit(1);
    }

    mod2dense_clear(r);
    for (i = 0; i < n; i++)
    {
        mod2dense_set(r, i, i, 1);
    }

    for (i = 0; i < n; i++)
    {
        k0 = i >> mod2_wordsize_shift;
        b0 = i & mod2_wordsize_mask;

        for (j = i; j < n; j++)
        {
            if (mod2_getbit(m->col[j][k0], b0)) break;
        }

        if (j == n) return 0;

        if (j != i)
        {
            t = m->col[i];
            m->col[i] = m->col[j];
            m->col[j] = t;

            t = r->col[i];
            r->col[i] = r->col[j];
            r->col[j] = t;
        }

        for (j = 0; j < n; j++)
        {
            if (j != i && mod2_getbit(m->col[j][k0], b0))
            {
                s = m->col[j];
                t = m->col[i];
                for (k = k0; k < w; k++) s[k] ^= t[k];
                s = r->col[j];
                t = r->col[i];
                for (k = 0; k < w; k++) s[k] ^= t[k];
            }
        }
    }

    return 1;
}


/**
 * @brief INVERT A DENSE MOD2 MATRIX WITH ROWS & COLUMNS SELECTED FROM BIGGER MATRIX.
 *
 * @param m              Matrix from which to pick a submatrix to invert
 * @param r              Place to store the inverse
 * @param rows           Set to indexes of rows used and not used
 * @param cols           Set to indexes of columns used and not used
 * @returns unknown ???
 */

int mod2dense_invert_selected(mod2dense *m, mod2dense *r, int *rows, int *cols)
{
    mod2word *s, *t;
    int i, j, k, n, n2, w, k0, b0, c, R;

    if (r == m)
    {
        fprintf(stderr,
            "mod2dense_invert_selected2: Result matrix is the same as the operand\n");
        exit(1);
    }

    n = mod2dense_rows(m);
    w = m->n_words;

    n2 = mod2dense_cols(m);

    if (mod2dense_rows(r) != n || mod2dense_cols(r) != n2)
    {
        fprintf(stderr,
            "mod2dense_invert_selected2: Matrix to receive inverse has wrong dimensions\n");
        exit(1);
    }

    mod2dense_clear(r);

    for (i = 0; i < n; i++)
    {
        rows[i] = i;
    }

    for (j = 0; j < n2; j++)
    {
        cols[j] = j;
    }

    R = 0;
    i = 0;

    k0 = 0;
    b0 = 0;
    for (;;)
    {
        while (i < n - R)
        {
            k0 = rows[i] >> mod2_wordsize_shift;
            b0 = rows[i] & mod2_wordsize_mask;

            for (j = i; j < n2; j++)
            {
                if (mod2_getbit(m->col[cols[j]][k0], b0)) break;
            }

            if (j < n2) break;

            R += 1;
            c = rows[i];
            rows[i] = rows[n - R];
            rows[n - R] = c;

        }

        if (i == n - R) break;

        c = cols[j];
        cols[j] = cols[i];
        cols[i] = c;

        mod2dense_set(r, rows[i], c, 1);

        for (j = 0; j < n2; j++)
        {
            if (j != c && mod2_getbit(m->col[j][k0], b0))
            {
                s = m->col[j];
                t = m->col[c];
                for (k = 0; k < w; k++) s[k] ^= t[k];
                s = r->col[j];
                t = r->col[c];
                for (k = 0; k < w; k++) s[k] ^= t[k];
            }
        }

        i += 1;
    }

    for (j = n - R; j < n; j++)
    {
        s = r->col[cols[j]];
        for (k = 0; k < w; k++) s[k] = 0;
    }

    return R;
}


/**
 * @brief FORCIBLY INVERT A DENSE MOD2 MATRIX.
 *
 * @param m              The matrix to find the inverse of (destroyed)
 * @param r              Place to store the inverse
 * @param a_row          Place to store row indexes of altered elements
 * @param a_col          Place to store column indexes of altered elements
 * @returns unknown ???
 */

int mod2dense_forcibly_invert(mod2dense *m, mod2dense *r, int *a_row, int *a_col)
{
    mod2word *s, *t;
    int i, j, k, n, w, k0, b0;
    int u, c;

    if (mod2dense_rows(m) != mod2dense_cols(m))
    {
        fprintf(stderr,
            "mod2dense_forcibly_invert: Matrix to invert is not square\n");
        exit(1);
    }

    if (r == m)
    {
        fprintf(stderr,
            "mod2dense_forcibly_invert: Result matrix is the same as the operand\n");
        exit(1);
    }

    n = mod2dense_rows(m);
    w = m->n_words;

    if (mod2dense_rows(r) != n || mod2dense_cols(r) != n)
    {
        fprintf(stderr,
            "mod2dense_forcibly_invert: Matrix to receive inverse has wrong dimensions\n");
        exit(1);
    }

    mod2dense_clear(r);
    for (i = 0; i < n; i++)
    {
        mod2dense_set(r, i, i, 1);
    }

    for (i = 0; i < n; i++)
    {
        a_row[i] = -1;
        a_col[i] = i;
    }

    for (i = 0; i < n; i++)
    {
        k0 = i >> mod2_wordsize_shift;
        b0 = i & mod2_wordsize_mask;

        for (j = i; j < n; j++)
        {
            if (mod2_getbit(m->col[j][k0], b0)) break;
        }

        if (j == n)
        {
            j = i;
            mod2dense_set(m, i, j, 1);
            a_row[i] = i;
        }

        if (j != i)
        {
            t = m->col[i];
            m->col[i] = m->col[j];
            m->col[j] = t;

            t = r->col[i];
            r->col[i] = r->col[j];
            r->col[j] = t;

            u = a_col[i];
            a_col[i] = a_col[j];
            a_col[j] = u;
        }

        for (j = 0; j < n; j++)
        {
            if (j != i && mod2_getbit(m->col[j][k0], b0))
            {
                s = m->col[j];
                t = m->col[i];
                for (k = k0; k < w; k++) s[k] ^= t[k];
                s = r->col[j];
                t = r->col[i];
                for (k = 0; k < w; k++) s[k] ^= t[k];
            }
        }
    }

    c = 0;
    for (i = 0; i < n; i++)
    {
        if (a_row[i] != -1)
        {
            a_row[c] = a_row[i];
            a_col[c] = a_col[i];
            c += 1;
        }
    }

    return c;
}
