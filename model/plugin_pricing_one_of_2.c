#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plugin_pricing_one_of_2.h"


char* plugin_pricing_one_of_2_type_ToString(simplebilly_api_plugin_pricing_one_of_2_TYPE_e type) {
    char* typeArray[] =  { "NULL", "recurring" };
    return typeArray[type];
}

simplebilly_api_plugin_pricing_one_of_2_TYPE_e plugin_pricing_one_of_2_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "recurring" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static plugin_pricing_one_of_2_t *plugin_pricing_one_of_2_create_internal(
    double *price_per_month,
    simplebilly_api_plugin_pricing_one_of_2_TYPE_e type
    ) {
    plugin_pricing_one_of_2_t *plugin_pricing_one_of_2_local_var = malloc(sizeof(plugin_pricing_one_of_2_t));
    if (!plugin_pricing_one_of_2_local_var) {
        return NULL;
    }
    memset(plugin_pricing_one_of_2_local_var, 0, sizeof(plugin_pricing_one_of_2_t));
    plugin_pricing_one_of_2_local_var->_library_owned = 1;
    plugin_pricing_one_of_2_local_var->price_per_month = price_per_month;
    plugin_pricing_one_of_2_local_var->type = type;
    return plugin_pricing_one_of_2_local_var;
}

__attribute__((deprecated)) plugin_pricing_one_of_2_t *plugin_pricing_one_of_2_create(
    double *price_per_month,
    simplebilly_api_plugin_pricing_one_of_2_TYPE_e type
    ) {
    double *price_per_month_copy = NULL;
    if (price_per_month) {
        price_per_month_copy = malloc(sizeof(double));
        if (price_per_month_copy) *price_per_month_copy = *price_per_month;
    }
    plugin_pricing_one_of_2_t *result = plugin_pricing_one_of_2_create_internal (
        price_per_month_copy,
        type
        );
    if (!result) {
        free(price_per_month_copy);
    }
    return result;
}

void plugin_pricing_one_of_2_free(plugin_pricing_one_of_2_t *plugin_pricing_one_of_2) {
    if(NULL == plugin_pricing_one_of_2){
        return ;
    }
    if(plugin_pricing_one_of_2->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plugin_pricing_one_of_2_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plugin_pricing_one_of_2->price_per_month) {
        free(plugin_pricing_one_of_2->price_per_month);
        plugin_pricing_one_of_2->price_per_month = NULL;
    }
    free(plugin_pricing_one_of_2);
}

cJSON *plugin_pricing_one_of_2_convertToJSON(plugin_pricing_one_of_2_t *plugin_pricing_one_of_2) {
    cJSON *item = cJSON_CreateObject();

    // plugin_pricing_one_of_2->price_per_month
    if (!plugin_pricing_one_of_2->price_per_month) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "price_per_month", *plugin_pricing_one_of_2->price_per_month) == NULL) {
    goto fail; //Numeric
    }


    // plugin_pricing_one_of_2->type
    if (simplebilly_api_plugin_pricing_one_of_2_TYPE_NULL == plugin_pricing_one_of_2->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", plugin_pricing_one_of_2_type_ToString(plugin_pricing_one_of_2->type)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plugin_pricing_one_of_2_t *plugin_pricing_one_of_2_parseFromJSON(cJSON *plugin_pricing_one_of_2JSON){

    plugin_pricing_one_of_2_t *plugin_pricing_one_of_2_local_var = NULL;

    // define the local variable for plugin_pricing_one_of_2->price_per_month
    double *price_per_month_local_var = NULL;

    // plugin_pricing_one_of_2->price_per_month
    cJSON *price_per_month = cJSON_GetObjectItemCaseSensitive(plugin_pricing_one_of_2JSON, "price_per_month");
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

    // plugin_pricing_one_of_2->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(plugin_pricing_one_of_2JSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    simplebilly_api_plugin_pricing_one_of_2_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = plugin_pricing_one_of_2_type_FromString(type->valuestring);



    plugin_pricing_one_of_2_local_var = plugin_pricing_one_of_2_create_internal (
        price_per_month_local_var,
        typeVariable
        );

    if (!plugin_pricing_one_of_2_local_var) {
        goto end;
    }

    return plugin_pricing_one_of_2_local_var;
end:
    if (price_per_month_local_var) {
        free(price_per_month_local_var);
        price_per_month_local_var = NULL;
    }
    return NULL;

}
