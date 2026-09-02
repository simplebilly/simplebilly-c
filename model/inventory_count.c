#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inventory_count.h"



static inventory_count_t *inventory_count_create_internal(
    char *count_date,
    char *count_number,
    any_type_t *line_items,
    char *notes,
    inventory_count_status_t *status,
    char *warehouse_id
    ) {
    inventory_count_t *inventory_count_local_var = malloc(sizeof(inventory_count_t));
    if (!inventory_count_local_var) {
        return NULL;
    }
    memset(inventory_count_local_var, 0, sizeof(inventory_count_t));
    inventory_count_local_var->_library_owned = 1;
    inventory_count_local_var->count_date = count_date;
    inventory_count_local_var->count_number = count_number;
    inventory_count_local_var->line_items = line_items;
    inventory_count_local_var->notes = notes;
    inventory_count_local_var->status = status;
    inventory_count_local_var->warehouse_id = warehouse_id;
    return inventory_count_local_var;
}

__attribute__((deprecated)) inventory_count_t *inventory_count_create(
    char *count_date,
    char *count_number,
    any_type_t *line_items,
    char *notes,
    inventory_count_status_t *status,
    char *warehouse_id
    ) {
    inventory_count_t *result = inventory_count_create_internal (
        count_date,
        count_number,
        line_items,
        notes,
        status,
        warehouse_id
        );
    if (!result) {
    }
    return result;
}

void inventory_count_free(inventory_count_t *inventory_count) {
    if(NULL == inventory_count){
        return ;
    }
    if(inventory_count->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inventory_count_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inventory_count->count_date) {
        free(inventory_count->count_date);
        inventory_count->count_date = NULL;
    }
    if (inventory_count->count_number) {
        free(inventory_count->count_number);
        inventory_count->count_number = NULL;
    }
    if (inventory_count->line_items) {
        _free(inventory_count->line_items);
        inventory_count->line_items = NULL;
    }
    if (inventory_count->notes) {
        free(inventory_count->notes);
        inventory_count->notes = NULL;
    }
    if (inventory_count->status) {
        inventory_count_status_free(inventory_count->status);
        inventory_count->status = NULL;
    }
    if (inventory_count->warehouse_id) {
        free(inventory_count->warehouse_id);
        inventory_count->warehouse_id = NULL;
    }
    free(inventory_count);
}

cJSON *inventory_count_convertToJSON(inventory_count_t *inventory_count) {
    cJSON *item = cJSON_CreateObject();

    // inventory_count->count_date
    if (!inventory_count->count_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "countDate", inventory_count->count_date) == NULL) {
    goto fail; //Date
    }


    // inventory_count->count_number
    if (!inventory_count->count_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "countNumber", inventory_count->count_number) == NULL) {
    goto fail; //String
    }


    // inventory_count->line_items
    if (!inventory_count->line_items) {
        goto fail;
    }
    cJSON *line_items_local_JSON = _convertToJSON(inventory_count->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // inventory_count->notes
    if(inventory_count->notes) {
    if(cJSON_AddStringToObject(item, "notes", inventory_count->notes) == NULL) {
    goto fail; //String
    }
    }


    // inventory_count->status
    if (!inventory_count->status) {
        goto fail;
    }
    cJSON *status_local_JSON = inventory_count_status_convertToJSON(inventory_count->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // inventory_count->warehouse_id
    if (!inventory_count->warehouse_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "warehouseId", inventory_count->warehouse_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

inventory_count_t *inventory_count_parseFromJSON(cJSON *inventory_countJSON){

    inventory_count_t *inventory_count_local_var = NULL;

    char *count_date_local_str = NULL;

    char *count_number_local_str = NULL;

    // define the local variable for inventory_count->line_items
    _t *line_items_local_nonprim = NULL;

    char *notes_local_str = NULL;

    // define the local variable for inventory_count->status
    inventory_count_status_t *status_local_nonprim = NULL;

    char *warehouse_id_local_str = NULL;

    // inventory_count->count_date
    cJSON *count_date = cJSON_GetObjectItemCaseSensitive(inventory_countJSON, "countDate");
    if (cJSON_IsNull(count_date)) {
        count_date = NULL;
    }
    if (!count_date) {
        goto end;
    }

    
    if(!cJSON_IsString(count_date))
    {
    goto end; //Date
    }

    // inventory_count->count_number
    cJSON *count_number = cJSON_GetObjectItemCaseSensitive(inventory_countJSON, "countNumber");
    if (cJSON_IsNull(count_number)) {
        count_number = NULL;
    }
    if (!count_number) {
        goto end;
    }

    
    if(!cJSON_IsString(count_number))
    {
    goto end; //String
    }

    // inventory_count->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(inventory_countJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (!line_items) {
        goto end;
    }

    
    line_items_local_nonprim = _parseFromJSON(line_items); //custom

    // inventory_count->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(inventory_countJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // inventory_count->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(inventory_countJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = inventory_count_status_parseFromJSON(status); //custom

    // inventory_count->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(inventory_countJSON, "warehouseId");
    if (cJSON_IsNull(warehouse_id)) {
        warehouse_id = NULL;
    }
    if (!warehouse_id) {
        goto end;
    }

    
    if(!cJSON_IsString(warehouse_id))
    {
    goto end; //String
    }


    if (count_date) count_date_local_str = strdup(count_date->valuestring);
    if (count_number && !cJSON_IsNull(count_number)) count_number_local_str = strdup(count_number->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (warehouse_id && !cJSON_IsNull(warehouse_id)) warehouse_id_local_str = strdup(warehouse_id->valuestring);

    inventory_count_local_var = inventory_count_create_internal (
        count_date_local_str,
        count_number_local_str,
        line_items_local_nonprim,
        notes_local_str,
        status_local_nonprim,
        warehouse_id_local_str
        );

    if (!inventory_count_local_var) {
        goto end;
    }

    return inventory_count_local_var;
end:
    if (count_date_local_str) {
        free(count_date_local_str);
        count_date_local_str = NULL;
    }
    if (count_number_local_str) {
        free(count_number_local_str);
        count_number_local_str = NULL;
    }
    if (line_items_local_nonprim) {
        _free(line_items_local_nonprim);
        line_items_local_nonprim = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (status_local_nonprim) {
        inventory_count_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (warehouse_id_local_str) {
        free(warehouse_id_local_str);
        warehouse_id_local_str = NULL;
    }
    return NULL;

}
