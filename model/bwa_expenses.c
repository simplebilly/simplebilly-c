#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bwa_expenses.h"



static bwa_expenses_t *bwa_expenses_create_internal(
    list_t *expense_breakdown,
    char *total_expenses
    ) {
    bwa_expenses_t *bwa_expenses_local_var = malloc(sizeof(bwa_expenses_t));
    if (!bwa_expenses_local_var) {
        return NULL;
    }
    memset(bwa_expenses_local_var, 0, sizeof(bwa_expenses_t));
    bwa_expenses_local_var->_library_owned = 1;
    bwa_expenses_local_var->expense_breakdown = expense_breakdown;
    bwa_expenses_local_var->total_expenses = total_expenses;
    return bwa_expenses_local_var;
}

__attribute__((deprecated)) bwa_expenses_t *bwa_expenses_create(
    list_t *expense_breakdown,
    char *total_expenses
    ) {
    bwa_expenses_t *result = bwa_expenses_create_internal (
        expense_breakdown,
        total_expenses
        );
    if (!result) {
    }
    return result;
}

void bwa_expenses_free(bwa_expenses_t *bwa_expenses) {
    if(NULL == bwa_expenses){
        return ;
    }
    if(bwa_expenses->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bwa_expenses_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bwa_expenses->expense_breakdown) {
        list_ForEach(listEntry, bwa_expenses->expense_breakdown) {
            expense_item_free(listEntry->data);
        }
        list_freeList(bwa_expenses->expense_breakdown);
        bwa_expenses->expense_breakdown = NULL;
    }
    if (bwa_expenses->total_expenses) {
        free(bwa_expenses->total_expenses);
        bwa_expenses->total_expenses = NULL;
    }
    free(bwa_expenses);
}

cJSON *bwa_expenses_convertToJSON(bwa_expenses_t *bwa_expenses) {
    cJSON *item = cJSON_CreateObject();

    // bwa_expenses->expense_breakdown
    if (!bwa_expenses->expense_breakdown) {
        goto fail;
    }
    cJSON *expense_breakdown = cJSON_AddArrayToObject(item, "expense_breakdown");
    if(expense_breakdown == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *expense_breakdownListEntry;
    if (bwa_expenses->expense_breakdown) {
    list_ForEach(expense_breakdownListEntry, bwa_expenses->expense_breakdown) {
    cJSON *itemLocal = expense_item_convertToJSON(expense_breakdownListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(expense_breakdown, itemLocal);
    }
    }


    // bwa_expenses->total_expenses
    if (!bwa_expenses->total_expenses) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_expenses", bwa_expenses->total_expenses) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bwa_expenses_t *bwa_expenses_parseFromJSON(cJSON *bwa_expensesJSON){

    bwa_expenses_t *bwa_expenses_local_var = NULL;

    // define the local list for bwa_expenses->expense_breakdown
    list_t *expense_breakdownList = NULL;

    char *total_expenses_local_str = NULL;

    // bwa_expenses->expense_breakdown
    cJSON *expense_breakdown = cJSON_GetObjectItemCaseSensitive(bwa_expensesJSON, "expense_breakdown");
    if (cJSON_IsNull(expense_breakdown)) {
        expense_breakdown = NULL;
    }
    if (!expense_breakdown) {
        goto end;
    }

    
    cJSON *expense_breakdown_local_nonprimitive = NULL;
    if(!cJSON_IsArray(expense_breakdown)){
        goto end; //nonprimitive container
    }

    expense_breakdownList = list_createList();

    cJSON_ArrayForEach(expense_breakdown_local_nonprimitive,expense_breakdown )
    {
        if(!cJSON_IsObject(expense_breakdown_local_nonprimitive)){
            goto end;
        }
        expense_item_t *expense_breakdownItem = expense_item_parseFromJSON(expense_breakdown_local_nonprimitive);

        list_addElement(expense_breakdownList, expense_breakdownItem);
    }

    // bwa_expenses->total_expenses
    cJSON *total_expenses = cJSON_GetObjectItemCaseSensitive(bwa_expensesJSON, "total_expenses");
    if (cJSON_IsNull(total_expenses)) {
        total_expenses = NULL;
    }
    if (!total_expenses) {
        goto end;
    }

    
    if(!cJSON_IsString(total_expenses))
    {
    goto end; //String
    }


    if (total_expenses && !cJSON_IsNull(total_expenses)) total_expenses_local_str = strdup(total_expenses->valuestring);

    bwa_expenses_local_var = bwa_expenses_create_internal (
        expense_breakdownList,
        total_expenses_local_str
        );

    if (!bwa_expenses_local_var) {
        goto end;
    }

    return bwa_expenses_local_var;
end:
    if (expense_breakdownList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, expense_breakdownList) {
            expense_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(expense_breakdownList);
        expense_breakdownList = NULL;
    }
    if (total_expenses_local_str) {
        free(total_expenses_local_str);
        total_expenses_local_str = NULL;
    }
    return NULL;

}
