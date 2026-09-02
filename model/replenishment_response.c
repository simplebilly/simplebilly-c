#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "replenishment_response.h"



static replenishment_response_t *replenishment_response_create_internal(
    char *generated_at,
    list_t *lines,
    char *target_warehouse_id,
    long *total_suggested_quantity
    ) {
    replenishment_response_t *replenishment_response_local_var = malloc(sizeof(replenishment_response_t));
    if (!replenishment_response_local_var) {
        return NULL;
    }
    memset(replenishment_response_local_var, 0, sizeof(replenishment_response_t));
    replenishment_response_local_var->_library_owned = 1;
    replenishment_response_local_var->generated_at = generated_at;
    replenishment_response_local_var->lines = lines;
    replenishment_response_local_var->target_warehouse_id = target_warehouse_id;
    replenishment_response_local_var->total_suggested_quantity = total_suggested_quantity;
    return replenishment_response_local_var;
}

__attribute__((deprecated)) replenishment_response_t *replenishment_response_create(
    char *generated_at,
    list_t *lines,
    char *target_warehouse_id,
    long *total_suggested_quantity
    ) {
    long *total_suggested_quantity_copy = NULL;
    if (total_suggested_quantity) {
        total_suggested_quantity_copy = malloc(sizeof(long));
        if (total_suggested_quantity_copy) *total_suggested_quantity_copy = *total_suggested_quantity;
    }
    replenishment_response_t *result = replenishment_response_create_internal (
        generated_at,
        lines,
        target_warehouse_id,
        total_suggested_quantity_copy
        );
    if (!result) {
        free(total_suggested_quantity_copy);
    }
    return result;
}

void replenishment_response_free(replenishment_response_t *replenishment_response) {
    if(NULL == replenishment_response){
        return ;
    }
    if(replenishment_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "replenishment_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (replenishment_response->generated_at) {
        free(replenishment_response->generated_at);
        replenishment_response->generated_at = NULL;
    }
    if (replenishment_response->lines) {
        list_ForEach(listEntry, replenishment_response->lines) {
            replenishment_suggestion_line_free(listEntry->data);
        }
        list_freeList(replenishment_response->lines);
        replenishment_response->lines = NULL;
    }
    if (replenishment_response->target_warehouse_id) {
        free(replenishment_response->target_warehouse_id);
        replenishment_response->target_warehouse_id = NULL;
    }
    if (replenishment_response->total_suggested_quantity) {
        free(replenishment_response->total_suggested_quantity);
        replenishment_response->total_suggested_quantity = NULL;
    }
    free(replenishment_response);
}

cJSON *replenishment_response_convertToJSON(replenishment_response_t *replenishment_response) {
    cJSON *item = cJSON_CreateObject();

    // replenishment_response->generated_at
    if (!replenishment_response->generated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "generatedAt", replenishment_response->generated_at) == NULL) {
    goto fail; //Date-Time
    }


    // replenishment_response->lines
    if (!replenishment_response->lines) {
        goto fail;
    }
    cJSON *lines = cJSON_AddArrayToObject(item, "lines");
    if(lines == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *linesListEntry;
    if (replenishment_response->lines) {
    list_ForEach(linesListEntry, replenishment_response->lines) {
    cJSON *itemLocal = replenishment_suggestion_line_convertToJSON(linesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(lines, itemLocal);
    }
    }


    // replenishment_response->target_warehouse_id
    if (!replenishment_response->target_warehouse_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "targetWarehouseId", replenishment_response->target_warehouse_id) == NULL) {
    goto fail; //String
    }


    // replenishment_response->total_suggested_quantity
    if (!replenishment_response->total_suggested_quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "totalSuggestedQuantity", *replenishment_response->total_suggested_quantity) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

replenishment_response_t *replenishment_response_parseFromJSON(cJSON *replenishment_responseJSON){

    replenishment_response_t *replenishment_response_local_var = NULL;

    char *generated_at_local_str = NULL;

    // define the local list for replenishment_response->lines
    list_t *linesList = NULL;

    char *target_warehouse_id_local_str = NULL;

    // define the local variable for replenishment_response->total_suggested_quantity
    long *total_suggested_quantity_local_var = NULL;

    // replenishment_response->generated_at
    cJSON *generated_at = cJSON_GetObjectItemCaseSensitive(replenishment_responseJSON, "generatedAt");
    if (cJSON_IsNull(generated_at)) {
        generated_at = NULL;
    }
    if (!generated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(generated_at) && !cJSON_IsNull(generated_at))
    {
    goto end; //DateTime
    }

    // replenishment_response->lines
    cJSON *lines = cJSON_GetObjectItemCaseSensitive(replenishment_responseJSON, "lines");
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
        replenishment_suggestion_line_t *linesItem = replenishment_suggestion_line_parseFromJSON(lines_local_nonprimitive);

        list_addElement(linesList, linesItem);
    }

    // replenishment_response->target_warehouse_id
    cJSON *target_warehouse_id = cJSON_GetObjectItemCaseSensitive(replenishment_responseJSON, "targetWarehouseId");
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

    // replenishment_response->total_suggested_quantity
    cJSON *total_suggested_quantity = cJSON_GetObjectItemCaseSensitive(replenishment_responseJSON, "totalSuggestedQuantity");
    if (cJSON_IsNull(total_suggested_quantity)) {
        total_suggested_quantity = NULL;
    }
    if (!total_suggested_quantity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_suggested_quantity))
    {
    goto end; //Numeric
    }
    total_suggested_quantity_local_var = malloc(sizeof(long));
    if(!total_suggested_quantity_local_var)
    {
        goto end;
    }
    *total_suggested_quantity_local_var = total_suggested_quantity->valuedouble;


    if (generated_at && !cJSON_IsNull(generated_at)) generated_at_local_str = strdup(generated_at->valuestring);
    if (target_warehouse_id && !cJSON_IsNull(target_warehouse_id)) target_warehouse_id_local_str = strdup(target_warehouse_id->valuestring);

    replenishment_response_local_var = replenishment_response_create_internal (
        generated_at_local_str,
        linesList,
        target_warehouse_id_local_str,
        total_suggested_quantity_local_var
        );

    if (!replenishment_response_local_var) {
        goto end;
    }

    return replenishment_response_local_var;
end:
    if (generated_at_local_str) {
        free(generated_at_local_str);
        generated_at_local_str = NULL;
    }
    if (linesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, linesList) {
            replenishment_suggestion_line_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(linesList);
        linesList = NULL;
    }
    if (target_warehouse_id_local_str) {
        free(target_warehouse_id_local_str);
        target_warehouse_id_local_str = NULL;
    }
    if (total_suggested_quantity_local_var) {
        free(total_suggested_quantity_local_var);
        total_suggested_quantity_local_var = NULL;
    }
    return NULL;

}
