#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "purchase_order_update.h"



static purchase_order_update_t *purchase_order_update_create_internal(
    char *currency,
    any_type_t *delivery_address,
    char *expected_delivery_date,
    any_type_t *line_items,
    char *notes,
    char *order_date,
    char *po_number,
    purchase_order_status_t *status,
    char *supplier_contact_id,
    char *supplier_name,
    char *total_gross_amount,
    char *total_net_amount
    ) {
    purchase_order_update_t *purchase_order_update_local_var = malloc(sizeof(purchase_order_update_t));
    if (!purchase_order_update_local_var) {
        return NULL;
    }
    memset(purchase_order_update_local_var, 0, sizeof(purchase_order_update_t));
    purchase_order_update_local_var->_library_owned = 1;
    purchase_order_update_local_var->currency = currency;
    purchase_order_update_local_var->delivery_address = delivery_address;
    purchase_order_update_local_var->expected_delivery_date = expected_delivery_date;
    purchase_order_update_local_var->line_items = line_items;
    purchase_order_update_local_var->notes = notes;
    purchase_order_update_local_var->order_date = order_date;
    purchase_order_update_local_var->po_number = po_number;
    purchase_order_update_local_var->status = status;
    purchase_order_update_local_var->supplier_contact_id = supplier_contact_id;
    purchase_order_update_local_var->supplier_name = supplier_name;
    purchase_order_update_local_var->total_gross_amount = total_gross_amount;
    purchase_order_update_local_var->total_net_amount = total_net_amount;
    return purchase_order_update_local_var;
}

__attribute__((deprecated)) purchase_order_update_t *purchase_order_update_create(
    char *currency,
    any_type_t *delivery_address,
    char *expected_delivery_date,
    any_type_t *line_items,
    char *notes,
    char *order_date,
    char *po_number,
    purchase_order_status_t *status,
    char *supplier_contact_id,
    char *supplier_name,
    char *total_gross_amount,
    char *total_net_amount
    ) {
    purchase_order_update_t *result = purchase_order_update_create_internal (
        currency,
        delivery_address,
        expected_delivery_date,
        line_items,
        notes,
        order_date,
        po_number,
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

void purchase_order_update_free(purchase_order_update_t *purchase_order_update) {
    if(NULL == purchase_order_update){
        return ;
    }
    if(purchase_order_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "purchase_order_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (purchase_order_update->currency) {
        free(purchase_order_update->currency);
        purchase_order_update->currency = NULL;
    }
    if (purchase_order_update->delivery_address) {
        _free(purchase_order_update->delivery_address);
        purchase_order_update->delivery_address = NULL;
    }
    if (purchase_order_update->expected_delivery_date) {
        free(purchase_order_update->expected_delivery_date);
        purchase_order_update->expected_delivery_date = NULL;
    }
    if (purchase_order_update->line_items) {
        _free(purchase_order_update->line_items);
        purchase_order_update->line_items = NULL;
    }
    if (purchase_order_update->notes) {
        free(purchase_order_update->notes);
        purchase_order_update->notes = NULL;
    }
    if (purchase_order_update->order_date) {
        free(purchase_order_update->order_date);
        purchase_order_update->order_date = NULL;
    }
    if (purchase_order_update->po_number) {
        free(purchase_order_update->po_number);
        purchase_order_update->po_number = NULL;
    }
    if (purchase_order_update->status) {
        purchase_order_status_free(purchase_order_update->status);
        purchase_order_update->status = NULL;
    }
    if (purchase_order_update->supplier_contact_id) {
        free(purchase_order_update->supplier_contact_id);
        purchase_order_update->supplier_contact_id = NULL;
    }
    if (purchase_order_update->supplier_name) {
        free(purchase_order_update->supplier_name);
        purchase_order_update->supplier_name = NULL;
    }
    if (purchase_order_update->total_gross_amount) {
        free(purchase_order_update->total_gross_amount);
        purchase_order_update->total_gross_amount = NULL;
    }
    if (purchase_order_update->total_net_amount) {
        free(purchase_order_update->total_net_amount);
        purchase_order_update->total_net_amount = NULL;
    }
    free(purchase_order_update);
}

cJSON *purchase_order_update_convertToJSON(purchase_order_update_t *purchase_order_update) {
    cJSON *item = cJSON_CreateObject();

    // purchase_order_update->currency
    if(purchase_order_update->currency) {
    if(cJSON_AddStringToObject(item, "currency", purchase_order_update->currency) == NULL) {
    goto fail; //String
    }
    }


    // purchase_order_update->delivery_address
    if(purchase_order_update->delivery_address) {
    cJSON *delivery_address_local_JSON = _convertToJSON(purchase_order_update->delivery_address);
    if(delivery_address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "deliveryAddress", delivery_address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // purchase_order_update->expected_delivery_date
    if(purchase_order_update->expected_delivery_date) {
    if(cJSON_AddStringToObject(item, "expectedDeliveryDate", purchase_order_update->expected_delivery_date) == NULL) {
    goto fail; //Date
    }
    }


    // purchase_order_update->line_items
    if(purchase_order_update->line_items) {
    cJSON *line_items_local_JSON = _convertToJSON(purchase_order_update->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // purchase_order_update->notes
    if(purchase_order_update->notes) {
    if(cJSON_AddStringToObject(item, "notes", purchase_order_update->notes) == NULL) {
    goto fail; //String
    }
    }


    // purchase_order_update->order_date
    if(purchase_order_update->order_date) {
    if(cJSON_AddStringToObject(item, "orderDate", purchase_order_update->order_date) == NULL) {
    goto fail; //Date
    }
    }


    // purchase_order_update->po_number
    if(purchase_order_update->po_number) {
    if(cJSON_AddStringToObject(item, "poNumber", purchase_order_update->po_number) == NULL) {
    goto fail; //String
    }
    }


    // purchase_order_update->status
    if(purchase_order_update->status) {
    cJSON *status_local_JSON = purchase_order_status_convertToJSON(purchase_order_update->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // purchase_order_update->supplier_contact_id
    if(purchase_order_update->supplier_contact_id) {
    if(cJSON_AddStringToObject(item, "supplierContactId", purchase_order_update->supplier_contact_id) == NULL) {
    goto fail; //String
    }
    }


    // purchase_order_update->supplier_name
    if(purchase_order_update->supplier_name) {
    if(cJSON_AddStringToObject(item, "supplierName", purchase_order_update->supplier_name) == NULL) {
    goto fail; //String
    }
    }


    // purchase_order_update->total_gross_amount
    if(purchase_order_update->total_gross_amount) {
    if(cJSON_AddStringToObject(item, "totalGrossAmount", purchase_order_update->total_gross_amount) == NULL) {
    goto fail; //String
    }
    }


    // purchase_order_update->total_net_amount
    if(purchase_order_update->total_net_amount) {
    if(cJSON_AddStringToObject(item, "totalNetAmount", purchase_order_update->total_net_amount) == NULL) {
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

purchase_order_update_t *purchase_order_update_parseFromJSON(cJSON *purchase_order_updateJSON){

    purchase_order_update_t *purchase_order_update_local_var = NULL;

    char *currency_local_str = NULL;

    // define the local variable for purchase_order_update->delivery_address
    _t *delivery_address_local_nonprim = NULL;

    char *expected_delivery_date_local_str = NULL;

    // define the local variable for purchase_order_update->line_items
    _t *line_items_local_nonprim = NULL;

    char *notes_local_str = NULL;

    char *order_date_local_str = NULL;

    char *po_number_local_str = NULL;

    // define the local variable for purchase_order_update->status
    purchase_order_status_t *status_local_nonprim = NULL;

    char *supplier_contact_id_local_str = NULL;

    char *supplier_name_local_str = NULL;

    char *total_gross_amount_local_str = NULL;

    char *total_net_amount_local_str = NULL;

    // purchase_order_update->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(purchase_order_updateJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // purchase_order_update->delivery_address
    cJSON *delivery_address = cJSON_GetObjectItemCaseSensitive(purchase_order_updateJSON, "deliveryAddress");
    if (cJSON_IsNull(delivery_address)) {
        delivery_address = NULL;
    }
    if (delivery_address) { 
    delivery_address_local_nonprim = _parseFromJSON(delivery_address); //custom
    }

    // purchase_order_update->expected_delivery_date
    cJSON *expected_delivery_date = cJSON_GetObjectItemCaseSensitive(purchase_order_updateJSON, "expectedDeliveryDate");
    if (cJSON_IsNull(expected_delivery_date)) {
        expected_delivery_date = NULL;
    }
    if (expected_delivery_date) { 
    if(!cJSON_IsString(expected_delivery_date))
    {
    goto end; //Date
    }
    }

    // purchase_order_update->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(purchase_order_updateJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (line_items) { 
    line_items_local_nonprim = _parseFromJSON(line_items); //custom
    }

    // purchase_order_update->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(purchase_order_updateJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // purchase_order_update->order_date
    cJSON *order_date = cJSON_GetObjectItemCaseSensitive(purchase_order_updateJSON, "orderDate");
    if (cJSON_IsNull(order_date)) {
        order_date = NULL;
    }
    if (order_date) { 
    if(!cJSON_IsString(order_date))
    {
    goto end; //Date
    }
    }

    // purchase_order_update->po_number
    cJSON *po_number = cJSON_GetObjectItemCaseSensitive(purchase_order_updateJSON, "poNumber");
    if (cJSON_IsNull(po_number)) {
        po_number = NULL;
    }
    if (po_number) { 
    if(!cJSON_IsString(po_number) && !cJSON_IsNull(po_number))
    {
    goto end; //String
    }
    }

    // purchase_order_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(purchase_order_updateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = purchase_order_status_parseFromJSON(status); //custom
    }

    // purchase_order_update->supplier_contact_id
    cJSON *supplier_contact_id = cJSON_GetObjectItemCaseSensitive(purchase_order_updateJSON, "supplierContactId");
    if (cJSON_IsNull(supplier_contact_id)) {
        supplier_contact_id = NULL;
    }
    if (supplier_contact_id) { 
    if(!cJSON_IsString(supplier_contact_id) && !cJSON_IsNull(supplier_contact_id))
    {
    goto end; //String
    }
    }

    // purchase_order_update->supplier_name
    cJSON *supplier_name = cJSON_GetObjectItemCaseSensitive(purchase_order_updateJSON, "supplierName");
    if (cJSON_IsNull(supplier_name)) {
        supplier_name = NULL;
    }
    if (supplier_name) { 
    if(!cJSON_IsString(supplier_name) && !cJSON_IsNull(supplier_name))
    {
    goto end; //String
    }
    }

    // purchase_order_update->total_gross_amount
    cJSON *total_gross_amount = cJSON_GetObjectItemCaseSensitive(purchase_order_updateJSON, "totalGrossAmount");
    if (cJSON_IsNull(total_gross_amount)) {
        total_gross_amount = NULL;
    }
    if (total_gross_amount) { 
    if(!cJSON_IsString(total_gross_amount) && !cJSON_IsNull(total_gross_amount))
    {
    goto end; //String
    }
    }

    // purchase_order_update->total_net_amount
    cJSON *total_net_amount = cJSON_GetObjectItemCaseSensitive(purchase_order_updateJSON, "totalNetAmount");
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
    if (expected_delivery_date) expected_delivery_date_local_str = strdup(expected_delivery_date->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (order_date) order_date_local_str = strdup(order_date->valuestring);
    if (po_number && !cJSON_IsNull(po_number)) po_number_local_str = strdup(po_number->valuestring);
    if (supplier_contact_id && !cJSON_IsNull(supplier_contact_id)) supplier_contact_id_local_str = strdup(supplier_contact_id->valuestring);
    if (supplier_name && !cJSON_IsNull(supplier_name)) supplier_name_local_str = strdup(supplier_name->valuestring);
    if (total_gross_amount && !cJSON_IsNull(total_gross_amount)) total_gross_amount_local_str = strdup(total_gross_amount->valuestring);
    if (total_net_amount && !cJSON_IsNull(total_net_amount)) total_net_amount_local_str = strdup(total_net_amount->valuestring);

    purchase_order_update_local_var = purchase_order_update_create_internal (
        currency_local_str,
        delivery_address ? delivery_address_local_nonprim : NULL,
        expected_delivery_date_local_str,
        line_items ? line_items_local_nonprim : NULL,
        notes_local_str,
        order_date_local_str,
        po_number_local_str,
        status ? status_local_nonprim : NULL,
        supplier_contact_id_local_str,
        supplier_name_local_str,
        total_gross_amount_local_str,
        total_net_amount_local_str
        );

    if (!purchase_order_update_local_var) {
        goto end;
    }

    return purchase_order_update_local_var;
end:
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (delivery_address_local_nonprim) {
        _free(delivery_address_local_nonprim);
        delivery_address_local_nonprim = NULL;
    }
    if (expected_delivery_date_local_str) {
        free(expected_delivery_date_local_str);
        expected_delivery_date_local_str = NULL;
    }
    if (line_items_local_nonprim) {
        _free(line_items_local_nonprim);
        line_items_local_nonprim = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (order_date_local_str) {
        free(order_date_local_str);
        order_date_local_str = NULL;
    }
    if (po_number_local_str) {
        free(po_number_local_str);
        po_number_local_str = NULL;
    }
    if (status_local_nonprim) {
        purchase_order_status_free(status_local_nonprim);
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
