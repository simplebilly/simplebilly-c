#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "suitability_request.h"



static suitability_request_t *suitability_request_create_internal(
    int *customer_annual_volume,
    list_t *items,
    address_t *recipient,
    address_t *sender
    ) {
    suitability_request_t *suitability_request_local_var = malloc(sizeof(suitability_request_t));
    if (!suitability_request_local_var) {
        return NULL;
    }
    memset(suitability_request_local_var, 0, sizeof(suitability_request_t));
    suitability_request_local_var->_library_owned = 1;
    suitability_request_local_var->customer_annual_volume = customer_annual_volume;
    suitability_request_local_var->items = items;
    suitability_request_local_var->recipient = recipient;
    suitability_request_local_var->sender = sender;
    return suitability_request_local_var;
}

__attribute__((deprecated)) suitability_request_t *suitability_request_create(
    int *customer_annual_volume,
    list_t *items,
    address_t *recipient,
    address_t *sender
    ) {
    int *customer_annual_volume_copy = NULL;
    if (customer_annual_volume) {
        customer_annual_volume_copy = malloc(sizeof(int));
        if (customer_annual_volume_copy) *customer_annual_volume_copy = *customer_annual_volume;
    }
    suitability_request_t *result = suitability_request_create_internal (
        customer_annual_volume_copy,
        items,
        recipient,
        sender
        );
    if (!result) {
        free(customer_annual_volume_copy);
    }
    return result;
}

void suitability_request_free(suitability_request_t *suitability_request) {
    if(NULL == suitability_request){
        return ;
    }
    if(suitability_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "suitability_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (suitability_request->customer_annual_volume) {
        free(suitability_request->customer_annual_volume);
        suitability_request->customer_annual_volume = NULL;
    }
    if (suitability_request->items) {
        list_ForEach(listEntry, suitability_request->items) {
            cart_item_input_free(listEntry->data);
        }
        list_freeList(suitability_request->items);
        suitability_request->items = NULL;
    }
    if (suitability_request->recipient) {
        address_free(suitability_request->recipient);
        suitability_request->recipient = NULL;
    }
    if (suitability_request->sender) {
        address_free(suitability_request->sender);
        suitability_request->sender = NULL;
    }
    free(suitability_request);
}

cJSON *suitability_request_convertToJSON(suitability_request_t *suitability_request) {
    cJSON *item = cJSON_CreateObject();

    // suitability_request->customer_annual_volume
    if(suitability_request->customer_annual_volume) {
    if(cJSON_AddNumberToObject(item, "customer_annual_volume", *suitability_request->customer_annual_volume) == NULL) {
    goto fail; //Numeric
    }
    }


    // suitability_request->items
    if (!suitability_request->items) {
        goto fail;
    }
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (suitability_request->items) {
    list_ForEach(itemsListEntry, suitability_request->items) {
    cJSON *itemLocal = cart_item_input_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // suitability_request->recipient
    if (!suitability_request->recipient) {
        goto fail;
    }
    cJSON *recipient_local_JSON = address_convertToJSON(suitability_request->recipient);
    if(recipient_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "recipient", recipient_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // suitability_request->sender
    if (!suitability_request->sender) {
        goto fail;
    }
    cJSON *sender_local_JSON = address_convertToJSON(suitability_request->sender);
    if(sender_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sender", sender_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

suitability_request_t *suitability_request_parseFromJSON(cJSON *suitability_requestJSON){

    suitability_request_t *suitability_request_local_var = NULL;

    // define the local variable for suitability_request->customer_annual_volume
    int *customer_annual_volume_local_var = NULL;

    // define the local list for suitability_request->items
    list_t *itemsList = NULL;

    // define the local variable for suitability_request->recipient
    address_t *recipient_local_nonprim = NULL;

    // define the local variable for suitability_request->sender
    address_t *sender_local_nonprim = NULL;

    // suitability_request->customer_annual_volume
    cJSON *customer_annual_volume = cJSON_GetObjectItemCaseSensitive(suitability_requestJSON, "customer_annual_volume");
    if (cJSON_IsNull(customer_annual_volume)) {
        customer_annual_volume = NULL;
    }
    if (customer_annual_volume) { 
    if(!cJSON_IsNumber(customer_annual_volume))
    {
    goto end; //Numeric
    }
    customer_annual_volume_local_var = malloc(sizeof(int));
    if(!customer_annual_volume_local_var)
    {
        goto end;
    }
    *customer_annual_volume_local_var = customer_annual_volume->valuedouble;
    }

    // suitability_request->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(suitability_requestJSON, "items");
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
        cart_item_input_t *itemsItem = cart_item_input_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // suitability_request->recipient
    cJSON *recipient = cJSON_GetObjectItemCaseSensitive(suitability_requestJSON, "recipient");
    if (cJSON_IsNull(recipient)) {
        recipient = NULL;
    }
    if (!recipient) {
        goto end;
    }

    
    recipient_local_nonprim = address_parseFromJSON(recipient); //nonprimitive

    // suitability_request->sender
    cJSON *sender = cJSON_GetObjectItemCaseSensitive(suitability_requestJSON, "sender");
    if (cJSON_IsNull(sender)) {
        sender = NULL;
    }
    if (!sender) {
        goto end;
    }

    
    sender_local_nonprim = address_parseFromJSON(sender); //nonprimitive



    suitability_request_local_var = suitability_request_create_internal (
        customer_annual_volume_local_var,
        itemsList,
        recipient_local_nonprim,
        sender_local_nonprim
        );

    if (!suitability_request_local_var) {
        goto end;
    }

    return suitability_request_local_var;
end:
    if (customer_annual_volume_local_var) {
        free(customer_annual_volume_local_var);
        customer_annual_volume_local_var = NULL;
    }
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            cart_item_input_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (recipient_local_nonprim) {
        address_free(recipient_local_nonprim);
        recipient_local_nonprim = NULL;
    }
    if (sender_local_nonprim) {
        address_free(sender_local_nonprim);
        sender_local_nonprim = NULL;
    }
    return NULL;

}
