#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payroll_create_payload.h"



static payroll_create_payload_t *payroll_create_payload_create_internal(
    list_t *employee_ids,
    list_t *extra_payments,
    int *month,
    int *year
    ) {
    payroll_create_payload_t *payroll_create_payload_local_var = malloc(sizeof(payroll_create_payload_t));
    if (!payroll_create_payload_local_var) {
        return NULL;
    }
    memset(payroll_create_payload_local_var, 0, sizeof(payroll_create_payload_t));
    payroll_create_payload_local_var->_library_owned = 1;
    payroll_create_payload_local_var->employee_ids = employee_ids;
    payroll_create_payload_local_var->extra_payments = extra_payments;
    payroll_create_payload_local_var->month = month;
    payroll_create_payload_local_var->year = year;
    return payroll_create_payload_local_var;
}

__attribute__((deprecated)) payroll_create_payload_t *payroll_create_payload_create(
    list_t *employee_ids,
    list_t *extra_payments,
    int *month,
    int *year
    ) {
    int *month_copy = NULL;
    if (month) {
        month_copy = malloc(sizeof(int));
        if (month_copy) *month_copy = *month;
    }
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    payroll_create_payload_t *result = payroll_create_payload_create_internal (
        employee_ids,
        extra_payments,
        month_copy,
        year_copy
        );
    if (!result) {
        free(month_copy);
        free(year_copy);
    }
    return result;
}

void payroll_create_payload_free(payroll_create_payload_t *payroll_create_payload) {
    if(NULL == payroll_create_payload){
        return ;
    }
    if(payroll_create_payload->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payroll_create_payload_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payroll_create_payload->employee_ids) {
        list_ForEach(listEntry, payroll_create_payload->employee_ids) {
            free(listEntry->data);
        }
        list_freeList(payroll_create_payload->employee_ids);
        payroll_create_payload->employee_ids = NULL;
    }
    if (payroll_create_payload->extra_payments) {
        list_ForEach(listEntry, payroll_create_payload->extra_payments) {
            extra_payment_free(listEntry->data);
        }
        list_freeList(payroll_create_payload->extra_payments);
        payroll_create_payload->extra_payments = NULL;
    }
    if (payroll_create_payload->month) {
        free(payroll_create_payload->month);
        payroll_create_payload->month = NULL;
    }
    if (payroll_create_payload->year) {
        free(payroll_create_payload->year);
        payroll_create_payload->year = NULL;
    }
    free(payroll_create_payload);
}

cJSON *payroll_create_payload_convertToJSON(payroll_create_payload_t *payroll_create_payload) {
    cJSON *item = cJSON_CreateObject();

    // payroll_create_payload->employee_ids
    if (!payroll_create_payload->employee_ids) {
        goto fail;
    }
    cJSON *employee_ids = cJSON_AddArrayToObject(item, "employee_ids");
    if(employee_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *employee_idsListEntry;
    list_ForEach(employee_idsListEntry, payroll_create_payload->employee_ids) {
    if(cJSON_AddStringToObject(employee_ids, "", employee_idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // payroll_create_payload->extra_payments
    if(payroll_create_payload->extra_payments) {
    cJSON *extra_payments = cJSON_AddArrayToObject(item, "extra_payments");
    if(extra_payments == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *extra_paymentsListEntry;
    if (payroll_create_payload->extra_payments) {
    list_ForEach(extra_paymentsListEntry, payroll_create_payload->extra_payments) {
    cJSON *itemLocal = extra_payment_convertToJSON(extra_paymentsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(extra_payments, itemLocal);
    }
    }
    }


    // payroll_create_payload->month
    if (!payroll_create_payload->month) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "month", *payroll_create_payload->month) == NULL) {
    goto fail; //Numeric
    }


    // payroll_create_payload->year
    if (!payroll_create_payload->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *payroll_create_payload->year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

payroll_create_payload_t *payroll_create_payload_parseFromJSON(cJSON *payroll_create_payloadJSON){

    payroll_create_payload_t *payroll_create_payload_local_var = NULL;

    // define the local list for payroll_create_payload->employee_ids
    list_t *employee_idsList = NULL;

    // define the local list for payroll_create_payload->extra_payments
    list_t *extra_paymentsList = NULL;

    // define the local variable for payroll_create_payload->month
    int *month_local_var = NULL;

    // define the local variable for payroll_create_payload->year
    int *year_local_var = NULL;

    // payroll_create_payload->employee_ids
    cJSON *employee_ids = cJSON_GetObjectItemCaseSensitive(payroll_create_payloadJSON, "employee_ids");
    if (cJSON_IsNull(employee_ids)) {
        employee_ids = NULL;
    }
    if (!employee_ids) {
        goto end;
    }

    
    cJSON *employee_ids_local = NULL;
    if(!cJSON_IsArray(employee_ids)) {
        goto end;//primitive container
    }
    employee_idsList = list_createList();

    cJSON_ArrayForEach(employee_ids_local, employee_ids)
    {
        if(!cJSON_IsString(employee_ids_local))
        {
            goto end;
        }
        list_addElement(employee_idsList , strdup(employee_ids_local->valuestring));
    }

    // payroll_create_payload->extra_payments
    cJSON *extra_payments = cJSON_GetObjectItemCaseSensitive(payroll_create_payloadJSON, "extra_payments");
    if (cJSON_IsNull(extra_payments)) {
        extra_payments = NULL;
    }
    if (extra_payments) { 
    cJSON *extra_payments_local_nonprimitive = NULL;
    if(!cJSON_IsArray(extra_payments)){
        goto end; //nonprimitive container
    }

    extra_paymentsList = list_createList();

    cJSON_ArrayForEach(extra_payments_local_nonprimitive,extra_payments )
    {
        if(!cJSON_IsObject(extra_payments_local_nonprimitive)){
            goto end;
        }
        extra_payment_t *extra_paymentsItem = extra_payment_parseFromJSON(extra_payments_local_nonprimitive);

        list_addElement(extra_paymentsList, extra_paymentsItem);
    }
    }

    // payroll_create_payload->month
    cJSON *month = cJSON_GetObjectItemCaseSensitive(payroll_create_payloadJSON, "month");
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

    // payroll_create_payload->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(payroll_create_payloadJSON, "year");
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



    payroll_create_payload_local_var = payroll_create_payload_create_internal (
        employee_idsList,
        extra_payments ? extra_paymentsList : NULL,
        month_local_var,
        year_local_var
        );

    if (!payroll_create_payload_local_var) {
        goto end;
    }

    return payroll_create_payload_local_var;
end:
    if (employee_idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, employee_idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(employee_idsList);
        employee_idsList = NULL;
    }
    if (extra_paymentsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, extra_paymentsList) {
            extra_payment_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(extra_paymentsList);
        extra_paymentsList = NULL;
    }
    if (month_local_var) {
        free(month_local_var);
        month_local_var = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    return NULL;

}
