#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shipment.h"



static shipment_t *shipment_create_internal(
    char *delivered_at,
    char *label_url,
    any_type_t *line_items_shipment,
    char *order_id,
    any_type_t *recipient_address,
    char *shipment_date,
    char *shipping_carrier,
    char *shipping_cost,
    char *shipping_method,
    char *signed_by,
    char *status,
    any_type_t *tracking_events,
    char *tracking_number,
    char *tracking_url,
    double *weight_kg
    ) {
    shipment_t *shipment_local_var = malloc(sizeof(shipment_t));
    if (!shipment_local_var) {
        return NULL;
    }
    memset(shipment_local_var, 0, sizeof(shipment_t));
    shipment_local_var->_library_owned = 1;
    shipment_local_var->delivered_at = delivered_at;
    shipment_local_var->label_url = label_url;
    shipment_local_var->line_items_shipment = line_items_shipment;
    shipment_local_var->order_id = order_id;
    shipment_local_var->recipient_address = recipient_address;
    shipment_local_var->shipment_date = shipment_date;
    shipment_local_var->shipping_carrier = shipping_carrier;
    shipment_local_var->shipping_cost = shipping_cost;
    shipment_local_var->shipping_method = shipping_method;
    shipment_local_var->signed_by = signed_by;
    shipment_local_var->status = status;
    shipment_local_var->tracking_events = tracking_events;
    shipment_local_var->tracking_number = tracking_number;
    shipment_local_var->tracking_url = tracking_url;
    shipment_local_var->weight_kg = weight_kg;
    return shipment_local_var;
}

__attribute__((deprecated)) shipment_t *shipment_create(
    char *delivered_at,
    char *label_url,
    any_type_t *line_items_shipment,
    char *order_id,
    any_type_t *recipient_address,
    char *shipment_date,
    char *shipping_carrier,
    char *shipping_cost,
    char *shipping_method,
    char *signed_by,
    char *status,
    any_type_t *tracking_events,
    char *tracking_number,
    char *tracking_url,
    double *weight_kg
    ) {
    double *weight_kg_copy = NULL;
    if (weight_kg) {
        weight_kg_copy = malloc(sizeof(double));
        if (weight_kg_copy) *weight_kg_copy = *weight_kg;
    }
    shipment_t *result = shipment_create_internal (
        delivered_at,
        label_url,
        line_items_shipment,
        order_id,
        recipient_address,
        shipment_date,
        shipping_carrier,
        shipping_cost,
        shipping_method,
        signed_by,
        status,
        tracking_events,
        tracking_number,
        tracking_url,
        weight_kg_copy
        );
    if (!result) {
        free(weight_kg_copy);
    }
    return result;
}

void shipment_free(shipment_t *shipment) {
    if(NULL == shipment){
        return ;
    }
    if(shipment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shipment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shipment->delivered_at) {
        free(shipment->delivered_at);
        shipment->delivered_at = NULL;
    }
    if (shipment->label_url) {
        free(shipment->label_url);
        shipment->label_url = NULL;
    }
    if (shipment->line_items_shipment) {
        _free(shipment->line_items_shipment);
        shipment->line_items_shipment = NULL;
    }
    if (shipment->order_id) {
        free(shipment->order_id);
        shipment->order_id = NULL;
    }
    if (shipment->recipient_address) {
        _free(shipment->recipient_address);
        shipment->recipient_address = NULL;
    }
    if (shipment->shipment_date) {
        free(shipment->shipment_date);
        shipment->shipment_date = NULL;
    }
    if (shipment->shipping_carrier) {
        free(shipment->shipping_carrier);
        shipment->shipping_carrier = NULL;
    }
    if (shipment->shipping_cost) {
        free(shipment->shipping_cost);
        shipment->shipping_cost = NULL;
    }
    if (shipment->shipping_method) {
        free(shipment->shipping_method);
        shipment->shipping_method = NULL;
    }
    if (shipment->signed_by) {
        free(shipment->signed_by);
        shipment->signed_by = NULL;
    }
    if (shipment->status) {
        free(shipment->status);
        shipment->status = NULL;
    }
    if (shipment->tracking_events) {
        _free(shipment->tracking_events);
        shipment->tracking_events = NULL;
    }
    if (shipment->tracking_number) {
        free(shipment->tracking_number);
        shipment->tracking_number = NULL;
    }
    if (shipment->tracking_url) {
        free(shipment->tracking_url);
        shipment->tracking_url = NULL;
    }
    if (shipment->weight_kg) {
        free(shipment->weight_kg);
        shipment->weight_kg = NULL;
    }
    free(shipment);
}

cJSON *shipment_convertToJSON(shipment_t *shipment) {
    cJSON *item = cJSON_CreateObject();

    // shipment->delivered_at
    if(shipment->delivered_at) {
    if(cJSON_AddStringToObject(item, "deliveredAt", shipment->delivered_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // shipment->label_url
    if(shipment->label_url) {
    if(cJSON_AddStringToObject(item, "labelUrl", shipment->label_url) == NULL) {
    goto fail; //String
    }
    }


    // shipment->line_items_shipment
    if(shipment->line_items_shipment) {
    cJSON *line_items_shipment_local_JSON = _convertToJSON(shipment->line_items_shipment);
    if(line_items_shipment_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItemsShipment", line_items_shipment_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // shipment->order_id
    if (!shipment->order_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "orderId", shipment->order_id) == NULL) {
    goto fail; //String
    }


    // shipment->recipient_address
    if(shipment->recipient_address) {
    cJSON *recipient_address_local_JSON = _convertToJSON(shipment->recipient_address);
    if(recipient_address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "recipientAddress", recipient_address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // shipment->shipment_date
    if (!shipment->shipment_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "shipmentDate", shipment->shipment_date) == NULL) {
    goto fail; //Date
    }


    // shipment->shipping_carrier
    if (!shipment->shipping_carrier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "shippingCarrier", shipment->shipping_carrier) == NULL) {
    goto fail; //String
    }


    // shipment->shipping_cost
    if(shipment->shipping_cost) {
    if(cJSON_AddStringToObject(item, "shippingCost", shipment->shipping_cost) == NULL) {
    goto fail; //String
    }
    }


    // shipment->shipping_method
    if(shipment->shipping_method) {
    if(cJSON_AddStringToObject(item, "shippingMethod", shipment->shipping_method) == NULL) {
    goto fail; //String
    }
    }


    // shipment->signed_by
    if(shipment->signed_by) {
    if(cJSON_AddStringToObject(item, "signedBy", shipment->signed_by) == NULL) {
    goto fail; //String
    }
    }


    // shipment->status
    if (!shipment->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", shipment->status) == NULL) {
    goto fail; //String
    }


    // shipment->tracking_events
    if(shipment->tracking_events) {
    cJSON *tracking_events_local_JSON = _convertToJSON(shipment->tracking_events);
    if(tracking_events_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "trackingEvents", tracking_events_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // shipment->tracking_number
    if(shipment->tracking_number) {
    if(cJSON_AddStringToObject(item, "trackingNumber", shipment->tracking_number) == NULL) {
    goto fail; //String
    }
    }


    // shipment->tracking_url
    if(shipment->tracking_url) {
    if(cJSON_AddStringToObject(item, "trackingUrl", shipment->tracking_url) == NULL) {
    goto fail; //String
    }
    }


    // shipment->weight_kg
    if(shipment->weight_kg) {
    if(cJSON_AddNumberToObject(item, "weightKg", *shipment->weight_kg) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

shipment_t *shipment_parseFromJSON(cJSON *shipmentJSON){

    shipment_t *shipment_local_var = NULL;

    char *delivered_at_local_str = NULL;

    char *label_url_local_str = NULL;

    // define the local variable for shipment->line_items_shipment
    _t *line_items_shipment_local_nonprim = NULL;

    char *order_id_local_str = NULL;

    // define the local variable for shipment->recipient_address
    _t *recipient_address_local_nonprim = NULL;

    char *shipment_date_local_str = NULL;

    char *shipping_carrier_local_str = NULL;

    char *shipping_cost_local_str = NULL;

    char *shipping_method_local_str = NULL;

    char *signed_by_local_str = NULL;

    char *status_local_str = NULL;

    // define the local variable for shipment->tracking_events
    _t *tracking_events_local_nonprim = NULL;

    char *tracking_number_local_str = NULL;

    char *tracking_url_local_str = NULL;

    // define the local variable for shipment->weight_kg
    double *weight_kg_local_var = NULL;

    // shipment->delivered_at
    cJSON *delivered_at = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "deliveredAt");
    if (cJSON_IsNull(delivered_at)) {
        delivered_at = NULL;
    }
    if (delivered_at) { 
    if(!cJSON_IsString(delivered_at) && !cJSON_IsNull(delivered_at))
    {
    goto end; //DateTime
    }
    }

    // shipment->label_url
    cJSON *label_url = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "labelUrl");
    if (cJSON_IsNull(label_url)) {
        label_url = NULL;
    }
    if (label_url) { 
    if(!cJSON_IsString(label_url) && !cJSON_IsNull(label_url))
    {
    goto end; //String
    }
    }

    // shipment->line_items_shipment
    cJSON *line_items_shipment = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "lineItemsShipment");
    if (cJSON_IsNull(line_items_shipment)) {
        line_items_shipment = NULL;
    }
    if (line_items_shipment) { 
    line_items_shipment_local_nonprim = _parseFromJSON(line_items_shipment); //custom
    }

    // shipment->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "orderId");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (!order_id) {
        goto end;
    }

    
    if(!cJSON_IsString(order_id))
    {
    goto end; //String
    }

    // shipment->recipient_address
    cJSON *recipient_address = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "recipientAddress");
    if (cJSON_IsNull(recipient_address)) {
        recipient_address = NULL;
    }
    if (recipient_address) { 
    recipient_address_local_nonprim = _parseFromJSON(recipient_address); //custom
    }

    // shipment->shipment_date
    cJSON *shipment_date = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "shipmentDate");
    if (cJSON_IsNull(shipment_date)) {
        shipment_date = NULL;
    }
    if (!shipment_date) {
        goto end;
    }

    
    if(!cJSON_IsString(shipment_date))
    {
    goto end; //Date
    }

    // shipment->shipping_carrier
    cJSON *shipping_carrier = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "shippingCarrier");
    if (cJSON_IsNull(shipping_carrier)) {
        shipping_carrier = NULL;
    }
    if (!shipping_carrier) {
        goto end;
    }

    
    if(!cJSON_IsString(shipping_carrier))
    {
    goto end; //String
    }

    // shipment->shipping_cost
    cJSON *shipping_cost = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "shippingCost");
    if (cJSON_IsNull(shipping_cost)) {
        shipping_cost = NULL;
    }
    if (shipping_cost) { 
    if(!cJSON_IsString(shipping_cost) && !cJSON_IsNull(shipping_cost))
    {
    goto end; //String
    }
    }

    // shipment->shipping_method
    cJSON *shipping_method = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "shippingMethod");
    if (cJSON_IsNull(shipping_method)) {
        shipping_method = NULL;
    }
    if (shipping_method) { 
    if(!cJSON_IsString(shipping_method) && !cJSON_IsNull(shipping_method))
    {
    goto end; //String
    }
    }

    // shipment->signed_by
    cJSON *signed_by = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "signedBy");
    if (cJSON_IsNull(signed_by)) {
        signed_by = NULL;
    }
    if (signed_by) { 
    if(!cJSON_IsString(signed_by) && !cJSON_IsNull(signed_by))
    {
    goto end; //String
    }
    }

    // shipment->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // shipment->tracking_events
    cJSON *tracking_events = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "trackingEvents");
    if (cJSON_IsNull(tracking_events)) {
        tracking_events = NULL;
    }
    if (tracking_events) { 
    tracking_events_local_nonprim = _parseFromJSON(tracking_events); //custom
    }

    // shipment->tracking_number
    cJSON *tracking_number = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "trackingNumber");
    if (cJSON_IsNull(tracking_number)) {
        tracking_number = NULL;
    }
    if (tracking_number) { 
    if(!cJSON_IsString(tracking_number) && !cJSON_IsNull(tracking_number))
    {
    goto end; //String
    }
    }

    // shipment->tracking_url
    cJSON *tracking_url = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "trackingUrl");
    if (cJSON_IsNull(tracking_url)) {
        tracking_url = NULL;
    }
    if (tracking_url) { 
    if(!cJSON_IsString(tracking_url) && !cJSON_IsNull(tracking_url))
    {
    goto end; //String
    }
    }

    // shipment->weight_kg
    cJSON *weight_kg = cJSON_GetObjectItemCaseSensitive(shipmentJSON, "weightKg");
    if (cJSON_IsNull(weight_kg)) {
        weight_kg = NULL;
    }
    if (weight_kg) { 
    if(!cJSON_IsNumber(weight_kg))
    {
    goto end; //Numeric
    }
    weight_kg_local_var = malloc(sizeof(double));
    if(!weight_kg_local_var)
    {
        goto end;
    }
    *weight_kg_local_var = weight_kg->valuedouble;
    }


    if (delivered_at && !cJSON_IsNull(delivered_at)) delivered_at_local_str = strdup(delivered_at->valuestring);
    if (label_url && !cJSON_IsNull(label_url)) label_url_local_str = strdup(label_url->valuestring);
    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);
    if (shipment_date) shipment_date_local_str = strdup(shipment_date->valuestring);
    if (shipping_carrier && !cJSON_IsNull(shipping_carrier)) shipping_carrier_local_str = strdup(shipping_carrier->valuestring);
    if (shipping_cost && !cJSON_IsNull(shipping_cost)) shipping_cost_local_str = strdup(shipping_cost->valuestring);
    if (shipping_method && !cJSON_IsNull(shipping_method)) shipping_method_local_str = strdup(shipping_method->valuestring);
    if (signed_by && !cJSON_IsNull(signed_by)) signed_by_local_str = strdup(signed_by->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (tracking_number && !cJSON_IsNull(tracking_number)) tracking_number_local_str = strdup(tracking_number->valuestring);
    if (tracking_url && !cJSON_IsNull(tracking_url)) tracking_url_local_str = strdup(tracking_url->valuestring);

    shipment_local_var = shipment_create_internal (
        delivered_at_local_str,
        label_url_local_str,
        line_items_shipment ? line_items_shipment_local_nonprim : NULL,
        order_id_local_str,
        recipient_address ? recipient_address_local_nonprim : NULL,
        shipment_date_local_str,
        shipping_carrier_local_str,
        shipping_cost_local_str,
        shipping_method_local_str,
        signed_by_local_str,
        status_local_str,
        tracking_events ? tracking_events_local_nonprim : NULL,
        tracking_number_local_str,
        tracking_url_local_str,
        weight_kg_local_var
        );

    if (!shipment_local_var) {
        goto end;
    }

    return shipment_local_var;
end:
    if (delivered_at_local_str) {
        free(delivered_at_local_str);
        delivered_at_local_str = NULL;
    }
    if (label_url_local_str) {
        free(label_url_local_str);
        label_url_local_str = NULL;
    }
    if (line_items_shipment_local_nonprim) {
        _free(line_items_shipment_local_nonprim);
        line_items_shipment_local_nonprim = NULL;
    }
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    if (recipient_address_local_nonprim) {
        _free(recipient_address_local_nonprim);
        recipient_address_local_nonprim = NULL;
    }
    if (shipment_date_local_str) {
        free(shipment_date_local_str);
        shipment_date_local_str = NULL;
    }
    if (shipping_carrier_local_str) {
        free(shipping_carrier_local_str);
        shipping_carrier_local_str = NULL;
    }
    if (shipping_cost_local_str) {
        free(shipping_cost_local_str);
        shipping_cost_local_str = NULL;
    }
    if (shipping_method_local_str) {
        free(shipping_method_local_str);
        shipping_method_local_str = NULL;
    }
    if (signed_by_local_str) {
        free(signed_by_local_str);
        signed_by_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (tracking_events_local_nonprim) {
        _free(tracking_events_local_nonprim);
        tracking_events_local_nonprim = NULL;
    }
    if (tracking_number_local_str) {
        free(tracking_number_local_str);
        tracking_number_local_str = NULL;
    }
    if (tracking_url_local_str) {
        free(tracking_url_local_str);
        tracking_url_local_str = NULL;
    }
    if (weight_kg_local_var) {
        free(weight_kg_local_var);
        weight_kg_local_var = NULL;
    }
    return NULL;

}
