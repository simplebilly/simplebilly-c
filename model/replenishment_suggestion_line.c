#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "replenishment_suggestion_line.h"



static replenishment_suggestion_line_t *replenishment_suggestion_line_create_internal(
    long *current_stock,
    long *max_stock,
    long *min_stock,
    char *product_id,
    char *product_name,
    char *sku,
    long *source_available,
    char *source_warehouse_id,
    long *suggested_quantity,
    char *target_warehouse_id
    ) {
    replenishment_suggestion_line_t *replenishment_suggestion_line_local_var = malloc(sizeof(replenishment_suggestion_line_t));
    if (!replenishment_suggestion_line_local_var) {
        return NULL;
    }
    memset(replenishment_suggestion_line_local_var, 0, sizeof(replenishment_suggestion_line_t));
    replenishment_suggestion_line_local_var->_library_owned = 1;
    replenishment_suggestion_line_local_var->current_stock = current_stock;
    replenishment_suggestion_line_local_var->max_stock = max_stock;
    replenishment_suggestion_line_local_var->min_stock = min_stock;
    replenishment_suggestion_line_local_var->product_id = product_id;
    replenishment_suggestion_line_local_var->product_name = product_name;
    replenishment_suggestion_line_local_var->sku = sku;
    replenishment_suggestion_line_local_var->source_available = source_available;
    replenishment_suggestion_line_local_var->source_warehouse_id = source_warehouse_id;
    replenishment_suggestion_line_local_var->suggested_quantity = suggested_quantity;
    replenishment_suggestion_line_local_var->target_warehouse_id = target_warehouse_id;
    return replenishment_suggestion_line_local_var;
}

__attribute__((deprecated)) replenishment_suggestion_line_t *replenishment_suggestion_line_create(
    long *current_stock,
    long *max_stock,
    long *min_stock,
    char *product_id,
    char *product_name,
    char *sku,
    long *source_available,
    char *source_warehouse_id,
    long *suggested_quantity,
    char *target_warehouse_id
    ) {
    long *current_stock_copy = NULL;
    if (current_stock) {
        current_stock_copy = malloc(sizeof(long));
        if (current_stock_copy) *current_stock_copy = *current_stock;
    }
    long *max_stock_copy = NULL;
    if (max_stock) {
        max_stock_copy = malloc(sizeof(long));
        if (max_stock_copy) *max_stock_copy = *max_stock;
    }
    long *min_stock_copy = NULL;
    if (min_stock) {
        min_stock_copy = malloc(sizeof(long));
        if (min_stock_copy) *min_stock_copy = *min_stock;
    }
    long *source_available_copy = NULL;
    if (source_available) {
        source_available_copy = malloc(sizeof(long));
        if (source_available_copy) *source_available_copy = *source_available;
    }
    long *suggested_quantity_copy = NULL;
    if (suggested_quantity) {
        suggested_quantity_copy = malloc(sizeof(long));
        if (suggested_quantity_copy) *suggested_quantity_copy = *suggested_quantity;
    }
    replenishment_suggestion_line_t *result = replenishment_suggestion_line_create_internal (
        current_stock_copy,
        max_stock_copy,
        min_stock_copy,
        product_id,
        product_name,
        sku,
        source_available_copy,
        source_warehouse_id,
        suggested_quantity_copy,
        target_warehouse_id
        );
    if (!result) {
        free(current_stock_copy);
        free(max_stock_copy);
        free(min_stock_copy);
        free(source_available_copy);
        free(suggested_quantity_copy);
    }
    return result;
}

void replenishment_suggestion_line_free(replenishment_suggestion_line_t *replenishment_suggestion_line) {
    if(NULL == replenishment_suggestion_line){
        return ;
    }
    if(replenishment_suggestion_line->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "replenishment_suggestion_line_free");
        return ;
    }
    listEntry_t *listEntry;
    if (replenishment_suggestion_line->current_stock) {
        free(replenishment_suggestion_line->current_stock);
        replenishment_suggestion_line->current_stock = NULL;
    }
    if (replenishment_suggestion_line->max_stock) {
        free(replenishment_suggestion_line->max_stock);
        replenishment_suggestion_line->max_stock = NULL;
    }
    if (replenishment_suggestion_line->min_stock) {
        free(replenishment_suggestion_line->min_stock);
        replenishment_suggestion_line->min_stock = NULL;
    }
    if (replenishment_suggestion_line->product_id) {
        free(replenishment_suggestion_line->product_id);
        replenishment_suggestion_line->product_id = NULL;
    }
    if (replenishment_suggestion_line->product_name) {
        free(replenishment_suggestion_line->product_name);
        replenishment_suggestion_line->product_name = NULL;
    }
    if (replenishment_suggestion_line->sku) {
        free(replenishment_suggestion_line->sku);
        replenishment_suggestion_line->sku = NULL;
    }
    if (replenishment_suggestion_line->source_available) {
        free(replenishment_suggestion_line->source_available);
        replenishment_suggestion_line->source_available = NULL;
    }
    if (replenishment_suggestion_line->source_warehouse_id) {
        free(replenishment_suggestion_line->source_warehouse_id);
        replenishment_suggestion_line->source_warehouse_id = NULL;
    }
    if (replenishment_suggestion_line->suggested_quantity) {
        free(replenishment_suggestion_line->suggested_quantity);
        replenishment_suggestion_line->suggested_quantity = NULL;
    }
    if (replenishment_suggestion_line->target_warehouse_id) {
        free(replenishment_suggestion_line->target_warehouse_id);
        replenishment_suggestion_line->target_warehouse_id = NULL;
    }
    free(replenishment_suggestion_line);
}

cJSON *replenishment_suggestion_line_convertToJSON(replenishment_suggestion_line_t *replenishment_suggestion_line) {
    cJSON *item = cJSON_CreateObject();

    // replenishment_suggestion_line->current_stock
    if (!replenishment_suggestion_line->current_stock) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "currentStock", *replenishment_suggestion_line->current_stock) == NULL) {
    goto fail; //Numeric
    }


    // replenishment_suggestion_line->max_stock
    if(replenishment_suggestion_line->max_stock) {
    if(cJSON_AddNumberToObject(item, "maxStock", *replenishment_suggestion_line->max_stock) == NULL) {
    goto fail; //Numeric
    }
    }


    // replenishment_suggestion_line->min_stock
    if(replenishment_suggestion_line->min_stock) {
    if(cJSON_AddNumberToObject(item, "minStock", *replenishment_suggestion_line->min_stock) == NULL) {
    goto fail; //Numeric
    }
    }


    // replenishment_suggestion_line->product_id
    if (!replenishment_suggestion_line->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", replenishment_suggestion_line->product_id) == NULL) {
    goto fail; //String
    }


    // replenishment_suggestion_line->product_name
    if (!replenishment_suggestion_line->product_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productName", replenishment_suggestion_line->product_name) == NULL) {
    goto fail; //String
    }


    // replenishment_suggestion_line->sku
    if (!replenishment_suggestion_line->sku) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sku", replenishment_suggestion_line->sku) == NULL) {
    goto fail; //String
    }


    // replenishment_suggestion_line->source_available
    if (!replenishment_suggestion_line->source_available) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "sourceAvailable", *replenishment_suggestion_line->source_available) == NULL) {
    goto fail; //Numeric
    }


    // replenishment_suggestion_line->source_warehouse_id
    if (!replenishment_suggestion_line->source_warehouse_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sourceWarehouseId", replenishment_suggestion_line->source_warehouse_id) == NULL) {
    goto fail; //String
    }


    // replenishment_suggestion_line->suggested_quantity
    if (!replenishment_suggestion_line->suggested_quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "suggestedQuantity", *replenishment_suggestion_line->suggested_quantity) == NULL) {
    goto fail; //Numeric
    }


    // replenishment_suggestion_line->target_warehouse_id
    if (!replenishment_suggestion_line->target_warehouse_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "targetWarehouseId", replenishment_suggestion_line->target_warehouse_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

replenishment_suggestion_line_t *replenishment_suggestion_line_parseFromJSON(cJSON *replenishment_suggestion_lineJSON){

    replenishment_suggestion_line_t *replenishment_suggestion_line_local_var = NULL;

    // define the local variable for replenishment_suggestion_line->current_stock
    long *current_stock_local_var = NULL;

    // define the local variable for replenishment_suggestion_line->max_stock
    long *max_stock_local_var = NULL;

    // define the local variable for replenishment_suggestion_line->min_stock
    long *min_stock_local_var = NULL;

    char *product_id_local_str = NULL;

    char *product_name_local_str = NULL;

    char *sku_local_str = NULL;

    // define the local variable for replenishment_suggestion_line->source_available
    long *source_available_local_var = NULL;

    char *source_warehouse_id_local_str = NULL;

    // define the local variable for replenishment_suggestion_line->suggested_quantity
    long *suggested_quantity_local_var = NULL;

    char *target_warehouse_id_local_str = NULL;

    // replenishment_suggestion_line->current_stock
    cJSON *current_stock = cJSON_GetObjectItemCaseSensitive(replenishment_suggestion_lineJSON, "currentStock");
    if (cJSON_IsNull(current_stock)) {
        current_stock = NULL;
    }
    if (!current_stock) {
        goto end;
    }

    
    if(!cJSON_IsNumber(current_stock))
    {
    goto end; //Numeric
    }
    current_stock_local_var = malloc(sizeof(long));
    if(!current_stock_local_var)
    {
        goto end;
    }
    *current_stock_local_var = current_stock->valuedouble;

    // replenishment_suggestion_line->max_stock
    cJSON *max_stock = cJSON_GetObjectItemCaseSensitive(replenishment_suggestion_lineJSON, "maxStock");
    if (cJSON_IsNull(max_stock)) {
        max_stock = NULL;
    }
    if (max_stock) { 
    if(!cJSON_IsNumber(max_stock))
    {
    goto end; //Numeric
    }
    max_stock_local_var = malloc(sizeof(long));
    if(!max_stock_local_var)
    {
        goto end;
    }
    *max_stock_local_var = max_stock->valuedouble;
    }

    // replenishment_suggestion_line->min_stock
    cJSON *min_stock = cJSON_GetObjectItemCaseSensitive(replenishment_suggestion_lineJSON, "minStock");
    if (cJSON_IsNull(min_stock)) {
        min_stock = NULL;
    }
    if (min_stock) { 
    if(!cJSON_IsNumber(min_stock))
    {
    goto end; //Numeric
    }
    min_stock_local_var = malloc(sizeof(long));
    if(!min_stock_local_var)
    {
        goto end;
    }
    *min_stock_local_var = min_stock->valuedouble;
    }

    // replenishment_suggestion_line->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(replenishment_suggestion_lineJSON, "productId");
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

    // replenishment_suggestion_line->product_name
    cJSON *product_name = cJSON_GetObjectItemCaseSensitive(replenishment_suggestion_lineJSON, "productName");
    if (cJSON_IsNull(product_name)) {
        product_name = NULL;
    }
    if (!product_name) {
        goto end;
    }

    
    if(!cJSON_IsString(product_name))
    {
    goto end; //String
    }

    // replenishment_suggestion_line->sku
    cJSON *sku = cJSON_GetObjectItemCaseSensitive(replenishment_suggestion_lineJSON, "sku");
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

    // replenishment_suggestion_line->source_available
    cJSON *source_available = cJSON_GetObjectItemCaseSensitive(replenishment_suggestion_lineJSON, "sourceAvailable");
    if (cJSON_IsNull(source_available)) {
        source_available = NULL;
    }
    if (!source_available) {
        goto end;
    }

    
    if(!cJSON_IsNumber(source_available))
    {
    goto end; //Numeric
    }
    source_available_local_var = malloc(sizeof(long));
    if(!source_available_local_var)
    {
        goto end;
    }
    *source_available_local_var = source_available->valuedouble;

    // replenishment_suggestion_line->source_warehouse_id
    cJSON *source_warehouse_id = cJSON_GetObjectItemCaseSensitive(replenishment_suggestion_lineJSON, "sourceWarehouseId");
    if (cJSON_IsNull(source_warehouse_id)) {
        source_warehouse_id = NULL;
    }
    if (!source_warehouse_id) {
        goto end;
    }

    
    if(!cJSON_IsString(source_warehouse_id))
    {
    goto end; //String
    }

    // replenishment_suggestion_line->suggested_quantity
    cJSON *suggested_quantity = cJSON_GetObjectItemCaseSensitive(replenishment_suggestion_lineJSON, "suggestedQuantity");
    if (cJSON_IsNull(suggested_quantity)) {
        suggested_quantity = NULL;
    }
    if (!suggested_quantity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(suggested_quantity))
    {
    goto end; //Numeric
    }
    suggested_quantity_local_var = malloc(sizeof(long));
    if(!suggested_quantity_local_var)
    {
        goto end;
    }
    *suggested_quantity_local_var = suggested_quantity->valuedouble;

    // replenishment_suggestion_line->target_warehouse_id
    cJSON *target_warehouse_id = cJSON_GetObjectItemCaseSensitive(replenishment_suggestion_lineJSON, "targetWarehouseId");
    if (cJSON_IsNull(target_warehouse_id)) {
        target_warehouse_id = NULL;
    }
    if (!target_warehouse_id) {
        goto end;
    }

    
    if(!cJSON_IsString(target_warehouse_id))
    {
    goto end; //String
    }


    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (product_name && !cJSON_IsNull(product_name)) product_name_local_str = strdup(product_name->valuestring);
    if (sku && !cJSON_IsNull(sku)) sku_local_str = strdup(sku->valuestring);
    if (source_warehouse_id && !cJSON_IsNull(source_warehouse_id)) source_warehouse_id_local_str = strdup(source_warehouse_id->valuestring);
    if (target_warehouse_id && !cJSON_IsNull(target_warehouse_id)) target_warehouse_id_local_str = strdup(target_warehouse_id->valuestring);

    replenishment_suggestion_line_local_var = replenishment_suggestion_line_create_internal (
        current_stock_local_var,
        max_stock_local_var,
        min_stock_local_var,
        product_id_local_str,
        product_name_local_str,
        sku_local_str,
        source_available_local_var,
        source_warehouse_id_local_str,
        suggested_quantity_local_var,
        target_warehouse_id_local_str
        );

    if (!replenishment_suggestion_line_local_var) {
        goto end;
    }

    return replenishment_suggestion_line_local_var;
end:
    if (current_stock_local_var) {
        free(current_stock_local_var);
        current_stock_local_var = NULL;
    }
    if (max_stock_local_var) {
        free(max_stock_local_var);
        max_stock_local_var = NULL;
    }
    if (min_stock_local_var) {
        free(min_stock_local_var);
        min_stock_local_var = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (product_name_local_str) {
        free(product_name_local_str);
        product_name_local_str = NULL;
    }
    if (sku_local_str) {
        free(sku_local_str);
        sku_local_str = NULL;
    }
    if (source_available_local_var) {
        free(source_available_local_var);
        source_available_local_var = NULL;
    }
    if (source_warehouse_id_local_str) {
        free(source_warehouse_id_local_str);
        source_warehouse_id_local_str = NULL;
    }
    if (suggested_quantity_local_var) {
        free(suggested_quantity_local_var);
        suggested_quantity_local_var = NULL;
    }
    if (target_warehouse_id_local_str) {
        free(target_warehouse_id_local_str);
        target_warehouse_id_local_str = NULL;
    }
    return NULL;

}
