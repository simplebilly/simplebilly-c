/*
 * plugin_error_one_of_6.h
 *
 * 
 */

#ifndef _plugin_error_one_of_6_H_
#define _plugin_error_one_of_6_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plugin_error_one_of_6_t plugin_error_one_of_6_t;




typedef struct plugin_error_one_of_6_t {
    char *not_implemented; // string

    int _library_owned; // Is the library responsible for freeing this object?
} plugin_error_one_of_6_t;

__attribute__((deprecated)) plugin_error_one_of_6_t *plugin_error_one_of_6_create(
    char *not_implemented
);

void plugin_error_one_of_6_free(plugin_error_one_of_6_t *plugin_error_one_of_6);

plugin_error_one_of_6_t *plugin_error_one_of_6_parseFromJSON(cJSON *plugin_error_one_of_6JSON);

cJSON *plugin_error_one_of_6_convertToJSON(plugin_error_one_of_6_t *plugin_error_one_of_6);

#endif /* _plugin_error_one_of_6_H_ */

