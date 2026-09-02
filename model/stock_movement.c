#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stock_movement.h"



static stock_movement_t *stock_movement_create_internal(
    long *delta,
    movement_type_t *movement_type,
    char *product_id,
    long *quantity,
    char *reason,
    char *reference_id,
    reference_type_t *reference_type,
    char *warehouse_id
    ) {
    stock_movement_t *stock_movement_local_var = malloc(sizeof(stock_movement_t));
    if (!stock_movement_local_var) {
        return NULL;
    }
    memset(stock_movement_local_var, 0, sizeof(stock_movement_t));
    stock_movement_local_var->_library_owned = 1;
    stock_movement_local_var->delta = delta;
    stock_movement_local_var->movement_type = movement_type;
    stock_movement_local_var->product_id = product_id;
    stock_movement_local_var->quantity = quantity;
    stock_movement_local_var->reason = reason;
    stock_movement_local_var->reference_id = reference_id;
    stock_movement_local_var->reference_type = reference_type;
    stock_movement_local_var->warehouse_id = warehouse_id;
    return stock_movement_local_var;
}

__attribute__((deprecated)) stock_movement_t *stock_movement_create(
    long *delta,
    movement_type_t *movement_type,
    char *product_id,
    long *quantity,
    char *reason,
    char *reference_id,
    reference_type_t *reference_type,
    char *warehouse_id
    ) {
    long *delta_copy = NULL;
    if (delta) {
        delta_copy = malloc(sizeof(long));
        if (delta_copy) *delta_copy = *delta;
    }
    long *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(long));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    stock_movement_t *result = stock_movement_create_internal (
        delta_copy,
        movement_type,
        product_id,
        quantity_copy,
        reason,
        reference_id,
        reference_type,
        warehouse_id
        );
    if (!result) {
        free(delta_copy);
        free(quantity_copy);
    }
    return result;
}

void stock_movement_free(stock_movement_t *stock_movement) {
    if(NULL == stock_movement){
        return ;
    }
    if(stock_movement->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stock_movement_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stock_movement->delta) {
        free(stock_movement->delta);
        stock_movement->delta = NULL;
    }
    if (stock_movement->movement_type) {
        movement_type_free(stock_movement->movement_type);
        stock_movement->movement_type = NULL;
    }
    if (stock_movement->product_id) {
        free(stock_movement->product_id);
        stock_movement->product_id = NULL;
    }
    if (stock_movement->quantity) {
        free(stock_movement->quantity);
        stock_movement->quantity = NULL;
    }
    if (stock_movement->reason) {
        free(stock_movement->reason);
        stock_movement->reason = NULL;
    }
    if (stock_movement->reference_id) {
        free(stock_movement->reference_id);
        stock_movement->reference_id = NULL;
    }
    if (stock_movement->reference_type) {
        reference_type_free(stock_movement->reference_type);
        stock_movement->reference_type = NULL;
    }
    if (stock_movement->warehouse_id) {
        free(stock_movement->warehouse_id);
        stock_movement->warehouse_id = NULL;
    }
    free(stock_movement);
}

cJSON *stock_movement_convertToJSON(stock_movement_t *stock_movement) {
    cJSON *item = cJSON_CreateObject();

    // stock_movement->delta
    if (!stock_movement->delta) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "delta", *stock_movement->delta) == NULL) {
    goto fail; //Numeric
    }


    // stock_movement->movement_type
    if (!stock_movement->movement_type) {
        goto fail;
    }
    cJSON *movement_type_local_JSON = movement_type_convertToJSON(stock_movement->movement_type);
    if(movement_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "movementType", movement_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // stock_movement->product_id
    if (!stock_movement->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", stock_movement->product_id) == NULL) {
    goto fail; //String
    }


    // stock_movement->quantity
    if (!stock_movement->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *stock_movement->quantity) == NULL) {
    goto fail; //Numeric
    }


    // stock_movement->reason
    if(stock_movement->reason) {
    if(cJSON_AddStringToObject(item, "reason", stock_movement->reason) == NULL) {
    goto fail; //String
    }
    }


    // stock_movement->reference_id
    if(stock_movement->reference_id) {
    if(cJSON_AddStringToObject(item, "referenceId", stock_movement->reference_id) == NULL) {
    goto fail; //String
    }
    }


    // stock_movement->reference_type
    if(stock_movement->reference_type) {
    cJSON *reference_type_local_JSON = reference_type_convertToJSON(stock_movement->reference_type);
    if(reference_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "referenceType", reference_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // stock_movement->warehouse_id
    if (!stock_movement->warehouse_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "warehouseId", stock_movement->warehouse_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

stock_movement_t *stock_movement_parseFromJSON(cJSON *stock_movementJSON){

    stock_movement_t *stock_movement_local_var = NULL;

    // define the local variable for stock_movement->delta
    long *delta_local_var = NULL;

    // define the local variable for stock_movement->movement_type
    movement_type_t *movement_type_local_nonprim = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for stock_movement->quantity
    long *quantity_local_var = NULL;

    char *reason_local_str = NULL;

    char *reference_id_local_str = NULL;

    // define the local variable for stock_movement->reference_type
    reference_type_t *reference_type_local_nonprim = NULL;

    char *warehouse_id_local_str = NULL;

    // stock_movement->delta
    cJSON *delta = cJSON_GetObjectItemCaseSensitive(stock_movementJSON, "delta");
    if (cJSON_IsNull(delta)) {
        delta = NULL;
    }
    if (!delta) {
        goto end;
    }

    
    if(!cJSON_IsNumber(delta))
    {
    goto end; //Numeric
    }
    delta_local_var = malloc(sizeof(long));
    if(!delta_local_var)
    {
        goto end;
    }
    *delta_local_var = delta->valuedouble;

    // stock_movement->movement_type
    cJSON *movement_type = cJSON_GetObjectItemCaseSensitive(stock_movementJSON, "movementType");
    if (cJSON_IsNull(movement_type)) {
        movement_type = NULL;
    }
    if (!movement_type) {
        goto end;
    }

    
    movement_type_local_nonprim = movement_type_parseFromJSON(movement_type); //custom

    // stock_movement->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(stock_movementJSON, "productId");
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

    // stock_movement->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(stock_movementJSON, "quantity");
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

    // stock_movement->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(stock_movementJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // stock_movement->reference_id
    cJSON *reference_id = cJSON_GetObjectItemCaseSensitive(stock_movementJSON, "referenceId");
    if (cJSON_IsNull(reference_id)) {
        reference_id = NULL;
    }
    if (reference_id) { 
    if(!cJSON_IsString(reference_id) && !cJSON_IsNull(reference_id))
    {
    goto end; //String
    }
    }

    // stock_movement->reference_type
    cJSON *reference_type = cJSON_GetObjectItemCaseSensitive(stock_movementJSON, "referenceType");
    if (cJSON_IsNull(reference_type)) {
        reference_type = NULL;
    }
    if (reference_type) { 
    reference_type_local_nonprim = reference_type_parseFromJSON(reference_type); //custom
    }

    // stock_movement->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(stock_movementJSON, "warehouseId");
    if (cJSON_IsNull(warehouse_id)) {
        warehouse_id = NULL;
    }
    if (!warehouse_id) {
        goto end;
    }

    
    if(!cJSON_IsString(warehouse_id))
    {
    goto end; //String
    }


    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);
    if (reference_id && !cJSON_IsNull(reference_id)) reference_id_local_str = strdup(reference_id->valuestring);
    if (warehouse_id && !cJSON_IsNull(warehouse_id)) warehouse_id_local_str = strdup(warehouse_id->valuestring);

    stock_movement_local_var = stock_movement_create_internal (
        delta_local_var,
        movement_type_local_nonprim,
        product_id_local_str,
        quantity_local_var,
        reason_local_str,
        reference_id_local_str,
        reference_type ? reference_type_local_nonprim : NULL,
        warehouse_id_local_str
        );

    if (!stock_movement_local_var) {
        goto end;
    }

    return stock_movement_local_var;
end:
    if (delta_local_var) {
        free(delta_local_var);
        delta_local_var = NULL;
    }
    if (movement_type_local_nonprim) {
        movement_type_free(movement_type_local_nonprim);
        movement_type_local_nonprim = NULL;
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
    if (reference_id_local_str) {
        free(reference_id_local_str);
        reference_id_local_str = NULL;
    }
    if (reference_type_local_nonprim) {
        reference_type_free(reference_type_local_nonprim);
        reference_type_local_nonprim = NULL;
    }
    if (warehouse_id_local_str) {
        free(warehouse_id_local_str);
        warehouse_id_local_str = NULL;
    }
    return NULL;

}
