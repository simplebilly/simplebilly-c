#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bwa_revenue.h"



static bwa_revenue_t *bwa_revenue_create_internal(
    list_t *revenue_breakdown,
    char *total_revenue
    ) {
    bwa_revenue_t *bwa_revenue_local_var = malloc(sizeof(bwa_revenue_t));
    if (!bwa_revenue_local_var) {
        return NULL;
    }
    memset(bwa_revenue_local_var, 0, sizeof(bwa_revenue_t));
    bwa_revenue_local_var->_library_owned = 1;
    bwa_revenue_local_var->revenue_breakdown = revenue_breakdown;
    bwa_revenue_local_var->total_revenue = total_revenue;
    return bwa_revenue_local_var;
}

__attribute__((deprecated)) bwa_revenue_t *bwa_revenue_create(
    list_t *revenue_breakdown,
    char *total_revenue
    ) {
    bwa_revenue_t *result = bwa_revenue_create_internal (
        revenue_breakdown,
        total_revenue
        );
    if (!result) {
    }
    return result;
}

void bwa_revenue_free(bwa_revenue_t *bwa_revenue) {
    if(NULL == bwa_revenue){
        return ;
    }
    if(bwa_revenue->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bwa_revenue_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bwa_revenue->revenue_breakdown) {
        list_ForEach(listEntry, bwa_revenue->revenue_breakdown) {
            revenue_item_free(listEntry->data);
        }
        list_freeList(bwa_revenue->revenue_breakdown);
        bwa_revenue->revenue_breakdown = NULL;
    }
    if (bwa_revenue->total_revenue) {
        free(bwa_revenue->total_revenue);
        bwa_revenue->total_revenue = NULL;
    }
    free(bwa_revenue);
}

cJSON *bwa_revenue_convertToJSON(bwa_revenue_t *bwa_revenue) {
    cJSON *item = cJSON_CreateObject();

    // bwa_revenue->revenue_breakdown
    if (!bwa_revenue->revenue_breakdown) {
        goto fail;
    }
    cJSON *revenue_breakdown = cJSON_AddArrayToObject(item, "revenue_breakdown");
    if(revenue_breakdown == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *revenue_breakdownListEntry;
    if (bwa_revenue->revenue_breakdown) {
    list_ForEach(revenue_breakdownListEntry, bwa_revenue->revenue_breakdown) {
    cJSON *itemLocal = revenue_item_convertToJSON(revenue_breakdownListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(revenue_breakdown, itemLocal);
    }
    }


    // bwa_revenue->total_revenue
    if (!bwa_revenue->total_revenue) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_revenue", bwa_revenue->total_revenue) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bwa_revenue_t *bwa_revenue_parseFromJSON(cJSON *bwa_revenueJSON){

    bwa_revenue_t *bwa_revenue_local_var = NULL;

    // define the local list for bwa_revenue->revenue_breakdown
    list_t *revenue_breakdownList = NULL;

    char *total_revenue_local_str = NULL;

    // bwa_revenue->revenue_breakdown
    cJSON *revenue_breakdown = cJSON_GetObjectItemCaseSensitive(bwa_revenueJSON, "revenue_breakdown");
    if (cJSON_IsNull(revenue_breakdown)) {
        revenue_breakdown = NULL;
    }
    if (!revenue_breakdown) {
        goto end;
    }

    
    cJSON *revenue_breakdown_local_nonprimitive = NULL;
    if(!cJSON_IsArray(revenue_breakdown)){
        goto end; //nonprimitive container
    }

    revenue_breakdownList = list_createList();

    cJSON_ArrayForEach(revenue_breakdown_local_nonprimitive,revenue_breakdown )
    {
        if(!cJSON_IsObject(revenue_breakdown_local_nonprimitive)){
            goto end;
        }
        revenue_item_t *revenue_breakdownItem = revenue_item_parseFromJSON(revenue_breakdown_local_nonprimitive);

        list_addElement(revenue_breakdownList, revenue_breakdownItem);
    }

    // bwa_revenue->total_revenue
    cJSON *total_revenue = cJSON_GetObjectItemCaseSensitive(bwa_revenueJSON, "total_revenue");
    if (cJSON_IsNull(total_revenue)) {
        total_revenue = NULL;
    }
    if (!total_revenue) {
        goto end;
    }

    
    if(!cJSON_IsString(total_revenue))
    {
    goto end; //String
    }


    if (total_revenue && !cJSON_IsNull(total_revenue)) total_revenue_local_str = strdup(total_revenue->valuestring);

    bwa_revenue_local_var = bwa_revenue_create_internal (
        revenue_breakdownList,
        total_revenue_local_str
        );

    if (!bwa_revenue_local_var) {
        goto end;
    }

    return bwa_revenue_local_var;
end:
    if (revenue_breakdownList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, revenue_breakdownList) {
            revenue_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(revenue_breakdownList);
        revenue_breakdownList = NULL;
    }
    if (total_revenue_local_str) {
        free(total_revenue_local_str);
        total_revenue_local_str = NULL;
    }
    return NULL;

}
