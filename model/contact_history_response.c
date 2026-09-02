#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "contact_history_response.h"



static contact_history_response_t *contact_history_response_create_internal(
    char *contact_id,
    long *inbound_count,
    list_t *items,
    long *outbound_count
    ) {
    contact_history_response_t *contact_history_response_local_var = malloc(sizeof(contact_history_response_t));
    if (!contact_history_response_local_var) {
        return NULL;
    }
    memset(contact_history_response_local_var, 0, sizeof(contact_history_response_t));
    contact_history_response_local_var->_library_owned = 1;
    contact_history_response_local_var->contact_id = contact_id;
    contact_history_response_local_var->inbound_count = inbound_count;
    contact_history_response_local_var->items = items;
    contact_history_response_local_var->outbound_count = outbound_count;
    return contact_history_response_local_var;
}

__attribute__((deprecated)) contact_history_response_t *contact_history_response_create(
    char *contact_id,
    long *inbound_count,
    list_t *items,
    long *outbound_count
    ) {
    long *inbound_count_copy = NULL;
    if (inbound_count) {
        inbound_count_copy = malloc(sizeof(long));
        if (inbound_count_copy) *inbound_count_copy = *inbound_count;
    }
    long *outbound_count_copy = NULL;
    if (outbound_count) {
        outbound_count_copy = malloc(sizeof(long));
        if (outbound_count_copy) *outbound_count_copy = *outbound_count;
    }
    contact_history_response_t *result = contact_history_response_create_internal (
        contact_id,
        inbound_count_copy,
        items,
        outbound_count_copy
        );
    if (!result) {
        free(inbound_count_copy);
        free(outbound_count_copy);
    }
    return result;
}

void contact_history_response_free(contact_history_response_t *contact_history_response) {
    if(NULL == contact_history_response){
        return ;
    }
    if(contact_history_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "contact_history_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (contact_history_response->contact_id) {
        free(contact_history_response->contact_id);
        contact_history_response->contact_id = NULL;
    }
    if (contact_history_response->inbound_count) {
        free(contact_history_response->inbound_count);
        contact_history_response->inbound_count = NULL;
    }
    if (contact_history_response->items) {
        list_ForEach(listEntry, contact_history_response->items) {
            customer_communication_free(listEntry->data);
        }
        list_freeList(contact_history_response->items);
        contact_history_response->items = NULL;
    }
    if (contact_history_response->outbound_count) {
        free(contact_history_response->outbound_count);
        contact_history_response->outbound_count = NULL;
    }
    free(contact_history_response);
}

cJSON *contact_history_response_convertToJSON(contact_history_response_t *contact_history_response) {
    cJSON *item = cJSON_CreateObject();

    // contact_history_response->contact_id
    if (!contact_history_response->contact_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "contactId", contact_history_response->contact_id) == NULL) {
    goto fail; //String
    }


    // contact_history_response->inbound_count
    if (!contact_history_response->inbound_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "inboundCount", *contact_history_response->inbound_count) == NULL) {
    goto fail; //Numeric
    }


    // contact_history_response->items
    if (!contact_history_response->items) {
        goto fail;
    }
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (contact_history_response->items) {
    list_ForEach(itemsListEntry, contact_history_response->items) {
    cJSON *itemLocal = customer_communication_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // contact_history_response->outbound_count
    if (!contact_history_response->outbound_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "outboundCount", *contact_history_response->outbound_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

contact_history_response_t *contact_history_response_parseFromJSON(cJSON *contact_history_responseJSON){

    contact_history_response_t *contact_history_response_local_var = NULL;

    char *contact_id_local_str = NULL;

    // define the local variable for contact_history_response->inbound_count
    long *inbound_count_local_var = NULL;

    // define the local list for contact_history_response->items
    list_t *itemsList = NULL;

    // define the local variable for contact_history_response->outbound_count
    long *outbound_count_local_var = NULL;

    // contact_history_response->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(contact_history_responseJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (!contact_id) {
        goto end;
    }

    
    if(!cJSON_IsString(contact_id))
    {
    goto end; //String
    }

    // contact_history_response->inbound_count
    cJSON *inbound_count = cJSON_GetObjectItemCaseSensitive(contact_history_responseJSON, "inboundCount");
    if (cJSON_IsNull(inbound_count)) {
        inbound_count = NULL;
    }
    if (!inbound_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(inbound_count))
    {
    goto end; //Numeric
    }
    inbound_count_local_var = malloc(sizeof(long));
    if(!inbound_count_local_var)
    {
        goto end;
    }
    *inbound_count_local_var = inbound_count->valuedouble;

    // contact_history_response->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(contact_history_responseJSON, "items");
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
        customer_communication_t *itemsItem = customer_communication_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // contact_history_response->outbound_count
    cJSON *outbound_count = cJSON_GetObjectItemCaseSensitive(contact_history_responseJSON, "outboundCount");
    if (cJSON_IsNull(outbound_count)) {
        outbound_count = NULL;
    }
    if (!outbound_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(outbound_count))
    {
    goto end; //Numeric
    }
    outbound_count_local_var = malloc(sizeof(long));
    if(!outbound_count_local_var)
    {
        goto end;
    }
    *outbound_count_local_var = outbound_count->valuedouble;


    if (contact_id && !cJSON_IsNull(contact_id)) contact_id_local_str = strdup(contact_id->valuestring);

    contact_history_response_local_var = contact_history_response_create_internal (
        contact_id_local_str,
        inbound_count_local_var,
        itemsList,
        outbound_count_local_var
        );

    if (!contact_history_response_local_var) {
        goto end;
    }

    return contact_history_response_local_var;
end:
    if (contact_id_local_str) {
        free(contact_id_local_str);
        contact_id_local_str = NULL;
    }
    if (inbound_count_local_var) {
        free(inbound_count_local_var);
        inbound_count_local_var = NULL;
    }
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            customer_communication_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (outbound_count_local_var) {
        free(outbound_count_local_var);
        outbound_count_local_var = NULL;
    }
    return NULL;

}
