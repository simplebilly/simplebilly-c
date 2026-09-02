/*
 * plugin_error.h
 *
 * 
 */

#ifndef _plugin_error_H_
#define _plugin_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plugin_error_t plugin_error_t;

#include "object.h"
#include "plugin_error_one_of.h"
#include "plugin_error_one_of_1.h"
#include "plugin_error_one_of_2.h"
#include "plugin_error_one_of_3.h"
#include "plugin_error_one_of_4.h"
#include "plugin_error_one_of_5.h"
#include "plugin_error_one_of_6.h"



typedef struct plugin_error_t {
    list_t *bad_request; //nonprimitive container
    list_t *not_found; //nonprimitive container
    list_t *unauthorized; //nonprimitive container
    list_t *internal_error; //nonprimitive container
    list_t *database_error; //nonprimitive container
    list_t *validation_error; //nonprimitive container
    char *not_implemented; // string

    int _library_owned; // Is the library responsible for freeing this object?
} plugin_error_t;

__attribute__((deprecated)) plugin_error_t *plugin_error_create(
    list_t *bad_request,
    list_t *not_found,
    list_t *unauthorized,
    list_t *internal_error,
    list_t *database_error,
    list_t *validation_error,
    char *not_implemented
);

void plugin_error_free(plugin_error_t *plugin_error);

plugin_error_t *plugin_error_parseFromJSON(cJSON *plugin_errorJSON);

cJSON *plugin_error_convertToJSON(plugin_error_t *plugin_error);

#endif /* _plugin_error_H_ */

