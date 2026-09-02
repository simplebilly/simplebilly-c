#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "order_confirmation.h"



static order_confirmation_t *order_confirmation_create_internal(
    any_type_t *address,
    char *confirmation_number,
    char *contact_id,
    char *contact_name,
    char *currency,
    any_type_t *files,
    char *introduction,
    any_type_t *line_items,
    char *preceding_sales_voucher_id,
    preceding_sales_voucher_type_t *preceding_sales_voucher_type,
    char *remark,
    char *subtotal,
    char *tax_condition,
    char *title,
    char *total_amount,
    char *total_tax,
    char *voucher_date,
    simplebilly_api_voucher_status__e voucher_status
    ) {
    order_confirmation_t *order_confirmation_local_var = malloc(sizeof(order_confirmation_t));
    if (!order_confirmation_local_var) {
        return NULL;
    }
    memset(order_confirmation_local_var, 0, sizeof(order_confirmation_t));
    order_confirmation_local_var->_library_owned = 1;
    order_confirmation_local_var->address = address;
    order_confirmation_local_var->confirmation_number = confirmation_number;
    order_confirmation_local_var->contact_id = contact_id;
    order_confirmation_local_var->contact_name = contact_name;
    order_confirmation_local_var->currency = currency;
    order_confirmation_local_var->files = files;
    order_confirmation_local_var->introduction = introduction;
    order_confirmation_local_var->line_items = line_items;
    order_confirmation_local_var->preceding_sales_voucher_id = preceding_sales_voucher_id;
    order_confirmation_local_var->preceding_sales_voucher_type = preceding_sales_voucher_type;
    order_confirmation_local_var->remark = remark;
    order_confirmation_local_var->subtotal = subtotal;
    order_confirmation_local_var->tax_condition = tax_condition;
    order_confirmation_local_var->title = title;
    order_confirmation_local_var->total_amount = total_amount;
    order_confirmation_local_var->total_tax = total_tax;
    order_confirmation_local_var->voucher_date = voucher_date;
    order_confirmation_local_var->voucher_status = voucher_status;
    return order_confirmation_local_var;
}

__attribute__((deprecated)) order_confirmation_t *order_confirmation_create(
    any_type_t *address,
    char *confirmation_number,
    char *contact_id,
    char *contact_name,
    char *currency,
    any_type_t *files,
    char *introduction,
    any_type_t *line_items,
    char *preceding_sales_voucher_id,
    preceding_sales_voucher_type_t *preceding_sales_voucher_type,
    char *remark,
    char *subtotal,
    char *tax_condition,
    char *title,
    char *total_amount,
    char *total_tax,
    char *voucher_date,
    simplebilly_api_voucher_status__e voucher_status
    ) {
    order_confirmation_t *result = order_confirmation_create_internal (
        address,
        confirmation_number,
        contact_id,
        contact_name,
        currency,
        files,
        introduction,
        line_items,
        preceding_sales_voucher_id,
        preceding_sales_voucher_type,
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

void order_confirmation_free(order_confirmation_t *order_confirmation) {
    if(NULL == order_confirmation){
        return ;
    }
    if(order_confirmation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "order_confirmation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (order_confirmation->address) {
        _free(order_confirmation->address);
        order_confirmation->address = NULL;
    }
    if (order_confirmation->confirmation_number) {
        free(order_confirmation->confirmation_number);
        order_confirmation->confirmation_number = NULL;
    }
    if (order_confirmation->contact_id) {
        free(order_confirmation->contact_id);
        order_confirmation->contact_id = NULL;
    }
    if (order_confirmation->contact_name) {
        free(order_confirmation->contact_name);
        order_confirmation->contact_name = NULL;
    }
    if (order_confirmation->currency) {
        free(order_confirmation->currency);
        order_confirmation->currency = NULL;
    }
    if (order_confirmation->files) {
        _free(order_confirmation->files);
        order_confirmation->files = NULL;
    }
    if (order_confirmation->introduction) {
        free(order_confirmation->introduction);
        order_confirmation->introduction = NULL;
    }
    if (order_confirmation->line_items) {
        _free(order_confirmation->line_items);
        order_confirmation->line_items = NULL;
    }
    if (order_confirmation->preceding_sales_voucher_id) {
        free(order_confirmation->preceding_sales_voucher_id);
        order_confirmation->preceding_sales_voucher_id = NULL;
    }
    if (order_confirmation->preceding_sales_voucher_type) {
        preceding_sales_voucher_type_free(order_confirmation->preceding_sales_voucher_type);
        order_confirmation->preceding_sales_voucher_type = NULL;
    }
    if (order_confirmation->remark) {
        free(order_confirmation->remark);
        order_confirmation->remark = NULL;
    }
    if (order_confirmation->subtotal) {
        free(order_confirmation->subtotal);
        order_confirmation->subtotal = NULL;
    }
    if (order_confirmation->tax_condition) {
        free(order_confirmation->tax_condition);
        order_confirmation->tax_condition = NULL;
    }
    if (order_confirmation->title) {
        free(order_confirmation->title);
        order_confirmation->title = NULL;
    }
    if (order_confirmation->total_amount) {
        free(order_confirmation->total_amount);
        order_confirmation->total_amount = NULL;
    }
    if (order_confirmation->total_tax) {
        free(order_confirmation->total_tax);
        order_confirmation->total_tax = NULL;
    }
    if (order_confirmation->voucher_date) {
        free(order_confirmation->voucher_date);
        order_confirmation->voucher_date = NULL;
    }
    free(order_confirmation);
}

cJSON *order_confirmation_convertToJSON(order_confirmation_t *order_confirmation) {
    cJSON *item = cJSON_CreateObject();

    // order_confirmation->address
    if(order_confirmation->address) {
    cJSON *address_local_JSON = _convertToJSON(order_confirmation->address);
    if(address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "address", address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_confirmation->confirmation_number
    if(order_confirmation->confirmation_number) {
    if(cJSON_AddStringToObject(item, "confirmationNumber", order_confirmation->confirmation_number) == NULL) {
    goto fail; //String
    }
    }


    // order_confirmation->contact_id
    if(order_confirmation->contact_id) {
    if(cJSON_AddStringToObject(item, "contactId", order_confirmation->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // order_confirmation->contact_name
    if(order_confirmation->contact_name) {
    if(cJSON_AddStringToObject(item, "contactName", order_confirmation->contact_name) == NULL) {
    goto fail; //String
    }
    }


    // order_confirmation->currency
    if (!order_confirmation->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", order_confirmation->currency) == NULL) {
    goto fail; //String
    }


    // order_confirmation->files
    if(order_confirmation->files) {
    cJSON *files_local_JSON = _convertToJSON(order_confirmation->files);
    if(files_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "files", files_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_confirmation->introduction
    if(order_confirmation->introduction) {
    if(cJSON_AddStringToObject(item, "introduction", order_confirmation->introduction) == NULL) {
    goto fail; //String
    }
    }


    // order_confirmation->line_items
    if(order_confirmation->line_items) {
    cJSON *line_items_local_JSON = _convertToJSON(order_confirmation->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_confirmation->preceding_sales_voucher_id
    if(order_confirmation->preceding_sales_voucher_id) {
    if(cJSON_AddStringToObject(item, "precedingSalesVoucherId", order_confirmation->preceding_sales_voucher_id) == NULL) {
    goto fail; //String
    }
    }


    // order_confirmation->preceding_sales_voucher_type
    if(order_confirmation->preceding_sales_voucher_type) {
    cJSON *preceding_sales_voucher_type_local_JSON = preceding_sales_voucher_type_convertToJSON(order_confirmation->preceding_sales_voucher_type);
    if(preceding_sales_voucher_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "precedingSalesVoucherType", preceding_sales_voucher_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // order_confirmation->remark
    if(order_confirmation->remark) {
    if(cJSON_AddStringToObject(item, "remark", order_confirmation->remark) == NULL) {
    goto fail; //String
    }
    }


    // order_confirmation->subtotal
    if(order_confirmation->subtotal) {
    if(cJSON_AddStringToObject(item, "subtotal", order_confirmation->subtotal) == NULL) {
    goto fail; //String
    }
    }


    // order_confirmation->tax_condition
    if(order_confirmation->tax_condition) {
    if(cJSON_AddStringToObject(item, "taxCondition", order_confirmation->tax_condition) == NULL) {
    goto fail; //String
    }
    }


    // order_confirmation->title
    if(order_confirmation->title) {
    if(cJSON_AddStringToObject(item, "title", order_confirmation->title) == NULL) {
    goto fail; //String
    }
    }


    // order_confirmation->total_amount
    if(order_confirmation->total_amount) {
    if(cJSON_AddStringToObject(item, "totalAmount", order_confirmation->total_amount) == NULL) {
    goto fail; //String
    }
    }


    // order_confirmation->total_tax
    if(order_confirmation->total_tax) {
    if(cJSON_AddStringToObject(item, "totalTax", order_confirmation->total_tax) == NULL) {
    goto fail; //String
    }
    }


    // order_confirmation->voucher_date
    if (!order_confirmation->voucher_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "voucherDate", order_confirmation->voucher_date) == NULL) {
    goto fail; //Date
    }


    // order_confirmation->voucher_status
    if (simplebilly_api_voucher_status__NULL == order_confirmation->voucher_status) {
        goto fail;
    }
    cJSON *voucher_status_local_JSON = voucher_status_convertToJSON(order_confirmation->voucher_status);
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

order_confirmation_t *order_confirmation_parseFromJSON(cJSON *order_confirmationJSON){

    order_confirmation_t *order_confirmation_local_var = NULL;

    // define the local variable for order_confirmation->address
    _t *address_local_nonprim = NULL;

    char *confirmation_number_local_str = NULL;

    char *contact_id_local_str = NULL;

    char *contact_name_local_str = NULL;

    char *currency_local_str = NULL;

    // define the local variable for order_confirmation->files
    _t *files_local_nonprim = NULL;

    char *introduction_local_str = NULL;

    // define the local variable for order_confirmation->line_items
    _t *line_items_local_nonprim = NULL;

    char *preceding_sales_voucher_id_local_str = NULL;

    // define the local variable for order_confirmation->preceding_sales_voucher_type
    preceding_sales_voucher_type_t *preceding_sales_voucher_type_local_nonprim = NULL;

    char *remark_local_str = NULL;

    char *subtotal_local_str = NULL;

    char *tax_condition_local_str = NULL;

    char *title_local_str = NULL;

    char *total_amount_local_str = NULL;

    char *total_tax_local_str = NULL;

    char *voucher_date_local_str = NULL;

    // define the local variable for order_confirmation->voucher_status
    simplebilly_api_voucher_status__e voucher_status_local_nonprim = 0;

    // order_confirmation->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    address_local_nonprim = _parseFromJSON(address); //custom
    }

    // order_confirmation->confirmation_number
    cJSON *confirmation_number = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "confirmationNumber");
    if (cJSON_IsNull(confirmation_number)) {
        confirmation_number = NULL;
    }
    if (confirmation_number) { 
    if(!cJSON_IsString(confirmation_number) && !cJSON_IsNull(confirmation_number))
    {
    goto end; //String
    }
    }

    // order_confirmation->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // order_confirmation->contact_name
    cJSON *contact_name = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "contactName");
    if (cJSON_IsNull(contact_name)) {
        contact_name = NULL;
    }
    if (contact_name) { 
    if(!cJSON_IsString(contact_name) && !cJSON_IsNull(contact_name))
    {
    goto end; //String
    }
    }

    // order_confirmation->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "currency");
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

    // order_confirmation->files
    cJSON *files = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "files");
    if (cJSON_IsNull(files)) {
        files = NULL;
    }
    if (files) { 
    files_local_nonprim = _parseFromJSON(files); //custom
    }

    // order_confirmation->introduction
    cJSON *introduction = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "introduction");
    if (cJSON_IsNull(introduction)) {
        introduction = NULL;
    }
    if (introduction) { 
    if(!cJSON_IsString(introduction) && !cJSON_IsNull(introduction))
    {
    goto end; //String
    }
    }

    // order_confirmation->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (line_items) { 
    line_items_local_nonprim = _parseFromJSON(line_items); //custom
    }

    // order_confirmation->preceding_sales_voucher_id
    cJSON *preceding_sales_voucher_id = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "precedingSalesVoucherId");
    if (cJSON_IsNull(preceding_sales_voucher_id)) {
        preceding_sales_voucher_id = NULL;
    }
    if (preceding_sales_voucher_id) { 
    if(!cJSON_IsString(preceding_sales_voucher_id) && !cJSON_IsNull(preceding_sales_voucher_id))
    {
    goto end; //String
    }
    }

    // order_confirmation->preceding_sales_voucher_type
    cJSON *preceding_sales_voucher_type = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "precedingSalesVoucherType");
    if (cJSON_IsNull(preceding_sales_voucher_type)) {
        preceding_sales_voucher_type = NULL;
    }
    if (preceding_sales_voucher_type) { 
    preceding_sales_voucher_type_local_nonprim = preceding_sales_voucher_type_parseFromJSON(preceding_sales_voucher_type); //custom
    }

    // order_confirmation->remark
    cJSON *remark = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "remark");
    if (cJSON_IsNull(remark)) {
        remark = NULL;
    }
    if (remark) { 
    if(!cJSON_IsString(remark) && !cJSON_IsNull(remark))
    {
    goto end; //String
    }
    }

    // order_confirmation->subtotal
    cJSON *subtotal = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "subtotal");
    if (cJSON_IsNull(subtotal)) {
        subtotal = NULL;
    }
    if (subtotal) { 
    if(!cJSON_IsString(subtotal) && !cJSON_IsNull(subtotal))
    {
    goto end; //String
    }
    }

    // order_confirmation->tax_condition
    cJSON *tax_condition = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "taxCondition");
    if (cJSON_IsNull(tax_condition)) {
        tax_condition = NULL;
    }
    if (tax_condition) { 
    if(!cJSON_IsString(tax_condition) && !cJSON_IsNull(tax_condition))
    {
    goto end; //String
    }
    }

    // order_confirmation->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // order_confirmation->total_amount
    cJSON *total_amount = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "totalAmount");
    if (cJSON_IsNull(total_amount)) {
        total_amount = NULL;
    }
    if (total_amount) { 
    if(!cJSON_IsString(total_amount) && !cJSON_IsNull(total_amount))
    {
    goto end; //String
    }
    }

    // order_confirmation->total_tax
    cJSON *total_tax = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "totalTax");
    if (cJSON_IsNull(total_tax)) {
        total_tax = NULL;
    }
    if (total_tax) { 
    if(!cJSON_IsString(total_tax) && !cJSON_IsNull(total_tax))
    {
    goto end; //String
    }
    }

    // order_confirmation->voucher_date
    cJSON *voucher_date = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "voucherDate");
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

    // order_confirmation->voucher_status
    cJSON *voucher_status = cJSON_GetObjectItemCaseSensitive(order_confirmationJSON, "voucherStatus");
    if (cJSON_IsNull(voucher_status)) {
        voucher_status = NULL;
    }
    if (!voucher_status) {
        goto end;
    }

    
    voucher_status_local_nonprim = voucher_status_parseFromJSON(voucher_status); //custom


    if (confirmation_number && !cJSON_IsNull(confirmation_number)) confirmation_number_local_str = strdup(confirmation_number->valuestring);
    if (contact_id && !cJSON_IsNull(contact_id)) contact_id_local_str = strdup(contact_id->valuestring);
    if (contact_name && !cJSON_IsNull(contact_name)) contact_name_local_str = strdup(contact_name->valuestring);
    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (introduction && !cJSON_IsNull(introduction)) introduction_local_str = strdup(introduction->valuestring);
    if (preceding_sales_voucher_id && !cJSON_IsNull(preceding_sales_voucher_id)) preceding_sales_voucher_id_local_str = strdup(preceding_sales_voucher_id->valuestring);
    if (remark && !cJSON_IsNull(remark)) remark_local_str = strdup(remark->valuestring);
    if (subtotal && !cJSON_IsNull(subtotal)) subtotal_local_str = strdup(subtotal->valuestring);
    if (tax_condition && !cJSON_IsNull(tax_condition)) tax_condition_local_str = strdup(tax_condition->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (total_amount && !cJSON_IsNull(total_amount)) total_amount_local_str = strdup(total_amount->valuestring);
    if (total_tax && !cJSON_IsNull(total_tax)) total_tax_local_str = strdup(total_tax->valuestring);
    if (voucher_date) voucher_date_local_str = strdup(voucher_date->valuestring);

    order_confirmation_local_var = order_confirmation_create_internal (
        address ? address_local_nonprim : NULL,
        confirmation_number_local_str,
        contact_id_local_str,
        contact_name_local_str,
        currency_local_str,
        files ? files_local_nonprim : NULL,
        introduction_local_str,
        line_items ? line_items_local_nonprim : NULL,
        preceding_sales_voucher_id_local_str,
        preceding_sales_voucher_type ? preceding_sales_voucher_type_local_nonprim : NULL,
        remark_local_str,
        subtotal_local_str,
        tax_condition_local_str,
        title_local_str,
        total_amount_local_str,
        total_tax_local_str,
        voucher_date_local_str,
        voucher_status_local_nonprim
        );

    if (!order_confirmation_local_var) {
        goto end;
    }

    return order_confirmation_local_var;
end:
    if (address_local_nonprim) {
        _free(address_local_nonprim);
        address_local_nonprim = NULL;
    }
    if (confirmation_number_local_str) {
        free(confirmation_number_local_str);
        confirmation_number_local_str = NULL;
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
