#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "deliverable_response.h"



static deliverable_response_t *deliverable_response_create_internal(
    long *available_stock,
    long *deliverable_quantity,
    long *max_sellable,
    char *product_id,
    long *reserved_stock,
    char *warehouse_id
    ) {
    deliverable_response_t *deliverable_response_local_var = malloc(sizeof(deliverable_response_t));
    if (!deliverable_response_local_var) {
        return NULL;
    }
    memset(deliverable_response_local_var, 0, sizeof(deliverable_response_t));
    deliverable_response_local_var->_library_owned = 1;
    deliverable_response_local_var->available_stock = available_stock;
    deliverable_response_local_var->deliverable_quantity = deliverable_quantity;
    deliverable_response_local_var->max_sellable = max_sellable;
    deliverable_response_local_var->product_id = product_id;
    deliverable_response_local_var->reserved_stock = reserved_stock;
    deliverable_response_local_var->warehouse_id = warehouse_id;
    return deliverable_response_local_var;
}

__attribute__((deprecated)) deliverable_response_t *deliverable_response_create(
    long *available_stock,
    long *deliverable_quantity,
    long *max_sellable,
    char *product_id,
    long *reserved_stock,
    char *warehouse_id
    ) {
    long *available_stock_copy = NULL;
    if (available_stock) {
        available_stock_copy = malloc(sizeof(long));
        if (available_stock_copy) *available_stock_copy = *available_stock;
    }
    long *deliverable_quantity_copy = NULL;
    if (deliverable_quantity) {
        deliverable_quantity_copy = malloc(sizeof(long));
        if (deliverable_quantity_copy) *deliverable_quantity_copy = *deliverable_quantity;
    }
    long *max_sellable_copy = NULL;
    if (max_sellable) {
        max_sellable_copy = malloc(sizeof(long));
        if (max_sellable_copy) *max_sellable_copy = *max_sellable;
    }
    long *reserved_stock_copy = NULL;
    if (reserved_stock) {
        reserved_stock_copy = malloc(sizeof(long));
        if (reserved_stock_copy) *reserved_stock_copy = *reserved_stock;
    }
    deliverable_response_t *result = deliverable_response_create_internal (
        available_stock_copy,
        deliverable_quantity_copy,
        max_sellable_copy,
        product_id,
        reserved_stock_copy,
        warehouse_id
        );
    if (!result) {
        free(available_stock_copy);
        free(deliverable_quantity_copy);
        free(max_sellable_copy);
        free(reserved_stock_copy);
    }
    return result;
}

void deliverable_response_free(deliverable_response_t *deliverable_response) {
    if(NULL == deliverable_response){
        return ;
    }
    if(deliverable_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "deliverable_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (deliverable_response->available_stock) {
        free(deliverable_response->available_stock);
        deliverable_response->available_stock = NULL;
    }
    if (deliverable_response->deliverable_quantity) {
        free(deliverable_response->deliverable_quantity);
        deliverable_response->deliverable_quantity = NULL;
    }
    if (deliverable_response->max_sellable) {
        free(deliverable_response->max_sellable);
        deliverable_response->max_sellable = NULL;
    }
    if (deliverable_response->product_id) {
        free(deliverable_response->product_id);
        deliverable_response->product_id = NULL;
    }
    if (deliverable_response->reserved_stock) {
        free(deliverable_response->reserved_stock);
        deliverable_response->reserved_stock = NULL;
    }
    if (deliverable_response->warehouse_id) {
        free(deliverable_response->warehouse_id);
        deliverable_response->warehouse_id = NULL;
    }
    free(deliverable_response);
}

cJSON *deliverable_response_convertToJSON(deliverable_response_t *deliverable_response) {
    cJSON *item = cJSON_CreateObject();

    // deliverable_response->available_stock
    if (!deliverable_response->available_stock) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "availableStock", *deliverable_response->available_stock) == NULL) {
    goto fail; //Numeric
    }


    // deliverable_response->deliverable_quantity
    if (!deliverable_response->deliverable_quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "deliverableQuantity", *deliverable_response->deliverable_quantity) == NULL) {
    goto fail; //Numeric
    }


    // deliverable_response->max_sellable
    if(deliverable_response->max_sellable) {
    if(cJSON_AddNumberToObject(item, "maxSellable", *deliverable_response->max_sellable) == NULL) {
    goto fail; //Numeric
    }
    }


    // deliverable_response->product_id
    if (!deliverable_response->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", deliverable_response->product_id) == NULL) {
    goto fail; //String
    }


    // deliverable_response->reserved_stock
    if (!deliverable_response->reserved_stock) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "reservedStock", *deliverable_response->reserved_stock) == NULL) {
    goto fail; //Numeric
    }


    // deliverable_response->warehouse_id
    if(deliverable_response->warehouse_id) {
    if(cJSON_AddStringToObject(item, "warehouseId", deliverable_response->warehouse_id) == NULL) {
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

deliverable_response_t *deliverable_response_parseFromJSON(cJSON *deliverable_responseJSON){

    deliverable_response_t *deliverable_response_local_var = NULL;

    // define the local variable for deliverable_response->available_stock
    long *available_stock_local_var = NULL;

    // define the local variable for deliverable_response->deliverable_quantity
    long *deliverable_quantity_local_var = NULL;

    // define the local variable for deliverable_response->max_sellable
    long *max_sellable_local_var = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for deliverable_response->reserved_stock
    long *reserved_stock_local_var = NULL;

    char *warehouse_id_local_str = NULL;

    // deliverable_response->available_stock
    cJSON *available_stock = cJSON_GetObjectItemCaseSensitive(deliverable_responseJSON, "availableStock");
    if (cJSON_IsNull(available_stock)) {
        available_stock = NULL;
    }
    if (!available_stock) {
        goto end;
    }

    
    if(!cJSON_IsNumber(available_stock))
    {
    goto end; //Numeric
    }
    available_stock_local_var = malloc(sizeof(long));
    if(!available_stock_local_var)
    {
        goto end;
    }
    *available_stock_local_var = available_stock->valuedouble;

    // deliverable_response->deliverable_quantity
    cJSON *deliverable_quantity = cJSON_GetObjectItemCaseSensitive(deliverable_responseJSON, "deliverableQuantity");
    if (cJSON_IsNull(deliverable_quantity)) {
        deliverable_quantity = NULL;
    }
    if (!deliverable_quantity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(deliverable_quantity))
    {
    goto end; //Numeric
    }
    deliverable_quantity_local_var = malloc(sizeof(long));
    if(!deliverable_quantity_local_var)
    {
        goto end;
    }
    *deliverable_quantity_local_var = deliverable_quantity->valuedouble;

    // deliverable_response->max_sellable
    cJSON *max_sellable = cJSON_GetObjectItemCaseSensitive(deliverable_responseJSON, "maxSellable");
    if (cJSON_IsNull(max_sellable)) {
        max_sellable = NULL;
    }
    if (max_sellable) { 
    if(!cJSON_IsNumber(max_sellable))
    {
    goto end; //Numeric
    }
    max_sellable_local_var = malloc(sizeof(long));
    if(!max_sellable_local_var)
    {
        goto end;
    }
    *max_sellable_local_var = max_sellable->valuedouble;
    }

    // deliverable_response->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(deliverable_responseJSON, "productId");
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

    // deliverable_response->reserved_stock
    cJSON *reserved_stock = cJSON_GetObjectItemCaseSensitive(deliverable_responseJSON, "reservedStock");
    if (cJSON_IsNull(reserved_stock)) {
        reserved_stock = NULL;
    }
    if (!reserved_stock) {
        goto end;
    }

    
    if(!cJSON_IsNumber(reserved_stock))
    {
    goto end; //Numeric
    }
    reserved_stock_local_var = malloc(sizeof(long));
    if(!reserved_stock_local_var)
    {
        goto end;
    }
    *reserved_stock_local_var = reserved_stock->valuedouble;

    // deliverable_response->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(deliverable_responseJSON, "warehouseId");
    if (cJSON_IsNull(warehouse_id)) {
        warehouse_id = NULL;
    }
    if (warehouse_id) { 
    if(!cJSON_IsString(warehouse_id) && !cJSON_IsNull(warehouse_id))
    {
    goto end; //String
    }
    }


    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (warehouse_id && !cJSON_IsNull(warehouse_id)) warehouse_id_local_str = strdup(warehouse_id->valuestring);

    deliverable_response_local_var = deliverable_response_create_internal (
        available_stock_local_var,
        deliverable_quantity_local_var,
        max_sellable_local_var,
        product_id_local_str,
        reserved_stock_local_var,
        warehouse_id_local_str
        );

    if (!deliverable_response_local_var) {
        goto end;
    }

    return deliverable_response_local_var;
end:
    if (available_stock_local_var) {
        free(available_stock_local_var);
        available_stock_local_var = NULL;
    }
    if (deliverable_quantity_local_var) {
        free(deliverable_quantity_local_var);
        deliverable_quantity_local_var = NULL;
    }
    if (max_sellable_local_var) {
        free(max_sellable_local_var);
        max_sellable_local_var = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (reserved_stock_local_var) {
        free(reserved_stock_local_var);
        reserved_stock_local_var = NULL;
    }
    if (warehouse_id_local_str) {
        free(warehouse_id_local_str);
        warehouse_id_local_str = NULL;
    }
    return NULL;

}
