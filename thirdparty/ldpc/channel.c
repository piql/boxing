/* CHANNEL.C - Procedures and variables regarding channels. */

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "channel.h"

/**
 * @brief PARSE A COMMAND-LINE SPECIFICATION OF A CHANNEL.  Takes a pointer to an
 * argument list and an argument count; returns the number of arguments that
 * make up a channel specification at this point in the command line.  Returns
 * zero if the argument list does not start with a channel specification.
 * Returns -1 if there seems to be a channel specification here, but it's
 * invalid.
 *
 * Sets the variables declared in channel.h to the type and parameters of
 * the channel.
 *
 * @param  argv		 Pointer to argument list 
 * @param  argc		 Number of arguments in list 
 * @praram channel   found channel type
 * @return number of arguments or -1 on error
 */

int channel_parse(char **argv, int argc, int *channel, double *channel_param)
{
    char junk;

    if (argc == 0) 
        return 0;

    if (argc < 2)
        return -1;

    if (strcmp(argv[0], "bsc") == 0 || strcmp(argv[0], "BSC") == 0)
    {
        *channel = BSC;
    }
    else if (strcmp(argv[0], "awgn") == 0 || strcmp(argv[0], "AWGN") == 0)
    {
        *channel = AWGN;
    }
    else if (strcmp(argv[0], "awln") == 0 || strcmp(argv[0], "AWLN") == 0)
    {
        *channel = AWLN;
    }
    else if (strcmp(argv[0], "awgn_32_2dpam") == 0 || strcmp(argv[0], "AWGN_32_2DPAM") == 0)
    {
        *channel = AWGN_32_2DPAM;
    }
    else
    {
        return 0;
    }

    if (sscanf(argv[1], "%lf%c", channel_param, &junk) != 1)
        return -1;

    if (*channel_param <= 0)
    {
        return -1;
    }

    if ((*channel == BSC) && (*channel_param >= 1))
    {
        return -1;
    }

    
    return 2;
}


/**
 * @brief PRINT USAGE MESSAGE REGARDING CHANNEL SPECIFICATIONS.
 */

void channel_usage(void)
{
    fprintf(stderr,
        "Channel: bsc error-probability | awgn standard-deviation | awln width\n");
}
