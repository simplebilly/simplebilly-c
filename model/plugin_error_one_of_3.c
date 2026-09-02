#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plugin_error_one_of_3.h"



static plugin_error_one_of_3_t *plugin_error_one_of_3_create_internal(
    list_t *internal_error
    ) {
    plugin_error_one_of_3_t *plugin_error_one_of_3_local_var = malloc(sizeof(plugin_error_one_of_3_t));
    if (!plugin_error_one_of_3_local_var) {
        return NULL;
    }
    memset(plugin_error_one_of_3_local_var, 0, sizeof(plugin_error_one_of_3_t));
    plugin_error_one_of_3_local_var->_library_owned = 1;
    plugin_error_one_of_3_local_var->internal_error = internal_error;
    return plugin_error_one_of_3_local_var;
}

__attribute__((deprecated)) plugin_error_one_of_3_t *plugin_error_one_of_3_create(
    list_t *internal_error
    ) {
    plugin_error_one_of_3_t *result = plugin_error_one_of_3_create_internal (
        internal_error
        );
    if (!result) {
    }
    return result;
}

void plugin_error_one_of_3_free(plugin_error_one_of_3_t *plugin_error_one_of_3) {
    if(NULL == plugin_error_one_of_3){
        return ;
    }
    if(plugin_error_one_of_3->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plugin_error_one_of_3_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plugin_error_one_of_3->internal_error) {
        list_ForEach(listEntry, plugin_error_one_of_3->internal_error) {
            object_free(listEntry->data);
        }
        list_freeList(plugin_error_one_of_3->internal_error);
        plugin_error_one_of_3->internal_error = NULL;
    }
    free(plugin_error_one_of_3);
}

cJSON *plugin_error_one_of_3_convertToJSON(plugin_error_one_of_3_t *plugin_error_one_of_3) {
    cJSON *item = cJSON_CreateObject();

    // plugin_error_one_of_3->internal_error
    if (!plugin_error_one_of_3->internal_error) {
        goto fail;
    }
    cJSON *internal_error = cJSON_AddArrayToObject(item, "InternalError");
    if(internal_error == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *internal_errorListEntry;
    if (plugin_error_one_of_3->internal_error) {
    list_ForEach(internal_errorListEntry, plugin_error_one_of_3->internal_error) {
    cJSON *itemLocal = object_convertToJSON(internal_errorListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(internal_error, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plugin_error_one_of_3_t *plugin_error_one_of_3_parseFromJSON(cJSON *plugin_error_one_of_3JSON){

    plugin_error_one_of_3_t *plugin_error_one_of_3_local_var = NULL;

    // define the local list for plugin_error_one_of_3->internal_error
    list_t *internal_errorList = NULL;

    // plugin_error_one_of_3->internal_error
    cJSON *internal_error = cJSON_GetObjectItemCaseSensitive(plugin_error_one_of_3JSON, "InternalError");
    if (cJSON_IsNull(internal_error)) {
        internal_error = NULL;
    }
    if (!internal_error) {
        goto end;
    }

    
    cJSON *internal_error_local_nonprimitive = NULL;
    if(!cJSON_IsArray(internal_error)){
        goto end; //nonprimitive container
    }

    internal_errorList = list_createList();

    cJSON_ArrayForEach(internal_error_local_nonprimitive,internal_error )
    {
        if(!cJSON_IsObject(internal_error_local_nonprimitive)){
            goto end;
        }
        object_t *internal_errorItem = object_parseFromJSON(internal_error_local_nonprimitive);

        list_addElement(internal_errorList, internal_errorItem);
    }



    plugin_error_one_of_3_local_var = plugin_error_one_of_3_create_internal (
        internal_errorList
        );

    if (!plugin_error_one_of_3_local_var) {
        goto end;
    }

    return plugin_error_one_of_3_local_var;
end:
    if (internal_errorList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, internal_errorList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(internal_errorList);
        internal_errorList = NULL;
    }
    return NULL;

}
