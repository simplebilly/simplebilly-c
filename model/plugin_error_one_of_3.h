/*
 * plugin_error_one_of_3.h
 *
 * 
 */

#ifndef _plugin_error_one_of_3_H_
#define _plugin_error_one_of_3_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plugin_error_one_of_3_t plugin_error_one_of_3_t;

#include "object.h"



typedef struct plugin_error_one_of_3_t {
    list_t *internal_error; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} plugin_error_one_of_3_t;

__attribute__((deprecated)) plugin_error_one_of_3_t *plugin_error_one_of_3_create(
    list_t *internal_error
);

void plugin_error_one_of_3_free(plugin_error_one_of_3_t *plugin_error_one_of_3);

plugin_error_one_of_3_t *plugin_error_one_of_3_parseFromJSON(cJSON *plugin_error_one_of_3JSON);

cJSON *plugin_error_one_of_3_convertToJSON(plugin_error_one_of_3_t *plugin_error_one_of_3);

#endif /* _plugin_error_one_of_3_H_ */

