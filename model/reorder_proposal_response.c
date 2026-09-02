#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reorder_proposal_response.h"



static reorder_proposal_response_t *reorder_proposal_response_create_internal(
    char *generated_at,
    list_t *lines,
    long *total_suggested_quantity
    ) {
    reorder_proposal_response_t *reorder_proposal_response_local_var = malloc(sizeof(reorder_proposal_response_t));
    if (!reorder_proposal_response_local_var) {
        return NULL;
    }
    memset(reorder_proposal_response_local_var, 0, sizeof(reorder_proposal_response_t));
    reorder_proposal_response_local_var->_library_owned = 1;
    reorder_proposal_response_local_var->generated_at = generated_at;
    reorder_proposal_response_local_var->lines = lines;
    reorder_proposal_response_local_var->total_suggested_quantity = total_suggested_quantity;
    return reorder_proposal_response_local_var;
}

__attribute__((deprecated)) reorder_proposal_response_t *reorder_proposal_response_create(
    char *generated_at,
    list_t *lines,
    long *total_suggested_quantity
    ) {
    long *total_suggested_quantity_copy = NULL;
    if (total_suggested_quantity) {
        total_suggested_quantity_copy = malloc(sizeof(long));
        if (total_suggested_quantity_copy) *total_suggested_quantity_copy = *total_suggested_quantity;
    }
    reorder_proposal_response_t *result = reorder_proposal_response_create_internal (
        generated_at,
        lines,
        total_suggested_quantity_copy
        );
    if (!result) {
        free(total_suggested_quantity_copy);
    }
    return result;
}

void reorder_proposal_response_free(reorder_proposal_response_t *reorder_proposal_response) {
    if(NULL == reorder_proposal_response){
        return ;
    }
    if(reorder_proposal_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reorder_proposal_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reorder_proposal_response->generated_at) {
        free(reorder_proposal_response->generated_at);
        reorder_proposal_response->generated_at = NULL;
    }
    if (reorder_proposal_response->lines) {
        list_ForEach(listEntry, reorder_proposal_response->lines) {
            reorder_proposal_line_free(listEntry->data);
        }
        list_freeList(reorder_proposal_response->lines);
        reorder_proposal_response->lines = NULL;
    }
    if (reorder_proposal_response->total_suggested_quantity) {
        free(reorder_proposal_response->total_suggested_quantity);
        reorder_proposal_response->total_suggested_quantity = NULL;
    }
    free(reorder_proposal_response);
}

cJSON *reorder_proposal_response_convertToJSON(reorder_proposal_response_t *reorder_proposal_response) {
    cJSON *item = cJSON_CreateObject();

    // reorder_proposal_response->generated_at
    if (!reorder_proposal_response->generated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "generatedAt", reorder_proposal_response->generated_at) == NULL) {
    goto fail; //Date-Time
    }


    // reorder_proposal_response->lines
    if (!reorder_proposal_response->lines) {
        goto fail;
    }
    cJSON *lines = cJSON_AddArrayToObject(item, "lines");
    if(lines == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *linesListEntry;
    if (reorder_proposal_response->lines) {
    list_ForEach(linesListEntry, reorder_proposal_response->lines) {
    cJSON *itemLocal = reorder_proposal_line_convertToJSON(linesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(lines, itemLocal);
    }
    }


    // reorder_proposal_response->total_suggested_quantity
    if (!reorder_proposal_response->total_suggested_quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "totalSuggestedQuantity", *reorder_proposal_response->total_suggested_quantity) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reorder_proposal_response_t *reorder_proposal_response_parseFromJSON(cJSON *reorder_proposal_responseJSON){

    reorder_proposal_response_t *reorder_proposal_response_local_var = NULL;

    char *generated_at_local_str = NULL;

    // define the local list for reorder_proposal_response->lines
    list_t *linesList = NULL;

    // define the local variable for reorder_proposal_response->total_suggested_quantity
    long *total_suggested_quantity_local_var = NULL;

    // reorder_proposal_response->generated_at
    cJSON *generated_at = cJSON_GetObjectItemCaseSensitive(reorder_proposal_responseJSON, "generatedAt");
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

    // reorder_proposal_response->lines
    cJSON *lines = cJSON_GetObjectItemCaseSensitive(reorder_proposal_responseJSON, "lines");
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
        reorder_proposal_line_t *linesItem = reorder_proposal_line_parseFromJSON(lines_local_nonprimitive);

        list_addElement(linesList, linesItem);
    }

    // reorder_proposal_response->total_suggested_quantity
    cJSON *total_suggested_quantity = cJSON_GetObjectItemCaseSensitive(reorder_proposal_responseJSON, "totalSuggestedQuantity");
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

    reorder_proposal_response_local_var = reorder_proposal_response_create_internal (
        generated_at_local_str,
        linesList,
        total_suggested_quantity_local_var
        );

    if (!reorder_proposal_response_local_var) {
        goto end;
    }

    return reorder_proposal_response_local_var;
end:
    if (generated_at_local_str) {
        free(generated_at_local_str);
        generated_at_local_str = NULL;
    }
    if (linesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, linesList) {
            reorder_proposal_line_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(linesList);
        linesList = NULL;
    }
    if (total_suggested_quantity_local_var) {
        free(total_suggested_quantity_local_var);
        total_suggested_quantity_local_var = NULL;
    }
    return NULL;

}
