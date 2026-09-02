#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "return_warehouse_summary.h"



static return_warehouse_summary_t *return_warehouse_summary_create_internal(
    long *items_restocked,
    long *items_scrapped,
    long *returns,
    char *warehouse_id
    ) {
    return_warehouse_summary_t *return_warehouse_summary_local_var = malloc(sizeof(return_warehouse_summary_t));
    if (!return_warehouse_summary_local_var) {
        return NULL;
    }
    memset(return_warehouse_summary_local_var, 0, sizeof(return_warehouse_summary_t));
    return_warehouse_summary_local_var->_library_owned = 1;
    return_warehouse_summary_local_var->items_restocked = items_restocked;
    return_warehouse_summary_local_var->items_scrapped = items_scrapped;
    return_warehouse_summary_local_var->returns = returns;
    return_warehouse_summary_local_var->warehouse_id = warehouse_id;
    return return_warehouse_summary_local_var;
}

__attribute__((deprecated)) return_warehouse_summary_t *return_warehouse_summary_create(
    long *items_restocked,
    long *items_scrapped,
    long *returns,
    char *warehouse_id
    ) {
    long *items_restocked_copy = NULL;
    if (items_restocked) {
        items_restocked_copy = malloc(sizeof(long));
        if (items_restocked_copy) *items_restocked_copy = *items_restocked;
    }
    long *items_scrapped_copy = NULL;
    if (items_scrapped) {
        items_scrapped_copy = malloc(sizeof(long));
        if (items_scrapped_copy) *items_scrapped_copy = *items_scrapped;
    }
    long *returns_copy = NULL;
    if (returns) {
        returns_copy = malloc(sizeof(long));
        if (returns_copy) *returns_copy = *returns;
    }
    return_warehouse_summary_t *result = return_warehouse_summary_create_internal (
        items_restocked_copy,
        items_scrapped_copy,
        returns_copy,
        warehouse_id
        );
    if (!result) {
        free(items_restocked_copy);
        free(items_scrapped_copy);
        free(returns_copy);
    }
    return result;
}

void return_warehouse_summary_free(return_warehouse_summary_t *return_warehouse_summary) {
    if(NULL == return_warehouse_summary){
        return ;
    }
    if(return_warehouse_summary->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "return_warehouse_summary_free");
        return ;
    }
    listEntry_t *listEntry;
    if (return_warehouse_summary->items_restocked) {
        free(return_warehouse_summary->items_restocked);
        return_warehouse_summary->items_restocked = NULL;
    }
    if (return_warehouse_summary->items_scrapped) {
        free(return_warehouse_summary->items_scrapped);
        return_warehouse_summary->items_scrapped = NULL;
    }
    if (return_warehouse_summary->returns) {
        free(return_warehouse_summary->returns);
        return_warehouse_summary->returns = NULL;
    }
    if (return_warehouse_summary->warehouse_id) {
        free(return_warehouse_summary->warehouse_id);
        return_warehouse_summary->warehouse_id = NULL;
    }
    free(return_warehouse_summary);
}

cJSON *return_warehouse_summary_convertToJSON(return_warehouse_summary_t *return_warehouse_summary) {
    cJSON *item = cJSON_CreateObject();

    // return_warehouse_summary->items_restocked
    if (!return_warehouse_summary->items_restocked) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "itemsRestocked", *return_warehouse_summary->items_restocked) == NULL) {
    goto fail; //Numeric
    }


    // return_warehouse_summary->items_scrapped
    if (!return_warehouse_summary->items_scrapped) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "itemsScrapped", *return_warehouse_summary->items_scrapped) == NULL) {
    goto fail; //Numeric
    }


    // return_warehouse_summary->returns
    if (!return_warehouse_summary->returns) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "returns", *return_warehouse_summary->returns) == NULL) {
    goto fail; //Numeric
    }


    // return_warehouse_summary->warehouse_id
    if(return_warehouse_summary->warehouse_id) {
    if(cJSON_AddStringToObject(item, "warehouseId", return_warehouse_summary->warehouse_id) == NULL) {
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

return_warehouse_summary_t *return_warehouse_summary_parseFromJSON(cJSON *return_warehouse_summaryJSON){

    return_warehouse_summary_t *return_warehouse_summary_local_var = NULL;

    // define the local variable for return_warehouse_summary->items_restocked
    long *items_restocked_local_var = NULL;

    // define the local variable for return_warehouse_summary->items_scrapped
    long *items_scrapped_local_var = NULL;

    // define the local variable for return_warehouse_summary->returns
    long *returns_local_var = NULL;

    char *warehouse_id_local_str = NULL;

    // return_warehouse_summary->items_restocked
    cJSON *items_restocked = cJSON_GetObjectItemCaseSensitive(return_warehouse_summaryJSON, "itemsRestocked");
    if (cJSON_IsNull(items_restocked)) {
        items_restocked = NULL;
    }
    if (!items_restocked) {
        goto end;
    }

    
    if(!cJSON_IsNumber(items_restocked))
    {
    goto end; //Numeric
    }
    items_restocked_local_var = malloc(sizeof(long));
    if(!items_restocked_local_var)
    {
        goto end;
    }
    *items_restocked_local_var = items_restocked->valuedouble;

    // return_warehouse_summary->items_scrapped
    cJSON *items_scrapped = cJSON_GetObjectItemCaseSensitive(return_warehouse_summaryJSON, "itemsScrapped");
    if (cJSON_IsNull(items_scrapped)) {
        items_scrapped = NULL;
    }
    if (!items_scrapped) {
        goto end;
    }

    
    if(!cJSON_IsNumber(items_scrapped))
    {
    goto end; //Numeric
    }
    items_scrapped_local_var = malloc(sizeof(long));
    if(!items_scrapped_local_var)
    {
        goto end;
    }
    *items_scrapped_local_var = items_scrapped->valuedouble;

    // return_warehouse_summary->returns
    cJSON *returns = cJSON_GetObjectItemCaseSensitive(return_warehouse_summaryJSON, "returns");
    if (cJSON_IsNull(returns)) {
        returns = NULL;
    }
    if (!returns) {
        goto end;
    }

    
    if(!cJSON_IsNumber(returns))
    {
    goto end; //Numeric
    }
    returns_local_var = malloc(sizeof(long));
    if(!returns_local_var)
    {
        goto end;
    }
    *returns_local_var = returns->valuedouble;

    // return_warehouse_summary->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(return_warehouse_summaryJSON, "warehouseId");
    if (cJSON_IsNull(warehouse_id)) {
        warehouse_id = NULL;
    }
    if (warehouse_id) { 
    if(!cJSON_IsString(warehouse_id) && !cJSON_IsNull(warehouse_id))
    {
    goto end; //String
    }
    }


    if (warehouse_id && !cJSON_IsNull(warehouse_id)) warehouse_id_local_str = strdup(warehouse_id->valuestring);

    return_warehouse_summary_local_var = return_warehouse_summary_create_internal (
        items_restocked_local_var,
        items_scrapped_local_var,
        returns_local_var,
        warehouse_id_local_str
        );

    if (!return_warehouse_summary_local_var) {
        goto end;
    }

    return return_warehouse_summary_local_var;
end:
    if (items_restocked_local_var) {
        free(items_restocked_local_var);
        items_restocked_local_var = NULL;
    }
    if (items_scrapped_local_var) {
        free(items_scrapped_local_var);
        items_scrapped_local_var = NULL;
    }
    if (returns_local_var) {
        free(returns_local_var);
        returns_local_var = NULL;
    }
    if (warehouse_id_local_str) {
        free(warehouse_id_local_str);
        warehouse_id_local_str = NULL;
    }
    return NULL;

}
