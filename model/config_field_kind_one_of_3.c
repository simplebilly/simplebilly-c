#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "config_field_kind_one_of_3.h"


char* config_field_kind_one_of_3_type_ToString(simplebilly_api_config_field_kind_one_of_3_TYPE_e type) {
    char* typeArray[] =  { "NULL", "select" };
    return typeArray[type];
}

simplebilly_api_config_field_kind_one_of_3_TYPE_e config_field_kind_one_of_3_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "select" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static config_field_kind_one_of_3_t *config_field_kind_one_of_3_create_internal(
    list_t *options,
    simplebilly_api_config_field_kind_one_of_3_TYPE_e type
    ) {
    config_field_kind_one_of_3_t *config_field_kind_one_of_3_local_var = malloc(sizeof(config_field_kind_one_of_3_t));
    if (!config_field_kind_one_of_3_local_var) {
        return NULL;
    }
    memset(config_field_kind_one_of_3_local_var, 0, sizeof(config_field_kind_one_of_3_t));
    config_field_kind_one_of_3_local_var->_library_owned = 1;
    config_field_kind_one_of_3_local_var->options = options;
    config_field_kind_one_of_3_local_var->type = type;
    return config_field_kind_one_of_3_local_var;
}

__attribute__((deprecated)) config_field_kind_one_of_3_t *config_field_kind_one_of_3_create(
    list_t *options,
    simplebilly_api_config_field_kind_one_of_3_TYPE_e type
    ) {
    config_field_kind_one_of_3_t *result = config_field_kind_one_of_3_create_internal (
        options,
        type
        );
    if (!result) {
    }
    return result;
}

void config_field_kind_one_of_3_free(config_field_kind_one_of_3_t *config_field_kind_one_of_3) {
    if(NULL == config_field_kind_one_of_3){
        return ;
    }
    if(config_field_kind_one_of_3->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "config_field_kind_one_of_3_free");
        return ;
    }
    listEntry_t *listEntry;
    if (config_field_kind_one_of_3->options) {
        list_ForEach(listEntry, config_field_kind_one_of_3->options) {
            free(listEntry->data);
        }
        list_freeList(config_field_kind_one_of_3->options);
        config_field_kind_one_of_3->options = NULL;
    }
    free(config_field_kind_one_of_3);
}

cJSON *config_field_kind_one_of_3_convertToJSON(config_field_kind_one_of_3_t *config_field_kind_one_of_3) {
    cJSON *item = cJSON_CreateObject();

    // config_field_kind_one_of_3->options
    if (!config_field_kind_one_of_3->options) {
        goto fail;
    }
    cJSON *options = cJSON_AddArrayToObject(item, "options");
    if(options == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *optionsListEntry;
    list_ForEach(optionsListEntry, config_field_kind_one_of_3->options) {
    if(cJSON_AddStringToObject(options, "", optionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // config_field_kind_one_of_3->type
    if (simplebilly_api_config_field_kind_one_of_3_TYPE_NULL == config_field_kind_one_of_3->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", config_field_kind_one_of_3_type_ToString(config_field_kind_one_of_3->type)) == NULL)
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

config_field_kind_one_of_3_t *config_field_kind_one_of_3_parseFromJSON(cJSON *config_field_kind_one_of_3JSON){

    config_field_kind_one_of_3_t *config_field_kind_one_of_3_local_var = NULL;

    // define the local list for config_field_kind_one_of_3->options
    list_t *optionsList = NULL;

    // config_field_kind_one_of_3->options
    cJSON *options = cJSON_GetObjectItemCaseSensitive(config_field_kind_one_of_3JSON, "options");
    if (cJSON_IsNull(options)) {
        options = NULL;
    }
    if (!options) {
        goto end;
    }

    
    cJSON *options_local = NULL;
    if(!cJSON_IsArray(options)) {
        goto end;//primitive container
    }
    optionsList = list_createList();

    cJSON_ArrayForEach(options_local, options)
    {
        if(!cJSON_IsString(options_local))
        {
            goto end;
        }
        list_addElement(optionsList , strdup(options_local->valuestring));
    }

    // config_field_kind_one_of_3->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(config_field_kind_one_of_3JSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    simplebilly_api_config_field_kind_one_of_3_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = config_field_kind_one_of_3_type_FromString(type->valuestring);



    config_field_kind_one_of_3_local_var = config_field_kind_one_of_3_create_internal (
        optionsList,
        typeVariable
        );

    if (!config_field_kind_one_of_3_local_var) {
        goto end;
    }

    return config_field_kind_one_of_3_local_var;
end:
    if (optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, optionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(optionsList);
        optionsList = NULL;
    }
    return NULL;

}
