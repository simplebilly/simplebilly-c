#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plugin_pricing_one_of_1.h"


char* plugin_pricing_one_of_1_type_ToString(simplebilly_api_plugin_pricing_one_of_1_TYPE_e type) {
    char* typeArray[] =  { "NULL", "one_time" };
    return typeArray[type];
}

simplebilly_api_plugin_pricing_one_of_1_TYPE_e plugin_pricing_one_of_1_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "one_time" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static plugin_pricing_one_of_1_t *plugin_pricing_one_of_1_create_internal(
    double *price,
    simplebilly_api_plugin_pricing_one_of_1_TYPE_e type
    ) {
    plugin_pricing_one_of_1_t *plugin_pricing_one_of_1_local_var = malloc(sizeof(plugin_pricing_one_of_1_t));
    if (!plugin_pricing_one_of_1_local_var) {
        return NULL;
    }
    memset(plugin_pricing_one_of_1_local_var, 0, sizeof(plugin_pricing_one_of_1_t));
    plugin_pricing_one_of_1_local_var->_library_owned = 1;
    plugin_pricing_one_of_1_local_var->price = price;
    plugin_pricing_one_of_1_local_var->type = type;
    return plugin_pricing_one_of_1_local_var;
}

__attribute__((deprecated)) plugin_pricing_one_of_1_t *plugin_pricing_one_of_1_create(
    double *price,
    simplebilly_api_plugin_pricing_one_of_1_TYPE_e type
    ) {
    double *price_copy = NULL;
    if (price) {
        price_copy = malloc(sizeof(double));
        if (price_copy) *price_copy = *price;
    }
    plugin_pricing_one_of_1_t *result = plugin_pricing_one_of_1_create_internal (
        price_copy,
        type
        );
    if (!result) {
        free(price_copy);
    }
    return result;
}

void plugin_pricing_one_of_1_free(plugin_pricing_one_of_1_t *plugin_pricing_one_of_1) {
    if(NULL == plugin_pricing_one_of_1){
        return ;
    }
    if(plugin_pricing_one_of_1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plugin_pricing_one_of_1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plugin_pricing_one_of_1->price) {
        free(plugin_pricing_one_of_1->price);
        plugin_pricing_one_of_1->price = NULL;
    }
    free(plugin_pricing_one_of_1);
}

cJSON *plugin_pricing_one_of_1_convertToJSON(plugin_pricing_one_of_1_t *plugin_pricing_one_of_1) {
    cJSON *item = cJSON_CreateObject();

    // plugin_pricing_one_of_1->price
    if (!plugin_pricing_one_of_1->price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "price", *plugin_pricing_one_of_1->price) == NULL) {
    goto fail; //Numeric
    }


    // plugin_pricing_one_of_1->type
    if (simplebilly_api_plugin_pricing_one_of_1_TYPE_NULL == plugin_pricing_one_of_1->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", plugin_pricing_one_of_1_type_ToString(plugin_pricing_one_of_1->type)) == NULL)
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

plugin_pricing_one_of_1_t *plugin_pricing_one_of_1_parseFromJSON(cJSON *plugin_pricing_one_of_1JSON){

    plugin_pricing_one_of_1_t *plugin_pricing_one_of_1_local_var = NULL;

    // define the local variable for plugin_pricing_one_of_1->price
    double *price_local_var = NULL;

    // plugin_pricing_one_of_1->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(plugin_pricing_one_of_1JSON, "price");
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

    // plugin_pricing_one_of_1->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(plugin_pricing_one_of_1JSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    simplebilly_api_plugin_pricing_one_of_1_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = plugin_pricing_one_of_1_type_FromString(type->valuestring);



    plugin_pricing_one_of_1_local_var = plugin_pricing_one_of_1_create_internal (
        price_local_var,
        typeVariable
        );

    if (!plugin_pricing_one_of_1_local_var) {
        goto end;
    }

    return plugin_pricing_one_of_1_local_var;
end:
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    return NULL;

}
