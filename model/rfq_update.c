#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rfq_update.h"



static rfq_update_t *rfq_update_create_internal(
    char *currency,
    any_type_t *line_items,
    char *notes,
    char *requested_date,
    char *response_date,
    char *rfq_number,
    rfq_status_t *status,
    char *supplier_contact_id,
    char *supplier_name
    ) {
    rfq_update_t *rfq_update_local_var = malloc(sizeof(rfq_update_t));
    if (!rfq_update_local_var) {
        return NULL;
    }
    memset(rfq_update_local_var, 0, sizeof(rfq_update_t));
    rfq_update_local_var->_library_owned = 1;
    rfq_update_local_var->currency = currency;
    rfq_update_local_var->line_items = line_items;
    rfq_update_local_var->notes = notes;
    rfq_update_local_var->requested_date = requested_date;
    rfq_update_local_var->response_date = response_date;
    rfq_update_local_var->rfq_number = rfq_number;
    rfq_update_local_var->status = status;
    rfq_update_local_var->supplier_contact_id = supplier_contact_id;
    rfq_update_local_var->supplier_name = supplier_name;
    return rfq_update_local_var;
}

__attribute__((deprecated)) rfq_update_t *rfq_update_create(
    char *currency,
    any_type_t *line_items,
    char *notes,
    char *requested_date,
    char *response_date,
    char *rfq_number,
    rfq_status_t *status,
    char *supplier_contact_id,
    char *supplier_name
    ) {
    rfq_update_t *result = rfq_update_create_internal (
        currency,
        line_items,
        notes,
        requested_date,
        response_date,
        rfq_number,
        status,
        supplier_contact_id,
        supplier_name
        );
    if (!result) {
    }
    return result;
}

void rfq_update_free(rfq_update_t *rfq_update) {
    if(NULL == rfq_update){
        return ;
    }
    if(rfq_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "rfq_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (rfq_update->currency) {
        free(rfq_update->currency);
        rfq_update->currency = NULL;
    }
    if (rfq_update->line_items) {
        _free(rfq_update->line_items);
        rfq_update->line_items = NULL;
    }
    if (rfq_update->notes) {
        free(rfq_update->notes);
        rfq_update->notes = NULL;
    }
    if (rfq_update->requested_date) {
        free(rfq_update->requested_date);
        rfq_update->requested_date = NULL;
    }
    if (rfq_update->response_date) {
        free(rfq_update->response_date);
        rfq_update->response_date = NULL;
    }
    if (rfq_update->rfq_number) {
        free(rfq_update->rfq_number);
        rfq_update->rfq_number = NULL;
    }
    if (rfq_update->status) {
        rfq_status_free(rfq_update->status);
        rfq_update->status = NULL;
    }
    if (rfq_update->supplier_contact_id) {
        free(rfq_update->supplier_contact_id);
        rfq_update->supplier_contact_id = NULL;
    }
    if (rfq_update->supplier_name) {
        free(rfq_update->supplier_name);
        rfq_update->supplier_name = NULL;
    }
    free(rfq_update);
}

cJSON *rfq_update_convertToJSON(rfq_update_t *rfq_update) {
    cJSON *item = cJSON_CreateObject();

    // rfq_update->currency
    if(rfq_update->currency) {
    if(cJSON_AddStringToObject(item, "currency", rfq_update->currency) == NULL) {
    goto fail; //String
    }
    }


    // rfq_update->line_items
    if(rfq_update->line_items) {
    cJSON *line_items_local_JSON = _convertToJSON(rfq_update->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // rfq_update->notes
    if(rfq_update->notes) {
    if(cJSON_AddStringToObject(item, "notes", rfq_update->notes) == NULL) {
    goto fail; //String
    }
    }


    // rfq_update->requested_date
    if(rfq_update->requested_date) {
    if(cJSON_AddStringToObject(item, "requestedDate", rfq_update->requested_date) == NULL) {
    goto fail; //Date
    }
    }


    // rfq_update->response_date
    if(rfq_update->response_date) {
    if(cJSON_AddStringToObject(item, "responseDate", rfq_update->response_date) == NULL) {
    goto fail; //Date
    }
    }


    // rfq_update->rfq_number
    if(rfq_update->rfq_number) {
    if(cJSON_AddStringToObject(item, "rfqNumber", rfq_update->rfq_number) == NULL) {
    goto fail; //String
    }
    }


    // rfq_update->status
    if(rfq_update->status) {
    cJSON *status_local_JSON = rfq_status_convertToJSON(rfq_update->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // rfq_update->supplier_contact_id
    if(rfq_update->supplier_contact_id) {
    if(cJSON_AddStringToObject(item, "supplierContactId", rfq_update->supplier_contact_id) == NULL) {
    goto fail; //String
    }
    }


    // rfq_update->supplier_name
    if(rfq_update->supplier_name) {
    if(cJSON_AddStringToObject(item, "supplierName", rfq_update->supplier_name) == NULL) {
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

rfq_update_t *rfq_update_parseFromJSON(cJSON *rfq_updateJSON){

    rfq_update_t *rfq_update_local_var = NULL;

    char *currency_local_str = NULL;

    // define the local variable for rfq_update->line_items
    _t *line_items_local_nonprim = NULL;

    char *notes_local_str = NULL;

    char *requested_date_local_str = NULL;

    char *response_date_local_str = NULL;

    char *rfq_number_local_str = NULL;

    // define the local variable for rfq_update->status
    rfq_status_t *status_local_nonprim = NULL;

    char *supplier_contact_id_local_str = NULL;

    char *supplier_name_local_str = NULL;

    // rfq_update->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(rfq_updateJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // rfq_update->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(rfq_updateJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (line_items) { 
    line_items_local_nonprim = _parseFromJSON(line_items); //custom
    }

    // rfq_update->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(rfq_updateJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // rfq_update->requested_date
    cJSON *requested_date = cJSON_GetObjectItemCaseSensitive(rfq_updateJSON, "requestedDate");
    if (cJSON_IsNull(requested_date)) {
        requested_date = NULL;
    }
    if (requested_date) { 
    if(!cJSON_IsString(requested_date))
    {
    goto end; //Date
    }
    }

    // rfq_update->response_date
    cJSON *response_date = cJSON_GetObjectItemCaseSensitive(rfq_updateJSON, "responseDate");
    if (cJSON_IsNull(response_date)) {
        response_date = NULL;
    }
    if (response_date) { 
    if(!cJSON_IsString(response_date))
    {
    goto end; //Date
    }
    }

    // rfq_update->rfq_number
    cJSON *rfq_number = cJSON_GetObjectItemCaseSensitive(rfq_updateJSON, "rfqNumber");
    if (cJSON_IsNull(rfq_number)) {
        rfq_number = NULL;
    }
    if (rfq_number) { 
    if(!cJSON_IsString(rfq_number) && !cJSON_IsNull(rfq_number))
    {
    goto end; //String
    }
    }

    // rfq_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(rfq_updateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = rfq_status_parseFromJSON(status); //custom
    }

    // rfq_update->supplier_contact_id
    cJSON *supplier_contact_id = cJSON_GetObjectItemCaseSensitive(rfq_updateJSON, "supplierContactId");
    if (cJSON_IsNull(supplier_contact_id)) {
        supplier_contact_id = NULL;
    }
    if (supplier_contact_id) { 
    if(!cJSON_IsString(supplier_contact_id) && !cJSON_IsNull(supplier_contact_id))
    {
    goto end; //String
    }
    }

    // rfq_update->supplier_name
    cJSON *supplier_name = cJSON_GetObjectItemCaseSensitive(rfq_updateJSON, "supplierName");
    if (cJSON_IsNull(supplier_name)) {
        supplier_name = NULL;
    }
    if (supplier_name) { 
    if(!cJSON_IsString(supplier_name) && !cJSON_IsNull(supplier_name))
    {
    goto end; //String
    }
    }


    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (requested_date) requested_date_local_str = strdup(requested_date->valuestring);
    if (response_date) response_date_local_str = strdup(response_date->valuestring);
    if (rfq_number && !cJSON_IsNull(rfq_number)) rfq_number_local_str = strdup(rfq_number->valuestring);
    if (supplier_contact_id && !cJSON_IsNull(supplier_contact_id)) supplier_contact_id_local_str = strdup(supplier_contact_id->valuestring);
    if (supplier_name && !cJSON_IsNull(supplier_name)) supplier_name_local_str = strdup(supplier_name->valuestring);

    rfq_update_local_var = rfq_update_create_internal (
        currency_local_str,
        line_items ? line_items_local_nonprim : NULL,
        notes_local_str,
        requested_date_local_str,
        response_date_local_str,
        rfq_number_local_str,
        status ? status_local_nonprim : NULL,
        supplier_contact_id_local_str,
        supplier_name_local_str
        );

    if (!rfq_update_local_var) {
        goto end;
    }

    return rfq_update_local_var;
end:
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (line_items_local_nonprim) {
        _free(line_items_local_nonprim);
        line_items_local_nonprim = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (requested_date_local_str) {
        free(requested_date_local_str);
        requested_date_local_str = NULL;
    }
    if (response_date_local_str) {
        free(response_date_local_str);
        response_date_local_str = NULL;
    }
    if (rfq_number_local_str) {
        free(rfq_number_local_str);
        rfq_number_local_str = NULL;
    }
    if (status_local_nonprim) {
        rfq_status_free(status_local_nonprim);
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
    return NULL;

}
