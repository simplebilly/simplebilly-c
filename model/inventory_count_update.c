#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inventory_count_update.h"



static inventory_count_update_t *inventory_count_update_create_internal(
    char *count_date,
    char *count_number,
    any_type_t *line_items,
    char *notes,
    inventory_count_status_t *status,
    char *warehouse_id
    ) {
    inventory_count_update_t *inventory_count_update_local_var = malloc(sizeof(inventory_count_update_t));
    if (!inventory_count_update_local_var) {
        return NULL;
    }
    memset(inventory_count_update_local_var, 0, sizeof(inventory_count_update_t));
    inventory_count_update_local_var->_library_owned = 1;
    inventory_count_update_local_var->count_date = count_date;
    inventory_count_update_local_var->count_number = count_number;
    inventory_count_update_local_var->line_items = line_items;
    inventory_count_update_local_var->notes = notes;
    inventory_count_update_local_var->status = status;
    inventory_count_update_local_var->warehouse_id = warehouse_id;
    return inventory_count_update_local_var;
}

__attribute__((deprecated)) inventory_count_update_t *inventory_count_update_create(
    char *count_date,
    char *count_number,
    any_type_t *line_items,
    char *notes,
    inventory_count_status_t *status,
    char *warehouse_id
    ) {
    inventory_count_update_t *result = inventory_count_update_create_internal (
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

void inventory_count_update_free(inventory_count_update_t *inventory_count_update) {
    if(NULL == inventory_count_update){
        return ;
    }
    if(inventory_count_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inventory_count_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inventory_count_update->count_date) {
        free(inventory_count_update->count_date);
        inventory_count_update->count_date = NULL;
    }
    if (inventory_count_update->count_number) {
        free(inventory_count_update->count_number);
        inventory_count_update->count_number = NULL;
    }
    if (inventory_count_update->line_items) {
        _free(inventory_count_update->line_items);
        inventory_count_update->line_items = NULL;
    }
    if (inventory_count_update->notes) {
        free(inventory_count_update->notes);
        inventory_count_update->notes = NULL;
    }
    if (inventory_count_update->status) {
        inventory_count_status_free(inventory_count_update->status);
        inventory_count_update->status = NULL;
    }
    if (inventory_count_update->warehouse_id) {
        free(inventory_count_update->warehouse_id);
        inventory_count_update->warehouse_id = NULL;
    }
    free(inventory_count_update);
}

cJSON *inventory_count_update_convertToJSON(inventory_count_update_t *inventory_count_update) {
    cJSON *item = cJSON_CreateObject();

    // inventory_count_update->count_date
    if(inventory_count_update->count_date) {
    if(cJSON_AddStringToObject(item, "countDate", inventory_count_update->count_date) == NULL) {
    goto fail; //Date
    }
    }


    // inventory_count_update->count_number
    if(inventory_count_update->count_number) {
    if(cJSON_AddStringToObject(item, "countNumber", inventory_count_update->count_number) == NULL) {
    goto fail; //String
    }
    }


    // inventory_count_update->line_items
    if(inventory_count_update->line_items) {
    cJSON *line_items_local_JSON = _convertToJSON(inventory_count_update->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // inventory_count_update->notes
    if(inventory_count_update->notes) {
    if(cJSON_AddStringToObject(item, "notes", inventory_count_update->notes) == NULL) {
    goto fail; //String
    }
    }


    // inventory_count_update->status
    if(inventory_count_update->status) {
    cJSON *status_local_JSON = inventory_count_status_convertToJSON(inventory_count_update->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // inventory_count_update->warehouse_id
    if(inventory_count_update->warehouse_id) {
    if(cJSON_AddStringToObject(item, "warehouseId", inventory_count_update->warehouse_id) == NULL) {
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

inventory_count_update_t *inventory_count_update_parseFromJSON(cJSON *inventory_count_updateJSON){

    inventory_count_update_t *inventory_count_update_local_var = NULL;

    char *count_date_local_str = NULL;

    char *count_number_local_str = NULL;

    // define the local variable for inventory_count_update->line_items
    _t *line_items_local_nonprim = NULL;

    char *notes_local_str = NULL;

    // define the local variable for inventory_count_update->status
    inventory_count_status_t *status_local_nonprim = NULL;

    char *warehouse_id_local_str = NULL;

    // inventory_count_update->count_date
    cJSON *count_date = cJSON_GetObjectItemCaseSensitive(inventory_count_updateJSON, "countDate");
    if (cJSON_IsNull(count_date)) {
        count_date = NULL;
    }
    if (count_date) { 
    if(!cJSON_IsString(count_date))
    {
    goto end; //Date
    }
    }

    // inventory_count_update->count_number
    cJSON *count_number = cJSON_GetObjectItemCaseSensitive(inventory_count_updateJSON, "countNumber");
    if (cJSON_IsNull(count_number)) {
        count_number = NULL;
    }
    if (count_number) { 
    if(!cJSON_IsString(count_number) && !cJSON_IsNull(count_number))
    {
    goto end; //String
    }
    }

    // inventory_count_update->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(inventory_count_updateJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (line_items) { 
    line_items_local_nonprim = _parseFromJSON(line_items); //custom
    }

    // inventory_count_update->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(inventory_count_updateJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // inventory_count_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(inventory_count_updateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = inventory_count_status_parseFromJSON(status); //custom
    }

    // inventory_count_update->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(inventory_count_updateJSON, "warehouseId");
    if (cJSON_IsNull(warehouse_id)) {
        warehouse_id = NULL;
    }
    if (warehouse_id) { 
    if(!cJSON_IsString(warehouse_id) && !cJSON_IsNull(warehouse_id))
    {
    goto end; //String
    }
    }


    if (count_date) count_date_local_str = strdup(count_date->valuestring);
    if (count_number && !cJSON_IsNull(count_number)) count_number_local_str = strdup(count_number->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (warehouse_id && !cJSON_IsNull(warehouse_id)) warehouse_id_local_str = strdup(warehouse_id->valuestring);

    inventory_count_update_local_var = inventory_count_update_create_internal (
        count_date_local_str,
        count_number_local_str,
        line_items ? line_items_local_nonprim : NULL,
        notes_local_str,
        status ? status_local_nonprim : NULL,
        warehouse_id_local_str
        );

    if (!inventory_count_update_local_var) {
        goto end;
    }

    return inventory_count_update_local_var;
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
