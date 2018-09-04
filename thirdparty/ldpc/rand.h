#ifndef LDPC_RAND_H
#define LDPC_RAND_H
/* RAND.H - Interface to random number generation procedures. */

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


/* STATE OF RANDOM NUMBER GENERATOR. */

#define N_tables 5		/* Number of tables of real random numbers */

typedef struct
{
    int seed;			/* Seed state derives from */
    int ptr[N_tables];		/* Pointers for tables of real random numbers */
    unsigned short state48[3];	/* State of 'rand48' pseudo-random generator */
} rand_state;


/* BASIC PSEUDO-RANDOM GENERATION PROCEDURES. */

void rand_seed(int seed);		/* Initialize current state structure by seed */

void rand_use_state(rand_state *st); /* Start using given state structure */
rand_state *rand_get_state(void);  /* Return pointer to current state */

int rand_word(void);		/* Generate random 31-bit positive integer */


/* GENERATORS FOR VARIOUS DISTRIBUTIONS. */

double rand_uniform(void);	/* Uniform from [0,1) */
double rand_uniopen(void);	/* Uniform from (0,1) */

int rand_int(int n);		/* Uniform from 0, 1, ... (n-1) */
int rand_pickd(double *p, int n);	/* From 0 ... (n-1), with given distribution */
int rand_pickf(float *p, int n);	/* Same as above, but with floats */
void rand_permutation(int *perm, int n); /* Random permutation */

int rand_poisson(double lambda);	/* Poisson with given mean */
double rand_gaussian(void);	/* Gaussian with mean zero and unit variance */
double rand_logistic(void);	/* Logistic centred at zero with unit width */
double rand_cauchy(void);	/* Cauchy centred at zero with unit width */
double rand_gamma(double a);	/* Gamma with given shape parameter */
double rand_exp(void);		/* Exponential with mean one */
double rand_beta(double a, double b); /* Beta with given parameters */

#endif /* LDPC_RAND_H */