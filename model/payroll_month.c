#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payroll_month.h"



static payroll_month_t *payroll_month_create_internal(
    char *gross,
    int *month,
    char *net
    ) {
    payroll_month_t *payroll_month_local_var = malloc(sizeof(payroll_month_t));
    if (!payroll_month_local_var) {
        return NULL;
    }
    memset(payroll_month_local_var, 0, sizeof(payroll_month_t));
    payroll_month_local_var->_library_owned = 1;
    payroll_month_local_var->gross = gross;
    payroll_month_local_var->month = month;
    payroll_month_local_var->net = net;
    return payroll_month_local_var;
}

__attribute__((deprecated)) payroll_month_t *payroll_month_create(
    char *gross,
    int *month,
    char *net
    ) {
    int *month_copy = NULL;
    if (month) {
        month_copy = malloc(sizeof(int));
        if (month_copy) *month_copy = *month;
    }
    payroll_month_t *result = payroll_month_create_internal (
        gross,
        month_copy,
        net
        );
    if (!result) {
        free(month_copy);
    }
    return result;
}

void payroll_month_free(payroll_month_t *payroll_month) {
    if(NULL == payroll_month){
        return ;
    }
    if(payroll_month->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payroll_month_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payroll_month->gross) {
        free(payroll_month->gross);
        payroll_month->gross = NULL;
    }
    if (payroll_month->month) {
        free(payroll_month->month);
        payroll_month->month = NULL;
    }
    if (payroll_month->net) {
        free(payroll_month->net);
        payroll_month->net = NULL;
    }
    free(payroll_month);
}

cJSON *payroll_month_convertToJSON(payroll_month_t *payroll_month) {
    cJSON *item = cJSON_CreateObject();

    // payroll_month->gross
    if (!payroll_month->gross) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gross", payroll_month->gross) == NULL) {
    goto fail; //String
    }


    // payroll_month->month
    if (!payroll_month->month) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "month", *payroll_month->month) == NULL) {
    goto fail; //Numeric
    }


    // payroll_month->net
    if (!payroll_month->net) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "net", payroll_month->net) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

payroll_month_t *payroll_month_parseFromJSON(cJSON *payroll_monthJSON){

    payroll_month_t *payroll_month_local_var = NULL;

    char *gross_local_str = NULL;

    // define the local variable for payroll_month->month
    int *month_local_var = NULL;

    char *net_local_str = NULL;

    // payroll_month->gross
    cJSON *gross = cJSON_GetObjectItemCaseSensitive(payroll_monthJSON, "gross");
    if (cJSON_IsNull(gross)) {
        gross = NULL;
    }
    if (!gross) {
        goto end;
    }

    
    if(!cJSON_IsString(gross))
    {
    goto end; //String
    }

    // payroll_month->month
    cJSON *month = cJSON_GetObjectItemCaseSensitive(payroll_monthJSON, "month");
    if (cJSON_IsNull(month)) {
        month = NULL;
    }
    if (!month) {
        goto end;
    }

    
    if(!cJSON_IsNumber(month))
    {
    goto end; //Numeric
    }
    month_local_var = malloc(sizeof(int));
    if(!month_local_var)
    {
        goto end;
    }
    *month_local_var = month->valuedouble;

    // payroll_month->net
    cJSON *net = cJSON_GetObjectItemCaseSensitive(payroll_monthJSON, "net");
    if (cJSON_IsNull(net)) {
        net = NULL;
    }
    if (!net) {
        goto end;
    }

    
    if(!cJSON_IsString(net))
    {
    goto end; //String
    }


    if (gross && !cJSON_IsNull(gross)) gross_local_str = strdup(gross->valuestring);
    if (net && !cJSON_IsNull(net)) net_local_str = strdup(net->valuestring);

    payroll_month_local_var = payroll_month_create_internal (
        gross_local_str,
        month_local_var,
        net_local_str
        );

    if (!payroll_month_local_var) {
        goto end;
    }

    return payroll_month_local_var;
end:
    if (gross_local_str) {
        free(gross_local_str);
        gross_local_str = NULL;
    }
    if (month_local_var) {
        free(month_local_var);
        month_local_var = NULL;
    }
    if (net_local_str) {
        free(net_local_str);
        net_local_str = NULL;
    }
    return NULL;

}
