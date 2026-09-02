#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "config_field_kind_one_of.h"


char* config_field_kind_one_of_type_ToString(simplebilly_api_config_field_kind_one_of_TYPE_e type) {
    char* typeArray[] =  { "NULL", "text" };
    return typeArray[type];
}

simplebilly_api_config_field_kind_one_of_TYPE_e config_field_kind_one_of_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "text" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static config_field_kind_one_of_t *config_field_kind_one_of_create_internal(
    simplebilly_api_config_field_kind_one_of_TYPE_e type
    ) {
    config_field_kind_one_of_t *config_field_kind_one_of_local_var = malloc(sizeof(config_field_kind_one_of_t));
    if (!config_field_kind_one_of_local_var) {
        return NULL;
    }
    memset(config_field_kind_one_of_local_var, 0, sizeof(config_field_kind_one_of_t));
    config_field_kind_one_of_local_var->_library_owned = 1;
    config_field_kind_one_of_local_var->type = type;
    return config_field_kind_one_of_local_var;
}

__attribute__((deprecated)) config_field_kind_one_of_t *config_field_kind_one_of_create(
    simplebilly_api_config_field_kind_one_of_TYPE_e type
    ) {
    config_field_kind_one_of_t *result = config_field_kind_one_of_create_internal (
        type
        );
    if (!result) {
    }
    return result;
}

void config_field_kind_one_of_free(config_field_kind_one_of_t *config_field_kind_one_of) {
    if(NULL == config_field_kind_one_of){
        return ;
    }
    if(config_field_kind_one_of->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "config_field_kind_one_of_free");
        return ;
    }
    listEntry_t *listEntry;
    free(config_field_kind_one_of);
}

cJSON *config_field_kind_one_of_convertToJSON(config_field_kind_one_of_t *config_field_kind_one_of) {
    cJSON *item = cJSON_CreateObject();

    // config_field_kind_one_of->type
    if (simplebilly_api_config_field_kind_one_of_TYPE_NULL == config_field_kind_one_of->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", config_field_kind_one_of_type_ToString(config_field_kind_one_of->type)) == NULL)
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

config_field_kind_one_of_t *config_field_kind_one_of_parseFromJSON(cJSON *config_field_kind_one_ofJSON){

    config_field_kind_one_of_t *config_field_kind_one_of_local_var = NULL;

    // config_field_kind_one_of->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(config_field_kind_one_ofJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    simplebilly_api_config_field_kind_one_of_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = config_field_kind_one_of_type_FromString(type->valuestring);



    config_field_kind_one_of_local_var = config_field_kind_one_of_create_internal (
        typeVariable
        );

    if (!config_field_kind_one_of_local_var) {
        goto end;
    }

    return config_field_kind_one_of_local_var;
end:
    return NULL;

}
