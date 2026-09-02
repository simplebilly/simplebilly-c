/*
 * plugin_pricing_one_of.h
 *
 * 
 */

#ifndef _plugin_pricing_one_of_H_
#define _plugin_pricing_one_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plugin_pricing_one_of_t plugin_pricing_one_of_t;


// Enum TYPE for plugin_pricing_one_of

typedef enum  { simplebilly_api_plugin_pricing_one_of_TYPE_NULL = 0, simplebilly_api_plugin_pricing_one_of_TYPE_free } simplebilly_api_plugin_pricing_one_of_TYPE_e;

char* plugin_pricing_one_of_type_ToString(simplebilly_api_plugin_pricing_one_of_TYPE_e type);

simplebilly_api_plugin_pricing_one_of_TYPE_e plugin_pricing_one_of_type_FromString(char* type);



typedef struct plugin_pricing_one_of_t {
    simplebilly_api_plugin_pricing_one_of_TYPE_e type; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} plugin_pricing_one_of_t;

__attribute__((deprecated)) plugin_pricing_one_of_t *plugin_pricing_one_of_create(
    simplebilly_api_plugin_pricing_one_of_TYPE_e type
);

void plugin_pricing_one_of_free(plugin_pricing_one_of_t *plugin_pricing_one_of);

plugin_pricing_one_of_t *plugin_pricing_one_of_parseFromJSON(cJSON *plugin_pricing_one_ofJSON);

cJSON *plugin_pricing_one_of_convertToJSON(plugin_pricing_one_of_t *plugin_pricing_one_of);

#endif /* _plugin_pricing_one_of_H_ */

