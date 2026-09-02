#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payment.h"



static payment_t *payment_create_internal(
    char *amount,
    any_type_t *attachment,
    char *currency,
    char *customer_id,
    char *description,
    any_type_t *metadata,
    simplebilly_api_payment_method__e method,
    char *payment_date,
    char *reference
    ) {
    payment_t *payment_local_var = malloc(sizeof(payment_t));
    if (!payment_local_var) {
        return NULL;
    }
    memset(payment_local_var, 0, sizeof(payment_t));
    payment_local_var->_library_owned = 1;
    payment_local_var->amount = amount;
    payment_local_var->attachment = attachment;
    payment_local_var->currency = currency;
    payment_local_var->customer_id = customer_id;
    payment_local_var->description = description;
    payment_local_var->metadata = metadata;
    payment_local_var->method = method;
    payment_local_var->payment_date = payment_date;
    payment_local_var->reference = reference;
    return payment_local_var;
}

__attribute__((deprecated)) payment_t *payment_create(
    char *amount,
    any_type_t *attachment,
    char *currency,
    char *customer_id,
    char *description,
    any_type_t *metadata,
    simplebilly_api_payment_method__e method,
    char *payment_date,
    char *reference
    ) {
    payment_t *result = payment_create_internal (
        amount,
        attachment,
        currency,
        customer_id,
        description,
        metadata,
        method,
        payment_date,
        reference
        );
    if (!result) {
    }
    return result;
}

void payment_free(payment_t *payment) {
    if(NULL == payment){
        return ;
    }
    if(payment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payment->amount) {
        free(payment->amount);
        payment->amount = NULL;
    }
    if (payment->attachment) {
        _free(payment->attachment);
        payment->attachment = NULL;
    }
    if (payment->currency) {
        free(payment->currency);
        payment->currency = NULL;
    }
    if (payment->customer_id) {
        free(payment->customer_id);
        payment->customer_id = NULL;
    }
    if (payment->description) {
        free(payment->description);
        payment->description = NULL;
    }
    if (payment->metadata) {
        _free(payment->metadata);
        payment->metadata = NULL;
    }
    if (payment->payment_date) {
        free(payment->payment_date);
        payment->payment_date = NULL;
    }
    if (payment->reference) {
        free(payment->reference);
        payment->reference = NULL;
    }
    free(payment);
}

cJSON *payment_convertToJSON(payment_t *payment) {
    cJSON *item = cJSON_CreateObject();

    // payment->amount
    if(payment->amount) {
    if(cJSON_AddStringToObject(item, "amount", payment->amount) == NULL) {
    goto fail; //String
    }
    }


    // payment->attachment
    if(payment->attachment) {
    cJSON *attachment_local_JSON = _convertToJSON(payment->attachment);
    if(attachment_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "attachment", attachment_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // payment->currency
    if(payment->currency) {
    if(cJSON_AddStringToObject(item, "currency", payment->currency) == NULL) {
    goto fail; //String
    }
    }


    // payment->customer_id
    if(payment->customer_id) {
    if(cJSON_AddStringToObject(item, "customerId", payment->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // payment->description
    if(payment->description) {
    if(cJSON_AddStringToObject(item, "description", payment->description) == NULL) {
    goto fail; //String
    }
    }


    // payment->metadata
    if(payment->metadata) {
    cJSON *metadata_local_JSON = _convertToJSON(payment->metadata);
    if(metadata_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // payment->method
    if(payment->method != simplebilly_api_payment_method__NULL) {
    cJSON *method_local_JSON = payment_method_convertToJSON(payment->method);
    if(method_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "method", method_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // payment->payment_date
    if(payment->payment_date) {
    if(cJSON_AddStringToObject(item, "paymentDate", payment->payment_date) == NULL) {
    goto fail; //Date-Time
    }
    }


    // payment->reference
    if(payment->reference) {
    if(cJSON_AddStringToObject(item, "reference", payment->reference) == NULL) {
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

payment_t *payment_parseFromJSON(cJSON *paymentJSON){

    payment_t *payment_local_var = NULL;

    char *amount_local_str = NULL;

    // define the local variable for payment->attachment
    _t *attachment_local_nonprim = NULL;

    char *currency_local_str = NULL;

    char *customer_id_local_str = NULL;

    char *description_local_str = NULL;

    // define the local variable for payment->metadata
    _t *metadata_local_nonprim = NULL;

    // define the local variable for payment->method
    simplebilly_api_payment_method__e method_local_nonprim = 0;

    char *payment_date_local_str = NULL;

    char *reference_local_str = NULL;

    // payment->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(paymentJSON, "amount");
    if (cJSON_IsNull(amount)) {
        amount = NULL;
    }
    if (amount) { 
    if(!cJSON_IsString(amount) && !cJSON_IsNull(amount))
    {
    goto end; //String
    }
    }

    // payment->attachment
    cJSON *attachment = cJSON_GetObjectItemCaseSensitive(paymentJSON, "attachment");
    if (cJSON_IsNull(attachment)) {
        attachment = NULL;
    }
    if (attachment) { 
    attachment_local_nonprim = _parseFromJSON(attachment); //custom
    }

    // payment->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(paymentJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // payment->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(paymentJSON, "customerId");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // payment->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(paymentJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // payment->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(paymentJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = _parseFromJSON(metadata); //custom
    }

    // payment->method
    cJSON *method = cJSON_GetObjectItemCaseSensitive(paymentJSON, "method");
    if (cJSON_IsNull(method)) {
        method = NULL;
    }
    if (method) { 
    method_local_nonprim = payment_method_parseFromJSON(method); //custom
    }

    // payment->payment_date
    cJSON *payment_date = cJSON_GetObjectItemCaseSensitive(paymentJSON, "paymentDate");
    if (cJSON_IsNull(payment_date)) {
        payment_date = NULL;
    }
    if (payment_date) { 
    if(!cJSON_IsString(payment_date) && !cJSON_IsNull(payment_date))
    {
    goto end; //DateTime
    }
    }

    // payment->reference
    cJSON *reference = cJSON_GetObjectItemCaseSensitive(paymentJSON, "reference");
    if (cJSON_IsNull(reference)) {
        reference = NULL;
    }
    if (reference) { 
    if(!cJSON_IsString(reference) && !cJSON_IsNull(reference))
    {
    goto end; //String
    }
    }


    if (amount && !cJSON_IsNull(amount)) amount_local_str = strdup(amount->valuestring);
    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (payment_date && !cJSON_IsNull(payment_date)) payment_date_local_str = strdup(payment_date->valuestring);
    if (reference && !cJSON_IsNull(reference)) reference_local_str = strdup(reference->valuestring);

    payment_local_var = payment_create_internal (
        amount_local_str,
        attachment ? attachment_local_nonprim : NULL,
        currency_local_str,
        customer_id_local_str,
        description_local_str,
        metadata ? metadata_local_nonprim : NULL,
        method ? method_local_nonprim : 0,
        payment_date_local_str,
        reference_local_str
        );

    if (!payment_local_var) {
        goto end;
    }

    return payment_local_var;
end:
    if (amount_local_str) {
        free(amount_local_str);
        amount_local_str = NULL;
    }
    if (attachment_local_nonprim) {
        _free(attachment_local_nonprim);
        attachment_local_nonprim = NULL;
    }
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (customer_id_local_str) {
        free(customer_id_local_str);
        customer_id_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (metadata_local_nonprim) {
        _free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (method_local_nonprim) {
        method_local_nonprim = 0;
    }
    if (payment_date_local_str) {
        free(payment_date_local_str);
        payment_date_local_str = NULL;
    }
    if (reference_local_str) {
        free(reference_local_str);
        reference_local_str = NULL;
    }
    return NULL;

}
