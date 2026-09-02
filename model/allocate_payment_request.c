#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "allocate_payment_request.h"



static allocate_payment_request_t *allocate_payment_request_create_internal(
    double *amount,
    char *invoice_id,
    char *payment_id
    ) {
    allocate_payment_request_t *allocate_payment_request_local_var = malloc(sizeof(allocate_payment_request_t));
    if (!allocate_payment_request_local_var) {
        return NULL;
    }
    memset(allocate_payment_request_local_var, 0, sizeof(allocate_payment_request_t));
    allocate_payment_request_local_var->_library_owned = 1;
    allocate_payment_request_local_var->amount = amount;
    allocate_payment_request_local_var->invoice_id = invoice_id;
    allocate_payment_request_local_var->payment_id = payment_id;
    return allocate_payment_request_local_var;
}

__attribute__((deprecated)) allocate_payment_request_t *allocate_payment_request_create(
    double *amount,
    char *invoice_id,
    char *payment_id
    ) {
    double *amount_copy = NULL;
    if (amount) {
        amount_copy = malloc(sizeof(double));
        if (amount_copy) *amount_copy = *amount;
    }
    allocate_payment_request_t *result = allocate_payment_request_create_internal (
        amount_copy,
        invoice_id,
        payment_id
        );
    if (!result) {
        free(amount_copy);
    }
    return result;
}

void allocate_payment_request_free(allocate_payment_request_t *allocate_payment_request) {
    if(NULL == allocate_payment_request){
        return ;
    }
    if(allocate_payment_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "allocate_payment_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (allocate_payment_request->amount) {
        free(allocate_payment_request->amount);
        allocate_payment_request->amount = NULL;
    }
    if (allocate_payment_request->invoice_id) {
        free(allocate_payment_request->invoice_id);
        allocate_payment_request->invoice_id = NULL;
    }
    if (allocate_payment_request->payment_id) {
        free(allocate_payment_request->payment_id);
        allocate_payment_request->payment_id = NULL;
    }
    free(allocate_payment_request);
}

cJSON *allocate_payment_request_convertToJSON(allocate_payment_request_t *allocate_payment_request) {
    cJSON *item = cJSON_CreateObject();

    // allocate_payment_request->amount
    if (!allocate_payment_request->amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "amount", *allocate_payment_request->amount) == NULL) {
    goto fail; //Numeric
    }


    // allocate_payment_request->invoice_id
    if (!allocate_payment_request->invoice_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoice_id", allocate_payment_request->invoice_id) == NULL) {
    goto fail; //String
    }


    // allocate_payment_request->payment_id
    if (!allocate_payment_request->payment_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payment_id", allocate_payment_request->payment_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

allocate_payment_request_t *allocate_payment_request_parseFromJSON(cJSON *allocate_payment_requestJSON){

    allocate_payment_request_t *allocate_payment_request_local_var = NULL;

    // define the local variable for allocate_payment_request->amount
    double *amount_local_var = NULL;

    char *invoice_id_local_str = NULL;

    char *payment_id_local_str = NULL;

    // allocate_payment_request->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(allocate_payment_requestJSON, "amount");
    if (cJSON_IsNull(amount)) {
        amount = NULL;
    }
    if (!amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(amount))
    {
    goto end; //Numeric
    }
    amount_local_var = malloc(sizeof(double));
    if(!amount_local_var)
    {
        goto end;
    }
    *amount_local_var = amount->valuedouble;

    // allocate_payment_request->invoice_id
    cJSON *invoice_id = cJSON_GetObjectItemCaseSensitive(allocate_payment_requestJSON, "invoice_id");
    if (cJSON_IsNull(invoice_id)) {
        invoice_id = NULL;
    }
    if (!invoice_id) {
        goto end;
    }

    
    if(!cJSON_IsString(invoice_id))
    {
    goto end; //String
    }

    // allocate_payment_request->payment_id
    cJSON *payment_id = cJSON_GetObjectItemCaseSensitive(allocate_payment_requestJSON, "payment_id");
    if (cJSON_IsNull(payment_id)) {
        payment_id = NULL;
    }
    if (!payment_id) {
        goto end;
    }

    
    if(!cJSON_IsString(payment_id))
    {
    goto end; //String
    }


    if (invoice_id && !cJSON_IsNull(invoice_id)) invoice_id_local_str = strdup(invoice_id->valuestring);
    if (payment_id && !cJSON_IsNull(payment_id)) payment_id_local_str = strdup(payment_id->valuestring);

    allocate_payment_request_local_var = allocate_payment_request_create_internal (
        amount_local_var,
        invoice_id_local_str,
        payment_id_local_str
        );

    if (!allocate_payment_request_local_var) {
        goto end;
    }

    return allocate_payment_request_local_var;
end:
    if (amount_local_var) {
        free(amount_local_var);
        amount_local_var = NULL;
    }
    if (invoice_id_local_str) {
        free(invoice_id_local_str);
        invoice_id_local_str = NULL;
    }
    if (payment_id_local_str) {
        free(payment_id_local_str);
        payment_id_local_str = NULL;
    }
    return NULL;

}
