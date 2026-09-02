#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plugin_error_one_of_5.h"



static plugin_error_one_of_5_t *plugin_error_one_of_5_create_internal(
    list_t *validation_error
    ) {
    plugin_error_one_of_5_t *plugin_error_one_of_5_local_var = malloc(sizeof(plugin_error_one_of_5_t));
    if (!plugin_error_one_of_5_local_var) {
        return NULL;
    }
    memset(plugin_error_one_of_5_local_var, 0, sizeof(plugin_error_one_of_5_t));
    plugin_error_one_of_5_local_var->_library_owned = 1;
    plugin_error_one_of_5_local_var->validation_error = validation_error;
    return plugin_error_one_of_5_local_var;
}

__attribute__((deprecated)) plugin_error_one_of_5_t *plugin_error_one_of_5_create(
    list_t *validation_error
    ) {
    plugin_error_one_of_5_t *result = plugin_error_one_of_5_create_internal (
        validation_error
        );
    if (!result) {
    }
    return result;
}

void plugin_error_one_of_5_free(plugin_error_one_of_5_t *plugin_error_one_of_5) {
    if(NULL == plugin_error_one_of_5){
        return ;
    }
    if(plugin_error_one_of_5->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plugin_error_one_of_5_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plugin_error_one_of_5->validation_error) {
        list_ForEach(listEntry, plugin_error_one_of_5->validation_error) {
            object_free(listEntry->data);
        }
        list_freeList(plugin_error_one_of_5->validation_error);
        plugin_error_one_of_5->validation_error = NULL;
    }
    free(plugin_error_one_of_5);
}

cJSON *plugin_error_one_of_5_convertToJSON(plugin_error_one_of_5_t *plugin_error_one_of_5) {
    cJSON *item = cJSON_CreateObject();

    // plugin_error_one_of_5->validation_error
    if (!plugin_error_one_of_5->validation_error) {
        goto fail;
    }
    cJSON *validation_error = cJSON_AddArrayToObject(item, "ValidationError");
    if(validation_error == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *validation_errorListEntry;
    if (plugin_error_one_of_5->validation_error) {
    list_ForEach(validation_errorListEntry, plugin_error_one_of_5->validation_error) {
    cJSON *itemLocal = object_convertToJSON(validation_errorListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(validation_error, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plugin_error_one_of_5_t *plugin_error_one_of_5_parseFromJSON(cJSON *plugin_error_one_of_5JSON){

    plugin_error_one_of_5_t *plugin_error_one_of_5_local_var = NULL;

    // define the local list for plugin_error_one_of_5->validation_error
    list_t *validation_errorList = NULL;

    // plugin_error_one_of_5->validation_error
    cJSON *validation_error = cJSON_GetObjectItemCaseSensitive(plugin_error_one_of_5JSON, "ValidationError");
    if (cJSON_IsNull(validation_error)) {
        validation_error = NULL;
    }
    if (!validation_error) {
        goto end;
    }

    
    cJSON *validation_error_local_nonprimitive = NULL;
    if(!cJSON_IsArray(validation_error)){
        goto end; //nonprimitive container
    }

    validation_errorList = list_createList();

    cJSON_ArrayForEach(validation_error_local_nonprimitive,validation_error )
    {
        if(!cJSON_IsObject(validation_error_local_nonprimitive)){
            goto end;
        }
        object_t *validation_errorItem = object_parseFromJSON(validation_error_local_nonprimitive);

        list_addElement(validation_errorList, validation_errorItem);
    }



    plugin_error_one_of_5_local_var = plugin_error_one_of_5_create_internal (
        validation_errorList
        );

    if (!plugin_error_one_of_5_local_var) {
        goto end;
    }

    return plugin_error_one_of_5_local_var;
end:
    if (validation_errorList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, validation_errorList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(validation_errorList);
        validation_errorList = NULL;
    }
    return NULL;

}
