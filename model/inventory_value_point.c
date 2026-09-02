#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inventory_value_point.h"



static inventory_value_point_t *inventory_value_point_create_internal(
    long *product_count,
    char *recorded_at,
    char *total_purchase_value,
    char *total_sales_value
    ) {
    inventory_value_point_t *inventory_value_point_local_var = malloc(sizeof(inventory_value_point_t));
    if (!inventory_value_point_local_var) {
        return NULL;
    }
    memset(inventory_value_point_local_var, 0, sizeof(inventory_value_point_t));
    inventory_value_point_local_var->_library_owned = 1;
    inventory_value_point_local_var->product_count = product_count;
    inventory_value_point_local_var->recorded_at = recorded_at;
    inventory_value_point_local_var->total_purchase_value = total_purchase_value;
    inventory_value_point_local_var->total_sales_value = total_sales_value;
    return inventory_value_point_local_var;
}

__attribute__((deprecated)) inventory_value_point_t *inventory_value_point_create(
    long *product_count,
    char *recorded_at,
    char *total_purchase_value,
    char *total_sales_value
    ) {
    long *product_count_copy = NULL;
    if (product_count) {
        product_count_copy = malloc(sizeof(long));
        if (product_count_copy) *product_count_copy = *product_count;
    }
    inventory_value_point_t *result = inventory_value_point_create_internal (
        product_count_copy,
        recorded_at,
        total_purchase_value,
        total_sales_value
        );
    if (!result) {
        free(product_count_copy);
    }
    return result;
}

void inventory_value_point_free(inventory_value_point_t *inventory_value_point) {
    if(NULL == inventory_value_point){
        return ;
    }
    if(inventory_value_point->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inventory_value_point_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inventory_value_point->product_count) {
        free(inventory_value_point->product_count);
        inventory_value_point->product_count = NULL;
    }
    if (inventory_value_point->recorded_at) {
        free(inventory_value_point->recorded_at);
        inventory_value_point->recorded_at = NULL;
    }
    if (inventory_value_point->total_purchase_value) {
        free(inventory_value_point->total_purchase_value);
        inventory_value_point->total_purchase_value = NULL;
    }
    if (inventory_value_point->total_sales_value) {
        free(inventory_value_point->total_sales_value);
        inventory_value_point->total_sales_value = NULL;
    }
    free(inventory_value_point);
}

cJSON *inventory_value_point_convertToJSON(inventory_value_point_t *inventory_value_point) {
    cJSON *item = cJSON_CreateObject();

    // inventory_value_point->product_count
    if (!inventory_value_point->product_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "product_count", *inventory_value_point->product_count) == NULL) {
    goto fail; //Numeric
    }


    // inventory_value_point->recorded_at
    if (!inventory_value_point->recorded_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "recorded_at", inventory_value_point->recorded_at) == NULL) {
    goto fail; //Date-Time
    }


    // inventory_value_point->total_purchase_value
    if (!inventory_value_point->total_purchase_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_purchase_value", inventory_value_point->total_purchase_value) == NULL) {
    goto fail; //String
    }


    // inventory_value_point->total_sales_value
    if (!inventory_value_point->total_sales_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_sales_value", inventory_value_point->total_sales_value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

inventory_value_point_t *inventory_value_point_parseFromJSON(cJSON *inventory_value_pointJSON){

    inventory_value_point_t *inventory_value_point_local_var = NULL;

    // define the local variable for inventory_value_point->product_count
    long *product_count_local_var = NULL;

    char *recorded_at_local_str = NULL;

    char *total_purchase_value_local_str = NULL;

    char *total_sales_value_local_str = NULL;

    // inventory_value_point->product_count
    cJSON *product_count = cJSON_GetObjectItemCaseSensitive(inventory_value_pointJSON, "product_count");
    if (cJSON_IsNull(product_count)) {
        product_count = NULL;
    }
    if (!product_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(product_count))
    {
    goto end; //Numeric
    }
    product_count_local_var = malloc(sizeof(long));
    if(!product_count_local_var)
    {
        goto end;
    }
    *product_count_local_var = product_count->valuedouble;

    // inventory_value_point->recorded_at
    cJSON *recorded_at = cJSON_GetObjectItemCaseSensitive(inventory_value_pointJSON, "recorded_at");
    if (cJSON_IsNull(recorded_at)) {
        recorded_at = NULL;
    }
    if (!recorded_at) {
        goto end;
    }

    
    if(!cJSON_IsString(recorded_at) && !cJSON_IsNull(recorded_at))
    {
    goto end; //DateTime
    }

    // inventory_value_point->total_purchase_value
    cJSON *total_purchase_value = cJSON_GetObjectItemCaseSensitive(inventory_value_pointJSON, "total_purchase_value");
    if (cJSON_IsNull(total_purchase_value)) {
        total_purchase_value = NULL;
    }
    if (!total_purchase_value) {
        goto end;
    }

    
    if(!cJSON_IsString(total_purchase_value))
    {
    goto end; //String
    }

    // inventory_value_point->total_sales_value
    cJSON *total_sales_value = cJSON_GetObjectItemCaseSensitive(inventory_value_pointJSON, "total_sales_value");
    if (cJSON_IsNull(total_sales_value)) {
        total_sales_value = NULL;
    }
    if (!total_sales_value) {
        goto end;
    }

    
    if(!cJSON_IsString(total_sales_value))
    {
    goto end; //String
    }


    if (recorded_at && !cJSON_IsNull(recorded_at)) recorded_at_local_str = strdup(recorded_at->valuestring);
    if (total_purchase_value && !cJSON_IsNull(total_purchase_value)) total_purchase_value_local_str = strdup(total_purchase_value->valuestring);
    if (total_sales_value && !cJSON_IsNull(total_sales_value)) total_sales_value_local_str = strdup(total_sales_value->valuestring);

    inventory_value_point_local_var = inventory_value_point_create_internal (
        product_count_local_var,
        recorded_at_local_str,
        total_purchase_value_local_str,
        total_sales_value_local_str
        );

    if (!inventory_value_point_local_var) {
        goto end;
    }

    return inventory_value_point_local_var;
end:
    if (product_count_local_var) {
        free(product_count_local_var);
        product_count_local_var = NULL;
    }
    if (recorded_at_local_str) {
        free(recorded_at_local_str);
        recorded_at_local_str = NULL;
    }
    if (total_purchase_value_local_str) {
        free(total_purchase_value_local_str);
        total_purchase_value_local_str = NULL;
    }
    if (total_sales_value_local_str) {
        free(total_sales_value_local_str);
        total_sales_value_local_str = NULL;
    }
    return NULL;

}
