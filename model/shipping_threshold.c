#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shipping_threshold.h"



static shipping_threshold_t *shipping_threshold_create_internal(
    int *is_active,
    long *max_sellable,
    char *name,
    char *notes,
    char *product_id,
    long *reserve_stock,
    char *warehouse_id
    ) {
    shipping_threshold_t *shipping_threshold_local_var = malloc(sizeof(shipping_threshold_t));
    if (!shipping_threshold_local_var) {
        return NULL;
    }
    memset(shipping_threshold_local_var, 0, sizeof(shipping_threshold_t));
    shipping_threshold_local_var->_library_owned = 1;
    shipping_threshold_local_var->is_active = is_active;
    shipping_threshold_local_var->max_sellable = max_sellable;
    shipping_threshold_local_var->name = name;
    shipping_threshold_local_var->notes = notes;
    shipping_threshold_local_var->product_id = product_id;
    shipping_threshold_local_var->reserve_stock = reserve_stock;
    shipping_threshold_local_var->warehouse_id = warehouse_id;
    return shipping_threshold_local_var;
}

__attribute__((deprecated)) shipping_threshold_t *shipping_threshold_create(
    int *is_active,
    long *max_sellable,
    char *name,
    char *notes,
    char *product_id,
    long *reserve_stock,
    char *warehouse_id
    ) {
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    long *max_sellable_copy = NULL;
    if (max_sellable) {
        max_sellable_copy = malloc(sizeof(long));
        if (max_sellable_copy) *max_sellable_copy = *max_sellable;
    }
    long *reserve_stock_copy = NULL;
    if (reserve_stock) {
        reserve_stock_copy = malloc(sizeof(long));
        if (reserve_stock_copy) *reserve_stock_copy = *reserve_stock;
    }
    shipping_threshold_t *result = shipping_threshold_create_internal (
        is_active_copy,
        max_sellable_copy,
        name,
        notes,
        product_id,
        reserve_stock_copy,
        warehouse_id
        );
    if (!result) {
        free(is_active_copy);
        free(max_sellable_copy);
        free(reserve_stock_copy);
    }
    return result;
}

void shipping_threshold_free(shipping_threshold_t *shipping_threshold) {
    if(NULL == shipping_threshold){
        return ;
    }
    if(shipping_threshold->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shipping_threshold_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shipping_threshold->is_active) {
        free(shipping_threshold->is_active);
        shipping_threshold->is_active = NULL;
    }
    if (shipping_threshold->max_sellable) {
        free(shipping_threshold->max_sellable);
        shipping_threshold->max_sellable = NULL;
    }
    if (shipping_threshold->name) {
        free(shipping_threshold->name);
        shipping_threshold->name = NULL;
    }
    if (shipping_threshold->notes) {
        free(shipping_threshold->notes);
        shipping_threshold->notes = NULL;
    }
    if (shipping_threshold->product_id) {
        free(shipping_threshold->product_id);
        shipping_threshold->product_id = NULL;
    }
    if (shipping_threshold->reserve_stock) {
        free(shipping_threshold->reserve_stock);
        shipping_threshold->reserve_stock = NULL;
    }
    if (shipping_threshold->warehouse_id) {
        free(shipping_threshold->warehouse_id);
        shipping_threshold->warehouse_id = NULL;
    }
    free(shipping_threshold);
}

cJSON *shipping_threshold_convertToJSON(shipping_threshold_t *shipping_threshold) {
    cJSON *item = cJSON_CreateObject();

    // shipping_threshold->is_active
    if(shipping_threshold->is_active) {
    if(cJSON_AddBoolToObject(item, "isActive", *shipping_threshold->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // shipping_threshold->max_sellable
    if(shipping_threshold->max_sellable) {
    if(cJSON_AddNumberToObject(item, "maxSellable", *shipping_threshold->max_sellable) == NULL) {
    goto fail; //Numeric
    }
    }


    // shipping_threshold->name
    if (!shipping_threshold->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", shipping_threshold->name) == NULL) {
    goto fail; //String
    }


    // shipping_threshold->notes
    if(shipping_threshold->notes) {
    if(cJSON_AddStringToObject(item, "notes", shipping_threshold->notes) == NULL) {
    goto fail; //String
    }
    }


    // shipping_threshold->product_id
    if(shipping_threshold->product_id) {
    if(cJSON_AddStringToObject(item, "productId", shipping_threshold->product_id) == NULL) {
    goto fail; //String
    }
    }


    // shipping_threshold->reserve_stock
    if(shipping_threshold->reserve_stock) {
    if(cJSON_AddNumberToObject(item, "reserveStock", *shipping_threshold->reserve_stock) == NULL) {
    goto fail; //Numeric
    }
    }


    // shipping_threshold->warehouse_id
    if(shipping_threshold->warehouse_id) {
    if(cJSON_AddStringToObject(item, "warehouseId", shipping_threshold->warehouse_id) == NULL) {
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

shipping_threshold_t *shipping_threshold_parseFromJSON(cJSON *shipping_thresholdJSON){

    shipping_threshold_t *shipping_threshold_local_var = NULL;

    // define the local variable for shipping_threshold->is_active
    int *is_active_local_var = NULL;

    // define the local variable for shipping_threshold->max_sellable
    long *max_sellable_local_var = NULL;

    char *name_local_str = NULL;

    char *notes_local_str = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for shipping_threshold->reserve_stock
    long *reserve_stock_local_var = NULL;

    char *warehouse_id_local_str = NULL;

    // shipping_threshold->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(shipping_thresholdJSON, "isActive");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (is_active) { 
    if(!cJSON_IsBool(is_active))
    {
    goto end; //Bool
    }
    is_active_local_var = malloc(sizeof(int));
    if(!is_active_local_var)
    {
        goto end;
    }
    *is_active_local_var = is_active->valueint;
    }

    // shipping_threshold->max_sellable
    cJSON *max_sellable = cJSON_GetObjectItemCaseSensitive(shipping_thresholdJSON, "maxSellable");
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

    // shipping_threshold->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(shipping_thresholdJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // shipping_threshold->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(shipping_thresholdJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // shipping_threshold->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(shipping_thresholdJSON, "productId");
    if (cJSON_IsNull(product_id)) {
        product_id = NULL;
    }
    if (product_id) { 
    if(!cJSON_IsString(product_id) && !cJSON_IsNull(product_id))
    {
    goto end; //String
    }
    }

    // shipping_threshold->reserve_stock
    cJSON *reserve_stock = cJSON_GetObjectItemCaseSensitive(shipping_thresholdJSON, "reserveStock");
    if (cJSON_IsNull(reserve_stock)) {
        reserve_stock = NULL;
    }
    if (reserve_stock) { 
    if(!cJSON_IsNumber(reserve_stock))
    {
    goto end; //Numeric
    }
    reserve_stock_local_var = malloc(sizeof(long));
    if(!reserve_stock_local_var)
    {
        goto end;
    }
    *reserve_stock_local_var = reserve_stock->valuedouble;
    }

    // shipping_threshold->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(shipping_thresholdJSON, "warehouseId");
    if (cJSON_IsNull(warehouse_id)) {
        warehouse_id = NULL;
    }
    if (warehouse_id) { 
    if(!cJSON_IsString(warehouse_id) && !cJSON_IsNull(warehouse_id))
    {
    goto end; //String
    }
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (warehouse_id && !cJSON_IsNull(warehouse_id)) warehouse_id_local_str = strdup(warehouse_id->valuestring);

    shipping_threshold_local_var = shipping_threshold_create_internal (
        is_active_local_var,
        max_sellable_local_var,
        name_local_str,
        notes_local_str,
        product_id_local_str,
        reserve_stock_local_var,
        warehouse_id_local_str
        );

    if (!shipping_threshold_local_var) {
        goto end;
    }

    return shipping_threshold_local_var;
end:
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (max_sellable_local_var) {
        free(max_sellable_local_var);
        max_sellable_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (reserve_stock_local_var) {
        free(reserve_stock_local_var);
        reserve_stock_local_var = NULL;
    }
    if (warehouse_id_local_str) {
        free(warehouse_id_local_str);
        warehouse_id_local_str = NULL;
    }
    return NULL;

}
