#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payroll_autopay_payload.h"



static payroll_autopay_payload_t *payroll_autopay_payload_create_internal(
    char *debtor_bic,
    char *debtor_iban,
    char *debtor_name,
    char *execution_date
    ) {
    payroll_autopay_payload_t *payroll_autopay_payload_local_var = malloc(sizeof(payroll_autopay_payload_t));
    if (!payroll_autopay_payload_local_var) {
        return NULL;
    }
    memset(payroll_autopay_payload_local_var, 0, sizeof(payroll_autopay_payload_t));
    payroll_autopay_payload_local_var->_library_owned = 1;
    payroll_autopay_payload_local_var->debtor_bic = debtor_bic;
    payroll_autopay_payload_local_var->debtor_iban = debtor_iban;
    payroll_autopay_payload_local_var->debtor_name = debtor_name;
    payroll_autopay_payload_local_var->execution_date = execution_date;
    return payroll_autopay_payload_local_var;
}

__attribute__((deprecated)) payroll_autopay_payload_t *payroll_autopay_payload_create(
    char *debtor_bic,
    char *debtor_iban,
    char *debtor_name,
    char *execution_date
    ) {
    payroll_autopay_payload_t *result = payroll_autopay_payload_create_internal (
        debtor_bic,
        debtor_iban,
        debtor_name,
        execution_date
        );
    if (!result) {
    }
    return result;
}

void payroll_autopay_payload_free(payroll_autopay_payload_t *payroll_autopay_payload) {
    if(NULL == payroll_autopay_payload){
        return ;
    }
    if(payroll_autopay_payload->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payroll_autopay_payload_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payroll_autopay_payload->debtor_bic) {
        free(payroll_autopay_payload->debtor_bic);
        payroll_autopay_payload->debtor_bic = NULL;
    }
    if (payroll_autopay_payload->debtor_iban) {
        free(payroll_autopay_payload->debtor_iban);
        payroll_autopay_payload->debtor_iban = NULL;
    }
    if (payroll_autopay_payload->debtor_name) {
        free(payroll_autopay_payload->debtor_name);
        payroll_autopay_payload->debtor_name = NULL;
    }
    if (payroll_autopay_payload->execution_date) {
        free(payroll_autopay_payload->execution_date);
        payroll_autopay_payload->execution_date = NULL;
    }
    free(payroll_autopay_payload);
}

cJSON *payroll_autopay_payload_convertToJSON(payroll_autopay_payload_t *payroll_autopay_payload) {
    cJSON *item = cJSON_CreateObject();

    // payroll_autopay_payload->debtor_bic
    if(payroll_autopay_payload->debtor_bic) {
    if(cJSON_AddStringToObject(item, "debtor_bic", payroll_autopay_payload->debtor_bic) == NULL) {
    goto fail; //String
    }
    }


    // payroll_autopay_payload->debtor_iban
    if(payroll_autopay_payload->debtor_iban) {
    if(cJSON_AddStringToObject(item, "debtor_iban", payroll_autopay_payload->debtor_iban) == NULL) {
    goto fail; //String
    }
    }


    // payroll_autopay_payload->debtor_name
    if(payroll_autopay_payload->debtor_name) {
    if(cJSON_AddStringToObject(item, "debtor_name", payroll_autopay_payload->debtor_name) == NULL) {
    goto fail; //String
    }
    }


    // payroll_autopay_payload->execution_date
    if(payroll_autopay_payload->execution_date) {
    if(cJSON_AddStringToObject(item, "execution_date", payroll_autopay_payload->execution_date) == NULL) {
    goto fail; //Date
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

payroll_autopay_payload_t *payroll_autopay_payload_parseFromJSON(cJSON *payroll_autopay_payloadJSON){

    payroll_autopay_payload_t *payroll_autopay_payload_local_var = NULL;

    char *debtor_bic_local_str = NULL;

    char *debtor_iban_local_str = NULL;

    char *debtor_name_local_str = NULL;

    char *execution_date_local_str = NULL;

    // payroll_autopay_payload->debtor_bic
    cJSON *debtor_bic = cJSON_GetObjectItemCaseSensitive(payroll_autopay_payloadJSON, "debtor_bic");
    if (cJSON_IsNull(debtor_bic)) {
        debtor_bic = NULL;
    }
    if (debtor_bic) { 
    if(!cJSON_IsString(debtor_bic) && !cJSON_IsNull(debtor_bic))
    {
    goto end; //String
    }
    }

    // payroll_autopay_payload->debtor_iban
    cJSON *debtor_iban = cJSON_GetObjectItemCaseSensitive(payroll_autopay_payloadJSON, "debtor_iban");
    if (cJSON_IsNull(debtor_iban)) {
        debtor_iban = NULL;
    }
    if (debtor_iban) { 
    if(!cJSON_IsString(debtor_iban) && !cJSON_IsNull(debtor_iban))
    {
    goto end; //String
    }
    }

    // payroll_autopay_payload->debtor_name
    cJSON *debtor_name = cJSON_GetObjectItemCaseSensitive(payroll_autopay_payloadJSON, "debtor_name");
    if (cJSON_IsNull(debtor_name)) {
        debtor_name = NULL;
    }
    if (debtor_name) { 
    if(!cJSON_IsString(debtor_name) && !cJSON_IsNull(debtor_name))
    {
    goto end; //String
    }
    }

    // payroll_autopay_payload->execution_date
    cJSON *execution_date = cJSON_GetObjectItemCaseSensitive(payroll_autopay_payloadJSON, "execution_date");
    if (cJSON_IsNull(execution_date)) {
        execution_date = NULL;
    }
    if (execution_date) { 
    if(!cJSON_IsString(execution_date))
    {
    goto end; //Date
    }
    }


    if (debtor_bic && !cJSON_IsNull(debtor_bic)) debtor_bic_local_str = strdup(debtor_bic->valuestring);
    if (debtor_iban && !cJSON_IsNull(debtor_iban)) debtor_iban_local_str = strdup(debtor_iban->valuestring);
    if (debtor_name && !cJSON_IsNull(debtor_name)) debtor_name_local_str = strdup(debtor_name->valuestring);
    if (execution_date) execution_date_local_str = strdup(execution_date->valuestring);

    payroll_autopay_payload_local_var = payroll_autopay_payload_create_internal (
        debtor_bic_local_str,
        debtor_iban_local_str,
        debtor_name_local_str,
        execution_date_local_str
        );

    if (!payroll_autopay_payload_local_var) {
        goto end;
    }

    return payroll_autopay_payload_local_var;
end:
    if (debtor_bic_local_str) {
        free(debtor_bic_local_str);
        debtor_bic_local_str = NULL;
    }
    if (debtor_iban_local_str) {
        free(debtor_iban_local_str);
        debtor_iban_local_str = NULL;
    }
    if (debtor_name_local_str) {
        free(debtor_name_local_str);
        debtor_name_local_str = NULL;
    }
    if (execution_date_local_str) {
        free(execution_date_local_str);
        execution_date_local_str = NULL;
    }
    return NULL;

}
