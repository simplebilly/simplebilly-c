#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stock_transfer.h"



static stock_transfer_t *stock_transfer_create_internal(
    any_type_t *line_items,
    char *notes,
    char *source_warehouse_id,
    stock_transfer_status_t *status,
    char *target_warehouse_id,
    char *transfer_date,
    char *transfer_number
    ) {
    stock_transfer_t *stock_transfer_local_var = malloc(sizeof(stock_transfer_t));
    if (!stock_transfer_local_var) {
        return NULL;
    }
    memset(stock_transfer_local_var, 0, sizeof(stock_transfer_t));
    stock_transfer_local_var->_library_owned = 1;
    stock_transfer_local_var->line_items = line_items;
    stock_transfer_local_var->notes = notes;
    stock_transfer_local_var->source_warehouse_id = source_warehouse_id;
    stock_transfer_local_var->status = status;
    stock_transfer_local_var->target_warehouse_id = target_warehouse_id;
    stock_transfer_local_var->transfer_date = transfer_date;
    stock_transfer_local_var->transfer_number = transfer_number;
    return stock_transfer_local_var;
}

__attribute__((deprecated)) stock_transfer_t *stock_transfer_create(
    any_type_t *line_items,
    char *notes,
    char *source_warehouse_id,
    stock_transfer_status_t *status,
    char *target_warehouse_id,
    char *transfer_date,
    char *transfer_number
    ) {
    stock_transfer_t *result = stock_transfer_create_internal (
        line_items,
        notes,
        source_warehouse_id,
        status,
        target_warehouse_id,
        transfer_date,
        transfer_number
        );
    if (!result) {
    }
    return result;
}

void stock_transfer_free(stock_transfer_t *stock_transfer) {
    if(NULL == stock_transfer){
        return ;
    }
    if(stock_transfer->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stock_transfer_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stock_transfer->line_items) {
        _free(stock_transfer->line_items);
        stock_transfer->line_items = NULL;
    }
    if (stock_transfer->notes) {
        free(stock_transfer->notes);
        stock_transfer->notes = NULL;
    }
    if (stock_transfer->source_warehouse_id) {
        free(stock_transfer->source_warehouse_id);
        stock_transfer->source_warehouse_id = NULL;
    }
    if (stock_transfer->status) {
        stock_transfer_status_free(stock_transfer->status);
        stock_transfer->status = NULL;
    }
    if (stock_transfer->target_warehouse_id) {
        free(stock_transfer->target_warehouse_id);
        stock_transfer->target_warehouse_id = NULL;
    }
    if (stock_transfer->transfer_date) {
        free(stock_transfer->transfer_date);
        stock_transfer->transfer_date = NULL;
    }
    if (stock_transfer->transfer_number) {
        free(stock_transfer->transfer_number);
        stock_transfer->transfer_number = NULL;
    }
    free(stock_transfer);
}

cJSON *stock_transfer_convertToJSON(stock_transfer_t *stock_transfer) {
    cJSON *item = cJSON_CreateObject();

    // stock_transfer->line_items
    if (!stock_transfer->line_items) {
        goto fail;
    }
    cJSON *line_items_local_JSON = _convertToJSON(stock_transfer->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // stock_transfer->notes
    if(stock_transfer->notes) {
    if(cJSON_AddStringToObject(item, "notes", stock_transfer->notes) == NULL) {
    goto fail; //String
    }
    }


    // stock_transfer->source_warehouse_id
    if (!stock_transfer->source_warehouse_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sourceWarehouseId", stock_transfer->source_warehouse_id) == NULL) {
    goto fail; //String
    }


    // stock_transfer->status
    if (!stock_transfer->status) {
        goto fail;
    }
    cJSON *status_local_JSON = stock_transfer_status_convertToJSON(stock_transfer->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // stock_transfer->target_warehouse_id
    if (!stock_transfer->target_warehouse_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "targetWarehouseId", stock_transfer->target_warehouse_id) == NULL) {
    goto fail; //String
    }


    // stock_transfer->transfer_date
    if (!stock_transfer->transfer_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "transferDate", stock_transfer->transfer_date) == NULL) {
    goto fail; //Date
    }


    // stock_transfer->transfer_number
    if (!stock_transfer->transfer_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "transferNumber", stock_transfer->transfer_number) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

stock_transfer_t *stock_transfer_parseFromJSON(cJSON *stock_transferJSON){

    stock_transfer_t *stock_transfer_local_var = NULL;

    // define the local variable for stock_transfer->line_items
    _t *line_items_local_nonprim = NULL;

    char *notes_local_str = NULL;

    char *source_warehouse_id_local_str = NULL;

    // define the local variable for stock_transfer->status
    stock_transfer_status_t *status_local_nonprim = NULL;

    char *target_warehouse_id_local_str = NULL;

    char *transfer_date_local_str = NULL;

    char *transfer_number_local_str = NULL;

    // stock_transfer->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(stock_transferJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (!line_items) {
        goto end;
    }

    
    line_items_local_nonprim = _parseFromJSON(line_items); //custom

    // stock_transfer->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(stock_transferJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // stock_transfer->source_warehouse_id
    cJSON *source_warehouse_id = cJSON_GetObjectItemCaseSensitive(stock_transferJSON, "sourceWarehouseId");
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

    // stock_transfer->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(stock_transferJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = stock_transfer_status_parseFromJSON(status); //custom

    // stock_transfer->target_warehouse_id
    cJSON *target_warehouse_id = cJSON_GetObjectItemCaseSensitive(stock_transferJSON, "targetWarehouseId");
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

    // stock_transfer->transfer_date
    cJSON *transfer_date = cJSON_GetObjectItemCaseSensitive(stock_transferJSON, "transferDate");
    if (cJSON_IsNull(transfer_date)) {
        transfer_date = NULL;
    }
    if (!transfer_date) {
        goto end;
    }

    
    if(!cJSON_IsString(transfer_date))
    {
    goto end; //Date
    }

    // stock_transfer->transfer_number
    cJSON *transfer_number = cJSON_GetObjectItemCaseSensitive(stock_transferJSON, "transferNumber");
    if (cJSON_IsNull(transfer_number)) {
        transfer_number = NULL;
    }
    if (!transfer_number) {
        goto end;
    }

    
    if(!cJSON_IsString(transfer_number))
    {
    goto end; //String
    }


    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (source_warehouse_id && !cJSON_IsNull(source_warehouse_id)) source_warehouse_id_local_str = strdup(source_warehouse_id->valuestring);
    if (target_warehouse_id && !cJSON_IsNull(target_warehouse_id)) target_warehouse_id_local_str = strdup(target_warehouse_id->valuestring);
    if (transfer_date) transfer_date_local_str = strdup(transfer_date->valuestring);
    if (transfer_number && !cJSON_IsNull(transfer_number)) transfer_number_local_str = strdup(transfer_number->valuestring);

    stock_transfer_local_var = stock_transfer_create_internal (
        line_items_local_nonprim,
        notes_local_str,
        source_warehouse_id_local_str,
        status_local_nonprim,
        target_warehouse_id_local_str,
        transfer_date_local_str,
        transfer_number_local_str
        );

    if (!stock_transfer_local_var) {
        goto end;
    }

    return stock_transfer_local_var;
end:
    if (line_items_local_nonprim) {
        _free(line_items_local_nonprim);
        line_items_local_nonprim = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (source_warehouse_id_local_str) {
        free(source_warehouse_id_local_str);
        source_warehouse_id_local_str = NULL;
    }
    if (status_local_nonprim) {
        stock_transfer_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (target_warehouse_id_local_str) {
        free(target_warehouse_id_local_str);
        target_warehouse_id_local_str = NULL;
    }
    if (transfer_date_local_str) {
        free(transfer_date_local_str);
        transfer_date_local_str = NULL;
    }
    if (transfer_number_local_str) {
        free(transfer_number_local_str);
        transfer_number_local_str = NULL;
    }
    return NULL;

}
