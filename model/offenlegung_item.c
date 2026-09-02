#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "offenlegung_item.h"



static offenlegung_item_t *offenlegung_item_create_internal(
    int *exists,
    char *name,
    char *source
    ) {
    offenlegung_item_t *offenlegung_item_local_var = malloc(sizeof(offenlegung_item_t));
    if (!offenlegung_item_local_var) {
        return NULL;
    }
    memset(offenlegung_item_local_var, 0, sizeof(offenlegung_item_t));
    offenlegung_item_local_var->_library_owned = 1;
    offenlegung_item_local_var->exists = exists;
    offenlegung_item_local_var->name = name;
    offenlegung_item_local_var->source = source;
    return offenlegung_item_local_var;
}

__attribute__((deprecated)) offenlegung_item_t *offenlegung_item_create(
    int *exists,
    char *name,
    char *source
    ) {
    int *exists_copy = NULL;
    if (exists) {
        exists_copy = malloc(sizeof(int));
        if (exists_copy) *exists_copy = *exists;
    }
    offenlegung_item_t *result = offenlegung_item_create_internal (
        exists_copy,
        name,
        source
        );
    if (!result) {
        free(exists_copy);
    }
    return result;
}

void offenlegung_item_free(offenlegung_item_t *offenlegung_item) {
    if(NULL == offenlegung_item){
        return ;
    }
    if(offenlegung_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "offenlegung_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (offenlegung_item->exists) {
        free(offenlegung_item->exists);
        offenlegung_item->exists = NULL;
    }
    if (offenlegung_item->name) {
        free(offenlegung_item->name);
        offenlegung_item->name = NULL;
    }
    if (offenlegung_item->source) {
        free(offenlegung_item->source);
        offenlegung_item->source = NULL;
    }
    free(offenlegung_item);
}

cJSON *offenlegung_item_convertToJSON(offenlegung_item_t *offenlegung_item) {
    cJSON *item = cJSON_CreateObject();

    // offenlegung_item->exists
    if (!offenlegung_item->exists) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "exists", *offenlegung_item->exists) == NULL) {
    goto fail; //Bool
    }


    // offenlegung_item->name
    if (!offenlegung_item->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", offenlegung_item->name) == NULL) {
    goto fail; //String
    }


    // offenlegung_item->source
    if (!offenlegung_item->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", offenlegung_item->source) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

offenlegung_item_t *offenlegung_item_parseFromJSON(cJSON *offenlegung_itemJSON){

    offenlegung_item_t *offenlegung_item_local_var = NULL;

    // define the local variable for offenlegung_item->exists
    int *exists_local_var = NULL;

    char *name_local_str = NULL;

    char *source_local_str = NULL;

    // offenlegung_item->exists
    cJSON *exists = cJSON_GetObjectItemCaseSensitive(offenlegung_itemJSON, "exists");
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

    // offenlegung_item->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(offenlegung_itemJSON, "name");
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

    // offenlegung_item->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(offenlegung_itemJSON, "source");
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

    offenlegung_item_local_var = offenlegung_item_create_internal (
        exists_local_var,
        name_local_str,
        source_local_str
        );

    if (!offenlegung_item_local_var) {
        goto end;
    }

    return offenlegung_item_local_var;
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
