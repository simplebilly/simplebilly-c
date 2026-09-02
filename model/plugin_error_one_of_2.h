/*
 * plugin_error_one_of_2.h
 *
 * 
 */

#ifndef _plugin_error_one_of_2_H_
#define _plugin_error_one_of_2_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plugin_error_one_of_2_t plugin_error_one_of_2_t;

#include "object.h"



typedef struct plugin_error_one_of_2_t {
    list_t *unauthorized; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} plugin_error_one_of_2_t;

__attribute__((deprecated)) plugin_error_one_of_2_t *plugin_error_one_of_2_create(
    list_t *unauthorized
);

void plugin_error_one_of_2_free(plugin_error_one_of_2_t *plugin_error_one_of_2);

plugin_error_one_of_2_t *plugin_error_one_of_2_parseFromJSON(cJSON *plugin_error_one_of_2JSON);

cJSON *plugin_error_one_of_2_convertToJSON(plugin_error_one_of_2_t *plugin_error_one_of_2);

#endif /* _plugin_error_one_of_2_H_ */

