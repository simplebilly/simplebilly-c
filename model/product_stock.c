#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "product_stock.h"



static product_stock_t *product_stock_create_internal(
    char *name,
    char *product_id,
    char *sku,
    long *stock_quantity
    ) {
    product_stock_t *product_stock_local_var = malloc(sizeof(product_stock_t));
    if (!product_stock_local_var) {
        return NULL;
    }
    memset(product_stock_local_var, 0, sizeof(product_stock_t));
    product_stock_local_var->_library_owned = 1;
    product_stock_local_var->name = name;
    product_stock_local_var->product_id = product_id;
    product_stock_local_var->sku = sku;
    product_stock_local_var->stock_quantity = stock_quantity;
    return product_stock_local_var;
}

__attribute__((deprecated)) product_stock_t *product_stock_create(
    char *name,
    char *product_id,
    char *sku,
    long *stock_quantity
    ) {
    long *stock_quantity_copy = NULL;
    if (stock_quantity) {
        stock_quantity_copy = malloc(sizeof(long));
        if (stock_quantity_copy) *stock_quantity_copy = *stock_quantity;
    }
    product_stock_t *result = product_stock_create_internal (
        name,
        product_id,
        sku,
        stock_quantity_copy
        );
    if (!result) {
        free(stock_quantity_copy);
    }
    return result;
}

void product_stock_free(product_stock_t *product_stock) {
    if(NULL == product_stock){
        return ;
    }
    if(product_stock->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "product_stock_free");
        return ;
    }
    listEntry_t *listEntry;
    if (product_stock->name) {
        free(product_stock->name);
        product_stock->name = NULL;
    }
    if (product_stock->product_id) {
        free(product_stock->product_id);
        product_stock->product_id = NULL;
    }
    if (product_stock->sku) {
        free(product_stock->sku);
        product_stock->sku = NULL;
    }
    if (product_stock->stock_quantity) {
        free(product_stock->stock_quantity);
        product_stock->stock_quantity = NULL;
    }
    free(product_stock);
}

cJSON *product_stock_convertToJSON(product_stock_t *product_stock) {
    cJSON *item = cJSON_CreateObject();

    // product_stock->name
    if (!product_stock->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", product_stock->name) == NULL) {
    goto fail; //String
    }


    // product_stock->product_id
    if (!product_stock->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "product_id", product_stock->product_id) == NULL) {
    goto fail; //String
    }


    // product_stock->sku
    if (!product_stock->sku) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sku", product_stock->sku) == NULL) {
    goto fail; //String
    }


    // product_stock->stock_quantity
    if(product_stock->stock_quantity) {
    if(cJSON_AddNumberToObject(item, "stock_quantity", *product_stock->stock_quantity) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

product_stock_t *product_stock_parseFromJSON(cJSON *product_stockJSON){

    product_stock_t *product_stock_local_var = NULL;

    char *name_local_str = NULL;

    char *product_id_local_str = NULL;

    char *sku_local_str = NULL;

    // define the local variable for product_stock->stock_quantity
    long *stock_quantity_local_var = NULL;

    // product_stock->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(product_stockJSON, "name");
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

    // product_stock->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(product_stockJSON, "product_id");
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

    // product_stock->sku
    cJSON *sku = cJSON_GetObjectItemCaseSensitive(product_stockJSON, "sku");
    if (cJSON_IsNull(sku)) {
        sku = NULL;
    }
    if (!sku) {
        goto end;
    }

    
    if(!cJSON_IsString(sku))
    {
    goto end; //String
    }

    // product_stock->stock_quantity
    cJSON *stock_quantity = cJSON_GetObjectItemCaseSensitive(product_stockJSON, "stock_quantity");
    if (cJSON_IsNull(stock_quantity)) {
        stock_quantity = NULL;
    }
    if (stock_quantity) { 
    if(!cJSON_IsNumber(stock_quantity))
    {
    goto end; //Numeric
    }
    stock_quantity_local_var = malloc(sizeof(long));
    if(!stock_quantity_local_var)
    {
        goto end;
    }
    *stock_quantity_local_var = stock_quantity->valuedouble;
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (sku && !cJSON_IsNull(sku)) sku_local_str = strdup(sku->valuestring);

    product_stock_local_var = product_stock_create_internal (
        name_local_str,
        product_id_local_str,
        sku_local_str,
        stock_quantity_local_var
        );

    if (!product_stock_local_var) {
        goto end;
    }

    return product_stock_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (sku_local_str) {
        free(sku_local_str);
        sku_local_str = NULL;
    }
    if (stock_quantity_local_var) {
        free(stock_quantity_local_var);
        stock_quantity_local_var = NULL;
    }
    return NULL;

}
