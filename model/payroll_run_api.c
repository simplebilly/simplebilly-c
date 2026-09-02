#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payroll_run_api.h"



static payroll_run_api_t *payroll_run_api_create_internal(
    char *approved_at,
    char *approved_by,
    char *created_at,
    list_t *entries,
    int *month,
    char *payment_date,
    char *period_label,
    char *run_id,
    simplebilly_api_payroll_run_status__e status,
    char *tenant_id,
    int *total_employee_count,
    char *total_employer_cost,
    char *total_gross,
    char *total_net,
    char *total_social_security,
    char *total_taxes,
    char *updated_at,
    int *year
    ) {
    payroll_run_api_t *payroll_run_api_local_var = malloc(sizeof(payroll_run_api_t));
    if (!payroll_run_api_local_var) {
        return NULL;
    }
    memset(payroll_run_api_local_var, 0, sizeof(payroll_run_api_t));
    payroll_run_api_local_var->_library_owned = 1;
    payroll_run_api_local_var->approved_at = approved_at;
    payroll_run_api_local_var->approved_by = approved_by;
    payroll_run_api_local_var->created_at = created_at;
    payroll_run_api_local_var->entries = entries;
    payroll_run_api_local_var->month = month;
    payroll_run_api_local_var->payment_date = payment_date;
    payroll_run_api_local_var->period_label = period_label;
    payroll_run_api_local_var->run_id = run_id;
    payroll_run_api_local_var->status = status;
    payroll_run_api_local_var->tenant_id = tenant_id;
    payroll_run_api_local_var->total_employee_count = total_employee_count;
    payroll_run_api_local_var->total_employer_cost = total_employer_cost;
    payroll_run_api_local_var->total_gross = total_gross;
    payroll_run_api_local_var->total_net = total_net;
    payroll_run_api_local_var->total_social_security = total_social_security;
    payroll_run_api_local_var->total_taxes = total_taxes;
    payroll_run_api_local_var->updated_at = updated_at;
    payroll_run_api_local_var->year = year;
    return payroll_run_api_local_var;
}

__attribute__((deprecated)) payroll_run_api_t *payroll_run_api_create(
    char *approved_at,
    char *approved_by,
    char *created_at,
    list_t *entries,
    int *month,
    char *payment_date,
    char *period_label,
    char *run_id,
    simplebilly_api_payroll_run_status__e status,
    char *tenant_id,
    int *total_employee_count,
    char *total_employer_cost,
    char *total_gross,
    char *total_net,
    char *total_social_security,
    char *total_taxes,
    char *updated_at,
    int *year
    ) {
    int *month_copy = NULL;
    if (month) {
        month_copy = malloc(sizeof(int));
        if (month_copy) *month_copy = *month;
    }
    int *total_employee_count_copy = NULL;
    if (total_employee_count) {
        total_employee_count_copy = malloc(sizeof(int));
        if (total_employee_count_copy) *total_employee_count_copy = *total_employee_count;
    }
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    payroll_run_api_t *result = payroll_run_api_create_internal (
        approved_at,
        approved_by,
        created_at,
        entries,
        month_copy,
        payment_date,
        period_label,
        run_id,
        status,
        tenant_id,
        total_employee_count_copy,
        total_employer_cost,
        total_gross,
        total_net,
        total_social_security,
        total_taxes,
        updated_at,
        year_copy
        );
    if (!result) {
        free(month_copy);
        free(total_employee_count_copy);
        free(year_copy);
    }
    return result;
}

void payroll_run_api_free(payroll_run_api_t *payroll_run_api) {
    if(NULL == payroll_run_api){
        return ;
    }
    if(payroll_run_api->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payroll_run_api_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payroll_run_api->approved_at) {
        free(payroll_run_api->approved_at);
        payroll_run_api->approved_at = NULL;
    }
    if (payroll_run_api->approved_by) {
        free(payroll_run_api->approved_by);
        payroll_run_api->approved_by = NULL;
    }
    if (payroll_run_api->created_at) {
        free(payroll_run_api->created_at);
        payroll_run_api->created_at = NULL;
    }
    if (payroll_run_api->entries) {
        list_ForEach(listEntry, payroll_run_api->entries) {
            payroll_entry_api_free(listEntry->data);
        }
        list_freeList(payroll_run_api->entries);
        payroll_run_api->entries = NULL;
    }
    if (payroll_run_api->month) {
        free(payroll_run_api->month);
        payroll_run_api->month = NULL;
    }
    if (payroll_run_api->payment_date) {
        free(payroll_run_api->payment_date);
        payroll_run_api->payment_date = NULL;
    }
    if (payroll_run_api->period_label) {
        free(payroll_run_api->period_label);
        payroll_run_api->period_label = NULL;
    }
    if (payroll_run_api->run_id) {
        free(payroll_run_api->run_id);
        payroll_run_api->run_id = NULL;
    }
    if (payroll_run_api->tenant_id) {
        free(payroll_run_api->tenant_id);
        payroll_run_api->tenant_id = NULL;
    }
    if (payroll_run_api->total_employee_count) {
        free(payroll_run_api->total_employee_count);
        payroll_run_api->total_employee_count = NULL;
    }
    if (payroll_run_api->total_employer_cost) {
        free(payroll_run_api->total_employer_cost);
        payroll_run_api->total_employer_cost = NULL;
    }
    if (payroll_run_api->total_gross) {
        free(payroll_run_api->total_gross);
        payroll_run_api->total_gross = NULL;
    }
    if (payroll_run_api->total_net) {
        free(payroll_run_api->total_net);
        payroll_run_api->total_net = NULL;
    }
    if (payroll_run_api->total_social_security) {
        free(payroll_run_api->total_social_security);
        payroll_run_api->total_social_security = NULL;
    }
    if (payroll_run_api->total_taxes) {
        free(payroll_run_api->total_taxes);
        payroll_run_api->total_taxes = NULL;
    }
    if (payroll_run_api->updated_at) {
        free(payroll_run_api->updated_at);
        payroll_run_api->updated_at = NULL;
    }
    if (payroll_run_api->year) {
        free(payroll_run_api->year);
        payroll_run_api->year = NULL;
    }
    free(payroll_run_api);
}

cJSON *payroll_run_api_convertToJSON(payroll_run_api_t *payroll_run_api) {
    cJSON *item = cJSON_CreateObject();

    // payroll_run_api->approved_at
    if(payroll_run_api->approved_at) {
    if(cJSON_AddStringToObject(item, "approved_at", payroll_run_api->approved_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // payroll_run_api->approved_by
    if(payroll_run_api->approved_by) {
    if(cJSON_AddStringToObject(item, "approved_by", payroll_run_api->approved_by) == NULL) {
    goto fail; //String
    }
    }


    // payroll_run_api->created_at
    if (!payroll_run_api->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", payroll_run_api->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // payroll_run_api->entries
    if (!payroll_run_api->entries) {
        goto fail;
    }
    cJSON *entries = cJSON_AddArrayToObject(item, "entries");
    if(entries == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entriesListEntry;
    if (payroll_run_api->entries) {
    list_ForEach(entriesListEntry, payroll_run_api->entries) {
    cJSON *itemLocal = payroll_entry_api_convertToJSON(entriesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entries, itemLocal);
    }
    }


    // payroll_run_api->month
    if (!payroll_run_api->month) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "month", *payroll_run_api->month) == NULL) {
    goto fail; //Numeric
    }


    // payroll_run_api->payment_date
    if(payroll_run_api->payment_date) {
    if(cJSON_AddStringToObject(item, "payment_date", payroll_run_api->payment_date) == NULL) {
    goto fail; //Date
    }
    }


    // payroll_run_api->period_label
    if (!payroll_run_api->period_label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "period_label", payroll_run_api->period_label) == NULL) {
    goto fail; //String
    }


    // payroll_run_api->run_id
    if (!payroll_run_api->run_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "run_id", payroll_run_api->run_id) == NULL) {
    goto fail; //String
    }


    // payroll_run_api->status
    if (simplebilly_api_payroll_run_status__NULL == payroll_run_api->status) {
        goto fail;
    }
    cJSON *status_local_JSON = payroll_run_status_convertToJSON(payroll_run_api->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // payroll_run_api->tenant_id
    if (!payroll_run_api->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenant_id", payroll_run_api->tenant_id) == NULL) {
    goto fail; //String
    }


    // payroll_run_api->total_employee_count
    if (!payroll_run_api->total_employee_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_employee_count", *payroll_run_api->total_employee_count) == NULL) {
    goto fail; //Numeric
    }


    // payroll_run_api->total_employer_cost
    if (!payroll_run_api->total_employer_cost) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_employer_cost", payroll_run_api->total_employer_cost) == NULL) {
    goto fail; //String
    }


    // payroll_run_api->total_gross
    if (!payroll_run_api->total_gross) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_gross", payroll_run_api->total_gross) == NULL) {
    goto fail; //String
    }


    // payroll_run_api->total_net
    if (!payroll_run_api->total_net) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_net", payroll_run_api->total_net) == NULL) {
    goto fail; //String
    }


    // payroll_run_api->total_social_security
    if (!payroll_run_api->total_social_security) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_social_security", payroll_run_api->total_social_security) == NULL) {
    goto fail; //String
    }


    // payroll_run_api->total_taxes
    if (!payroll_run_api->total_taxes) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_taxes", payroll_run_api->total_taxes) == NULL) {
    goto fail; //String
    }


    // payroll_run_api->updated_at
    if(payroll_run_api->updated_at) {
    if(cJSON_AddStringToObject(item, "updated_at", payroll_run_api->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // payroll_run_api->year
    if (!payroll_run_api->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *payroll_run_api->year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

payroll_run_api_t *payroll_run_api_parseFromJSON(cJSON *payroll_run_apiJSON){

    payroll_run_api_t *payroll_run_api_local_var = NULL;

    char *approved_at_local_str = NULL;

    char *approved_by_local_str = NULL;

    char *created_at_local_str = NULL;

    // define the local list for payroll_run_api->entries
    list_t *entriesList = NULL;

    // define the local variable for payroll_run_api->month
    int *month_local_var = NULL;

    char *payment_date_local_str = NULL;

    char *period_label_local_str = NULL;

    char *run_id_local_str = NULL;

    // define the local variable for payroll_run_api->status
    simplebilly_api_payroll_run_status__e status_local_nonprim = 0;

    char *tenant_id_local_str = NULL;

    // define the local variable for payroll_run_api->total_employee_count
    int *total_employee_count_local_var = NULL;

    char *total_employer_cost_local_str = NULL;

    char *total_gross_local_str = NULL;

    char *total_net_local_str = NULL;

    char *total_social_security_local_str = NULL;

    char *total_taxes_local_str = NULL;

    char *updated_at_local_str = NULL;

    // define the local variable for payroll_run_api->year
    int *year_local_var = NULL;

    // payroll_run_api->approved_at
    cJSON *approved_at = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "approved_at");
    if (cJSON_IsNull(approved_at)) {
        approved_at = NULL;
    }
    if (approved_at) { 
    if(!cJSON_IsString(approved_at) && !cJSON_IsNull(approved_at))
    {
    goto end; //DateTime
    }
    }

    // payroll_run_api->approved_by
    cJSON *approved_by = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "approved_by");
    if (cJSON_IsNull(approved_by)) {
        approved_by = NULL;
    }
    if (approved_by) { 
    if(!cJSON_IsString(approved_by) && !cJSON_IsNull(approved_by))
    {
    goto end; //String
    }
    }

    // payroll_run_api->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "created_at");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // payroll_run_api->entries
    cJSON *entries = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "entries");
    if (cJSON_IsNull(entries)) {
        entries = NULL;
    }
    if (!entries) {
        goto end;
    }

    
    cJSON *entries_local_nonprimitive = NULL;
    if(!cJSON_IsArray(entries)){
        goto end; //nonprimitive container
    }

    entriesList = list_createList();

    cJSON_ArrayForEach(entries_local_nonprimitive,entries )
    {
        if(!cJSON_IsObject(entries_local_nonprimitive)){
            goto end;
        }
        payroll_entry_api_t *entriesItem = payroll_entry_api_parseFromJSON(entries_local_nonprimitive);

        list_addElement(entriesList, entriesItem);
    }

    // payroll_run_api->month
    cJSON *month = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "month");
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

    // payroll_run_api->payment_date
    cJSON *payment_date = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "payment_date");
    if (cJSON_IsNull(payment_date)) {
        payment_date = NULL;
    }
    if (payment_date) { 
    if(!cJSON_IsString(payment_date))
    {
    goto end; //Date
    }
    }

    // payroll_run_api->period_label
    cJSON *period_label = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "period_label");
    if (cJSON_IsNull(period_label)) {
        period_label = NULL;
    }
    if (!period_label) {
        goto end;
    }

    
    if(!cJSON_IsString(period_label))
    {
    goto end; //String
    }

    // payroll_run_api->run_id
    cJSON *run_id = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "run_id");
    if (cJSON_IsNull(run_id)) {
        run_id = NULL;
    }
    if (!run_id) {
        goto end;
    }

    
    if(!cJSON_IsString(run_id))
    {
    goto end; //String
    }

    // payroll_run_api->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = payroll_run_status_parseFromJSON(status); //custom

    // payroll_run_api->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "tenant_id");
    if (cJSON_IsNull(tenant_id)) {
        tenant_id = NULL;
    }
    if (!tenant_id) {
        goto end;
    }

    
    if(!cJSON_IsString(tenant_id))
    {
    goto end; //String
    }

    // payroll_run_api->total_employee_count
    cJSON *total_employee_count = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "total_employee_count");
    if (cJSON_IsNull(total_employee_count)) {
        total_employee_count = NULL;
    }
    if (!total_employee_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_employee_count))
    {
    goto end; //Numeric
    }
    total_employee_count_local_var = malloc(sizeof(int));
    if(!total_employee_count_local_var)
    {
        goto end;
    }
    *total_employee_count_local_var = total_employee_count->valuedouble;

    // payroll_run_api->total_employer_cost
    cJSON *total_employer_cost = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "total_employer_cost");
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

    // payroll_run_api->total_gross
    cJSON *total_gross = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "total_gross");
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

    // payroll_run_api->total_net
    cJSON *total_net = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "total_net");
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

    // payroll_run_api->total_social_security
    cJSON *total_social_security = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "total_social_security");
    if (cJSON_IsNull(total_social_security)) {
        total_social_security = NULL;
    }
    if (!total_social_security) {
        goto end;
    }

    
    if(!cJSON_IsString(total_social_security))
    {
    goto end; //String
    }

    // payroll_run_api->total_taxes
    cJSON *total_taxes = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "total_taxes");
    if (cJSON_IsNull(total_taxes)) {
        total_taxes = NULL;
    }
    if (!total_taxes) {
        goto end;
    }

    
    if(!cJSON_IsString(total_taxes))
    {
    goto end; //String
    }

    // payroll_run_api->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "updated_at");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }

    // payroll_run_api->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(payroll_run_apiJSON, "year");
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


    if (approved_at && !cJSON_IsNull(approved_at)) approved_at_local_str = strdup(approved_at->valuestring);
    if (approved_by && !cJSON_IsNull(approved_by)) approved_by_local_str = strdup(approved_by->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (payment_date) payment_date_local_str = strdup(payment_date->valuestring);
    if (period_label && !cJSON_IsNull(period_label)) period_label_local_str = strdup(period_label->valuestring);
    if (run_id && !cJSON_IsNull(run_id)) run_id_local_str = strdup(run_id->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (total_employer_cost && !cJSON_IsNull(total_employer_cost)) total_employer_cost_local_str = strdup(total_employer_cost->valuestring);
    if (total_gross && !cJSON_IsNull(total_gross)) total_gross_local_str = strdup(total_gross->valuestring);
    if (total_net && !cJSON_IsNull(total_net)) total_net_local_str = strdup(total_net->valuestring);
    if (total_social_security && !cJSON_IsNull(total_social_security)) total_social_security_local_str = strdup(total_social_security->valuestring);
    if (total_taxes && !cJSON_IsNull(total_taxes)) total_taxes_local_str = strdup(total_taxes->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    payroll_run_api_local_var = payroll_run_api_create_internal (
        approved_at_local_str,
        approved_by_local_str,
        created_at_local_str,
        entriesList,
        month_local_var,
        payment_date_local_str,
        period_label_local_str,
        run_id_local_str,
        status_local_nonprim,
        tenant_id_local_str,
        total_employee_count_local_var,
        total_employer_cost_local_str,
        total_gross_local_str,
        total_net_local_str,
        total_social_security_local_str,
        total_taxes_local_str,
        updated_at_local_str,
        year_local_var
        );

    if (!payroll_run_api_local_var) {
        goto end;
    }

    return payroll_run_api_local_var;
end:
    if (approved_at_local_str) {
        free(approved_at_local_str);
        approved_at_local_str = NULL;
    }
    if (approved_by_local_str) {
        free(approved_by_local_str);
        approved_by_local_str = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (entriesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, entriesList) {
            payroll_entry_api_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(entriesList);
        entriesList = NULL;
    }
    if (month_local_var) {
        free(month_local_var);
        month_local_var = NULL;
    }
    if (payment_date_local_str) {
        free(payment_date_local_str);
        payment_date_local_str = NULL;
    }
    if (period_label_local_str) {
        free(period_label_local_str);
        period_label_local_str = NULL;
    }
    if (run_id_local_str) {
        free(run_id_local_str);
        run_id_local_str = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (total_employee_count_local_var) {
        free(total_employee_count_local_var);
        total_employee_count_local_var = NULL;
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
    if (total_social_security_local_str) {
        free(total_social_security_local_str);
        total_social_security_local_str = NULL;
    }
    if (total_taxes_local_str) {
        free(total_taxes_local_str);
        total_taxes_local_str = NULL;
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
