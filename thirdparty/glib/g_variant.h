/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/.
 */

/*
 * Modified by Piql: Added custom types.
 */

#ifndef G_VARIANT_H
#define G_VARIANT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "boxing/bool.h"

#include "boxing/math/math.h"

typedef enum
{
    G_VARIANT_POINTER,
    G_VARIANT_INT,
    G_VARIANT_UINT,
    G_VARIANT_LONGLONG,
    G_VARIANT_ULONGLONG,
    G_VARIANT_FLOAT,
    G_VARIANT_DOUBLE,
    G_VARIANT_STRING,
    G_VARIANT_POINTI
} g_variant_type;

typedef struct
{
    g_variant_type type;
    void * data;
} g_variant;

g_variant * g_variant_create_pointer(void * value);
g_variant * g_variant_create_int(int value);
g_variant * g_variant_create_uint(unsigned int value);
g_variant * g_variant_create_longlong(long long value);
g_variant * g_variant_create_ulonglong(unsigned long long value);
g_variant * g_variant_create_float(float value);
g_variant * g_variant_create_double(double value);
g_variant * g_variant_create_string(const char * value);
g_variant * g_variant_create_pointi(boxing_pointi point);
g_variant * g_variant_create(const char * value);
g_variant * g_variant_clone(const g_variant * variant);

void                g_variant_free(g_variant * variant);

void                g_variant_set_uint(g_variant * variant, unsigned int value);

int                 g_variant_to_int(const g_variant * variant);
unsigned int        g_variant_to_uint(const g_variant * variant);
long long           g_variant_to_longlong(const g_variant * variant);
unsigned long long  g_variant_to_ulonglong(const g_variant * variant);
int                 g_variant_to_bool(const g_variant * variant); // 1 - true, 0 - false
char *              g_variant_to_string(const g_variant * variant);// String is allocated here and the caller is responsible for freeing
boxing_pointi       g_variant_to_pointi(const g_variant * variant, DBOOL * success); // you can pass NULL as success
char *              g_variant_if_string(const g_variant * variant);// String is NOT allocated here, the existing string is returned IF the variant is a string.
DBOOL               g_variant_equals(const g_variant *a, const g_variant *b);

#ifdef __cplusplus
}
#endif


#endif
