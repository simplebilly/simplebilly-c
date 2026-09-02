#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "down_payment_invoice.h"



static down_payment_invoice_t *down_payment_invoice_create_internal(
    char *contact_id,
    char *contact_name,
    char *created_at,
    char *currency,
    char *id,
    char *notes,
    char *paid_amount,
    char *total_amount,
    char *voucher_date,
    char *voucher_number,
    char *voucher_status
    ) {
    down_payment_invoice_t *down_payment_invoice_local_var = malloc(sizeof(down_payment_invoice_t));
    if (!down_payment_invoice_local_var) {
        return NULL;
    }
    memset(down_payment_invoice_local_var, 0, sizeof(down_payment_invoice_t));
    down_payment_invoice_local_var->_library_owned = 1;
    down_payment_invoice_local_var->contact_id = contact_id;
    down_payment_invoice_local_var->contact_name = contact_name;
    down_payment_invoice_local_var->created_at = created_at;
    down_payment_invoice_local_var->currency = currency;
    down_payment_invoice_local_var->id = id;
    down_payment_invoice_local_var->notes = notes;
    down_payment_invoice_local_var->paid_amount = paid_amount;
    down_payment_invoice_local_var->total_amount = total_amount;
    down_payment_invoice_local_var->voucher_date = voucher_date;
    down_payment_invoice_local_var->voucher_number = voucher_number;
    down_payment_invoice_local_var->voucher_status = voucher_status;
    return down_payment_invoice_local_var;
}

__attribute__((deprecated)) down_payment_invoice_t *down_payment_invoice_create(
    char *contact_id,
    char *contact_name,
    char *created_at,
    char *currency,
    char *id,
    char *notes,
    char *paid_amount,
    char *total_amount,
    char *voucher_date,
    char *voucher_number,
    char *voucher_status
    ) {
    down_payment_invoice_t *result = down_payment_invoice_create_internal (
        contact_id,
        contact_name,
        created_at,
        currency,
        id,
        notes,
        paid_amount,
        total_amount,
        voucher_date,
        voucher_number,
        voucher_status
        );
    if (!result) {
    }
    return result;
}

void down_payment_invoice_free(down_payment_invoice_t *down_payment_invoice) {
    if(NULL == down_payment_invoice){
        return ;
    }
    if(down_payment_invoice->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "down_payment_invoice_free");
        return ;
    }
    listEntry_t *listEntry;
    if (down_payment_invoice->contact_id) {
        free(down_payment_invoice->contact_id);
        down_payment_invoice->contact_id = NULL;
    }
    if (down_payment_invoice->contact_name) {
        free(down_payment_invoice->contact_name);
        down_payment_invoice->contact_name = NULL;
    }
    if (down_payment_invoice->created_at) {
        free(down_payment_invoice->created_at);
        down_payment_invoice->created_at = NULL;
    }
    if (down_payment_invoice->currency) {
        free(down_payment_invoice->currency);
        down_payment_invoice->currency = NULL;
    }
    if (down_payment_invoice->id) {
        free(down_payment_invoice->id);
        down_payment_invoice->id = NULL;
    }
    if (down_payment_invoice->notes) {
        free(down_payment_invoice->notes);
        down_payment_invoice->notes = NULL;
    }
    if (down_payment_invoice->paid_amount) {
        free(down_payment_invoice->paid_amount);
        down_payment_invoice->paid_amount = NULL;
    }
    if (down_payment_invoice->total_amount) {
        free(down_payment_invoice->total_amount);
        down_payment_invoice->total_amount = NULL;
    }
    if (down_payment_invoice->voucher_date) {
        free(down_payment_invoice->voucher_date);
        down_payment_invoice->voucher_date = NULL;
    }
    if (down_payment_invoice->voucher_number) {
        free(down_payment_invoice->voucher_number);
        down_payment_invoice->voucher_number = NULL;
    }
    if (down_payment_invoice->voucher_status) {
        free(down_payment_invoice->voucher_status);
        down_payment_invoice->voucher_status = NULL;
    }
    free(down_payment_invoice);
}

cJSON *down_payment_invoice_convertToJSON(down_payment_invoice_t *down_payment_invoice) {
    cJSON *item = cJSON_CreateObject();

    // down_payment_invoice->contact_id
    if(down_payment_invoice->contact_id) {
    if(cJSON_AddStringToObject(item, "contact_id", down_payment_invoice->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // down_payment_invoice->contact_name
    if(down_payment_invoice->contact_name) {
    if(cJSON_AddStringToObject(item, "contact_name", down_payment_invoice->contact_name) == NULL) {
    goto fail; //String
    }
    }


    // down_payment_invoice->created_at
    if (!down_payment_invoice->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", down_payment_invoice->created_at) == NULL) {
    goto fail; //String
    }


    // down_payment_invoice->currency
    if (!down_payment_invoice->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", down_payment_invoice->currency) == NULL) {
    goto fail; //String
    }


    // down_payment_invoice->id
    if (!down_payment_invoice->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", down_payment_invoice->id) == NULL) {
    goto fail; //String
    }


    // down_payment_invoice->notes
    if(down_payment_invoice->notes) {
    if(cJSON_AddStringToObject(item, "notes", down_payment_invoice->notes) == NULL) {
    goto fail; //String
    }
    }


    // down_payment_invoice->paid_amount
    if (!down_payment_invoice->paid_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "paid_amount", down_payment_invoice->paid_amount) == NULL) {
    goto fail; //String
    }


    // down_payment_invoice->total_amount
    if (!down_payment_invoice->total_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_amount", down_payment_invoice->total_amount) == NULL) {
    goto fail; //String
    }


    // down_payment_invoice->voucher_date
    if (!down_payment_invoice->voucher_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "voucher_date", down_payment_invoice->voucher_date) == NULL) {
    goto fail; //Date
    }


    // down_payment_invoice->voucher_number
    if(down_payment_invoice->voucher_number) {
    if(cJSON_AddStringToObject(item, "voucher_number", down_payment_invoice->voucher_number) == NULL) {
    goto fail; //String
    }
    }


    // down_payment_invoice->voucher_status
    if (!down_payment_invoice->voucher_status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "voucher_status", down_payment_invoice->voucher_status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

down_payment_invoice_t *down_payment_invoice_parseFromJSON(cJSON *down_payment_invoiceJSON){

    down_payment_invoice_t *down_payment_invoice_local_var = NULL;

    char *contact_id_local_str = NULL;

    char *contact_name_local_str = NULL;

    char *created_at_local_str = NULL;

    char *currency_local_str = NULL;

    char *id_local_str = NULL;

    char *notes_local_str = NULL;

    char *paid_amount_local_str = NULL;

    char *total_amount_local_str = NULL;

    char *voucher_date_local_str = NULL;

    char *voucher_number_local_str = NULL;

    char *voucher_status_local_str = NULL;

    // down_payment_invoice->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(down_payment_invoiceJSON, "contact_id");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // down_payment_invoice->contact_name
    cJSON *contact_name = cJSON_GetObjectItemCaseSensitive(down_payment_invoiceJSON, "contact_name");
    if (cJSON_IsNull(contact_name)) {
        contact_name = NULL;
    }
    if (contact_name) { 
    if(!cJSON_IsString(contact_name) && !cJSON_IsNull(contact_name))
    {
    goto end; //String
    }
    }

    // down_payment_invoice->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(down_payment_invoiceJSON, "created_at");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at))
    {
    goto end; //String
    }

    // down_payment_invoice->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(down_payment_invoiceJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (!currency) {
        goto end;
    }

    
    if(!cJSON_IsString(currency))
    {
    goto end; //String
    }

    // down_payment_invoice->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(down_payment_invoiceJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // down_payment_invoice->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(down_payment_invoiceJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // down_payment_invoice->paid_amount
    cJSON *paid_amount = cJSON_GetObjectItemCaseSensitive(down_payment_invoiceJSON, "paid_amount");
    if (cJSON_IsNull(paid_amount)) {
        paid_amount = NULL;
    }
    if (!paid_amount) {
        goto end;
    }

    
    if(!cJSON_IsString(paid_amount))
    {
    goto end; //String
    }

    // down_payment_invoice->total_amount
    cJSON *total_amount = cJSON_GetObjectItemCaseSensitive(down_payment_invoiceJSON, "total_amount");
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

    // down_payment_invoice->voucher_date
    cJSON *voucher_date = cJSON_GetObjectItemCaseSensitive(down_payment_invoiceJSON, "voucher_date");
    if (cJSON_IsNull(voucher_date)) {
        voucher_date = NULL;
    }
    if (!voucher_date) {
        goto end;
    }

    
    if(!cJSON_IsString(voucher_date))
    {
    goto end; //Date
    }

    // down_payment_invoice->voucher_number
    cJSON *voucher_number = cJSON_GetObjectItemCaseSensitive(down_payment_invoiceJSON, "voucher_number");
    if (cJSON_IsNull(voucher_number)) {
        voucher_number = NULL;
    }
    if (voucher_number) { 
    if(!cJSON_IsString(voucher_number) && !cJSON_IsNull(voucher_number))
    {
    goto end; //String
    }
    }

    // down_payment_invoice->voucher_status
    cJSON *voucher_status = cJSON_GetObjectItemCaseSensitive(down_payment_invoiceJSON, "voucher_status");
    if (cJSON_IsNull(voucher_status)) {
        voucher_status = NULL;
    }
    if (!voucher_status) {
        goto end;
    }

    
    if(!cJSON_IsString(voucher_status))
    {
    goto end; //String
    }


    if (contact_id && !cJSON_IsNull(contact_id)) contact_id_local_str = strdup(contact_id->valuestring);
    if (contact_name && !cJSON_IsNull(contact_name)) contact_name_local_str = strdup(contact_name->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (paid_amount && !cJSON_IsNull(paid_amount)) paid_amount_local_str = strdup(paid_amount->valuestring);
    if (total_amount && !cJSON_IsNull(total_amount)) total_amount_local_str = strdup(total_amount->valuestring);
    if (voucher_date) voucher_date_local_str = strdup(voucher_date->valuestring);
    if (voucher_number && !cJSON_IsNull(voucher_number)) voucher_number_local_str = strdup(voucher_number->valuestring);
    if (voucher_status && !cJSON_IsNull(voucher_status)) voucher_status_local_str = strdup(voucher_status->valuestring);

    down_payment_invoice_local_var = down_payment_invoice_create_internal (
        contact_id_local_str,
        contact_name_local_str,
        created_at_local_str,
        currency_local_str,
        id_local_str,
        notes_local_str,
        paid_amount_local_str,
        total_amount_local_str,
        voucher_date_local_str,
        voucher_number_local_str,
        voucher_status_local_str
        );

    if (!down_payment_invoice_local_var) {
        goto end;
    }

    return down_payment_invoice_local_var;
end:
    if (contact_id_local_str) {
        free(contact_id_local_str);
        contact_id_local_str = NULL;
    }
    if (contact_name_local_str) {
        free(contact_name_local_str);
        contact_name_local_str = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (paid_amount_local_str) {
        free(paid_amount_local_str);
        paid_amount_local_str = NULL;
    }
    if (total_amount_local_str) {
        free(total_amount_local_str);
        total_amount_local_str = NULL;
    }
    if (voucher_date_local_str) {
        free(voucher_date_local_str);
        voucher_date_local_str = NULL;
    }
    if (voucher_number_local_str) {
        free(voucher_number_local_str);
        voucher_number_local_str = NULL;
    }
    if (voucher_status_local_str) {
        free(voucher_status_local_str);
        voucher_status_local_str = NULL;
    }
    return NULL;

}
