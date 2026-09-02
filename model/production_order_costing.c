#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "production_order_costing.h"



static production_order_costing_t *production_order_costing_create_internal(
    char *cost_per_unit,
    char *cost_source,
    list_t *lines,
    char *margin_per_unit,
    char *margin_percent,
    char *material_cost_total,
    char *order_number,
    char *production_order_id,
    long *quantity,
    char *sale_price,
    char *status
    ) {
    production_order_costing_t *production_order_costing_local_var = malloc(sizeof(production_order_costing_t));
    if (!production_order_costing_local_var) {
        return NULL;
    }
    memset(production_order_costing_local_var, 0, sizeof(production_order_costing_t));
    production_order_costing_local_var->_library_owned = 1;
    production_order_costing_local_var->cost_per_unit = cost_per_unit;
    production_order_costing_local_var->cost_source = cost_source;
    production_order_costing_local_var->lines = lines;
    production_order_costing_local_var->margin_per_unit = margin_per_unit;
    production_order_costing_local_var->margin_percent = margin_percent;
    production_order_costing_local_var->material_cost_total = material_cost_total;
    production_order_costing_local_var->order_number = order_number;
    production_order_costing_local_var->production_order_id = production_order_id;
    production_order_costing_local_var->quantity = quantity;
    production_order_costing_local_var->sale_price = sale_price;
    production_order_costing_local_var->status = status;
    return production_order_costing_local_var;
}

__attribute__((deprecated)) production_order_costing_t *production_order_costing_create(
    char *cost_per_unit,
    char *cost_source,
    list_t *lines,
    char *margin_per_unit,
    char *margin_percent,
    char *material_cost_total,
    char *order_number,
    char *production_order_id,
    long *quantity,
    char *sale_price,
    char *status
    ) {
    long *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(long));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    production_order_costing_t *result = production_order_costing_create_internal (
        cost_per_unit,
        cost_source,
        lines,
        margin_per_unit,
        margin_percent,
        material_cost_total,
        order_number,
        production_order_id,
        quantity_copy,
        sale_price,
        status
        );
    if (!result) {
        free(quantity_copy);
    }
    return result;
}

void production_order_costing_free(production_order_costing_t *production_order_costing) {
    if(NULL == production_order_costing){
        return ;
    }
    if(production_order_costing->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "production_order_costing_free");
        return ;
    }
    listEntry_t *listEntry;
    if (production_order_costing->cost_per_unit) {
        free(production_order_costing->cost_per_unit);
        production_order_costing->cost_per_unit = NULL;
    }
    if (production_order_costing->cost_source) {
        free(production_order_costing->cost_source);
        production_order_costing->cost_source = NULL;
    }
    if (production_order_costing->lines) {
        list_ForEach(listEntry, production_order_costing->lines) {
            costing_line_free(listEntry->data);
        }
        list_freeList(production_order_costing->lines);
        production_order_costing->lines = NULL;
    }
    if (production_order_costing->margin_per_unit) {
        free(production_order_costing->margin_per_unit);
        production_order_costing->margin_per_unit = NULL;
    }
    if (production_order_costing->margin_percent) {
        free(production_order_costing->margin_percent);
        production_order_costing->margin_percent = NULL;
    }
    if (production_order_costing->material_cost_total) {
        free(production_order_costing->material_cost_total);
        production_order_costing->material_cost_total = NULL;
    }
    if (production_order_costing->order_number) {
        free(production_order_costing->order_number);
        production_order_costing->order_number = NULL;
    }
    if (production_order_costing->production_order_id) {
        free(production_order_costing->production_order_id);
        production_order_costing->production_order_id = NULL;
    }
    if (production_order_costing->quantity) {
        free(production_order_costing->quantity);
        production_order_costing->quantity = NULL;
    }
    if (production_order_costing->sale_price) {
        free(production_order_costing->sale_price);
        production_order_costing->sale_price = NULL;
    }
    if (production_order_costing->status) {
        free(production_order_costing->status);
        production_order_costing->status = NULL;
    }
    free(production_order_costing);
}

cJSON *production_order_costing_convertToJSON(production_order_costing_t *production_order_costing) {
    cJSON *item = cJSON_CreateObject();

    // production_order_costing->cost_per_unit
    if (!production_order_costing->cost_per_unit) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "costPerUnit", production_order_costing->cost_per_unit) == NULL) {
    goto fail; //String
    }


    // production_order_costing->cost_source
    if (!production_order_costing->cost_source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "costSource", production_order_costing->cost_source) == NULL) {
    goto fail; //String
    }


    // production_order_costing->lines
    if (!production_order_costing->lines) {
        goto fail;
    }
    cJSON *lines = cJSON_AddArrayToObject(item, "lines");
    if(lines == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *linesListEntry;
    if (production_order_costing->lines) {
    list_ForEach(linesListEntry, production_order_costing->lines) {
    cJSON *itemLocal = costing_line_convertToJSON(linesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(lines, itemLocal);
    }
    }


    // production_order_costing->margin_per_unit
    if(production_order_costing->margin_per_unit) {
    if(cJSON_AddStringToObject(item, "marginPerUnit", production_order_costing->margin_per_unit) == NULL) {
    goto fail; //String
    }
    }


    // production_order_costing->margin_percent
    if(production_order_costing->margin_percent) {
    if(cJSON_AddStringToObject(item, "marginPercent", production_order_costing->margin_percent) == NULL) {
    goto fail; //String
    }
    }


    // production_order_costing->material_cost_total
    if (!production_order_costing->material_cost_total) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "materialCostTotal", production_order_costing->material_cost_total) == NULL) {
    goto fail; //String
    }


    // production_order_costing->order_number
    if (!production_order_costing->order_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "orderNumber", production_order_costing->order_number) == NULL) {
    goto fail; //String
    }


    // production_order_costing->production_order_id
    if (!production_order_costing->production_order_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productionOrderId", production_order_costing->production_order_id) == NULL) {
    goto fail; //String
    }


    // production_order_costing->quantity
    if (!production_order_costing->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *production_order_costing->quantity) == NULL) {
    goto fail; //Numeric
    }


    // production_order_costing->sale_price
    if(production_order_costing->sale_price) {
    if(cJSON_AddStringToObject(item, "salePrice", production_order_costing->sale_price) == NULL) {
    goto fail; //String
    }
    }


    // production_order_costing->status
    if (!production_order_costing->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", production_order_costing->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

production_order_costing_t *production_order_costing_parseFromJSON(cJSON *production_order_costingJSON){

    production_order_costing_t *production_order_costing_local_var = NULL;

    char *cost_per_unit_local_str = NULL;

    char *cost_source_local_str = NULL;

    // define the local list for production_order_costing->lines
    list_t *linesList = NULL;

    char *margin_per_unit_local_str = NULL;

    char *margin_percent_local_str = NULL;

    char *material_cost_total_local_str = NULL;

    char *order_number_local_str = NULL;

    char *production_order_id_local_str = NULL;

    // define the local variable for production_order_costing->quantity
    long *quantity_local_var = NULL;

    char *sale_price_local_str = NULL;

    char *status_local_str = NULL;

    // production_order_costing->cost_per_unit
    cJSON *cost_per_unit = cJSON_GetObjectItemCaseSensitive(production_order_costingJSON, "costPerUnit");
    if (cJSON_IsNull(cost_per_unit)) {
        cost_per_unit = NULL;
    }
    if (!cost_per_unit) {
        goto end;
    }

    
    if(!cJSON_IsString(cost_per_unit))
    {
    goto end; //String
    }

    // production_order_costing->cost_source
    cJSON *cost_source = cJSON_GetObjectItemCaseSensitive(production_order_costingJSON, "costSource");
    if (cJSON_IsNull(cost_source)) {
        cost_source = NULL;
    }
    if (!cost_source) {
        goto end;
    }

    
    if(!cJSON_IsString(cost_source))
    {
    goto end; //String
    }

    // production_order_costing->lines
    cJSON *lines = cJSON_GetObjectItemCaseSensitive(production_order_costingJSON, "lines");
    if (cJSON_IsNull(lines)) {
        lines = NULL;
    }
    if (!lines) {
        goto end;
    }

    
    cJSON *lines_local_nonprimitive = NULL;
    if(!cJSON_IsArray(lines)){
        goto end; //nonprimitive container
    }

    linesList = list_createList();

    cJSON_ArrayForEach(lines_local_nonprimitive,lines )
    {
        if(!cJSON_IsObject(lines_local_nonprimitive)){
            goto end;
        }
        costing_line_t *linesItem = costing_line_parseFromJSON(lines_local_nonprimitive);

        list_addElement(linesList, linesItem);
    }

    // production_order_costing->margin_per_unit
    cJSON *margin_per_unit = cJSON_GetObjectItemCaseSensitive(production_order_costingJSON, "marginPerUnit");
    if (cJSON_IsNull(margin_per_unit)) {
        margin_per_unit = NULL;
    }
    if (margin_per_unit) { 
    if(!cJSON_IsString(margin_per_unit) && !cJSON_IsNull(margin_per_unit))
    {
    goto end; //String
    }
    }

    // production_order_costing->margin_percent
    cJSON *margin_percent = cJSON_GetObjectItemCaseSensitive(production_order_costingJSON, "marginPercent");
    if (cJSON_IsNull(margin_percent)) {
        margin_percent = NULL;
    }
    if (margin_percent) { 
    if(!cJSON_IsString(margin_percent) && !cJSON_IsNull(margin_percent))
    {
    goto end; //String
    }
    }

    // production_order_costing->material_cost_total
    cJSON *material_cost_total = cJSON_GetObjectItemCaseSensitive(production_order_costingJSON, "materialCostTotal");
    if (cJSON_IsNull(material_cost_total)) {
        material_cost_total = NULL;
    }
    if (!material_cost_total) {
        goto end;
    }

    
    if(!cJSON_IsString(material_cost_total))
    {
    goto end; //String
    }

    // production_order_costing->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(production_order_costingJSON, "orderNumber");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (!order_number) {
        goto end;
    }

    
    if(!cJSON_IsString(order_number))
    {
    goto end; //String
    }

    // production_order_costing->production_order_id
    cJSON *production_order_id = cJSON_GetObjectItemCaseSensitive(production_order_costingJSON, "productionOrderId");
    if (cJSON_IsNull(production_order_id)) {
        production_order_id = NULL;
    }
    if (!production_order_id) {
        goto end;
    }

    
    if(!cJSON_IsString(production_order_id))
    {
    goto end; //String
    }

    // production_order_costing->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(production_order_costingJSON, "quantity");
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

    // production_order_costing->sale_price
    cJSON *sale_price = cJSON_GetObjectItemCaseSensitive(production_order_costingJSON, "salePrice");
    if (cJSON_IsNull(sale_price)) {
        sale_price = NULL;
    }
    if (sale_price) { 
    if(!cJSON_IsString(sale_price) && !cJSON_IsNull(sale_price))
    {
    goto end; //String
    }
    }

    // production_order_costing->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(production_order_costingJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }


    if (cost_per_unit && !cJSON_IsNull(cost_per_unit)) cost_per_unit_local_str = strdup(cost_per_unit->valuestring);
    if (cost_source && !cJSON_IsNull(cost_source)) cost_source_local_str = strdup(cost_source->valuestring);
    if (margin_per_unit && !cJSON_IsNull(margin_per_unit)) margin_per_unit_local_str = strdup(margin_per_unit->valuestring);
    if (margin_percent && !cJSON_IsNull(margin_percent)) margin_percent_local_str = strdup(margin_percent->valuestring);
    if (material_cost_total && !cJSON_IsNull(material_cost_total)) material_cost_total_local_str = strdup(material_cost_total->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);
    if (production_order_id && !cJSON_IsNull(production_order_id)) production_order_id_local_str = strdup(production_order_id->valuestring);
    if (sale_price && !cJSON_IsNull(sale_price)) sale_price_local_str = strdup(sale_price->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    production_order_costing_local_var = production_order_costing_create_internal (
        cost_per_unit_local_str,
        cost_source_local_str,
        linesList,
        margin_per_unit_local_str,
        margin_percent_local_str,
        material_cost_total_local_str,
        order_number_local_str,
        production_order_id_local_str,
        quantity_local_var,
        sale_price_local_str,
        status_local_str
        );

    if (!production_order_costing_local_var) {
        goto end;
    }

    return production_order_costing_local_var;
end:
    if (cost_per_unit_local_str) {
        free(cost_per_unit_local_str);
        cost_per_unit_local_str = NULL;
    }
    if (cost_source_local_str) {
        free(cost_source_local_str);
        cost_source_local_str = NULL;
    }
    if (linesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, linesList) {
            costing_line_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(linesList);
        linesList = NULL;
    }
    if (margin_per_unit_local_str) {
        free(margin_per_unit_local_str);
        margin_per_unit_local_str = NULL;
    }
    if (margin_percent_local_str) {
        free(margin_percent_local_str);
        margin_percent_local_str = NULL;
    }
    if (material_cost_total_local_str) {
        free(material_cost_total_local_str);
        material_cost_total_local_str = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    if (production_order_id_local_str) {
        free(production_order_id_local_str);
        production_order_id_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (sale_price_local_str) {
        free(sale_price_local_str);
        sale_price_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
