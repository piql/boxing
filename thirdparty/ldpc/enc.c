/* ENC.C - Encoding procedures. */

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

#include "alloc.h"
#include "mod2sparse.h"
#include "mod2dense.h"
#include "mod2convert.h"
#include "rcode.h"
#include "enc.h"

static void sparse_encode(generator_matrix *G, char *sblk, char *cblk);
static void dense_encode(generator_matrix *G, char *sblk, char *cblk);
static void mixed_encode(generator_matrix *G, char *sblk, char *cblk);

/* The procedures in this module obtain the generator matrix to use for
   encoding from the global variables declared in rcode.h */

/**
* @brief ENCODE A BLOCK ANY GENERATOR MATRIX.
*
* @param G
* @param sblk
* @param cblk
*/

void ldpc_encode(generator_matrix *G, char *sblk, char *cblk)
{
    switch (G->type)
    {
    case 's':
    { sparse_encode(G, sblk, cblk);
    break;
    }
    case 'd':
    { dense_encode(G, sblk, cblk);
    break;
    }
    case 'm':
    { mixed_encode(G, sblk, cblk);
    break;
    }
    }

}

/**
 * @brief ENCODE A BLOCK USING A SPARSE REPRESENTATION OF THE GENERATOR MATRIX. 
 *
 * @param G
 * @param sblk
 * @param cblk
 */

static void sparse_encode(generator_matrix *G, char *sblk, char *cblk)
{
    int i, j;

    mod2entry *e;
    char *x, *y;
    int M = G->M;
    int N = G->N;


    x = chk_alloc(M, sizeof *x);
    y = chk_alloc(M, sizeof *y);

    /* Multiply the vector of source bits by the systematic columns of the
       parity check matrix, giving x.  Also copy these bits to the coded block. */

    for (i = 0; i < M; i++) x[i] = 0;

    for (j = M; j < N; j++)
    {
        cblk[G->cols[j]] = sblk[j - M];

        if (sblk[j - M] == 1)
        {
            for (e = mod2sparse_first_in_col(G->H, G->cols[j]);
                !mod2sparse_at_end(e);
                e = mod2sparse_next_in_col(e))
            {
                x[mod2sparse_row(e)] ^= 1;
            }
        }
    }

    /* Solve Ly=x for y by forward substitution, then U(cblk)=y by backward
       substitution. */

    if (!mod2sparse_forward_sub(G->L, G->rows, x, y)
        || !mod2sparse_backward_sub(G->U, G->cols, y, cblk))
    {
        abort(); /* Shouldn't occur, even if the parity check matrix has
                    redundant rows */
    }

    boxing_memory_free(x);
    boxing_memory_free(y);
}


/**
 * @bref ENCODE A BLOCK USING DENSE REPRESENTATION OF GENERATOR MATRIX. 
 *
 * @param G
 * @param sblk
 * @param cblk
 */

static void dense_encode(generator_matrix *G, char *sblk, char *cblk)
{
    int j;
    int M = G->M;
    int N = G->N;
    mod2dense *u;
    mod2dense *v;

    u = mod2dense_allocate(N - M, 1);
    v = mod2dense_allocate(M, 1);


    /* Copy source bits to the systematic part of the coded block. */

    for (j = M; j < N; j++)
    {
        cblk[G->cols[j]] = sblk[j - M];
    }

    /* Multiply by Inv(A) X B to produce check bits. */

    for (j = M; j < N; j++)
    {
        mod2dense_set(u, j - M, 0, sblk[j - M]);
    }

    mod2dense_multiply(G->G, u, v);

    /* Copy check bits to the right places in the coded block. */

    for (j = 0; j < M; j++)
    {
        cblk[G->cols[j]] = mod2dense_get(v, j, 0);
    }

    mod2dense_free(u);
    mod2dense_free(v);
}


/**
 * @brief ENCODE A BLOCK USING MIXED REPRESENTATION OF GENERATOR MATRIX. 
 *
 * @param G
 * @param sblk
 * @param cblk
 */

static void mixed_encode(generator_matrix *G, char *sblk, char *cblk)
{
    mod2entry *e;
    int j;
    int M = G->M;
    int N = G->N;
    mod2sparse * H = G->H;
    int *cols = G->cols;

    mod2dense *u;
    mod2dense *v;

    u = mod2dense_allocate(M, 1);
    v = mod2dense_allocate(M, 1);

    /* Multiply the vector of source bits by the message bit columns of the
       parity check matrix.  Also copy these bits to the coded block.  Take
       account of how columns have been reordered. */

    mod2dense_clear(u);

    for (j = M; j < N; j++)
    {
        cblk[cols[j]] = sblk[j - M];

        if (sblk[j - M] == 1)
        {
            for (e = mod2sparse_first_in_col(H, cols[j]);
                !mod2sparse_at_end(e);
                e = mod2sparse_next_in_col(e))
            {
                (void)mod2dense_flip(u, mod2sparse_row(e), 0);
            }
        }
    }

    /* Multiply by Inv(A) to produce check bits. */

    mod2dense_multiply(G->G, u, v);

    /* Copy check bits to the right places in the coded block. */

    for (j = 0; j < M; j++)
    {
        cblk[cols[j]] = mod2dense_get(v, j, 0);
    }

    mod2dense_free(u);
    mod2dense_free(v);
}
