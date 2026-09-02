#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delivery_note_create.h"



static delivery_note_create_t *delivery_note_create_create_internal(
    any_type_t *address,
    char *contact_id,
    char *contact_name,
    char *currency,
    char *delivery_date,
    char *delivery_note_number,
    any_type_t *files,
    char *introduction,
    any_type_t *line_items,
    char *preceding_sales_voucher_id,
    preceding_sales_voucher_type_t *preceding_sales_voucher_type,
    char *remark,
    char *shipping_date,
    char *shipping_method,
    char *title,
    char *voucher_date,
    simplebilly_api_voucher_status__e voucher_status
    ) {
    delivery_note_create_t *delivery_note_create_local_var = malloc(sizeof(delivery_note_create_t));
    if (!delivery_note_create_local_var) {
        return NULL;
    }
    memset(delivery_note_create_local_var, 0, sizeof(delivery_note_create_t));
    delivery_note_create_local_var->_library_owned = 1;
    delivery_note_create_local_var->address = address;
    delivery_note_create_local_var->contact_id = contact_id;
    delivery_note_create_local_var->contact_name = contact_name;
    delivery_note_create_local_var->currency = currency;
    delivery_note_create_local_var->delivery_date = delivery_date;
    delivery_note_create_local_var->delivery_note_number = delivery_note_number;
    delivery_note_create_local_var->files = files;
    delivery_note_create_local_var->introduction = introduction;
    delivery_note_create_local_var->line_items = line_items;
    delivery_note_create_local_var->preceding_sales_voucher_id = preceding_sales_voucher_id;
    delivery_note_create_local_var->preceding_sales_voucher_type = preceding_sales_voucher_type;
    delivery_note_create_local_var->remark = remark;
    delivery_note_create_local_var->shipping_date = shipping_date;
    delivery_note_create_local_var->shipping_method = shipping_method;
    delivery_note_create_local_var->title = title;
    delivery_note_create_local_var->voucher_date = voucher_date;
    delivery_note_create_local_var->voucher_status = voucher_status;
    return delivery_note_create_local_var;
}

__attribute__((deprecated)) delivery_note_create_t *delivery_note_create_create(
    any_type_t *address,
    char *contact_id,
    char *contact_name,
    char *currency,
    char *delivery_date,
    char *delivery_note_number,
    any_type_t *files,
    char *introduction,
    any_type_t *line_items,
    char *preceding_sales_voucher_id,
    preceding_sales_voucher_type_t *preceding_sales_voucher_type,
    char *remark,
    char *shipping_date,
    char *shipping_method,
    char *title,
    char *voucher_date,
    simplebilly_api_voucher_status__e voucher_status
    ) {
    delivery_note_create_t *result = delivery_note_create_create_internal (
        address,
        contact_id,
        contact_name,
        currency,
        delivery_date,
        delivery_note_number,
        files,
        introduction,
        line_items,
        preceding_sales_voucher_id,
        preceding_sales_voucher_type,
        remark,
        shipping_date,
        shipping_method,
        title,
        voucher_date,
        voucher_status
        );
    if (!result) {
    }
    return result;
}

void delivery_note_create_free(delivery_note_create_t *delivery_note_create) {
    if(NULL == delivery_note_create){
        return ;
    }
    if(delivery_note_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delivery_note_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delivery_note_create->address) {
        _free(delivery_note_create->address);
        delivery_note_create->address = NULL;
    }
    if (delivery_note_create->contact_id) {
        free(delivery_note_create->contact_id);
        delivery_note_create->contact_id = NULL;
    }
    if (delivery_note_create->contact_name) {
        free(delivery_note_create->contact_name);
        delivery_note_create->contact_name = NULL;
    }
    if (delivery_note_create->currency) {
        free(delivery_note_create->currency);
        delivery_note_create->currency = NULL;
    }
    if (delivery_note_create->delivery_date) {
        free(delivery_note_create->delivery_date);
        delivery_note_create->delivery_date = NULL;
    }
    if (delivery_note_create->delivery_note_number) {
        free(delivery_note_create->delivery_note_number);
        delivery_note_create->delivery_note_number = NULL;
    }
    if (delivery_note_create->files) {
        _free(delivery_note_create->files);
        delivery_note_create->files = NULL;
    }
    if (delivery_note_create->introduction) {
        free(delivery_note_create->introduction);
        delivery_note_create->introduction = NULL;
    }
    if (delivery_note_create->line_items) {
        _free(delivery_note_create->line_items);
        delivery_note_create->line_items = NULL;
    }
    if (delivery_note_create->preceding_sales_voucher_id) {
        free(delivery_note_create->preceding_sales_voucher_id);
        delivery_note_create->preceding_sales_voucher_id = NULL;
    }
    if (delivery_note_create->preceding_sales_voucher_type) {
        preceding_sales_voucher_type_free(delivery_note_create->preceding_sales_voucher_type);
        delivery_note_create->preceding_sales_voucher_type = NULL;
    }
    if (delivery_note_create->remark) {
        free(delivery_note_create->remark);
        delivery_note_create->remark = NULL;
    }
    if (delivery_note_create->shipping_date) {
        free(delivery_note_create->shipping_date);
        delivery_note_create->shipping_date = NULL;
    }
    if (delivery_note_create->shipping_method) {
        free(delivery_note_create->shipping_method);
        delivery_note_create->shipping_method = NULL;
    }
    if (delivery_note_create->title) {
        free(delivery_note_create->title);
        delivery_note_create->title = NULL;
    }
    if (delivery_note_create->voucher_date) {
        free(delivery_note_create->voucher_date);
        delivery_note_create->voucher_date = NULL;
    }
    free(delivery_note_create);
}

cJSON *delivery_note_create_convertToJSON(delivery_note_create_t *delivery_note_create) {
    cJSON *item = cJSON_CreateObject();

    // delivery_note_create->address
    if(delivery_note_create->address) {
    cJSON *address_local_JSON = _convertToJSON(delivery_note_create->address);
    if(address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "address", address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // delivery_note_create->contact_id
    if(delivery_note_create->contact_id) {
    if(cJSON_AddStringToObject(item, "contactId", delivery_note_create->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // delivery_note_create->contact_name
    if(delivery_note_create->contact_name) {
    if(cJSON_AddStringToObject(item, "contactName", delivery_note_create->contact_name) == NULL) {
    goto fail; //String
    }
    }


    // delivery_note_create->currency
    if (!delivery_note_create->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", delivery_note_create->currency) == NULL) {
    goto fail; //String
    }


    // delivery_note_create->delivery_date
    if(delivery_note_create->delivery_date) {
    if(cJSON_AddStringToObject(item, "deliveryDate", delivery_note_create->delivery_date) == NULL) {
    goto fail; //Date
    }
    }


    // delivery_note_create->delivery_note_number
    if(delivery_note_create->delivery_note_number) {
    if(cJSON_AddStringToObject(item, "deliveryNoteNumber", delivery_note_create->delivery_note_number) == NULL) {
    goto fail; //String
    }
    }


    // delivery_note_create->files
    if(delivery_note_create->files) {
    cJSON *files_local_JSON = _convertToJSON(delivery_note_create->files);
    if(files_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "files", files_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // delivery_note_create->introduction
    if(delivery_note_create->introduction) {
    if(cJSON_AddStringToObject(item, "introduction", delivery_note_create->introduction) == NULL) {
    goto fail; //String
    }
    }


    // delivery_note_create->line_items
    if(delivery_note_create->line_items) {
    cJSON *line_items_local_JSON = _convertToJSON(delivery_note_create->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // delivery_note_create->preceding_sales_voucher_id
    if(delivery_note_create->preceding_sales_voucher_id) {
    if(cJSON_AddStringToObject(item, "precedingSalesVoucherId", delivery_note_create->preceding_sales_voucher_id) == NULL) {
    goto fail; //String
    }
    }


    // delivery_note_create->preceding_sales_voucher_type
    if(delivery_note_create->preceding_sales_voucher_type) {
    cJSON *preceding_sales_voucher_type_local_JSON = preceding_sales_voucher_type_convertToJSON(delivery_note_create->preceding_sales_voucher_type);
    if(preceding_sales_voucher_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "precedingSalesVoucherType", preceding_sales_voucher_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // delivery_note_create->remark
    if(delivery_note_create->remark) {
    if(cJSON_AddStringToObject(item, "remark", delivery_note_create->remark) == NULL) {
    goto fail; //String
    }
    }


    // delivery_note_create->shipping_date
    if(delivery_note_create->shipping_date) {
    if(cJSON_AddStringToObject(item, "shippingDate", delivery_note_create->shipping_date) == NULL) {
    goto fail; //Date
    }
    }


    // delivery_note_create->shipping_method
    if(delivery_note_create->shipping_method) {
    if(cJSON_AddStringToObject(item, "shippingMethod", delivery_note_create->shipping_method) == NULL) {
    goto fail; //String
    }
    }


    // delivery_note_create->title
    if(delivery_note_create->title) {
    if(cJSON_AddStringToObject(item, "title", delivery_note_create->title) == NULL) {
    goto fail; //String
    }
    }


    // delivery_note_create->voucher_date
    if (!delivery_note_create->voucher_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "voucherDate", delivery_note_create->voucher_date) == NULL) {
    goto fail; //Date
    }


    // delivery_note_create->voucher_status
    if (simplebilly_api_voucher_status__NULL == delivery_note_create->voucher_status) {
        goto fail;
    }
    cJSON *voucher_status_local_JSON = voucher_status_convertToJSON(delivery_note_create->voucher_status);
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

delivery_note_create_t *delivery_note_create_parseFromJSON(cJSON *delivery_note_createJSON){

    delivery_note_create_t *delivery_note_create_local_var = NULL;

    // define the local variable for delivery_note_create->address
    _t *address_local_nonprim = NULL;

    char *contact_id_local_str = NULL;

    char *contact_name_local_str = NULL;

    char *currency_local_str = NULL;

    char *delivery_date_local_str = NULL;

    char *delivery_note_number_local_str = NULL;

    // define the local variable for delivery_note_create->files
    _t *files_local_nonprim = NULL;

    char *introduction_local_str = NULL;

    // define the local variable for delivery_note_create->line_items
    _t *line_items_local_nonprim = NULL;

    char *preceding_sales_voucher_id_local_str = NULL;

    // define the local variable for delivery_note_create->preceding_sales_voucher_type
    preceding_sales_voucher_type_t *preceding_sales_voucher_type_local_nonprim = NULL;

    char *remark_local_str = NULL;

    char *shipping_date_local_str = NULL;

    char *shipping_method_local_str = NULL;

    char *title_local_str = NULL;

    char *voucher_date_local_str = NULL;

    // define the local variable for delivery_note_create->voucher_status
    simplebilly_api_voucher_status__e voucher_status_local_nonprim = 0;

    // delivery_note_create->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    address_local_nonprim = _parseFromJSON(address); //custom
    }

    // delivery_note_create->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // delivery_note_create->contact_name
    cJSON *contact_name = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "contactName");
    if (cJSON_IsNull(contact_name)) {
        contact_name = NULL;
    }
    if (contact_name) { 
    if(!cJSON_IsString(contact_name) && !cJSON_IsNull(contact_name))
    {
    goto end; //String
    }
    }

    // delivery_note_create->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "currency");
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

    // delivery_note_create->delivery_date
    cJSON *delivery_date = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "deliveryDate");
    if (cJSON_IsNull(delivery_date)) {
        delivery_date = NULL;
    }
    if (delivery_date) { 
    if(!cJSON_IsString(delivery_date))
    {
    goto end; //Date
    }
    }

    // delivery_note_create->delivery_note_number
    cJSON *delivery_note_number = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "deliveryNoteNumber");
    if (cJSON_IsNull(delivery_note_number)) {
        delivery_note_number = NULL;
    }
    if (delivery_note_number) { 
    if(!cJSON_IsString(delivery_note_number) && !cJSON_IsNull(delivery_note_number))
    {
    goto end; //String
    }
    }

    // delivery_note_create->files
    cJSON *files = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "files");
    if (cJSON_IsNull(files)) {
        files = NULL;
    }
    if (files) { 
    files_local_nonprim = _parseFromJSON(files); //custom
    }

    // delivery_note_create->introduction
    cJSON *introduction = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "introduction");
    if (cJSON_IsNull(introduction)) {
        introduction = NULL;
    }
    if (introduction) { 
    if(!cJSON_IsString(introduction) && !cJSON_IsNull(introduction))
    {
    goto end; //String
    }
    }

    // delivery_note_create->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (line_items) { 
    line_items_local_nonprim = _parseFromJSON(line_items); //custom
    }

    // delivery_note_create->preceding_sales_voucher_id
    cJSON *preceding_sales_voucher_id = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "precedingSalesVoucherId");
    if (cJSON_IsNull(preceding_sales_voucher_id)) {
        preceding_sales_voucher_id = NULL;
    }
    if (preceding_sales_voucher_id) { 
    if(!cJSON_IsString(preceding_sales_voucher_id) && !cJSON_IsNull(preceding_sales_voucher_id))
    {
    goto end; //String
    }
    }

    // delivery_note_create->preceding_sales_voucher_type
    cJSON *preceding_sales_voucher_type = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "precedingSalesVoucherType");
    if (cJSON_IsNull(preceding_sales_voucher_type)) {
        preceding_sales_voucher_type = NULL;
    }
    if (preceding_sales_voucher_type) { 
    preceding_sales_voucher_type_local_nonprim = preceding_sales_voucher_type_parseFromJSON(preceding_sales_voucher_type); //custom
    }

    // delivery_note_create->remark
    cJSON *remark = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "remark");
    if (cJSON_IsNull(remark)) {
        remark = NULL;
    }
    if (remark) { 
    if(!cJSON_IsString(remark) && !cJSON_IsNull(remark))
    {
    goto end; //String
    }
    }

    // delivery_note_create->shipping_date
    cJSON *shipping_date = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "shippingDate");
    if (cJSON_IsNull(shipping_date)) {
        shipping_date = NULL;
    }
    if (shipping_date) { 
    if(!cJSON_IsString(shipping_date))
    {
    goto end; //Date
    }
    }

    // delivery_note_create->shipping_method
    cJSON *shipping_method = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "shippingMethod");
    if (cJSON_IsNull(shipping_method)) {
        shipping_method = NULL;
    }
    if (shipping_method) { 
    if(!cJSON_IsString(shipping_method) && !cJSON_IsNull(shipping_method))
    {
    goto end; //String
    }
    }

    // delivery_note_create->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // delivery_note_create->voucher_date
    cJSON *voucher_date = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "voucherDate");
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

    // delivery_note_create->voucher_status
    cJSON *voucher_status = cJSON_GetObjectItemCaseSensitive(delivery_note_createJSON, "voucherStatus");
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
    if (delivery_date) delivery_date_local_str = strdup(delivery_date->valuestring);
    if (delivery_note_number && !cJSON_IsNull(delivery_note_number)) delivery_note_number_local_str = strdup(delivery_note_number->valuestring);
    if (introduction && !cJSON_IsNull(introduction)) introduction_local_str = strdup(introduction->valuestring);
    if (preceding_sales_voucher_id && !cJSON_IsNull(preceding_sales_voucher_id)) preceding_sales_voucher_id_local_str = strdup(preceding_sales_voucher_id->valuestring);
    if (remark && !cJSON_IsNull(remark)) remark_local_str = strdup(remark->valuestring);
    if (shipping_date) shipping_date_local_str = strdup(shipping_date->valuestring);
    if (shipping_method && !cJSON_IsNull(shipping_method)) shipping_method_local_str = strdup(shipping_method->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (voucher_date) voucher_date_local_str = strdup(voucher_date->valuestring);

    delivery_note_create_local_var = delivery_note_create_create_internal (
        address ? address_local_nonprim : NULL,
        contact_id_local_str,
        contact_name_local_str,
        currency_local_str,
        delivery_date_local_str,
        delivery_note_number_local_str,
        files ? files_local_nonprim : NULL,
        introduction_local_str,
        line_items ? line_items_local_nonprim : NULL,
        preceding_sales_voucher_id_local_str,
        preceding_sales_voucher_type ? preceding_sales_voucher_type_local_nonprim : NULL,
        remark_local_str,
        shipping_date_local_str,
        shipping_method_local_str,
        title_local_str,
        voucher_date_local_str,
        voucher_status_local_nonprim
        );

    if (!delivery_note_create_local_var) {
        goto end;
    }

    return delivery_note_create_local_var;
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
    if (delivery_date_local_str) {
        free(delivery_date_local_str);
        delivery_date_local_str = NULL;
    }
    if (delivery_note_number_local_str) {
        free(delivery_note_number_local_str);
        delivery_note_number_local_str = NULL;
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
    if (shipping_date_local_str) {
        free(shipping_date_local_str);
        shipping_date_local_str = NULL;
    }
    if (shipping_method_local_str) {
        free(shipping_method_local_str);
        shipping_method_local_str = NULL;
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
