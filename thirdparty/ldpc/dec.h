/* DEC.H - Interface to decoding procedures. */

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


extern int table;	/* Trace option, 2 for a table of decoding details */
extern int block_no;	/* Number of current block, from zero */

/* PROCEDURES RELATING TO DECODING METHODS. */

unsigned ldpc_decode_enum(double *lratio, char *dblk, double *bitpr, int max_block, generator_matrix* G);
unsigned ldpc_decode_prprp(mod2sparse *H, double *lratio, char *dblk, char *pchk, double *bprb, int max_iter);

