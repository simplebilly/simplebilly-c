#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "costing_line.h"



static costing_line_t *costing_line_create_internal(
    char *line_cost,
    char *name,
    char *product_id,
    long *quantity_per_unit,
    char *sku,
    long *total_quantity,
    char *unit_purchase_price
    ) {
    costing_line_t *costing_line_local_var = malloc(sizeof(costing_line_t));
    if (!costing_line_local_var) {
        return NULL;
    }
    memset(costing_line_local_var, 0, sizeof(costing_line_t));
    costing_line_local_var->_library_owned = 1;
    costing_line_local_var->line_cost = line_cost;
    costing_line_local_var->name = name;
    costing_line_local_var->product_id = product_id;
    costing_line_local_var->quantity_per_unit = quantity_per_unit;
    costing_line_local_var->sku = sku;
    costing_line_local_var->total_quantity = total_quantity;
    costing_line_local_var->unit_purchase_price = unit_purchase_price;
    return costing_line_local_var;
}

__attribute__((deprecated)) costing_line_t *costing_line_create(
    char *line_cost,
    char *name,
    char *product_id,
    long *quantity_per_unit,
    char *sku,
    long *total_quantity,
    char *unit_purchase_price
    ) {
    long *quantity_per_unit_copy = NULL;
    if (quantity_per_unit) {
        quantity_per_unit_copy = malloc(sizeof(long));
        if (quantity_per_unit_copy) *quantity_per_unit_copy = *quantity_per_unit;
    }
    long *total_quantity_copy = NULL;
    if (total_quantity) {
        total_quantity_copy = malloc(sizeof(long));
        if (total_quantity_copy) *total_quantity_copy = *total_quantity;
    }
    costing_line_t *result = costing_line_create_internal (
        line_cost,
        name,
        product_id,
        quantity_per_unit_copy,
        sku,
        total_quantity_copy,
        unit_purchase_price
        );
    if (!result) {
        free(quantity_per_unit_copy);
        free(total_quantity_copy);
    }
    return result;
}

void costing_line_free(costing_line_t *costing_line) {
    if(NULL == costing_line){
        return ;
    }
    if(costing_line->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "costing_line_free");
        return ;
    }
    listEntry_t *listEntry;
    if (costing_line->line_cost) {
        free(costing_line->line_cost);
        costing_line->line_cost = NULL;
    }
    if (costing_line->name) {
        free(costing_line->name);
        costing_line->name = NULL;
    }
    if (costing_line->product_id) {
        free(costing_line->product_id);
        costing_line->product_id = NULL;
    }
    if (costing_line->quantity_per_unit) {
        free(costing_line->quantity_per_unit);
        costing_line->quantity_per_unit = NULL;
    }
    if (costing_line->sku) {
        free(costing_line->sku);
        costing_line->sku = NULL;
    }
    if (costing_line->total_quantity) {
        free(costing_line->total_quantity);
        costing_line->total_quantity = NULL;
    }
    if (costing_line->unit_purchase_price) {
        free(costing_line->unit_purchase_price);
        costing_line->unit_purchase_price = NULL;
    }
    free(costing_line);
}

cJSON *costing_line_convertToJSON(costing_line_t *costing_line) {
    cJSON *item = cJSON_CreateObject();

    // costing_line->line_cost
    if (!costing_line->line_cost) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "lineCost", costing_line->line_cost) == NULL) {
    goto fail; //String
    }


    // costing_line->name
    if (!costing_line->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", costing_line->name) == NULL) {
    goto fail; //String
    }


    // costing_line->product_id
    if (!costing_line->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", costing_line->product_id) == NULL) {
    goto fail; //String
    }


    // costing_line->quantity_per_unit
    if (!costing_line->quantity_per_unit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantityPerUnit", *costing_line->quantity_per_unit) == NULL) {
    goto fail; //Numeric
    }


    // costing_line->sku
    if (!costing_line->sku) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sku", costing_line->sku) == NULL) {
    goto fail; //String
    }


    // costing_line->total_quantity
    if (!costing_line->total_quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "totalQuantity", *costing_line->total_quantity) == NULL) {
    goto fail; //Numeric
    }


    // costing_line->unit_purchase_price
    if(costing_line->unit_purchase_price) {
    if(cJSON_AddStringToObject(item, "unitPurchasePrice", costing_line->unit_purchase_price) == NULL) {
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

costing_line_t *costing_line_parseFromJSON(cJSON *costing_lineJSON){

    costing_line_t *costing_line_local_var = NULL;

    char *line_cost_local_str = NULL;

    char *name_local_str = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for costing_line->quantity_per_unit
    long *quantity_per_unit_local_var = NULL;

    char *sku_local_str = NULL;

    // define the local variable for costing_line->total_quantity
    long *total_quantity_local_var = NULL;

    char *unit_purchase_price_local_str = NULL;

    // costing_line->line_cost
    cJSON *line_cost = cJSON_GetObjectItemCaseSensitive(costing_lineJSON, "lineCost");
    if (cJSON_IsNull(line_cost)) {
        line_cost = NULL;
    }
    if (!line_cost) {
        goto end;
    }

    
    if(!cJSON_IsString(line_cost))
    {
    goto end; //String
    }

    // costing_line->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(costing_lineJSON, "name");
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

    // costing_line->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(costing_lineJSON, "productId");
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

    // costing_line->quantity_per_unit
    cJSON *quantity_per_unit = cJSON_GetObjectItemCaseSensitive(costing_lineJSON, "quantityPerUnit");
    if (cJSON_IsNull(quantity_per_unit)) {
        quantity_per_unit = NULL;
    }
    if (!quantity_per_unit) {
        goto end;
    }

    
    if(!cJSON_IsNumber(quantity_per_unit))
    {
    goto end; //Numeric
    }
    quantity_per_unit_local_var = malloc(sizeof(long));
    if(!quantity_per_unit_local_var)
    {
        goto end;
    }
    *quantity_per_unit_local_var = quantity_per_unit->valuedouble;

    // costing_line->sku
    cJSON *sku = cJSON_GetObjectItemCaseSensitive(costing_lineJSON, "sku");
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

    // costing_line->total_quantity
    cJSON *total_quantity = cJSON_GetObjectItemCaseSensitive(costing_lineJSON, "totalQuantity");
    if (cJSON_IsNull(total_quantity)) {
        total_quantity = NULL;
    }
    if (!total_quantity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_quantity))
    {
    goto end; //Numeric
    }
    total_quantity_local_var = malloc(sizeof(long));
    if(!total_quantity_local_var)
    {
        goto end;
    }
    *total_quantity_local_var = total_quantity->valuedouble;

    // costing_line->unit_purchase_price
    cJSON *unit_purchase_price = cJSON_GetObjectItemCaseSensitive(costing_lineJSON, "unitPurchasePrice");
    if (cJSON_IsNull(unit_purchase_price)) {
        unit_purchase_price = NULL;
    }
    if (unit_purchase_price) { 
    if(!cJSON_IsString(unit_purchase_price) && !cJSON_IsNull(unit_purchase_price))
    {
    goto end; //String
    }
    }


    if (line_cost && !cJSON_IsNull(line_cost)) line_cost_local_str = strdup(line_cost->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (sku && !cJSON_IsNull(sku)) sku_local_str = strdup(sku->valuestring);
    if (unit_purchase_price && !cJSON_IsNull(unit_purchase_price)) unit_purchase_price_local_str = strdup(unit_purchase_price->valuestring);

    costing_line_local_var = costing_line_create_internal (
        line_cost_local_str,
        name_local_str,
        product_id_local_str,
        quantity_per_unit_local_var,
        sku_local_str,
        total_quantity_local_var,
        unit_purchase_price_local_str
        );

    if (!costing_line_local_var) {
        goto end;
    }

    return costing_line_local_var;
end:
    if (line_cost_local_str) {
        free(line_cost_local_str);
        line_cost_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (quantity_per_unit_local_var) {
        free(quantity_per_unit_local_var);
        quantity_per_unit_local_var = NULL;
    }
    if (sku_local_str) {
        free(sku_local_str);
        sku_local_str = NULL;
    }
    if (total_quantity_local_var) {
        free(total_quantity_local_var);
        total_quantity_local_var = NULL;
    }
    if (unit_purchase_price_local_str) {
        free(unit_purchase_price_local_str);
        unit_purchase_price_local_str = NULL;
    }
    return NULL;

}
