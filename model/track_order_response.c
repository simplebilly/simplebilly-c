#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "track_order_response.h"



static track_order_response_t *track_order_response_create_internal(
    char *order_number,
    char *order_status,
    list_t *shipments
    ) {
    track_order_response_t *track_order_response_local_var = malloc(sizeof(track_order_response_t));
    if (!track_order_response_local_var) {
        return NULL;
    }
    memset(track_order_response_local_var, 0, sizeof(track_order_response_t));
    track_order_response_local_var->_library_owned = 1;
    track_order_response_local_var->order_number = order_number;
    track_order_response_local_var->order_status = order_status;
    track_order_response_local_var->shipments = shipments;
    return track_order_response_local_var;
}

__attribute__((deprecated)) track_order_response_t *track_order_response_create(
    char *order_number,
    char *order_status,
    list_t *shipments
    ) {
    track_order_response_t *result = track_order_response_create_internal (
        order_number,
        order_status,
        shipments
        );
    if (!result) {
    }
    return result;
}

void track_order_response_free(track_order_response_t *track_order_response) {
    if(NULL == track_order_response){
        return ;
    }
    if(track_order_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "track_order_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (track_order_response->order_number) {
        free(track_order_response->order_number);
        track_order_response->order_number = NULL;
    }
    if (track_order_response->order_status) {
        free(track_order_response->order_status);
        track_order_response->order_status = NULL;
    }
    if (track_order_response->shipments) {
        list_ForEach(listEntry, track_order_response->shipments) {
            tracked_shipment_free(listEntry->data);
        }
        list_freeList(track_order_response->shipments);
        track_order_response->shipments = NULL;
    }
    free(track_order_response);
}

cJSON *track_order_response_convertToJSON(track_order_response_t *track_order_response) {
    cJSON *item = cJSON_CreateObject();

    // track_order_response->order_number
    if (!track_order_response->order_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_number", track_order_response->order_number) == NULL) {
    goto fail; //String
    }


    // track_order_response->order_status
    if (!track_order_response->order_status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_status", track_order_response->order_status) == NULL) {
    goto fail; //String
    }


    // track_order_response->shipments
    if (!track_order_response->shipments) {
        goto fail;
    }
    cJSON *shipments = cJSON_AddArrayToObject(item, "shipments");
    if(shipments == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *shipmentsListEntry;
    if (track_order_response->shipments) {
    list_ForEach(shipmentsListEntry, track_order_response->shipments) {
    cJSON *itemLocal = tracked_shipment_convertToJSON(shipmentsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(shipments, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

track_order_response_t *track_order_response_parseFromJSON(cJSON *track_order_responseJSON){

    track_order_response_t *track_order_response_local_var = NULL;

    char *order_number_local_str = NULL;

    char *order_status_local_str = NULL;

    // define the local list for track_order_response->shipments
    list_t *shipmentsList = NULL;

    // track_order_response->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(track_order_responseJSON, "order_number");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (!order_number) {
        goto end;
    }

    
    if(!cJSON_IsString(order_number))
    {
    goto end; //String
    }

    // track_order_response->order_status
    cJSON *order_status = cJSON_GetObjectItemCaseSensitive(track_order_responseJSON, "order_status");
    if (cJSON_IsNull(order_status)) {
        order_status = NULL;
    }
    if (!order_status) {
        goto end;
    }

    
    if(!cJSON_IsString(order_status))
    {
    goto end; //String
    }

    // track_order_response->shipments
    cJSON *shipments = cJSON_GetObjectItemCaseSensitive(track_order_responseJSON, "shipments");
    if (cJSON_IsNull(shipments)) {
        shipments = NULL;
    }
    if (!shipments) {
        goto end;
    }

    
    cJSON *shipments_local_nonprimitive = NULL;
    if(!cJSON_IsArray(shipments)){
        goto end; //nonprimitive container
    }

    shipmentsList = list_createList();

    cJSON_ArrayForEach(shipments_local_nonprimitive,shipments )
    {
        if(!cJSON_IsObject(shipments_local_nonprimitive)){
            goto end;
        }
        tracked_shipment_t *shipmentsItem = tracked_shipment_parseFromJSON(shipments_local_nonprimitive);

        list_addElement(shipmentsList, shipmentsItem);
    }


    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);
    if (order_status && !cJSON_IsNull(order_status)) order_status_local_str = strdup(order_status->valuestring);

    track_order_response_local_var = track_order_response_create_internal (
        order_number_local_str,
        order_status_local_str,
        shipmentsList
        );

    if (!track_order_response_local_var) {
        goto end;
    }

    return track_order_response_local_var;
end:
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    if (order_status_local_str) {
        free(order_status_local_str);
        order_status_local_str = NULL;
    }
    if (shipmentsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, shipmentsList) {
            tracked_shipment_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(shipmentsList);
        shipmentsList = NULL;
    }
    return NULL;

}
