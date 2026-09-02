#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "proforma_invoice_update.h"



static proforma_invoice_update_t *proforma_invoice_update_create_internal(
    char *converted_at,
    char *converted_to_invoice_id,
    currency_code_t *currency,
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
    proforma_invoice_update_t *proforma_invoice_update_local_var = malloc(sizeof(proforma_invoice_update_t));
    if (!proforma_invoice_update_local_var) {
        return NULL;
    }
    memset(proforma_invoice_update_local_var, 0, sizeof(proforma_invoice_update_t));
    proforma_invoice_update_local_var->_library_owned = 1;
    proforma_invoice_update_local_var->converted_at = converted_at;
    proforma_invoice_update_local_var->converted_to_invoice_id = converted_to_invoice_id;
    proforma_invoice_update_local_var->currency = currency;
    proforma_invoice_update_local_var->customer_id = customer_id;
    proforma_invoice_update_local_var->customer_snapshot = customer_snapshot;
    proforma_invoice_update_local_var->issue_date = issue_date;
    proforma_invoice_update_local_var->line_items = line_items;
    proforma_invoice_update_local_var->notes = notes;
    proforma_invoice_update_local_var->order_number = order_number;
    proforma_invoice_update_local_var->payment_due_date = payment_due_date;
    proforma_invoice_update_local_var->quotation_id = quotation_id;
    proforma_invoice_update_local_var->status = status;
    proforma_invoice_update_local_var->subtotal = subtotal;
    proforma_invoice_update_local_var->total_amount = total_amount;
    proforma_invoice_update_local_var->total_tax = total_tax;
    return proforma_invoice_update_local_var;
}

__attribute__((deprecated)) proforma_invoice_update_t *proforma_invoice_update_create(
    char *converted_at,
    char *converted_to_invoice_id,
    currency_code_t *currency,
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
    proforma_invoice_update_t *result = proforma_invoice_update_create_internal (
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

void proforma_invoice_update_free(proforma_invoice_update_t *proforma_invoice_update) {
    if(NULL == proforma_invoice_update){
        return ;
    }
    if(proforma_invoice_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "proforma_invoice_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (proforma_invoice_update->converted_at) {
        free(proforma_invoice_update->converted_at);
        proforma_invoice_update->converted_at = NULL;
    }
    if (proforma_invoice_update->converted_to_invoice_id) {
        free(proforma_invoice_update->converted_to_invoice_id);
        proforma_invoice_update->converted_to_invoice_id = NULL;
    }
    if (proforma_invoice_update->currency) {
        currency_code_free(proforma_invoice_update->currency);
        proforma_invoice_update->currency = NULL;
    }
    if (proforma_invoice_update->customer_id) {
        free(proforma_invoice_update->customer_id);
        proforma_invoice_update->customer_id = NULL;
    }
    if (proforma_invoice_update->customer_snapshot) {
        _free(proforma_invoice_update->customer_snapshot);
        proforma_invoice_update->customer_snapshot = NULL;
    }
    if (proforma_invoice_update->issue_date) {
        free(proforma_invoice_update->issue_date);
        proforma_invoice_update->issue_date = NULL;
    }
    if (proforma_invoice_update->line_items) {
        _free(proforma_invoice_update->line_items);
        proforma_invoice_update->line_items = NULL;
    }
    if (proforma_invoice_update->notes) {
        free(proforma_invoice_update->notes);
        proforma_invoice_update->notes = NULL;
    }
    if (proforma_invoice_update->order_number) {
        free(proforma_invoice_update->order_number);
        proforma_invoice_update->order_number = NULL;
    }
    if (proforma_invoice_update->payment_due_date) {
        free(proforma_invoice_update->payment_due_date);
        proforma_invoice_update->payment_due_date = NULL;
    }
    if (proforma_invoice_update->quotation_id) {
        free(proforma_invoice_update->quotation_id);
        proforma_invoice_update->quotation_id = NULL;
    }
    if (proforma_invoice_update->status) {
        proforma_invoice_status_free(proforma_invoice_update->status);
        proforma_invoice_update->status = NULL;
    }
    if (proforma_invoice_update->subtotal) {
        free(proforma_invoice_update->subtotal);
        proforma_invoice_update->subtotal = NULL;
    }
    if (proforma_invoice_update->total_amount) {
        free(proforma_invoice_update->total_amount);
        proforma_invoice_update->total_amount = NULL;
    }
    if (proforma_invoice_update->total_tax) {
        free(proforma_invoice_update->total_tax);
        proforma_invoice_update->total_tax = NULL;
    }
    free(proforma_invoice_update);
}

cJSON *proforma_invoice_update_convertToJSON(proforma_invoice_update_t *proforma_invoice_update) {
    cJSON *item = cJSON_CreateObject();

    // proforma_invoice_update->converted_at
    if(proforma_invoice_update->converted_at) {
    if(cJSON_AddStringToObject(item, "convertedAt", proforma_invoice_update->converted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // proforma_invoice_update->converted_to_invoice_id
    if(proforma_invoice_update->converted_to_invoice_id) {
    if(cJSON_AddStringToObject(item, "convertedToInvoiceId", proforma_invoice_update->converted_to_invoice_id) == NULL) {
    goto fail; //String
    }
    }


    // proforma_invoice_update->currency
    if(proforma_invoice_update->currency) {
    cJSON *currency_local_JSON = currency_code_convertToJSON(proforma_invoice_update->currency);
    if(currency_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "currency", currency_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // proforma_invoice_update->customer_id
    if(proforma_invoice_update->customer_id) {
    if(cJSON_AddStringToObject(item, "customerId", proforma_invoice_update->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // proforma_invoice_update->customer_snapshot
    if(proforma_invoice_update->customer_snapshot) {
    cJSON *customer_snapshot_local_JSON = _convertToJSON(proforma_invoice_update->customer_snapshot);
    if(customer_snapshot_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "customerSnapshot", customer_snapshot_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // proforma_invoice_update->issue_date
    if(proforma_invoice_update->issue_date) {
    if(cJSON_AddStringToObject(item, "issueDate", proforma_invoice_update->issue_date) == NULL) {
    goto fail; //Date
    }
    }


    // proforma_invoice_update->line_items
    if(proforma_invoice_update->line_items) {
    cJSON *line_items_local_JSON = _convertToJSON(proforma_invoice_update->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // proforma_invoice_update->notes
    if(proforma_invoice_update->notes) {
    if(cJSON_AddStringToObject(item, "notes", proforma_invoice_update->notes) == NULL) {
    goto fail; //String
    }
    }


    // proforma_invoice_update->order_number
    if(proforma_invoice_update->order_number) {
    if(cJSON_AddStringToObject(item, "orderNumber", proforma_invoice_update->order_number) == NULL) {
    goto fail; //String
    }
    }


    // proforma_invoice_update->payment_due_date
    if(proforma_invoice_update->payment_due_date) {
    if(cJSON_AddStringToObject(item, "paymentDueDate", proforma_invoice_update->payment_due_date) == NULL) {
    goto fail; //Date
    }
    }


    // proforma_invoice_update->quotation_id
    if(proforma_invoice_update->quotation_id) {
    if(cJSON_AddStringToObject(item, "quotationId", proforma_invoice_update->quotation_id) == NULL) {
    goto fail; //String
    }
    }


    // proforma_invoice_update->status
    if(proforma_invoice_update->status) {
    cJSON *status_local_JSON = proforma_invoice_status_convertToJSON(proforma_invoice_update->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // proforma_invoice_update->subtotal
    if(proforma_invoice_update->subtotal) {
    if(cJSON_AddStringToObject(item, "subtotal", proforma_invoice_update->subtotal) == NULL) {
    goto fail; //String
    }
    }


    // proforma_invoice_update->total_amount
    if(proforma_invoice_update->total_amount) {
    if(cJSON_AddStringToObject(item, "totalAmount", proforma_invoice_update->total_amount) == NULL) {
    goto fail; //String
    }
    }


    // proforma_invoice_update->total_tax
    if(proforma_invoice_update->total_tax) {
    if(cJSON_AddStringToObject(item, "totalTax", proforma_invoice_update->total_tax) == NULL) {
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

proforma_invoice_update_t *proforma_invoice_update_parseFromJSON(cJSON *proforma_invoice_updateJSON){

    proforma_invoice_update_t *proforma_invoice_update_local_var = NULL;

    char *converted_at_local_str = NULL;

    char *converted_to_invoice_id_local_str = NULL;

    // define the local variable for proforma_invoice_update->currency
    currency_code_t *currency_local_nonprim = NULL;

    char *customer_id_local_str = NULL;

    // define the local variable for proforma_invoice_update->customer_snapshot
    _t *customer_snapshot_local_nonprim = NULL;

    char *issue_date_local_str = NULL;

    // define the local variable for proforma_invoice_update->line_items
    _t *line_items_local_nonprim = NULL;

    char *notes_local_str = NULL;

    char *order_number_local_str = NULL;

    char *payment_due_date_local_str = NULL;

    char *quotation_id_local_str = NULL;

    // define the local variable for proforma_invoice_update->status
    proforma_invoice_status_t *status_local_nonprim = NULL;

    char *subtotal_local_str = NULL;

    char *total_amount_local_str = NULL;

    char *total_tax_local_str = NULL;

    // proforma_invoice_update->converted_at
    cJSON *converted_at = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "convertedAt");
    if (cJSON_IsNull(converted_at)) {
        converted_at = NULL;
    }
    if (converted_at) { 
    if(!cJSON_IsString(converted_at) && !cJSON_IsNull(converted_at))
    {
    goto end; //DateTime
    }
    }

    // proforma_invoice_update->converted_to_invoice_id
    cJSON *converted_to_invoice_id = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "convertedToInvoiceId");
    if (cJSON_IsNull(converted_to_invoice_id)) {
        converted_to_invoice_id = NULL;
    }
    if (converted_to_invoice_id) { 
    if(!cJSON_IsString(converted_to_invoice_id) && !cJSON_IsNull(converted_to_invoice_id))
    {
    goto end; //String
    }
    }

    // proforma_invoice_update->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    currency_local_nonprim = currency_code_parseFromJSON(currency); //custom
    }

    // proforma_invoice_update->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "customerId");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // proforma_invoice_update->customer_snapshot
    cJSON *customer_snapshot = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "customerSnapshot");
    if (cJSON_IsNull(customer_snapshot)) {
        customer_snapshot = NULL;
    }
    if (customer_snapshot) { 
    customer_snapshot_local_nonprim = _parseFromJSON(customer_snapshot); //custom
    }

    // proforma_invoice_update->issue_date
    cJSON *issue_date = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "issueDate");
    if (cJSON_IsNull(issue_date)) {
        issue_date = NULL;
    }
    if (issue_date) { 
    if(!cJSON_IsString(issue_date))
    {
    goto end; //Date
    }
    }

    // proforma_invoice_update->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (line_items) { 
    line_items_local_nonprim = _parseFromJSON(line_items); //custom
    }

    // proforma_invoice_update->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // proforma_invoice_update->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "orderNumber");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (order_number) { 
    if(!cJSON_IsString(order_number) && !cJSON_IsNull(order_number))
    {
    goto end; //String
    }
    }

    // proforma_invoice_update->payment_due_date
    cJSON *payment_due_date = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "paymentDueDate");
    if (cJSON_IsNull(payment_due_date)) {
        payment_due_date = NULL;
    }
    if (payment_due_date) { 
    if(!cJSON_IsString(payment_due_date))
    {
    goto end; //Date
    }
    }

    // proforma_invoice_update->quotation_id
    cJSON *quotation_id = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "quotationId");
    if (cJSON_IsNull(quotation_id)) {
        quotation_id = NULL;
    }
    if (quotation_id) { 
    if(!cJSON_IsString(quotation_id) && !cJSON_IsNull(quotation_id))
    {
    goto end; //String
    }
    }

    // proforma_invoice_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = proforma_invoice_status_parseFromJSON(status); //custom
    }

    // proforma_invoice_update->subtotal
    cJSON *subtotal = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "subtotal");
    if (cJSON_IsNull(subtotal)) {
        subtotal = NULL;
    }
    if (subtotal) { 
    if(!cJSON_IsString(subtotal) && !cJSON_IsNull(subtotal))
    {
    goto end; //String
    }
    }

    // proforma_invoice_update->total_amount
    cJSON *total_amount = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "totalAmount");
    if (cJSON_IsNull(total_amount)) {
        total_amount = NULL;
    }
    if (total_amount) { 
    if(!cJSON_IsString(total_amount) && !cJSON_IsNull(total_amount))
    {
    goto end; //String
    }
    }

    // proforma_invoice_update->total_tax
    cJSON *total_tax = cJSON_GetObjectItemCaseSensitive(proforma_invoice_updateJSON, "totalTax");
    if (cJSON_IsNull(total_tax)) {
        total_tax = NULL;
    }
    if (total_tax) { 
    if(!cJSON_IsString(total_tax) && !cJSON_IsNull(total_tax))
    {
    goto end; //String
    }
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

    proforma_invoice_update_local_var = proforma_invoice_update_create_internal (
        converted_at_local_str,
        converted_to_invoice_id_local_str,
        currency ? currency_local_nonprim : NULL,
        customer_id_local_str,
        customer_snapshot ? customer_snapshot_local_nonprim : NULL,
        issue_date_local_str,
        line_items ? line_items_local_nonprim : NULL,
        notes_local_str,
        order_number_local_str,
        payment_due_date_local_str,
        quotation_id_local_str,
        status ? status_local_nonprim : NULL,
        subtotal_local_str,
        total_amount_local_str,
        total_tax_local_str
        );

    if (!proforma_invoice_update_local_var) {
        goto end;
    }

    return proforma_invoice_update_local_var;
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
        currency_code_free(currency_local_nonprim);
        currency_local_nonprim = NULL;
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
