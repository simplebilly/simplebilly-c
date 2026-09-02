#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "order_tags_request.h"



static order_tags_request_t *order_tags_request_create_internal(
    list_t *tags
    ) {
    order_tags_request_t *order_tags_request_local_var = malloc(sizeof(order_tags_request_t));
    if (!order_tags_request_local_var) {
        return NULL;
    }
    memset(order_tags_request_local_var, 0, sizeof(order_tags_request_t));
    order_tags_request_local_var->_library_owned = 1;
    order_tags_request_local_var->tags = tags;
    return order_tags_request_local_var;
}

__attribute__((deprecated)) order_tags_request_t *order_tags_request_create(
    list_t *tags
    ) {
    order_tags_request_t *result = order_tags_request_create_internal (
        tags
        );
    if (!result) {
    }
    return result;
}

void order_tags_request_free(order_tags_request_t *order_tags_request) {
    if(NULL == order_tags_request){
        return ;
    }
    if(order_tags_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "order_tags_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (order_tags_request->tags) {
        list_ForEach(listEntry, order_tags_request->tags) {
            free(listEntry->data);
        }
        list_freeList(order_tags_request->tags);
        order_tags_request->tags = NULL;
    }
    free(order_tags_request);
}

cJSON *order_tags_request_convertToJSON(order_tags_request_t *order_tags_request) {
    cJSON *item = cJSON_CreateObject();

    // order_tags_request->tags
    if (!order_tags_request->tags) {
        goto fail;
    }
    cJSON *tags = cJSON_AddArrayToObject(item, "tags");
    if(tags == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *tagsListEntry;
    list_ForEach(tagsListEntry, order_tags_request->tags) {
    if(cJSON_AddStringToObject(tags, "", tagsListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

order_tags_request_t *order_tags_request_parseFromJSON(cJSON *order_tags_requestJSON){

    order_tags_request_t *order_tags_request_local_var = NULL;

    // define the local list for order_tags_request->tags
    list_t *tagsList = NULL;

    // order_tags_request->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(order_tags_requestJSON, "tags");
    if (cJSON_IsNull(tags)) {
        tags = NULL;
    }
    if (!tags) {
        goto end;
    }

    
    cJSON *tags_local = NULL;
    if(!cJSON_IsArray(tags)) {
        goto end;//primitive container
    }
    tagsList = list_createList();

    cJSON_ArrayForEach(tags_local, tags)
    {
        if(!cJSON_IsString(tags_local))
        {
            goto end;
        }
        list_addElement(tagsList , strdup(tags_local->valuestring));
    }



    order_tags_request_local_var = order_tags_request_create_internal (
        tagsList
        );

    if (!order_tags_request_local_var) {
        goto end;
    }

    return order_tags_request_local_var;
end:
    if (tagsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tagsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tagsList);
        tagsList = NULL;
    }
    return NULL;

}
