#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plugin_error_one_of.h"



static plugin_error_one_of_t *plugin_error_one_of_create_internal(
    list_t *bad_request
    ) {
    plugin_error_one_of_t *plugin_error_one_of_local_var = malloc(sizeof(plugin_error_one_of_t));
    if (!plugin_error_one_of_local_var) {
        return NULL;
    }
    memset(plugin_error_one_of_local_var, 0, sizeof(plugin_error_one_of_t));
    plugin_error_one_of_local_var->_library_owned = 1;
    plugin_error_one_of_local_var->bad_request = bad_request;
    return plugin_error_one_of_local_var;
}

__attribute__((deprecated)) plugin_error_one_of_t *plugin_error_one_of_create(
    list_t *bad_request
    ) {
    plugin_error_one_of_t *result = plugin_error_one_of_create_internal (
        bad_request
        );
    if (!result) {
    }
    return result;
}

void plugin_error_one_of_free(plugin_error_one_of_t *plugin_error_one_of) {
    if(NULL == plugin_error_one_of){
        return ;
    }
    if(plugin_error_one_of->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plugin_error_one_of_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plugin_error_one_of->bad_request) {
        list_ForEach(listEntry, plugin_error_one_of->bad_request) {
            object_free(listEntry->data);
        }
        list_freeList(plugin_error_one_of->bad_request);
        plugin_error_one_of->bad_request = NULL;
    }
    free(plugin_error_one_of);
}

cJSON *plugin_error_one_of_convertToJSON(plugin_error_one_of_t *plugin_error_one_of) {
    cJSON *item = cJSON_CreateObject();

    // plugin_error_one_of->bad_request
    if (!plugin_error_one_of->bad_request) {
        goto fail;
    }
    cJSON *bad_request = cJSON_AddArrayToObject(item, "BadRequest");
    if(bad_request == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *bad_requestListEntry;
    if (plugin_error_one_of->bad_request) {
    list_ForEach(bad_requestListEntry, plugin_error_one_of->bad_request) {
    cJSON *itemLocal = object_convertToJSON(bad_requestListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(bad_request, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plugin_error_one_of_t *plugin_error_one_of_parseFromJSON(cJSON *plugin_error_one_ofJSON){

    plugin_error_one_of_t *plugin_error_one_of_local_var = NULL;

    // define the local list for plugin_error_one_of->bad_request
    list_t *bad_requestList = NULL;

    // plugin_error_one_of->bad_request
    cJSON *bad_request = cJSON_GetObjectItemCaseSensitive(plugin_error_one_ofJSON, "BadRequest");
    if (cJSON_IsNull(bad_request)) {
        bad_request = NULL;
    }
    if (!bad_request) {
        goto end;
    }

    
    cJSON *bad_request_local_nonprimitive = NULL;
    if(!cJSON_IsArray(bad_request)){
        goto end; //nonprimitive container
    }

    bad_requestList = list_createList();

    cJSON_ArrayForEach(bad_request_local_nonprimitive,bad_request )
    {
        if(!cJSON_IsObject(bad_request_local_nonprimitive)){
            goto end;
        }
        object_t *bad_requestItem = object_parseFromJSON(bad_request_local_nonprimitive);

        list_addElement(bad_requestList, bad_requestItem);
    }



    plugin_error_one_of_local_var = plugin_error_one_of_create_internal (
        bad_requestList
        );

    if (!plugin_error_one_of_local_var) {
        goto end;
    }

    return plugin_error_one_of_local_var;
end:
    if (bad_requestList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, bad_requestList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(bad_requestList);
        bad_requestList = NULL;
    }
    return NULL;

}
