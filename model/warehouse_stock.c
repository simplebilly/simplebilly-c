#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "warehouse_stock.h"



static warehouse_stock_t *warehouse_stock_create_internal(
    char *batch_number,
    char *bin_location,
    char *expiry_date,
    char *product_id,
    long *quantity,
    any_type_t *serial_numbers,
    char *warehouse_id
    ) {
    warehouse_stock_t *warehouse_stock_local_var = malloc(sizeof(warehouse_stock_t));
    if (!warehouse_stock_local_var) {
        return NULL;
    }
    memset(warehouse_stock_local_var, 0, sizeof(warehouse_stock_t));
    warehouse_stock_local_var->_library_owned = 1;
    warehouse_stock_local_var->batch_number = batch_number;
    warehouse_stock_local_var->bin_location = bin_location;
    warehouse_stock_local_var->expiry_date = expiry_date;
    warehouse_stock_local_var->product_id = product_id;
    warehouse_stock_local_var->quantity = quantity;
    warehouse_stock_local_var->serial_numbers = serial_numbers;
    warehouse_stock_local_var->warehouse_id = warehouse_id;
    return warehouse_stock_local_var;
}

__attribute__((deprecated)) warehouse_stock_t *warehouse_stock_create(
    char *batch_number,
    char *bin_location,
    char *expiry_date,
    char *product_id,
    long *quantity,
    any_type_t *serial_numbers,
    char *warehouse_id
    ) {
    long *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(long));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    warehouse_stock_t *result = warehouse_stock_create_internal (
        batch_number,
        bin_location,
        expiry_date,
        product_id,
        quantity_copy,
        serial_numbers,
        warehouse_id
        );
    if (!result) {
        free(quantity_copy);
    }
    return result;
}

void warehouse_stock_free(warehouse_stock_t *warehouse_stock) {
    if(NULL == warehouse_stock){
        return ;
    }
    if(warehouse_stock->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "warehouse_stock_free");
        return ;
    }
    listEntry_t *listEntry;
    if (warehouse_stock->batch_number) {
        free(warehouse_stock->batch_number);
        warehouse_stock->batch_number = NULL;
    }
    if (warehouse_stock->bin_location) {
        free(warehouse_stock->bin_location);
        warehouse_stock->bin_location = NULL;
    }
    if (warehouse_stock->expiry_date) {
        free(warehouse_stock->expiry_date);
        warehouse_stock->expiry_date = NULL;
    }
    if (warehouse_stock->product_id) {
        free(warehouse_stock->product_id);
        warehouse_stock->product_id = NULL;
    }
    if (warehouse_stock->quantity) {
        free(warehouse_stock->quantity);
        warehouse_stock->quantity = NULL;
    }
    if (warehouse_stock->serial_numbers) {
        _free(warehouse_stock->serial_numbers);
        warehouse_stock->serial_numbers = NULL;
    }
    if (warehouse_stock->warehouse_id) {
        free(warehouse_stock->warehouse_id);
        warehouse_stock->warehouse_id = NULL;
    }
    free(warehouse_stock);
}

cJSON *warehouse_stock_convertToJSON(warehouse_stock_t *warehouse_stock) {
    cJSON *item = cJSON_CreateObject();

    // warehouse_stock->batch_number
    if(warehouse_stock->batch_number) {
    if(cJSON_AddStringToObject(item, "batchNumber", warehouse_stock->batch_number) == NULL) {
    goto fail; //String
    }
    }


    // warehouse_stock->bin_location
    if(warehouse_stock->bin_location) {
    if(cJSON_AddStringToObject(item, "binLocation", warehouse_stock->bin_location) == NULL) {
    goto fail; //String
    }
    }


    // warehouse_stock->expiry_date
    if(warehouse_stock->expiry_date) {
    if(cJSON_AddStringToObject(item, "expiryDate", warehouse_stock->expiry_date) == NULL) {
    goto fail; //Date
    }
    }


    // warehouse_stock->product_id
    if (!warehouse_stock->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", warehouse_stock->product_id) == NULL) {
    goto fail; //String
    }


    // warehouse_stock->quantity
    if (!warehouse_stock->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *warehouse_stock->quantity) == NULL) {
    goto fail; //Numeric
    }


    // warehouse_stock->serial_numbers
    if(warehouse_stock->serial_numbers) {
    cJSON *serial_numbers_local_JSON = _convertToJSON(warehouse_stock->serial_numbers);
    if(serial_numbers_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "serialNumbers", serial_numbers_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // warehouse_stock->warehouse_id
    if (!warehouse_stock->warehouse_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "warehouseId", warehouse_stock->warehouse_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

warehouse_stock_t *warehouse_stock_parseFromJSON(cJSON *warehouse_stockJSON){

    warehouse_stock_t *warehouse_stock_local_var = NULL;

    char *batch_number_local_str = NULL;

    char *bin_location_local_str = NULL;

    char *expiry_date_local_str = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for warehouse_stock->quantity
    long *quantity_local_var = NULL;

    // define the local variable for warehouse_stock->serial_numbers
    _t *serial_numbers_local_nonprim = NULL;

    char *warehouse_id_local_str = NULL;

    // warehouse_stock->batch_number
    cJSON *batch_number = cJSON_GetObjectItemCaseSensitive(warehouse_stockJSON, "batchNumber");
    if (cJSON_IsNull(batch_number)) {
        batch_number = NULL;
    }
    if (batch_number) { 
    if(!cJSON_IsString(batch_number) && !cJSON_IsNull(batch_number))
    {
    goto end; //String
    }
    }

    // warehouse_stock->bin_location
    cJSON *bin_location = cJSON_GetObjectItemCaseSensitive(warehouse_stockJSON, "binLocation");
    if (cJSON_IsNull(bin_location)) {
        bin_location = NULL;
    }
    if (bin_location) { 
    if(!cJSON_IsString(bin_location) && !cJSON_IsNull(bin_location))
    {
    goto end; //String
    }
    }

    // warehouse_stock->expiry_date
    cJSON *expiry_date = cJSON_GetObjectItemCaseSensitive(warehouse_stockJSON, "expiryDate");
    if (cJSON_IsNull(expiry_date)) {
        expiry_date = NULL;
    }
    if (expiry_date) { 
    if(!cJSON_IsString(expiry_date))
    {
    goto end; //Date
    }
    }

    // warehouse_stock->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(warehouse_stockJSON, "productId");
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

    // warehouse_stock->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(warehouse_stockJSON, "quantity");
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

    // warehouse_stock->serial_numbers
    cJSON *serial_numbers = cJSON_GetObjectItemCaseSensitive(warehouse_stockJSON, "serialNumbers");
    if (cJSON_IsNull(serial_numbers)) {
        serial_numbers = NULL;
    }
    if (serial_numbers) { 
    serial_numbers_local_nonprim = _parseFromJSON(serial_numbers); //custom
    }

    // warehouse_stock->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(warehouse_stockJSON, "warehouseId");
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


    if (batch_number && !cJSON_IsNull(batch_number)) batch_number_local_str = strdup(batch_number->valuestring);
    if (bin_location && !cJSON_IsNull(bin_location)) bin_location_local_str = strdup(bin_location->valuestring);
    if (expiry_date) expiry_date_local_str = strdup(expiry_date->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (warehouse_id && !cJSON_IsNull(warehouse_id)) warehouse_id_local_str = strdup(warehouse_id->valuestring);

    warehouse_stock_local_var = warehouse_stock_create_internal (
        batch_number_local_str,
        bin_location_local_str,
        expiry_date_local_str,
        product_id_local_str,
        quantity_local_var,
        serial_numbers ? serial_numbers_local_nonprim : NULL,
        warehouse_id_local_str
        );

    if (!warehouse_stock_local_var) {
        goto end;
    }

    return warehouse_stock_local_var;
end:
    if (batch_number_local_str) {
        free(batch_number_local_str);
        batch_number_local_str = NULL;
    }
    if (bin_location_local_str) {
        free(bin_location_local_str);
        bin_location_local_str = NULL;
    }
    if (expiry_date_local_str) {
        free(expiry_date_local_str);
        expiry_date_local_str = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (serial_numbers_local_nonprim) {
        _free(serial_numbers_local_nonprim);
        serial_numbers_local_nonprim = NULL;
    }
    if (warehouse_id_local_str) {
        free(warehouse_id_local_str);
        warehouse_id_local_str = NULL;
    }
    return NULL;

}
