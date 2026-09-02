#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plugin_error_one_of_4.h"



static plugin_error_one_of_4_t *plugin_error_one_of_4_create_internal(
    list_t *database_error
    ) {
    plugin_error_one_of_4_t *plugin_error_one_of_4_local_var = malloc(sizeof(plugin_error_one_of_4_t));
    if (!plugin_error_one_of_4_local_var) {
        return NULL;
    }
    memset(plugin_error_one_of_4_local_var, 0, sizeof(plugin_error_one_of_4_t));
    plugin_error_one_of_4_local_var->_library_owned = 1;
    plugin_error_one_of_4_local_var->database_error = database_error;
    return plugin_error_one_of_4_local_var;
}

__attribute__((deprecated)) plugin_error_one_of_4_t *plugin_error_one_of_4_create(
    list_t *database_error
    ) {
    plugin_error_one_of_4_t *result = plugin_error_one_of_4_create_internal (
        database_error
        );
    if (!result) {
    }
    return result;
}

void plugin_error_one_of_4_free(plugin_error_one_of_4_t *plugin_error_one_of_4) {
    if(NULL == plugin_error_one_of_4){
        return ;
    }
    if(plugin_error_one_of_4->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plugin_error_one_of_4_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plugin_error_one_of_4->database_error) {
        list_ForEach(listEntry, plugin_error_one_of_4->database_error) {
            object_free(listEntry->data);
        }
        list_freeList(plugin_error_one_of_4->database_error);
        plugin_error_one_of_4->database_error = NULL;
    }
    free(plugin_error_one_of_4);
}

cJSON *plugin_error_one_of_4_convertToJSON(plugin_error_one_of_4_t *plugin_error_one_of_4) {
    cJSON *item = cJSON_CreateObject();

    // plugin_error_one_of_4->database_error
    if (!plugin_error_one_of_4->database_error) {
        goto fail;
    }
    cJSON *database_error = cJSON_AddArrayToObject(item, "DatabaseError");
    if(database_error == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *database_errorListEntry;
    if (plugin_error_one_of_4->database_error) {
    list_ForEach(database_errorListEntry, plugin_error_one_of_4->database_error) {
    cJSON *itemLocal = object_convertToJSON(database_errorListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(database_error, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plugin_error_one_of_4_t *plugin_error_one_of_4_parseFromJSON(cJSON *plugin_error_one_of_4JSON){

    plugin_error_one_of_4_t *plugin_error_one_of_4_local_var = NULL;

    // define the local list for plugin_error_one_of_4->database_error
    list_t *database_errorList = NULL;

    // plugin_error_one_of_4->database_error
    cJSON *database_error = cJSON_GetObjectItemCaseSensitive(plugin_error_one_of_4JSON, "DatabaseError");
    if (cJSON_IsNull(database_error)) {
        database_error = NULL;
    }
    if (!database_error) {
        goto end;
    }

    
    cJSON *database_error_local_nonprimitive = NULL;
    if(!cJSON_IsArray(database_error)){
        goto end; //nonprimitive container
    }

    database_errorList = list_createList();

    cJSON_ArrayForEach(database_error_local_nonprimitive,database_error )
    {
        if(!cJSON_IsObject(database_error_local_nonprimitive)){
            goto end;
        }
        object_t *database_errorItem = object_parseFromJSON(database_error_local_nonprimitive);

        list_addElement(database_errorList, database_errorItem);
    }



    plugin_error_one_of_4_local_var = plugin_error_one_of_4_create_internal (
        database_errorList
        );

    if (!plugin_error_one_of_4_local_var) {
        goto end;
    }

    return plugin_error_one_of_4_local_var;
end:
    if (database_errorList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, database_errorList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(database_errorList);
        database_errorList = NULL;
    }
    return NULL;

}
