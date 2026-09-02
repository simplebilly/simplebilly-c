#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "public_return_request.h"



static public_return_request_t *public_return_request_create_internal(
    char *email,
    list_t *items,
    char *notes,
    char *order_number
    ) {
    public_return_request_t *public_return_request_local_var = malloc(sizeof(public_return_request_t));
    if (!public_return_request_local_var) {
        return NULL;
    }
    memset(public_return_request_local_var, 0, sizeof(public_return_request_t));
    public_return_request_local_var->_library_owned = 1;
    public_return_request_local_var->email = email;
    public_return_request_local_var->items = items;
    public_return_request_local_var->notes = notes;
    public_return_request_local_var->order_number = order_number;
    return public_return_request_local_var;
}

__attribute__((deprecated)) public_return_request_t *public_return_request_create(
    char *email,
    list_t *items,
    char *notes,
    char *order_number
    ) {
    public_return_request_t *result = public_return_request_create_internal (
        email,
        items,
        notes,
        order_number
        );
    if (!result) {
    }
    return result;
}

void public_return_request_free(public_return_request_t *public_return_request) {
    if(NULL == public_return_request){
        return ;
    }
    if(public_return_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "public_return_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (public_return_request->email) {
        free(public_return_request->email);
        public_return_request->email = NULL;
    }
    if (public_return_request->items) {
        list_ForEach(listEntry, public_return_request->items) {
            public_return_item_free(listEntry->data);
        }
        list_freeList(public_return_request->items);
        public_return_request->items = NULL;
    }
    if (public_return_request->notes) {
        free(public_return_request->notes);
        public_return_request->notes = NULL;
    }
    if (public_return_request->order_number) {
        free(public_return_request->order_number);
        public_return_request->order_number = NULL;
    }
    free(public_return_request);
}

cJSON *public_return_request_convertToJSON(public_return_request_t *public_return_request) {
    cJSON *item = cJSON_CreateObject();

    // public_return_request->email
    if (!public_return_request->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", public_return_request->email) == NULL) {
    goto fail; //String
    }


    // public_return_request->items
    if (!public_return_request->items) {
        goto fail;
    }
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (public_return_request->items) {
    list_ForEach(itemsListEntry, public_return_request->items) {
    cJSON *itemLocal = public_return_item_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // public_return_request->notes
    if(public_return_request->notes) {
    if(cJSON_AddStringToObject(item, "notes", public_return_request->notes) == NULL) {
    goto fail; //String
    }
    }


    // public_return_request->order_number
    if (!public_return_request->order_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "orderNumber", public_return_request->order_number) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

public_return_request_t *public_return_request_parseFromJSON(cJSON *public_return_requestJSON){

    public_return_request_t *public_return_request_local_var = NULL;

    char *email_local_str = NULL;

    // define the local list for public_return_request->items
    list_t *itemsList = NULL;

    char *notes_local_str = NULL;

    char *order_number_local_str = NULL;

    // public_return_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(public_return_requestJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }

    // public_return_request->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(public_return_requestJSON, "items");
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
        public_return_item_t *itemsItem = public_return_item_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // public_return_request->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(public_return_requestJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // public_return_request->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(public_return_requestJSON, "orderNumber");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (!order_number) {
        goto end;
    }

    
    if(!cJSON_IsString(order_number))
    {
    goto end; //String
    }


    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);

    public_return_request_local_var = public_return_request_create_internal (
        email_local_str,
        itemsList,
        notes_local_str,
        order_number_local_str
        );

    if (!public_return_request_local_var) {
        goto end;
    }

    return public_return_request_local_var;
end:
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            public_return_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    return NULL;

}
