#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "goods_receipt.h"



static goods_receipt_t *goods_receipt_create_internal(
    char *gr_number,
    any_type_t *line_items,
    char *notes,
    char *purchase_order_id,
    char *receipt_date,
    char *supplier_contact_id,
    char *supplier_name,
    char *warehouse_id
    ) {
    goods_receipt_t *goods_receipt_local_var = malloc(sizeof(goods_receipt_t));
    if (!goods_receipt_local_var) {
        return NULL;
    }
    memset(goods_receipt_local_var, 0, sizeof(goods_receipt_t));
    goods_receipt_local_var->_library_owned = 1;
    goods_receipt_local_var->gr_number = gr_number;
    goods_receipt_local_var->line_items = line_items;
    goods_receipt_local_var->notes = notes;
    goods_receipt_local_var->purchase_order_id = purchase_order_id;
    goods_receipt_local_var->receipt_date = receipt_date;
    goods_receipt_local_var->supplier_contact_id = supplier_contact_id;
    goods_receipt_local_var->supplier_name = supplier_name;
    goods_receipt_local_var->warehouse_id = warehouse_id;
    return goods_receipt_local_var;
}

__attribute__((deprecated)) goods_receipt_t *goods_receipt_create(
    char *gr_number,
    any_type_t *line_items,
    char *notes,
    char *purchase_order_id,
    char *receipt_date,
    char *supplier_contact_id,
    char *supplier_name,
    char *warehouse_id
    ) {
    goods_receipt_t *result = goods_receipt_create_internal (
        gr_number,
        line_items,
        notes,
        purchase_order_id,
        receipt_date,
        supplier_contact_id,
        supplier_name,
        warehouse_id
        );
    if (!result) {
    }
    return result;
}

void goods_receipt_free(goods_receipt_t *goods_receipt) {
    if(NULL == goods_receipt){
        return ;
    }
    if(goods_receipt->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "goods_receipt_free");
        return ;
    }
    listEntry_t *listEntry;
    if (goods_receipt->gr_number) {
        free(goods_receipt->gr_number);
        goods_receipt->gr_number = NULL;
    }
    if (goods_receipt->line_items) {
        _free(goods_receipt->line_items);
        goods_receipt->line_items = NULL;
    }
    if (goods_receipt->notes) {
        free(goods_receipt->notes);
        goods_receipt->notes = NULL;
    }
    if (goods_receipt->purchase_order_id) {
        free(goods_receipt->purchase_order_id);
        goods_receipt->purchase_order_id = NULL;
    }
    if (goods_receipt->receipt_date) {
        free(goods_receipt->receipt_date);
        goods_receipt->receipt_date = NULL;
    }
    if (goods_receipt->supplier_contact_id) {
        free(goods_receipt->supplier_contact_id);
        goods_receipt->supplier_contact_id = NULL;
    }
    if (goods_receipt->supplier_name) {
        free(goods_receipt->supplier_name);
        goods_receipt->supplier_name = NULL;
    }
    if (goods_receipt->warehouse_id) {
        free(goods_receipt->warehouse_id);
        goods_receipt->warehouse_id = NULL;
    }
    free(goods_receipt);
}

cJSON *goods_receipt_convertToJSON(goods_receipt_t *goods_receipt) {
    cJSON *item = cJSON_CreateObject();

    // goods_receipt->gr_number
    if (!goods_receipt->gr_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "grNumber", goods_receipt->gr_number) == NULL) {
    goto fail; //String
    }


    // goods_receipt->line_items
    if (!goods_receipt->line_items) {
        goto fail;
    }
    cJSON *line_items_local_JSON = _convertToJSON(goods_receipt->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // goods_receipt->notes
    if(goods_receipt->notes) {
    if(cJSON_AddStringToObject(item, "notes", goods_receipt->notes) == NULL) {
    goto fail; //String
    }
    }


    // goods_receipt->purchase_order_id
    if(goods_receipt->purchase_order_id) {
    if(cJSON_AddStringToObject(item, "purchaseOrderId", goods_receipt->purchase_order_id) == NULL) {
    goto fail; //String
    }
    }


    // goods_receipt->receipt_date
    if (!goods_receipt->receipt_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "receiptDate", goods_receipt->receipt_date) == NULL) {
    goto fail; //Date
    }


    // goods_receipt->supplier_contact_id
    if(goods_receipt->supplier_contact_id) {
    if(cJSON_AddStringToObject(item, "supplierContactId", goods_receipt->supplier_contact_id) == NULL) {
    goto fail; //String
    }
    }


    // goods_receipt->supplier_name
    if(goods_receipt->supplier_name) {
    if(cJSON_AddStringToObject(item, "supplierName", goods_receipt->supplier_name) == NULL) {
    goto fail; //String
    }
    }


    // goods_receipt->warehouse_id
    if (!goods_receipt->warehouse_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "warehouseId", goods_receipt->warehouse_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

goods_receipt_t *goods_receipt_parseFromJSON(cJSON *goods_receiptJSON){

    goods_receipt_t *goods_receipt_local_var = NULL;

    char *gr_number_local_str = NULL;

    // define the local variable for goods_receipt->line_items
    _t *line_items_local_nonprim = NULL;

    char *notes_local_str = NULL;

    char *purchase_order_id_local_str = NULL;

    char *receipt_date_local_str = NULL;

    char *supplier_contact_id_local_str = NULL;

    char *supplier_name_local_str = NULL;

    char *warehouse_id_local_str = NULL;

    // goods_receipt->gr_number
    cJSON *gr_number = cJSON_GetObjectItemCaseSensitive(goods_receiptJSON, "grNumber");
    if (cJSON_IsNull(gr_number)) {
        gr_number = NULL;
    }
    if (!gr_number) {
        goto end;
    }

    
    if(!cJSON_IsString(gr_number))
    {
    goto end; //String
    }

    // goods_receipt->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(goods_receiptJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (!line_items) {
        goto end;
    }

    
    line_items_local_nonprim = _parseFromJSON(line_items); //custom

    // goods_receipt->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(goods_receiptJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // goods_receipt->purchase_order_id
    cJSON *purchase_order_id = cJSON_GetObjectItemCaseSensitive(goods_receiptJSON, "purchaseOrderId");
    if (cJSON_IsNull(purchase_order_id)) {
        purchase_order_id = NULL;
    }
    if (purchase_order_id) { 
    if(!cJSON_IsString(purchase_order_id) && !cJSON_IsNull(purchase_order_id))
    {
    goto end; //String
    }
    }

    // goods_receipt->receipt_date
    cJSON *receipt_date = cJSON_GetObjectItemCaseSensitive(goods_receiptJSON, "receiptDate");
    if (cJSON_IsNull(receipt_date)) {
        receipt_date = NULL;
    }
    if (!receipt_date) {
        goto end;
    }

    
    if(!cJSON_IsString(receipt_date))
    {
    goto end; //Date
    }

    // goods_receipt->supplier_contact_id
    cJSON *supplier_contact_id = cJSON_GetObjectItemCaseSensitive(goods_receiptJSON, "supplierContactId");
    if (cJSON_IsNull(supplier_contact_id)) {
        supplier_contact_id = NULL;
    }
    if (supplier_contact_id) { 
    if(!cJSON_IsString(supplier_contact_id) && !cJSON_IsNull(supplier_contact_id))
    {
    goto end; //String
    }
    }

    // goods_receipt->supplier_name
    cJSON *supplier_name = cJSON_GetObjectItemCaseSensitive(goods_receiptJSON, "supplierName");
    if (cJSON_IsNull(supplier_name)) {
        supplier_name = NULL;
    }
    if (supplier_name) { 
    if(!cJSON_IsString(supplier_name) && !cJSON_IsNull(supplier_name))
    {
    goto end; //String
    }
    }

    // goods_receipt->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(goods_receiptJSON, "warehouseId");
    if (cJSON_IsNull(warehouse_id)) {
        warehouse_id = NULL;
    }
    if (!warehouse_id) {
        goto end;
    }

    
    if(!cJSON_IsString(warehouse_id))
    {
    goto end; //String
    }


    if (gr_number && !cJSON_IsNull(gr_number)) gr_number_local_str = strdup(gr_number->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (purchase_order_id && !cJSON_IsNull(purchase_order_id)) purchase_order_id_local_str = strdup(purchase_order_id->valuestring);
    if (receipt_date) receipt_date_local_str = strdup(receipt_date->valuestring);
    if (supplier_contact_id && !cJSON_IsNull(supplier_contact_id)) supplier_contact_id_local_str = strdup(supplier_contact_id->valuestring);
    if (supplier_name && !cJSON_IsNull(supplier_name)) supplier_name_local_str = strdup(supplier_name->valuestring);
    if (warehouse_id && !cJSON_IsNull(warehouse_id)) warehouse_id_local_str = strdup(warehouse_id->valuestring);

    goods_receipt_local_var = goods_receipt_create_internal (
        gr_number_local_str,
        line_items_local_nonprim,
        notes_local_str,
        purchase_order_id_local_str,
        receipt_date_local_str,
        supplier_contact_id_local_str,
        supplier_name_local_str,
        warehouse_id_local_str
        );

    if (!goods_receipt_local_var) {
        goto end;
    }

    return goods_receipt_local_var;
end:
    if (gr_number_local_str) {
        free(gr_number_local_str);
        gr_number_local_str = NULL;
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
    if (receipt_date_local_str) {
        free(receipt_date_local_str);
        receipt_date_local_str = NULL;
    }
    if (supplier_contact_id_local_str) {
        free(supplier_contact_id_local_str);
        supplier_contact_id_local_str = NULL;
    }
    if (supplier_name_local_str) {
        free(supplier_name_local_str);
        supplier_name_local_str = NULL;
    }
    if (warehouse_id_local_str) {
        free(warehouse_id_local_str);
        warehouse_id_local_str = NULL;
    }
    return NULL;

}
