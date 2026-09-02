#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "product_variant_update.h"



static product_variant_update_t *product_variant_update_create_internal(
    char *barcode,
    char *image_link,
    int *is_active,
    char *name,
    any_type_t *option_values,
    char *price,
    char *price_delta,
    char *product_id,
    char *sku,
    long *stock_quantity
    ) {
    product_variant_update_t *product_variant_update_local_var = malloc(sizeof(product_variant_update_t));
    if (!product_variant_update_local_var) {
        return NULL;
    }
    memset(product_variant_update_local_var, 0, sizeof(product_variant_update_t));
    product_variant_update_local_var->_library_owned = 1;
    product_variant_update_local_var->barcode = barcode;
    product_variant_update_local_var->image_link = image_link;
    product_variant_update_local_var->is_active = is_active;
    product_variant_update_local_var->name = name;
    product_variant_update_local_var->option_values = option_values;
    product_variant_update_local_var->price = price;
    product_variant_update_local_var->price_delta = price_delta;
    product_variant_update_local_var->product_id = product_id;
    product_variant_update_local_var->sku = sku;
    product_variant_update_local_var->stock_quantity = stock_quantity;
    return product_variant_update_local_var;
}

__attribute__((deprecated)) product_variant_update_t *product_variant_update_create(
    char *barcode,
    char *image_link,
    int *is_active,
    char *name,
    any_type_t *option_values,
    char *price,
    char *price_delta,
    char *product_id,
    char *sku,
    long *stock_quantity
    ) {
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    long *stock_quantity_copy = NULL;
    if (stock_quantity) {
        stock_quantity_copy = malloc(sizeof(long));
        if (stock_quantity_copy) *stock_quantity_copy = *stock_quantity;
    }
    product_variant_update_t *result = product_variant_update_create_internal (
        barcode,
        image_link,
        is_active_copy,
        name,
        option_values,
        price,
        price_delta,
        product_id,
        sku,
        stock_quantity_copy
        );
    if (!result) {
        free(is_active_copy);
        free(stock_quantity_copy);
    }
    return result;
}

void product_variant_update_free(product_variant_update_t *product_variant_update) {
    if(NULL == product_variant_update){
        return ;
    }
    if(product_variant_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "product_variant_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (product_variant_update->barcode) {
        free(product_variant_update->barcode);
        product_variant_update->barcode = NULL;
    }
    if (product_variant_update->image_link) {
        free(product_variant_update->image_link);
        product_variant_update->image_link = NULL;
    }
    if (product_variant_update->is_active) {
        free(product_variant_update->is_active);
        product_variant_update->is_active = NULL;
    }
    if (product_variant_update->name) {
        free(product_variant_update->name);
        product_variant_update->name = NULL;
    }
    if (product_variant_update->option_values) {
        _free(product_variant_update->option_values);
        product_variant_update->option_values = NULL;
    }
    if (product_variant_update->price) {
        free(product_variant_update->price);
        product_variant_update->price = NULL;
    }
    if (product_variant_update->price_delta) {
        free(product_variant_update->price_delta);
        product_variant_update->price_delta = NULL;
    }
    if (product_variant_update->product_id) {
        free(product_variant_update->product_id);
        product_variant_update->product_id = NULL;
    }
    if (product_variant_update->sku) {
        free(product_variant_update->sku);
        product_variant_update->sku = NULL;
    }
    if (product_variant_update->stock_quantity) {
        free(product_variant_update->stock_quantity);
        product_variant_update->stock_quantity = NULL;
    }
    free(product_variant_update);
}

cJSON *product_variant_update_convertToJSON(product_variant_update_t *product_variant_update) {
    cJSON *item = cJSON_CreateObject();

    // product_variant_update->barcode
    if(product_variant_update->barcode) {
    if(cJSON_AddStringToObject(item, "barcode", product_variant_update->barcode) == NULL) {
    goto fail; //String
    }
    }


    // product_variant_update->image_link
    if(product_variant_update->image_link) {
    if(cJSON_AddStringToObject(item, "imageLink", product_variant_update->image_link) == NULL) {
    goto fail; //String
    }
    }


    // product_variant_update->is_active
    if(product_variant_update->is_active) {
    if(cJSON_AddBoolToObject(item, "isActive", *product_variant_update->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // product_variant_update->name
    if(product_variant_update->name) {
    if(cJSON_AddStringToObject(item, "name", product_variant_update->name) == NULL) {
    goto fail; //String
    }
    }


    // product_variant_update->option_values
    if(product_variant_update->option_values) {
    cJSON *option_values_local_JSON = _convertToJSON(product_variant_update->option_values);
    if(option_values_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "optionValues", option_values_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // product_variant_update->price
    if(product_variant_update->price) {
    if(cJSON_AddStringToObject(item, "price", product_variant_update->price) == NULL) {
    goto fail; //String
    }
    }


    // product_variant_update->price_delta
    if(product_variant_update->price_delta) {
    if(cJSON_AddStringToObject(item, "priceDelta", product_variant_update->price_delta) == NULL) {
    goto fail; //String
    }
    }


    // product_variant_update->product_id
    if(product_variant_update->product_id) {
    if(cJSON_AddStringToObject(item, "productId", product_variant_update->product_id) == NULL) {
    goto fail; //String
    }
    }


    // product_variant_update->sku
    if(product_variant_update->sku) {
    if(cJSON_AddStringToObject(item, "sku", product_variant_update->sku) == NULL) {
    goto fail; //String
    }
    }


    // product_variant_update->stock_quantity
    if(product_variant_update->stock_quantity) {
    if(cJSON_AddNumberToObject(item, "stockQuantity", *product_variant_update->stock_quantity) == NULL) {
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

product_variant_update_t *product_variant_update_parseFromJSON(cJSON *product_variant_updateJSON){

    product_variant_update_t *product_variant_update_local_var = NULL;

    char *barcode_local_str = NULL;

    char *image_link_local_str = NULL;

    // define the local variable for product_variant_update->is_active
    int *is_active_local_var = NULL;

    char *name_local_str = NULL;

    // define the local variable for product_variant_update->option_values
    _t *option_values_local_nonprim = NULL;

    char *price_local_str = NULL;

    char *price_delta_local_str = NULL;

    char *product_id_local_str = NULL;

    char *sku_local_str = NULL;

    // define the local variable for product_variant_update->stock_quantity
    long *stock_quantity_local_var = NULL;

    // product_variant_update->barcode
    cJSON *barcode = cJSON_GetObjectItemCaseSensitive(product_variant_updateJSON, "barcode");
    if (cJSON_IsNull(barcode)) {
        barcode = NULL;
    }
    if (barcode) { 
    if(!cJSON_IsString(barcode) && !cJSON_IsNull(barcode))
    {
    goto end; //String
    }
    }

    // product_variant_update->image_link
    cJSON *image_link = cJSON_GetObjectItemCaseSensitive(product_variant_updateJSON, "imageLink");
    if (cJSON_IsNull(image_link)) {
        image_link = NULL;
    }
    if (image_link) { 
    if(!cJSON_IsString(image_link) && !cJSON_IsNull(image_link))
    {
    goto end; //String
    }
    }

    // product_variant_update->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(product_variant_updateJSON, "isActive");
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

    // product_variant_update->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(product_variant_updateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // product_variant_update->option_values
    cJSON *option_values = cJSON_GetObjectItemCaseSensitive(product_variant_updateJSON, "optionValues");
    if (cJSON_IsNull(option_values)) {
        option_values = NULL;
    }
    if (option_values) { 
    option_values_local_nonprim = _parseFromJSON(option_values); //custom
    }

    // product_variant_update->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(product_variant_updateJSON, "price");
    if (cJSON_IsNull(price)) {
        price = NULL;
    }
    if (price) { 
    if(!cJSON_IsString(price) && !cJSON_IsNull(price))
    {
    goto end; //String
    }
    }

    // product_variant_update->price_delta
    cJSON *price_delta = cJSON_GetObjectItemCaseSensitive(product_variant_updateJSON, "priceDelta");
    if (cJSON_IsNull(price_delta)) {
        price_delta = NULL;
    }
    if (price_delta) { 
    if(!cJSON_IsString(price_delta) && !cJSON_IsNull(price_delta))
    {
    goto end; //String
    }
    }

    // product_variant_update->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(product_variant_updateJSON, "productId");
    if (cJSON_IsNull(product_id)) {
        product_id = NULL;
    }
    if (product_id) { 
    if(!cJSON_IsString(product_id) && !cJSON_IsNull(product_id))
    {
    goto end; //String
    }
    }

    // product_variant_update->sku
    cJSON *sku = cJSON_GetObjectItemCaseSensitive(product_variant_updateJSON, "sku");
    if (cJSON_IsNull(sku)) {
        sku = NULL;
    }
    if (sku) { 
    if(!cJSON_IsString(sku) && !cJSON_IsNull(sku))
    {
    goto end; //String
    }
    }

    // product_variant_update->stock_quantity
    cJSON *stock_quantity = cJSON_GetObjectItemCaseSensitive(product_variant_updateJSON, "stockQuantity");
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


    if (barcode && !cJSON_IsNull(barcode)) barcode_local_str = strdup(barcode->valuestring);
    if (image_link && !cJSON_IsNull(image_link)) image_link_local_str = strdup(image_link->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (price && !cJSON_IsNull(price)) price_local_str = strdup(price->valuestring);
    if (price_delta && !cJSON_IsNull(price_delta)) price_delta_local_str = strdup(price_delta->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (sku && !cJSON_IsNull(sku)) sku_local_str = strdup(sku->valuestring);

    product_variant_update_local_var = product_variant_update_create_internal (
        barcode_local_str,
        image_link_local_str,
        is_active_local_var,
        name_local_str,
        option_values ? option_values_local_nonprim : NULL,
        price_local_str,
        price_delta_local_str,
        product_id_local_str,
        sku_local_str,
        stock_quantity_local_var
        );

    if (!product_variant_update_local_var) {
        goto end;
    }

    return product_variant_update_local_var;
end:
    if (barcode_local_str) {
        free(barcode_local_str);
        barcode_local_str = NULL;
    }
    if (image_link_local_str) {
        free(image_link_local_str);
        image_link_local_str = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (option_values_local_nonprim) {
        _free(option_values_local_nonprim);
        option_values_local_nonprim = NULL;
    }
    if (price_local_str) {
        free(price_local_str);
        price_local_str = NULL;
    }
    if (price_delta_local_str) {
        free(price_delta_local_str);
        price_delta_local_str = NULL;
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
