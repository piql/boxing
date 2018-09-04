/*****************************************************************************
**
**  Boxinglib global definitions
**
**  Creation date:  2015/10/24
**  Created by:     Piql AS
**
**
**  Copyright (c) 2015 Piql AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/

//  PROJECT INCLUDES
//

#include "boxing/globals.h"


//----------------------------------------------------------------------------
/*! 
  * \addtogroup unbox
  * \{
  */


//  CONSTANTS
//

//----------------------------------------------------------------------------
/*!
  * Node name for class node. All node names are lowercase.
  */

const char * CONFIG_XML_NODE_CLASS = "class";

//----------------------------------------------------------------------------
/*!
  * Node name for property node. All attribute names are lowercase.
  */

const char * CONFIG_XML_NODE_PROPERTY = "property";

//----------------------------------------------------------------------------
/*!
  * Name for attribute attribute. All attribute names are lowercase.
  */

const char * CONFIG_XML_ATTR_NAME = "key";

//----------------------------------------------------------------------------
/*!
  * Name for value attribute. All attribute names are lowercase.
  */

const char * CONFIG_XML_ATTR_VALUE = "value";

//----------------------------------------------------------------------------
/*!
  * Name for key alias.
  */

const char * CONFIG_XML_KEY_ALIAS = "alias";

//----------------------------------------------------------------------------
/*!
  * Name for version attribute. All attribute names are lowercase.
  */

const char * CONFIG_XML_ATTR_VERSION = "version";


//----------------------------------------------------------------------------
/*!
  * Forward error correction process string.
  */

const char * FORWARD_ERROR_CORRECTION_PROCESS  = "process";


//----------------------------------------------------------------------------
/**
  * Frame builder block size property key.
  */
const char * FRAME_BUILDER_BLOCKSIZE               = "blockSize"; // deprecated, use FRAME_BUILDER_SCALINGFACTOR instead

//----------------------------------------------------------------------------
/**
  * Frame builder scaling factor property key.
  */

const char * FRAME_BUILDER_SCALINGFACTOR           = "scalingFactor";

//----------------------------------------------------------------------------
/**
  * Frame builder color depth property key.
  */

const char * FRAME_BUILDER_COLORDEPTH              = "colorDepth";

//----------------------------------------------------------------------------
/**
  * Frame builder print color depth property key.
  */

const char * FRAME_BUILDER_PRINTCOLORDEPTH         = "printColorDepth";

//----------------------------------------------------------------------------
/**
  * Frame builder frame number property key.
  */

const char * FRAME_BUILDER_FRAMENUMBER             = "frameNumber";

//----------------------------------------------------------------------------
/**
  * Image raw version property key.
  */

const char * IMAGERAW_RAW_VERSION                  = "rawVersion";


//----------------------------------------------------------------------------
/*!
  * \} end of unbox group
  */
