/*****************************************************************************
**
**  Implementation of the logging interface
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
#include "boxing/log.h"

#if !defined (DLOG_DISABLED)
//  PRIVATE INTERFACE
//

static void def_boxing_fatal_exception(const char * str);


/*! 
  * \addtogroup unbox
  * \{
  */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_LEVEL_INFO() log.h
 *  \brief Info log level.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_LEVEL_WARNING() log.h
 *  \brief Warning log level.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_LEVEL_ERROR() log.h
 *  \brief Error log level.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_LEVEL_FATAL() log.h
 *  \brief Fatal log level.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DFATAL(expression, string) log.h
 *  \brief DFATAL execption.
 *
 *  DFATAL if expression is false the application will abort.
 *
 *  \param[in]  expression  Expression.
 *  \param[in]  string      Log string.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_FATAL(string) log.h
 *  \brief Fatal log message.
 *
 *  \param[in]  string  Log string.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_FATAL1(string, var1) log.h
 *  \brief Fatal log message with one argument.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_FATAL2(string, var1, var2) log.h
 *  \brief Fatal log message with two arguments.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First arguments.
 *  \param[in]  var2    Second arguments.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_FATAL3(string, var1, var2, var3) log.h
 *  \brief Fatal log message with three arguments.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 *  \param[in]  var2    Second argument.
 *  \param[in]  var3    Third argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_FATAL4(string, var1, var2, var3, var4) log.h
 *  \brief Fatal log message with four arguments.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 *  \param[in]  var2    Second argument.
 *  \param[in]  var3    Third argument.
 *  \param[in]  var4    Fourth argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_ERROR(string) log.h
 *  \brief Error log message.
 *
 *  \param[in]  string  Log string.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_ERROR1(string, var1) log.h
 *  \brief Error log macro with one argument.
 *
 *  Error log macro with one argument.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_ERROR2(string, var1, var2) log.h
 *  \brief Error log macro with two arguments.
 *
 *  Error log macro with two arguments.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 *  \param[in]  var2    Second argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_ERROR3(string, var1, var2, var3) log.h
 *  \brief Error log macro with three arguments.
 *
 *  Error log macro with three arguments.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 *  \param[in]  var2    Second argument.
 *  \param[in]  var3    Third argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_ERROR4(string, var1, var2, var3, var4) log.h
 *  \brief Error log macro with four arguments.
 *
 *  Error log macro with four arguments.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 *  \param[in]  var2    Second argument.
 *  \param[in]  var3    Third argument.
 *  \param[in]  var4    Fourth argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_WARNING(string) log.h
 *  \brief Warning log macro.
 *
 *  Warning log macro description.
 *
 *  \param[in]  string  Log string.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_WARNING1(string, var1) log.h
 *  \brief Warning log macro with one argument.
 *
 *  Warning log macro with one argument.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_WARNING2(string, var1, var2) log.h
 *  \brief Warning log macro with two arguments.
 *
 *  Warning log macro with two arguments.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 *  \param[in]  var2    Second argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_WARNING3(string, var1, var2, var3) log.h
 *  \brief Warning log macro with three arguments.
 *
 *  Warning log macro with three arguments.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 *  \param[in]  var2    Second argument.
 *  \param[in]  var3    Third argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_WARNING4(string, var1, var2, var3, var4) log.h
 *  \brief Warning log macro with four arguments.
 *
 *  Warning log macro with four arguments.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 *  \param[in]  var2    Second argument.
 *  \param[in]  var3    Third argument.
 *  \param[in]  var4    Fourth argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_INFO(string) log.h
 *  \brief Information log macro.
 *
 *  Information log macro description.
 *
 *  \param[in]  string  Log string.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_INFO1(string, var1) log.h
 *  \brief Information log macro with one argument.
 *
 *  Information log macro with one argument.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_INFO2(string, var1, var2) log.h
 *  \brief Information log macro with two arguments.
 *
 *  Information log macro with two arguments.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 *  \param[in]  var2    Second argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_INFO3(string, var1, var2, var3) log.h
 *  \brief Information log macro with three arguments.
 *
 *  Information log macro with three arguments.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 *  \param[in]  var2    Second argument.
 *  \param[in]  var3    Third argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def DLOG_INFO4(string, var1, var2, var3, var4) log.h
 *  \brief Information log macro with four arguments.
 *
 *  Information log macro with four arguments.
 *
 *  \param[in]  string  Log string.
 *  \param[in]  var1    First argument.
 *  \param[in]  var2    Second argument.
 *  \param[in]  var3    Third argument.
 *  \param[in]  var4    Fourth argument.
 */


//----------------------------------------------------------------------------
/*!
 *  \def boxing_throw(a) log.h
 *  \brief Throw the a argument.
 *
 *  Throw the a argument.
 *
 *  \param[in]  a  Throw argument.
 */


/*! 
 *  \typedef void (*boxing_log_custom)(int log_level, const char * string)
 *  \brief Function to define custom log.
 *
 *  \param[in] log_level  Log level.
 *  \param[in] string     Log string.
 *   
 *  Function to define custom log.
 */


/*! 
 *  \typedef void (*boxing_log_args_custom)(int log_level, const char * format, va_list args)
 *  \brief Function to define args custom log.
 *
 *  \param[in] log_level  Log level.
 *  \param[in] format     Format string.
 *  \param[in] args       Va list.
 *   
 *  Function to define args custom log.
 */


/*! 
 *  \typedef void(*boxing_fatal_exception_cb_t)(const char * str)
 *  \brief Callback function for the fatal exeption.
 *
 *  \param[in] str  Fatal exeption string.
 *   
 *  Callback function for the fatal exeption.
 */


// PUBLIC LOG FUNCTIONS
//


//----------------------------------------------------------------------------
/*!
 *  \fn void boxing_log(int log_level, const char * string) log.h
 *  \brief Log function.
 *
 *  Log function description.
 *
 *  \param[in] log_level  Log level.
 *  \param[in] string     Log string.
 */


//----------------------------------------------------------------------------
/*!
 *  \fn void boxing_log_args(int log_level, const char * format, ...) log.h
 *  \brief Log args function.
 *
 *  Log args function description.
 *
 *  \param[in] log_level  Log level.
 *  \param[in] format     Log format string.
 */


boxing_fatal_exception_cb_t boxing_fatal_exception = &def_boxing_fatal_exception;


//----------------------------------------------------------------------------
/*!
  * \} end of unbox group
  */


// PRIVATE LOG FUNCTIONS
//

static void def_boxing_fatal_exception(const char * str)
{
    fprintf(stderr, "%s", str);
#ifdef _DEBUG
    abort();
#else
    exit(1);
#endif // _DEBUG
}

#endif // DLOG_DISABLED
