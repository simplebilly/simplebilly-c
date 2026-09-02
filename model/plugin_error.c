#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plugin_error.h"



static plugin_error_t *plugin_error_create_internal(
    list_t *bad_request,
    list_t *not_found,
    list_t *unauthorized,
    list_t *internal_error,
    list_t *database_error,
    list_t *validation_error,
    char *not_implemented
    ) {
    plugin_error_t *plugin_error_local_var = malloc(sizeof(plugin_error_t));
    if (!plugin_error_local_var) {
        return NULL;
    }
    memset(plugin_error_local_var, 0, sizeof(plugin_error_t));
    plugin_error_local_var->_library_owned = 1;
    plugin_error_local_var->bad_request = bad_request;
    plugin_error_local_var->not_found = not_found;
    plugin_error_local_var->unauthorized = unauthorized;
    plugin_error_local_var->internal_error = internal_error;
    plugin_error_local_var->database_error = database_error;
    plugin_error_local_var->validation_error = validation_error;
    plugin_error_local_var->not_implemented = not_implemented;
    return plugin_error_local_var;
}

__attribute__((deprecated)) plugin_error_t *plugin_error_create(
    list_t *bad_request,
    list_t *not_found,
    list_t *unauthorized,
    list_t *internal_error,
    list_t *database_error,
    list_t *validation_error,
    char *not_implemented
    ) {
    plugin_error_t *result = plugin_error_create_internal (
        bad_request,
        not_found,
        unauthorized,
        internal_error,
        database_error,
        validation_error,
        not_implemented
        );
    if (!result) {
    }
    return result;
}

void plugin_error_free(plugin_error_t *plugin_error) {
    if(NULL == plugin_error){
        return ;
    }
    if(plugin_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plugin_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plugin_error->bad_request) {
        list_ForEach(listEntry, plugin_error->bad_request) {
            object_free(listEntry->data);
        }
        list_freeList(plugin_error->bad_request);
        plugin_error->bad_request = NULL;
    }
    if (plugin_error->not_found) {
        list_ForEach(listEntry, plugin_error->not_found) {
            object_free(listEntry->data);
        }
        list_freeList(plugin_error->not_found);
        plugin_error->not_found = NULL;
    }
    if (plugin_error->unauthorized) {
        list_ForEach(listEntry, plugin_error->unauthorized) {
            object_free(listEntry->data);
        }
        list_freeList(plugin_error->unauthorized);
        plugin_error->unauthorized = NULL;
    }
    if (plugin_error->internal_error) {
        list_ForEach(listEntry, plugin_error->internal_error) {
            object_free(listEntry->data);
        }
        list_freeList(plugin_error->internal_error);
        plugin_error->internal_error = NULL;
    }
    if (plugin_error->database_error) {
        list_ForEach(listEntry, plugin_error->database_error) {
            object_free(listEntry->data);
        }
        list_freeList(plugin_error->database_error);
        plugin_error->database_error = NULL;
    }
    if (plugin_error->validation_error) {
        list_ForEach(listEntry, plugin_error->validation_error) {
            object_free(listEntry->data);
        }
        list_freeList(plugin_error->validation_error);
        plugin_error->validation_error = NULL;
    }
    if (plugin_error->not_implemented) {
        free(plugin_error->not_implemented);
        plugin_error->not_implemented = NULL;
    }
    free(plugin_error);
}

cJSON *plugin_error_convertToJSON(plugin_error_t *plugin_error) {
    cJSON *item = cJSON_CreateObject();

    // plugin_error->bad_request
    if (!plugin_error->bad_request) {
        goto fail;
    }
    cJSON *bad_request = cJSON_AddArrayToObject(item, "BadRequest");
    if(bad_request == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *bad_requestListEntry;
    if (plugin_error->bad_request) {
    list_ForEach(bad_requestListEntry, plugin_error->bad_request) {
    cJSON *itemLocal = object_convertToJSON(bad_requestListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(bad_request, itemLocal);
    }
    }


    // plugin_error->not_found
    if (!plugin_error->not_found) {
        goto fail;
    }
    cJSON *not_found = cJSON_AddArrayToObject(item, "NotFound");
    if(not_found == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *not_foundListEntry;
    if (plugin_error->not_found) {
    list_ForEach(not_foundListEntry, plugin_error->not_found) {
    cJSON *itemLocal = object_convertToJSON(not_foundListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(not_found, itemLocal);
    }
    }


    // plugin_error->unauthorized
    if (!plugin_error->unauthorized) {
        goto fail;
    }
    cJSON *unauthorized = cJSON_AddArrayToObject(item, "Unauthorized");
    if(unauthorized == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *unauthorizedListEntry;
    if (plugin_error->unauthorized) {
    list_ForEach(unauthorizedListEntry, plugin_error->unauthorized) {
    cJSON *itemLocal = object_convertToJSON(unauthorizedListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(unauthorized, itemLocal);
    }
    }


    // plugin_error->internal_error
    if (!plugin_error->internal_error) {
        goto fail;
    }
    cJSON *internal_error = cJSON_AddArrayToObject(item, "InternalError");
    if(internal_error == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *internal_errorListEntry;
    if (plugin_error->internal_error) {
    list_ForEach(internal_errorListEntry, plugin_error->internal_error) {
    cJSON *itemLocal = object_convertToJSON(internal_errorListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(internal_error, itemLocal);
    }
    }


    // plugin_error->database_error
    if (!plugin_error->database_error) {
        goto fail;
    }
    cJSON *database_error = cJSON_AddArrayToObject(item, "DatabaseError");
    if(database_error == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *database_errorListEntry;
    if (plugin_error->database_error) {
    list_ForEach(database_errorListEntry, plugin_error->database_error) {
    cJSON *itemLocal = object_convertToJSON(database_errorListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(database_error, itemLocal);
    }
    }


    // plugin_error->validation_error
    if (!plugin_error->validation_error) {
        goto fail;
    }
    cJSON *validation_error = cJSON_AddArrayToObject(item, "ValidationError");
    if(validation_error == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *validation_errorListEntry;
    if (plugin_error->validation_error) {
    list_ForEach(validation_errorListEntry, plugin_error->validation_error) {
    cJSON *itemLocal = object_convertToJSON(validation_errorListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(validation_error, itemLocal);
    }
    }


    // plugin_error->not_implemented
    if (!plugin_error->not_implemented) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "NotImplemented", plugin_error->not_implemented) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plugin_error_t *plugin_error_parseFromJSON(cJSON *plugin_errorJSON){

    plugin_error_t *plugin_error_local_var = NULL;

    // define the local list for plugin_error->bad_request
    list_t *bad_requestList = NULL;

    // define the local list for plugin_error->not_found
    list_t *not_foundList = NULL;

    // define the local list for plugin_error->unauthorized
    list_t *unauthorizedList = NULL;

    // define the local list for plugin_error->internal_error
    list_t *internal_errorList = NULL;

    // define the local list for plugin_error->database_error
    list_t *database_errorList = NULL;

    // define the local list for plugin_error->validation_error
    list_t *validation_errorList = NULL;

    char *not_implemented_local_str = NULL;

    // plugin_error->bad_request
    cJSON *bad_request = cJSON_GetObjectItemCaseSensitive(plugin_errorJSON, "BadRequest");
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

    // plugin_error->not_found
    cJSON *not_found = cJSON_GetObjectItemCaseSensitive(plugin_errorJSON, "NotFound");
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

    // plugin_error->unauthorized
    cJSON *unauthorized = cJSON_GetObjectItemCaseSensitive(plugin_errorJSON, "Unauthorized");
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

    // plugin_error->internal_error
    cJSON *internal_error = cJSON_GetObjectItemCaseSensitive(plugin_errorJSON, "InternalError");
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

    // plugin_error->database_error
    cJSON *database_error = cJSON_GetObjectItemCaseSensitive(plugin_errorJSON, "DatabaseError");
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

    // plugin_error->validation_error
    cJSON *validation_error = cJSON_GetObjectItemCaseSensitive(plugin_errorJSON, "ValidationError");
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

    // plugin_error->not_implemented
    cJSON *not_implemented = cJSON_GetObjectItemCaseSensitive(plugin_errorJSON, "NotImplemented");
    if (cJSON_IsNull(not_implemented)) {
        not_implemented = NULL;
    }
    if (!not_implemented) {
        goto end;
    }

    
    if(!cJSON_IsString(not_implemented))
    {
    goto end; //String
    }


    if (not_implemented && !cJSON_IsNull(not_implemented)) not_implemented_local_str = strdup(not_implemented->valuestring);

    plugin_error_local_var = plugin_error_create_internal (
        bad_requestList,
        not_foundList,
        unauthorizedList,
        internal_errorList,
        database_errorList,
        validation_errorList,
        not_implemented_local_str
        );

    if (!plugin_error_local_var) {
        goto end;
    }

    return plugin_error_local_var;
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
    if (not_foundList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, not_foundList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(not_foundList);
        not_foundList = NULL;
    }
    if (unauthorizedList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, unauthorizedList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(unauthorizedList);
        unauthorizedList = NULL;
    }
    if (internal_errorList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, internal_errorList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(internal_errorList);
        internal_errorList = NULL;
    }
    if (database_errorList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, database_errorList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(database_errorList);
        database_errorList = NULL;
    }
    if (validation_errorList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, validation_errorList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(validation_errorList);
        validation_errorList = NULL;
    }
    if (not_implemented_local_str) {
        free(not_implemented_local_str);
        not_implemented_local_str = NULL;
    }
    return NULL;

}
