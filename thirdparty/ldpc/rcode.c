/* RCODE.C - Procedures to read parity check and generator matrices. */

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

#include "boxing/platform/memory.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "alloc.h"
#include "intio.h"
#include "open.h"
#include "mod2sparse.h"
#include "mod2dense.h"
#include "mod2convert.h"
#include "rcode.h"

static int *column_partition(distrib *, int);
static void print_generator_check_info(generator_matrix *gen_matrix);


/**
 * @brief READ PARITY CHECK MATRIX.  Sets the H, M, and N global variables.  If an
 * error is encountered, a message is displayed on standard error, and the
 * program is terminated. 
 *
 * @param pchk_file     the name of the file from which the parity matrix is read from
 * @return paritymatrix
 */

mod2sparse* ldcp_pchk_read(char *pchk_file)
{
    FILE *f;

    f = open_file_std(pchk_file, "rb");
    if (f == NULL)
    {
        fprintf(stderr, "Can't open parity check file: %s\n", pchk_file);
        return NULL;
    }

    if (intio_read(f) != ('P' << 8) + 0x80)
    {
        fprintf(stderr, "File %s doesn't contain a parity check matrix\n", pchk_file);
        fclose(f);
        return NULL;
    }

    mod2sparse * H = mod2sparse_read(f);
    fclose(f);

    if (H == 0)
    {
        fprintf(stderr, "Error reading parity check matrix from %s\n", pchk_file);
    }

    return H;
}



/*
 * @brief READ GENERATOR MATRIX.  The parity check matrix must have already been
 * read, unless the last argument is set to 1.  The generator matrix must be
 * compatible with the parity check matrix, if it has been read.  If the
 * second argument is 1, only the column ordering (the last N-M of which are
 * the indexes of the message bits) is read, into the 'cols' global variable.
 * Otherwise, everything is read, into the global variables appropriate
 * to the representation.  The 'type' global variable is set to a letter
 * indicating which represention is used.
 *
 * If an error is encountered, a message is displayed on standard error,
 * and the program is terminated. 
 *
 *
 * @param gen_file        Name of generator matrix file
 * @param cols_only       Read only column ordering?
 * @param no_pchk_file    No parity check file used?
 * @param H               parity matrix
 */

generator_matrix* ldpc_generator_read(char *gen_file, int cols_only, int no_pchk_file, mod2sparse *H)
{
    int M2, N2;
    FILE *f;
    int i;

    f = open_file_std(gen_file, "rb");
    if (f == NULL)
    {
        fprintf(stderr, "Can't open generator matrix file: %s\n", gen_file);
        return NULL;
    }

    if (intio_read(f) != ('G' << 8) + 0x80)
    {
        fprintf(stderr, "File %s doesn't contain a generator matrix\n", gen_file);
        return NULL;
    }

    generator_matrix* gen_matrix = BOXING_MEMORY_ALLOCATE_TYPE_ARRAY_CLEAR(generator_matrix, 1);
    gen_matrix->H = H;

    if (fread(&gen_matrix->type, 1, 1, f) != 1) goto error;

    M2 = intio_read(f);
    N2 = intio_read(f);

    if (feof(f) || ferror(f)) goto error;

    if (no_pchk_file)
    {
        gen_matrix->M = M2;
        gen_matrix->N = N2;
    }
    else
    {
        if (M2 != mod2sparse_rows(H) || N2 != mod2sparse_cols(H))
        {
            fprintf(stderr,
                "Generator matrix and parity-check matrix are incompatible\n");
            ldpc_generator_free(gen_matrix);
            return NULL;
        }
        gen_matrix->M = mod2sparse_rows(H);
        gen_matrix->N = mod2sparse_cols(H);
    }

    gen_matrix->cols = chk_alloc(gen_matrix->N, sizeof *gen_matrix->cols);
    gen_matrix->rows = chk_alloc(gen_matrix->M, sizeof *gen_matrix->rows);

    for (i = 0; i < gen_matrix->N; i++)
    {
        gen_matrix->cols[i] = intio_read(f);
        if (feof(f) || ferror(f)) goto error;
    }

    if (!cols_only)
    {
        switch (gen_matrix->type)
        {
        case 's':
        {
            for (i = 0; i < gen_matrix->M; i++)
            {
                gen_matrix->rows[i] = intio_read(f);
                if (feof(f) || ferror(f)) goto error;
            }

            if ((gen_matrix->L = mod2sparse_read(f)) == 0) goto error;
            if ((gen_matrix->U = mod2sparse_read(f)) == 0) goto error;

            if (mod2sparse_rows(gen_matrix->L) != gen_matrix->M || mod2sparse_cols(gen_matrix->L) != gen_matrix->M) goto garbled;
            if (mod2sparse_rows(gen_matrix->U) != gen_matrix->M || mod2sparse_cols(gen_matrix->U) < gen_matrix->M) goto garbled;

            break;
        }

        case 'd':
        {
            if ((gen_matrix->G = mod2dense_read(f)) == 0) goto error;

            if (mod2dense_rows(gen_matrix->G) != gen_matrix->M || mod2dense_cols(gen_matrix->G) != gen_matrix->N - gen_matrix->M) goto garbled;

            break;
        }

        case 'm':
        {
            if ((gen_matrix->G = mod2dense_read(f)) == 0) goto error;

            if (mod2dense_rows(gen_matrix->G) != gen_matrix->M || mod2dense_cols(gen_matrix->G) != gen_matrix->M) goto garbled;

            break;
        }

        default:
        { 
            fprintf(stderr, "Unknown type of generator matrix in file %s\n", gen_file);
            ldpc_generator_free(gen_matrix);
            return NULL;
        }
        }
    }

    fclose(f);

    return gen_matrix;

error:
    fprintf(stderr, "Error reading generator matrix from file %s\n", gen_file);
    ldpc_generator_free(gen_matrix);
    return NULL;

garbled:
    fprintf(stderr, "Garbled generator matrix in file %s\n", gen_file);
    ldpc_generator_free(gen_matrix);
    return NULL;
}

/**
* @brief Write it all to the generator matrix file.
*/

void ldpc_generator_write(generator_matrix *gen_matrix, FILE *f)
{
    intio_write(f, ('G' << 8) + 0x80);

    fwrite(&gen_matrix->type, 1, 1, f);

    intio_write(f, gen_matrix->M);
    intio_write(f, gen_matrix->N);

    for (int i = 0; i < gen_matrix->N; i++)
    {
        intio_write(f, gen_matrix->cols[i]);
    }


    if (gen_matrix->type == 's')
    {
        for (int i = 0; i < gen_matrix->M; i++)
        {
            intio_write(f, gen_matrix->rows[i]);
        }

        mod2sparse_write(f, gen_matrix->L);
        mod2sparse_write(f, gen_matrix->U);
    }
    else
    {
        mod2dense_write(f, gen_matrix->G);
    }
}

void ldpc_generator_free(generator_matrix *gen_matrix)
{
    boxing_memory_free(gen_matrix->cols);
    boxing_memory_free(gen_matrix->rows);
    boxing_memory_free(gen_matrix->L);
    boxing_memory_free(gen_matrix->U);
    mod2sparse_free(gen_matrix->H);
    mod2dense_free(gen_matrix->G);
    boxing_memory_free(gen_matrix);
}


/**
* @brief CREATE A SPARSE PARITY-CHECK MATRIX.  Of size M by N
*
* @param seed      Random number seed
* @param method    How to make it
* @param d         Distribution list specified
* @param no4cycle  Eliminate cycles of length four?
* @param M Random  Check bits
* @param N Random  Message size including check bits
* @return a sparse parity check matrix on success, othervise NULL
*/

mod2sparse * ldcp_pchk_make(int seed, pchk_make_method method, distrib *d, int no4cycle, int M, int N)
{
    mod2entry *e, *f, *g, *h;
    int added, uneven, elim4, all_even, n_full, left;
    int i, j, k, t, z, cb_N;
    int *part, *u;

    rand_seed(10 * seed + 1);

    mod2sparse * H = mod2sparse_allocate(M, N);
    part = column_partition(d, N);
    if (!part)
    {
        mod2sparse_free(H);
        return NULL;
    }
    /* Create the initial version of the parity check matrix. */

    switch (method)
    {
    case pchk_evencol:
    {
        z = 0;
        left = part[z];

        for (j = 0; j < N; j++)
        {
            while (left == 0)
            {
                z += 1;
                if (z > distrib_size(d))
                {
                    mod2sparse_free(H);
                    return NULL;
                }
                left = part[z];
            }
            for (k = 0; k < distrib_num(d, z); k++)
            {
                do
                {
                    i = rand_int(M);
                } while (mod2sparse_find(H, i, j));
                mod2sparse_insert(H, i, j);
            }
            left -= 1;
        }

        break;
    }

    case pchk_evenboth:
    {
        cb_N = 0;
        for (z = 0; z < distrib_size(d); z++)
        {
            cb_N += distrib_num(d, z) * part[z];
        }

        u = chk_alloc(cb_N, sizeof *u);

        for (k = cb_N - 1; k >= 0; k--)
        {
            u[k] = k%M;
        }

        uneven = 0;
        t = 0;
        z = 0;
        left = part[z];

        for (j = 0; j < N; j++)
        {
            while (left == 0)
            {
                z += 1;
                if (z > distrib_size(d))
                {
                    mod2sparse_free(H);
                    return NULL;
                }
                left = part[z];
            }

            for (k = 0; k < distrib_num(d, z); k++)
            {
                for (i = t; i < cb_N && mod2sparse_find(H, u[i], j); i++);

                if (i == cb_N)
                {
                    uneven += 1;
                    do
                    {
                        i = rand_int(M);
                    } while (mod2sparse_find(H, i, j));
                    mod2sparse_insert(H, i, j);
                }
                else
                {
                    do
                    {
                        i = t + rand_int(cb_N - t);
                    } while (mod2sparse_find(H, u[i], j));
                    mod2sparse_insert(H, u[i], j);
                    u[i] = u[t];
                    t += 1;
                }
            }

            left -= 1;
        }

        if (uneven > 0)
        {
            fprintf(stderr, "Had to place %d checks in rows unevenly\n", uneven);
        }

        break;
    }

    default:
        mod2sparse_free(H);
        return NULL;
    }

    /* Add extra bits to avoid rows with less than two checks. */

    added = 0;

    for (i = 0; i < M; i++)
    {
        e = mod2sparse_first_in_row(H, i);
        if (mod2sparse_at_end(e))
        {
            j = rand_int(N);
            e = mod2sparse_insert(H, i, j);
            added += 1;
        }
        e = mod2sparse_first_in_row(H, i);
        if (mod2sparse_at_end(mod2sparse_next_in_row(e)) && N>1)
        {
            do
            {
                j = rand_int(N);
            } while (j == mod2sparse_col(e));
            mod2sparse_insert(H, i, j);
            added += 1;
        }
    }

    if (added > 0)
    {
        fprintf(stderr, "Added %d extra bit-checks to make row counts at least two\n", added);
    }

    /* Add extra bits to try to avoid problems with even column counts. */

    n_full = 0;
    all_even = 1;
    for (z = 0; z < distrib_size(d); z++)
    {
        if (distrib_num(d, z) == M)
        {
            n_full += part[z];
        }
        if (distrib_num(d, z) % 2 == 1)
        {
            all_even = 0;
        }
    }

    if (all_even && N - n_full > 1 && added < 2)
    {
        int a;
        for (a = 0; added + a < 2; a++)
        {
            do
            {
                i = rand_int(M);
                j = rand_int(N);
            } while (mod2sparse_find(H, i, j));
            mod2sparse_insert(H, i, j);
        }
        fprintf(stderr, "Added %d extra bit-checks to try to avoid problems from even column counts\n", a);
    }

    /* Eliminate cycles of length four, if asked, and if possible. */

    if (no4cycle)
    {
        elim4 = 0;

        for (t = 0; t < 10; t++)
        {
            k = 0;
            for (j = 0; j < N; j++)
            {
                for (e = mod2sparse_first_in_col(H, j);
                    !mod2sparse_at_end(e);
                    e = mod2sparse_next_in_col(e))
                {
                    for (f = mod2sparse_first_in_row(H, mod2sparse_row(e));
                        !mod2sparse_at_end(f);
                        f = mod2sparse_next_in_row(f))
                    {
                        if (f == e) continue;
                        for (g = mod2sparse_first_in_col(H, mod2sparse_col(f));
                            !mod2sparse_at_end(g);
                            g = mod2sparse_next_in_col(g))
                        {
                            if (g == f) continue;
                            for (h = mod2sparse_first_in_row(H, mod2sparse_row(g));
                                !mod2sparse_at_end(h);
                                h = mod2sparse_next_in_row(h))
                            {
                                if (mod2sparse_col(h) == j)
                                {
                                    do
                                    {
                                        i = rand_int(M);
                                    } while (mod2sparse_find(H, i, j));
                                    mod2sparse_delete(H, e);
                                    mod2sparse_insert(H, i, j);
                                    elim4 += 1;
                                    k += 1;
                                    goto nextj;
                                }
                            }
                        }
                    }
                }
            nextj:;
            }
            if (k == 0) break;
        }

        if (elim4 > 0)
        {
            fprintf(stderr, "Eliminated %d cycles of length four by moving checks within column\n", elim4);
        }

        if (t == 10)
        {
            fprintf(stderr, "Couldn't eliminate all cycles of length four in 10 passes\n");
        }
    }
    return H;
}


/**
* @brief PARTITION THE COLUMNS ACCORDING TO THE SPECIFIED PROPORTIONS.  It
* may not be possible to do this exactly.  Returns a pointer to an
* array of integers containing the numbers of columns corresponding
* to the entries in the distribution passed.
*
* @param d      List of proportions and number of check-bits
* @param n		 Total number of columns to partition
* @return      Returns a pointer to an array of integers on success, othervise NULL
*/

static int *column_partition(distrib *d, int n)
{
    double *trunc;
    int *part;
    int cur, used;
    int i, j;

    trunc = chk_alloc(distrib_size(d), sizeof(double));
    part = chk_alloc(distrib_size(d), sizeof(int));

    used = 0;
    for (i = 0; i < distrib_size(d); i++)
    {
        cur = (int)floor(distrib_prop(d, i)*n);
        part[i] = cur;
        trunc[i] = distrib_prop(d, i)*n - cur;
        used += cur;
    }

    if (used > n)
    {
        return NULL;
    }

    while (used < n)
    {
        cur = 0;
        for (j = 1; j < distrib_size(d); j++)
        {
            if (trunc[j] > trunc[cur])
            {
                cur = j;
            }
        }
        part[cur] += 1;
        used += 1;
        trunc[cur] = -1;
    }

    boxing_memory_free(trunc);
    return part;
}

/**
* @brief MAKE DENSE OR MIXED REPRESENTATION OF GENERATOR MATRIX.
*/

generator_matrix * ldpc_generator_make_dense_mixed(mod2sparse * H, gen_make_method method)
{
    mod2dense *DH, *A, *A2, *AI, *B;
    int i, n;
    int *rows_inv;
    int M = mod2sparse_rows(H);
    int N = mod2sparse_cols(H);
    //mod2sparse * H = par_chk->H;
    char type;

    if (method == gen_dense)
    {
        type = 'd';
    }
    else if (method == gen_mixed)
    {
        type = 'm';
    }
    else
    {
        return NULL;
    }

    /* Allocate space for row and column permutations. */
    generator_matrix *gen_matrix = BOXING_MEMORY_ALLOCATE_TYPE_ARRAY_CLEAR(generator_matrix, 1);

    gen_matrix->H = mod2sparse_clone(H);
    gen_matrix->M = mod2sparse_rows(H);
    gen_matrix->N = mod2sparse_cols(H);
    gen_matrix->cols = chk_alloc(N, sizeof *gen_matrix->cols);
    gen_matrix->rows = chk_alloc(M, sizeof *gen_matrix->rows);
    gen_matrix->type = type;

    DH = mod2dense_allocate(M, N);
    AI = mod2dense_allocate(M, M);
    B = mod2dense_allocate(M, N - M);
    gen_matrix->G = mod2dense_allocate(M, N - M);

    mod2sparse_to_dense(gen_matrix->H, DH);


    A = mod2dense_allocate(M, N);
    A2 = mod2dense_allocate(M, N);

    n = mod2dense_invert_selected(DH, A2, gen_matrix->rows, gen_matrix->cols);
    mod2sparse_to_dense(gen_matrix->H, DH);  /* DH was destroyed by invert_selected */

    if (n > 0)
    {
        fprintf(stderr, "Note: Parity check matrix has %d redundant checks\n", n);
    }

    rows_inv = chk_alloc(M, sizeof *rows_inv);

    for (i = 0; i < M; i++)
    {
        rows_inv[gen_matrix->rows[i]] = i;
    }

    mod2dense_copyrows(A2, A, gen_matrix->rows);
    mod2dense_copycols(A, A2, gen_matrix->cols);
    mod2dense_copycols(A2, AI, rows_inv);

    mod2dense_copycols(DH, B, gen_matrix->cols + M);

    /* Form final generator matrix. */

    if (method == gen_dense)
    {
        mod2dense_multiply(AI, B, gen_matrix->G);
    }
    else if (method == gen_mixed)
    {
        gen_matrix->G = AI;
    }

    /* Compute and print number of 1s. */

    print_generator_check_info(gen_matrix);

    return gen_matrix;
}

static void print_generator_check_info(generator_matrix *gen_matrix)
{
    int i, j, c, c2;
    int M = gen_matrix->M;
    int N = gen_matrix->N;

    if (gen_matrix->type == 'd')
    {
        c = 0;
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N - M; j++)
            {
                c += mod2dense_get(gen_matrix->G, i, j);
            }
        }
        fprintf(stderr,
            "Number of 1s per check in Inv(A) X B is %.1f\n", (double)c / M);
    }

    if (gen_matrix->type == 'm')
    {
        c = 0;
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < M; j++)
            {
                c += mod2dense_get(gen_matrix->G, i, j);
            }
        }
        c2 = 0;
        for (i = M; i < N; i++)
        {
            c2 += mod2sparse_count_col(gen_matrix->H, gen_matrix->cols[i]);
        }
        fprintf(stderr,
            "Number of 1s per check in Inv(A) is %.1f, in B is %.1f, total is %.1f\n",
            (double)c / M, (double)c2 / M, (double)(c + c2) / M);
    }
}

/**
* @brief MAKE SPARSE REPRESENTATION OF GENERATOR MATRIX.
*/

generator_matrix * ldpc_generator_make_sparse(mod2sparse * H, mod2sparse_strategy strategy, int abandon_number, int abandon_when)
{
    int n, cL, cU, cB;
    int i;
    int M = mod2sparse_rows(H);
    int N = mod2sparse_cols(H);
    //  mod2sparse * H = par_chk->H;
    /* Find LU decomposition. */

    /* Allocate space for row and column permutations. */
    generator_matrix *gen_matrix = BOXING_MEMORY_ALLOCATE_TYPE_ARRAY_CLEAR(generator_matrix, 1);

    gen_matrix->H = mod2sparse_clone(H);
    gen_matrix->M = mod2sparse_rows(H);
    gen_matrix->N = mod2sparse_cols(H);
    gen_matrix->cols = chk_alloc(N, sizeof *gen_matrix->cols);
    gen_matrix->rows = chk_alloc(M, sizeof *gen_matrix->rows);
    gen_matrix->type = 's';


    gen_matrix->L = mod2sparse_allocate(M, M);
    gen_matrix->U = mod2sparse_allocate(M, N);

    n = mod2sparse_decomp(gen_matrix->H, M, gen_matrix->L, gen_matrix->U, gen_matrix->rows, gen_matrix->cols, strategy, abandon_number, abandon_when);

    if (n != 0 && abandon_number == 0)
    {
        fprintf(stderr, "Note: Parity check matrix has %d redundant checks\n", n);
    }

    if (n != 0 && abandon_number > 0)
    {
        fprintf(stderr, "Note: Have %d dependent columns, but this could be due to abandonment.\n", n);
        fprintf(stderr, "      Try again with lower abandonment number.\n");
        return NULL;
    }

    /* Compute and print number of 1s. */

    cL = cU = cB = 0;

    for (i = 0; i < M; i++) cL += mod2sparse_count_row(gen_matrix->L, i);
    for (i = 0; i < M; i++) cU += mod2sparse_count_row(gen_matrix->U, i);
    for (i = M; i < N; i++) cB += mod2sparse_count_col(gen_matrix->H, gen_matrix->cols[i]);

    fprintf(stderr,
        "Number of 1s per check in L is %.1f, U is %.1f, B is %.1f, total is %.1f\n",
        (double)cU / M, (double)cL / M, (double)cB / M, (double)(cL + cU + cB) / M);

    return gen_matrix;
}
