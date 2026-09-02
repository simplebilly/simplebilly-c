#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reorder_proposal_line.h"



static reorder_proposal_line_t *reorder_proposal_line_create_internal(
    long *current_stock,
    long *max_stock,
    long *min_stock,
    char *product_id,
    char *product_name,
    long *reorder_quantity,
    char *sku,
    long *suggested_quantity
    ) {
    reorder_proposal_line_t *reorder_proposal_line_local_var = malloc(sizeof(reorder_proposal_line_t));
    if (!reorder_proposal_line_local_var) {
        return NULL;
    }
    memset(reorder_proposal_line_local_var, 0, sizeof(reorder_proposal_line_t));
    reorder_proposal_line_local_var->_library_owned = 1;
    reorder_proposal_line_local_var->current_stock = current_stock;
    reorder_proposal_line_local_var->max_stock = max_stock;
    reorder_proposal_line_local_var->min_stock = min_stock;
    reorder_proposal_line_local_var->product_id = product_id;
    reorder_proposal_line_local_var->product_name = product_name;
    reorder_proposal_line_local_var->reorder_quantity = reorder_quantity;
    reorder_proposal_line_local_var->sku = sku;
    reorder_proposal_line_local_var->suggested_quantity = suggested_quantity;
    return reorder_proposal_line_local_var;
}

__attribute__((deprecated)) reorder_proposal_line_t *reorder_proposal_line_create(
    long *current_stock,
    long *max_stock,
    long *min_stock,
    char *product_id,
    char *product_name,
    long *reorder_quantity,
    char *sku,
    long *suggested_quantity
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
    long *reorder_quantity_copy = NULL;
    if (reorder_quantity) {
        reorder_quantity_copy = malloc(sizeof(long));
        if (reorder_quantity_copy) *reorder_quantity_copy = *reorder_quantity;
    }
    long *suggested_quantity_copy = NULL;
    if (suggested_quantity) {
        suggested_quantity_copy = malloc(sizeof(long));
        if (suggested_quantity_copy) *suggested_quantity_copy = *suggested_quantity;
    }
    reorder_proposal_line_t *result = reorder_proposal_line_create_internal (
        current_stock_copy,
        max_stock_copy,
        min_stock_copy,
        product_id,
        product_name,
        reorder_quantity_copy,
        sku,
        suggested_quantity_copy
        );
    if (!result) {
        free(current_stock_copy);
        free(max_stock_copy);
        free(min_stock_copy);
        free(reorder_quantity_copy);
        free(suggested_quantity_copy);
    }
    return result;
}

void reorder_proposal_line_free(reorder_proposal_line_t *reorder_proposal_line) {
    if(NULL == reorder_proposal_line){
        return ;
    }
    if(reorder_proposal_line->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reorder_proposal_line_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reorder_proposal_line->current_stock) {
        free(reorder_proposal_line->current_stock);
        reorder_proposal_line->current_stock = NULL;
    }
    if (reorder_proposal_line->max_stock) {
        free(reorder_proposal_line->max_stock);
        reorder_proposal_line->max_stock = NULL;
    }
    if (reorder_proposal_line->min_stock) {
        free(reorder_proposal_line->min_stock);
        reorder_proposal_line->min_stock = NULL;
    }
    if (reorder_proposal_line->product_id) {
        free(reorder_proposal_line->product_id);
        reorder_proposal_line->product_id = NULL;
    }
    if (reorder_proposal_line->product_name) {
        free(reorder_proposal_line->product_name);
        reorder_proposal_line->product_name = NULL;
    }
    if (reorder_proposal_line->reorder_quantity) {
        free(reorder_proposal_line->reorder_quantity);
        reorder_proposal_line->reorder_quantity = NULL;
    }
    if (reorder_proposal_line->sku) {
        free(reorder_proposal_line->sku);
        reorder_proposal_line->sku = NULL;
    }
    if (reorder_proposal_line->suggested_quantity) {
        free(reorder_proposal_line->suggested_quantity);
        reorder_proposal_line->suggested_quantity = NULL;
    }
    free(reorder_proposal_line);
}

cJSON *reorder_proposal_line_convertToJSON(reorder_proposal_line_t *reorder_proposal_line) {
    cJSON *item = cJSON_CreateObject();

    // reorder_proposal_line->current_stock
    if (!reorder_proposal_line->current_stock) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "currentStock", *reorder_proposal_line->current_stock) == NULL) {
    goto fail; //Numeric
    }


    // reorder_proposal_line->max_stock
    if(reorder_proposal_line->max_stock) {
    if(cJSON_AddNumberToObject(item, "maxStock", *reorder_proposal_line->max_stock) == NULL) {
    goto fail; //Numeric
    }
    }


    // reorder_proposal_line->min_stock
    if(reorder_proposal_line->min_stock) {
    if(cJSON_AddNumberToObject(item, "minStock", *reorder_proposal_line->min_stock) == NULL) {
    goto fail; //Numeric
    }
    }


    // reorder_proposal_line->product_id
    if (!reorder_proposal_line->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", reorder_proposal_line->product_id) == NULL) {
    goto fail; //String
    }


    // reorder_proposal_line->product_name
    if (!reorder_proposal_line->product_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productName", reorder_proposal_line->product_name) == NULL) {
    goto fail; //String
    }


    // reorder_proposal_line->reorder_quantity
    if(reorder_proposal_line->reorder_quantity) {
    if(cJSON_AddNumberToObject(item, "reorderQuantity", *reorder_proposal_line->reorder_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // reorder_proposal_line->sku
    if (!reorder_proposal_line->sku) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sku", reorder_proposal_line->sku) == NULL) {
    goto fail; //String
    }


    // reorder_proposal_line->suggested_quantity
    if (!reorder_proposal_line->suggested_quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "suggestedQuantity", *reorder_proposal_line->suggested_quantity) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reorder_proposal_line_t *reorder_proposal_line_parseFromJSON(cJSON *reorder_proposal_lineJSON){

    reorder_proposal_line_t *reorder_proposal_line_local_var = NULL;

    // define the local variable for reorder_proposal_line->current_stock
    long *current_stock_local_var = NULL;

    // define the local variable for reorder_proposal_line->max_stock
    long *max_stock_local_var = NULL;

    // define the local variable for reorder_proposal_line->min_stock
    long *min_stock_local_var = NULL;

    char *product_id_local_str = NULL;

    char *product_name_local_str = NULL;

    // define the local variable for reorder_proposal_line->reorder_quantity
    long *reorder_quantity_local_var = NULL;

    char *sku_local_str = NULL;

    // define the local variable for reorder_proposal_line->suggested_quantity
    long *suggested_quantity_local_var = NULL;

    // reorder_proposal_line->current_stock
    cJSON *current_stock = cJSON_GetObjectItemCaseSensitive(reorder_proposal_lineJSON, "currentStock");
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

    // reorder_proposal_line->max_stock
    cJSON *max_stock = cJSON_GetObjectItemCaseSensitive(reorder_proposal_lineJSON, "maxStock");
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

    // reorder_proposal_line->min_stock
    cJSON *min_stock = cJSON_GetObjectItemCaseSensitive(reorder_proposal_lineJSON, "minStock");
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

    // reorder_proposal_line->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(reorder_proposal_lineJSON, "productId");
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

    // reorder_proposal_line->product_name
    cJSON *product_name = cJSON_GetObjectItemCaseSensitive(reorder_proposal_lineJSON, "productName");
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

    // reorder_proposal_line->reorder_quantity
    cJSON *reorder_quantity = cJSON_GetObjectItemCaseSensitive(reorder_proposal_lineJSON, "reorderQuantity");
    if (cJSON_IsNull(reorder_quantity)) {
        reorder_quantity = NULL;
    }
    if (reorder_quantity) { 
    if(!cJSON_IsNumber(reorder_quantity))
    {
    goto end; //Numeric
    }
    reorder_quantity_local_var = malloc(sizeof(long));
    if(!reorder_quantity_local_var)
    {
        goto end;
    }
    *reorder_quantity_local_var = reorder_quantity->valuedouble;
    }

    // reorder_proposal_line->sku
    cJSON *sku = cJSON_GetObjectItemCaseSensitive(reorder_proposal_lineJSON, "sku");
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

    // reorder_proposal_line->suggested_quantity
    cJSON *suggested_quantity = cJSON_GetObjectItemCaseSensitive(reorder_proposal_lineJSON, "suggestedQuantity");
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


    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (product_name && !cJSON_IsNull(product_name)) product_name_local_str = strdup(product_name->valuestring);
    if (sku && !cJSON_IsNull(sku)) sku_local_str = strdup(sku->valuestring);

    reorder_proposal_line_local_var = reorder_proposal_line_create_internal (
        current_stock_local_var,
        max_stock_local_var,
        min_stock_local_var,
        product_id_local_str,
        product_name_local_str,
        reorder_quantity_local_var,
        sku_local_str,
        suggested_quantity_local_var
        );

    if (!reorder_proposal_line_local_var) {
        goto end;
    }

    return reorder_proposal_line_local_var;
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
    if (reorder_quantity_local_var) {
        free(reorder_quantity_local_var);
        reorder_quantity_local_var = NULL;
    }
    if (sku_local_str) {
        free(sku_local_str);
        sku_local_str = NULL;
    }
    if (suggested_quantity_local_var) {
        free(suggested_quantity_local_var);
        suggested_quantity_local_var = NULL;
    }
    return NULL;

}
