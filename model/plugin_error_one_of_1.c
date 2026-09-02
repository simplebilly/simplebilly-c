#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plugin_error_one_of_1.h"



static plugin_error_one_of_1_t *plugin_error_one_of_1_create_internal(
    list_t *not_found
    ) {
    plugin_error_one_of_1_t *plugin_error_one_of_1_local_var = malloc(sizeof(plugin_error_one_of_1_t));
    if (!plugin_error_one_of_1_local_var) {
        return NULL;
    }
    memset(plugin_error_one_of_1_local_var, 0, sizeof(plugin_error_one_of_1_t));
    plugin_error_one_of_1_local_var->_library_owned = 1;
    plugin_error_one_of_1_local_var->not_found = not_found;
    return plugin_error_one_of_1_local_var;
}

__attribute__((deprecated)) plugin_error_one_of_1_t *plugin_error_one_of_1_create(
    list_t *not_found
    ) {
    plugin_error_one_of_1_t *result = plugin_error_one_of_1_create_internal (
        not_found
        );
    if (!result) {
    }
    return result;
}

void plugin_error_one_of_1_free(plugin_error_one_of_1_t *plugin_error_one_of_1) {
    if(NULL == plugin_error_one_of_1){
        return ;
    }
    if(plugin_error_one_of_1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plugin_error_one_of_1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plugin_error_one_of_1->not_found) {
        list_ForEach(listEntry, plugin_error_one_of_1->not_found) {
            object_free(listEntry->data);
        }
        list_freeList(plugin_error_one_of_1->not_found);
        plugin_error_one_of_1->not_found = NULL;
    }
    free(plugin_error_one_of_1);
}

cJSON *plugin_error_one_of_1_convertToJSON(plugin_error_one_of_1_t *plugin_error_one_of_1) {
    cJSON *item = cJSON_CreateObject();

    // plugin_error_one_of_1->not_found
    if (!plugin_error_one_of_1->not_found) {
        goto fail;
    }
    cJSON *not_found = cJSON_AddArrayToObject(item, "NotFound");
    if(not_found == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *not_foundListEntry;
    if (plugin_error_one_of_1->not_found) {
    list_ForEach(not_foundListEntry, plugin_error_one_of_1->not_found) {
    cJSON *itemLocal = object_convertToJSON(not_foundListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(not_found, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plugin_error_one_of_1_t *plugin_error_one_of_1_parseFromJSON(cJSON *plugin_error_one_of_1JSON){

    plugin_error_one_of_1_t *plugin_error_one_of_1_local_var = NULL;

    // define the local list for plugin_error_one_of_1->not_found
    list_t *not_foundList = NULL;

    // plugin_error_one_of_1->not_found
    cJSON *not_found = cJSON_GetObjectItemCaseSensitive(plugin_error_one_of_1JSON, "NotFound");
    if (cJSON_IsNull(not_found)) {
        not_found = NULL;
    }
    if (!not_found) {
        goto end;
    }

    
    cJSON *not_found_local_nonprimitive = NULL;
    if(!cJSON_IsArray(not_found)){
        goto end; //nonprimitive container
    }

    not_foundList = list_createList();

    cJSON_ArrayForEach(not_found_local_nonprimitive,not_found )
    {
        if(!cJSON_IsObject(not_found_local_nonprimitive)){
            goto end;
        }
        object_t *not_foundItem = object_parseFromJSON(not_found_local_nonprimitive);

        list_addElement(not_foundList, not_foundItem);
    }



    plugin_error_one_of_1_local_var = plugin_error_one_of_1_create_internal (
        not_foundList
        );

    if (!plugin_error_one_of_1_local_var) {
        goto end;
    }

    return plugin_error_one_of_1_local_var;
end:
    if (not_foundList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, not_foundList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(not_foundList);
        not_foundList = NULL;
    }
    return NULL;

}
