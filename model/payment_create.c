#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payment_create.h"



static payment_create_t *payment_create_create_internal(
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
    payment_create_t *payment_create_local_var = malloc(sizeof(payment_create_t));
    if (!payment_create_local_var) {
        return NULL;
    }
    memset(payment_create_local_var, 0, sizeof(payment_create_t));
    payment_create_local_var->_library_owned = 1;
    payment_create_local_var->amount = amount;
    payment_create_local_var->attachment = attachment;
    payment_create_local_var->currency = currency;
    payment_create_local_var->customer_id = customer_id;
    payment_create_local_var->description = description;
    payment_create_local_var->metadata = metadata;
    payment_create_local_var->method = method;
    payment_create_local_var->payment_date = payment_date;
    payment_create_local_var->reference = reference;
    return payment_create_local_var;
}

__attribute__((deprecated)) payment_create_t *payment_create_create(
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
    payment_create_t *result = payment_create_create_internal (
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

void payment_create_free(payment_create_t *payment_create) {
    if(NULL == payment_create){
        return ;
    }
    if(payment_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payment_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payment_create->amount) {
        free(payment_create->amount);
        payment_create->amount = NULL;
    }
    if (payment_create->attachment) {
        _free(payment_create->attachment);
        payment_create->attachment = NULL;
    }
    if (payment_create->currency) {
        free(payment_create->currency);
        payment_create->currency = NULL;
    }
    if (payment_create->customer_id) {
        free(payment_create->customer_id);
        payment_create->customer_id = NULL;
    }
    if (payment_create->description) {
        free(payment_create->description);
        payment_create->description = NULL;
    }
    if (payment_create->metadata) {
        _free(payment_create->metadata);
        payment_create->metadata = NULL;
    }
    if (payment_create->payment_date) {
        free(payment_create->payment_date);
        payment_create->payment_date = NULL;
    }
    if (payment_create->reference) {
        free(payment_create->reference);
        payment_create->reference = NULL;
    }
    free(payment_create);
}

cJSON *payment_create_convertToJSON(payment_create_t *payment_create) {
    cJSON *item = cJSON_CreateObject();

    // payment_create->amount
    if(payment_create->amount) {
    if(cJSON_AddStringToObject(item, "amount", payment_create->amount) == NULL) {
    goto fail; //String
    }
    }


    // payment_create->attachment
    if(payment_create->attachment) {
    cJSON *attachment_local_JSON = _convertToJSON(payment_create->attachment);
    if(attachment_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "attachment", attachment_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // payment_create->currency
    if(payment_create->currency) {
    if(cJSON_AddStringToObject(item, "currency", payment_create->currency) == NULL) {
    goto fail; //String
    }
    }


    // payment_create->customer_id
    if(payment_create->customer_id) {
    if(cJSON_AddStringToObject(item, "customerId", payment_create->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // payment_create->description
    if(payment_create->description) {
    if(cJSON_AddStringToObject(item, "description", payment_create->description) == NULL) {
    goto fail; //String
    }
    }


    // payment_create->metadata
    if(payment_create->metadata) {
    cJSON *metadata_local_JSON = _convertToJSON(payment_create->metadata);
    if(metadata_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // payment_create->method
    if(payment_create->method != simplebilly_api_payment_method__NULL) {
    cJSON *method_local_JSON = payment_method_convertToJSON(payment_create->method);
    if(method_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "method", method_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // payment_create->payment_date
    if(payment_create->payment_date) {
    if(cJSON_AddStringToObject(item, "paymentDate", payment_create->payment_date) == NULL) {
    goto fail; //Date-Time
    }
    }


    // payment_create->reference
    if(payment_create->reference) {
    if(cJSON_AddStringToObject(item, "reference", payment_create->reference) == NULL) {
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

payment_create_t *payment_create_parseFromJSON(cJSON *payment_createJSON){

    payment_create_t *payment_create_local_var = NULL;

    char *amount_local_str = NULL;

    // define the local variable for payment_create->attachment
    _t *attachment_local_nonprim = NULL;

    char *currency_local_str = NULL;

    char *customer_id_local_str = NULL;

    char *description_local_str = NULL;

    // define the local variable for payment_create->metadata
    _t *metadata_local_nonprim = NULL;

    // define the local variable for payment_create->method
    simplebilly_api_payment_method__e method_local_nonprim = 0;

    char *payment_date_local_str = NULL;

    char *reference_local_str = NULL;

    // payment_create->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(payment_createJSON, "amount");
    if (cJSON_IsNull(amount)) {
        amount = NULL;
    }
    if (amount) { 
    if(!cJSON_IsString(amount) && !cJSON_IsNull(amount))
    {
    goto end; //String
    }
    }

    // payment_create->attachment
    cJSON *attachment = cJSON_GetObjectItemCaseSensitive(payment_createJSON, "attachment");
    if (cJSON_IsNull(attachment)) {
        attachment = NULL;
    }
    if (attachment) { 
    attachment_local_nonprim = _parseFromJSON(attachment); //custom
    }

    // payment_create->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(payment_createJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // payment_create->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(payment_createJSON, "customerId");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // payment_create->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(payment_createJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // payment_create->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(payment_createJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = _parseFromJSON(metadata); //custom
    }

    // payment_create->method
    cJSON *method = cJSON_GetObjectItemCaseSensitive(payment_createJSON, "method");
    if (cJSON_IsNull(method)) {
        method = NULL;
    }
    if (method) { 
    method_local_nonprim = payment_method_parseFromJSON(method); //custom
    }

    // payment_create->payment_date
    cJSON *payment_date = cJSON_GetObjectItemCaseSensitive(payment_createJSON, "paymentDate");
    if (cJSON_IsNull(payment_date)) {
        payment_date = NULL;
    }
    if (payment_date) { 
    if(!cJSON_IsString(payment_date) && !cJSON_IsNull(payment_date))
    {
    goto end; //DateTime
    }
    }

    // payment_create->reference
    cJSON *reference = cJSON_GetObjectItemCaseSensitive(payment_createJSON, "reference");
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

    payment_create_local_var = payment_create_create_internal (
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

    if (!payment_create_local_var) {
        goto end;
    }

    return payment_create_local_var;
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
