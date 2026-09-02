/*
 * plugin_pricing_one_of_2.h
 *
 * 
 */

#ifndef _plugin_pricing_one_of_2_H_
#define _plugin_pricing_one_of_2_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plugin_pricing_one_of_2_t plugin_pricing_one_of_2_t;


// Enum TYPE for plugin_pricing_one_of_2

typedef enum  { simplebilly_api_plugin_pricing_one_of_2_TYPE_NULL = 0, simplebilly_api_plugin_pricing_one_of_2_TYPE_recurring } simplebilly_api_plugin_pricing_one_of_2_TYPE_e;

char* plugin_pricing_one_of_2_type_ToString(simplebilly_api_plugin_pricing_one_of_2_TYPE_e type);

simplebilly_api_plugin_pricing_one_of_2_TYPE_e plugin_pricing_one_of_2_type_FromString(char* type);



typedef struct plugin_pricing_one_of_2_t {
    double *price_per_month; //numeric
    simplebilly_api_plugin_pricing_one_of_2_TYPE_e type; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} plugin_pricing_one_of_2_t;

__attribute__((deprecated)) plugin_pricing_one_of_2_t *plugin_pricing_one_of_2_create(
    double *price_per_month,
    simplebilly_api_plugin_pricing_one_of_2_TYPE_e type
);

void plugin_pricing_one_of_2_free(plugin_pricing_one_of_2_t *plugin_pricing_one_of_2);

plugin_pricing_one_of_2_t *plugin_pricing_one_of_2_parseFromJSON(cJSON *plugin_pricing_one_of_2JSON);

cJSON *plugin_pricing_one_of_2_convertToJSON(plugin_pricing_one_of_2_t *plugin_pricing_one_of_2);

#endif /* _plugin_pricing_one_of_2_H_ */

