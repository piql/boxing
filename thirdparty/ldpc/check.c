/* CHECK.C - Compute parity checks and other stats on decodings. */

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

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "mod2sparse.h"
#include "check.h"



/**
 * @brief COMPUTE PARITY CHECKS.  Returns the number of parity checks violated by
 * dblk.  The results of all the parity checks are stored in pchk. 
 *
 * @param H      Parity check matrix
 * @param dblk   Guess for codeword
 * @param pchk   Place to store parity checks
 *
 */
int check(mod2sparse *H, char *dblk, char *pchk)
{
    int M, i, c;

    M = mod2sparse_rows(H);

    mod2sparse_mulvec(H, dblk, pchk);

    c = 0;
    for (i = 0; i < M; i++)
    {
        c += pchk[i];
    }

    return c;
}


/**
 * @brief COUNT HOW MANY BITS HAVED CHANGED FROM BIT INDICATED BY LIKELIHOOD.  The
 * simple decoding based on likelihood ratio is compared to the given decoding.
 * A bit for which the likelihood ratio is exactly one counts as half a
 * change, which explains why the result is a double rather than an int.
 *
 * @param lratio  Likelihood ratios for bits
 * @param dblk    Candidate decoding
 * @param N       Number of bits
 * @return
 */

double changed(double *lratio, char *dblk, int N)
{
    double changed;
    int j;

    changed = 0;
    for (j = 0; j < N; j++)
    {
        changed += lratio[j] == 1 ? 0.5 : dblk[j] != (lratio[j]>1);
    }

    return changed;
}


/**
 * COMPUTE THE EXPECTED NUMBER OF PARITY CHECK ERRORS.   Computes the
 * expected number of parity check errors with respect to the distribution
 * given by the bit probabilities passed, with bits assumed to be independent.
 *
 * @param H   Parity check matrix
 * @param bpr Bit probabilities
 * @return
 */

double expected_parity_errors(mod2sparse *H, double *bpr)
{
    mod2entry *f;
    double ee, p;
    int M, i, j;

    M = mod2sparse_rows(H);

    ee = 0;

    for (i = 0; i < M; i++)
    {
        p = 0;
        for (f = mod2sparse_first_in_row(H, i);
            !mod2sparse_at_end(f);
            f = mod2sparse_next_in_row(f))
        {
            j = mod2sparse_col(f);
            p = p * (1 - bpr[j]) + (1 - p) * bpr[j];
        }
        ee += p;
    }

    return ee;
}


/**
 * @brief COMPUTE LOG LIKELIHOOD OF A DECODING.
 *
 * @param lratio  Likelihood ratios for bits
 * @param bits    Bits in decoding
 * @param N       Length of codeword
 * @return log likelihood
 */

double loglikelihood(double *lratio, char *bits, int N)
{
    double ll;
    int j;

    ll = 0;

    for (j = 0; j < N; j++)
    {
        ll -= bits[j] ? log(1 + 1 / lratio[j]) : log(1 + lratio[j]);
    }

    return ll;
}


/**
 * @brief COMPUTE THE EXPECTED LOG LIKELIHOOD BASED ON BIT PROBABILITIES.  Computes
 * the expected value of the log likelihood with respect to the distribution
 * given by the bit probabilities passed, with bits assumed to be independent.
 *
 * @param lratio   Likelihood ratios for bits
 * @param bpr      Bit probabilities
 * @param N        Length of codeword
 * @return expected lof likelihood
 */

double expected_loglikelihood(double *lratio, double *bpr, int N)
{
    double ll;
    int j;

    ll = 0;

    for (j = 0; j < N; j++)
    {
        if (bpr[j] > 0)
        {
            ll -= bpr[j] * log(1 + 1 / lratio[j]);
        }
        if (bpr[j] < 1)
        {
            ll -= (1 - bpr[j])*log(1 + lratio[j]);
        }
    }

    return ll;
}


/**
 * @brief COMPUTE ENTROPY FROM BIT PROBABILITIES.  Computes the entropy of the
 * distribution given by the bit probabilities, on the assumption that
 * bits are independent.
 *
 * @parma bpr  Bit probabilities
 * @parma N    Length of codeword
 * @return entropy
 */

double entropy(double *bpr, int N)
{
    double e;
    int j;

    e = 0;
    for (j = 0; j < N; j++)
    {
        if (bpr[j] > 0 && bpr[j] < 1)
        {
            e -= bpr[j] * log(bpr[j]) + (1 - bpr[j])*log(1 - bpr[j]);
        }
    }

    return e / log(2.0);
}
