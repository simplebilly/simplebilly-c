#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payroll_summary_item.h"



static payroll_summary_item_t *payroll_summary_item_create_internal(
    int *employee_count,
    char *month,
    simplebilly_api_payroll_run_status__e status,
    char *total_employer_cost,
    char *total_gross,
    char *total_net,
    int *year
    ) {
    payroll_summary_item_t *payroll_summary_item_local_var = malloc(sizeof(payroll_summary_item_t));
    if (!payroll_summary_item_local_var) {
        return NULL;
    }
    memset(payroll_summary_item_local_var, 0, sizeof(payroll_summary_item_t));
    payroll_summary_item_local_var->_library_owned = 1;
    payroll_summary_item_local_var->employee_count = employee_count;
    payroll_summary_item_local_var->month = month;
    payroll_summary_item_local_var->status = status;
    payroll_summary_item_local_var->total_employer_cost = total_employer_cost;
    payroll_summary_item_local_var->total_gross = total_gross;
    payroll_summary_item_local_var->total_net = total_net;
    payroll_summary_item_local_var->year = year;
    return payroll_summary_item_local_var;
}

__attribute__((deprecated)) payroll_summary_item_t *payroll_summary_item_create(
    int *employee_count,
    char *month,
    simplebilly_api_payroll_run_status__e status,
    char *total_employer_cost,
    char *total_gross,
    char *total_net,
    int *year
    ) {
    int *employee_count_copy = NULL;
    if (employee_count) {
        employee_count_copy = malloc(sizeof(int));
        if (employee_count_copy) *employee_count_copy = *employee_count;
    }
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    payroll_summary_item_t *result = payroll_summary_item_create_internal (
        employee_count_copy,
        month,
        status,
        total_employer_cost,
        total_gross,
        total_net,
        year_copy
        );
    if (!result) {
        free(employee_count_copy);
        free(year_copy);
    }
    return result;
}

void payroll_summary_item_free(payroll_summary_item_t *payroll_summary_item) {
    if(NULL == payroll_summary_item){
        return ;
    }
    if(payroll_summary_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payroll_summary_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payroll_summary_item->employee_count) {
        free(payroll_summary_item->employee_count);
        payroll_summary_item->employee_count = NULL;
    }
    if (payroll_summary_item->month) {
        free(payroll_summary_item->month);
        payroll_summary_item->month = NULL;
    }
    if (payroll_summary_item->total_employer_cost) {
        free(payroll_summary_item->total_employer_cost);
        payroll_summary_item->total_employer_cost = NULL;
    }
    if (payroll_summary_item->total_gross) {
        free(payroll_summary_item->total_gross);
        payroll_summary_item->total_gross = NULL;
    }
    if (payroll_summary_item->total_net) {
        free(payroll_summary_item->total_net);
        payroll_summary_item->total_net = NULL;
    }
    if (payroll_summary_item->year) {
        free(payroll_summary_item->year);
        payroll_summary_item->year = NULL;
    }
    free(payroll_summary_item);
}

cJSON *payroll_summary_item_convertToJSON(payroll_summary_item_t *payroll_summary_item) {
    cJSON *item = cJSON_CreateObject();

    // payroll_summary_item->employee_count
    if (!payroll_summary_item->employee_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "employee_count", *payroll_summary_item->employee_count) == NULL) {
    goto fail; //Numeric
    }


    // payroll_summary_item->month
    if (!payroll_summary_item->month) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "month", payroll_summary_item->month) == NULL) {
    goto fail; //String
    }


    // payroll_summary_item->status
    if (simplebilly_api_payroll_run_status__NULL == payroll_summary_item->status) {
        goto fail;
    }
    cJSON *status_local_JSON = payroll_run_status_convertToJSON(payroll_summary_item->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // payroll_summary_item->total_employer_cost
    if (!payroll_summary_item->total_employer_cost) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_employer_cost", payroll_summary_item->total_employer_cost) == NULL) {
    goto fail; //String
    }


    // payroll_summary_item->total_gross
    if (!payroll_summary_item->total_gross) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_gross", payroll_summary_item->total_gross) == NULL) {
    goto fail; //String
    }


    // payroll_summary_item->total_net
    if (!payroll_summary_item->total_net) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_net", payroll_summary_item->total_net) == NULL) {
    goto fail; //String
    }


    // payroll_summary_item->year
    if (!payroll_summary_item->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *payroll_summary_item->year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

payroll_summary_item_t *payroll_summary_item_parseFromJSON(cJSON *payroll_summary_itemJSON){

    payroll_summary_item_t *payroll_summary_item_local_var = NULL;

    // define the local variable for payroll_summary_item->employee_count
    int *employee_count_local_var = NULL;

    char *month_local_str = NULL;

    // define the local variable for payroll_summary_item->status
    simplebilly_api_payroll_run_status__e status_local_nonprim = 0;

    char *total_employer_cost_local_str = NULL;

    char *total_gross_local_str = NULL;

    char *total_net_local_str = NULL;

    // define the local variable for payroll_summary_item->year
    int *year_local_var = NULL;

    // payroll_summary_item->employee_count
    cJSON *employee_count = cJSON_GetObjectItemCaseSensitive(payroll_summary_itemJSON, "employee_count");
    if (cJSON_IsNull(employee_count)) {
        employee_count = NULL;
    }
    if (!employee_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(employee_count))
    {
    goto end; //Numeric
    }
    employee_count_local_var = malloc(sizeof(int));
    if(!employee_count_local_var)
    {
        goto end;
    }
    *employee_count_local_var = employee_count->valuedouble;

    // payroll_summary_item->month
    cJSON *month = cJSON_GetObjectItemCaseSensitive(payroll_summary_itemJSON, "month");
    if (cJSON_IsNull(month)) {
        month = NULL;
    }
    if (!month) {
        goto end;
    }

    
    if(!cJSON_IsString(month))
    {
    goto end; //String
    }

    // payroll_summary_item->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(payroll_summary_itemJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = payroll_run_status_parseFromJSON(status); //custom

    // payroll_summary_item->total_employer_cost
    cJSON *total_employer_cost = cJSON_GetObjectItemCaseSensitive(payroll_summary_itemJSON, "total_employer_cost");
    if (cJSON_IsNull(total_employer_cost)) {
        total_employer_cost = NULL;
    }
    if (!total_employer_cost) {
        goto end;
    }

    
    if(!cJSON_IsString(total_employer_cost))
    {
    goto end; //String
    }

    // payroll_summary_item->total_gross
    cJSON *total_gross = cJSON_GetObjectItemCaseSensitive(payroll_summary_itemJSON, "total_gross");
    if (cJSON_IsNull(total_gross)) {
        total_gross = NULL;
    }
    if (!total_gross) {
        goto end;
    }

    
    if(!cJSON_IsString(total_gross))
    {
    goto end; //String
    }

    // payroll_summary_item->total_net
    cJSON *total_net = cJSON_GetObjectItemCaseSensitive(payroll_summary_itemJSON, "total_net");
    if (cJSON_IsNull(total_net)) {
        total_net = NULL;
    }
    if (!total_net) {
        goto end;
    }

    
    if(!cJSON_IsString(total_net))
    {
    goto end; //String
    }

    // payroll_summary_item->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(payroll_summary_itemJSON, "year");
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


    if (month && !cJSON_IsNull(month)) month_local_str = strdup(month->valuestring);
    if (total_employer_cost && !cJSON_IsNull(total_employer_cost)) total_employer_cost_local_str = strdup(total_employer_cost->valuestring);
    if (total_gross && !cJSON_IsNull(total_gross)) total_gross_local_str = strdup(total_gross->valuestring);
    if (total_net && !cJSON_IsNull(total_net)) total_net_local_str = strdup(total_net->valuestring);

    payroll_summary_item_local_var = payroll_summary_item_create_internal (
        employee_count_local_var,
        month_local_str,
        status_local_nonprim,
        total_employer_cost_local_str,
        total_gross_local_str,
        total_net_local_str,
        year_local_var
        );

    if (!payroll_summary_item_local_var) {
        goto end;
    }

    return payroll_summary_item_local_var;
end:
    if (employee_count_local_var) {
        free(employee_count_local_var);
        employee_count_local_var = NULL;
    }
    if (month_local_str) {
        free(month_local_str);
        month_local_str = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    if (total_employer_cost_local_str) {
        free(total_employer_cost_local_str);
        total_employer_cost_local_str = NULL;
    }
    if (total_gross_local_str) {
        free(total_gross_local_str);
        total_gross_local_str = NULL;
    }
    if (total_net_local_str) {
        free(total_net_local_str);
        total_net_local_str = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    return NULL;

}
