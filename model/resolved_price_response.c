#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "resolved_price_response.h"



static resolved_price_response_t *resolved_price_response_create_internal(
    int *is_list_price,
    char *price_tier_id,
    char *product_id,
    long *quantity,
    char *unit_price
    ) {
    resolved_price_response_t *resolved_price_response_local_var = malloc(sizeof(resolved_price_response_t));
    if (!resolved_price_response_local_var) {
        return NULL;
    }
    memset(resolved_price_response_local_var, 0, sizeof(resolved_price_response_t));
    resolved_price_response_local_var->_library_owned = 1;
    resolved_price_response_local_var->is_list_price = is_list_price;
    resolved_price_response_local_var->price_tier_id = price_tier_id;
    resolved_price_response_local_var->product_id = product_id;
    resolved_price_response_local_var->quantity = quantity;
    resolved_price_response_local_var->unit_price = unit_price;
    return resolved_price_response_local_var;
}

__attribute__((deprecated)) resolved_price_response_t *resolved_price_response_create(
    int *is_list_price,
    char *price_tier_id,
    char *product_id,
    long *quantity,
    char *unit_price
    ) {
    int *is_list_price_copy = NULL;
    if (is_list_price) {
        is_list_price_copy = malloc(sizeof(int));
        if (is_list_price_copy) *is_list_price_copy = *is_list_price;
    }
    long *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(long));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    resolved_price_response_t *result = resolved_price_response_create_internal (
        is_list_price_copy,
        price_tier_id,
        product_id,
        quantity_copy,
        unit_price
        );
    if (!result) {
        free(is_list_price_copy);
        free(quantity_copy);
    }
    return result;
}

void resolved_price_response_free(resolved_price_response_t *resolved_price_response) {
    if(NULL == resolved_price_response){
        return ;
    }
    if(resolved_price_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "resolved_price_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (resolved_price_response->is_list_price) {
        free(resolved_price_response->is_list_price);
        resolved_price_response->is_list_price = NULL;
    }
    if (resolved_price_response->price_tier_id) {
        free(resolved_price_response->price_tier_id);
        resolved_price_response->price_tier_id = NULL;
    }
    if (resolved_price_response->product_id) {
        free(resolved_price_response->product_id);
        resolved_price_response->product_id = NULL;
    }
    if (resolved_price_response->quantity) {
        free(resolved_price_response->quantity);
        resolved_price_response->quantity = NULL;
    }
    if (resolved_price_response->unit_price) {
        free(resolved_price_response->unit_price);
        resolved_price_response->unit_price = NULL;
    }
    free(resolved_price_response);
}

cJSON *resolved_price_response_convertToJSON(resolved_price_response_t *resolved_price_response) {
    cJSON *item = cJSON_CreateObject();

    // resolved_price_response->is_list_price
    if (!resolved_price_response->is_list_price) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "isListPrice", *resolved_price_response->is_list_price) == NULL) {
    goto fail; //Bool
    }


    // resolved_price_response->price_tier_id
    if(resolved_price_response->price_tier_id) {
    if(cJSON_AddStringToObject(item, "priceTierId", resolved_price_response->price_tier_id) == NULL) {
    goto fail; //String
    }
    }


    // resolved_price_response->product_id
    if (!resolved_price_response->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", resolved_price_response->product_id) == NULL) {
    goto fail; //String
    }


    // resolved_price_response->quantity
    if (!resolved_price_response->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *resolved_price_response->quantity) == NULL) {
    goto fail; //Numeric
    }


    // resolved_price_response->unit_price
    if (!resolved_price_response->unit_price) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "unitPrice", resolved_price_response->unit_price) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

resolved_price_response_t *resolved_price_response_parseFromJSON(cJSON *resolved_price_responseJSON){

    resolved_price_response_t *resolved_price_response_local_var = NULL;

    // define the local variable for resolved_price_response->is_list_price
    int *is_list_price_local_var = NULL;

    char *price_tier_id_local_str = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for resolved_price_response->quantity
    long *quantity_local_var = NULL;

    char *unit_price_local_str = NULL;

    // resolved_price_response->is_list_price
    cJSON *is_list_price = cJSON_GetObjectItemCaseSensitive(resolved_price_responseJSON, "isListPrice");
    if (cJSON_IsNull(is_list_price)) {
        is_list_price = NULL;
    }
    if (!is_list_price) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_list_price))
    {
    goto end; //Bool
    }
    is_list_price_local_var = malloc(sizeof(int));
    if(!is_list_price_local_var)
    {
        goto end;
    }
    *is_list_price_local_var = is_list_price->valueint;

    // resolved_price_response->price_tier_id
    cJSON *price_tier_id = cJSON_GetObjectItemCaseSensitive(resolved_price_responseJSON, "priceTierId");
    if (cJSON_IsNull(price_tier_id)) {
        price_tier_id = NULL;
    }
    if (price_tier_id) { 
    if(!cJSON_IsString(price_tier_id) && !cJSON_IsNull(price_tier_id))
    {
    goto end; //String
    }
    }

    // resolved_price_response->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(resolved_price_responseJSON, "productId");
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

    // resolved_price_response->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(resolved_price_responseJSON, "quantity");
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

    // resolved_price_response->unit_price
    cJSON *unit_price = cJSON_GetObjectItemCaseSensitive(resolved_price_responseJSON, "unitPrice");
    if (cJSON_IsNull(unit_price)) {
        unit_price = NULL;
    }
    if (!unit_price) {
        goto end;
    }

    
    if(!cJSON_IsString(unit_price))
    {
    goto end; //String
    }


    if (price_tier_id && !cJSON_IsNull(price_tier_id)) price_tier_id_local_str = strdup(price_tier_id->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (unit_price && !cJSON_IsNull(unit_price)) unit_price_local_str = strdup(unit_price->valuestring);

    resolved_price_response_local_var = resolved_price_response_create_internal (
        is_list_price_local_var,
        price_tier_id_local_str,
        product_id_local_str,
        quantity_local_var,
        unit_price_local_str
        );

    if (!resolved_price_response_local_var) {
        goto end;
    }

    return resolved_price_response_local_var;
end:
    if (is_list_price_local_var) {
        free(is_list_price_local_var);
        is_list_price_local_var = NULL;
    }
    if (price_tier_id_local_str) {
        free(price_tier_id_local_str);
        price_tier_id_local_str = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (unit_price_local_str) {
        free(unit_price_local_str);
        unit_price_local_str = NULL;
    }
    return NULL;

}
