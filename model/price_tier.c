#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "price_tier.h"



static price_tier_t *price_tier_create_internal(
    char *customer_group_id,
    long *min_quantity,
    char *product_id,
    char *unit_price
    ) {
    price_tier_t *price_tier_local_var = malloc(sizeof(price_tier_t));
    if (!price_tier_local_var) {
        return NULL;
    }
    memset(price_tier_local_var, 0, sizeof(price_tier_t));
    price_tier_local_var->_library_owned = 1;
    price_tier_local_var->customer_group_id = customer_group_id;
    price_tier_local_var->min_quantity = min_quantity;
    price_tier_local_var->product_id = product_id;
    price_tier_local_var->unit_price = unit_price;
    return price_tier_local_var;
}

__attribute__((deprecated)) price_tier_t *price_tier_create(
    char *customer_group_id,
    long *min_quantity,
    char *product_id,
    char *unit_price
    ) {
    long *min_quantity_copy = NULL;
    if (min_quantity) {
        min_quantity_copy = malloc(sizeof(long));
        if (min_quantity_copy) *min_quantity_copy = *min_quantity;
    }
    price_tier_t *result = price_tier_create_internal (
        customer_group_id,
        min_quantity_copy,
        product_id,
        unit_price
        );
    if (!result) {
        free(min_quantity_copy);
    }
    return result;
}

void price_tier_free(price_tier_t *price_tier) {
    if(NULL == price_tier){
        return ;
    }
    if(price_tier->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "price_tier_free");
        return ;
    }
    listEntry_t *listEntry;
    if (price_tier->customer_group_id) {
        free(price_tier->customer_group_id);
        price_tier->customer_group_id = NULL;
    }
    if (price_tier->min_quantity) {
        free(price_tier->min_quantity);
        price_tier->min_quantity = NULL;
    }
    if (price_tier->product_id) {
        free(price_tier->product_id);
        price_tier->product_id = NULL;
    }
    if (price_tier->unit_price) {
        free(price_tier->unit_price);
        price_tier->unit_price = NULL;
    }
    free(price_tier);
}

cJSON *price_tier_convertToJSON(price_tier_t *price_tier) {
    cJSON *item = cJSON_CreateObject();

    // price_tier->customer_group_id
    if(price_tier->customer_group_id) {
    if(cJSON_AddStringToObject(item, "customerGroupId", price_tier->customer_group_id) == NULL) {
    goto fail; //String
    }
    }


    // price_tier->min_quantity
    if(price_tier->min_quantity) {
    if(cJSON_AddNumberToObject(item, "minQuantity", *price_tier->min_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // price_tier->product_id
    if (!price_tier->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", price_tier->product_id) == NULL) {
    goto fail; //String
    }


    // price_tier->unit_price
    if (!price_tier->unit_price) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "unitPrice", price_tier->unit_price) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

price_tier_t *price_tier_parseFromJSON(cJSON *price_tierJSON){

    price_tier_t *price_tier_local_var = NULL;

    char *customer_group_id_local_str = NULL;

    // define the local variable for price_tier->min_quantity
    long *min_quantity_local_var = NULL;

    char *product_id_local_str = NULL;

    char *unit_price_local_str = NULL;

    // price_tier->customer_group_id
    cJSON *customer_group_id = cJSON_GetObjectItemCaseSensitive(price_tierJSON, "customerGroupId");
    if (cJSON_IsNull(customer_group_id)) {
        customer_group_id = NULL;
    }
    if (customer_group_id) { 
    if(!cJSON_IsString(customer_group_id) && !cJSON_IsNull(customer_group_id))
    {
    goto end; //String
    }
    }

    // price_tier->min_quantity
    cJSON *min_quantity = cJSON_GetObjectItemCaseSensitive(price_tierJSON, "minQuantity");
    if (cJSON_IsNull(min_quantity)) {
        min_quantity = NULL;
    }
    if (min_quantity) { 
    if(!cJSON_IsNumber(min_quantity))
    {
    goto end; //Numeric
    }
    min_quantity_local_var = malloc(sizeof(long));
    if(!min_quantity_local_var)
    {
        goto end;
    }
    *min_quantity_local_var = min_quantity->valuedouble;
    }

    // price_tier->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(price_tierJSON, "productId");
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

    // price_tier->unit_price
    cJSON *unit_price = cJSON_GetObjectItemCaseSensitive(price_tierJSON, "unitPrice");
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


    if (customer_group_id && !cJSON_IsNull(customer_group_id)) customer_group_id_local_str = strdup(customer_group_id->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (unit_price && !cJSON_IsNull(unit_price)) unit_price_local_str = strdup(unit_price->valuestring);

    price_tier_local_var = price_tier_create_internal (
        customer_group_id_local_str,
        min_quantity_local_var,
        product_id_local_str,
        unit_price_local_str
        );

    if (!price_tier_local_var) {
        goto end;
    }

    return price_tier_local_var;
end:
    if (customer_group_id_local_str) {
        free(customer_group_id_local_str);
        customer_group_id_local_str = NULL;
    }
    if (min_quantity_local_var) {
        free(min_quantity_local_var);
        min_quantity_local_var = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (unit_price_local_str) {
        free(unit_price_local_str);
        unit_price_local_str = NULL;
    }
    return NULL;

}
