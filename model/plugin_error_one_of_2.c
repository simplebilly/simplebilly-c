#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plugin_error_one_of_2.h"



static plugin_error_one_of_2_t *plugin_error_one_of_2_create_internal(
    list_t *unauthorized
    ) {
    plugin_error_one_of_2_t *plugin_error_one_of_2_local_var = malloc(sizeof(plugin_error_one_of_2_t));
    if (!plugin_error_one_of_2_local_var) {
        return NULL;
    }
    memset(plugin_error_one_of_2_local_var, 0, sizeof(plugin_error_one_of_2_t));
    plugin_error_one_of_2_local_var->_library_owned = 1;
    plugin_error_one_of_2_local_var->unauthorized = unauthorized;
    return plugin_error_one_of_2_local_var;
}

__attribute__((deprecated)) plugin_error_one_of_2_t *plugin_error_one_of_2_create(
    list_t *unauthorized
    ) {
    plugin_error_one_of_2_t *result = plugin_error_one_of_2_create_internal (
        unauthorized
        );
    if (!result) {
    }
    return result;
}

void plugin_error_one_of_2_free(plugin_error_one_of_2_t *plugin_error_one_of_2) {
    if(NULL == plugin_error_one_of_2){
        return ;
    }
    if(plugin_error_one_of_2->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plugin_error_one_of_2_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plugin_error_one_of_2->unauthorized) {
        list_ForEach(listEntry, plugin_error_one_of_2->unauthorized) {
            object_free(listEntry->data);
        }
        list_freeList(plugin_error_one_of_2->unauthorized);
        plugin_error_one_of_2->unauthorized = NULL;
    }
    free(plugin_error_one_of_2);
}

cJSON *plugin_error_one_of_2_convertToJSON(plugin_error_one_of_2_t *plugin_error_one_of_2) {
    cJSON *item = cJSON_CreateObject();

    // plugin_error_one_of_2->unauthorized
    if (!plugin_error_one_of_2->unauthorized) {
        goto fail;
    }
    cJSON *unauthorized = cJSON_AddArrayToObject(item, "Unauthorized");
    if(unauthorized == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *unauthorizedListEntry;
    if (plugin_error_one_of_2->unauthorized) {
    list_ForEach(unauthorizedListEntry, plugin_error_one_of_2->unauthorized) {
    cJSON *itemLocal = object_convertToJSON(unauthorizedListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(unauthorized, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plugin_error_one_of_2_t *plugin_error_one_of_2_parseFromJSON(cJSON *plugin_error_one_of_2JSON){

    plugin_error_one_of_2_t *plugin_error_one_of_2_local_var = NULL;

    // define the local list for plugin_error_one_of_2->unauthorized
    list_t *unauthorizedList = NULL;

    // plugin_error_one_of_2->unauthorized
    cJSON *unauthorized = cJSON_GetObjectItemCaseSensitive(plugin_error_one_of_2JSON, "Unauthorized");
    if (cJSON_IsNull(unauthorized)) {
        unauthorized = NULL;
    }
    if (!unauthorized) {
        goto end;
    }

    
    cJSON *unauthorized_local_nonprimitive = NULL;
    if(!cJSON_IsArray(unauthorized)){
        goto end; //nonprimitive container
    }

    unauthorizedList = list_createList();

    cJSON_ArrayForEach(unauthorized_local_nonprimitive,unauthorized )
    {
        if(!cJSON_IsObject(unauthorized_local_nonprimitive)){
            goto end;
        }
        object_t *unauthorizedItem = object_parseFromJSON(unauthorized_local_nonprimitive);

        list_addElement(unauthorizedList, unauthorizedItem);
    }



    plugin_error_one_of_2_local_var = plugin_error_one_of_2_create_internal (
        unauthorizedList
        );

    if (!plugin_error_one_of_2_local_var) {
        goto end;
    }

    return plugin_error_one_of_2_local_var;
end:
    if (unauthorizedList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, unauthorizedList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(unauthorizedList);
        unauthorizedList = NULL;
    }
    return NULL;

}
