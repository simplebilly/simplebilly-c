#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "voucher.h"



static voucher_t *voucher_create_internal(
    char *category_id,
    char *contact_id,
    char *contact_name,
    char *currency,
    char *description,
    any_type_t *file_attachments,
    any_type_t *line_items,
    any_type_t *metadata,
    char *notes,
    char *open_amount,
    char *paid_date,
    payment_status_t *payment_status,
    any_type_t *tax_amounts,
    char *tax_condition,
    char *total_gross_amount,
    char *total_net_amount,
    char *voucher_date,
    char *voucher_number,
    simplebilly_api_voucher_status__e voucher_status,
    simplebilly_api_voucher_type__e voucher_type
    ) {
    voucher_t *voucher_local_var = malloc(sizeof(voucher_t));
    if (!voucher_local_var) {
        return NULL;
    }
    memset(voucher_local_var, 0, sizeof(voucher_t));
    voucher_local_var->_library_owned = 1;
    voucher_local_var->category_id = category_id;
    voucher_local_var->contact_id = contact_id;
    voucher_local_var->contact_name = contact_name;
    voucher_local_var->currency = currency;
    voucher_local_var->description = description;
    voucher_local_var->file_attachments = file_attachments;
    voucher_local_var->line_items = line_items;
    voucher_local_var->metadata = metadata;
    voucher_local_var->notes = notes;
    voucher_local_var->open_amount = open_amount;
    voucher_local_var->paid_date = paid_date;
    voucher_local_var->payment_status = payment_status;
    voucher_local_var->tax_amounts = tax_amounts;
    voucher_local_var->tax_condition = tax_condition;
    voucher_local_var->total_gross_amount = total_gross_amount;
    voucher_local_var->total_net_amount = total_net_amount;
    voucher_local_var->voucher_date = voucher_date;
    voucher_local_var->voucher_number = voucher_number;
    voucher_local_var->voucher_status = voucher_status;
    voucher_local_var->voucher_type = voucher_type;
    return voucher_local_var;
}

__attribute__((deprecated)) voucher_t *voucher_create(
    char *category_id,
    char *contact_id,
    char *contact_name,
    char *currency,
    char *description,
    any_type_t *file_attachments,
    any_type_t *line_items,
    any_type_t *metadata,
    char *notes,
    char *open_amount,
    char *paid_date,
    payment_status_t *payment_status,
    any_type_t *tax_amounts,
    char *tax_condition,
    char *total_gross_amount,
    char *total_net_amount,
    char *voucher_date,
    char *voucher_number,
    simplebilly_api_voucher_status__e voucher_status,
    simplebilly_api_voucher_type__e voucher_type
    ) {
    voucher_t *result = voucher_create_internal (
        category_id,
        contact_id,
        contact_name,
        currency,
        description,
        file_attachments,
        line_items,
        metadata,
        notes,
        open_amount,
        paid_date,
        payment_status,
        tax_amounts,
        tax_condition,
        total_gross_amount,
        total_net_amount,
        voucher_date,
        voucher_number,
        voucher_status,
        voucher_type
        );
    if (!result) {
    }
    return result;
}

void voucher_free(voucher_t *voucher) {
    if(NULL == voucher){
        return ;
    }
    if(voucher->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "voucher_free");
        return ;
    }
    listEntry_t *listEntry;
    if (voucher->category_id) {
        free(voucher->category_id);
        voucher->category_id = NULL;
    }
    if (voucher->contact_id) {
        free(voucher->contact_id);
        voucher->contact_id = NULL;
    }
    if (voucher->contact_name) {
        free(voucher->contact_name);
        voucher->contact_name = NULL;
    }
    if (voucher->currency) {
        free(voucher->currency);
        voucher->currency = NULL;
    }
    if (voucher->description) {
        free(voucher->description);
        voucher->description = NULL;
    }
    if (voucher->file_attachments) {
        _free(voucher->file_attachments);
        voucher->file_attachments = NULL;
    }
    if (voucher->line_items) {
        _free(voucher->line_items);
        voucher->line_items = NULL;
    }
    if (voucher->metadata) {
        _free(voucher->metadata);
        voucher->metadata = NULL;
    }
    if (voucher->notes) {
        free(voucher->notes);
        voucher->notes = NULL;
    }
    if (voucher->open_amount) {
        free(voucher->open_amount);
        voucher->open_amount = NULL;
    }
    if (voucher->paid_date) {
        free(voucher->paid_date);
        voucher->paid_date = NULL;
    }
    if (voucher->payment_status) {
        payment_status_free(voucher->payment_status);
        voucher->payment_status = NULL;
    }
    if (voucher->tax_amounts) {
        _free(voucher->tax_amounts);
        voucher->tax_amounts = NULL;
    }
    if (voucher->tax_condition) {
        free(voucher->tax_condition);
        voucher->tax_condition = NULL;
    }
    if (voucher->total_gross_amount) {
        free(voucher->total_gross_amount);
        voucher->total_gross_amount = NULL;
    }
    if (voucher->total_net_amount) {
        free(voucher->total_net_amount);
        voucher->total_net_amount = NULL;
    }
    if (voucher->voucher_date) {
        free(voucher->voucher_date);
        voucher->voucher_date = NULL;
    }
    if (voucher->voucher_number) {
        free(voucher->voucher_number);
        voucher->voucher_number = NULL;
    }
    free(voucher);
}

cJSON *voucher_convertToJSON(voucher_t *voucher) {
    cJSON *item = cJSON_CreateObject();

    // voucher->category_id
    if(voucher->category_id) {
    if(cJSON_AddStringToObject(item, "categoryId", voucher->category_id) == NULL) {
    goto fail; //String
    }
    }


    // voucher->contact_id
    if(voucher->contact_id) {
    if(cJSON_AddStringToObject(item, "contactId", voucher->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // voucher->contact_name
    if(voucher->contact_name) {
    if(cJSON_AddStringToObject(item, "contactName", voucher->contact_name) == NULL) {
    goto fail; //String
    }
    }


    // voucher->currency
    if (!voucher->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", voucher->currency) == NULL) {
    goto fail; //String
    }


    // voucher->description
    if(voucher->description) {
    if(cJSON_AddStringToObject(item, "description", voucher->description) == NULL) {
    goto fail; //String
    }
    }


    // voucher->file_attachments
    if(voucher->file_attachments) {
    cJSON *file_attachments_local_JSON = _convertToJSON(voucher->file_attachments);
    if(file_attachments_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "fileAttachments", file_attachments_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // voucher->line_items
    if(voucher->line_items) {
    cJSON *line_items_local_JSON = _convertToJSON(voucher->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // voucher->metadata
    if(voucher->metadata) {
    cJSON *metadata_local_JSON = _convertToJSON(voucher->metadata);
    if(metadata_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // voucher->notes
    if(voucher->notes) {
    if(cJSON_AddStringToObject(item, "notes", voucher->notes) == NULL) {
    goto fail; //String
    }
    }


    // voucher->open_amount
    if(voucher->open_amount) {
    if(cJSON_AddStringToObject(item, "openAmount", voucher->open_amount) == NULL) {
    goto fail; //String
    }
    }


    // voucher->paid_date
    if(voucher->paid_date) {
    if(cJSON_AddStringToObject(item, "paidDate", voucher->paid_date) == NULL) {
    goto fail; //Date
    }
    }


    // voucher->payment_status
    if(voucher->payment_status) {
    cJSON *payment_status_local_JSON = payment_status_convertToJSON(voucher->payment_status);
    if(payment_status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "paymentStatus", payment_status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // voucher->tax_amounts
    if(voucher->tax_amounts) {
    cJSON *tax_amounts_local_JSON = _convertToJSON(voucher->tax_amounts);
    if(tax_amounts_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "taxAmounts", tax_amounts_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // voucher->tax_condition
    if(voucher->tax_condition) {
    if(cJSON_AddStringToObject(item, "taxCondition", voucher->tax_condition) == NULL) {
    goto fail; //String
    }
    }


    // voucher->total_gross_amount
    if(voucher->total_gross_amount) {
    if(cJSON_AddStringToObject(item, "totalGrossAmount", voucher->total_gross_amount) == NULL) {
    goto fail; //String
    }
    }


    // voucher->total_net_amount
    if(voucher->total_net_amount) {
    if(cJSON_AddStringToObject(item, "totalNetAmount", voucher->total_net_amount) == NULL) {
    goto fail; //String
    }
    }


    // voucher->voucher_date
    if (!voucher->voucher_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "voucherDate", voucher->voucher_date) == NULL) {
    goto fail; //Date
    }


    // voucher->voucher_number
    if(voucher->voucher_number) {
    if(cJSON_AddStringToObject(item, "voucherNumber", voucher->voucher_number) == NULL) {
    goto fail; //String
    }
    }


    // voucher->voucher_status
    if (simplebilly_api_voucher_status__NULL == voucher->voucher_status) {
        goto fail;
    }
    cJSON *voucher_status_local_JSON = voucher_status_convertToJSON(voucher->voucher_status);
    if(voucher_status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "voucherStatus", voucher_status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // voucher->voucher_type
    if (simplebilly_api_voucher_type__NULL == voucher->voucher_type) {
        goto fail;
    }
    cJSON *voucher_type_local_JSON = voucher_type_convertToJSON(voucher->voucher_type);
    if(voucher_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "voucherType", voucher_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

voucher_t *voucher_parseFromJSON(cJSON *voucherJSON){

    voucher_t *voucher_local_var = NULL;

    char *category_id_local_str = NULL;

    char *contact_id_local_str = NULL;

    char *contact_name_local_str = NULL;

    char *currency_local_str = NULL;

    char *description_local_str = NULL;

    // define the local variable for voucher->file_attachments
    _t *file_attachments_local_nonprim = NULL;

    // define the local variable for voucher->line_items
    _t *line_items_local_nonprim = NULL;

    // define the local variable for voucher->metadata
    _t *metadata_local_nonprim = NULL;

    char *notes_local_str = NULL;

    char *open_amount_local_str = NULL;

    char *paid_date_local_str = NULL;

    // define the local variable for voucher->payment_status
    payment_status_t *payment_status_local_nonprim = NULL;

    // define the local variable for voucher->tax_amounts
    _t *tax_amounts_local_nonprim = NULL;

    char *tax_condition_local_str = NULL;

    char *total_gross_amount_local_str = NULL;

    char *total_net_amount_local_str = NULL;

    char *voucher_date_local_str = NULL;

    char *voucher_number_local_str = NULL;

    // define the local variable for voucher->voucher_status
    simplebilly_api_voucher_status__e voucher_status_local_nonprim = 0;

    // define the local variable for voucher->voucher_type
    simplebilly_api_voucher_type__e voucher_type_local_nonprim = 0;

    // voucher->category_id
    cJSON *category_id = cJSON_GetObjectItemCaseSensitive(voucherJSON, "categoryId");
    if (cJSON_IsNull(category_id)) {
        category_id = NULL;
    }
    if (category_id) { 
    if(!cJSON_IsString(category_id) && !cJSON_IsNull(category_id))
    {
    goto end; //String
    }
    }

    // voucher->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(voucherJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // voucher->contact_name
    cJSON *contact_name = cJSON_GetObjectItemCaseSensitive(voucherJSON, "contactName");
    if (cJSON_IsNull(contact_name)) {
        contact_name = NULL;
    }
    if (contact_name) { 
    if(!cJSON_IsString(contact_name) && !cJSON_IsNull(contact_name))
    {
    goto end; //String
    }
    }

    // voucher->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(voucherJSON, "currency");
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

    // voucher->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(voucherJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // voucher->file_attachments
    cJSON *file_attachments = cJSON_GetObjectItemCaseSensitive(voucherJSON, "fileAttachments");
    if (cJSON_IsNull(file_attachments)) {
        file_attachments = NULL;
    }
    if (file_attachments) { 
    file_attachments_local_nonprim = _parseFromJSON(file_attachments); //custom
    }

    // voucher->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(voucherJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (line_items) { 
    line_items_local_nonprim = _parseFromJSON(line_items); //custom
    }

    // voucher->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(voucherJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = _parseFromJSON(metadata); //custom
    }

    // voucher->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(voucherJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // voucher->open_amount
    cJSON *open_amount = cJSON_GetObjectItemCaseSensitive(voucherJSON, "openAmount");
    if (cJSON_IsNull(open_amount)) {
        open_amount = NULL;
    }
    if (open_amount) { 
    if(!cJSON_IsString(open_amount) && !cJSON_IsNull(open_amount))
    {
    goto end; //String
    }
    }

    // voucher->paid_date
    cJSON *paid_date = cJSON_GetObjectItemCaseSensitive(voucherJSON, "paidDate");
    if (cJSON_IsNull(paid_date)) {
        paid_date = NULL;
    }
    if (paid_date) { 
    if(!cJSON_IsString(paid_date))
    {
    goto end; //Date
    }
    }

    // voucher->payment_status
    cJSON *payment_status = cJSON_GetObjectItemCaseSensitive(voucherJSON, "paymentStatus");
    if (cJSON_IsNull(payment_status)) {
        payment_status = NULL;
    }
    if (payment_status) { 
    payment_status_local_nonprim = payment_status_parseFromJSON(payment_status); //custom
    }

    // voucher->tax_amounts
    cJSON *tax_amounts = cJSON_GetObjectItemCaseSensitive(voucherJSON, "taxAmounts");
    if (cJSON_IsNull(tax_amounts)) {
        tax_amounts = NULL;
    }
    if (tax_amounts) { 
    tax_amounts_local_nonprim = _parseFromJSON(tax_amounts); //custom
    }

    // voucher->tax_condition
    cJSON *tax_condition = cJSON_GetObjectItemCaseSensitive(voucherJSON, "taxCondition");
    if (cJSON_IsNull(tax_condition)) {
        tax_condition = NULL;
    }
    if (tax_condition) { 
    if(!cJSON_IsString(tax_condition) && !cJSON_IsNull(tax_condition))
    {
    goto end; //String
    }
    }

    // voucher->total_gross_amount
    cJSON *total_gross_amount = cJSON_GetObjectItemCaseSensitive(voucherJSON, "totalGrossAmount");
    if (cJSON_IsNull(total_gross_amount)) {
        total_gross_amount = NULL;
    }
    if (total_gross_amount) { 
    if(!cJSON_IsString(total_gross_amount) && !cJSON_IsNull(total_gross_amount))
    {
    goto end; //String
    }
    }

    // voucher->total_net_amount
    cJSON *total_net_amount = cJSON_GetObjectItemCaseSensitive(voucherJSON, "totalNetAmount");
    if (cJSON_IsNull(total_net_amount)) {
        total_net_amount = NULL;
    }
    if (total_net_amount) { 
    if(!cJSON_IsString(total_net_amount) && !cJSON_IsNull(total_net_amount))
    {
    goto end; //String
    }
    }

    // voucher->voucher_date
    cJSON *voucher_date = cJSON_GetObjectItemCaseSensitive(voucherJSON, "voucherDate");
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

    // voucher->voucher_number
    cJSON *voucher_number = cJSON_GetObjectItemCaseSensitive(voucherJSON, "voucherNumber");
    if (cJSON_IsNull(voucher_number)) {
        voucher_number = NULL;
    }
    if (voucher_number) { 
    if(!cJSON_IsString(voucher_number) && !cJSON_IsNull(voucher_number))
    {
    goto end; //String
    }
    }

    // voucher->voucher_status
    cJSON *voucher_status = cJSON_GetObjectItemCaseSensitive(voucherJSON, "voucherStatus");
    if (cJSON_IsNull(voucher_status)) {
        voucher_status = NULL;
    }
    if (!voucher_status) {
        goto end;
    }

    
    voucher_status_local_nonprim = voucher_status_parseFromJSON(voucher_status); //custom

    // voucher->voucher_type
    cJSON *voucher_type = cJSON_GetObjectItemCaseSensitive(voucherJSON, "voucherType");
    if (cJSON_IsNull(voucher_type)) {
        voucher_type = NULL;
    }
    if (!voucher_type) {
        goto end;
    }

    
    voucher_type_local_nonprim = voucher_type_parseFromJSON(voucher_type); //custom


    if (category_id && !cJSON_IsNull(category_id)) category_id_local_str = strdup(category_id->valuestring);
    if (contact_id && !cJSON_IsNull(contact_id)) contact_id_local_str = strdup(contact_id->valuestring);
    if (contact_name && !cJSON_IsNull(contact_name)) contact_name_local_str = strdup(contact_name->valuestring);
    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (open_amount && !cJSON_IsNull(open_amount)) open_amount_local_str = strdup(open_amount->valuestring);
    if (paid_date) paid_date_local_str = strdup(paid_date->valuestring);
    if (tax_condition && !cJSON_IsNull(tax_condition)) tax_condition_local_str = strdup(tax_condition->valuestring);
    if (total_gross_amount && !cJSON_IsNull(total_gross_amount)) total_gross_amount_local_str = strdup(total_gross_amount->valuestring);
    if (total_net_amount && !cJSON_IsNull(total_net_amount)) total_net_amount_local_str = strdup(total_net_amount->valuestring);
    if (voucher_date) voucher_date_local_str = strdup(voucher_date->valuestring);
    if (voucher_number && !cJSON_IsNull(voucher_number)) voucher_number_local_str = strdup(voucher_number->valuestring);

    voucher_local_var = voucher_create_internal (
        category_id_local_str,
        contact_id_local_str,
        contact_name_local_str,
        currency_local_str,
        description_local_str,
        file_attachments ? file_attachments_local_nonprim : NULL,
        line_items ? line_items_local_nonprim : NULL,
        metadata ? metadata_local_nonprim : NULL,
        notes_local_str,
        open_amount_local_str,
        paid_date_local_str,
        payment_status ? payment_status_local_nonprim : NULL,
        tax_amounts ? tax_amounts_local_nonprim : NULL,
        tax_condition_local_str,
        total_gross_amount_local_str,
        total_net_amount_local_str,
        voucher_date_local_str,
        voucher_number_local_str,
        voucher_status_local_nonprim,
        voucher_type_local_nonprim
        );

    if (!voucher_local_var) {
        goto end;
    }

    return voucher_local_var;
end:
    if (category_id_local_str) {
        free(category_id_local_str);
        category_id_local_str = NULL;
    }
    if (contact_id_local_str) {
        free(contact_id_local_str);
        contact_id_local_str = NULL;
    }
    if (contact_name_local_str) {
        free(contact_name_local_str);
        contact_name_local_str = NULL;
    }
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (file_attachments_local_nonprim) {
        _free(file_attachments_local_nonprim);
        file_attachments_local_nonprim = NULL;
    }
    if (line_items_local_nonprim) {
        _free(line_items_local_nonprim);
        line_items_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        _free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (open_amount_local_str) {
        free(open_amount_local_str);
        open_amount_local_str = NULL;
    }
    if (paid_date_local_str) {
        free(paid_date_local_str);
        paid_date_local_str = NULL;
    }
    if (payment_status_local_nonprim) {
        payment_status_free(payment_status_local_nonprim);
        payment_status_local_nonprim = NULL;
    }
    if (tax_amounts_local_nonprim) {
        _free(tax_amounts_local_nonprim);
        tax_amounts_local_nonprim = NULL;
    }
    if (tax_condition_local_str) {
        free(tax_condition_local_str);
        tax_condition_local_str = NULL;
    }
    if (total_gross_amount_local_str) {
        free(total_gross_amount_local_str);
        total_gross_amount_local_str = NULL;
    }
    if (total_net_amount_local_str) {
        free(total_net_amount_local_str);
        total_net_amount_local_str = NULL;
    }
    if (voucher_date_local_str) {
        free(voucher_date_local_str);
        voucher_date_local_str = NULL;
    }
    if (voucher_number_local_str) {
        free(voucher_number_local_str);
        voucher_number_local_str = NULL;
    }
    if (voucher_status_local_nonprim) {
        voucher_status_local_nonprim = 0;
    }
    if (voucher_type_local_nonprim) {
        voucher_type_local_nonprim = 0;
    }
    return NULL;

}
