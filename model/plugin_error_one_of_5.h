/*
 * plugin_error_one_of_5.h
 *
 * 
 */

#ifndef _plugin_error_one_of_5_H_
#define _plugin_error_one_of_5_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plugin_error_one_of_5_t plugin_error_one_of_5_t;

#include "object.h"



typedef struct plugin_error_one_of_5_t {
    list_t *validation_error; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} plugin_error_one_of_5_t;

__attribute__((deprecated)) plugin_error_one_of_5_t *plugin_error_one_of_5_create(
    list_t *validation_error
);

void plugin_error_one_of_5_free(plugin_error_one_of_5_t *plugin_error_one_of_5);

plugin_error_one_of_5_t *plugin_error_one_of_5_parseFromJSON(cJSON *plugin_error_one_of_5JSON);

cJSON *plugin_error_one_of_5_convertToJSON(plugin_error_one_of_5_t *plugin_error_one_of_5);

#endif /* _plugin_error_one_of_5_H_ */

