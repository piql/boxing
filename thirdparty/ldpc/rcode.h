/* RCODE.H - Parity chk and gen matrix storage, and procedures to read them.*/

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


/* VARIABLES HOLDING DATA READ.  These are declared for real in rcode.c. */

typedef struct ldpc_generator_s
{
    mod2sparse *H;	/**< Parity check matrix */

    int M;		    /**< Number of rows in parity check matrix */
    int N;		    /**< Number of columns in parity check matrix */
                    
    char type;	    /**< Type of generator matrix representation */
    int *cols;	    /**< Ordering of columns in generator matrix */
    int *rows;	    /**< Ordering of rows in generator matrix (type 's') */
    mod2sparse *L;  /**< Sparse L decomposition, if type=='s' */
    mod2sparse *U;  /**< Sparse U decomposition, if type=='s' */

    mod2dense *G;	/**< Dense or mixed representation of generator matrix,
                    if type=='d' or type=='m' */
}ldpc_generator;

typedef ldpc_generator generator_matrix; // remove later

/* PROCEDURES FOR READING DATA. */

mod2sparse* ldcp_pchk_read(char *pchk_file);
ldpc_generator* ldpc_generator_read(char *gen_file, int cols_only, int no_pchk_file, mod2sparse *H);
void ldpc_generator_write(generator_matrix *gen_matrix, FILE *f);
void ldpc_generator_free(generator_matrix *gen_matrix);


#include "rand.h"
#include "distrib.h"

/* METHODS FOR CONSTRUCTING CODES. */

typedef enum
{
    pchk_unknown,
    pchk_evencol, 	/**< Uniform number of bits per column, with number specified */
    pchk_evenboth 	/**< Uniform (as possible) over both columns and rows */
} pchk_make_method;

mod2sparse * ldcp_pchk_make(int, pchk_make_method, distrib *, int, int M, int N);

typedef enum
{ 
    gen_unknown,
    gen_sparse, 
    gen_dense, 
    gen_mixed 
} gen_make_method;      /* Ways of making it */

generator_matrix * ldpc_generator_make_dense_mixed(mod2sparse * H, gen_make_method method);
generator_matrix * ldpc_generator_make_sparse(mod2sparse * H, mod2sparse_strategy strategy, int abandon_number, int abandon_when);
