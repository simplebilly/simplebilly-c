#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "public_return_response.h"



static public_return_response_t *public_return_response_create_internal(
    char *created_at,
    any_type_t *items,
    char *notes,
    char *order_number,
    char *return_number,
    char *return_order_id,
    char *status,
    char *updated_at
    ) {
    public_return_response_t *public_return_response_local_var = malloc(sizeof(public_return_response_t));
    if (!public_return_response_local_var) {
        return NULL;
    }
    memset(public_return_response_local_var, 0, sizeof(public_return_response_t));
    public_return_response_local_var->_library_owned = 1;
    public_return_response_local_var->created_at = created_at;
    public_return_response_local_var->items = items;
    public_return_response_local_var->notes = notes;
    public_return_response_local_var->order_number = order_number;
    public_return_response_local_var->return_number = return_number;
    public_return_response_local_var->return_order_id = return_order_id;
    public_return_response_local_var->status = status;
    public_return_response_local_var->updated_at = updated_at;
    return public_return_response_local_var;
}

__attribute__((deprecated)) public_return_response_t *public_return_response_create(
    char *created_at,
    any_type_t *items,
    char *notes,
    char *order_number,
    char *return_number,
    char *return_order_id,
    char *status,
    char *updated_at
    ) {
    public_return_response_t *result = public_return_response_create_internal (
        created_at,
        items,
        notes,
        order_number,
        return_number,
        return_order_id,
        status,
        updated_at
        );
    if (!result) {
    }
    return result;
}

void public_return_response_free(public_return_response_t *public_return_response) {
    if(NULL == public_return_response){
        return ;
    }
    if(public_return_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "public_return_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (public_return_response->created_at) {
        free(public_return_response->created_at);
        public_return_response->created_at = NULL;
    }
    if (public_return_response->items) {
        _free(public_return_response->items);
        public_return_response->items = NULL;
    }
    if (public_return_response->notes) {
        free(public_return_response->notes);
        public_return_response->notes = NULL;
    }
    if (public_return_response->order_number) {
        free(public_return_response->order_number);
        public_return_response->order_number = NULL;
    }
    if (public_return_response->return_number) {
        free(public_return_response->return_number);
        public_return_response->return_number = NULL;
    }
    if (public_return_response->return_order_id) {
        free(public_return_response->return_order_id);
        public_return_response->return_order_id = NULL;
    }
    if (public_return_response->status) {
        free(public_return_response->status);
        public_return_response->status = NULL;
    }
    if (public_return_response->updated_at) {
        free(public_return_response->updated_at);
        public_return_response->updated_at = NULL;
    }
    free(public_return_response);
}

cJSON *public_return_response_convertToJSON(public_return_response_t *public_return_response) {
    cJSON *item = cJSON_CreateObject();

    // public_return_response->created_at
    if (!public_return_response->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", public_return_response->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // public_return_response->items
    if (!public_return_response->items) {
        goto fail;
    }
    cJSON *items_local_JSON = _convertToJSON(public_return_response->items);
    if(items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "items", items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // public_return_response->notes
    if(public_return_response->notes) {
    if(cJSON_AddStringToObject(item, "notes", public_return_response->notes) == NULL) {
    goto fail; //String
    }
    }


    // public_return_response->order_number
    if(public_return_response->order_number) {
    if(cJSON_AddStringToObject(item, "orderNumber", public_return_response->order_number) == NULL) {
    goto fail; //String
    }
    }


    // public_return_response->return_number
    if (!public_return_response->return_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "returnNumber", public_return_response->return_number) == NULL) {
    goto fail; //String
    }


    // public_return_response->return_order_id
    if (!public_return_response->return_order_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "returnOrderId", public_return_response->return_order_id) == NULL) {
    goto fail; //String
    }


    // public_return_response->status
    if (!public_return_response->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", public_return_response->status) == NULL) {
    goto fail; //String
    }


    // public_return_response->updated_at
    if(public_return_response->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", public_return_response->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

public_return_response_t *public_return_response_parseFromJSON(cJSON *public_return_responseJSON){

    public_return_response_t *public_return_response_local_var = NULL;

    char *created_at_local_str = NULL;

    // define the local variable for public_return_response->items
    _t *items_local_nonprim = NULL;

    char *notes_local_str = NULL;

    char *order_number_local_str = NULL;

    char *return_number_local_str = NULL;

    char *return_order_id_local_str = NULL;

    char *status_local_str = NULL;

    char *updated_at_local_str = NULL;

    // public_return_response->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(public_return_responseJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // public_return_response->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(public_return_responseJSON, "items");
    if (cJSON_IsNull(items)) {
        items = NULL;
    }
    if (!items) {
        goto end;
    }

    
    items_local_nonprim = _parseFromJSON(items); //custom

    // public_return_response->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(public_return_responseJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // public_return_response->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(public_return_responseJSON, "orderNumber");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (order_number) { 
    if(!cJSON_IsString(order_number) && !cJSON_IsNull(order_number))
    {
    goto end; //String
    }
    }

    // public_return_response->return_number
    cJSON *return_number = cJSON_GetObjectItemCaseSensitive(public_return_responseJSON, "returnNumber");
    if (cJSON_IsNull(return_number)) {
        return_number = NULL;
    }
    if (!return_number) {
        goto end;
    }

    
    if(!cJSON_IsString(return_number))
    {
    goto end; //String
    }

    // public_return_response->return_order_id
    cJSON *return_order_id = cJSON_GetObjectItemCaseSensitive(public_return_responseJSON, "returnOrderId");
    if (cJSON_IsNull(return_order_id)) {
        return_order_id = NULL;
    }
    if (!return_order_id) {
        goto end;
    }

    
    if(!cJSON_IsString(return_order_id))
    {
    goto end; //String
    }

    // public_return_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(public_return_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // public_return_response->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(public_return_responseJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);
    if (return_number && !cJSON_IsNull(return_number)) return_number_local_str = strdup(return_number->valuestring);
    if (return_order_id && !cJSON_IsNull(return_order_id)) return_order_id_local_str = strdup(return_order_id->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    public_return_response_local_var = public_return_response_create_internal (
        created_at_local_str,
        items_local_nonprim,
        notes_local_str,
        order_number_local_str,
        return_number_local_str,
        return_order_id_local_str,
        status_local_str,
        updated_at_local_str
        );

    if (!public_return_response_local_var) {
        goto end;
    }

    return public_return_response_local_var;
end:
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (items_local_nonprim) {
        _free(items_local_nonprim);
        items_local_nonprim = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    if (return_number_local_str) {
        free(return_number_local_str);
        return_number_local_str = NULL;
    }
    if (return_order_id_local_str) {
        free(return_order_id_local_str);
        return_order_id_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    return NULL;

}
