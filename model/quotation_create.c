#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "quotation_create.h"



static quotation_create_t *quotation_create_create_internal(
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
    char *tax_condition,
    char *title,
    char *voucher_date,
    simplebilly_api_voucher_status__e voucher_status
    ) {
    quotation_create_t *quotation_create_local_var = malloc(sizeof(quotation_create_t));
    if (!quotation_create_local_var) {
        return NULL;
    }
    memset(quotation_create_local_var, 0, sizeof(quotation_create_t));
    quotation_create_local_var->_library_owned = 1;
    quotation_create_local_var->address = address;
    quotation_create_local_var->contact_id = contact_id;
    quotation_create_local_var->contact_name = contact_name;
    quotation_create_local_var->currency = currency;
    quotation_create_local_var->expiration_date = expiration_date;
    quotation_create_local_var->files = files;
    quotation_create_local_var->introduction = introduction;
    quotation_create_local_var->line_items = line_items;
    quotation_create_local_var->preceding_sales_voucher_id = preceding_sales_voucher_id;
    quotation_create_local_var->preceding_sales_voucher_type = preceding_sales_voucher_type;
    quotation_create_local_var->quotation_number = quotation_number;
    quotation_create_local_var->remark = remark;
    quotation_create_local_var->tax_condition = tax_condition;
    quotation_create_local_var->title = title;
    quotation_create_local_var->voucher_date = voucher_date;
    quotation_create_local_var->voucher_status = voucher_status;
    return quotation_create_local_var;
}

__attribute__((deprecated)) quotation_create_t *quotation_create_create(
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
    char *tax_condition,
    char *title,
    char *voucher_date,
    simplebilly_api_voucher_status__e voucher_status
    ) {
    quotation_create_t *result = quotation_create_create_internal (
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
        tax_condition,
        title,
        voucher_date,
        voucher_status
        );
    if (!result) {
    }
    return result;
}

void quotation_create_free(quotation_create_t *quotation_create) {
    if(NULL == quotation_create){
        return ;
    }
    if(quotation_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "quotation_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (quotation_create->address) {
        _free(quotation_create->address);
        quotation_create->address = NULL;
    }
    if (quotation_create->contact_id) {
        free(quotation_create->contact_id);
        quotation_create->contact_id = NULL;
    }
    if (quotation_create->contact_name) {
        free(quotation_create->contact_name);
        quotation_create->contact_name = NULL;
    }
    if (quotation_create->currency) {
        free(quotation_create->currency);
        quotation_create->currency = NULL;
    }
    if (quotation_create->expiration_date) {
        free(quotation_create->expiration_date);
        quotation_create->expiration_date = NULL;
    }
    if (quotation_create->files) {
        _free(quotation_create->files);
        quotation_create->files = NULL;
    }
    if (quotation_create->introduction) {
        free(quotation_create->introduction);
        quotation_create->introduction = NULL;
    }
    if (quotation_create->line_items) {
        _free(quotation_create->line_items);
        quotation_create->line_items = NULL;
    }
    if (quotation_create->preceding_sales_voucher_id) {
        free(quotation_create->preceding_sales_voucher_id);
        quotation_create->preceding_sales_voucher_id = NULL;
    }
    if (quotation_create->preceding_sales_voucher_type) {
        preceding_sales_voucher_type_free(quotation_create->preceding_sales_voucher_type);
        quotation_create->preceding_sales_voucher_type = NULL;
    }
    if (quotation_create->quotation_number) {
        free(quotation_create->quotation_number);
        quotation_create->quotation_number = NULL;
    }
    if (quotation_create->remark) {
        free(quotation_create->remark);
        quotation_create->remark = NULL;
    }
    if (quotation_create->tax_condition) {
        free(quotation_create->tax_condition);
        quotation_create->tax_condition = NULL;
    }
    if (quotation_create->title) {
        free(quotation_create->title);
        quotation_create->title = NULL;
    }
    if (quotation_create->voucher_date) {
        free(quotation_create->voucher_date);
        quotation_create->voucher_date = NULL;
    }
    free(quotation_create);
}

cJSON *quotation_create_convertToJSON(quotation_create_t *quotation_create) {
    cJSON *item = cJSON_CreateObject();

    // quotation_create->address
    if(quotation_create->address) {
    cJSON *address_local_JSON = _convertToJSON(quotation_create->address);
    if(address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "address", address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // quotation_create->contact_id
    if(quotation_create->contact_id) {
    if(cJSON_AddStringToObject(item, "contactId", quotation_create->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // quotation_create->contact_name
    if(quotation_create->contact_name) {
    if(cJSON_AddStringToObject(item, "contactName", quotation_create->contact_name) == NULL) {
    goto fail; //String
    }
    }


    // quotation_create->currency
    if (!quotation_create->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", quotation_create->currency) == NULL) {
    goto fail; //String
    }


    // quotation_create->expiration_date
    if(quotation_create->expiration_date) {
    if(cJSON_AddStringToObject(item, "expirationDate", quotation_create->expiration_date) == NULL) {
    goto fail; //Date
    }
    }


    // quotation_create->files
    if(quotation_create->files) {
    cJSON *files_local_JSON = _convertToJSON(quotation_create->files);
    if(files_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "files", files_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // quotation_create->introduction
    if(quotation_create->introduction) {
    if(cJSON_AddStringToObject(item, "introduction", quotation_create->introduction) == NULL) {
    goto fail; //String
    }
    }


    // quotation_create->line_items
    if(quotation_create->line_items) {
    cJSON *line_items_local_JSON = _convertToJSON(quotation_create->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // quotation_create->preceding_sales_voucher_id
    if(quotation_create->preceding_sales_voucher_id) {
    if(cJSON_AddStringToObject(item, "precedingSalesVoucherId", quotation_create->preceding_sales_voucher_id) == NULL) {
    goto fail; //String
    }
    }


    // quotation_create->preceding_sales_voucher_type
    if(quotation_create->preceding_sales_voucher_type) {
    cJSON *preceding_sales_voucher_type_local_JSON = preceding_sales_voucher_type_convertToJSON(quotation_create->preceding_sales_voucher_type);
    if(preceding_sales_voucher_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "precedingSalesVoucherType", preceding_sales_voucher_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // quotation_create->quotation_number
    if(quotation_create->quotation_number) {
    if(cJSON_AddStringToObject(item, "quotationNumber", quotation_create->quotation_number) == NULL) {
    goto fail; //String
    }
    }


    // quotation_create->remark
    if(quotation_create->remark) {
    if(cJSON_AddStringToObject(item, "remark", quotation_create->remark) == NULL) {
    goto fail; //String
    }
    }


    // quotation_create->tax_condition
    if(quotation_create->tax_condition) {
    if(cJSON_AddStringToObject(item, "taxCondition", quotation_create->tax_condition) == NULL) {
    goto fail; //String
    }
    }


    // quotation_create->title
    if(quotation_create->title) {
    if(cJSON_AddStringToObject(item, "title", quotation_create->title) == NULL) {
    goto fail; //String
    }
    }


    // quotation_create->voucher_date
    if (!quotation_create->voucher_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "voucherDate", quotation_create->voucher_date) == NULL) {
    goto fail; //Date
    }


    // quotation_create->voucher_status
    if (simplebilly_api_voucher_status__NULL == quotation_create->voucher_status) {
        goto fail;
    }
    cJSON *voucher_status_local_JSON = voucher_status_convertToJSON(quotation_create->voucher_status);
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

quotation_create_t *quotation_create_parseFromJSON(cJSON *quotation_createJSON){

    quotation_create_t *quotation_create_local_var = NULL;

    // define the local variable for quotation_create->address
    _t *address_local_nonprim = NULL;

    char *contact_id_local_str = NULL;

    char *contact_name_local_str = NULL;

    char *currency_local_str = NULL;

    char *expiration_date_local_str = NULL;

    // define the local variable for quotation_create->files
    _t *files_local_nonprim = NULL;

    char *introduction_local_str = NULL;

    // define the local variable for quotation_create->line_items
    _t *line_items_local_nonprim = NULL;

    char *preceding_sales_voucher_id_local_str = NULL;

    // define the local variable for quotation_create->preceding_sales_voucher_type
    preceding_sales_voucher_type_t *preceding_sales_voucher_type_local_nonprim = NULL;

    char *quotation_number_local_str = NULL;

    char *remark_local_str = NULL;

    char *tax_condition_local_str = NULL;

    char *title_local_str = NULL;

    char *voucher_date_local_str = NULL;

    // define the local variable for quotation_create->voucher_status
    simplebilly_api_voucher_status__e voucher_status_local_nonprim = 0;

    // quotation_create->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    address_local_nonprim = _parseFromJSON(address); //custom
    }

    // quotation_create->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // quotation_create->contact_name
    cJSON *contact_name = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "contactName");
    if (cJSON_IsNull(contact_name)) {
        contact_name = NULL;
    }
    if (contact_name) { 
    if(!cJSON_IsString(contact_name) && !cJSON_IsNull(contact_name))
    {
    goto end; //String
    }
    }

    // quotation_create->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "currency");
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

    // quotation_create->expiration_date
    cJSON *expiration_date = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "expirationDate");
    if (cJSON_IsNull(expiration_date)) {
        expiration_date = NULL;
    }
    if (expiration_date) { 
    if(!cJSON_IsString(expiration_date))
    {
    goto end; //Date
    }
    }

    // quotation_create->files
    cJSON *files = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "files");
    if (cJSON_IsNull(files)) {
        files = NULL;
    }
    if (files) { 
    files_local_nonprim = _parseFromJSON(files); //custom
    }

    // quotation_create->introduction
    cJSON *introduction = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "introduction");
    if (cJSON_IsNull(introduction)) {
        introduction = NULL;
    }
    if (introduction) { 
    if(!cJSON_IsString(introduction) && !cJSON_IsNull(introduction))
    {
    goto end; //String
    }
    }

    // quotation_create->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (line_items) { 
    line_items_local_nonprim = _parseFromJSON(line_items); //custom
    }

    // quotation_create->preceding_sales_voucher_id
    cJSON *preceding_sales_voucher_id = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "precedingSalesVoucherId");
    if (cJSON_IsNull(preceding_sales_voucher_id)) {
        preceding_sales_voucher_id = NULL;
    }
    if (preceding_sales_voucher_id) { 
    if(!cJSON_IsString(preceding_sales_voucher_id) && !cJSON_IsNull(preceding_sales_voucher_id))
    {
    goto end; //String
    }
    }

    // quotation_create->preceding_sales_voucher_type
    cJSON *preceding_sales_voucher_type = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "precedingSalesVoucherType");
    if (cJSON_IsNull(preceding_sales_voucher_type)) {
        preceding_sales_voucher_type = NULL;
    }
    if (preceding_sales_voucher_type) { 
    preceding_sales_voucher_type_local_nonprim = preceding_sales_voucher_type_parseFromJSON(preceding_sales_voucher_type); //custom
    }

    // quotation_create->quotation_number
    cJSON *quotation_number = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "quotationNumber");
    if (cJSON_IsNull(quotation_number)) {
        quotation_number = NULL;
    }
    if (quotation_number) { 
    if(!cJSON_IsString(quotation_number) && !cJSON_IsNull(quotation_number))
    {
    goto end; //String
    }
    }

    // quotation_create->remark
    cJSON *remark = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "remark");
    if (cJSON_IsNull(remark)) {
        remark = NULL;
    }
    if (remark) { 
    if(!cJSON_IsString(remark) && !cJSON_IsNull(remark))
    {
    goto end; //String
    }
    }

    // quotation_create->tax_condition
    cJSON *tax_condition = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "taxCondition");
    if (cJSON_IsNull(tax_condition)) {
        tax_condition = NULL;
    }
    if (tax_condition) { 
    if(!cJSON_IsString(tax_condition) && !cJSON_IsNull(tax_condition))
    {
    goto end; //String
    }
    }

    // quotation_create->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // quotation_create->voucher_date
    cJSON *voucher_date = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "voucherDate");
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

    // quotation_create->voucher_status
    cJSON *voucher_status = cJSON_GetObjectItemCaseSensitive(quotation_createJSON, "voucherStatus");
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
    if (tax_condition && !cJSON_IsNull(tax_condition)) tax_condition_local_str = strdup(tax_condition->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (voucher_date) voucher_date_local_str = strdup(voucher_date->valuestring);

    quotation_create_local_var = quotation_create_create_internal (
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
        tax_condition_local_str,
        title_local_str,
        voucher_date_local_str,
        voucher_status_local_nonprim
        );

    if (!quotation_create_local_var) {
        goto end;
    }

    return quotation_create_local_var;
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
    if (tax_condition_local_str) {
        free(tax_condition_local_str);
        tax_condition_local_str = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
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
