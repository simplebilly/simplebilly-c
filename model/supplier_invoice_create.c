#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "supplier_invoice_create.h"



static supplier_invoice_create_t *supplier_invoice_create_create_internal(
    char *currency,
    char *goods_receipt_id,
    char *invoice_date,
    char *invoice_number,
    any_type_t *line_items,
    char *notes,
    char *purchase_order_id,
    supplier_invoice_status_t *status,
    char *supplier_contact_id,
    char *supplier_name,
    char *total_gross_amount,
    char *total_net_amount
    ) {
    supplier_invoice_create_t *supplier_invoice_create_local_var = malloc(sizeof(supplier_invoice_create_t));
    if (!supplier_invoice_create_local_var) {
        return NULL;
    }
    memset(supplier_invoice_create_local_var, 0, sizeof(supplier_invoice_create_t));
    supplier_invoice_create_local_var->_library_owned = 1;
    supplier_invoice_create_local_var->currency = currency;
    supplier_invoice_create_local_var->goods_receipt_id = goods_receipt_id;
    supplier_invoice_create_local_var->invoice_date = invoice_date;
    supplier_invoice_create_local_var->invoice_number = invoice_number;
    supplier_invoice_create_local_var->line_items = line_items;
    supplier_invoice_create_local_var->notes = notes;
    supplier_invoice_create_local_var->purchase_order_id = purchase_order_id;
    supplier_invoice_create_local_var->status = status;
    supplier_invoice_create_local_var->supplier_contact_id = supplier_contact_id;
    supplier_invoice_create_local_var->supplier_name = supplier_name;
    supplier_invoice_create_local_var->total_gross_amount = total_gross_amount;
    supplier_invoice_create_local_var->total_net_amount = total_net_amount;
    return supplier_invoice_create_local_var;
}

__attribute__((deprecated)) supplier_invoice_create_t *supplier_invoice_create_create(
    char *currency,
    char *goods_receipt_id,
    char *invoice_date,
    char *invoice_number,
    any_type_t *line_items,
    char *notes,
    char *purchase_order_id,
    supplier_invoice_status_t *status,
    char *supplier_contact_id,
    char *supplier_name,
    char *total_gross_amount,
    char *total_net_amount
    ) {
    supplier_invoice_create_t *result = supplier_invoice_create_create_internal (
        currency,
        goods_receipt_id,
        invoice_date,
        invoice_number,
        line_items,
        notes,
        purchase_order_id,
        status,
        supplier_contact_id,
        supplier_name,
        total_gross_amount,
        total_net_amount
        );
    if (!result) {
    }
    return result;
}

void supplier_invoice_create_free(supplier_invoice_create_t *supplier_invoice_create) {
    if(NULL == supplier_invoice_create){
        return ;
    }
    if(supplier_invoice_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "supplier_invoice_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (supplier_invoice_create->currency) {
        free(supplier_invoice_create->currency);
        supplier_invoice_create->currency = NULL;
    }
    if (supplier_invoice_create->goods_receipt_id) {
        free(supplier_invoice_create->goods_receipt_id);
        supplier_invoice_create->goods_receipt_id = NULL;
    }
    if (supplier_invoice_create->invoice_date) {
        free(supplier_invoice_create->invoice_date);
        supplier_invoice_create->invoice_date = NULL;
    }
    if (supplier_invoice_create->invoice_number) {
        free(supplier_invoice_create->invoice_number);
        supplier_invoice_create->invoice_number = NULL;
    }
    if (supplier_invoice_create->line_items) {
        _free(supplier_invoice_create->line_items);
        supplier_invoice_create->line_items = NULL;
    }
    if (supplier_invoice_create->notes) {
        free(supplier_invoice_create->notes);
        supplier_invoice_create->notes = NULL;
    }
    if (supplier_invoice_create->purchase_order_id) {
        free(supplier_invoice_create->purchase_order_id);
        supplier_invoice_create->purchase_order_id = NULL;
    }
    if (supplier_invoice_create->status) {
        supplier_invoice_status_free(supplier_invoice_create->status);
        supplier_invoice_create->status = NULL;
    }
    if (supplier_invoice_create->supplier_contact_id) {
        free(supplier_invoice_create->supplier_contact_id);
        supplier_invoice_create->supplier_contact_id = NULL;
    }
    if (supplier_invoice_create->supplier_name) {
        free(supplier_invoice_create->supplier_name);
        supplier_invoice_create->supplier_name = NULL;
    }
    if (supplier_invoice_create->total_gross_amount) {
        free(supplier_invoice_create->total_gross_amount);
        supplier_invoice_create->total_gross_amount = NULL;
    }
    if (supplier_invoice_create->total_net_amount) {
        free(supplier_invoice_create->total_net_amount);
        supplier_invoice_create->total_net_amount = NULL;
    }
    free(supplier_invoice_create);
}

cJSON *supplier_invoice_create_convertToJSON(supplier_invoice_create_t *supplier_invoice_create) {
    cJSON *item = cJSON_CreateObject();

    // supplier_invoice_create->currency
    if(supplier_invoice_create->currency) {
    if(cJSON_AddStringToObject(item, "currency", supplier_invoice_create->currency) == NULL) {
    goto fail; //String
    }
    }


    // supplier_invoice_create->goods_receipt_id
    if(supplier_invoice_create->goods_receipt_id) {
    if(cJSON_AddStringToObject(item, "goodsReceiptId", supplier_invoice_create->goods_receipt_id) == NULL) {
    goto fail; //String
    }
    }


    // supplier_invoice_create->invoice_date
    if (!supplier_invoice_create->invoice_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoiceDate", supplier_invoice_create->invoice_date) == NULL) {
    goto fail; //Date
    }


    // supplier_invoice_create->invoice_number
    if (!supplier_invoice_create->invoice_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoiceNumber", supplier_invoice_create->invoice_number) == NULL) {
    goto fail; //String
    }


    // supplier_invoice_create->line_items
    if (!supplier_invoice_create->line_items) {
        goto fail;
    }
    cJSON *line_items_local_JSON = _convertToJSON(supplier_invoice_create->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // supplier_invoice_create->notes
    if(supplier_invoice_create->notes) {
    if(cJSON_AddStringToObject(item, "notes", supplier_invoice_create->notes) == NULL) {
    goto fail; //String
    }
    }


    // supplier_invoice_create->purchase_order_id
    if(supplier_invoice_create->purchase_order_id) {
    if(cJSON_AddStringToObject(item, "purchaseOrderId", supplier_invoice_create->purchase_order_id) == NULL) {
    goto fail; //String
    }
    }


    // supplier_invoice_create->status
    if (!supplier_invoice_create->status) {
        goto fail;
    }
    cJSON *status_local_JSON = supplier_invoice_status_convertToJSON(supplier_invoice_create->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // supplier_invoice_create->supplier_contact_id
    if(supplier_invoice_create->supplier_contact_id) {
    if(cJSON_AddStringToObject(item, "supplierContactId", supplier_invoice_create->supplier_contact_id) == NULL) {
    goto fail; //String
    }
    }


    // supplier_invoice_create->supplier_name
    if(supplier_invoice_create->supplier_name) {
    if(cJSON_AddStringToObject(item, "supplierName", supplier_invoice_create->supplier_name) == NULL) {
    goto fail; //String
    }
    }


    // supplier_invoice_create->total_gross_amount
    if(supplier_invoice_create->total_gross_amount) {
    if(cJSON_AddStringToObject(item, "totalGrossAmount", supplier_invoice_create->total_gross_amount) == NULL) {
    goto fail; //String
    }
    }


    // supplier_invoice_create->total_net_amount
    if(supplier_invoice_create->total_net_amount) {
    if(cJSON_AddStringToObject(item, "totalNetAmount", supplier_invoice_create->total_net_amount) == NULL) {
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

supplier_invoice_create_t *supplier_invoice_create_parseFromJSON(cJSON *supplier_invoice_createJSON){

    supplier_invoice_create_t *supplier_invoice_create_local_var = NULL;

    char *currency_local_str = NULL;

    char *goods_receipt_id_local_str = NULL;

    char *invoice_date_local_str = NULL;

    char *invoice_number_local_str = NULL;

    // define the local variable for supplier_invoice_create->line_items
    _t *line_items_local_nonprim = NULL;

    char *notes_local_str = NULL;

    char *purchase_order_id_local_str = NULL;

    // define the local variable for supplier_invoice_create->status
    supplier_invoice_status_t *status_local_nonprim = NULL;

    char *supplier_contact_id_local_str = NULL;

    char *supplier_name_local_str = NULL;

    char *total_gross_amount_local_str = NULL;

    char *total_net_amount_local_str = NULL;

    // supplier_invoice_create->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(supplier_invoice_createJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // supplier_invoice_create->goods_receipt_id
    cJSON *goods_receipt_id = cJSON_GetObjectItemCaseSensitive(supplier_invoice_createJSON, "goodsReceiptId");
    if (cJSON_IsNull(goods_receipt_id)) {
        goods_receipt_id = NULL;
    }
    if (goods_receipt_id) { 
    if(!cJSON_IsString(goods_receipt_id) && !cJSON_IsNull(goods_receipt_id))
    {
    goto end; //String
    }
    }

    // supplier_invoice_create->invoice_date
    cJSON *invoice_date = cJSON_GetObjectItemCaseSensitive(supplier_invoice_createJSON, "invoiceDate");
    if (cJSON_IsNull(invoice_date)) {
        invoice_date = NULL;
    }
    if (!invoice_date) {
        goto end;
    }

    
    if(!cJSON_IsString(invoice_date))
    {
    goto end; //Date
    }

    // supplier_invoice_create->invoice_number
    cJSON *invoice_number = cJSON_GetObjectItemCaseSensitive(supplier_invoice_createJSON, "invoiceNumber");
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

    // supplier_invoice_create->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(supplier_invoice_createJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (!line_items) {
        goto end;
    }

    
    line_items_local_nonprim = _parseFromJSON(line_items); //custom

    // supplier_invoice_create->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(supplier_invoice_createJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // supplier_invoice_create->purchase_order_id
    cJSON *purchase_order_id = cJSON_GetObjectItemCaseSensitive(supplier_invoice_createJSON, "purchaseOrderId");
    if (cJSON_IsNull(purchase_order_id)) {
        purchase_order_id = NULL;
    }
    if (purchase_order_id) { 
    if(!cJSON_IsString(purchase_order_id) && !cJSON_IsNull(purchase_order_id))
    {
    goto end; //String
    }
    }

    // supplier_invoice_create->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(supplier_invoice_createJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = supplier_invoice_status_parseFromJSON(status); //custom

    // supplier_invoice_create->supplier_contact_id
    cJSON *supplier_contact_id = cJSON_GetObjectItemCaseSensitive(supplier_invoice_createJSON, "supplierContactId");
    if (cJSON_IsNull(supplier_contact_id)) {
        supplier_contact_id = NULL;
    }
    if (supplier_contact_id) { 
    if(!cJSON_IsString(supplier_contact_id) && !cJSON_IsNull(supplier_contact_id))
    {
    goto end; //String
    }
    }

    // supplier_invoice_create->supplier_name
    cJSON *supplier_name = cJSON_GetObjectItemCaseSensitive(supplier_invoice_createJSON, "supplierName");
    if (cJSON_IsNull(supplier_name)) {
        supplier_name = NULL;
    }
    if (supplier_name) { 
    if(!cJSON_IsString(supplier_name) && !cJSON_IsNull(supplier_name))
    {
    goto end; //String
    }
    }

    // supplier_invoice_create->total_gross_amount
    cJSON *total_gross_amount = cJSON_GetObjectItemCaseSensitive(supplier_invoice_createJSON, "totalGrossAmount");
    if (cJSON_IsNull(total_gross_amount)) {
        total_gross_amount = NULL;
    }
    if (total_gross_amount) { 
    if(!cJSON_IsString(total_gross_amount) && !cJSON_IsNull(total_gross_amount))
    {
    goto end; //String
    }
    }

    // supplier_invoice_create->total_net_amount
    cJSON *total_net_amount = cJSON_GetObjectItemCaseSensitive(supplier_invoice_createJSON, "totalNetAmount");
    if (cJSON_IsNull(total_net_amount)) {
        total_net_amount = NULL;
    }
    if (total_net_amount) { 
    if(!cJSON_IsString(total_net_amount) && !cJSON_IsNull(total_net_amount))
    {
    goto end; //String
    }
    }


    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (goods_receipt_id && !cJSON_IsNull(goods_receipt_id)) goods_receipt_id_local_str = strdup(goods_receipt_id->valuestring);
    if (invoice_date) invoice_date_local_str = strdup(invoice_date->valuestring);
    if (invoice_number && !cJSON_IsNull(invoice_number)) invoice_number_local_str = strdup(invoice_number->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (purchase_order_id && !cJSON_IsNull(purchase_order_id)) purchase_order_id_local_str = strdup(purchase_order_id->valuestring);
    if (supplier_contact_id && !cJSON_IsNull(supplier_contact_id)) supplier_contact_id_local_str = strdup(supplier_contact_id->valuestring);
    if (supplier_name && !cJSON_IsNull(supplier_name)) supplier_name_local_str = strdup(supplier_name->valuestring);
    if (total_gross_amount && !cJSON_IsNull(total_gross_amount)) total_gross_amount_local_str = strdup(total_gross_amount->valuestring);
    if (total_net_amount && !cJSON_IsNull(total_net_amount)) total_net_amount_local_str = strdup(total_net_amount->valuestring);

    supplier_invoice_create_local_var = supplier_invoice_create_create_internal (
        currency_local_str,
        goods_receipt_id_local_str,
        invoice_date_local_str,
        invoice_number_local_str,
        line_items_local_nonprim,
        notes_local_str,
        purchase_order_id_local_str,
        status_local_nonprim,
        supplier_contact_id_local_str,
        supplier_name_local_str,
        total_gross_amount_local_str,
        total_net_amount_local_str
        );

    if (!supplier_invoice_create_local_var) {
        goto end;
    }

    return supplier_invoice_create_local_var;
end:
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (goods_receipt_id_local_str) {
        free(goods_receipt_id_local_str);
        goods_receipt_id_local_str = NULL;
    }
    if (invoice_date_local_str) {
        free(invoice_date_local_str);
        invoice_date_local_str = NULL;
    }
    if (invoice_number_local_str) {
        free(invoice_number_local_str);
        invoice_number_local_str = NULL;
    }
    if (line_items_local_nonprim) {
        _free(line_items_local_nonprim);
        line_items_local_nonprim = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (purchase_order_id_local_str) {
        free(purchase_order_id_local_str);
        purchase_order_id_local_str = NULL;
    }
    if (status_local_nonprim) {
        supplier_invoice_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (supplier_contact_id_local_str) {
        free(supplier_contact_id_local_str);
        supplier_contact_id_local_str = NULL;
    }
    if (supplier_name_local_str) {
        free(supplier_name_local_str);
        supplier_name_local_str = NULL;
    }
    if (total_gross_amount_local_str) {
        free(total_gross_amount_local_str);
        total_gross_amount_local_str = NULL;
    }
    if (total_net_amount_local_str) {
        free(total_net_amount_local_str);
        total_net_amount_local_str = NULL;
    }
    return NULL;

}
