#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gu_v_report.h"



static gu_v_report_t *gu_v_report_create_internal(
    list_t *expenses,
    char *generated_at,
    char *net_income,
    char *period,
    list_t *revenue,
    char *total_expenses,
    char *total_revenue
    ) {
    gu_v_report_t *gu_v_report_local_var = malloc(sizeof(gu_v_report_t));
    if (!gu_v_report_local_var) {
        return NULL;
    }
    memset(gu_v_report_local_var, 0, sizeof(gu_v_report_t));
    gu_v_report_local_var->_library_owned = 1;
    gu_v_report_local_var->expenses = expenses;
    gu_v_report_local_var->generated_at = generated_at;
    gu_v_report_local_var->net_income = net_income;
    gu_v_report_local_var->period = period;
    gu_v_report_local_var->revenue = revenue;
    gu_v_report_local_var->total_expenses = total_expenses;
    gu_v_report_local_var->total_revenue = total_revenue;
    return gu_v_report_local_var;
}

__attribute__((deprecated)) gu_v_report_t *gu_v_report_create(
    list_t *expenses,
    char *generated_at,
    char *net_income,
    char *period,
    list_t *revenue,
    char *total_expenses,
    char *total_revenue
    ) {
    gu_v_report_t *result = gu_v_report_create_internal (
        expenses,
        generated_at,
        net_income,
        period,
        revenue,
        total_expenses,
        total_revenue
        );
    if (!result) {
    }
    return result;
}

void gu_v_report_free(gu_v_report_t *gu_v_report) {
    if(NULL == gu_v_report){
        return ;
    }
    if(gu_v_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gu_v_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gu_v_report->expenses) {
        list_ForEach(listEntry, gu_v_report->expenses) {
            gu_v_item_free(listEntry->data);
        }
        list_freeList(gu_v_report->expenses);
        gu_v_report->expenses = NULL;
    }
    if (gu_v_report->generated_at) {
        free(gu_v_report->generated_at);
        gu_v_report->generated_at = NULL;
    }
    if (gu_v_report->net_income) {
        free(gu_v_report->net_income);
        gu_v_report->net_income = NULL;
    }
    if (gu_v_report->period) {
        free(gu_v_report->period);
        gu_v_report->period = NULL;
    }
    if (gu_v_report->revenue) {
        list_ForEach(listEntry, gu_v_report->revenue) {
            gu_v_item_free(listEntry->data);
        }
        list_freeList(gu_v_report->revenue);
        gu_v_report->revenue = NULL;
    }
    if (gu_v_report->total_expenses) {
        free(gu_v_report->total_expenses);
        gu_v_report->total_expenses = NULL;
    }
    if (gu_v_report->total_revenue) {
        free(gu_v_report->total_revenue);
        gu_v_report->total_revenue = NULL;
    }
    free(gu_v_report);
}

cJSON *gu_v_report_convertToJSON(gu_v_report_t *gu_v_report) {
    cJSON *item = cJSON_CreateObject();

    // gu_v_report->expenses
    if (!gu_v_report->expenses) {
        goto fail;
    }
    cJSON *expenses = cJSON_AddArrayToObject(item, "expenses");
    if(expenses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *expensesListEntry;
    if (gu_v_report->expenses) {
    list_ForEach(expensesListEntry, gu_v_report->expenses) {
    cJSON *itemLocal = gu_v_item_convertToJSON(expensesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(expenses, itemLocal);
    }
    }


    // gu_v_report->generated_at
    if (!gu_v_report->generated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "generated_at", gu_v_report->generated_at) == NULL) {
    goto fail; //String
    }


    // gu_v_report->net_income
    if (!gu_v_report->net_income) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "net_income", gu_v_report->net_income) == NULL) {
    goto fail; //String
    }


    // gu_v_report->period
    if (!gu_v_report->period) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "period", gu_v_report->period) == NULL) {
    goto fail; //String
    }


    // gu_v_report->revenue
    if (!gu_v_report->revenue) {
        goto fail;
    }
    cJSON *revenue = cJSON_AddArrayToObject(item, "revenue");
    if(revenue == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *revenueListEntry;
    if (gu_v_report->revenue) {
    list_ForEach(revenueListEntry, gu_v_report->revenue) {
    cJSON *itemLocal = gu_v_item_convertToJSON(revenueListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(revenue, itemLocal);
    }
    }


    // gu_v_report->total_expenses
    if (!gu_v_report->total_expenses) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_expenses", gu_v_report->total_expenses) == NULL) {
    goto fail; //String
    }


    // gu_v_report->total_revenue
    if (!gu_v_report->total_revenue) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_revenue", gu_v_report->total_revenue) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gu_v_report_t *gu_v_report_parseFromJSON(cJSON *gu_v_reportJSON){

    gu_v_report_t *gu_v_report_local_var = NULL;

    // define the local list for gu_v_report->expenses
    list_t *expensesList = NULL;

    char *generated_at_local_str = NULL;

    char *net_income_local_str = NULL;

    char *period_local_str = NULL;

    // define the local list for gu_v_report->revenue
    list_t *revenueList = NULL;

    char *total_expenses_local_str = NULL;

    char *total_revenue_local_str = NULL;

    // gu_v_report->expenses
    cJSON *expenses = cJSON_GetObjectItemCaseSensitive(gu_v_reportJSON, "expenses");
    if (cJSON_IsNull(expenses)) {
        expenses = NULL;
    }
    if (!expenses) {
        goto end;
    }

    
    cJSON *expenses_local_nonprimitive = NULL;
    if(!cJSON_IsArray(expenses)){
        goto end; //nonprimitive container
    }

    expensesList = list_createList();

    cJSON_ArrayForEach(expenses_local_nonprimitive,expenses )
    {
        if(!cJSON_IsObject(expenses_local_nonprimitive)){
            goto end;
        }
        gu_v_item_t *expensesItem = gu_v_item_parseFromJSON(expenses_local_nonprimitive);

        list_addElement(expensesList, expensesItem);
    }

    // gu_v_report->generated_at
    cJSON *generated_at = cJSON_GetObjectItemCaseSensitive(gu_v_reportJSON, "generated_at");
    if (cJSON_IsNull(generated_at)) {
        generated_at = NULL;
    }
    if (!generated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(generated_at))
    {
    goto end; //String
    }

    // gu_v_report->net_income
    cJSON *net_income = cJSON_GetObjectItemCaseSensitive(gu_v_reportJSON, "net_income");
    if (cJSON_IsNull(net_income)) {
        net_income = NULL;
    }
    if (!net_income) {
        goto end;
    }

    
    if(!cJSON_IsString(net_income))
    {
    goto end; //String
    }

    // gu_v_report->period
    cJSON *period = cJSON_GetObjectItemCaseSensitive(gu_v_reportJSON, "period");
    if (cJSON_IsNull(period)) {
        period = NULL;
    }
    if (!period) {
        goto end;
    }

    
    if(!cJSON_IsString(period))
    {
    goto end; //String
    }

    // gu_v_report->revenue
    cJSON *revenue = cJSON_GetObjectItemCaseSensitive(gu_v_reportJSON, "revenue");
    if (cJSON_IsNull(revenue)) {
        revenue = NULL;
    }
    if (!revenue) {
        goto end;
    }

    
    cJSON *revenue_local_nonprimitive = NULL;
    if(!cJSON_IsArray(revenue)){
        goto end; //nonprimitive container
    }

    revenueList = list_createList();

    cJSON_ArrayForEach(revenue_local_nonprimitive,revenue )
    {
        if(!cJSON_IsObject(revenue_local_nonprimitive)){
            goto end;
        }
        gu_v_item_t *revenueItem = gu_v_item_parseFromJSON(revenue_local_nonprimitive);

        list_addElement(revenueList, revenueItem);
    }

    // gu_v_report->total_expenses
    cJSON *total_expenses = cJSON_GetObjectItemCaseSensitive(gu_v_reportJSON, "total_expenses");
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

    // gu_v_report->total_revenue
    cJSON *total_revenue = cJSON_GetObjectItemCaseSensitive(gu_v_reportJSON, "total_revenue");
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


    if (generated_at && !cJSON_IsNull(generated_at)) generated_at_local_str = strdup(generated_at->valuestring);
    if (net_income && !cJSON_IsNull(net_income)) net_income_local_str = strdup(net_income->valuestring);
    if (period && !cJSON_IsNull(period)) period_local_str = strdup(period->valuestring);
    if (total_expenses && !cJSON_IsNull(total_expenses)) total_expenses_local_str = strdup(total_expenses->valuestring);
    if (total_revenue && !cJSON_IsNull(total_revenue)) total_revenue_local_str = strdup(total_revenue->valuestring);

    gu_v_report_local_var = gu_v_report_create_internal (
        expensesList,
        generated_at_local_str,
        net_income_local_str,
        period_local_str,
        revenueList,
        total_expenses_local_str,
        total_revenue_local_str
        );

    if (!gu_v_report_local_var) {
        goto end;
    }

    return gu_v_report_local_var;
end:
    if (expensesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, expensesList) {
            gu_v_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(expensesList);
        expensesList = NULL;
    }
    if (generated_at_local_str) {
        free(generated_at_local_str);
        generated_at_local_str = NULL;
    }
    if (net_income_local_str) {
        free(net_income_local_str);
        net_income_local_str = NULL;
    }
    if (period_local_str) {
        free(period_local_str);
        period_local_str = NULL;
    }
    if (revenueList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, revenueList) {
            gu_v_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(revenueList);
        revenueList = NULL;
    }
    if (total_expenses_local_str) {
        free(total_expenses_local_str);
        total_expenses_local_str = NULL;
    }
    if (total_revenue_local_str) {
        free(total_revenue_local_str);
        total_revenue_local_str = NULL;
    }
    return NULL;

}
