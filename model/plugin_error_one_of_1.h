/*
 * plugin_error_one_of_1.h
 *
 * 
 */

#ifndef _plugin_error_one_of_1_H_
#define _plugin_error_one_of_1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plugin_error_one_of_1_t plugin_error_one_of_1_t;

#include "object.h"



typedef struct plugin_error_one_of_1_t {
    list_t *not_found; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} plugin_error_one_of_1_t;

__attribute__((deprecated)) plugin_error_one_of_1_t *plugin_error_one_of_1_create(
    list_t *not_found
);

void plugin_error_one_of_1_free(plugin_error_one_of_1_t *plugin_error_one_of_1);

plugin_error_one_of_1_t *plugin_error_one_of_1_parseFromJSON(cJSON *plugin_error_one_of_1JSON);

cJSON *plugin_error_one_of_1_convertToJSON(plugin_error_one_of_1_t *plugin_error_one_of_1);

#endif /* _plugin_error_one_of_1_H_ */

