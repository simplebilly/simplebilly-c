#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "institute_check_item.h"



static institute_check_item_t *institute_check_item_create_internal(
    int *exists,
    char *name,
    char *source
    ) {
    institute_check_item_t *institute_check_item_local_var = malloc(sizeof(institute_check_item_t));
    if (!institute_check_item_local_var) {
        return NULL;
    }
    memset(institute_check_item_local_var, 0, sizeof(institute_check_item_t));
    institute_check_item_local_var->_library_owned = 1;
    institute_check_item_local_var->exists = exists;
    institute_check_item_local_var->name = name;
    institute_check_item_local_var->source = source;
    return institute_check_item_local_var;
}

__attribute__((deprecated)) institute_check_item_t *institute_check_item_create(
    int *exists,
    char *name,
    char *source
    ) {
    int *exists_copy = NULL;
    if (exists) {
        exists_copy = malloc(sizeof(int));
        if (exists_copy) *exists_copy = *exists;
    }
    institute_check_item_t *result = institute_check_item_create_internal (
        exists_copy,
        name,
        source
        );
    if (!result) {
        free(exists_copy);
    }
    return result;
}

void institute_check_item_free(institute_check_item_t *institute_check_item) {
    if(NULL == institute_check_item){
        return ;
    }
    if(institute_check_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "institute_check_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (institute_check_item->exists) {
        free(institute_check_item->exists);
        institute_check_item->exists = NULL;
    }
    if (institute_check_item->name) {
        free(institute_check_item->name);
        institute_check_item->name = NULL;
    }
    if (institute_check_item->source) {
        free(institute_check_item->source);
        institute_check_item->source = NULL;
    }
    free(institute_check_item);
}

cJSON *institute_check_item_convertToJSON(institute_check_item_t *institute_check_item) {
    cJSON *item = cJSON_CreateObject();

    // institute_check_item->exists
    if (!institute_check_item->exists) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "exists", *institute_check_item->exists) == NULL) {
    goto fail; //Bool
    }


    // institute_check_item->name
    if (!institute_check_item->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", institute_check_item->name) == NULL) {
    goto fail; //String
    }


    // institute_check_item->source
    if (!institute_check_item->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", institute_check_item->source) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

institute_check_item_t *institute_check_item_parseFromJSON(cJSON *institute_check_itemJSON){

    institute_check_item_t *institute_check_item_local_var = NULL;

    // define the local variable for institute_check_item->exists
    int *exists_local_var = NULL;

    char *name_local_str = NULL;

    char *source_local_str = NULL;

    // institute_check_item->exists
    cJSON *exists = cJSON_GetObjectItemCaseSensitive(institute_check_itemJSON, "exists");
    if (cJSON_IsNull(exists)) {
        exists = NULL;
    }
    if (!exists) {
        goto end;
    }

    
    if(!cJSON_IsBool(exists))
    {
    goto end; //Bool
    }
    exists_local_var = malloc(sizeof(int));
    if(!exists_local_var)
    {
        goto end;
    }
    *exists_local_var = exists->valueint;

    // institute_check_item->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(institute_check_itemJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // institute_check_item->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(institute_check_itemJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (!source) {
        goto end;
    }

    
    if(!cJSON_IsString(source))
    {
    goto end; //String
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (source && !cJSON_IsNull(source)) source_local_str = strdup(source->valuestring);

    institute_check_item_local_var = institute_check_item_create_internal (
        exists_local_var,
        name_local_str,
        source_local_str
        );

    if (!institute_check_item_local_var) {
        goto end;
    }

    return institute_check_item_local_var;
end:
    if (exists_local_var) {
        free(exists_local_var);
        exists_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (source_local_str) {
        free(source_local_str);
        source_local_str = NULL;
    }
    return NULL;

}
