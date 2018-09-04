/*****************************************************************************
**
**  Implementation of the unboxing utility
**
**  Creation date:  2017/04/05
**  Created by:     Aleksandr Ivanov
**
**
**  Copyright (c) 2017 Piql AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/

//  PROJECT INCLUDES
//

#include "unboxingutility.h"
#include "boxing/platform/memory.h"
#include "boxing/string.h"
#include "boxing/config.h"
#include "boxing_config.h"

//----------------------------------------------------------------------------
/*!
 *  \ingroup testutils
 *  \struct  boxing_unboxer_utility_s   unboxingutility.h
 *  \brief   Utility structure to unboxing data.
 *
 *  \param unboxer               Boxer instance.
 *  \param parameters            Structure to storage unboxer parameters..
 *
 *  Structure to storage all neccessary tools to unboxing data.
 */


// PUBLIC UNBOXING UTILITY FUNCTIONS
//


#ifdef BOXINGLIB_CALLBACK
//----------------------------------------------------------------------------
/*!
 *  \brief The function creates a structure for unboxing data.
 *
 *  The function creates a structure for unboxing data with all neccessary tools.
 *  If creates is successful, then function return instance, else function return NULL.
 *
 *  \ingroup testutils
 *  \param[in]   format_name           Format name for data boxing.
 *  \param[in]   is_raw                A sign that the input data is generated.
 *  \param[in]   on_all_complete       Pointer to a function that is called after the end of unboxing.
 *  \param[in]   on_metadata_complete  Pointer to a function that is called after the completion of metadata generation.
 *  \return instance of boxing_unboxer_utility structure or NULL.
 */
boxing_unboxer_utility* boxing_unboxer_utility_create(const char* format_name, DBOOL is_raw, boxing_all_complete_cb on_all_complete, boxing_metadata_complete_cb  on_metadata_complete)
#else
//----------------------------------------------------------------------------
/*!
 *  \brief The function creates a structure for unboxing data.
 *
 *  The function creates a structure for unboxing data with all neccessary tools.
 *  If creates is successful, then function return instance, else function return NULL.
 *
 *  \ingroup testutils
 *  \param[in]   format_name           Format name for data boxing.
 *  \param[in]   is_raw                A sign that the input data is generated.
 *  \return instance of boxing_unboxer_utility structure or NULL.
 */
boxing_unboxer_utility* boxing_unboxer_utility_create(const char* format_name, DBOOL is_raw)
#endif
{
    // Check the input data
    if (format_name == NULL)
    {
        return NULL;
    }

    // Create an instance of the object
    boxing_unboxer_utility* utility = BOXING_MEMORY_ALLOCATE_TYPE(boxing_unboxer_utility);
    utility->unboxer = NULL;
    utility->parameters = NULL;

    // Create structure of boxing configuration parameters
    utility->parameters = BOXING_MEMORY_ALLOCATE_TYPE(boxing_unboxer_parameters);
    boxing_unboxer_parameters_init(utility->parameters);
    boxing_memory_clear(utility->parameters, sizeof(utility->parameters));

    // Setting the frame format by its name
    if (boxing_unboxer_set_frame_format(utility, format_name) == DFALSE)
    {
        return NULL;
    }

    // Set the parameters
    utility->parameters->is_raw = is_raw;
#ifdef BOXINGLIB_CALLBACK
    utility->parameters->on_all_complete = on_all_complete;
    utility->parameters->on_metadata_complete = on_metadata_complete;
#endif

    // Create the unboxer structure
    utility->unboxer = boxing_unboxer_create(utility->parameters);

    return utility;
}


//----------------------------------------------------------------------------
/*!
 *  \brief The function sets the frame format by its name.
 *
 *  The function sets the frame format by its name.
 *  If sets is successful, then function return DTRUE, else function return DFALSE.
 *
 *  \ingroup testutils
 *  \param[in]   utility           Instance of boxing_unboxer_utility structure.
 *  \param[in]   format_name       Name of the format.
 *  \return sign of successful completion of the function.
 */

DBOOL boxing_unboxer_set_frame_format(boxing_unboxer_utility* utility, const char* format_name)
{
    if (utility == NULL || format_name == NULL)
    {
        return DFALSE;
    }

    if (utility->parameters == NULL)
    {
        return DFALSE;
    }

    // Create an instance of the configuration
    boxing_config * config = boxing_get_boxing_config(format_name);

    // Set the format
    utility->parameters->format = config;

    return DTRUE;
}


//----------------------------------------------------------------------------
/*!
 *  \brief The function makes data unboxing.
 *
 *  The function processes the input image data and generates a source file data.
 *  If the input unboxer_utility instance is NULL or input image pointer is NULL then the function returns an error.
 *
 *  \ingroup testutils
 *  \param[in]   unboxer_utility  Unboxing utility instance.
 *  \param[in]   input_image      Input image instance.
 *  \param[out]  output_data      Output source file data.
 *  \return process result.
 */

int boxing_unboxer_utility_unbox(boxing_unboxer_utility* unboxer_utility, boxing_image8* input_image, gvector* output_data)
{
    if (unboxer_utility == NULL || input_image == NULL)
    {
        return BOXING_UNBOXER_INPUT_DATA_ERROR;
    }

    boxing_metadata_list *metadata = boxing_metadata_list_create();
    
    int extract_result;
    int process_result = boxing_unboxer_unbox(output_data, metadata, input_image, unboxer_utility->unboxer, &extract_result, output_data);
	 
    boxing_metadata_list_free(metadata);

    return process_result;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Frees occupied memory of boxing_unboxer_utility structure.
 *
 *  Frees occupied memory of all internal structure pointers and structure pointer.
 *
 *  \ingroup testutils
 *  \param[in]   unboxer_utility  Unboxing utility instance.
 */

void boxing_unboxer_utility_free(boxing_unboxer_utility* unboxer_utility)
{
    if (unboxer_utility != NULL)
    {
        boxing_config_free((boxing_config *)unboxer_utility->parameters->format);
        boxing_unboxer_free(unboxer_utility->unboxer);
        boxing_unboxer_parameters_free(unboxer_utility->parameters);
        boxing_memory_free(unboxer_utility->parameters);
    }

    boxing_memory_free(unboxer_utility);
}
