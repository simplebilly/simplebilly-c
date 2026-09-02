#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "quotation.h"



static quotation_t *quotation_create_internal(
    any_type_t *address,
    char *contact_id,
    char *contact_name,
    char *currency,
    char *expiration_date,
    any_type_t *files,
    char *introduction,
    any_type_t *line_items,
    char *preceding_sales_voucher_id,
    preceding_sales_voucher_type_t *preceding_sales_voucher_type,
    char *quotation_number,
    char *remark,
    char *subtotal,
    char *tax_condition,
    char *title,
    char *total_amount,
    char *total_tax,
    char *voucher_date,
    simplebilly_api_voucher_status__e voucher_status
    ) {
    quotation_t *quotation_local_var = malloc(sizeof(quotation_t));
    if (!quotation_local_var) {
        return NULL;
    }
    memset(quotation_local_var, 0, sizeof(quotation_t));
    quotation_local_var->_library_owned = 1;
    quotation_local_var->address = address;
    quotation_local_var->contact_id = contact_id;
    quotation_local_var->contact_name = contact_name;
    quotation_local_var->currency = currency;
    quotation_local_var->expiration_date = expiration_date;
    quotation_local_var->files = files;
    quotation_local_var->introduction = introduction;
    quotation_local_var->line_items = line_items;
    quotation_local_var->preceding_sales_voucher_id = preceding_sales_voucher_id;
    quotation_local_var->preceding_sales_voucher_type = preceding_sales_voucher_type;
    quotation_local_var->quotation_number = quotation_number;
    quotation_local_var->remark = remark;
    quotation_local_var->subtotal = subtotal;
    quotation_local_var->tax_condition = tax_condition;
    quotation_local_var->title = title;
    quotation_local_var->total_amount = total_amount;
    quotation_local_var->total_tax = total_tax;
    quotation_local_var->voucher_date = voucher_date;
    quotation_local_var->voucher_status = voucher_status;
    return quotation_local_var;
}

__attribute__((deprecated)) quotation_t *quotation_create(
    any_type_t *address,
    char *contact_id,
    char *contact_name,
    char *currency,
    char *expiration_date,
    any_type_t *files,
    char *introduction,
    any_type_t *line_items,
    char *preceding_sales_voucher_id,
    preceding_sales_voucher_type_t *preceding_sales_voucher_type,
    char *quotation_number,
    char *remark,
    char *subtotal,
    char *tax_condition,
    char *title,
    char *total_amount,
    char *total_tax,
    char *voucher_date,
    simplebilly_api_voucher_status__e voucher_status
    ) {
    quotation_t *result = quotation_create_internal (
        address,
        contact_id,
        contact_name,
        currency,
        expiration_date,
        files,
        introduction,
        line_items,
        preceding_sales_voucher_id,
        preceding_sales_voucher_type,
        quotation_number,
        remark,
        subtotal,
        tax_condition,
        title,
        total_amount,
        total_tax,
        voucher_date,
        voucher_status
        );
    if (!result) {
    }
    return result;
}

void quotation_free(quotation_t *quotation) {
    if(NULL == quotation){
        return ;
    }
    if(quotation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "quotation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (quotation->address) {
        _free(quotation->address);
        quotation->address = NULL;
    }
    if (quotation->contact_id) {
        free(quotation->contact_id);
        quotation->contact_id = NULL;
    }
    if (quotation->contact_name) {
        free(quotation->contact_name);
        quotation->contact_name = NULL;
    }
    if (quotation->currency) {
        free(quotation->currency);
        quotation->currency = NULL;
    }
    if (quotation->expiration_date) {
        free(quotation->expiration_date);
        quotation->expiration_date = NULL;
    }
    if (quotation->files) {
        _free(quotation->files);
        quotation->files = NULL;
    }
    if (quotation->introduction) {
        free(quotation->introduction);
        quotation->introduction = NULL;
    }
    if (quotation->line_items) {
        _free(quotation->line_items);
        quotation->line_items = NULL;
    }
    if (quotation->preceding_sales_voucher_id) {
        free(quotation->preceding_sales_voucher_id);
        quotation->preceding_sales_voucher_id = NULL;
    }
    if (quotation->preceding_sales_voucher_type) {
        preceding_sales_voucher_type_free(quotation->preceding_sales_voucher_type);
        quotation->preceding_sales_voucher_type = NULL;
    }
    if (quotation->quotation_number) {
        free(quotation->quotation_number);
        quotation->quotation_number = NULL;
    }
    if (quotation->remark) {
        free(quotation->remark);
        quotation->remark = NULL;
    }
    if (quotation->subtotal) {
        free(quotation->subtotal);
        quotation->subtotal = NULL;
    }
    if (quotation->tax_condition) {
        free(quotation->tax_condition);
        quotation->tax_condition = NULL;
    }
    if (quotation->title) {
        free(quotation->title);
        quotation->title = NULL;
    }
    if (quotation->total_amount) {
        free(quotation->total_amount);
        quotation->total_amount = NULL;
    }
    if (quotation->total_tax) {
        free(quotation->total_tax);
        quotation->total_tax = NULL;
    }
    if (quotation->voucher_date) {
        free(quotation->voucher_date);
        quotation->voucher_date = NULL;
    }
    free(quotation);
}

cJSON *quotation_convertToJSON(quotation_t *quotation) {
    cJSON *item = cJSON_CreateObject();

    // quotation->address
    if(quotation->address) {
    cJSON *address_local_JSON = _convertToJSON(quotation->address);
    if(address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "address", address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // quotation->contact_id
    if(quotation->contact_id) {
    if(cJSON_AddStringToObject(item, "contactId", quotation->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // quotation->contact_name
    if(quotation->contact_name) {
    if(cJSON_AddStringToObject(item, "contactName", quotation->contact_name) == NULL) {
    goto fail; //String
    }
    }


    // quotation->currency
    if (!quotation->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", quotation->currency) == NULL) {
    goto fail; //String
    }


    // quotation->expiration_date
    if(quotation->expiration_date) {
    if(cJSON_AddStringToObject(item, "expirationDate", quotation->expiration_date) == NULL) {
    goto fail; //Date
    }
    }


    // quotation->files
    if(quotation->files) {
    cJSON *files_local_JSON = _convertToJSON(quotation->files);
    if(files_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "files", files_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // quotation->introduction
    if(quotation->introduction) {
    if(cJSON_AddStringToObject(item, "introduction", quotation->introduction) == NULL) {
    goto fail; //String
    }
    }


    // quotation->line_items
    if(quotation->line_items) {
    cJSON *line_items_local_JSON = _convertToJSON(quotation->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // quotation->preceding_sales_voucher_id
    if(quotation->preceding_sales_voucher_id) {
    if(cJSON_AddStringToObject(item, "precedingSalesVoucherId", quotation->preceding_sales_voucher_id) == NULL) {
    goto fail; //String
    }
    }


    // quotation->preceding_sales_voucher_type
    if(quotation->preceding_sales_voucher_type) {
    cJSON *preceding_sales_voucher_type_local_JSON = preceding_sales_voucher_type_convertToJSON(quotation->preceding_sales_voucher_type);
    if(preceding_sales_voucher_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "precedingSalesVoucherType", preceding_sales_voucher_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // quotation->quotation_number
    if(quotation->quotation_number) {
    if(cJSON_AddStringToObject(item, "quotationNumber", quotation->quotation_number) == NULL) {
    goto fail; //String
    }
    }


    // quotation->remark
    if(quotation->remark) {
    if(cJSON_AddStringToObject(item, "remark", quotation->remark) == NULL) {
    goto fail; //String
    }
    }


    // quotation->subtotal
    if(quotation->subtotal) {
    if(cJSON_AddStringToObject(item, "subtotal", quotation->subtotal) == NULL) {
    goto fail; //String
    }
    }


    // quotation->tax_condition
    if(quotation->tax_condition) {
    if(cJSON_AddStringToObject(item, "taxCondition", quotation->tax_condition) == NULL) {
    goto fail; //String
    }
    }


    // quotation->title
    if(quotation->title) {
    if(cJSON_AddStringToObject(item, "title", quotation->title) == NULL) {
    goto fail; //String
    }
    }


    // quotation->total_amount
    if(quotation->total_amount) {
    if(cJSON_AddStringToObject(item, "totalAmount", quotation->total_amount) == NULL) {
    goto fail; //String
    }
    }


    // quotation->total_tax
    if(quotation->total_tax) {
    if(cJSON_AddStringToObject(item, "totalTax", quotation->total_tax) == NULL) {
    goto fail; //String
    }
    }


    // quotation->voucher_date
    if (!quotation->voucher_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "voucherDate", quotation->voucher_date) == NULL) {
    goto fail; //Date
    }


    // quotation->voucher_status
    if (simplebilly_api_voucher_status__NULL == quotation->voucher_status) {
        goto fail;
    }
    cJSON *voucher_status_local_JSON = voucher_status_convertToJSON(quotation->voucher_status);
    if(voucher_status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "voucherStatus", voucher_status_local_JSON);
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

quotation_t *quotation_parseFromJSON(cJSON *quotationJSON){

    quotation_t *quotation_local_var = NULL;

    // define the local variable for quotation->address
    _t *address_local_nonprim = NULL;

    char *contact_id_local_str = NULL;

    char *contact_name_local_str = NULL;

    char *currency_local_str = NULL;

    char *expiration_date_local_str = NULL;

    // define the local variable for quotation->files
    _t *files_local_nonprim = NULL;

    char *introduction_local_str = NULL;

    // define the local variable for quotation->line_items
    _t *line_items_local_nonprim = NULL;

    char *preceding_sales_voucher_id_local_str = NULL;

    // define the local variable for quotation->preceding_sales_voucher_type
    preceding_sales_voucher_type_t *preceding_sales_voucher_type_local_nonprim = NULL;

    char *quotation_number_local_str = NULL;

    char *remark_local_str = NULL;

    char *subtotal_local_str = NULL;

    char *tax_condition_local_str = NULL;

    char *title_local_str = NULL;

    char *total_amount_local_str = NULL;

    char *total_tax_local_str = NULL;

    char *voucher_date_local_str = NULL;

    // define the local variable for quotation->voucher_status
    simplebilly_api_voucher_status__e voucher_status_local_nonprim = 0;

    // quotation->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(quotationJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    address_local_nonprim = _parseFromJSON(address); //custom
    }

    // quotation->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(quotationJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // quotation->contact_name
    cJSON *contact_name = cJSON_GetObjectItemCaseSensitive(quotationJSON, "contactName");
    if (cJSON_IsNull(contact_name)) {
        contact_name = NULL;
    }
    if (contact_name) { 
    if(!cJSON_IsString(contact_name) && !cJSON_IsNull(contact_name))
    {
    goto end; //String
    }
    }

    // quotation->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(quotationJSON, "currency");
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

    // quotation->expiration_date
    cJSON *expiration_date = cJSON_GetObjectItemCaseSensitive(quotationJSON, "expirationDate");
    if (cJSON_IsNull(expiration_date)) {
        expiration_date = NULL;
    }
    if (expiration_date) { 
    if(!cJSON_IsString(expiration_date))
    {
    goto end; //Date
    }
    }

    // quotation->files
    cJSON *files = cJSON_GetObjectItemCaseSensitive(quotationJSON, "files");
    if (cJSON_IsNull(files)) {
        files = NULL;
    }
    if (files) { 
    files_local_nonprim = _parseFromJSON(files); //custom
    }

    // quotation->introduction
    cJSON *introduction = cJSON_GetObjectItemCaseSensitive(quotationJSON, "introduction");
    if (cJSON_IsNull(introduction)) {
        introduction = NULL;
    }
    if (introduction) { 
    if(!cJSON_IsString(introduction) && !cJSON_IsNull(introduction))
    {
    goto end; //String
    }
    }

    // quotation->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(quotationJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (line_items) { 
    line_items_local_nonprim = _parseFromJSON(line_items); //custom
    }

    // quotation->preceding_sales_voucher_id
    cJSON *preceding_sales_voucher_id = cJSON_GetObjectItemCaseSensitive(quotationJSON, "precedingSalesVoucherId");
    if (cJSON_IsNull(preceding_sales_voucher_id)) {
        preceding_sales_voucher_id = NULL;
    }
    if (preceding_sales_voucher_id) { 
    if(!cJSON_IsString(preceding_sales_voucher_id) && !cJSON_IsNull(preceding_sales_voucher_id))
    {
    goto end; //String
    }
    }

    // quotation->preceding_sales_voucher_type
    cJSON *preceding_sales_voucher_type = cJSON_GetObjectItemCaseSensitive(quotationJSON, "precedingSalesVoucherType");
    if (cJSON_IsNull(preceding_sales_voucher_type)) {
        preceding_sales_voucher_type = NULL;
    }
    if (preceding_sales_voucher_type) { 
    preceding_sales_voucher_type_local_nonprim = preceding_sales_voucher_type_parseFromJSON(preceding_sales_voucher_type); //custom
    }

    // quotation->quotation_number
    cJSON *quotation_number = cJSON_GetObjectItemCaseSensitive(quotationJSON, "quotationNumber");
    if (cJSON_IsNull(quotation_number)) {
        quotation_number = NULL;
    }
    if (quotation_number) { 
    if(!cJSON_IsString(quotation_number) && !cJSON_IsNull(quotation_number))
    {
    goto end; //String
    }
    }

    // quotation->remark
    cJSON *remark = cJSON_GetObjectItemCaseSensitive(quotationJSON, "remark");
    if (cJSON_IsNull(remark)) {
        remark = NULL;
    }
    if (remark) { 
    if(!cJSON_IsString(remark) && !cJSON_IsNull(remark))
    {
    goto end; //String
    }
    }

    // quotation->subtotal
    cJSON *subtotal = cJSON_GetObjectItemCaseSensitive(quotationJSON, "subtotal");
    if (cJSON_IsNull(subtotal)) {
        subtotal = NULL;
    }
    if (subtotal) { 
    if(!cJSON_IsString(subtotal) && !cJSON_IsNull(subtotal))
    {
    goto end; //String
    }
    }

    // quotation->tax_condition
    cJSON *tax_condition = cJSON_GetObjectItemCaseSensitive(quotationJSON, "taxCondition");
    if (cJSON_IsNull(tax_condition)) {
        tax_condition = NULL;
    }
    if (tax_condition) { 
    if(!cJSON_IsString(tax_condition) && !cJSON_IsNull(tax_condition))
    {
    goto end; //String
    }
    }

    // quotation->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(quotationJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // quotation->total_amount
    cJSON *total_amount = cJSON_GetObjectItemCaseSensitive(quotationJSON, "totalAmount");
    if (cJSON_IsNull(total_amount)) {
        total_amount = NULL;
    }
    if (total_amount) { 
    if(!cJSON_IsString(total_amount) && !cJSON_IsNull(total_amount))
    {
    goto end; //String
    }
    }

    // quotation->total_tax
    cJSON *total_tax = cJSON_GetObjectItemCaseSensitive(quotationJSON, "totalTax");
    if (cJSON_IsNull(total_tax)) {
        total_tax = NULL;
    }
    if (total_tax) { 
    if(!cJSON_IsString(total_tax) && !cJSON_IsNull(total_tax))
    {
    goto end; //String
    }
    }

    // quotation->voucher_date
    cJSON *voucher_date = cJSON_GetObjectItemCaseSensitive(quotationJSON, "voucherDate");
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

    // quotation->voucher_status
    cJSON *voucher_status = cJSON_GetObjectItemCaseSensitive(quotationJSON, "voucherStatus");
    if (cJSON_IsNull(voucher_status)) {
        voucher_status = NULL;
    }
    if (!voucher_status) {
        goto end;
    }

    
    voucher_status_local_nonprim = voucher_status_parseFromJSON(voucher_status); //custom


    if (contact_id && !cJSON_IsNull(contact_id)) contact_id_local_str = strdup(contact_id->valuestring);
    if (contact_name && !cJSON_IsNull(contact_name)) contact_name_local_str = strdup(contact_name->valuestring);
    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (expiration_date) expiration_date_local_str = strdup(expiration_date->valuestring);
    if (introduction && !cJSON_IsNull(introduction)) introduction_local_str = strdup(introduction->valuestring);
    if (preceding_sales_voucher_id && !cJSON_IsNull(preceding_sales_voucher_id)) preceding_sales_voucher_id_local_str = strdup(preceding_sales_voucher_id->valuestring);
    if (quotation_number && !cJSON_IsNull(quotation_number)) quotation_number_local_str = strdup(quotation_number->valuestring);
    if (remark && !cJSON_IsNull(remark)) remark_local_str = strdup(remark->valuestring);
    if (subtotal && !cJSON_IsNull(subtotal)) subtotal_local_str = strdup(subtotal->valuestring);
    if (tax_condition && !cJSON_IsNull(tax_condition)) tax_condition_local_str = strdup(tax_condition->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (total_amount && !cJSON_IsNull(total_amount)) total_amount_local_str = strdup(total_amount->valuestring);
    if (total_tax && !cJSON_IsNull(total_tax)) total_tax_local_str = strdup(total_tax->valuestring);
    if (voucher_date) voucher_date_local_str = strdup(voucher_date->valuestring);

    quotation_local_var = quotation_create_internal (
        address ? address_local_nonprim : NULL,
        contact_id_local_str,
        contact_name_local_str,
        currency_local_str,
        expiration_date_local_str,
        files ? files_local_nonprim : NULL,
        introduction_local_str,
        line_items ? line_items_local_nonprim : NULL,
        preceding_sales_voucher_id_local_str,
        preceding_sales_voucher_type ? preceding_sales_voucher_type_local_nonprim : NULL,
        quotation_number_local_str,
        remark_local_str,
        subtotal_local_str,
        tax_condition_local_str,
        title_local_str,
        total_amount_local_str,
        total_tax_local_str,
        voucher_date_local_str,
        voucher_status_local_nonprim
        );

    if (!quotation_local_var) {
        goto end;
    }

    return quotation_local_var;
end:
    if (address_local_nonprim) {
        _free(address_local_nonprim);
        address_local_nonprim = NULL;
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
    if (expiration_date_local_str) {
        free(expiration_date_local_str);
        expiration_date_local_str = NULL;
    }
    if (files_local_nonprim) {
        _free(files_local_nonprim);
        files_local_nonprim = NULL;
    }
    if (introduction_local_str) {
        free(introduction_local_str);
        introduction_local_str = NULL;
    }
    if (line_items_local_nonprim) {
        _free(line_items_local_nonprim);
        line_items_local_nonprim = NULL;
    }
    if (preceding_sales_voucher_id_local_str) {
        free(preceding_sales_voucher_id_local_str);
        preceding_sales_voucher_id_local_str = NULL;
    }
    if (preceding_sales_voucher_type_local_nonprim) {
        preceding_sales_voucher_type_free(preceding_sales_voucher_type_local_nonprim);
        preceding_sales_voucher_type_local_nonprim = NULL;
    }
    if (quotation_number_local_str) {
        free(quotation_number_local_str);
        quotation_number_local_str = NULL;
    }
    if (remark_local_str) {
        free(remark_local_str);
        remark_local_str = NULL;
    }
    if (subtotal_local_str) {
        free(subtotal_local_str);
        subtotal_local_str = NULL;
    }
    if (tax_condition_local_str) {
        free(tax_condition_local_str);
        tax_condition_local_str = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    if (total_amount_local_str) {
        free(total_amount_local_str);
        total_amount_local_str = NULL;
    }
    if (total_tax_local_str) {
        free(total_tax_local_str);
        total_tax_local_str = NULL;
    }
    if (voucher_date_local_str) {
        free(voucher_date_local_str);
        voucher_date_local_str = NULL;
    }
    if (voucher_status_local_nonprim) {
        voucher_status_local_nonprim = 0;
    }
    return NULL;

}
