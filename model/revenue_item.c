#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "revenue_item.h"



static revenue_item_t *revenue_item_create_internal(
    char *amount,
    char *category,
    double *percentage
    ) {
    revenue_item_t *revenue_item_local_var = malloc(sizeof(revenue_item_t));
    if (!revenue_item_local_var) {
        return NULL;
    }
    memset(revenue_item_local_var, 0, sizeof(revenue_item_t));
    revenue_item_local_var->_library_owned = 1;
    revenue_item_local_var->amount = amount;
    revenue_item_local_var->category = category;
    revenue_item_local_var->percentage = percentage;
    return revenue_item_local_var;
}

__attribute__((deprecated)) revenue_item_t *revenue_item_create(
    char *amount,
    char *category,
    double *percentage
    ) {
    double *percentage_copy = NULL;
    if (percentage) {
        percentage_copy = malloc(sizeof(double));
        if (percentage_copy) *percentage_copy = *percentage;
    }
    revenue_item_t *result = revenue_item_create_internal (
        amount,
        category,
        percentage_copy
        );
    if (!result) {
        free(percentage_copy);
    }
    return result;
}

void revenue_item_free(revenue_item_t *revenue_item) {
    if(NULL == revenue_item){
        return ;
    }
    if(revenue_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "revenue_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (revenue_item->amount) {
        free(revenue_item->amount);
        revenue_item->amount = NULL;
    }
    if (revenue_item->category) {
        free(revenue_item->category);
        revenue_item->category = NULL;
    }
    if (revenue_item->percentage) {
        free(revenue_item->percentage);
        revenue_item->percentage = NULL;
    }
    free(revenue_item);
}

cJSON *revenue_item_convertToJSON(revenue_item_t *revenue_item) {
    cJSON *item = cJSON_CreateObject();

    // revenue_item->amount
    if (!revenue_item->amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amount", revenue_item->amount) == NULL) {
    goto fail; //String
    }


    // revenue_item->category
    if (!revenue_item->category) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "category", revenue_item->category) == NULL) {
    goto fail; //String
    }


    // revenue_item->percentage
    if (!revenue_item->percentage) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "percentage", *revenue_item->percentage) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

revenue_item_t *revenue_item_parseFromJSON(cJSON *revenue_itemJSON){

    revenue_item_t *revenue_item_local_var = NULL;

    char *amount_local_str = NULL;

    char *category_local_str = NULL;

    // define the local variable for revenue_item->percentage
    double *percentage_local_var = NULL;

    // revenue_item->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(revenue_itemJSON, "amount");
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

    // revenue_item->category
    cJSON *category = cJSON_GetObjectItemCaseSensitive(revenue_itemJSON, "category");
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

    // revenue_item->percentage
    cJSON *percentage = cJSON_GetObjectItemCaseSensitive(revenue_itemJSON, "percentage");
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

    revenue_item_local_var = revenue_item_create_internal (
        amount_local_str,
        category_local_str,
        percentage_local_var
        );

    if (!revenue_item_local_var) {
        goto end;
    }

    return revenue_item_local_var;
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
