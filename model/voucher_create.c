#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "voucher_create.h"



static voucher_create_t *voucher_create_create_internal(
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
    voucher_create_t *voucher_create_local_var = malloc(sizeof(voucher_create_t));
    if (!voucher_create_local_var) {
        return NULL;
    }
    memset(voucher_create_local_var, 0, sizeof(voucher_create_t));
    voucher_create_local_var->_library_owned = 1;
    voucher_create_local_var->category_id = category_id;
    voucher_create_local_var->contact_id = contact_id;
    voucher_create_local_var->contact_name = contact_name;
    voucher_create_local_var->currency = currency;
    voucher_create_local_var->description = description;
    voucher_create_local_var->file_attachments = file_attachments;
    voucher_create_local_var->line_items = line_items;
    voucher_create_local_var->metadata = metadata;
    voucher_create_local_var->notes = notes;
    voucher_create_local_var->open_amount = open_amount;
    voucher_create_local_var->paid_date = paid_date;
    voucher_create_local_var->payment_status = payment_status;
    voucher_create_local_var->tax_amounts = tax_amounts;
    voucher_create_local_var->tax_condition = tax_condition;
    voucher_create_local_var->total_gross_amount = total_gross_amount;
    voucher_create_local_var->total_net_amount = total_net_amount;
    voucher_create_local_var->voucher_date = voucher_date;
    voucher_create_local_var->voucher_number = voucher_number;
    voucher_create_local_var->voucher_status = voucher_status;
    voucher_create_local_var->voucher_type = voucher_type;
    return voucher_create_local_var;
}

__attribute__((deprecated)) voucher_create_t *voucher_create_create(
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
    voucher_create_t *result = voucher_create_create_internal (
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

void voucher_create_free(voucher_create_t *voucher_create) {
    if(NULL == voucher_create){
        return ;
    }
    if(voucher_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "voucher_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (voucher_create->category_id) {
        free(voucher_create->category_id);
        voucher_create->category_id = NULL;
    }
    if (voucher_create->contact_id) {
        free(voucher_create->contact_id);
        voucher_create->contact_id = NULL;
    }
    if (voucher_create->contact_name) {
        free(voucher_create->contact_name);
        voucher_create->contact_name = NULL;
    }
    if (voucher_create->currency) {
        free(voucher_create->currency);
        voucher_create->currency = NULL;
    }
    if (voucher_create->description) {
        free(voucher_create->description);
        voucher_create->description = NULL;
    }
    if (voucher_create->file_attachments) {
        _free(voucher_create->file_attachments);
        voucher_create->file_attachments = NULL;
    }
    if (voucher_create->line_items) {
        _free(voucher_create->line_items);
        voucher_create->line_items = NULL;
    }
    if (voucher_create->metadata) {
        _free(voucher_create->metadata);
        voucher_create->metadata = NULL;
    }
    if (voucher_create->notes) {
        free(voucher_create->notes);
        voucher_create->notes = NULL;
    }
    if (voucher_create->open_amount) {
        free(voucher_create->open_amount);
        voucher_create->open_amount = NULL;
    }
    if (voucher_create->paid_date) {
        free(voucher_create->paid_date);
        voucher_create->paid_date = NULL;
    }
    if (voucher_create->payment_status) {
        payment_status_free(voucher_create->payment_status);
        voucher_create->payment_status = NULL;
    }
    if (voucher_create->tax_amounts) {
        _free(voucher_create->tax_amounts);
        voucher_create->tax_amounts = NULL;
    }
    if (voucher_create->tax_condition) {
        free(voucher_create->tax_condition);
        voucher_create->tax_condition = NULL;
    }
    if (voucher_create->total_gross_amount) {
        free(voucher_create->total_gross_amount);
        voucher_create->total_gross_amount = NULL;
    }
    if (voucher_create->total_net_amount) {
        free(voucher_create->total_net_amount);
        voucher_create->total_net_amount = NULL;
    }
    if (voucher_create->voucher_date) {
        free(voucher_create->voucher_date);
        voucher_create->voucher_date = NULL;
    }
    if (voucher_create->voucher_number) {
        free(voucher_create->voucher_number);
        voucher_create->voucher_number = NULL;
    }
    free(voucher_create);
}

cJSON *voucher_create_convertToJSON(voucher_create_t *voucher_create) {
    cJSON *item = cJSON_CreateObject();

    // voucher_create->category_id
    if(voucher_create->category_id) {
    if(cJSON_AddStringToObject(item, "categoryId", voucher_create->category_id) == NULL) {
    goto fail; //String
    }
    }


    // voucher_create->contact_id
    if(voucher_create->contact_id) {
    if(cJSON_AddStringToObject(item, "contactId", voucher_create->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // voucher_create->contact_name
    if(voucher_create->contact_name) {
    if(cJSON_AddStringToObject(item, "contactName", voucher_create->contact_name) == NULL) {
    goto fail; //String
    }
    }


    // voucher_create->currency
    if (!voucher_create->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", voucher_create->currency) == NULL) {
    goto fail; //String
    }


    // voucher_create->description
    if(voucher_create->description) {
    if(cJSON_AddStringToObject(item, "description", voucher_create->description) == NULL) {
    goto fail; //String
    }
    }


    // voucher_create->file_attachments
    if(voucher_create->file_attachments) {
    cJSON *file_attachments_local_JSON = _convertToJSON(voucher_create->file_attachments);
    if(file_attachments_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "fileAttachments", file_attachments_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // voucher_create->line_items
    if(voucher_create->line_items) {
    cJSON *line_items_local_JSON = _convertToJSON(voucher_create->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // voucher_create->metadata
    if(voucher_create->metadata) {
    cJSON *metadata_local_JSON = _convertToJSON(voucher_create->metadata);
    if(metadata_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // voucher_create->notes
    if(voucher_create->notes) {
    if(cJSON_AddStringToObject(item, "notes", voucher_create->notes) == NULL) {
    goto fail; //String
    }
    }


    // voucher_create->open_amount
    if(voucher_create->open_amount) {
    if(cJSON_AddStringToObject(item, "openAmount", voucher_create->open_amount) == NULL) {
    goto fail; //String
    }
    }


    // voucher_create->paid_date
    if(voucher_create->paid_date) {
    if(cJSON_AddStringToObject(item, "paidDate", voucher_create->paid_date) == NULL) {
    goto fail; //Date
    }
    }


    // voucher_create->payment_status
    if(voucher_create->payment_status) {
    cJSON *payment_status_local_JSON = payment_status_convertToJSON(voucher_create->payment_status);
    if(payment_status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "paymentStatus", payment_status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // voucher_create->tax_amounts
    if(voucher_create->tax_amounts) {
    cJSON *tax_amounts_local_JSON = _convertToJSON(voucher_create->tax_amounts);
    if(tax_amounts_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "taxAmounts", tax_amounts_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // voucher_create->tax_condition
    if(voucher_create->tax_condition) {
    if(cJSON_AddStringToObject(item, "taxCondition", voucher_create->tax_condition) == NULL) {
    goto fail; //String
    }
    }


    // voucher_create->total_gross_amount
    if(voucher_create->total_gross_amount) {
    if(cJSON_AddStringToObject(item, "totalGrossAmount", voucher_create->total_gross_amount) == NULL) {
    goto fail; //String
    }
    }


    // voucher_create->total_net_amount
    if(voucher_create->total_net_amount) {
    if(cJSON_AddStringToObject(item, "totalNetAmount", voucher_create->total_net_amount) == NULL) {
    goto fail; //String
    }
    }


    // voucher_create->voucher_date
    if (!voucher_create->voucher_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "voucherDate", voucher_create->voucher_date) == NULL) {
    goto fail; //Date
    }


    // voucher_create->voucher_number
    if(voucher_create->voucher_number) {
    if(cJSON_AddStringToObject(item, "voucherNumber", voucher_create->voucher_number) == NULL) {
    goto fail; //String
    }
    }


    // voucher_create->voucher_status
    if (simplebilly_api_voucher_status__NULL == voucher_create->voucher_status) {
        goto fail;
    }
    cJSON *voucher_status_local_JSON = voucher_status_convertToJSON(voucher_create->voucher_status);
    if(voucher_status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "voucherStatus", voucher_status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // voucher_create->voucher_type
    if (simplebilly_api_voucher_type__NULL == voucher_create->voucher_type) {
        goto fail;
    }
    cJSON *voucher_type_local_JSON = voucher_type_convertToJSON(voucher_create->voucher_type);
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

voucher_create_t *voucher_create_parseFromJSON(cJSON *voucher_createJSON){

    voucher_create_t *voucher_create_local_var = NULL;

    char *category_id_local_str = NULL;

    char *contact_id_local_str = NULL;

    char *contact_name_local_str = NULL;

    char *currency_local_str = NULL;

    char *description_local_str = NULL;

    // define the local variable for voucher_create->file_attachments
    _t *file_attachments_local_nonprim = NULL;

    // define the local variable for voucher_create->line_items
    _t *line_items_local_nonprim = NULL;

    // define the local variable for voucher_create->metadata
    _t *metadata_local_nonprim = NULL;

    char *notes_local_str = NULL;

    char *open_amount_local_str = NULL;

    char *paid_date_local_str = NULL;

    // define the local variable for voucher_create->payment_status
    payment_status_t *payment_status_local_nonprim = NULL;

    // define the local variable for voucher_create->tax_amounts
    _t *tax_amounts_local_nonprim = NULL;

    char *tax_condition_local_str = NULL;

    char *total_gross_amount_local_str = NULL;

    char *total_net_amount_local_str = NULL;

    char *voucher_date_local_str = NULL;

    char *voucher_number_local_str = NULL;

    // define the local variable for voucher_create->voucher_status
    simplebilly_api_voucher_status__e voucher_status_local_nonprim = 0;

    // define the local variable for voucher_create->voucher_type
    simplebilly_api_voucher_type__e voucher_type_local_nonprim = 0;

    // voucher_create->category_id
    cJSON *category_id = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "categoryId");
    if (cJSON_IsNull(category_id)) {
        category_id = NULL;
    }
    if (category_id) { 
    if(!cJSON_IsString(category_id) && !cJSON_IsNull(category_id))
    {
    goto end; //String
    }
    }

    // voucher_create->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // voucher_create->contact_name
    cJSON *contact_name = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "contactName");
    if (cJSON_IsNull(contact_name)) {
        contact_name = NULL;
    }
    if (contact_name) { 
    if(!cJSON_IsString(contact_name) && !cJSON_IsNull(contact_name))
    {
    goto end; //String
    }
    }

    // voucher_create->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "currency");
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

    // voucher_create->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // voucher_create->file_attachments
    cJSON *file_attachments = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "fileAttachments");
    if (cJSON_IsNull(file_attachments)) {
        file_attachments = NULL;
    }
    if (file_attachments) { 
    file_attachments_local_nonprim = _parseFromJSON(file_attachments); //custom
    }

    // voucher_create->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (line_items) { 
    line_items_local_nonprim = _parseFromJSON(line_items); //custom
    }

    // voucher_create->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = _parseFromJSON(metadata); //custom
    }

    // voucher_create->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // voucher_create->open_amount
    cJSON *open_amount = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "openAmount");
    if (cJSON_IsNull(open_amount)) {
        open_amount = NULL;
    }
    if (open_amount) { 
    if(!cJSON_IsString(open_amount) && !cJSON_IsNull(open_amount))
    {
    goto end; //String
    }
    }

    // voucher_create->paid_date
    cJSON *paid_date = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "paidDate");
    if (cJSON_IsNull(paid_date)) {
        paid_date = NULL;
    }
    if (paid_date) { 
    if(!cJSON_IsString(paid_date))
    {
    goto end; //Date
    }
    }

    // voucher_create->payment_status
    cJSON *payment_status = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "paymentStatus");
    if (cJSON_IsNull(payment_status)) {
        payment_status = NULL;
    }
    if (payment_status) { 
    payment_status_local_nonprim = payment_status_parseFromJSON(payment_status); //custom
    }

    // voucher_create->tax_amounts
    cJSON *tax_amounts = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "taxAmounts");
    if (cJSON_IsNull(tax_amounts)) {
        tax_amounts = NULL;
    }
    if (tax_amounts) { 
    tax_amounts_local_nonprim = _parseFromJSON(tax_amounts); //custom
    }

    // voucher_create->tax_condition
    cJSON *tax_condition = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "taxCondition");
    if (cJSON_IsNull(tax_condition)) {
        tax_condition = NULL;
    }
    if (tax_condition) { 
    if(!cJSON_IsString(tax_condition) && !cJSON_IsNull(tax_condition))
    {
    goto end; //String
    }
    }

    // voucher_create->total_gross_amount
    cJSON *total_gross_amount = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "totalGrossAmount");
    if (cJSON_IsNull(total_gross_amount)) {
        total_gross_amount = NULL;
    }
    if (total_gross_amount) { 
    if(!cJSON_IsString(total_gross_amount) && !cJSON_IsNull(total_gross_amount))
    {
    goto end; //String
    }
    }

    // voucher_create->total_net_amount
    cJSON *total_net_amount = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "totalNetAmount");
    if (cJSON_IsNull(total_net_amount)) {
        total_net_amount = NULL;
    }
    if (total_net_amount) { 
    if(!cJSON_IsString(total_net_amount) && !cJSON_IsNull(total_net_amount))
    {
    goto end; //String
    }
    }

    // voucher_create->voucher_date
    cJSON *voucher_date = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "voucherDate");
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

    // voucher_create->voucher_number
    cJSON *voucher_number = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "voucherNumber");
    if (cJSON_IsNull(voucher_number)) {
        voucher_number = NULL;
    }
    if (voucher_number) { 
    if(!cJSON_IsString(voucher_number) && !cJSON_IsNull(voucher_number))
    {
    goto end; //String
    }
    }

    // voucher_create->voucher_status
    cJSON *voucher_status = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "voucherStatus");
    if (cJSON_IsNull(voucher_status)) {
        voucher_status = NULL;
    }
    if (!voucher_status) {
        goto end;
    }

    
    voucher_status_local_nonprim = voucher_status_parseFromJSON(voucher_status); //custom

    // voucher_create->voucher_type
    cJSON *voucher_type = cJSON_GetObjectItemCaseSensitive(voucher_createJSON, "voucherType");
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

    voucher_create_local_var = voucher_create_create_internal (
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

    if (!voucher_create_local_var) {
        goto end;
    }

    return voucher_create_local_var;
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
