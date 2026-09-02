#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "production_order.h"



static production_order_t *production_order_create_internal(
    char *bom_id,
    any_type_t *components,
    char *end_date,
    char *notes,
    char *order_number,
    char *product_id,
    long *quantity,
    char *source_warehouse_id,
    char *start_date,
    production_order_status_t *status,
    char *target_warehouse_id
    ) {
    production_order_t *production_order_local_var = malloc(sizeof(production_order_t));
    if (!production_order_local_var) {
        return NULL;
    }
    memset(production_order_local_var, 0, sizeof(production_order_t));
    production_order_local_var->_library_owned = 1;
    production_order_local_var->bom_id = bom_id;
    production_order_local_var->components = components;
    production_order_local_var->end_date = end_date;
    production_order_local_var->notes = notes;
    production_order_local_var->order_number = order_number;
    production_order_local_var->product_id = product_id;
    production_order_local_var->quantity = quantity;
    production_order_local_var->source_warehouse_id = source_warehouse_id;
    production_order_local_var->start_date = start_date;
    production_order_local_var->status = status;
    production_order_local_var->target_warehouse_id = target_warehouse_id;
    return production_order_local_var;
}

__attribute__((deprecated)) production_order_t *production_order_create(
    char *bom_id,
    any_type_t *components,
    char *end_date,
    char *notes,
    char *order_number,
    char *product_id,
    long *quantity,
    char *source_warehouse_id,
    char *start_date,
    production_order_status_t *status,
    char *target_warehouse_id
    ) {
    long *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(long));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    production_order_t *result = production_order_create_internal (
        bom_id,
        components,
        end_date,
        notes,
        order_number,
        product_id,
        quantity_copy,
        source_warehouse_id,
        start_date,
        status,
        target_warehouse_id
        );
    if (!result) {
        free(quantity_copy);
    }
    return result;
}

void production_order_free(production_order_t *production_order) {
    if(NULL == production_order){
        return ;
    }
    if(production_order->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "production_order_free");
        return ;
    }
    listEntry_t *listEntry;
    if (production_order->bom_id) {
        free(production_order->bom_id);
        production_order->bom_id = NULL;
    }
    if (production_order->components) {
        _free(production_order->components);
        production_order->components = NULL;
    }
    if (production_order->end_date) {
        free(production_order->end_date);
        production_order->end_date = NULL;
    }
    if (production_order->notes) {
        free(production_order->notes);
        production_order->notes = NULL;
    }
    if (production_order->order_number) {
        free(production_order->order_number);
        production_order->order_number = NULL;
    }
    if (production_order->product_id) {
        free(production_order->product_id);
        production_order->product_id = NULL;
    }
    if (production_order->quantity) {
        free(production_order->quantity);
        production_order->quantity = NULL;
    }
    if (production_order->source_warehouse_id) {
        free(production_order->source_warehouse_id);
        production_order->source_warehouse_id = NULL;
    }
    if (production_order->start_date) {
        free(production_order->start_date);
        production_order->start_date = NULL;
    }
    if (production_order->status) {
        production_order_status_free(production_order->status);
        production_order->status = NULL;
    }
    if (production_order->target_warehouse_id) {
        free(production_order->target_warehouse_id);
        production_order->target_warehouse_id = NULL;
    }
    free(production_order);
}

cJSON *production_order_convertToJSON(production_order_t *production_order) {
    cJSON *item = cJSON_CreateObject();

    // production_order->bom_id
    if(production_order->bom_id) {
    if(cJSON_AddStringToObject(item, "bomId", production_order->bom_id) == NULL) {
    goto fail; //String
    }
    }


    // production_order->components
    if(production_order->components) {
    cJSON *components_local_JSON = _convertToJSON(production_order->components);
    if(components_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "components", components_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // production_order->end_date
    if(production_order->end_date) {
    if(cJSON_AddStringToObject(item, "endDate", production_order->end_date) == NULL) {
    goto fail; //Date
    }
    }


    // production_order->notes
    if(production_order->notes) {
    if(cJSON_AddStringToObject(item, "notes", production_order->notes) == NULL) {
    goto fail; //String
    }
    }


    // production_order->order_number
    if (!production_order->order_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "orderNumber", production_order->order_number) == NULL) {
    goto fail; //String
    }


    // production_order->product_id
    if (!production_order->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", production_order->product_id) == NULL) {
    goto fail; //String
    }


    // production_order->quantity
    if (!production_order->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *production_order->quantity) == NULL) {
    goto fail; //Numeric
    }


    // production_order->source_warehouse_id
    if(production_order->source_warehouse_id) {
    if(cJSON_AddStringToObject(item, "sourceWarehouseId", production_order->source_warehouse_id) == NULL) {
    goto fail; //String
    }
    }


    // production_order->start_date
    if(production_order->start_date) {
    if(cJSON_AddStringToObject(item, "startDate", production_order->start_date) == NULL) {
    goto fail; //Date
    }
    }


    // production_order->status
    if(production_order->status) {
    cJSON *status_local_JSON = production_order_status_convertToJSON(production_order->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // production_order->target_warehouse_id
    if(production_order->target_warehouse_id) {
    if(cJSON_AddStringToObject(item, "targetWarehouseId", production_order->target_warehouse_id) == NULL) {
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

production_order_t *production_order_parseFromJSON(cJSON *production_orderJSON){

    production_order_t *production_order_local_var = NULL;

    char *bom_id_local_str = NULL;

    // define the local variable for production_order->components
    _t *components_local_nonprim = NULL;

    char *end_date_local_str = NULL;

    char *notes_local_str = NULL;

    char *order_number_local_str = NULL;

    char *product_id_local_str = NULL;

    // define the local variable for production_order->quantity
    long *quantity_local_var = NULL;

    char *source_warehouse_id_local_str = NULL;

    char *start_date_local_str = NULL;

    // define the local variable for production_order->status
    production_order_status_t *status_local_nonprim = NULL;

    char *target_warehouse_id_local_str = NULL;

    // production_order->bom_id
    cJSON *bom_id = cJSON_GetObjectItemCaseSensitive(production_orderJSON, "bomId");
    if (cJSON_IsNull(bom_id)) {
        bom_id = NULL;
    }
    if (bom_id) { 
    if(!cJSON_IsString(bom_id) && !cJSON_IsNull(bom_id))
    {
    goto end; //String
    }
    }

    // production_order->components
    cJSON *components = cJSON_GetObjectItemCaseSensitive(production_orderJSON, "components");
    if (cJSON_IsNull(components)) {
        components = NULL;
    }
    if (components) { 
    components_local_nonprim = _parseFromJSON(components); //custom
    }

    // production_order->end_date
    cJSON *end_date = cJSON_GetObjectItemCaseSensitive(production_orderJSON, "endDate");
    if (cJSON_IsNull(end_date)) {
        end_date = NULL;
    }
    if (end_date) { 
    if(!cJSON_IsString(end_date))
    {
    goto end; //Date
    }
    }

    // production_order->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(production_orderJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // production_order->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(production_orderJSON, "orderNumber");
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

    // production_order->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(production_orderJSON, "productId");
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

    // production_order->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(production_orderJSON, "quantity");
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

    // production_order->source_warehouse_id
    cJSON *source_warehouse_id = cJSON_GetObjectItemCaseSensitive(production_orderJSON, "sourceWarehouseId");
    if (cJSON_IsNull(source_warehouse_id)) {
        source_warehouse_id = NULL;
    }
    if (source_warehouse_id) { 
    if(!cJSON_IsString(source_warehouse_id) && !cJSON_IsNull(source_warehouse_id))
    {
    goto end; //String
    }
    }

    // production_order->start_date
    cJSON *start_date = cJSON_GetObjectItemCaseSensitive(production_orderJSON, "startDate");
    if (cJSON_IsNull(start_date)) {
        start_date = NULL;
    }
    if (start_date) { 
    if(!cJSON_IsString(start_date))
    {
    goto end; //Date
    }
    }

    // production_order->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(production_orderJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = production_order_status_parseFromJSON(status); //custom
    }

    // production_order->target_warehouse_id
    cJSON *target_warehouse_id = cJSON_GetObjectItemCaseSensitive(production_orderJSON, "targetWarehouseId");
    if (cJSON_IsNull(target_warehouse_id)) {
        target_warehouse_id = NULL;
    }
    if (target_warehouse_id) { 
    if(!cJSON_IsString(target_warehouse_id) && !cJSON_IsNull(target_warehouse_id))
    {
    goto end; //String
    }
    }


    if (bom_id && !cJSON_IsNull(bom_id)) bom_id_local_str = strdup(bom_id->valuestring);
    if (end_date) end_date_local_str = strdup(end_date->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (source_warehouse_id && !cJSON_IsNull(source_warehouse_id)) source_warehouse_id_local_str = strdup(source_warehouse_id->valuestring);
    if (start_date) start_date_local_str = strdup(start_date->valuestring);
    if (target_warehouse_id && !cJSON_IsNull(target_warehouse_id)) target_warehouse_id_local_str = strdup(target_warehouse_id->valuestring);

    production_order_local_var = production_order_create_internal (
        bom_id_local_str,
        components ? components_local_nonprim : NULL,
        end_date_local_str,
        notes_local_str,
        order_number_local_str,
        product_id_local_str,
        quantity_local_var,
        source_warehouse_id_local_str,
        start_date_local_str,
        status ? status_local_nonprim : NULL,
        target_warehouse_id_local_str
        );

    if (!production_order_local_var) {
        goto end;
    }

    return production_order_local_var;
end:
    if (bom_id_local_str) {
        free(bom_id_local_str);
        bom_id_local_str = NULL;
    }
    if (components_local_nonprim) {
        _free(components_local_nonprim);
        components_local_nonprim = NULL;
    }
    if (end_date_local_str) {
        free(end_date_local_str);
        end_date_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (source_warehouse_id_local_str) {
        free(source_warehouse_id_local_str);
        source_warehouse_id_local_str = NULL;
    }
    if (start_date_local_str) {
        free(start_date_local_str);
        start_date_local_str = NULL;
    }
    if (status_local_nonprim) {
        production_order_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (target_warehouse_id_local_str) {
        free(target_warehouse_id_local_str);
        target_warehouse_id_local_str = NULL;
    }
    return NULL;

}
