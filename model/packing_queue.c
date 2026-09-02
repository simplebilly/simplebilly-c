#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "packing_queue.h"



static packing_queue_t *packing_queue_create_internal(
    list_t *items,
    int *page,
    int *page_size,
    long *total_count
    ) {
    packing_queue_t *packing_queue_local_var = malloc(sizeof(packing_queue_t));
    if (!packing_queue_local_var) {
        return NULL;
    }
    memset(packing_queue_local_var, 0, sizeof(packing_queue_t));
    packing_queue_local_var->_library_owned = 1;
    packing_queue_local_var->items = items;
    packing_queue_local_var->page = page;
    packing_queue_local_var->page_size = page_size;
    packing_queue_local_var->total_count = total_count;
    return packing_queue_local_var;
}

__attribute__((deprecated)) packing_queue_t *packing_queue_create(
    list_t *items,
    int *page,
    int *page_size,
    long *total_count
    ) {
    int *page_copy = NULL;
    if (page) {
        page_copy = malloc(sizeof(int));
        if (page_copy) *page_copy = *page;
    }
    int *page_size_copy = NULL;
    if (page_size) {
        page_size_copy = malloc(sizeof(int));
        if (page_size_copy) *page_size_copy = *page_size;
    }
    long *total_count_copy = NULL;
    if (total_count) {
        total_count_copy = malloc(sizeof(long));
        if (total_count_copy) *total_count_copy = *total_count;
    }
    packing_queue_t *result = packing_queue_create_internal (
        items,
        page_copy,
        page_size_copy,
        total_count_copy
        );
    if (!result) {
        free(page_copy);
        free(page_size_copy);
        free(total_count_copy);
    }
    return result;
}

void packing_queue_free(packing_queue_t *packing_queue) {
    if(NULL == packing_queue){
        return ;
    }
    if(packing_queue->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "packing_queue_free");
        return ;
    }
    listEntry_t *listEntry;
    if (packing_queue->items) {
        list_ForEach(listEntry, packing_queue->items) {
            packing_queue_item_free(listEntry->data);
        }
        list_freeList(packing_queue->items);
        packing_queue->items = NULL;
    }
    if (packing_queue->page) {
        free(packing_queue->page);
        packing_queue->page = NULL;
    }
    if (packing_queue->page_size) {
        free(packing_queue->page_size);
        packing_queue->page_size = NULL;
    }
    if (packing_queue->total_count) {
        free(packing_queue->total_count);
        packing_queue->total_count = NULL;
    }
    free(packing_queue);
}

cJSON *packing_queue_convertToJSON(packing_queue_t *packing_queue) {
    cJSON *item = cJSON_CreateObject();

    // packing_queue->items
    if (!packing_queue->items) {
        goto fail;
    }
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (packing_queue->items) {
    list_ForEach(itemsListEntry, packing_queue->items) {
    cJSON *itemLocal = packing_queue_item_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // packing_queue->page
    if (!packing_queue->page) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "page", *packing_queue->page) == NULL) {
    goto fail; //Numeric
    }


    // packing_queue->page_size
    if (!packing_queue->page_size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "page_size", *packing_queue->page_size) == NULL) {
    goto fail; //Numeric
    }


    // packing_queue->total_count
    if (!packing_queue->total_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_count", *packing_queue->total_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

packing_queue_t *packing_queue_parseFromJSON(cJSON *packing_queueJSON){

    packing_queue_t *packing_queue_local_var = NULL;

    // define the local list for packing_queue->items
    list_t *itemsList = NULL;

    // define the local variable for packing_queue->page
    int *page_local_var = NULL;

    // define the local variable for packing_queue->page_size
    int *page_size_local_var = NULL;

    // define the local variable for packing_queue->total_count
    long *total_count_local_var = NULL;

    // packing_queue->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(packing_queueJSON, "items");
    if (cJSON_IsNull(items)) {
        items = NULL;
    }
    if (!items) {
        goto end;
    }

    
    cJSON *items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(items)){
        goto end; //nonprimitive container
    }

    itemsList = list_createList();

    cJSON_ArrayForEach(items_local_nonprimitive,items )
    {
        if(!cJSON_IsObject(items_local_nonprimitive)){
            goto end;
        }
        packing_queue_item_t *itemsItem = packing_queue_item_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // packing_queue->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(packing_queueJSON, "page");
    if (cJSON_IsNull(page)) {
        page = NULL;
    }
    if (!page) {
        goto end;
    }

    
    if(!cJSON_IsNumber(page))
    {
    goto end; //Numeric
    }
    page_local_var = malloc(sizeof(int));
    if(!page_local_var)
    {
        goto end;
    }
    *page_local_var = page->valuedouble;

    // packing_queue->page_size
    cJSON *page_size = cJSON_GetObjectItemCaseSensitive(packing_queueJSON, "page_size");
    if (cJSON_IsNull(page_size)) {
        page_size = NULL;
    }
    if (!page_size) {
        goto end;
    }

    
    if(!cJSON_IsNumber(page_size))
    {
    goto end; //Numeric
    }
    page_size_local_var = malloc(sizeof(int));
    if(!page_size_local_var)
    {
        goto end;
    }
    *page_size_local_var = page_size->valuedouble;

    // packing_queue->total_count
    cJSON *total_count = cJSON_GetObjectItemCaseSensitive(packing_queueJSON, "total_count");
    if (cJSON_IsNull(total_count)) {
        total_count = NULL;
    }
    if (!total_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_count))
    {
    goto end; //Numeric
    }
    total_count_local_var = malloc(sizeof(long));
    if(!total_count_local_var)
    {
        goto end;
    }
    *total_count_local_var = total_count->valuedouble;



    packing_queue_local_var = packing_queue_create_internal (
        itemsList,
        page_local_var,
        page_size_local_var,
        total_count_local_var
        );

    if (!packing_queue_local_var) {
        goto end;
    }

    return packing_queue_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            packing_queue_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (page_local_var) {
        free(page_local_var);
        page_local_var = NULL;
    }
    if (page_size_local_var) {
        free(page_size_local_var);
        page_size_local_var = NULL;
    }
    if (total_count_local_var) {
        free(total_count_local_var);
        total_count_local_var = NULL;
    }
    return NULL;

}
