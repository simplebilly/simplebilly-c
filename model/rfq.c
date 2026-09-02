#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rfq.h"



static rfq_t *rfq_create_internal(
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
    rfq_t *rfq_local_var = malloc(sizeof(rfq_t));
    if (!rfq_local_var) {
        return NULL;
    }
    memset(rfq_local_var, 0, sizeof(rfq_t));
    rfq_local_var->_library_owned = 1;
    rfq_local_var->currency = currency;
    rfq_local_var->line_items = line_items;
    rfq_local_var->notes = notes;
    rfq_local_var->requested_date = requested_date;
    rfq_local_var->response_date = response_date;
    rfq_local_var->rfq_number = rfq_number;
    rfq_local_var->status = status;
    rfq_local_var->supplier_contact_id = supplier_contact_id;
    rfq_local_var->supplier_name = supplier_name;
    return rfq_local_var;
}

__attribute__((deprecated)) rfq_t *rfq_create(
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
    rfq_t *result = rfq_create_internal (
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

void rfq_free(rfq_t *rfq) {
    if(NULL == rfq){
        return ;
    }
    if(rfq->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "rfq_free");
        return ;
    }
    listEntry_t *listEntry;
    if (rfq->currency) {
        free(rfq->currency);
        rfq->currency = NULL;
    }
    if (rfq->line_items) {
        _free(rfq->line_items);
        rfq->line_items = NULL;
    }
    if (rfq->notes) {
        free(rfq->notes);
        rfq->notes = NULL;
    }
    if (rfq->requested_date) {
        free(rfq->requested_date);
        rfq->requested_date = NULL;
    }
    if (rfq->response_date) {
        free(rfq->response_date);
        rfq->response_date = NULL;
    }
    if (rfq->rfq_number) {
        free(rfq->rfq_number);
        rfq->rfq_number = NULL;
    }
    if (rfq->status) {
        rfq_status_free(rfq->status);
        rfq->status = NULL;
    }
    if (rfq->supplier_contact_id) {
        free(rfq->supplier_contact_id);
        rfq->supplier_contact_id = NULL;
    }
    if (rfq->supplier_name) {
        free(rfq->supplier_name);
        rfq->supplier_name = NULL;
    }
    free(rfq);
}

cJSON *rfq_convertToJSON(rfq_t *rfq) {
    cJSON *item = cJSON_CreateObject();

    // rfq->currency
    if(rfq->currency) {
    if(cJSON_AddStringToObject(item, "currency", rfq->currency) == NULL) {
    goto fail; //String
    }
    }


    // rfq->line_items
    if (!rfq->line_items) {
        goto fail;
    }
    cJSON *line_items_local_JSON = _convertToJSON(rfq->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // rfq->notes
    if(rfq->notes) {
    if(cJSON_AddStringToObject(item, "notes", rfq->notes) == NULL) {
    goto fail; //String
    }
    }


    // rfq->requested_date
    if (!rfq->requested_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "requestedDate", rfq->requested_date) == NULL) {
    goto fail; //Date
    }


    // rfq->response_date
    if(rfq->response_date) {
    if(cJSON_AddStringToObject(item, "responseDate", rfq->response_date) == NULL) {
    goto fail; //Date
    }
    }


    // rfq->rfq_number
    if (!rfq->rfq_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "rfqNumber", rfq->rfq_number) == NULL) {
    goto fail; //String
    }


    // rfq->status
    if (!rfq->status) {
        goto fail;
    }
    cJSON *status_local_JSON = rfq_status_convertToJSON(rfq->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // rfq->supplier_contact_id
    if(rfq->supplier_contact_id) {
    if(cJSON_AddStringToObject(item, "supplierContactId", rfq->supplier_contact_id) == NULL) {
    goto fail; //String
    }
    }


    // rfq->supplier_name
    if(rfq->supplier_name) {
    if(cJSON_AddStringToObject(item, "supplierName", rfq->supplier_name) == NULL) {
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

rfq_t *rfq_parseFromJSON(cJSON *rfqJSON){

    rfq_t *rfq_local_var = NULL;

    char *currency_local_str = NULL;

    // define the local variable for rfq->line_items
    _t *line_items_local_nonprim = NULL;

    char *notes_local_str = NULL;

    char *requested_date_local_str = NULL;

    char *response_date_local_str = NULL;

    char *rfq_number_local_str = NULL;

    // define the local variable for rfq->status
    rfq_status_t *status_local_nonprim = NULL;

    char *supplier_contact_id_local_str = NULL;

    char *supplier_name_local_str = NULL;

    // rfq->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(rfqJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // rfq->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(rfqJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (!line_items) {
        goto end;
    }

    
    line_items_local_nonprim = _parseFromJSON(line_items); //custom

    // rfq->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(rfqJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // rfq->requested_date
    cJSON *requested_date = cJSON_GetObjectItemCaseSensitive(rfqJSON, "requestedDate");
    if (cJSON_IsNull(requested_date)) {
        requested_date = NULL;
    }
    if (!requested_date) {
        goto end;
    }

    
    if(!cJSON_IsString(requested_date))
    {
    goto end; //Date
    }

    // rfq->response_date
    cJSON *response_date = cJSON_GetObjectItemCaseSensitive(rfqJSON, "responseDate");
    if (cJSON_IsNull(response_date)) {
        response_date = NULL;
    }
    if (response_date) { 
    if(!cJSON_IsString(response_date))
    {
    goto end; //Date
    }
    }

    // rfq->rfq_number
    cJSON *rfq_number = cJSON_GetObjectItemCaseSensitive(rfqJSON, "rfqNumber");
    if (cJSON_IsNull(rfq_number)) {
        rfq_number = NULL;
    }
    if (!rfq_number) {
        goto end;
    }

    
    if(!cJSON_IsString(rfq_number))
    {
    goto end; //String
    }

    // rfq->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(rfqJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = rfq_status_parseFromJSON(status); //custom

    // rfq->supplier_contact_id
    cJSON *supplier_contact_id = cJSON_GetObjectItemCaseSensitive(rfqJSON, "supplierContactId");
    if (cJSON_IsNull(supplier_contact_id)) {
        supplier_contact_id = NULL;
    }
    if (supplier_contact_id) { 
    if(!cJSON_IsString(supplier_contact_id) && !cJSON_IsNull(supplier_contact_id))
    {
    goto end; //String
    }
    }

    // rfq->supplier_name
    cJSON *supplier_name = cJSON_GetObjectItemCaseSensitive(rfqJSON, "supplierName");
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

    rfq_local_var = rfq_create_internal (
        currency_local_str,
        line_items_local_nonprim,
        notes_local_str,
        requested_date_local_str,
        response_date_local_str,
        rfq_number_local_str,
        status_local_nonprim,
        supplier_contact_id_local_str,
        supplier_name_local_str
        );

    if (!rfq_local_var) {
        goto end;
    }

    return rfq_local_var;
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
