#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "proposed_assignment.h"



static proposed_assignment_t *proposed_assignment_create_internal(
    char *amount_paid,
    double *confidence,
    char *customer_id,
    char *invoice_id,
    char *invoice_number,
    char *open_amount,
    char *payment_date,
    char *payment_id,
    char *reason,
    char *reference
    ) {
    proposed_assignment_t *proposed_assignment_local_var = malloc(sizeof(proposed_assignment_t));
    if (!proposed_assignment_local_var) {
        return NULL;
    }
    memset(proposed_assignment_local_var, 0, sizeof(proposed_assignment_t));
    proposed_assignment_local_var->_library_owned = 1;
    proposed_assignment_local_var->amount_paid = amount_paid;
    proposed_assignment_local_var->confidence = confidence;
    proposed_assignment_local_var->customer_id = customer_id;
    proposed_assignment_local_var->invoice_id = invoice_id;
    proposed_assignment_local_var->invoice_number = invoice_number;
    proposed_assignment_local_var->open_amount = open_amount;
    proposed_assignment_local_var->payment_date = payment_date;
    proposed_assignment_local_var->payment_id = payment_id;
    proposed_assignment_local_var->reason = reason;
    proposed_assignment_local_var->reference = reference;
    return proposed_assignment_local_var;
}

__attribute__((deprecated)) proposed_assignment_t *proposed_assignment_create(
    char *amount_paid,
    double *confidence,
    char *customer_id,
    char *invoice_id,
    char *invoice_number,
    char *open_amount,
    char *payment_date,
    char *payment_id,
    char *reason,
    char *reference
    ) {
    double *confidence_copy = NULL;
    if (confidence) {
        confidence_copy = malloc(sizeof(double));
        if (confidence_copy) *confidence_copy = *confidence;
    }
    proposed_assignment_t *result = proposed_assignment_create_internal (
        amount_paid,
        confidence_copy,
        customer_id,
        invoice_id,
        invoice_number,
        open_amount,
        payment_date,
        payment_id,
        reason,
        reference
        );
    if (!result) {
        free(confidence_copy);
    }
    return result;
}

void proposed_assignment_free(proposed_assignment_t *proposed_assignment) {
    if(NULL == proposed_assignment){
        return ;
    }
    if(proposed_assignment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "proposed_assignment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (proposed_assignment->amount_paid) {
        free(proposed_assignment->amount_paid);
        proposed_assignment->amount_paid = NULL;
    }
    if (proposed_assignment->confidence) {
        free(proposed_assignment->confidence);
        proposed_assignment->confidence = NULL;
    }
    if (proposed_assignment->customer_id) {
        free(proposed_assignment->customer_id);
        proposed_assignment->customer_id = NULL;
    }
    if (proposed_assignment->invoice_id) {
        free(proposed_assignment->invoice_id);
        proposed_assignment->invoice_id = NULL;
    }
    if (proposed_assignment->invoice_number) {
        free(proposed_assignment->invoice_number);
        proposed_assignment->invoice_number = NULL;
    }
    if (proposed_assignment->open_amount) {
        free(proposed_assignment->open_amount);
        proposed_assignment->open_amount = NULL;
    }
    if (proposed_assignment->payment_date) {
        free(proposed_assignment->payment_date);
        proposed_assignment->payment_date = NULL;
    }
    if (proposed_assignment->payment_id) {
        free(proposed_assignment->payment_id);
        proposed_assignment->payment_id = NULL;
    }
    if (proposed_assignment->reason) {
        free(proposed_assignment->reason);
        proposed_assignment->reason = NULL;
    }
    if (proposed_assignment->reference) {
        free(proposed_assignment->reference);
        proposed_assignment->reference = NULL;
    }
    free(proposed_assignment);
}

cJSON *proposed_assignment_convertToJSON(proposed_assignment_t *proposed_assignment) {
    cJSON *item = cJSON_CreateObject();

    // proposed_assignment->amount_paid
    if (!proposed_assignment->amount_paid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amount_paid", proposed_assignment->amount_paid) == NULL) {
    goto fail; //String
    }


    // proposed_assignment->confidence
    if (!proposed_assignment->confidence) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "confidence", *proposed_assignment->confidence) == NULL) {
    goto fail; //Numeric
    }


    // proposed_assignment->customer_id
    if(proposed_assignment->customer_id) {
    if(cJSON_AddStringToObject(item, "customer_id", proposed_assignment->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // proposed_assignment->invoice_id
    if (!proposed_assignment->invoice_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoice_id", proposed_assignment->invoice_id) == NULL) {
    goto fail; //String
    }


    // proposed_assignment->invoice_number
    if (!proposed_assignment->invoice_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoice_number", proposed_assignment->invoice_number) == NULL) {
    goto fail; //String
    }


    // proposed_assignment->open_amount
    if (!proposed_assignment->open_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "open_amount", proposed_assignment->open_amount) == NULL) {
    goto fail; //String
    }


    // proposed_assignment->payment_date
    if (!proposed_assignment->payment_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payment_date", proposed_assignment->payment_date) == NULL) {
    goto fail; //String
    }


    // proposed_assignment->payment_id
    if (!proposed_assignment->payment_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payment_id", proposed_assignment->payment_id) == NULL) {
    goto fail; //String
    }


    // proposed_assignment->reason
    if (!proposed_assignment->reason) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "reason", proposed_assignment->reason) == NULL) {
    goto fail; //String
    }


    // proposed_assignment->reference
    if(proposed_assignment->reference) {
    if(cJSON_AddStringToObject(item, "reference", proposed_assignment->reference) == NULL) {
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

proposed_assignment_t *proposed_assignment_parseFromJSON(cJSON *proposed_assignmentJSON){

    proposed_assignment_t *proposed_assignment_local_var = NULL;

    char *amount_paid_local_str = NULL;

    // define the local variable for proposed_assignment->confidence
    double *confidence_local_var = NULL;

    char *customer_id_local_str = NULL;

    char *invoice_id_local_str = NULL;

    char *invoice_number_local_str = NULL;

    char *open_amount_local_str = NULL;

    char *payment_date_local_str = NULL;

    char *payment_id_local_str = NULL;

    char *reason_local_str = NULL;

    char *reference_local_str = NULL;

    // proposed_assignment->amount_paid
    cJSON *amount_paid = cJSON_GetObjectItemCaseSensitive(proposed_assignmentJSON, "amount_paid");
    if (cJSON_IsNull(amount_paid)) {
        amount_paid = NULL;
    }
    if (!amount_paid) {
        goto end;
    }

    
    if(!cJSON_IsString(amount_paid))
    {
    goto end; //String
    }

    // proposed_assignment->confidence
    cJSON *confidence = cJSON_GetObjectItemCaseSensitive(proposed_assignmentJSON, "confidence");
    if (cJSON_IsNull(confidence)) {
        confidence = NULL;
    }
    if (!confidence) {
        goto end;
    }

    
    if(!cJSON_IsNumber(confidence))
    {
    goto end; //Numeric
    }
    confidence_local_var = malloc(sizeof(double));
    if(!confidence_local_var)
    {
        goto end;
    }
    *confidence_local_var = confidence->valuedouble;

    // proposed_assignment->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(proposed_assignmentJSON, "customer_id");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // proposed_assignment->invoice_id
    cJSON *invoice_id = cJSON_GetObjectItemCaseSensitive(proposed_assignmentJSON, "invoice_id");
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

    // proposed_assignment->invoice_number
    cJSON *invoice_number = cJSON_GetObjectItemCaseSensitive(proposed_assignmentJSON, "invoice_number");
    if (cJSON_IsNull(invoice_number)) {
        invoice_number = NULL;
    }
    if (!invoice_number) {
        goto end;
    }

    
    if(!cJSON_IsString(invoice_number))
    {
    goto end; //String
    }

    // proposed_assignment->open_amount
    cJSON *open_amount = cJSON_GetObjectItemCaseSensitive(proposed_assignmentJSON, "open_amount");
    if (cJSON_IsNull(open_amount)) {
        open_amount = NULL;
    }
    if (!open_amount) {
        goto end;
    }

    
    if(!cJSON_IsString(open_amount))
    {
    goto end; //String
    }

    // proposed_assignment->payment_date
    cJSON *payment_date = cJSON_GetObjectItemCaseSensitive(proposed_assignmentJSON, "payment_date");
    if (cJSON_IsNull(payment_date)) {
        payment_date = NULL;
    }
    if (!payment_date) {
        goto end;
    }

    
    if(!cJSON_IsString(payment_date))
    {
    goto end; //String
    }

    // proposed_assignment->payment_id
    cJSON *payment_id = cJSON_GetObjectItemCaseSensitive(proposed_assignmentJSON, "payment_id");
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

    // proposed_assignment->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(proposed_assignmentJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (!reason) {
        goto end;
    }

    
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }

    // proposed_assignment->reference
    cJSON *reference = cJSON_GetObjectItemCaseSensitive(proposed_assignmentJSON, "reference");
    if (cJSON_IsNull(reference)) {
        reference = NULL;
    }
    if (reference) { 
    if(!cJSON_IsString(reference) && !cJSON_IsNull(reference))
    {
    goto end; //String
    }
    }


    if (amount_paid && !cJSON_IsNull(amount_paid)) amount_paid_local_str = strdup(amount_paid->valuestring);
    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (invoice_id && !cJSON_IsNull(invoice_id)) invoice_id_local_str = strdup(invoice_id->valuestring);
    if (invoice_number && !cJSON_IsNull(invoice_number)) invoice_number_local_str = strdup(invoice_number->valuestring);
    if (open_amount && !cJSON_IsNull(open_amount)) open_amount_local_str = strdup(open_amount->valuestring);
    if (payment_date && !cJSON_IsNull(payment_date)) payment_date_local_str = strdup(payment_date->valuestring);
    if (payment_id && !cJSON_IsNull(payment_id)) payment_id_local_str = strdup(payment_id->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);
    if (reference && !cJSON_IsNull(reference)) reference_local_str = strdup(reference->valuestring);

    proposed_assignment_local_var = proposed_assignment_create_internal (
        amount_paid_local_str,
        confidence_local_var,
        customer_id_local_str,
        invoice_id_local_str,
        invoice_number_local_str,
        open_amount_local_str,
        payment_date_local_str,
        payment_id_local_str,
        reason_local_str,
        reference_local_str
        );

    if (!proposed_assignment_local_var) {
        goto end;
    }

    return proposed_assignment_local_var;
end:
    if (amount_paid_local_str) {
        free(amount_paid_local_str);
        amount_paid_local_str = NULL;
    }
    if (confidence_local_var) {
        free(confidence_local_var);
        confidence_local_var = NULL;
    }
    if (customer_id_local_str) {
        free(customer_id_local_str);
        customer_id_local_str = NULL;
    }
    if (invoice_id_local_str) {
        free(invoice_id_local_str);
        invoice_id_local_str = NULL;
    }
    if (invoice_number_local_str) {
        free(invoice_number_local_str);
        invoice_number_local_str = NULL;
    }
    if (open_amount_local_str) {
        free(open_amount_local_str);
        open_amount_local_str = NULL;
    }
    if (payment_date_local_str) {
        free(payment_date_local_str);
        payment_date_local_str = NULL;
    }
    if (payment_id_local_str) {
        free(payment_id_local_str);
        payment_id_local_str = NULL;
    }
    if (reason_local_str) {
        free(reason_local_str);
        reason_local_str = NULL;
    }
    if (reference_local_str) {
        free(reference_local_str);
        reference_local_str = NULL;
    }
    return NULL;

}
