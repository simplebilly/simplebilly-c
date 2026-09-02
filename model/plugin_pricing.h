/*
 * plugin_pricing.h
 *
 * How a plugin is priced in the marketplace. Tagged on &#x60;type&#x60; so the same enum deserializes both the API DTO and the &#x60;plugin_marketplace.json&#x60; manifest (&#x60;{\&quot;type\&quot;:\&quot;free\&quot;}&#x60; / &#x60;{\&quot;type\&quot;:\&quot;one_time\&quot;,\&quot;price\&quot;:99.0}&#x60; / &#x60;{\&quot;type\&quot;:\&quot;recurring\&quot;,\&quot;price_per_month\&quot;:19.9}&#x60;).
 */

#ifndef _plugin_pricing_H_
#define _plugin_pricing_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plugin_pricing_t plugin_pricing_t;

#include "plugin_pricing_one_of.h"
#include "plugin_pricing_one_of_1.h"
#include "plugin_pricing_one_of_2.h"

// Enum TYPE for plugin_pricing

typedef enum  { simplebilly_api_plugin_pricing_TYPE_NULL = 0, simplebilly_api_plugin_pricing_TYPE_free, simplebilly_api_plugin_pricing_TYPE_one_time, simplebilly_api_plugin_pricing_TYPE_recurring } simplebilly_api_plugin_pricing_TYPE_e;

char* plugin_pricing_type_ToString(simplebilly_api_plugin_pricing_TYPE_e type);

simplebilly_api_plugin_pricing_TYPE_e plugin_pricing_type_FromString(char* type);



typedef struct plugin_pricing_t {
    simplebilly_api_plugin_pricing_TYPE_e type; //enum
    double *price; //numeric
    double *price_per_month; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} plugin_pricing_t;

__attribute__((deprecated)) plugin_pricing_t *plugin_pricing_create(
    simplebilly_api_plugin_pricing_TYPE_e type,
    double *price,
    double *price_per_month
);

void plugin_pricing_free(plugin_pricing_t *plugin_pricing);

plugin_pricing_t *plugin_pricing_parseFromJSON(cJSON *plugin_pricingJSON);

cJSON *plugin_pricing_convertToJSON(plugin_pricing_t *plugin_pricing);

#endif /* _plugin_pricing_H_ */

