#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "liquidity_position.h"



static liquidity_position_t *liquidity_position_create_internal(
    double *accounts_payable,
    double *accounts_receivable,
    double *cash_and_equivalents,
    double *current_ratio,
    double *quick_ratio,
    double *working_capital
    ) {
    liquidity_position_t *liquidity_position_local_var = malloc(sizeof(liquidity_position_t));
    if (!liquidity_position_local_var) {
        return NULL;
    }
    memset(liquidity_position_local_var, 0, sizeof(liquidity_position_t));
    liquidity_position_local_var->_library_owned = 1;
    liquidity_position_local_var->accounts_payable = accounts_payable;
    liquidity_position_local_var->accounts_receivable = accounts_receivable;
    liquidity_position_local_var->cash_and_equivalents = cash_and_equivalents;
    liquidity_position_local_var->current_ratio = current_ratio;
    liquidity_position_local_var->quick_ratio = quick_ratio;
    liquidity_position_local_var->working_capital = working_capital;
    return liquidity_position_local_var;
}

__attribute__((deprecated)) liquidity_position_t *liquidity_position_create(
    double *accounts_payable,
    double *accounts_receivable,
    double *cash_and_equivalents,
    double *current_ratio,
    double *quick_ratio,
    double *working_capital
    ) {
    double *accounts_payable_copy = NULL;
    if (accounts_payable) {
        accounts_payable_copy = malloc(sizeof(double));
        if (accounts_payable_copy) *accounts_payable_copy = *accounts_payable;
    }
    double *accounts_receivable_copy = NULL;
    if (accounts_receivable) {
        accounts_receivable_copy = malloc(sizeof(double));
        if (accounts_receivable_copy) *accounts_receivable_copy = *accounts_receivable;
    }
    double *cash_and_equivalents_copy = NULL;
    if (cash_and_equivalents) {
        cash_and_equivalents_copy = malloc(sizeof(double));
        if (cash_and_equivalents_copy) *cash_and_equivalents_copy = *cash_and_equivalents;
    }
    double *current_ratio_copy = NULL;
    if (current_ratio) {
        current_ratio_copy = malloc(sizeof(double));
        if (current_ratio_copy) *current_ratio_copy = *current_ratio;
    }
    double *quick_ratio_copy = NULL;
    if (quick_ratio) {
        quick_ratio_copy = malloc(sizeof(double));
        if (quick_ratio_copy) *quick_ratio_copy = *quick_ratio;
    }
    double *working_capital_copy = NULL;
    if (working_capital) {
        working_capital_copy = malloc(sizeof(double));
        if (working_capital_copy) *working_capital_copy = *working_capital;
    }
    liquidity_position_t *result = liquidity_position_create_internal (
        accounts_payable_copy,
        accounts_receivable_copy,
        cash_and_equivalents_copy,
        current_ratio_copy,
        quick_ratio_copy,
        working_capital_copy
        );
    if (!result) {
        free(accounts_payable_copy);
        free(accounts_receivable_copy);
        free(cash_and_equivalents_copy);
        free(current_ratio_copy);
        free(quick_ratio_copy);
        free(working_capital_copy);
    }
    return result;
}

void liquidity_position_free(liquidity_position_t *liquidity_position) {
    if(NULL == liquidity_position){
        return ;
    }
    if(liquidity_position->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "liquidity_position_free");
        return ;
    }
    listEntry_t *listEntry;
    if (liquidity_position->accounts_payable) {
        free(liquidity_position->accounts_payable);
        liquidity_position->accounts_payable = NULL;
    }
    if (liquidity_position->accounts_receivable) {
        free(liquidity_position->accounts_receivable);
        liquidity_position->accounts_receivable = NULL;
    }
    if (liquidity_position->cash_and_equivalents) {
        free(liquidity_position->cash_and_equivalents);
        liquidity_position->cash_and_equivalents = NULL;
    }
    if (liquidity_position->current_ratio) {
        free(liquidity_position->current_ratio);
        liquidity_position->current_ratio = NULL;
    }
    if (liquidity_position->quick_ratio) {
        free(liquidity_position->quick_ratio);
        liquidity_position->quick_ratio = NULL;
    }
    if (liquidity_position->working_capital) {
        free(liquidity_position->working_capital);
        liquidity_position->working_capital = NULL;
    }
    free(liquidity_position);
}

cJSON *liquidity_position_convertToJSON(liquidity_position_t *liquidity_position) {
    cJSON *item = cJSON_CreateObject();

    // liquidity_position->accounts_payable
    if (!liquidity_position->accounts_payable) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "accounts_payable", *liquidity_position->accounts_payable) == NULL) {
    goto fail; //Numeric
    }


    // liquidity_position->accounts_receivable
    if (!liquidity_position->accounts_receivable) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "accounts_receivable", *liquidity_position->accounts_receivable) == NULL) {
    goto fail; //Numeric
    }


    // liquidity_position->cash_and_equivalents
    if (!liquidity_position->cash_and_equivalents) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cash_and_equivalents", *liquidity_position->cash_and_equivalents) == NULL) {
    goto fail; //Numeric
    }


    // liquidity_position->current_ratio
    if (!liquidity_position->current_ratio) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "current_ratio", *liquidity_position->current_ratio) == NULL) {
    goto fail; //Numeric
    }


    // liquidity_position->quick_ratio
    if (!liquidity_position->quick_ratio) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quick_ratio", *liquidity_position->quick_ratio) == NULL) {
    goto fail; //Numeric
    }


    // liquidity_position->working_capital
    if (!liquidity_position->working_capital) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "working_capital", *liquidity_position->working_capital) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

liquidity_position_t *liquidity_position_parseFromJSON(cJSON *liquidity_positionJSON){

    liquidity_position_t *liquidity_position_local_var = NULL;

    // define the local variable for liquidity_position->accounts_payable
    double *accounts_payable_local_var = NULL;

    // define the local variable for liquidity_position->accounts_receivable
    double *accounts_receivable_local_var = NULL;

    // define the local variable for liquidity_position->cash_and_equivalents
    double *cash_and_equivalents_local_var = NULL;

    // define the local variable for liquidity_position->current_ratio
    double *current_ratio_local_var = NULL;

    // define the local variable for liquidity_position->quick_ratio
    double *quick_ratio_local_var = NULL;

    // define the local variable for liquidity_position->working_capital
    double *working_capital_local_var = NULL;

    // liquidity_position->accounts_payable
    cJSON *accounts_payable = cJSON_GetObjectItemCaseSensitive(liquidity_positionJSON, "accounts_payable");
    if (cJSON_IsNull(accounts_payable)) {
        accounts_payable = NULL;
    }
    if (!accounts_payable) {
        goto end;
    }

    
    if(!cJSON_IsNumber(accounts_payable))
    {
    goto end; //Numeric
    }
    accounts_payable_local_var = malloc(sizeof(double));
    if(!accounts_payable_local_var)
    {
        goto end;
    }
    *accounts_payable_local_var = accounts_payable->valuedouble;

    // liquidity_position->accounts_receivable
    cJSON *accounts_receivable = cJSON_GetObjectItemCaseSensitive(liquidity_positionJSON, "accounts_receivable");
    if (cJSON_IsNull(accounts_receivable)) {
        accounts_receivable = NULL;
    }
    if (!accounts_receivable) {
        goto end;
    }

    
    if(!cJSON_IsNumber(accounts_receivable))
    {
    goto end; //Numeric
    }
    accounts_receivable_local_var = malloc(sizeof(double));
    if(!accounts_receivable_local_var)
    {
        goto end;
    }
    *accounts_receivable_local_var = accounts_receivable->valuedouble;

    // liquidity_position->cash_and_equivalents
    cJSON *cash_and_equivalents = cJSON_GetObjectItemCaseSensitive(liquidity_positionJSON, "cash_and_equivalents");
    if (cJSON_IsNull(cash_and_equivalents)) {
        cash_and_equivalents = NULL;
    }
    if (!cash_and_equivalents) {
        goto end;
    }

    
    if(!cJSON_IsNumber(cash_and_equivalents))
    {
    goto end; //Numeric
    }
    cash_and_equivalents_local_var = malloc(sizeof(double));
    if(!cash_and_equivalents_local_var)
    {
        goto end;
    }
    *cash_and_equivalents_local_var = cash_and_equivalents->valuedouble;

    // liquidity_position->current_ratio
    cJSON *current_ratio = cJSON_GetObjectItemCaseSensitive(liquidity_positionJSON, "current_ratio");
    if (cJSON_IsNull(current_ratio)) {
        current_ratio = NULL;
    }
    if (!current_ratio) {
        goto end;
    }

    
    if(!cJSON_IsNumber(current_ratio))
    {
    goto end; //Numeric
    }
    current_ratio_local_var = malloc(sizeof(double));
    if(!current_ratio_local_var)
    {
        goto end;
    }
    *current_ratio_local_var = current_ratio->valuedouble;

    // liquidity_position->quick_ratio
    cJSON *quick_ratio = cJSON_GetObjectItemCaseSensitive(liquidity_positionJSON, "quick_ratio");
    if (cJSON_IsNull(quick_ratio)) {
        quick_ratio = NULL;
    }
    if (!quick_ratio) {
        goto end;
    }

    
    if(!cJSON_IsNumber(quick_ratio))
    {
    goto end; //Numeric
    }
    quick_ratio_local_var = malloc(sizeof(double));
    if(!quick_ratio_local_var)
    {
        goto end;
    }
    *quick_ratio_local_var = quick_ratio->valuedouble;

    // liquidity_position->working_capital
    cJSON *working_capital = cJSON_GetObjectItemCaseSensitive(liquidity_positionJSON, "working_capital");
    if (cJSON_IsNull(working_capital)) {
        working_capital = NULL;
    }
    if (!working_capital) {
        goto end;
    }

    
    if(!cJSON_IsNumber(working_capital))
    {
    goto end; //Numeric
    }
    working_capital_local_var = malloc(sizeof(double));
    if(!working_capital_local_var)
    {
        goto end;
    }
    *working_capital_local_var = working_capital->valuedouble;



    liquidity_position_local_var = liquidity_position_create_internal (
        accounts_payable_local_var,
        accounts_receivable_local_var,
        cash_and_equivalents_local_var,
        current_ratio_local_var,
        quick_ratio_local_var,
        working_capital_local_var
        );

    if (!liquidity_position_local_var) {
        goto end;
    }

    return liquidity_position_local_var;
end:
    if (accounts_payable_local_var) {
        free(accounts_payable_local_var);
        accounts_payable_local_var = NULL;
    }
    if (accounts_receivable_local_var) {
        free(accounts_receivable_local_var);
        accounts_receivable_local_var = NULL;
    }
    if (cash_and_equivalents_local_var) {
        free(cash_and_equivalents_local_var);
        cash_and_equivalents_local_var = NULL;
    }
    if (current_ratio_local_var) {
        free(current_ratio_local_var);
        current_ratio_local_var = NULL;
    }
    if (quick_ratio_local_var) {
        free(quick_ratio_local_var);
        quick_ratio_local_var = NULL;
    }
    if (working_capital_local_var) {
        free(working_capital_local_var);
        working_capital_local_var = NULL;
    }
    return NULL;

}
