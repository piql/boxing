/*****************************************************************************
**
**  Implementation of the bitutils interface
**
**  Creation date:  2016/06/28
**  Created by:     Piql
**
**
**  Copyright (c) 2016 Piql AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/

//  PROJECT INCLUDES
//
#include "boxing/math/bitutils.h"


/*! 
  * \addtogroup math
  * \{
  */


//----------------------------------------------------------------------------
/*!
 *  \def BIT_IS_ON(byte_array, position) bitutils.h
 *  \brief Macro for determining the status of a bit in a byte array.
 *
 *  Macro for determining the status of a bit in a byte array.
 *
 *  \param[in]  byte_array  Byte Array.
 *  \param[in]  position    Bit position.
 */


//----------------------------------------------------------------------------
/*!
 *  \def BIT_SET_ON(byte_array, position) bitutils.h
 *  \brief Macro for setting the specified bit in a byte array.
 *
 *  Macro for setting the specified bit in a byte array.
 *
 *  \param[in]  byte_array  Byte Array.
 *  \param[in]  position    Bit position.
 */


//----------------------------------------------------------------------------
/*!
 *  \def BIT_SET_OFF(byte_array, position) bitutils.h
 *  \brief Macro for resetting the specified bit in a byte array.
 *
 *  Macro for resetting the specified bit in a byte array.
 *
 *  \param[in]  byte_array  Byte Array.
 *  \param[in]  position    Bit position.
 */


//----------------------------------------------------------------------------
/*!
 *  \brief Convert the byte encoding uint64_t values to big-endian order.
 *
 *  This function convert the byte encoding uint64_t values from the byte order
 *  that the current CPU (the "host") uses, to big-endian byte order.
 *
 *  \param[in]  hostlonglong   uint64_t value.
 *  \return converted uint64_t value.
 */

uint64_t htobell(uint64_t hostlonglong);


//----------------------------------------------------------------------------
/*!
 *  \brief Convert the byte encoding uint32_t values to big-endian order.
 *
 *  This function convert the byte encoding uint32_t values from the byte order
 *  that the current CPU (the "host") uses, to big-endian byte order.
 *
 *  \param[in]  hostlong   uint32_t value.
 *  \return converted uint32_t value.
 */

uint32_t htobel(uint32_t hostlong);


//----------------------------------------------------------------------------
/*!
 *  \brief Convert the byte encoding uint16_t values to big-endian order.
 *
 *  This function convert the byte encoding uint16_t values from the byte order
 *  that the current CPU (the "host") uses, to big-endian byte order.
 *
 *  \param[in]  hostshort   uint16_t value.
 *  \return converted uint16_t value.
 */

uint16_t htobes(uint16_t hostshort);


//----------------------------------------------------------------------------
/*!
 *  \brief Convert uint64_t values from big-endian order to host byte order.
 *
 *  This function convert the byte encoding uint64_t values from the big-endian byte order
 *  to the byte order that the current CPU (the "host") uses.
 *
 *  \param[in]  belonglong   uint64_t value.
 *  \return converted uint64_t value.
 */

uint64_t betohll(uint64_t belonglong);


//----------------------------------------------------------------------------
/*!
 *  \brief Convert uint32_t values from big-endian order to host byte order.
 *
 *  This function convert the byte encoding uint32_t values from the big-endian byte order
 *  to the byte order that the current CPU (the "host") uses.
 *
 *  \param[in]  belong   uint32_t value.
 *  \return converted uint32_t value.
 */

uint32_t betohl(uint32_t belong);


//----------------------------------------------------------------------------
/*!
 *  \brief Convert uint16_t values from big-endian order to host byte order.
 *
 *  This function convert the byte encoding uint16_t values from the big-endian byte order
 *  to the byte order that the current CPU (the "host") uses.
 *
 *  \param[in]  beshort   uint16_t value.
 *  \return converted uint16_t value.
 */

uint16_t betohs(uint16_t beshort);


//----------------------------------------------------------------------------
/*!
  * \} end of math group
  */
