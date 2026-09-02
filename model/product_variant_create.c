#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "product_variant_create.h"



static product_variant_create_t *product_variant_create_create_internal(
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
    product_variant_create_t *product_variant_create_local_var = malloc(sizeof(product_variant_create_t));
    if (!product_variant_create_local_var) {
        return NULL;
    }
    memset(product_variant_create_local_var, 0, sizeof(product_variant_create_t));
    product_variant_create_local_var->_library_owned = 1;
    product_variant_create_local_var->barcode = barcode;
    product_variant_create_local_var->image_link = image_link;
    product_variant_create_local_var->is_active = is_active;
    product_variant_create_local_var->name = name;
    product_variant_create_local_var->option_values = option_values;
    product_variant_create_local_var->price = price;
    product_variant_create_local_var->price_delta = price_delta;
    product_variant_create_local_var->product_id = product_id;
    product_variant_create_local_var->sku = sku;
    product_variant_create_local_var->stock_quantity = stock_quantity;
    return product_variant_create_local_var;
}

__attribute__((deprecated)) product_variant_create_t *product_variant_create_create(
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
    product_variant_create_t *result = product_variant_create_create_internal (
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

void product_variant_create_free(product_variant_create_t *product_variant_create) {
    if(NULL == product_variant_create){
        return ;
    }
    if(product_variant_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "product_variant_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (product_variant_create->barcode) {
        free(product_variant_create->barcode);
        product_variant_create->barcode = NULL;
    }
    if (product_variant_create->image_link) {
        free(product_variant_create->image_link);
        product_variant_create->image_link = NULL;
    }
    if (product_variant_create->is_active) {
        free(product_variant_create->is_active);
        product_variant_create->is_active = NULL;
    }
    if (product_variant_create->name) {
        free(product_variant_create->name);
        product_variant_create->name = NULL;
    }
    if (product_variant_create->option_values) {
        _free(product_variant_create->option_values);
        product_variant_create->option_values = NULL;
    }
    if (product_variant_create->price) {
        free(product_variant_create->price);
        product_variant_create->price = NULL;
    }
    if (product_variant_create->price_delta) {
        free(product_variant_create->price_delta);
        product_variant_create->price_delta = NULL;
    }
    if (product_variant_create->product_id) {
        free(product_variant_create->product_id);
        product_variant_create->product_id = NULL;
    }
    if (product_variant_create->sku) {
        free(product_variant_create->sku);
        product_variant_create->sku = NULL;
    }
    if (product_variant_create->stock_quantity) {
        free(product_variant_create->stock_quantity);
        product_variant_create->stock_quantity = NULL;
    }
    free(product_variant_create);
}

cJSON *product_variant_create_convertToJSON(product_variant_create_t *product_variant_create) {
    cJSON *item = cJSON_CreateObject();

    // product_variant_create->barcode
    if(product_variant_create->barcode) {
    if(cJSON_AddStringToObject(item, "barcode", product_variant_create->barcode) == NULL) {
    goto fail; //String
    }
    }


    // product_variant_create->image_link
    if(product_variant_create->image_link) {
    if(cJSON_AddStringToObject(item, "imageLink", product_variant_create->image_link) == NULL) {
    goto fail; //String
    }
    }


    // product_variant_create->is_active
    if(product_variant_create->is_active) {
    if(cJSON_AddBoolToObject(item, "isActive", *product_variant_create->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // product_variant_create->name
    if(product_variant_create->name) {
    if(cJSON_AddStringToObject(item, "name", product_variant_create->name) == NULL) {
    goto fail; //String
    }
    }


    // product_variant_create->option_values
    if(product_variant_create->option_values) {
    cJSON *option_values_local_JSON = _convertToJSON(product_variant_create->option_values);
    if(option_values_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "optionValues", option_values_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // product_variant_create->price
    if(product_variant_create->price) {
    if(cJSON_AddStringToObject(item, "price", product_variant_create->price) == NULL) {
    goto fail; //String
    }
    }


    // product_variant_create->price_delta
    if(product_variant_create->price_delta) {
    if(cJSON_AddStringToObject(item, "priceDelta", product_variant_create->price_delta) == NULL) {
    goto fail; //String
    }
    }


    // product_variant_create->product_id
    if (!product_variant_create->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", product_variant_create->product_id) == NULL) {
    goto fail; //String
    }


    // product_variant_create->sku
    if (!product_variant_create->sku) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sku", product_variant_create->sku) == NULL) {
    goto fail; //String
    }


    // product_variant_create->stock_quantity
    if(product_variant_create->stock_quantity) {
    if(cJSON_AddNumberToObject(item, "stockQuantity", *product_variant_create->stock_quantity) == NULL) {
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

product_variant_create_t *product_variant_create_parseFromJSON(cJSON *product_variant_createJSON){

    product_variant_create_t *product_variant_create_local_var = NULL;

    char *barcode_local_str = NULL;

    char *image_link_local_str = NULL;

    // define the local variable for product_variant_create->is_active
    int *is_active_local_var = NULL;

    char *name_local_str = NULL;

    // define the local variable for product_variant_create->option_values
    _t *option_values_local_nonprim = NULL;

    char *price_local_str = NULL;

    char *price_delta_local_str = NULL;

    char *product_id_local_str = NULL;

    char *sku_local_str = NULL;

    // define the local variable for product_variant_create->stock_quantity
    long *stock_quantity_local_var = NULL;

    // product_variant_create->barcode
    cJSON *barcode = cJSON_GetObjectItemCaseSensitive(product_variant_createJSON, "barcode");
    if (cJSON_IsNull(barcode)) {
        barcode = NULL;
    }
    if (barcode) { 
    if(!cJSON_IsString(barcode) && !cJSON_IsNull(barcode))
    {
    goto end; //String
    }
    }

    // product_variant_create->image_link
    cJSON *image_link = cJSON_GetObjectItemCaseSensitive(product_variant_createJSON, "imageLink");
    if (cJSON_IsNull(image_link)) {
        image_link = NULL;
    }
    if (image_link) { 
    if(!cJSON_IsString(image_link) && !cJSON_IsNull(image_link))
    {
    goto end; //String
    }
    }

    // product_variant_create->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(product_variant_createJSON, "isActive");
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

    // product_variant_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(product_variant_createJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // product_variant_create->option_values
    cJSON *option_values = cJSON_GetObjectItemCaseSensitive(product_variant_createJSON, "optionValues");
    if (cJSON_IsNull(option_values)) {
        option_values = NULL;
    }
    if (option_values) { 
    option_values_local_nonprim = _parseFromJSON(option_values); //custom
    }

    // product_variant_create->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(product_variant_createJSON, "price");
    if (cJSON_IsNull(price)) {
        price = NULL;
    }
    if (price) { 
    if(!cJSON_IsString(price) && !cJSON_IsNull(price))
    {
    goto end; //String
    }
    }

    // product_variant_create->price_delta
    cJSON *price_delta = cJSON_GetObjectItemCaseSensitive(product_variant_createJSON, "priceDelta");
    if (cJSON_IsNull(price_delta)) {
        price_delta = NULL;
    }
    if (price_delta) { 
    if(!cJSON_IsString(price_delta) && !cJSON_IsNull(price_delta))
    {
    goto end; //String
    }
    }

    // product_variant_create->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(product_variant_createJSON, "productId");
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

    // product_variant_create->sku
    cJSON *sku = cJSON_GetObjectItemCaseSensitive(product_variant_createJSON, "sku");
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

    // product_variant_create->stock_quantity
    cJSON *stock_quantity = cJSON_GetObjectItemCaseSensitive(product_variant_createJSON, "stockQuantity");
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

    product_variant_create_local_var = product_variant_create_create_internal (
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

    if (!product_variant_create_local_var) {
        goto end;
    }

    return product_variant_create_local_var;
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
