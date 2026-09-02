#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cashflow_report.h"



static cashflow_report_t *cashflow_report_create_internal(
    double *closing_balance,
    double *financing_cashflow,
    double *investing_cashflow,
    double *net_cashflow,
    double *opening_balance,
    double *operating_cashflow,
    char *period
    ) {
    cashflow_report_t *cashflow_report_local_var = malloc(sizeof(cashflow_report_t));
    if (!cashflow_report_local_var) {
        return NULL;
    }
    memset(cashflow_report_local_var, 0, sizeof(cashflow_report_t));
    cashflow_report_local_var->_library_owned = 1;
    cashflow_report_local_var->closing_balance = closing_balance;
    cashflow_report_local_var->financing_cashflow = financing_cashflow;
    cashflow_report_local_var->investing_cashflow = investing_cashflow;
    cashflow_report_local_var->net_cashflow = net_cashflow;
    cashflow_report_local_var->opening_balance = opening_balance;
    cashflow_report_local_var->operating_cashflow = operating_cashflow;
    cashflow_report_local_var->period = period;
    return cashflow_report_local_var;
}

__attribute__((deprecated)) cashflow_report_t *cashflow_report_create(
    double *closing_balance,
    double *financing_cashflow,
    double *investing_cashflow,
    double *net_cashflow,
    double *opening_balance,
    double *operating_cashflow,
    char *period
    ) {
    double *closing_balance_copy = NULL;
    if (closing_balance) {
        closing_balance_copy = malloc(sizeof(double));
        if (closing_balance_copy) *closing_balance_copy = *closing_balance;
    }
    double *financing_cashflow_copy = NULL;
    if (financing_cashflow) {
        financing_cashflow_copy = malloc(sizeof(double));
        if (financing_cashflow_copy) *financing_cashflow_copy = *financing_cashflow;
    }
    double *investing_cashflow_copy = NULL;
    if (investing_cashflow) {
        investing_cashflow_copy = malloc(sizeof(double));
        if (investing_cashflow_copy) *investing_cashflow_copy = *investing_cashflow;
    }
    double *net_cashflow_copy = NULL;
    if (net_cashflow) {
        net_cashflow_copy = malloc(sizeof(double));
        if (net_cashflow_copy) *net_cashflow_copy = *net_cashflow;
    }
    double *opening_balance_copy = NULL;
    if (opening_balance) {
        opening_balance_copy = malloc(sizeof(double));
        if (opening_balance_copy) *opening_balance_copy = *opening_balance;
    }
    double *operating_cashflow_copy = NULL;
    if (operating_cashflow) {
        operating_cashflow_copy = malloc(sizeof(double));
        if (operating_cashflow_copy) *operating_cashflow_copy = *operating_cashflow;
    }
    cashflow_report_t *result = cashflow_report_create_internal (
        closing_balance_copy,
        financing_cashflow_copy,
        investing_cashflow_copy,
        net_cashflow_copy,
        opening_balance_copy,
        operating_cashflow_copy,
        period
        );
    if (!result) {
        free(closing_balance_copy);
        free(financing_cashflow_copy);
        free(investing_cashflow_copy);
        free(net_cashflow_copy);
        free(opening_balance_copy);
        free(operating_cashflow_copy);
    }
    return result;
}

void cashflow_report_free(cashflow_report_t *cashflow_report) {
    if(NULL == cashflow_report){
        return ;
    }
    if(cashflow_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cashflow_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cashflow_report->closing_balance) {
        free(cashflow_report->closing_balance);
        cashflow_report->closing_balance = NULL;
    }
    if (cashflow_report->financing_cashflow) {
        free(cashflow_report->financing_cashflow);
        cashflow_report->financing_cashflow = NULL;
    }
    if (cashflow_report->investing_cashflow) {
        free(cashflow_report->investing_cashflow);
        cashflow_report->investing_cashflow = NULL;
    }
    if (cashflow_report->net_cashflow) {
        free(cashflow_report->net_cashflow);
        cashflow_report->net_cashflow = NULL;
    }
    if (cashflow_report->opening_balance) {
        free(cashflow_report->opening_balance);
        cashflow_report->opening_balance = NULL;
    }
    if (cashflow_report->operating_cashflow) {
        free(cashflow_report->operating_cashflow);
        cashflow_report->operating_cashflow = NULL;
    }
    if (cashflow_report->period) {
        free(cashflow_report->period);
        cashflow_report->period = NULL;
    }
    free(cashflow_report);
}

cJSON *cashflow_report_convertToJSON(cashflow_report_t *cashflow_report) {
    cJSON *item = cJSON_CreateObject();

    // cashflow_report->closing_balance
    if (!cashflow_report->closing_balance) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "closing_balance", *cashflow_report->closing_balance) == NULL) {
    goto fail; //Numeric
    }


    // cashflow_report->financing_cashflow
    if (!cashflow_report->financing_cashflow) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "financing_cashflow", *cashflow_report->financing_cashflow) == NULL) {
    goto fail; //Numeric
    }


    // cashflow_report->investing_cashflow
    if (!cashflow_report->investing_cashflow) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "investing_cashflow", *cashflow_report->investing_cashflow) == NULL) {
    goto fail; //Numeric
    }


    // cashflow_report->net_cashflow
    if (!cashflow_report->net_cashflow) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "net_cashflow", *cashflow_report->net_cashflow) == NULL) {
    goto fail; //Numeric
    }


    // cashflow_report->opening_balance
    if (!cashflow_report->opening_balance) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "opening_balance", *cashflow_report->opening_balance) == NULL) {
    goto fail; //Numeric
    }


    // cashflow_report->operating_cashflow
    if (!cashflow_report->operating_cashflow) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "operating_cashflow", *cashflow_report->operating_cashflow) == NULL) {
    goto fail; //Numeric
    }


    // cashflow_report->period
    if (!cashflow_report->period) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "period", cashflow_report->period) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cashflow_report_t *cashflow_report_parseFromJSON(cJSON *cashflow_reportJSON){

    cashflow_report_t *cashflow_report_local_var = NULL;

    // define the local variable for cashflow_report->closing_balance
    double *closing_balance_local_var = NULL;

    // define the local variable for cashflow_report->financing_cashflow
    double *financing_cashflow_local_var = NULL;

    // define the local variable for cashflow_report->investing_cashflow
    double *investing_cashflow_local_var = NULL;

    // define the local variable for cashflow_report->net_cashflow
    double *net_cashflow_local_var = NULL;

    // define the local variable for cashflow_report->opening_balance
    double *opening_balance_local_var = NULL;

    // define the local variable for cashflow_report->operating_cashflow
    double *operating_cashflow_local_var = NULL;

    char *period_local_str = NULL;

    // cashflow_report->closing_balance
    cJSON *closing_balance = cJSON_GetObjectItemCaseSensitive(cashflow_reportJSON, "closing_balance");
    if (cJSON_IsNull(closing_balance)) {
        closing_balance = NULL;
    }
    if (!closing_balance) {
        goto end;
    }

    
    if(!cJSON_IsNumber(closing_balance))
    {
    goto end; //Numeric
    }
    closing_balance_local_var = malloc(sizeof(double));
    if(!closing_balance_local_var)
    {
        goto end;
    }
    *closing_balance_local_var = closing_balance->valuedouble;

    // cashflow_report->financing_cashflow
    cJSON *financing_cashflow = cJSON_GetObjectItemCaseSensitive(cashflow_reportJSON, "financing_cashflow");
    if (cJSON_IsNull(financing_cashflow)) {
        financing_cashflow = NULL;
    }
    if (!financing_cashflow) {
        goto end;
    }

    
    if(!cJSON_IsNumber(financing_cashflow))
    {
    goto end; //Numeric
    }
    financing_cashflow_local_var = malloc(sizeof(double));
    if(!financing_cashflow_local_var)
    {
        goto end;
    }
    *financing_cashflow_local_var = financing_cashflow->valuedouble;

    // cashflow_report->investing_cashflow
    cJSON *investing_cashflow = cJSON_GetObjectItemCaseSensitive(cashflow_reportJSON, "investing_cashflow");
    if (cJSON_IsNull(investing_cashflow)) {
        investing_cashflow = NULL;
    }
    if (!investing_cashflow) {
        goto end;
    }

    
    if(!cJSON_IsNumber(investing_cashflow))
    {
    goto end; //Numeric
    }
    investing_cashflow_local_var = malloc(sizeof(double));
    if(!investing_cashflow_local_var)
    {
        goto end;
    }
    *investing_cashflow_local_var = investing_cashflow->valuedouble;

    // cashflow_report->net_cashflow
    cJSON *net_cashflow = cJSON_GetObjectItemCaseSensitive(cashflow_reportJSON, "net_cashflow");
    if (cJSON_IsNull(net_cashflow)) {
        net_cashflow = NULL;
    }
    if (!net_cashflow) {
        goto end;
    }

    
    if(!cJSON_IsNumber(net_cashflow))
    {
    goto end; //Numeric
    }
    net_cashflow_local_var = malloc(sizeof(double));
    if(!net_cashflow_local_var)
    {
        goto end;
    }
    *net_cashflow_local_var = net_cashflow->valuedouble;

    // cashflow_report->opening_balance
    cJSON *opening_balance = cJSON_GetObjectItemCaseSensitive(cashflow_reportJSON, "opening_balance");
    if (cJSON_IsNull(opening_balance)) {
        opening_balance = NULL;
    }
    if (!opening_balance) {
        goto end;
    }

    
    if(!cJSON_IsNumber(opening_balance))
    {
    goto end; //Numeric
    }
    opening_balance_local_var = malloc(sizeof(double));
    if(!opening_balance_local_var)
    {
        goto end;
    }
    *opening_balance_local_var = opening_balance->valuedouble;

    // cashflow_report->operating_cashflow
    cJSON *operating_cashflow = cJSON_GetObjectItemCaseSensitive(cashflow_reportJSON, "operating_cashflow");
    if (cJSON_IsNull(operating_cashflow)) {
        operating_cashflow = NULL;
    }
    if (!operating_cashflow) {
        goto end;
    }

    
    if(!cJSON_IsNumber(operating_cashflow))
    {
    goto end; //Numeric
    }
    operating_cashflow_local_var = malloc(sizeof(double));
    if(!operating_cashflow_local_var)
    {
        goto end;
    }
    *operating_cashflow_local_var = operating_cashflow->valuedouble;

    // cashflow_report->period
    cJSON *period = cJSON_GetObjectItemCaseSensitive(cashflow_reportJSON, "period");
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


    if (period && !cJSON_IsNull(period)) period_local_str = strdup(period->valuestring);

    cashflow_report_local_var = cashflow_report_create_internal (
        closing_balance_local_var,
        financing_cashflow_local_var,
        investing_cashflow_local_var,
        net_cashflow_local_var,
        opening_balance_local_var,
        operating_cashflow_local_var,
        period_local_str
        );

    if (!cashflow_report_local_var) {
        goto end;
    }

    return cashflow_report_local_var;
end:
    if (closing_balance_local_var) {
        free(closing_balance_local_var);
        closing_balance_local_var = NULL;
    }
    if (financing_cashflow_local_var) {
        free(financing_cashflow_local_var);
        financing_cashflow_local_var = NULL;
    }
    if (investing_cashflow_local_var) {
        free(investing_cashflow_local_var);
        investing_cashflow_local_var = NULL;
    }
    if (net_cashflow_local_var) {
        free(net_cashflow_local_var);
        net_cashflow_local_var = NULL;
    }
    if (opening_balance_local_var) {
        free(opening_balance_local_var);
        opening_balance_local_var = NULL;
    }
    if (operating_cashflow_local_var) {
        free(operating_cashflow_local_var);
        operating_cashflow_local_var = NULL;
    }
    if (period_local_str) {
        free(period_local_str);
        period_local_str = NULL;
    }
    return NULL;

}
