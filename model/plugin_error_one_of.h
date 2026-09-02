/*
 * plugin_error_one_of.h
 *
 * 
 */

#ifndef _plugin_error_one_of_H_
#define _plugin_error_one_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plugin_error_one_of_t plugin_error_one_of_t;

#include "object.h"



typedef struct plugin_error_one_of_t {
    list_t *bad_request; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} plugin_error_one_of_t;

__attribute__((deprecated)) plugin_error_one_of_t *plugin_error_one_of_create(
    list_t *bad_request
);

void plugin_error_one_of_free(plugin_error_one_of_t *plugin_error_one_of);

plugin_error_one_of_t *plugin_error_one_of_parseFromJSON(cJSON *plugin_error_one_ofJSON);

cJSON *plugin_error_one_of_convertToJSON(plugin_error_one_of_t *plugin_error_one_of);

#endif /* _plugin_error_one_of_H_ */

