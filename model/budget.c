#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "budget.h"



static budget_t *budget_create_internal(
    char *category,
    char *monthly_goal,
    char *updated_at,
    int *year
    ) {
    budget_t *budget_local_var = malloc(sizeof(budget_t));
    if (!budget_local_var) {
        return NULL;
    }
    memset(budget_local_var, 0, sizeof(budget_t));
    budget_local_var->_library_owned = 1;
    budget_local_var->category = category;
    budget_local_var->monthly_goal = monthly_goal;
    budget_local_var->updated_at = updated_at;
    budget_local_var->year = year;
    return budget_local_var;
}

__attribute__((deprecated)) budget_t *budget_create(
    char *category,
    char *monthly_goal,
    char *updated_at,
    int *year
    ) {
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    budget_t *result = budget_create_internal (
        category,
        monthly_goal,
        updated_at,
        year_copy
        );
    if (!result) {
        free(year_copy);
    }
    return result;
}

void budget_free(budget_t *budget) {
    if(NULL == budget){
        return ;
    }
    if(budget->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "budget_free");
        return ;
    }
    listEntry_t *listEntry;
    if (budget->category) {
        free(budget->category);
        budget->category = NULL;
    }
    if (budget->monthly_goal) {
        free(budget->monthly_goal);
        budget->monthly_goal = NULL;
    }
    if (budget->updated_at) {
        free(budget->updated_at);
        budget->updated_at = NULL;
    }
    if (budget->year) {
        free(budget->year);
        budget->year = NULL;
    }
    free(budget);
}

cJSON *budget_convertToJSON(budget_t *budget) {
    cJSON *item = cJSON_CreateObject();

    // budget->category
    if (!budget->category) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "category", budget->category) == NULL) {
    goto fail; //String
    }


    // budget->monthly_goal
    if (!budget->monthly_goal) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "monthlyGoal", budget->monthly_goal) == NULL) {
    goto fail; //String
    }


    // budget->updated_at
    if(budget->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", budget->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // budget->year
    if (!budget->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *budget->year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

budget_t *budget_parseFromJSON(cJSON *budgetJSON){

    budget_t *budget_local_var = NULL;

    char *category_local_str = NULL;

    char *monthly_goal_local_str = NULL;

    char *updated_at_local_str = NULL;

    // define the local variable for budget->year
    int *year_local_var = NULL;

    // budget->category
    cJSON *category = cJSON_GetObjectItemCaseSensitive(budgetJSON, "category");
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

    // budget->monthly_goal
    cJSON *monthly_goal = cJSON_GetObjectItemCaseSensitive(budgetJSON, "monthlyGoal");
    if (cJSON_IsNull(monthly_goal)) {
        monthly_goal = NULL;
    }
    if (!monthly_goal) {
        goto end;
    }

    
    if(!cJSON_IsString(monthly_goal))
    {
    goto end; //String
    }

    // budget->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(budgetJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }

    // budget->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(budgetJSON, "year");
    if (cJSON_IsNull(year)) {
        year = NULL;
    }
    if (!year) {
        goto end;
    }

    
    if(!cJSON_IsNumber(year))
    {
    goto end; //Numeric
    }
    year_local_var = malloc(sizeof(int));
    if(!year_local_var)
    {
        goto end;
    }
    *year_local_var = year->valuedouble;


    if (category && !cJSON_IsNull(category)) category_local_str = strdup(category->valuestring);
    if (monthly_goal && !cJSON_IsNull(monthly_goal)) monthly_goal_local_str = strdup(monthly_goal->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    budget_local_var = budget_create_internal (
        category_local_str,
        monthly_goal_local_str,
        updated_at_local_str,
        year_local_var
        );

    if (!budget_local_var) {
        goto end;
    }

    return budget_local_var;
end:
    if (category_local_str) {
        free(category_local_str);
        category_local_str = NULL;
    }
    if (monthly_goal_local_str) {
        free(monthly_goal_local_str);
        monthly_goal_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    return NULL;

}
