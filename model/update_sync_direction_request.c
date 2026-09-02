#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_sync_direction_request.h"



static update_sync_direction_request_t *update_sync_direction_request_create_internal(
    list_t* directions
    ) {
    update_sync_direction_request_t *update_sync_direction_request_local_var = malloc(sizeof(update_sync_direction_request_t));
    if (!update_sync_direction_request_local_var) {
        return NULL;
    }
    memset(update_sync_direction_request_local_var, 0, sizeof(update_sync_direction_request_t));
    update_sync_direction_request_local_var->_library_owned = 1;
    update_sync_direction_request_local_var->directions = directions;
    return update_sync_direction_request_local_var;
}

__attribute__((deprecated)) update_sync_direction_request_t *update_sync_direction_request_create(
    list_t* directions
    ) {
    update_sync_direction_request_t *result = update_sync_direction_request_create_internal (
        directions
        );
    if (!result) {
    }
    return result;
}

void update_sync_direction_request_free(update_sync_direction_request_t *update_sync_direction_request) {
    if(NULL == update_sync_direction_request){
        return ;
    }
    if(update_sync_direction_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_sync_direction_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_sync_direction_request->directions) {
        list_ForEach(listEntry, update_sync_direction_request->directions) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(update_sync_direction_request->directions);
        update_sync_direction_request->directions = NULL;
    }
    free(update_sync_direction_request);
}

cJSON *update_sync_direction_request_convertToJSON(update_sync_direction_request_t *update_sync_direction_request) {
    cJSON *item = cJSON_CreateObject();

    // update_sync_direction_request->directions
    if (!update_sync_direction_request->directions) {
        goto fail;
    }
    cJSON *directions = cJSON_AddObjectToObject(item, "directions");
    if(directions == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = directions;
    listEntry_t *directionsListEntry;
    if (update_sync_direction_request->directions) {
    list_ForEach(directionsListEntry, update_sync_direction_request->directions) {
        keyValuePair_t *localKeyValue = directionsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

update_sync_direction_request_t *update_sync_direction_request_parseFromJSON(cJSON *update_sync_direction_requestJSON){

    update_sync_direction_request_t *update_sync_direction_request_local_var = NULL;

    // define the local map for update_sync_direction_request->directions
    list_t *directionsList = NULL;

    // update_sync_direction_request->directions
    cJSON *directions = cJSON_GetObjectItemCaseSensitive(update_sync_direction_requestJSON, "directions");
    if (cJSON_IsNull(directions)) {
        directions = NULL;
    }
    if (!directions) {
        goto end;
    }

    
    cJSON *directions_local_map = NULL;
    if(!cJSON_IsObject(directions) && !cJSON_IsNull(directions))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(directions))
    {
        directionsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(directions_local_map, directions)
        {
            cJSON *localMapObject = directions_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(directionsList , localMapKeyPair);
        }
    }



    update_sync_direction_request_local_var = update_sync_direction_request_create_internal (
        directionsList
        );

    if (!update_sync_direction_request_local_var) {
        goto end;
    }

    return update_sync_direction_request_local_var;
end:
    if (directionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, directionsList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(directionsList);
        directionsList = NULL;
    }
    return NULL;

}
