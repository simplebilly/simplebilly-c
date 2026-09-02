#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tracked_shipment.h"



static tracked_shipment_t *tracked_shipment_create_internal(
    char *carrier,
    list_t *events,
    char *label_url,
    char *status,
    char *tracking_number,
    char *tracking_url
    ) {
    tracked_shipment_t *tracked_shipment_local_var = malloc(sizeof(tracked_shipment_t));
    if (!tracked_shipment_local_var) {
        return NULL;
    }
    memset(tracked_shipment_local_var, 0, sizeof(tracked_shipment_t));
    tracked_shipment_local_var->_library_owned = 1;
    tracked_shipment_local_var->carrier = carrier;
    tracked_shipment_local_var->events = events;
    tracked_shipment_local_var->label_url = label_url;
    tracked_shipment_local_var->status = status;
    tracked_shipment_local_var->tracking_number = tracking_number;
    tracked_shipment_local_var->tracking_url = tracking_url;
    return tracked_shipment_local_var;
}

__attribute__((deprecated)) tracked_shipment_t *tracked_shipment_create(
    char *carrier,
    list_t *events,
    char *label_url,
    char *status,
    char *tracking_number,
    char *tracking_url
    ) {
    tracked_shipment_t *result = tracked_shipment_create_internal (
        carrier,
        events,
        label_url,
        status,
        tracking_number,
        tracking_url
        );
    if (!result) {
    }
    return result;
}

void tracked_shipment_free(tracked_shipment_t *tracked_shipment) {
    if(NULL == tracked_shipment){
        return ;
    }
    if(tracked_shipment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "tracked_shipment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (tracked_shipment->carrier) {
        free(tracked_shipment->carrier);
        tracked_shipment->carrier = NULL;
    }
    if (tracked_shipment->events) {
        list_ForEach(listEntry, tracked_shipment->events) {
            tracking_event_free(listEntry->data);
        }
        list_freeList(tracked_shipment->events);
        tracked_shipment->events = NULL;
    }
    if (tracked_shipment->label_url) {
        free(tracked_shipment->label_url);
        tracked_shipment->label_url = NULL;
    }
    if (tracked_shipment->status) {
        free(tracked_shipment->status);
        tracked_shipment->status = NULL;
    }
    if (tracked_shipment->tracking_number) {
        free(tracked_shipment->tracking_number);
        tracked_shipment->tracking_number = NULL;
    }
    if (tracked_shipment->tracking_url) {
        free(tracked_shipment->tracking_url);
        tracked_shipment->tracking_url = NULL;
    }
    free(tracked_shipment);
}

cJSON *tracked_shipment_convertToJSON(tracked_shipment_t *tracked_shipment) {
    cJSON *item = cJSON_CreateObject();

    // tracked_shipment->carrier
    if (!tracked_shipment->carrier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "carrier", tracked_shipment->carrier) == NULL) {
    goto fail; //String
    }


    // tracked_shipment->events
    if (!tracked_shipment->events) {
        goto fail;
    }
    cJSON *events = cJSON_AddArrayToObject(item, "events");
    if(events == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *eventsListEntry;
    if (tracked_shipment->events) {
    list_ForEach(eventsListEntry, tracked_shipment->events) {
    cJSON *itemLocal = tracking_event_convertToJSON(eventsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(events, itemLocal);
    }
    }


    // tracked_shipment->label_url
    if(tracked_shipment->label_url) {
    if(cJSON_AddStringToObject(item, "label_url", tracked_shipment->label_url) == NULL) {
    goto fail; //String
    }
    }


    // tracked_shipment->status
    if (!tracked_shipment->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", tracked_shipment->status) == NULL) {
    goto fail; //String
    }


    // tracked_shipment->tracking_number
    if(tracked_shipment->tracking_number) {
    if(cJSON_AddStringToObject(item, "tracking_number", tracked_shipment->tracking_number) == NULL) {
    goto fail; //String
    }
    }


    // tracked_shipment->tracking_url
    if(tracked_shipment->tracking_url) {
    if(cJSON_AddStringToObject(item, "tracking_url", tracked_shipment->tracking_url) == NULL) {
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

tracked_shipment_t *tracked_shipment_parseFromJSON(cJSON *tracked_shipmentJSON){

    tracked_shipment_t *tracked_shipment_local_var = NULL;

    char *carrier_local_str = NULL;

    // define the local list for tracked_shipment->events
    list_t *eventsList = NULL;

    char *label_url_local_str = NULL;

    char *status_local_str = NULL;

    char *tracking_number_local_str = NULL;

    char *tracking_url_local_str = NULL;

    // tracked_shipment->carrier
    cJSON *carrier = cJSON_GetObjectItemCaseSensitive(tracked_shipmentJSON, "carrier");
    if (cJSON_IsNull(carrier)) {
        carrier = NULL;
    }
    if (!carrier) {
        goto end;
    }

    
    if(!cJSON_IsString(carrier))
    {
    goto end; //String
    }

    // tracked_shipment->events
    cJSON *events = cJSON_GetObjectItemCaseSensitive(tracked_shipmentJSON, "events");
    if (cJSON_IsNull(events)) {
        events = NULL;
    }
    if (!events) {
        goto end;
    }

    
    cJSON *events_local_nonprimitive = NULL;
    if(!cJSON_IsArray(events)){
        goto end; //nonprimitive container
    }

    eventsList = list_createList();

    cJSON_ArrayForEach(events_local_nonprimitive,events )
    {
        if(!cJSON_IsObject(events_local_nonprimitive)){
            goto end;
        }
        tracking_event_t *eventsItem = tracking_event_parseFromJSON(events_local_nonprimitive);

        list_addElement(eventsList, eventsItem);
    }

    // tracked_shipment->label_url
    cJSON *label_url = cJSON_GetObjectItemCaseSensitive(tracked_shipmentJSON, "label_url");
    if (cJSON_IsNull(label_url)) {
        label_url = NULL;
    }
    if (label_url) { 
    if(!cJSON_IsString(label_url) && !cJSON_IsNull(label_url))
    {
    goto end; //String
    }
    }

    // tracked_shipment->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(tracked_shipmentJSON, "status");
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

    // tracked_shipment->tracking_number
    cJSON *tracking_number = cJSON_GetObjectItemCaseSensitive(tracked_shipmentJSON, "tracking_number");
    if (cJSON_IsNull(tracking_number)) {
        tracking_number = NULL;
    }
    if (tracking_number) { 
    if(!cJSON_IsString(tracking_number) && !cJSON_IsNull(tracking_number))
    {
    goto end; //String
    }
    }

    // tracked_shipment->tracking_url
    cJSON *tracking_url = cJSON_GetObjectItemCaseSensitive(tracked_shipmentJSON, "tracking_url");
    if (cJSON_IsNull(tracking_url)) {
        tracking_url = NULL;
    }
    if (tracking_url) { 
    if(!cJSON_IsString(tracking_url) && !cJSON_IsNull(tracking_url))
    {
    goto end; //String
    }
    }


    if (carrier && !cJSON_IsNull(carrier)) carrier_local_str = strdup(carrier->valuestring);
    if (label_url && !cJSON_IsNull(label_url)) label_url_local_str = strdup(label_url->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (tracking_number && !cJSON_IsNull(tracking_number)) tracking_number_local_str = strdup(tracking_number->valuestring);
    if (tracking_url && !cJSON_IsNull(tracking_url)) tracking_url_local_str = strdup(tracking_url->valuestring);

    tracked_shipment_local_var = tracked_shipment_create_internal (
        carrier_local_str,
        eventsList,
        label_url_local_str,
        status_local_str,
        tracking_number_local_str,
        tracking_url_local_str
        );

    if (!tracked_shipment_local_var) {
        goto end;
    }

    return tracked_shipment_local_var;
end:
    if (carrier_local_str) {
        free(carrier_local_str);
        carrier_local_str = NULL;
    }
    if (eventsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, eventsList) {
            tracking_event_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(eventsList);
        eventsList = NULL;
    }
    if (label_url_local_str) {
        free(label_url_local_str);
        label_url_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (tracking_number_local_str) {
        free(tracking_number_local_str);
        tracking_number_local_str = NULL;
    }
    if (tracking_url_local_str) {
        free(tracking_url_local_str);
        tracking_url_local_str = NULL;
    }
    return NULL;

}
