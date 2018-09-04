#ifndef BOXING_BASE_CONFIG_H
#define BOXING_BASE_CONFIG_H

/*****************************************************************************
**
**  Definition of the platform config interface
**
**  Creation date:  2014/12/16
**  Created by:     Piql AS
**
**
**  Copyright (c) 2014 Piql AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/


/****************************************************************************/
/*  O P E R A T I N G   S Y S T E M   M A C R O S                           */
/****************************************************************************/

/***********/
/*  LINUX  */
/***********/

#if defined( linux ) || defined( __linux ) || defined( __linux__ ) || defined( __APPLE_CC__ ) || defined(__CYGWIN__)
#   define  D_OS_LINUX
#   define  D_OS_UNIX
#   define  _FILE_OFFSET_BITS 64
#   if defined ( __APPLE_CC__ )
#       define  D_OS_X
#   endif

/**********/
/*  ECOS  */
/**********/
#elif defined( __ECOS )
#define D_OS_ECOS


/***********/
/*  WIN32  */
/***********/

#elif defined( _WIN32 )
#   define  D_OS_WIN32


/********************/
/*  UNSUPPORTED OS  */
/********************/

#else
#   error   "*** UNSUPPORTED OS ***"
#endif  /* D_OS_xxx */


/********************************** EOF *************************************/

#endif
