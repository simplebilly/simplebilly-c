/*
 * plugin_pricing_one_of_1.h
 *
 * 
 */

#ifndef _plugin_pricing_one_of_1_H_
#define _plugin_pricing_one_of_1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plugin_pricing_one_of_1_t plugin_pricing_one_of_1_t;


// Enum TYPE for plugin_pricing_one_of_1

typedef enum  { simplebilly_api_plugin_pricing_one_of_1_TYPE_NULL = 0, simplebilly_api_plugin_pricing_one_of_1_TYPE_one_time } simplebilly_api_plugin_pricing_one_of_1_TYPE_e;

char* plugin_pricing_one_of_1_type_ToString(simplebilly_api_plugin_pricing_one_of_1_TYPE_e type);

simplebilly_api_plugin_pricing_one_of_1_TYPE_e plugin_pricing_one_of_1_type_FromString(char* type);



typedef struct plugin_pricing_one_of_1_t {
    double *price; //numeric
    simplebilly_api_plugin_pricing_one_of_1_TYPE_e type; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} plugin_pricing_one_of_1_t;

__attribute__((deprecated)) plugin_pricing_one_of_1_t *plugin_pricing_one_of_1_create(
    double *price,
    simplebilly_api_plugin_pricing_one_of_1_TYPE_e type
);

void plugin_pricing_one_of_1_free(plugin_pricing_one_of_1_t *plugin_pricing_one_of_1);

plugin_pricing_one_of_1_t *plugin_pricing_one_of_1_parseFromJSON(cJSON *plugin_pricing_one_of_1JSON);

cJSON *plugin_pricing_one_of_1_convertToJSON(plugin_pricing_one_of_1_t *plugin_pricing_one_of_1);

#endif /* _plugin_pricing_one_of_1_H_ */

