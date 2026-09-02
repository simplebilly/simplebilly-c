/*
 * plugin_error_one_of_4.h
 *
 * 
 */

#ifndef _plugin_error_one_of_4_H_
#define _plugin_error_one_of_4_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plugin_error_one_of_4_t plugin_error_one_of_4_t;

#include "object.h"



typedef struct plugin_error_one_of_4_t {
    list_t *database_error; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} plugin_error_one_of_4_t;

__attribute__((deprecated)) plugin_error_one_of_4_t *plugin_error_one_of_4_create(
    list_t *database_error
);

void plugin_error_one_of_4_free(plugin_error_one_of_4_t *plugin_error_one_of_4);

plugin_error_one_of_4_t *plugin_error_one_of_4_parseFromJSON(cJSON *plugin_error_one_of_4JSON);

cJSON *plugin_error_one_of_4_convertToJSON(plugin_error_one_of_4_t *plugin_error_one_of_4);

#endif /* _plugin_error_one_of_4_H_ */

