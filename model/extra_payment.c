#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extra_payment.h"



static extra_payment_t *extra_payment_create_internal(
    char *amount,
    char *employee_id,
    char *reason
    ) {
    extra_payment_t *extra_payment_local_var = malloc(sizeof(extra_payment_t));
    if (!extra_payment_local_var) {
        return NULL;
    }
    memset(extra_payment_local_var, 0, sizeof(extra_payment_t));
    extra_payment_local_var->_library_owned = 1;
    extra_payment_local_var->amount = amount;
    extra_payment_local_var->employee_id = employee_id;
    extra_payment_local_var->reason = reason;
    return extra_payment_local_var;
}

__attribute__((deprecated)) extra_payment_t *extra_payment_create(
    char *amount,
    char *employee_id,
    char *reason
    ) {
    extra_payment_t *result = extra_payment_create_internal (
        amount,
        employee_id,
        reason
        );
    if (!result) {
    }
    return result;
}

void extra_payment_free(extra_payment_t *extra_payment) {
    if(NULL == extra_payment){
        return ;
    }
    if(extra_payment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "extra_payment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (extra_payment->amount) {
        free(extra_payment->amount);
        extra_payment->amount = NULL;
    }
    if (extra_payment->employee_id) {
        free(extra_payment->employee_id);
        extra_payment->employee_id = NULL;
    }
    if (extra_payment->reason) {
        free(extra_payment->reason);
        extra_payment->reason = NULL;
    }
    free(extra_payment);
}

cJSON *extra_payment_convertToJSON(extra_payment_t *extra_payment) {
    cJSON *item = cJSON_CreateObject();

    // extra_payment->amount
    if (!extra_payment->amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amount", extra_payment->amount) == NULL) {
    goto fail; //String
    }


    // extra_payment->employee_id
    if (!extra_payment->employee_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "employee_id", extra_payment->employee_id) == NULL) {
    goto fail; //String
    }


    // extra_payment->reason
    if(extra_payment->reason) {
    if(cJSON_AddStringToObject(item, "reason", extra_payment->reason) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

extra_payment_t *extra_payment_parseFromJSON(cJSON *extra_paymentJSON){

    extra_payment_t *extra_payment_local_var = NULL;

    char *amount_local_str = NULL;

    char *employee_id_local_str = NULL;

    char *reason_local_str = NULL;

    // extra_payment->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(extra_paymentJSON, "amount");
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

    // extra_payment->employee_id
    cJSON *employee_id = cJSON_GetObjectItemCaseSensitive(extra_paymentJSON, "employee_id");
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

    // extra_payment->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(extra_paymentJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    if (amount && !cJSON_IsNull(amount)) amount_local_str = strdup(amount->valuestring);
    if (employee_id && !cJSON_IsNull(employee_id)) employee_id_local_str = strdup(employee_id->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);

    extra_payment_local_var = extra_payment_create_internal (
        amount_local_str,
        employee_id_local_str,
        reason_local_str
        );

    if (!extra_payment_local_var) {
        goto end;
    }

    return extra_payment_local_var;
end:
    if (amount_local_str) {
        free(amount_local_str);
        amount_local_str = NULL;
    }
    if (employee_id_local_str) {
        free(employee_id_local_str);
        employee_id_local_str = NULL;
    }
    if (reason_local_str) {
        free(reason_local_str);
        reason_local_str = NULL;
    }
    return NULL;

}
