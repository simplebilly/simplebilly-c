#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "public_return_item.h"



static public_return_item_t *public_return_item_create_internal(
    char *name,
    char *product_id,
    long *quantity,
    char *reason
    ) {
    public_return_item_t *public_return_item_local_var = malloc(sizeof(public_return_item_t));
    if (!public_return_item_local_var) {
        return NULL;
    }
    memset(public_return_item_local_var, 0, sizeof(public_return_item_t));
    public_return_item_local_var->_library_owned = 1;
    public_return_item_local_var->name = name;
    public_return_item_local_var->product_id = product_id;
    public_return_item_local_var->quantity = quantity;
    public_return_item_local_var->reason = reason;
    return public_return_item_local_var;
}

__attribute__((deprecated)) public_return_item_t *public_return_item_create(
    char *name,
    char *product_id,
    long *quantity,
    char *reason
    ) {
    long *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(long));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    public_return_item_t *result = public_return_item_create_internal (
        name,
        product_id,
        quantity_copy,
        reason
        );
    if (!result) {
        free(quantity_copy);
    }
    return result;
}

void public_return_item_free(public_return_item_t *public_return_item) {
    if(NULL == public_return_item){
        return ;
    }
    if(public_return_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "public_return_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (public_return_item->name) {
        free(public_return_item->name);
        public_return_item->name = NULL;
    }
    if (public_return_item->product_id) {
        free(public_return_item->product_id);
        public_return_item->product_id = NULL;
    }
    if (public_return_item->quantity) {
        free(public_return_item->quantity);
        public_return_item->quantity = NULL;
    }
    if (public_return_item->reason) {
        free(public_return_item->reason);
        public_return_item->reason = NULL;
    }
    free(public_return_item);
}

cJSON *public_return_item_convertToJSON(public_return_item_t *public_return_item) {
    cJSON *item = cJSON_CreateObject();

    // public_return_item->name
    if(public_return_item->name) {
    if(cJSON_AddStringToObject(item, "name", public_return_item->name) == NULL) {
    goto fail; //String
    }
    }


    // public_return_item->product_id
    if (!public_return_item->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", public_return_item->product_id) == NULL) {
    goto fail; //String
    }


    // public_return_item->quantity
    if (!public_return_item->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *public_return_item->quantity) == NULL) {
    goto fail; //Numeric
    }


    // public_return_item->reason
    if(public_return_item->reason) {
    if(cJSON_AddStringToObject(item, "reason", public_return_item->reason) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

public_return_item_t *public_return_item_parseFromJSON(cJSON *public_return_itemJSON){

    public_return_item_t *public_return_item_local_var = NULL;

    char *name_local_str = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for public_return_item->quantity
    long *quantity_local_var = NULL;

    char *reason_local_str = NULL;

    // public_return_item->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(public_return_itemJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // public_return_item->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(public_return_itemJSON, "productId");
    if (cJSON_IsNull(product_id)) {
        product_id = NULL;
    }
    if (!product_id) {
        goto end;
    }

    
    if(!cJSON_IsString(product_id))
    {
    goto end; //String
    }

    // public_return_item->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(public_return_itemJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (!quantity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }
    quantity_local_var = malloc(sizeof(long));
    if(!quantity_local_var)
    {
        goto end;
    }
    *quantity_local_var = quantity->valuedouble;

    // public_return_item->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(public_return_itemJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);

    public_return_item_local_var = public_return_item_create_internal (
        name_local_str,
        product_id_local_str,
        quantity_local_var,
        reason_local_str
        );

    if (!public_return_item_local_var) {
        goto end;
    }

    return public_return_item_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (reason_local_str) {
        free(reason_local_str);
        reason_local_str = NULL;
    }
    return NULL;

}
