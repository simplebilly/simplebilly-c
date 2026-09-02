#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "proforma_invoice_create.h"



static proforma_invoice_create_t *proforma_invoice_create_create_internal(
    char *converted_at,
    char *converted_to_invoice_id,
    simplebilly_api_currency_code__e currency,
    char *customer_id,
    any_type_t *customer_snapshot,
    char *issue_date,
    any_type_t *line_items,
    char *notes,
    char *order_number,
    char *payment_due_date,
    char *quotation_id,
    proforma_invoice_status_t *status,
    char *subtotal,
    char *total_amount,
    char *total_tax
    ) {
    proforma_invoice_create_t *proforma_invoice_create_local_var = malloc(sizeof(proforma_invoice_create_t));
    if (!proforma_invoice_create_local_var) {
        return NULL;
    }
    memset(proforma_invoice_create_local_var, 0, sizeof(proforma_invoice_create_t));
    proforma_invoice_create_local_var->_library_owned = 1;
    proforma_invoice_create_local_var->converted_at = converted_at;
    proforma_invoice_create_local_var->converted_to_invoice_id = converted_to_invoice_id;
    proforma_invoice_create_local_var->currency = currency;
    proforma_invoice_create_local_var->customer_id = customer_id;
    proforma_invoice_create_local_var->customer_snapshot = customer_snapshot;
    proforma_invoice_create_local_var->issue_date = issue_date;
    proforma_invoice_create_local_var->line_items = line_items;
    proforma_invoice_create_local_var->notes = notes;
    proforma_invoice_create_local_var->order_number = order_number;
    proforma_invoice_create_local_var->payment_due_date = payment_due_date;
    proforma_invoice_create_local_var->quotation_id = quotation_id;
    proforma_invoice_create_local_var->status = status;
    proforma_invoice_create_local_var->subtotal = subtotal;
    proforma_invoice_create_local_var->total_amount = total_amount;
    proforma_invoice_create_local_var->total_tax = total_tax;
    return proforma_invoice_create_local_var;
}

__attribute__((deprecated)) proforma_invoice_create_t *proforma_invoice_create_create(
    char *converted_at,
    char *converted_to_invoice_id,
    simplebilly_api_currency_code__e currency,
    char *customer_id,
    any_type_t *customer_snapshot,
    char *issue_date,
    any_type_t *line_items,
    char *notes,
    char *order_number,
    char *payment_due_date,
    char *quotation_id,
    proforma_invoice_status_t *status,
    char *subtotal,
    char *total_amount,
    char *total_tax
    ) {
    proforma_invoice_create_t *result = proforma_invoice_create_create_internal (
        converted_at,
        converted_to_invoice_id,
        currency,
        customer_id,
        customer_snapshot,
        issue_date,
        line_items,
        notes,
        order_number,
        payment_due_date,
        quotation_id,
        status,
        subtotal,
        total_amount,
        total_tax
        );
    if (!result) {
    }
    return result;
}

void proforma_invoice_create_free(proforma_invoice_create_t *proforma_invoice_create) {
    if(NULL == proforma_invoice_create){
        return ;
    }
    if(proforma_invoice_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "proforma_invoice_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (proforma_invoice_create->converted_at) {
        free(proforma_invoice_create->converted_at);
        proforma_invoice_create->converted_at = NULL;
    }
    if (proforma_invoice_create->converted_to_invoice_id) {
        free(proforma_invoice_create->converted_to_invoice_id);
        proforma_invoice_create->converted_to_invoice_id = NULL;
    }
    if (proforma_invoice_create->customer_id) {
        free(proforma_invoice_create->customer_id);
        proforma_invoice_create->customer_id = NULL;
    }
    if (proforma_invoice_create->customer_snapshot) {
        _free(proforma_invoice_create->customer_snapshot);
        proforma_invoice_create->customer_snapshot = NULL;
    }
    if (proforma_invoice_create->issue_date) {
        free(proforma_invoice_create->issue_date);
        proforma_invoice_create->issue_date = NULL;
    }
    if (proforma_invoice_create->line_items) {
        _free(proforma_invoice_create->line_items);
        proforma_invoice_create->line_items = NULL;
    }
    if (proforma_invoice_create->notes) {
        free(proforma_invoice_create->notes);
        proforma_invoice_create->notes = NULL;
    }
    if (proforma_invoice_create->order_number) {
        free(proforma_invoice_create->order_number);
        proforma_invoice_create->order_number = NULL;
    }
    if (proforma_invoice_create->payment_due_date) {
        free(proforma_invoice_create->payment_due_date);
        proforma_invoice_create->payment_due_date = NULL;
    }
    if (proforma_invoice_create->quotation_id) {
        free(proforma_invoice_create->quotation_id);
        proforma_invoice_create->quotation_id = NULL;
    }
    if (proforma_invoice_create->status) {
        proforma_invoice_status_free(proforma_invoice_create->status);
        proforma_invoice_create->status = NULL;
    }
    if (proforma_invoice_create->subtotal) {
        free(proforma_invoice_create->subtotal);
        proforma_invoice_create->subtotal = NULL;
    }
    if (proforma_invoice_create->total_amount) {
        free(proforma_invoice_create->total_amount);
        proforma_invoice_create->total_amount = NULL;
    }
    if (proforma_invoice_create->total_tax) {
        free(proforma_invoice_create->total_tax);
        proforma_invoice_create->total_tax = NULL;
    }
    free(proforma_invoice_create);
}

cJSON *proforma_invoice_create_convertToJSON(proforma_invoice_create_t *proforma_invoice_create) {
    cJSON *item = cJSON_CreateObject();

    // proforma_invoice_create->converted_at
    if(proforma_invoice_create->converted_at) {
    if(cJSON_AddStringToObject(item, "convertedAt", proforma_invoice_create->converted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // proforma_invoice_create->converted_to_invoice_id
    if(proforma_invoice_create->converted_to_invoice_id) {
    if(cJSON_AddStringToObject(item, "convertedToInvoiceId", proforma_invoice_create->converted_to_invoice_id) == NULL) {
    goto fail; //String
    }
    }


    // proforma_invoice_create->currency
    if (simplebilly_api_currency_code__NULL == proforma_invoice_create->currency) {
        goto fail;
    }
    cJSON *currency_local_JSON = currency_code_convertToJSON(proforma_invoice_create->currency);
    if(currency_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "currency", currency_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // proforma_invoice_create->customer_id
    if(proforma_invoice_create->customer_id) {
    if(cJSON_AddStringToObject(item, "customerId", proforma_invoice_create->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // proforma_invoice_create->customer_snapshot
    if(proforma_invoice_create->customer_snapshot) {
    cJSON *customer_snapshot_local_JSON = _convertToJSON(proforma_invoice_create->customer_snapshot);
    if(customer_snapshot_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "customerSnapshot", customer_snapshot_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // proforma_invoice_create->issue_date
    if (!proforma_invoice_create->issue_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "issueDate", proforma_invoice_create->issue_date) == NULL) {
    goto fail; //Date
    }


    // proforma_invoice_create->line_items
    if (!proforma_invoice_create->line_items) {
        goto fail;
    }
    cJSON *line_items_local_JSON = _convertToJSON(proforma_invoice_create->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // proforma_invoice_create->notes
    if(proforma_invoice_create->notes) {
    if(cJSON_AddStringToObject(item, "notes", proforma_invoice_create->notes) == NULL) {
    goto fail; //String
    }
    }


    // proforma_invoice_create->order_number
    if(proforma_invoice_create->order_number) {
    if(cJSON_AddStringToObject(item, "orderNumber", proforma_invoice_create->order_number) == NULL) {
    goto fail; //String
    }
    }


    // proforma_invoice_create->payment_due_date
    if(proforma_invoice_create->payment_due_date) {
    if(cJSON_AddStringToObject(item, "paymentDueDate", proforma_invoice_create->payment_due_date) == NULL) {
    goto fail; //Date
    }
    }


    // proforma_invoice_create->quotation_id
    if(proforma_invoice_create->quotation_id) {
    if(cJSON_AddStringToObject(item, "quotationId", proforma_invoice_create->quotation_id) == NULL) {
    goto fail; //String
    }
    }


    // proforma_invoice_create->status
    if (!proforma_invoice_create->status) {
        goto fail;
    }
    cJSON *status_local_JSON = proforma_invoice_status_convertToJSON(proforma_invoice_create->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // proforma_invoice_create->subtotal
    if (!proforma_invoice_create->subtotal) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "subtotal", proforma_invoice_create->subtotal) == NULL) {
    goto fail; //String
    }


    // proforma_invoice_create->total_amount
    if (!proforma_invoice_create->total_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "totalAmount", proforma_invoice_create->total_amount) == NULL) {
    goto fail; //String
    }


    // proforma_invoice_create->total_tax
    if (!proforma_invoice_create->total_tax) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "totalTax", proforma_invoice_create->total_tax) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

proforma_invoice_create_t *proforma_invoice_create_parseFromJSON(cJSON *proforma_invoice_createJSON){

    proforma_invoice_create_t *proforma_invoice_create_local_var = NULL;

    char *converted_at_local_str = NULL;

    char *converted_to_invoice_id_local_str = NULL;

    // define the local variable for proforma_invoice_create->currency
    simplebilly_api_currency_code__e currency_local_nonprim = 0;

    char *customer_id_local_str = NULL;

    // define the local variable for proforma_invoice_create->customer_snapshot
    _t *customer_snapshot_local_nonprim = NULL;

    char *issue_date_local_str = NULL;

    // define the local variable for proforma_invoice_create->line_items
    _t *line_items_local_nonprim = NULL;

    char *notes_local_str = NULL;

    char *order_number_local_str = NULL;

    char *payment_due_date_local_str = NULL;

    char *quotation_id_local_str = NULL;

    // define the local variable for proforma_invoice_create->status
    proforma_invoice_status_t *status_local_nonprim = NULL;

    char *subtotal_local_str = NULL;

    char *total_amount_local_str = NULL;

    char *total_tax_local_str = NULL;

    // proforma_invoice_create->converted_at
    cJSON *converted_at = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "convertedAt");
    if (cJSON_IsNull(converted_at)) {
        converted_at = NULL;
    }
    if (converted_at) { 
    if(!cJSON_IsString(converted_at) && !cJSON_IsNull(converted_at))
    {
    goto end; //DateTime
    }
    }

    // proforma_invoice_create->converted_to_invoice_id
    cJSON *converted_to_invoice_id = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "convertedToInvoiceId");
    if (cJSON_IsNull(converted_to_invoice_id)) {
        converted_to_invoice_id = NULL;
    }
    if (converted_to_invoice_id) { 
    if(!cJSON_IsString(converted_to_invoice_id) && !cJSON_IsNull(converted_to_invoice_id))
    {
    goto end; //String
    }
    }

    // proforma_invoice_create->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (!currency) {
        goto end;
    }

    
    currency_local_nonprim = currency_code_parseFromJSON(currency); //custom

    // proforma_invoice_create->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "customerId");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // proforma_invoice_create->customer_snapshot
    cJSON *customer_snapshot = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "customerSnapshot");
    if (cJSON_IsNull(customer_snapshot)) {
        customer_snapshot = NULL;
    }
    if (customer_snapshot) { 
    customer_snapshot_local_nonprim = _parseFromJSON(customer_snapshot); //custom
    }

    // proforma_invoice_create->issue_date
    cJSON *issue_date = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "issueDate");
    if (cJSON_IsNull(issue_date)) {
        issue_date = NULL;
    }
    if (!issue_date) {
        goto end;
    }

    
    if(!cJSON_IsString(issue_date))
    {
    goto end; //Date
    }

    // proforma_invoice_create->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (!line_items) {
        goto end;
    }

    
    line_items_local_nonprim = _parseFromJSON(line_items); //custom

    // proforma_invoice_create->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // proforma_invoice_create->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "orderNumber");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (order_number) { 
    if(!cJSON_IsString(order_number) && !cJSON_IsNull(order_number))
    {
    goto end; //String
    }
    }

    // proforma_invoice_create->payment_due_date
    cJSON *payment_due_date = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "paymentDueDate");
    if (cJSON_IsNull(payment_due_date)) {
        payment_due_date = NULL;
    }
    if (payment_due_date) { 
    if(!cJSON_IsString(payment_due_date))
    {
    goto end; //Date
    }
    }

    // proforma_invoice_create->quotation_id
    cJSON *quotation_id = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "quotationId");
    if (cJSON_IsNull(quotation_id)) {
        quotation_id = NULL;
    }
    if (quotation_id) { 
    if(!cJSON_IsString(quotation_id) && !cJSON_IsNull(quotation_id))
    {
    goto end; //String
    }
    }

    // proforma_invoice_create->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = proforma_invoice_status_parseFromJSON(status); //custom

    // proforma_invoice_create->subtotal
    cJSON *subtotal = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "subtotal");
    if (cJSON_IsNull(subtotal)) {
        subtotal = NULL;
    }
    if (!subtotal) {
        goto end;
    }

    
    if(!cJSON_IsString(subtotal))
    {
    goto end; //String
    }

    // proforma_invoice_create->total_amount
    cJSON *total_amount = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "totalAmount");
    if (cJSON_IsNull(total_amount)) {
        total_amount = NULL;
    }
    if (!total_amount) {
        goto end;
    }

    
    if(!cJSON_IsString(total_amount))
    {
    goto end; //String
    }

    // proforma_invoice_create->total_tax
    cJSON *total_tax = cJSON_GetObjectItemCaseSensitive(proforma_invoice_createJSON, "totalTax");
    if (cJSON_IsNull(total_tax)) {
        total_tax = NULL;
    }
    if (!total_tax) {
        goto end;
    }

    
    if(!cJSON_IsString(total_tax))
    {
    goto end; //String
    }


    if (converted_at && !cJSON_IsNull(converted_at)) converted_at_local_str = strdup(converted_at->valuestring);
    if (converted_to_invoice_id && !cJSON_IsNull(converted_to_invoice_id)) converted_to_invoice_id_local_str = strdup(converted_to_invoice_id->valuestring);
    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (issue_date) issue_date_local_str = strdup(issue_date->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);
    if (payment_due_date) payment_due_date_local_str = strdup(payment_due_date->valuestring);
    if (quotation_id && !cJSON_IsNull(quotation_id)) quotation_id_local_str = strdup(quotation_id->valuestring);
    if (subtotal && !cJSON_IsNull(subtotal)) subtotal_local_str = strdup(subtotal->valuestring);
    if (total_amount && !cJSON_IsNull(total_amount)) total_amount_local_str = strdup(total_amount->valuestring);
    if (total_tax && !cJSON_IsNull(total_tax)) total_tax_local_str = strdup(total_tax->valuestring);

    proforma_invoice_create_local_var = proforma_invoice_create_create_internal (
        converted_at_local_str,
        converted_to_invoice_id_local_str,
        currency_local_nonprim,
        customer_id_local_str,
        customer_snapshot ? customer_snapshot_local_nonprim : NULL,
        issue_date_local_str,
        line_items_local_nonprim,
        notes_local_str,
        order_number_local_str,
        payment_due_date_local_str,
        quotation_id_local_str,
        status_local_nonprim,
        subtotal_local_str,
        total_amount_local_str,
        total_tax_local_str
        );

    if (!proforma_invoice_create_local_var) {
        goto end;
    }

    return proforma_invoice_create_local_var;
end:
    if (converted_at_local_str) {
        free(converted_at_local_str);
        converted_at_local_str = NULL;
    }
    if (converted_to_invoice_id_local_str) {
        free(converted_to_invoice_id_local_str);
        converted_to_invoice_id_local_str = NULL;
    }
    if (currency_local_nonprim) {
        currency_local_nonprim = 0;
    }
    if (customer_id_local_str) {
        free(customer_id_local_str);
        customer_id_local_str = NULL;
    }
    if (customer_snapshot_local_nonprim) {
        _free(customer_snapshot_local_nonprim);
        customer_snapshot_local_nonprim = NULL;
    }
    if (issue_date_local_str) {
        free(issue_date_local_str);
        issue_date_local_str = NULL;
    }
    if (line_items_local_nonprim) {
        _free(line_items_local_nonprim);
        line_items_local_nonprim = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    if (payment_due_date_local_str) {
        free(payment_due_date_local_str);
        payment_due_date_local_str = NULL;
    }
    if (quotation_id_local_str) {
        free(quotation_id_local_str);
        quotation_id_local_str = NULL;
    }
    if (status_local_nonprim) {
        proforma_invoice_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (subtotal_local_str) {
        free(subtotal_local_str);
        subtotal_local_str = NULL;
    }
    if (total_amount_local_str) {
        free(total_amount_local_str);
        total_amount_local_str = NULL;
    }
    if (total_tax_local_str) {
        free(total_tax_local_str);
        total_tax_local_str = NULL;
    }
    return NULL;

}
