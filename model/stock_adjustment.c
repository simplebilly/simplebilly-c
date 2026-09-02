#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stock_adjustment.h"



static stock_adjustment_t *stock_adjustment_create_internal(
    char *batch_number,
    char *bin_location,
    char *expiry_date,
    char *product_id,
    long *quantity,
    list_t *serial_numbers
    ) {
    stock_adjustment_t *stock_adjustment_local_var = malloc(sizeof(stock_adjustment_t));
    if (!stock_adjustment_local_var) {
        return NULL;
    }
    memset(stock_adjustment_local_var, 0, sizeof(stock_adjustment_t));
    stock_adjustment_local_var->_library_owned = 1;
    stock_adjustment_local_var->batch_number = batch_number;
    stock_adjustment_local_var->bin_location = bin_location;
    stock_adjustment_local_var->expiry_date = expiry_date;
    stock_adjustment_local_var->product_id = product_id;
    stock_adjustment_local_var->quantity = quantity;
    stock_adjustment_local_var->serial_numbers = serial_numbers;
    return stock_adjustment_local_var;
}

__attribute__((deprecated)) stock_adjustment_t *stock_adjustment_create(
    char *batch_number,
    char *bin_location,
    char *expiry_date,
    char *product_id,
    long *quantity,
    list_t *serial_numbers
    ) {
    long *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(long));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    stock_adjustment_t *result = stock_adjustment_create_internal (
        batch_number,
        bin_location,
        expiry_date,
        product_id,
        quantity_copy,
        serial_numbers
        );
    if (!result) {
        free(quantity_copy);
    }
    return result;
}

void stock_adjustment_free(stock_adjustment_t *stock_adjustment) {
    if(NULL == stock_adjustment){
        return ;
    }
    if(stock_adjustment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stock_adjustment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stock_adjustment->batch_number) {
        free(stock_adjustment->batch_number);
        stock_adjustment->batch_number = NULL;
    }
    if (stock_adjustment->bin_location) {
        free(stock_adjustment->bin_location);
        stock_adjustment->bin_location = NULL;
    }
    if (stock_adjustment->expiry_date) {
        free(stock_adjustment->expiry_date);
        stock_adjustment->expiry_date = NULL;
    }
    if (stock_adjustment->product_id) {
        free(stock_adjustment->product_id);
        stock_adjustment->product_id = NULL;
    }
    if (stock_adjustment->quantity) {
        free(stock_adjustment->quantity);
        stock_adjustment->quantity = NULL;
    }
    if (stock_adjustment->serial_numbers) {
        list_ForEach(listEntry, stock_adjustment->serial_numbers) {
            free(listEntry->data);
        }
        list_freeList(stock_adjustment->serial_numbers);
        stock_adjustment->serial_numbers = NULL;
    }
    free(stock_adjustment);
}

cJSON *stock_adjustment_convertToJSON(stock_adjustment_t *stock_adjustment) {
    cJSON *item = cJSON_CreateObject();

    // stock_adjustment->batch_number
    if(stock_adjustment->batch_number) {
    if(cJSON_AddStringToObject(item, "batchNumber", stock_adjustment->batch_number) == NULL) {
    goto fail; //String
    }
    }


    // stock_adjustment->bin_location
    if(stock_adjustment->bin_location) {
    if(cJSON_AddStringToObject(item, "binLocation", stock_adjustment->bin_location) == NULL) {
    goto fail; //String
    }
    }


    // stock_adjustment->expiry_date
    if(stock_adjustment->expiry_date) {
    if(cJSON_AddStringToObject(item, "expiryDate", stock_adjustment->expiry_date) == NULL) {
    goto fail; //Date
    }
    }


    // stock_adjustment->product_id
    if(stock_adjustment->product_id) {
    if(cJSON_AddStringToObject(item, "productId", stock_adjustment->product_id) == NULL) {
    goto fail; //String
    }
    }


    // stock_adjustment->quantity
    if (!stock_adjustment->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *stock_adjustment->quantity) == NULL) {
    goto fail; //Numeric
    }


    // stock_adjustment->serial_numbers
    if(stock_adjustment->serial_numbers) {
    cJSON *serial_numbers = cJSON_AddArrayToObject(item, "serialNumbers");
    if(serial_numbers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *serial_numbersListEntry;
    list_ForEach(serial_numbersListEntry, stock_adjustment->serial_numbers) {
    if(cJSON_AddStringToObject(serial_numbers, "", serial_numbersListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

stock_adjustment_t *stock_adjustment_parseFromJSON(cJSON *stock_adjustmentJSON){

    stock_adjustment_t *stock_adjustment_local_var = NULL;

    char *batch_number_local_str = NULL;

    char *bin_location_local_str = NULL;

    char *expiry_date_local_str = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for stock_adjustment->quantity
    long *quantity_local_var = NULL;

    // define the local list for stock_adjustment->serial_numbers
    list_t *serial_numbersList = NULL;

    // stock_adjustment->batch_number
    cJSON *batch_number = cJSON_GetObjectItemCaseSensitive(stock_adjustmentJSON, "batchNumber");
    if (cJSON_IsNull(batch_number)) {
        batch_number = NULL;
    }
    if (batch_number) { 
    if(!cJSON_IsString(batch_number) && !cJSON_IsNull(batch_number))
    {
    goto end; //String
    }
    }

    // stock_adjustment->bin_location
    cJSON *bin_location = cJSON_GetObjectItemCaseSensitive(stock_adjustmentJSON, "binLocation");
    if (cJSON_IsNull(bin_location)) {
        bin_location = NULL;
    }
    if (bin_location) { 
    if(!cJSON_IsString(bin_location) && !cJSON_IsNull(bin_location))
    {
    goto end; //String
    }
    }

    // stock_adjustment->expiry_date
    cJSON *expiry_date = cJSON_GetObjectItemCaseSensitive(stock_adjustmentJSON, "expiryDate");
    if (cJSON_IsNull(expiry_date)) {
        expiry_date = NULL;
    }
    if (expiry_date) { 
    if(!cJSON_IsString(expiry_date))
    {
    goto end; //Date
    }
    }

    // stock_adjustment->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(stock_adjustmentJSON, "productId");
    if (cJSON_IsNull(product_id)) {
        product_id = NULL;
    }
    if (product_id) { 
    if(!cJSON_IsString(product_id) && !cJSON_IsNull(product_id))
    {
    goto end; //String
    }
    }

    // stock_adjustment->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(stock_adjustmentJSON, "quantity");
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

    // stock_adjustment->serial_numbers
    cJSON *serial_numbers = cJSON_GetObjectItemCaseSensitive(stock_adjustmentJSON, "serialNumbers");
    if (cJSON_IsNull(serial_numbers)) {
        serial_numbers = NULL;
    }
    if (serial_numbers) { 
    cJSON *serial_numbers_local = NULL;
    if(!cJSON_IsArray(serial_numbers)) {
        goto end;//primitive container
    }
    serial_numbersList = list_createList();

    cJSON_ArrayForEach(serial_numbers_local, serial_numbers)
    {
        if(!cJSON_IsString(serial_numbers_local))
        {
            goto end;
        }
        list_addElement(serial_numbersList , strdup(serial_numbers_local->valuestring));
    }
    }


    if (batch_number && !cJSON_IsNull(batch_number)) batch_number_local_str = strdup(batch_number->valuestring);
    if (bin_location && !cJSON_IsNull(bin_location)) bin_location_local_str = strdup(bin_location->valuestring);
    if (expiry_date) expiry_date_local_str = strdup(expiry_date->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);

    stock_adjustment_local_var = stock_adjustment_create_internal (
        batch_number_local_str,
        bin_location_local_str,
        expiry_date_local_str,
        product_id_local_str,
        quantity_local_var,
        serial_numbers ? serial_numbersList : NULL
        );

    if (!stock_adjustment_local_var) {
        goto end;
    }

    return stock_adjustment_local_var;
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
    if (serial_numbersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, serial_numbersList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(serial_numbersList);
        serial_numbersList = NULL;
    }
    return NULL;

}
