#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plugin_pricing.h"


char* plugin_pricing_type_ToString(simplebilly_api_plugin_pricing_TYPE_e type) {
    char* typeArray[] =  { "NULL", "free", "one_time", "recurring" };
    return typeArray[type];
}

simplebilly_api_plugin_pricing_TYPE_e plugin_pricing_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "free", "one_time", "recurring" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static plugin_pricing_t *plugin_pricing_create_internal(
    simplebilly_api_plugin_pricing_TYPE_e type,
    double *price,
    double *price_per_month
    ) {
    plugin_pricing_t *plugin_pricing_local_var = malloc(sizeof(plugin_pricing_t));
    if (!plugin_pricing_local_var) {
        return NULL;
    }
    memset(plugin_pricing_local_var, 0, sizeof(plugin_pricing_t));
    plugin_pricing_local_var->_library_owned = 1;
    plugin_pricing_local_var->type = type;
    plugin_pricing_local_var->price = price;
    plugin_pricing_local_var->price_per_month = price_per_month;
    return plugin_pricing_local_var;
}

__attribute__((deprecated)) plugin_pricing_t *plugin_pricing_create(
    simplebilly_api_plugin_pricing_TYPE_e type,
    double *price,
    double *price_per_month
    ) {
    double *price_copy = NULL;
    if (price) {
        price_copy = malloc(sizeof(double));
        if (price_copy) *price_copy = *price;
    }
    double *price_per_month_copy = NULL;
    if (price_per_month) {
        price_per_month_copy = malloc(sizeof(double));
        if (price_per_month_copy) *price_per_month_copy = *price_per_month;
    }
    plugin_pricing_t *result = plugin_pricing_create_internal (
        type,
        price_copy,
        price_per_month_copy
        );
    if (!result) {
        free(price_copy);
        free(price_per_month_copy);
    }
    return result;
}

void plugin_pricing_free(plugin_pricing_t *plugin_pricing) {
    if(NULL == plugin_pricing){
        return ;
    }
    if(plugin_pricing->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plugin_pricing_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plugin_pricing->price) {
        free(plugin_pricing->price);
        plugin_pricing->price = NULL;
    }
    if (plugin_pricing->price_per_month) {
        free(plugin_pricing->price_per_month);
        plugin_pricing->price_per_month = NULL;
    }
    free(plugin_pricing);
}

cJSON *plugin_pricing_convertToJSON(plugin_pricing_t *plugin_pricing) {
    cJSON *item = cJSON_CreateObject();

    // plugin_pricing->type
    if (simplebilly_api_plugin_pricing_TYPE_NULL == plugin_pricing->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", plugin_pricing_type_ToString(plugin_pricing->type)) == NULL)
    {
    goto fail; //Enum
    }


    // plugin_pricing->price
    if (!plugin_pricing->price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "price", *plugin_pricing->price) == NULL) {
    goto fail; //Numeric
    }


    // plugin_pricing->price_per_month
    if (!plugin_pricing->price_per_month) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "price_per_month", *plugin_pricing->price_per_month) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plugin_pricing_t *plugin_pricing_parseFromJSON(cJSON *plugin_pricingJSON){

    plugin_pricing_t *plugin_pricing_local_var = NULL;

    // define the local variable for plugin_pricing->price
    double *price_local_var = NULL;

    // define the local variable for plugin_pricing->price_per_month
    double *price_per_month_local_var = NULL;

    // plugin_pricing->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(plugin_pricingJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    simplebilly_api_plugin_pricing_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = plugin_pricing_type_FromString(type->valuestring);

    // plugin_pricing->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(plugin_pricingJSON, "price");
    if (cJSON_IsNull(price)) {
        price = NULL;
    }
    if (!price) {
        goto end;
    }

    
    if(!cJSON_IsNumber(price))
    {
    goto end; //Numeric
    }
    price_local_var = malloc(sizeof(double));
    if(!price_local_var)
    {
        goto end;
    }
    *price_local_var = price->valuedouble;

    // plugin_pricing->price_per_month
    cJSON *price_per_month = cJSON_GetObjectItemCaseSensitive(plugin_pricingJSON, "price_per_month");
    if (cJSON_IsNull(price_per_month)) {
        price_per_month = NULL;
    }
    if (!price_per_month) {
        goto end;
    }

    
    if(!cJSON_IsNumber(price_per_month))
    {
    goto end; //Numeric
    }
    price_per_month_local_var = malloc(sizeof(double));
    if(!price_per_month_local_var)
    {
        goto end;
    }
    *price_per_month_local_var = price_per_month->valuedouble;



    plugin_pricing_local_var = plugin_pricing_create_internal (
        typeVariable,
        price_local_var,
        price_per_month_local_var
        );

    if (!plugin_pricing_local_var) {
        goto end;
    }

    return plugin_pricing_local_var;
end:
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    if (price_per_month_local_var) {
        free(price_per_month_local_var);
        price_per_month_local_var = NULL;
    }
    return NULL;

}
