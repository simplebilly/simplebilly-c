#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "expense_item.h"



static expense_item_t *expense_item_create_internal(
    char *amount,
    char *category,
    double *percentage
    ) {
    expense_item_t *expense_item_local_var = malloc(sizeof(expense_item_t));
    if (!expense_item_local_var) {
        return NULL;
    }
    memset(expense_item_local_var, 0, sizeof(expense_item_t));
    expense_item_local_var->_library_owned = 1;
    expense_item_local_var->amount = amount;
    expense_item_local_var->category = category;
    expense_item_local_var->percentage = percentage;
    return expense_item_local_var;
}

__attribute__((deprecated)) expense_item_t *expense_item_create(
    char *amount,
    char *category,
    double *percentage
    ) {
    double *percentage_copy = NULL;
    if (percentage) {
        percentage_copy = malloc(sizeof(double));
        if (percentage_copy) *percentage_copy = *percentage;
    }
    expense_item_t *result = expense_item_create_internal (
        amount,
        category,
        percentage_copy
        );
    if (!result) {
        free(percentage_copy);
    }
    return result;
}

void expense_item_free(expense_item_t *expense_item) {
    if(NULL == expense_item){
        return ;
    }
    if(expense_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "expense_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (expense_item->amount) {
        free(expense_item->amount);
        expense_item->amount = NULL;
    }
    if (expense_item->category) {
        free(expense_item->category);
        expense_item->category = NULL;
    }
    if (expense_item->percentage) {
        free(expense_item->percentage);
        expense_item->percentage = NULL;
    }
    free(expense_item);
}

cJSON *expense_item_convertToJSON(expense_item_t *expense_item) {
    cJSON *item = cJSON_CreateObject();

    // expense_item->amount
    if (!expense_item->amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amount", expense_item->amount) == NULL) {
    goto fail; //String
    }


    // expense_item->category
    if (!expense_item->category) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "category", expense_item->category) == NULL) {
    goto fail; //String
    }


    // expense_item->percentage
    if (!expense_item->percentage) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "percentage", *expense_item->percentage) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

expense_item_t *expense_item_parseFromJSON(cJSON *expense_itemJSON){

    expense_item_t *expense_item_local_var = NULL;

    char *amount_local_str = NULL;

    char *category_local_str = NULL;

    // define the local variable for expense_item->percentage
    double *percentage_local_var = NULL;

    // expense_item->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(expense_itemJSON, "amount");
    if (cJSON_IsNull(amount)) {
        amount = NULL;
    }
    if (!amount) {
        goto end;
    }

    
    if(!cJSON_IsString(amount))
    {
    goto end; //String
    }

    // expense_item->category
    cJSON *category = cJSON_GetObjectItemCaseSensitive(expense_itemJSON, "category");
    if (cJSON_IsNull(category)) {
        category = NULL;
    }
    if (!category) {
        goto end;
    }

    
    if(!cJSON_IsString(category))
    {
    goto end; //String
    }

    // expense_item->percentage
    cJSON *percentage = cJSON_GetObjectItemCaseSensitive(expense_itemJSON, "percentage");
    if (cJSON_IsNull(percentage)) {
        percentage = NULL;
    }
    if (!percentage) {
        goto end;
    }

    
    if(!cJSON_IsNumber(percentage))
    {
    goto end; //Numeric
    }
    percentage_local_var = malloc(sizeof(double));
    if(!percentage_local_var)
    {
        goto end;
    }
    *percentage_local_var = percentage->valuedouble;


    if (amount && !cJSON_IsNull(amount)) amount_local_str = strdup(amount->valuestring);
    if (category && !cJSON_IsNull(category)) category_local_str = strdup(category->valuestring);

    expense_item_local_var = expense_item_create_internal (
        amount_local_str,
        category_local_str,
        percentage_local_var
        );

    if (!expense_item_local_var) {
        goto end;
    }

    return expense_item_local_var;
end:
    if (amount_local_str) {
        free(amount_local_str);
        amount_local_str = NULL;
    }
    if (category_local_str) {
        free(category_local_str);
        category_local_str = NULL;
    }
    if (percentage_local_var) {
        free(percentage_local_var);
        percentage_local_var = NULL;
    }
    return NULL;

}
