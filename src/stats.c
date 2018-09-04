/*****************************************************************************
**
**  Storing the description of statistical structures
**
**  Creation date:  2017/07/12
**  Created by:     Oleksandr Ivanov
**
**
**  Copyright (c) 2014 Piql AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/


/*! 
  * \addtogroup unbox
  * \{
  */


//----------------------------------------------------------------------------
/*!
 *  \struct  boxing_stats_decode_s  stats.h
 *  \brief   Boxing decode statistic
 *
 *  \param resolved_errors         Number of resolver boxing errors. 
 *  \param unresolved_errors       Number of unresolver boxing errors.
 *  \param fec_accumulated_amount  FEC accumulated amount.
 *  \param fec_accumulated_weight  FEC accumulated weight.
 *
 *  The struct with statistic information about boxing process.
 */


//----------------------------------------------------------------------------
/*!
 *  \struct  boxing_stats_mtf_s  stats.h
 *  \brief   Boxing decode mtf statistic 
 *
 *  \param top_horizontal_mtf     Top horizontal mtf.
 *  \param bottom_horizontal_mtf  Bottom horizontal mtf.
 *  \param left_vertical_mtf      Left vertical mtf.
 *  \param right_vertical_mtf     Right vertical mtf.
 *
 *  The struct with mtf statistic information about boxing process.
 */


//----------------------------------------------------------------------------
/*!
 *  \struct  boxing_reference_bar_stats_s  stats.h
 *  \brief   Boxing decode reference bar statistic 
 *
 *  \param top_mtf       Top mtf.
 *  \param bottom_mtf    Bottom mtf.
 *  \param left_mtf      Left mtf.
 *  \param right_mtf     Right mtf.
 *
 *  The struct with reference bar mtf statistic information about boxing process.
 */


//----------------------------------------------------------------------------
/*!
  * \} end of unbox group
  */


typedef int remove_iso_compilers_warning; // Unused type definition to avoid warnings - ISO C requires a translation unit to contain at least one declaration
