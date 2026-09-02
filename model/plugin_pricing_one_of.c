#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plugin_pricing_one_of.h"


char* plugin_pricing_one_of_type_ToString(simplebilly_api_plugin_pricing_one_of_TYPE_e type) {
    char* typeArray[] =  { "NULL", "free" };
    return typeArray[type];
}

simplebilly_api_plugin_pricing_one_of_TYPE_e plugin_pricing_one_of_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "free" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static plugin_pricing_one_of_t *plugin_pricing_one_of_create_internal(
    simplebilly_api_plugin_pricing_one_of_TYPE_e type
    ) {
    plugin_pricing_one_of_t *plugin_pricing_one_of_local_var = malloc(sizeof(plugin_pricing_one_of_t));
    if (!plugin_pricing_one_of_local_var) {
        return NULL;
    }
    memset(plugin_pricing_one_of_local_var, 0, sizeof(plugin_pricing_one_of_t));
    plugin_pricing_one_of_local_var->_library_owned = 1;
    plugin_pricing_one_of_local_var->type = type;
    return plugin_pricing_one_of_local_var;
}

__attribute__((deprecated)) plugin_pricing_one_of_t *plugin_pricing_one_of_create(
    simplebilly_api_plugin_pricing_one_of_TYPE_e type
    ) {
    plugin_pricing_one_of_t *result = plugin_pricing_one_of_create_internal (
        type
        );
    if (!result) {
    }
    return result;
}

void plugin_pricing_one_of_free(plugin_pricing_one_of_t *plugin_pricing_one_of) {
    if(NULL == plugin_pricing_one_of){
        return ;
    }
    if(plugin_pricing_one_of->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plugin_pricing_one_of_free");
        return ;
    }
    listEntry_t *listEntry;
    free(plugin_pricing_one_of);
}

cJSON *plugin_pricing_one_of_convertToJSON(plugin_pricing_one_of_t *plugin_pricing_one_of) {
    cJSON *item = cJSON_CreateObject();

    // plugin_pricing_one_of->type
    if (simplebilly_api_plugin_pricing_one_of_TYPE_NULL == plugin_pricing_one_of->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", plugin_pricing_one_of_type_ToString(plugin_pricing_one_of->type)) == NULL)
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

plugin_pricing_one_of_t *plugin_pricing_one_of_parseFromJSON(cJSON *plugin_pricing_one_ofJSON){

    plugin_pricing_one_of_t *plugin_pricing_one_of_local_var = NULL;

    // plugin_pricing_one_of->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(plugin_pricing_one_ofJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    simplebilly_api_plugin_pricing_one_of_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = plugin_pricing_one_of_type_FromString(type->valuestring);



    plugin_pricing_one_of_local_var = plugin_pricing_one_of_create_internal (
        typeVariable
        );

    if (!plugin_pricing_one_of_local_var) {
        goto end;
    }

    return plugin_pricing_one_of_local_var;
end:
    return NULL;

}
