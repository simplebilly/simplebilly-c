#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "income_statement.h"



static income_statement_t *income_statement_create_internal(
    list_t *expense_items,
    char *net_income,
    list_t *revenue_items,
    char *total_expenses,
    char *total_revenue
    ) {
    income_statement_t *income_statement_local_var = malloc(sizeof(income_statement_t));
    if (!income_statement_local_var) {
        return NULL;
    }
    memset(income_statement_local_var, 0, sizeof(income_statement_t));
    income_statement_local_var->_library_owned = 1;
    income_statement_local_var->expense_items = expense_items;
    income_statement_local_var->net_income = net_income;
    income_statement_local_var->revenue_items = revenue_items;
    income_statement_local_var->total_expenses = total_expenses;
    income_statement_local_var->total_revenue = total_revenue;
    return income_statement_local_var;
}

__attribute__((deprecated)) income_statement_t *income_statement_create(
    list_t *expense_items,
    char *net_income,
    list_t *revenue_items,
    char *total_expenses,
    char *total_revenue
    ) {
    income_statement_t *result = income_statement_create_internal (
        expense_items,
        net_income,
        revenue_items,
        total_expenses,
        total_revenue
        );
    if (!result) {
    }
    return result;
}

void income_statement_free(income_statement_t *income_statement) {
    if(NULL == income_statement){
        return ;
    }
    if(income_statement->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "income_statement_free");
        return ;
    }
    listEntry_t *listEntry;
    if (income_statement->expense_items) {
        list_ForEach(listEntry, income_statement->expense_items) {
            pn_l_item_free(listEntry->data);
        }
        list_freeList(income_statement->expense_items);
        income_statement->expense_items = NULL;
    }
    if (income_statement->net_income) {
        free(income_statement->net_income);
        income_statement->net_income = NULL;
    }
    if (income_statement->revenue_items) {
        list_ForEach(listEntry, income_statement->revenue_items) {
            pn_l_item_free(listEntry->data);
        }
        list_freeList(income_statement->revenue_items);
        income_statement->revenue_items = NULL;
    }
    if (income_statement->total_expenses) {
        free(income_statement->total_expenses);
        income_statement->total_expenses = NULL;
    }
    if (income_statement->total_revenue) {
        free(income_statement->total_revenue);
        income_statement->total_revenue = NULL;
    }
    free(income_statement);
}

cJSON *income_statement_convertToJSON(income_statement_t *income_statement) {
    cJSON *item = cJSON_CreateObject();

    // income_statement->expense_items
    if (!income_statement->expense_items) {
        goto fail;
    }
    cJSON *expense_items = cJSON_AddArrayToObject(item, "expense_items");
    if(expense_items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *expense_itemsListEntry;
    if (income_statement->expense_items) {
    list_ForEach(expense_itemsListEntry, income_statement->expense_items) {
    cJSON *itemLocal = pn_l_item_convertToJSON(expense_itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(expense_items, itemLocal);
    }
    }


    // income_statement->net_income
    if (!income_statement->net_income) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "net_income", income_statement->net_income) == NULL) {
    goto fail; //String
    }


    // income_statement->revenue_items
    if (!income_statement->revenue_items) {
        goto fail;
    }
    cJSON *revenue_items = cJSON_AddArrayToObject(item, "revenue_items");
    if(revenue_items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *revenue_itemsListEntry;
    if (income_statement->revenue_items) {
    list_ForEach(revenue_itemsListEntry, income_statement->revenue_items) {
    cJSON *itemLocal = pn_l_item_convertToJSON(revenue_itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(revenue_items, itemLocal);
    }
    }


    // income_statement->total_expenses
    if (!income_statement->total_expenses) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_expenses", income_statement->total_expenses) == NULL) {
    goto fail; //String
    }


    // income_statement->total_revenue
    if (!income_statement->total_revenue) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_revenue", income_statement->total_revenue) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

income_statement_t *income_statement_parseFromJSON(cJSON *income_statementJSON){

    income_statement_t *income_statement_local_var = NULL;

    // define the local list for income_statement->expense_items
    list_t *expense_itemsList = NULL;

    char *net_income_local_str = NULL;

    // define the local list for income_statement->revenue_items
    list_t *revenue_itemsList = NULL;

    char *total_expenses_local_str = NULL;

    char *total_revenue_local_str = NULL;

    // income_statement->expense_items
    cJSON *expense_items = cJSON_GetObjectItemCaseSensitive(income_statementJSON, "expense_items");
    if (cJSON_IsNull(expense_items)) {
        expense_items = NULL;
    }
    if (!expense_items) {
        goto end;
    }

    
    cJSON *expense_items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(expense_items)){
        goto end; //nonprimitive container
    }

    expense_itemsList = list_createList();

    cJSON_ArrayForEach(expense_items_local_nonprimitive,expense_items )
    {
        if(!cJSON_IsObject(expense_items_local_nonprimitive)){
            goto end;
        }
        pn_l_item_t *expense_itemsItem = pn_l_item_parseFromJSON(expense_items_local_nonprimitive);

        list_addElement(expense_itemsList, expense_itemsItem);
    }

    // income_statement->net_income
    cJSON *net_income = cJSON_GetObjectItemCaseSensitive(income_statementJSON, "net_income");
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

    // income_statement->revenue_items
    cJSON *revenue_items = cJSON_GetObjectItemCaseSensitive(income_statementJSON, "revenue_items");
    if (cJSON_IsNull(revenue_items)) {
        revenue_items = NULL;
    }
    if (!revenue_items) {
        goto end;
    }

    
    cJSON *revenue_items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(revenue_items)){
        goto end; //nonprimitive container
    }

    revenue_itemsList = list_createList();

    cJSON_ArrayForEach(revenue_items_local_nonprimitive,revenue_items )
    {
        if(!cJSON_IsObject(revenue_items_local_nonprimitive)){
            goto end;
        }
        pn_l_item_t *revenue_itemsItem = pn_l_item_parseFromJSON(revenue_items_local_nonprimitive);

        list_addElement(revenue_itemsList, revenue_itemsItem);
    }

    // income_statement->total_expenses
    cJSON *total_expenses = cJSON_GetObjectItemCaseSensitive(income_statementJSON, "total_expenses");
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

    // income_statement->total_revenue
    cJSON *total_revenue = cJSON_GetObjectItemCaseSensitive(income_statementJSON, "total_revenue");
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


    if (net_income && !cJSON_IsNull(net_income)) net_income_local_str = strdup(net_income->valuestring);
    if (total_expenses && !cJSON_IsNull(total_expenses)) total_expenses_local_str = strdup(total_expenses->valuestring);
    if (total_revenue && !cJSON_IsNull(total_revenue)) total_revenue_local_str = strdup(total_revenue->valuestring);

    income_statement_local_var = income_statement_create_internal (
        expense_itemsList,
        net_income_local_str,
        revenue_itemsList,
        total_expenses_local_str,
        total_revenue_local_str
        );

    if (!income_statement_local_var) {
        goto end;
    }

    return income_statement_local_var;
end:
    if (expense_itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, expense_itemsList) {
            pn_l_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(expense_itemsList);
        expense_itemsList = NULL;
    }
    if (net_income_local_str) {
        free(net_income_local_str);
        net_income_local_str = NULL;
    }
    if (revenue_itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, revenue_itemsList) {
            pn_l_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(revenue_itemsList);
        revenue_itemsList = NULL;
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
