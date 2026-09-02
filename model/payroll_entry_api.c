#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payroll_entry_api.h"



static payroll_entry_api_t *payroll_entry_api_create_internal(
    char *av_employee,
    char *av_employer,
    char *church_tax_amount,
    employee_t *employee,
    char *employee_id,
    char *entry_id,
    char *extra_payment_reason,
    char *extra_payments,
    char *gross_salary,
    char *kv_employee,
    char *kv_employer,
    char *lohnsteuer,
    char *net_salary,
    char *notes,
    char *pv_employee,
    char *pv_employer,
    char *run_id,
    char *rv_employee,
    char *rv_employer,
    int *sick_days,
    char *soli,
    simplebilly_api_payroll_run_status__e status,
    char *total_deductions,
    char *total_employer_cost,
    int *vacation_days_used
    ) {
    payroll_entry_api_t *payroll_entry_api_local_var = malloc(sizeof(payroll_entry_api_t));
    if (!payroll_entry_api_local_var) {
        return NULL;
    }
    memset(payroll_entry_api_local_var, 0, sizeof(payroll_entry_api_t));
    payroll_entry_api_local_var->_library_owned = 1;
    payroll_entry_api_local_var->av_employee = av_employee;
    payroll_entry_api_local_var->av_employer = av_employer;
    payroll_entry_api_local_var->church_tax_amount = church_tax_amount;
    payroll_entry_api_local_var->employee = employee;
    payroll_entry_api_local_var->employee_id = employee_id;
    payroll_entry_api_local_var->entry_id = entry_id;
    payroll_entry_api_local_var->extra_payment_reason = extra_payment_reason;
    payroll_entry_api_local_var->extra_payments = extra_payments;
    payroll_entry_api_local_var->gross_salary = gross_salary;
    payroll_entry_api_local_var->kv_employee = kv_employee;
    payroll_entry_api_local_var->kv_employer = kv_employer;
    payroll_entry_api_local_var->lohnsteuer = lohnsteuer;
    payroll_entry_api_local_var->net_salary = net_salary;
    payroll_entry_api_local_var->notes = notes;
    payroll_entry_api_local_var->pv_employee = pv_employee;
    payroll_entry_api_local_var->pv_employer = pv_employer;
    payroll_entry_api_local_var->run_id = run_id;
    payroll_entry_api_local_var->rv_employee = rv_employee;
    payroll_entry_api_local_var->rv_employer = rv_employer;
    payroll_entry_api_local_var->sick_days = sick_days;
    payroll_entry_api_local_var->soli = soli;
    payroll_entry_api_local_var->status = status;
    payroll_entry_api_local_var->total_deductions = total_deductions;
    payroll_entry_api_local_var->total_employer_cost = total_employer_cost;
    payroll_entry_api_local_var->vacation_days_used = vacation_days_used;
    return payroll_entry_api_local_var;
}

__attribute__((deprecated)) payroll_entry_api_t *payroll_entry_api_create(
    char *av_employee,
    char *av_employer,
    char *church_tax_amount,
    employee_t *employee,
    char *employee_id,
    char *entry_id,
    char *extra_payment_reason,
    char *extra_payments,
    char *gross_salary,
    char *kv_employee,
    char *kv_employer,
    char *lohnsteuer,
    char *net_salary,
    char *notes,
    char *pv_employee,
    char *pv_employer,
    char *run_id,
    char *rv_employee,
    char *rv_employer,
    int *sick_days,
    char *soli,
    simplebilly_api_payroll_run_status__e status,
    char *total_deductions,
    char *total_employer_cost,
    int *vacation_days_used
    ) {
    int *sick_days_copy = NULL;
    if (sick_days) {
        sick_days_copy = malloc(sizeof(int));
        if (sick_days_copy) *sick_days_copy = *sick_days;
    }
    int *vacation_days_used_copy = NULL;
    if (vacation_days_used) {
        vacation_days_used_copy = malloc(sizeof(int));
        if (vacation_days_used_copy) *vacation_days_used_copy = *vacation_days_used;
    }
    payroll_entry_api_t *result = payroll_entry_api_create_internal (
        av_employee,
        av_employer,
        church_tax_amount,
        employee,
        employee_id,
        entry_id,
        extra_payment_reason,
        extra_payments,
        gross_salary,
        kv_employee,
        kv_employer,
        lohnsteuer,
        net_salary,
        notes,
        pv_employee,
        pv_employer,
        run_id,
        rv_employee,
        rv_employer,
        sick_days_copy,
        soli,
        status,
        total_deductions,
        total_employer_cost,
        vacation_days_used_copy
        );
    if (!result) {
        free(sick_days_copy);
        free(vacation_days_used_copy);
    }
    return result;
}

void payroll_entry_api_free(payroll_entry_api_t *payroll_entry_api) {
    if(NULL == payroll_entry_api){
        return ;
    }
    if(payroll_entry_api->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payroll_entry_api_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payroll_entry_api->av_employee) {
        free(payroll_entry_api->av_employee);
        payroll_entry_api->av_employee = NULL;
    }
    if (payroll_entry_api->av_employer) {
        free(payroll_entry_api->av_employer);
        payroll_entry_api->av_employer = NULL;
    }
    if (payroll_entry_api->church_tax_amount) {
        free(payroll_entry_api->church_tax_amount);
        payroll_entry_api->church_tax_amount = NULL;
    }
    if (payroll_entry_api->employee) {
        employee_free(payroll_entry_api->employee);
        payroll_entry_api->employee = NULL;
    }
    if (payroll_entry_api->employee_id) {
        free(payroll_entry_api->employee_id);
        payroll_entry_api->employee_id = NULL;
    }
    if (payroll_entry_api->entry_id) {
        free(payroll_entry_api->entry_id);
        payroll_entry_api->entry_id = NULL;
    }
    if (payroll_entry_api->extra_payment_reason) {
        free(payroll_entry_api->extra_payment_reason);
        payroll_entry_api->extra_payment_reason = NULL;
    }
    if (payroll_entry_api->extra_payments) {
        free(payroll_entry_api->extra_payments);
        payroll_entry_api->extra_payments = NULL;
    }
    if (payroll_entry_api->gross_salary) {
        free(payroll_entry_api->gross_salary);
        payroll_entry_api->gross_salary = NULL;
    }
    if (payroll_entry_api->kv_employee) {
        free(payroll_entry_api->kv_employee);
        payroll_entry_api->kv_employee = NULL;
    }
    if (payroll_entry_api->kv_employer) {
        free(payroll_entry_api->kv_employer);
        payroll_entry_api->kv_employer = NULL;
    }
    if (payroll_entry_api->lohnsteuer) {
        free(payroll_entry_api->lohnsteuer);
        payroll_entry_api->lohnsteuer = NULL;
    }
    if (payroll_entry_api->net_salary) {
        free(payroll_entry_api->net_salary);
        payroll_entry_api->net_salary = NULL;
    }
    if (payroll_entry_api->notes) {
        free(payroll_entry_api->notes);
        payroll_entry_api->notes = NULL;
    }
    if (payroll_entry_api->pv_employee) {
        free(payroll_entry_api->pv_employee);
        payroll_entry_api->pv_employee = NULL;
    }
    if (payroll_entry_api->pv_employer) {
        free(payroll_entry_api->pv_employer);
        payroll_entry_api->pv_employer = NULL;
    }
    if (payroll_entry_api->run_id) {
        free(payroll_entry_api->run_id);
        payroll_entry_api->run_id = NULL;
    }
    if (payroll_entry_api->rv_employee) {
        free(payroll_entry_api->rv_employee);
        payroll_entry_api->rv_employee = NULL;
    }
    if (payroll_entry_api->rv_employer) {
        free(payroll_entry_api->rv_employer);
        payroll_entry_api->rv_employer = NULL;
    }
    if (payroll_entry_api->sick_days) {
        free(payroll_entry_api->sick_days);
        payroll_entry_api->sick_days = NULL;
    }
    if (payroll_entry_api->soli) {
        free(payroll_entry_api->soli);
        payroll_entry_api->soli = NULL;
    }
    if (payroll_entry_api->total_deductions) {
        free(payroll_entry_api->total_deductions);
        payroll_entry_api->total_deductions = NULL;
    }
    if (payroll_entry_api->total_employer_cost) {
        free(payroll_entry_api->total_employer_cost);
        payroll_entry_api->total_employer_cost = NULL;
    }
    if (payroll_entry_api->vacation_days_used) {
        free(payroll_entry_api->vacation_days_used);
        payroll_entry_api->vacation_days_used = NULL;
    }
    free(payroll_entry_api);
}

cJSON *payroll_entry_api_convertToJSON(payroll_entry_api_t *payroll_entry_api) {
    cJSON *item = cJSON_CreateObject();

    // payroll_entry_api->av_employee
    if (!payroll_entry_api->av_employee) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "av_employee", payroll_entry_api->av_employee) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->av_employer
    if (!payroll_entry_api->av_employer) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "av_employer", payroll_entry_api->av_employer) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->church_tax_amount
    if (!payroll_entry_api->church_tax_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "church_tax_amount", payroll_entry_api->church_tax_amount) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->employee
    if(payroll_entry_api->employee) {
    cJSON *employee_local_JSON = employee_convertToJSON(payroll_entry_api->employee);
    if(employee_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "employee", employee_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // payroll_entry_api->employee_id
    if (!payroll_entry_api->employee_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "employee_id", payroll_entry_api->employee_id) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->entry_id
    if (!payroll_entry_api->entry_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "entry_id", payroll_entry_api->entry_id) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->extra_payment_reason
    if(payroll_entry_api->extra_payment_reason) {
    if(cJSON_AddStringToObject(item, "extra_payment_reason", payroll_entry_api->extra_payment_reason) == NULL) {
    goto fail; //String
    }
    }


    // payroll_entry_api->extra_payments
    if (!payroll_entry_api->extra_payments) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "extra_payments", payroll_entry_api->extra_payments) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->gross_salary
    if (!payroll_entry_api->gross_salary) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gross_salary", payroll_entry_api->gross_salary) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->kv_employee
    if (!payroll_entry_api->kv_employee) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kv_employee", payroll_entry_api->kv_employee) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->kv_employer
    if (!payroll_entry_api->kv_employer) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kv_employer", payroll_entry_api->kv_employer) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->lohnsteuer
    if (!payroll_entry_api->lohnsteuer) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "lohnsteuer", payroll_entry_api->lohnsteuer) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->net_salary
    if (!payroll_entry_api->net_salary) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "net_salary", payroll_entry_api->net_salary) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->notes
    if(payroll_entry_api->notes) {
    if(cJSON_AddStringToObject(item, "notes", payroll_entry_api->notes) == NULL) {
    goto fail; //String
    }
    }


    // payroll_entry_api->pv_employee
    if (!payroll_entry_api->pv_employee) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pv_employee", payroll_entry_api->pv_employee) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->pv_employer
    if (!payroll_entry_api->pv_employer) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pv_employer", payroll_entry_api->pv_employer) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->run_id
    if (!payroll_entry_api->run_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "run_id", payroll_entry_api->run_id) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->rv_employee
    if (!payroll_entry_api->rv_employee) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "rv_employee", payroll_entry_api->rv_employee) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->rv_employer
    if (!payroll_entry_api->rv_employer) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "rv_employer", payroll_entry_api->rv_employer) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->sick_days
    if (!payroll_entry_api->sick_days) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "sick_days", *payroll_entry_api->sick_days) == NULL) {
    goto fail; //Numeric
    }


    // payroll_entry_api->soli
    if (!payroll_entry_api->soli) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "soli", payroll_entry_api->soli) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->status
    if (simplebilly_api_payroll_run_status__NULL == payroll_entry_api->status) {
        goto fail;
    }
    cJSON *status_local_JSON = payroll_run_status_convertToJSON(payroll_entry_api->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // payroll_entry_api->total_deductions
    if (!payroll_entry_api->total_deductions) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_deductions", payroll_entry_api->total_deductions) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->total_employer_cost
    if (!payroll_entry_api->total_employer_cost) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_employer_cost", payroll_entry_api->total_employer_cost) == NULL) {
    goto fail; //String
    }


    // payroll_entry_api->vacation_days_used
    if (!payroll_entry_api->vacation_days_used) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "vacation_days_used", *payroll_entry_api->vacation_days_used) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

payroll_entry_api_t *payroll_entry_api_parseFromJSON(cJSON *payroll_entry_apiJSON){

    payroll_entry_api_t *payroll_entry_api_local_var = NULL;

    char *av_employee_local_str = NULL;

    char *av_employer_local_str = NULL;

    char *church_tax_amount_local_str = NULL;

    // define the local variable for payroll_entry_api->employee
    employee_t *employee_local_nonprim = NULL;

    char *employee_id_local_str = NULL;

    char *entry_id_local_str = NULL;

    char *extra_payment_reason_local_str = NULL;

    char *extra_payments_local_str = NULL;

    char *gross_salary_local_str = NULL;

    char *kv_employee_local_str = NULL;

    char *kv_employer_local_str = NULL;

    char *lohnsteuer_local_str = NULL;

    char *net_salary_local_str = NULL;

    char *notes_local_str = NULL;

    char *pv_employee_local_str = NULL;

    char *pv_employer_local_str = NULL;

    char *run_id_local_str = NULL;

    char *rv_employee_local_str = NULL;

    char *rv_employer_local_str = NULL;

    // define the local variable for payroll_entry_api->sick_days
    int *sick_days_local_var = NULL;

    char *soli_local_str = NULL;

    // define the local variable for payroll_entry_api->status
    simplebilly_api_payroll_run_status__e status_local_nonprim = 0;

    char *total_deductions_local_str = NULL;

    char *total_employer_cost_local_str = NULL;

    // define the local variable for payroll_entry_api->vacation_days_used
    int *vacation_days_used_local_var = NULL;

    // payroll_entry_api->av_employee
    cJSON *av_employee = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "av_employee");
    if (cJSON_IsNull(av_employee)) {
        av_employee = NULL;
    }
    if (!av_employee) {
        goto end;
    }

    
    if(!cJSON_IsString(av_employee))
    {
    goto end; //String
    }

    // payroll_entry_api->av_employer
    cJSON *av_employer = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "av_employer");
    if (cJSON_IsNull(av_employer)) {
        av_employer = NULL;
    }
    if (!av_employer) {
        goto end;
    }

    
    if(!cJSON_IsString(av_employer))
    {
    goto end; //String
    }

    // payroll_entry_api->church_tax_amount
    cJSON *church_tax_amount = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "church_tax_amount");
    if (cJSON_IsNull(church_tax_amount)) {
        church_tax_amount = NULL;
    }
    if (!church_tax_amount) {
        goto end;
    }

    
    if(!cJSON_IsString(church_tax_amount))
    {
    goto end; //String
    }

    // payroll_entry_api->employee
    cJSON *employee = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "employee");
    if (cJSON_IsNull(employee)) {
        employee = NULL;
    }
    if (employee) { 
    employee_local_nonprim = employee_parseFromJSON(employee); //nonprimitive
    }

    // payroll_entry_api->employee_id
    cJSON *employee_id = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "employee_id");
    if (cJSON_IsNull(employee_id)) {
        employee_id = NULL;
    }
    if (!employee_id) {
        goto end;
    }

    
    if(!cJSON_IsString(employee_id))
    {
    goto end; //String
    }

    // payroll_entry_api->entry_id
    cJSON *entry_id = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "entry_id");
    if (cJSON_IsNull(entry_id)) {
        entry_id = NULL;
    }
    if (!entry_id) {
        goto end;
    }

    
    if(!cJSON_IsString(entry_id))
    {
    goto end; //String
    }

    // payroll_entry_api->extra_payment_reason
    cJSON *extra_payment_reason = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "extra_payment_reason");
    if (cJSON_IsNull(extra_payment_reason)) {
        extra_payment_reason = NULL;
    }
    if (extra_payment_reason) { 
    if(!cJSON_IsString(extra_payment_reason) && !cJSON_IsNull(extra_payment_reason))
    {
    goto end; //String
    }
    }

    // payroll_entry_api->extra_payments
    cJSON *extra_payments = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "extra_payments");
    if (cJSON_IsNull(extra_payments)) {
        extra_payments = NULL;
    }
    if (!extra_payments) {
        goto end;
    }

    
    if(!cJSON_IsString(extra_payments))
    {
    goto end; //String
    }

    // payroll_entry_api->gross_salary
    cJSON *gross_salary = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "gross_salary");
    if (cJSON_IsNull(gross_salary)) {
        gross_salary = NULL;
    }
    if (!gross_salary) {
        goto end;
    }

    
    if(!cJSON_IsString(gross_salary))
    {
    goto end; //String
    }

    // payroll_entry_api->kv_employee
    cJSON *kv_employee = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "kv_employee");
    if (cJSON_IsNull(kv_employee)) {
        kv_employee = NULL;
    }
    if (!kv_employee) {
        goto end;
    }

    
    if(!cJSON_IsString(kv_employee))
    {
    goto end; //String
    }

    // payroll_entry_api->kv_employer
    cJSON *kv_employer = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "kv_employer");
    if (cJSON_IsNull(kv_employer)) {
        kv_employer = NULL;
    }
    if (!kv_employer) {
        goto end;
    }

    
    if(!cJSON_IsString(kv_employer))
    {
    goto end; //String
    }

    // payroll_entry_api->lohnsteuer
    cJSON *lohnsteuer = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "lohnsteuer");
    if (cJSON_IsNull(lohnsteuer)) {
        lohnsteuer = NULL;
    }
    if (!lohnsteuer) {
        goto end;
    }

    
    if(!cJSON_IsString(lohnsteuer))
    {
    goto end; //String
    }

    // payroll_entry_api->net_salary
    cJSON *net_salary = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "net_salary");
    if (cJSON_IsNull(net_salary)) {
        net_salary = NULL;
    }
    if (!net_salary) {
        goto end;
    }

    
    if(!cJSON_IsString(net_salary))
    {
    goto end; //String
    }

    // payroll_entry_api->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // payroll_entry_api->pv_employee
    cJSON *pv_employee = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "pv_employee");
    if (cJSON_IsNull(pv_employee)) {
        pv_employee = NULL;
    }
    if (!pv_employee) {
        goto end;
    }

    
    if(!cJSON_IsString(pv_employee))
    {
    goto end; //String
    }

    // payroll_entry_api->pv_employer
    cJSON *pv_employer = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "pv_employer");
    if (cJSON_IsNull(pv_employer)) {
        pv_employer = NULL;
    }
    if (!pv_employer) {
        goto end;
    }

    
    if(!cJSON_IsString(pv_employer))
    {
    goto end; //String
    }

    // payroll_entry_api->run_id
    cJSON *run_id = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "run_id");
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

    // payroll_entry_api->rv_employee
    cJSON *rv_employee = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "rv_employee");
    if (cJSON_IsNull(rv_employee)) {
        rv_employee = NULL;
    }
    if (!rv_employee) {
        goto end;
    }

    
    if(!cJSON_IsString(rv_employee))
    {
    goto end; //String
    }

    // payroll_entry_api->rv_employer
    cJSON *rv_employer = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "rv_employer");
    if (cJSON_IsNull(rv_employer)) {
        rv_employer = NULL;
    }
    if (!rv_employer) {
        goto end;
    }

    
    if(!cJSON_IsString(rv_employer))
    {
    goto end; //String
    }

    // payroll_entry_api->sick_days
    cJSON *sick_days = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "sick_days");
    if (cJSON_IsNull(sick_days)) {
        sick_days = NULL;
    }
    if (!sick_days) {
        goto end;
    }

    
    if(!cJSON_IsNumber(sick_days))
    {
    goto end; //Numeric
    }
    sick_days_local_var = malloc(sizeof(int));
    if(!sick_days_local_var)
    {
        goto end;
    }
    *sick_days_local_var = sick_days->valuedouble;

    // payroll_entry_api->soli
    cJSON *soli = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "soli");
    if (cJSON_IsNull(soli)) {
        soli = NULL;
    }
    if (!soli) {
        goto end;
    }

    
    if(!cJSON_IsString(soli))
    {
    goto end; //String
    }

    // payroll_entry_api->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = payroll_run_status_parseFromJSON(status); //custom

    // payroll_entry_api->total_deductions
    cJSON *total_deductions = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "total_deductions");
    if (cJSON_IsNull(total_deductions)) {
        total_deductions = NULL;
    }
    if (!total_deductions) {
        goto end;
    }

    
    if(!cJSON_IsString(total_deductions))
    {
    goto end; //String
    }

    // payroll_entry_api->total_employer_cost
    cJSON *total_employer_cost = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "total_employer_cost");
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

    // payroll_entry_api->vacation_days_used
    cJSON *vacation_days_used = cJSON_GetObjectItemCaseSensitive(payroll_entry_apiJSON, "vacation_days_used");
    if (cJSON_IsNull(vacation_days_used)) {
        vacation_days_used = NULL;
    }
    if (!vacation_days_used) {
        goto end;
    }

    
    if(!cJSON_IsNumber(vacation_days_used))
    {
    goto end; //Numeric
    }
    vacation_days_used_local_var = malloc(sizeof(int));
    if(!vacation_days_used_local_var)
    {
        goto end;
    }
    *vacation_days_used_local_var = vacation_days_used->valuedouble;


    if (av_employee && !cJSON_IsNull(av_employee)) av_employee_local_str = strdup(av_employee->valuestring);
    if (av_employer && !cJSON_IsNull(av_employer)) av_employer_local_str = strdup(av_employer->valuestring);
    if (church_tax_amount && !cJSON_IsNull(church_tax_amount)) church_tax_amount_local_str = strdup(church_tax_amount->valuestring);
    if (employee_id && !cJSON_IsNull(employee_id)) employee_id_local_str = strdup(employee_id->valuestring);
    if (entry_id && !cJSON_IsNull(entry_id)) entry_id_local_str = strdup(entry_id->valuestring);
    if (extra_payment_reason && !cJSON_IsNull(extra_payment_reason)) extra_payment_reason_local_str = strdup(extra_payment_reason->valuestring);
    if (extra_payments && !cJSON_IsNull(extra_payments)) extra_payments_local_str = strdup(extra_payments->valuestring);
    if (gross_salary && !cJSON_IsNull(gross_salary)) gross_salary_local_str = strdup(gross_salary->valuestring);
    if (kv_employee && !cJSON_IsNull(kv_employee)) kv_employee_local_str = strdup(kv_employee->valuestring);
    if (kv_employer && !cJSON_IsNull(kv_employer)) kv_employer_local_str = strdup(kv_employer->valuestring);
    if (lohnsteuer && !cJSON_IsNull(lohnsteuer)) lohnsteuer_local_str = strdup(lohnsteuer->valuestring);
    if (net_salary && !cJSON_IsNull(net_salary)) net_salary_local_str = strdup(net_salary->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (pv_employee && !cJSON_IsNull(pv_employee)) pv_employee_local_str = strdup(pv_employee->valuestring);
    if (pv_employer && !cJSON_IsNull(pv_employer)) pv_employer_local_str = strdup(pv_employer->valuestring);
    if (run_id && !cJSON_IsNull(run_id)) run_id_local_str = strdup(run_id->valuestring);
    if (rv_employee && !cJSON_IsNull(rv_employee)) rv_employee_local_str = strdup(rv_employee->valuestring);
    if (rv_employer && !cJSON_IsNull(rv_employer)) rv_employer_local_str = strdup(rv_employer->valuestring);
    if (soli && !cJSON_IsNull(soli)) soli_local_str = strdup(soli->valuestring);
    if (total_deductions && !cJSON_IsNull(total_deductions)) total_deductions_local_str = strdup(total_deductions->valuestring);
    if (total_employer_cost && !cJSON_IsNull(total_employer_cost)) total_employer_cost_local_str = strdup(total_employer_cost->valuestring);

    payroll_entry_api_local_var = payroll_entry_api_create_internal (
        av_employee_local_str,
        av_employer_local_str,
        church_tax_amount_local_str,
        employee ? employee_local_nonprim : NULL,
        employee_id_local_str,
        entry_id_local_str,
        extra_payment_reason_local_str,
        extra_payments_local_str,
        gross_salary_local_str,
        kv_employee_local_str,
        kv_employer_local_str,
        lohnsteuer_local_str,
        net_salary_local_str,
        notes_local_str,
        pv_employee_local_str,
        pv_employer_local_str,
        run_id_local_str,
        rv_employee_local_str,
        rv_employer_local_str,
        sick_days_local_var,
        soli_local_str,
        status_local_nonprim,
        total_deductions_local_str,
        total_employer_cost_local_str,
        vacation_days_used_local_var
        );

    if (!payroll_entry_api_local_var) {
        goto end;
    }

    return payroll_entry_api_local_var;
end:
    if (av_employee_local_str) {
        free(av_employee_local_str);
        av_employee_local_str = NULL;
    }
    if (av_employer_local_str) {
        free(av_employer_local_str);
        av_employer_local_str = NULL;
    }
    if (church_tax_amount_local_str) {
        free(church_tax_amount_local_str);
        church_tax_amount_local_str = NULL;
    }
    if (employee_local_nonprim) {
        employee_free(employee_local_nonprim);
        employee_local_nonprim = NULL;
    }
    if (employee_id_local_str) {
        free(employee_id_local_str);
        employee_id_local_str = NULL;
    }
    if (entry_id_local_str) {
        free(entry_id_local_str);
        entry_id_local_str = NULL;
    }
    if (extra_payment_reason_local_str) {
        free(extra_payment_reason_local_str);
        extra_payment_reason_local_str = NULL;
    }
    if (extra_payments_local_str) {
        free(extra_payments_local_str);
        extra_payments_local_str = NULL;
    }
    if (gross_salary_local_str) {
        free(gross_salary_local_str);
        gross_salary_local_str = NULL;
    }
    if (kv_employee_local_str) {
        free(kv_employee_local_str);
        kv_employee_local_str = NULL;
    }
    if (kv_employer_local_str) {
        free(kv_employer_local_str);
        kv_employer_local_str = NULL;
    }
    if (lohnsteuer_local_str) {
        free(lohnsteuer_local_str);
        lohnsteuer_local_str = NULL;
    }
    if (net_salary_local_str) {
        free(net_salary_local_str);
        net_salary_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (pv_employee_local_str) {
        free(pv_employee_local_str);
        pv_employee_local_str = NULL;
    }
    if (pv_employer_local_str) {
        free(pv_employer_local_str);
        pv_employer_local_str = NULL;
    }
    if (run_id_local_str) {
        free(run_id_local_str);
        run_id_local_str = NULL;
    }
    if (rv_employee_local_str) {
        free(rv_employee_local_str);
        rv_employee_local_str = NULL;
    }
    if (rv_employer_local_str) {
        free(rv_employer_local_str);
        rv_employer_local_str = NULL;
    }
    if (sick_days_local_var) {
        free(sick_days_local_var);
        sick_days_local_var = NULL;
    }
    if (soli_local_str) {
        free(soli_local_str);
        soli_local_str = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    if (total_deductions_local_str) {
        free(total_deductions_local_str);
        total_deductions_local_str = NULL;
    }
    if (total_employer_cost_local_str) {
        free(total_employer_cost_local_str);
        total_employer_cost_local_str = NULL;
    }
    if (vacation_days_used_local_var) {
        free(vacation_days_used_local_var);
        vacation_days_used_local_var = NULL;
    }
    return NULL;

}
