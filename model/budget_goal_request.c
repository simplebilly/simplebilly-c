#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "budget_goal_request.h"



static budget_goal_request_t *budget_goal_request_create_internal(
    char *monthly_goal,
    int *year
    ) {
    budget_goal_request_t *budget_goal_request_local_var = malloc(sizeof(budget_goal_request_t));
    if (!budget_goal_request_local_var) {
        return NULL;
    }
    memset(budget_goal_request_local_var, 0, sizeof(budget_goal_request_t));
    budget_goal_request_local_var->_library_owned = 1;
    budget_goal_request_local_var->monthly_goal = monthly_goal;
    budget_goal_request_local_var->year = year;
    return budget_goal_request_local_var;
}

__attribute__((deprecated)) budget_goal_request_t *budget_goal_request_create(
    char *monthly_goal,
    int *year
    ) {
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    budget_goal_request_t *result = budget_goal_request_create_internal (
        monthly_goal,
        year_copy
        );
    if (!result) {
        free(year_copy);
    }
    return result;
}

void budget_goal_request_free(budget_goal_request_t *budget_goal_request) {
    if(NULL == budget_goal_request){
        return ;
    }
    if(budget_goal_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "budget_goal_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (budget_goal_request->monthly_goal) {
        free(budget_goal_request->monthly_goal);
        budget_goal_request->monthly_goal = NULL;
    }
    if (budget_goal_request->year) {
        free(budget_goal_request->year);
        budget_goal_request->year = NULL;
    }
    free(budget_goal_request);
}

cJSON *budget_goal_request_convertToJSON(budget_goal_request_t *budget_goal_request) {
    cJSON *item = cJSON_CreateObject();

    // budget_goal_request->monthly_goal
    if (!budget_goal_request->monthly_goal) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "monthly_goal", budget_goal_request->monthly_goal) == NULL) {
    goto fail; //String
    }


    // budget_goal_request->year
    if (!budget_goal_request->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *budget_goal_request->year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

budget_goal_request_t *budget_goal_request_parseFromJSON(cJSON *budget_goal_requestJSON){

    budget_goal_request_t *budget_goal_request_local_var = NULL;

    char *monthly_goal_local_str = NULL;

    // define the local variable for budget_goal_request->year
    int *year_local_var = NULL;

    // budget_goal_request->monthly_goal
    cJSON *monthly_goal = cJSON_GetObjectItemCaseSensitive(budget_goal_requestJSON, "monthly_goal");
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

    // budget_goal_request->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(budget_goal_requestJSON, "year");
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


    if (monthly_goal && !cJSON_IsNull(monthly_goal)) monthly_goal_local_str = strdup(monthly_goal->valuestring);

    budget_goal_request_local_var = budget_goal_request_create_internal (
        monthly_goal_local_str,
        year_local_var
        );

    if (!budget_goal_request_local_var) {
        goto end;
    }

    return budget_goal_request_local_var;
end:
    if (monthly_goal_local_str) {
        free(monthly_goal_local_str);
        monthly_goal_local_str = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    return NULL;

}
