#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payroll_pay_payload.h"



static payroll_pay_payload_t *payroll_pay_payload_create_internal(
    char *payment_date
    ) {
    payroll_pay_payload_t *payroll_pay_payload_local_var = malloc(sizeof(payroll_pay_payload_t));
    if (!payroll_pay_payload_local_var) {
        return NULL;
    }
    memset(payroll_pay_payload_local_var, 0, sizeof(payroll_pay_payload_t));
    payroll_pay_payload_local_var->_library_owned = 1;
    payroll_pay_payload_local_var->payment_date = payment_date;
    return payroll_pay_payload_local_var;
}

__attribute__((deprecated)) payroll_pay_payload_t *payroll_pay_payload_create(
    char *payment_date
    ) {
    payroll_pay_payload_t *result = payroll_pay_payload_create_internal (
        payment_date
        );
    if (!result) {
    }
    return result;
}

void payroll_pay_payload_free(payroll_pay_payload_t *payroll_pay_payload) {
    if(NULL == payroll_pay_payload){
        return ;
    }
    if(payroll_pay_payload->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payroll_pay_payload_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payroll_pay_payload->payment_date) {
        free(payroll_pay_payload->payment_date);
        payroll_pay_payload->payment_date = NULL;
    }
    free(payroll_pay_payload);
}

cJSON *payroll_pay_payload_convertToJSON(payroll_pay_payload_t *payroll_pay_payload) {
    cJSON *item = cJSON_CreateObject();

    // payroll_pay_payload->payment_date
    if (!payroll_pay_payload->payment_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payment_date", payroll_pay_payload->payment_date) == NULL) {
    goto fail; //Date
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

payroll_pay_payload_t *payroll_pay_payload_parseFromJSON(cJSON *payroll_pay_payloadJSON){

    payroll_pay_payload_t *payroll_pay_payload_local_var = NULL;

    char *payment_date_local_str = NULL;

    // payroll_pay_payload->payment_date
    cJSON *payment_date = cJSON_GetObjectItemCaseSensitive(payroll_pay_payloadJSON, "payment_date");
    if (cJSON_IsNull(payment_date)) {
        payment_date = NULL;
    }
    if (!payment_date) {
        goto end;
    }

    
    if(!cJSON_IsString(payment_date))
    {
    goto end; //Date
    }


    if (payment_date) payment_date_local_str = strdup(payment_date->valuestring);

    payroll_pay_payload_local_var = payroll_pay_payload_create_internal (
        payment_date_local_str
        );

    if (!payroll_pay_payload_local_var) {
        goto end;
    }

    return payroll_pay_payload_local_var;
end:
    if (payment_date_local_str) {
        free(payment_date_local_str);
        payment_date_local_str = NULL;
    }
    return NULL;

}
