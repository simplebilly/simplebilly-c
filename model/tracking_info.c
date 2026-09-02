#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tracking_info.h"



static tracking_info_t *tracking_info_create_internal(
    char *carrier,
    char *estimated_delivery,
    list_t *events,
    any_type_t *raw_response,
    char *status,
    char *tracking_number
    ) {
    tracking_info_t *tracking_info_local_var = malloc(sizeof(tracking_info_t));
    if (!tracking_info_local_var) {
        return NULL;
    }
    memset(tracking_info_local_var, 0, sizeof(tracking_info_t));
    tracking_info_local_var->_library_owned = 1;
    tracking_info_local_var->carrier = carrier;
    tracking_info_local_var->estimated_delivery = estimated_delivery;
    tracking_info_local_var->events = events;
    tracking_info_local_var->raw_response = raw_response;
    tracking_info_local_var->status = status;
    tracking_info_local_var->tracking_number = tracking_number;
    return tracking_info_local_var;
}

__attribute__((deprecated)) tracking_info_t *tracking_info_create(
    char *carrier,
    char *estimated_delivery,
    list_t *events,
    any_type_t *raw_response,
    char *status,
    char *tracking_number
    ) {
    tracking_info_t *result = tracking_info_create_internal (
        carrier,
        estimated_delivery,
        events,
        raw_response,
        status,
        tracking_number
        );
    if (!result) {
    }
    return result;
}

void tracking_info_free(tracking_info_t *tracking_info) {
    if(NULL == tracking_info){
        return ;
    }
    if(tracking_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "tracking_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (tracking_info->carrier) {
        free(tracking_info->carrier);
        tracking_info->carrier = NULL;
    }
    if (tracking_info->estimated_delivery) {
        free(tracking_info->estimated_delivery);
        tracking_info->estimated_delivery = NULL;
    }
    if (tracking_info->events) {
        list_ForEach(listEntry, tracking_info->events) {
            tracking_event_free(listEntry->data);
        }
        list_freeList(tracking_info->events);
        tracking_info->events = NULL;
    }
    if (tracking_info->raw_response) {
        _free(tracking_info->raw_response);
        tracking_info->raw_response = NULL;
    }
    if (tracking_info->status) {
        free(tracking_info->status);
        tracking_info->status = NULL;
    }
    if (tracking_info->tracking_number) {
        free(tracking_info->tracking_number);
        tracking_info->tracking_number = NULL;
    }
    free(tracking_info);
}

cJSON *tracking_info_convertToJSON(tracking_info_t *tracking_info) {
    cJSON *item = cJSON_CreateObject();

    // tracking_info->carrier
    if (!tracking_info->carrier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "carrier", tracking_info->carrier) == NULL) {
    goto fail; //String
    }


    // tracking_info->estimated_delivery
    if(tracking_info->estimated_delivery) {
    if(cJSON_AddStringToObject(item, "estimated_delivery", tracking_info->estimated_delivery) == NULL) {
    goto fail; //String
    }
    }


    // tracking_info->events
    if (!tracking_info->events) {
        goto fail;
    }
    cJSON *events = cJSON_AddArrayToObject(item, "events");
    if(events == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *eventsListEntry;
    if (tracking_info->events) {
    list_ForEach(eventsListEntry, tracking_info->events) {
    cJSON *itemLocal = tracking_event_convertToJSON(eventsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(events, itemLocal);
    }
    }


    // tracking_info->raw_response
    if(tracking_info->raw_response) {
    cJSON *raw_response_local_JSON = _convertToJSON(tracking_info->raw_response);
    if(raw_response_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "raw_response", raw_response_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // tracking_info->status
    if (!tracking_info->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", tracking_info->status) == NULL) {
    goto fail; //String
    }


    // tracking_info->tracking_number
    if (!tracking_info->tracking_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tracking_number", tracking_info->tracking_number) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

tracking_info_t *tracking_info_parseFromJSON(cJSON *tracking_infoJSON){

    tracking_info_t *tracking_info_local_var = NULL;

    char *carrier_local_str = NULL;

    char *estimated_delivery_local_str = NULL;

    // define the local list for tracking_info->events
    list_t *eventsList = NULL;

    // define the local variable for tracking_info->raw_response
    _t *raw_response_local_nonprim = NULL;

    char *status_local_str = NULL;

    char *tracking_number_local_str = NULL;

    // tracking_info->carrier
    cJSON *carrier = cJSON_GetObjectItemCaseSensitive(tracking_infoJSON, "carrier");
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

    // tracking_info->estimated_delivery
    cJSON *estimated_delivery = cJSON_GetObjectItemCaseSensitive(tracking_infoJSON, "estimated_delivery");
    if (cJSON_IsNull(estimated_delivery)) {
        estimated_delivery = NULL;
    }
    if (estimated_delivery) { 
    if(!cJSON_IsString(estimated_delivery) && !cJSON_IsNull(estimated_delivery))
    {
    goto end; //String
    }
    }

    // tracking_info->events
    cJSON *events = cJSON_GetObjectItemCaseSensitive(tracking_infoJSON, "events");
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

    // tracking_info->raw_response
    cJSON *raw_response = cJSON_GetObjectItemCaseSensitive(tracking_infoJSON, "raw_response");
    if (cJSON_IsNull(raw_response)) {
        raw_response = NULL;
    }
    if (raw_response) { 
    raw_response_local_nonprim = _parseFromJSON(raw_response); //custom
    }

    // tracking_info->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(tracking_infoJSON, "status");
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

    // tracking_info->tracking_number
    cJSON *tracking_number = cJSON_GetObjectItemCaseSensitive(tracking_infoJSON, "tracking_number");
    if (cJSON_IsNull(tracking_number)) {
        tracking_number = NULL;
    }
    if (!tracking_number) {
        goto end;
    }

    
    if(!cJSON_IsString(tracking_number))
    {
    goto end; //String
    }


    if (carrier && !cJSON_IsNull(carrier)) carrier_local_str = strdup(carrier->valuestring);
    if (estimated_delivery && !cJSON_IsNull(estimated_delivery)) estimated_delivery_local_str = strdup(estimated_delivery->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (tracking_number && !cJSON_IsNull(tracking_number)) tracking_number_local_str = strdup(tracking_number->valuestring);

    tracking_info_local_var = tracking_info_create_internal (
        carrier_local_str,
        estimated_delivery_local_str,
        eventsList,
        raw_response ? raw_response_local_nonprim : NULL,
        status_local_str,
        tracking_number_local_str
        );

    if (!tracking_info_local_var) {
        goto end;
    }

    return tracking_info_local_var;
end:
    if (carrier_local_str) {
        free(carrier_local_str);
        carrier_local_str = NULL;
    }
    if (estimated_delivery_local_str) {
        free(estimated_delivery_local_str);
        estimated_delivery_local_str = NULL;
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
    if (raw_response_local_nonprim) {
        _free(raw_response_local_nonprim);
        raw_response_local_nonprim = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (tracking_number_local_str) {
        free(tracking_number_local_str);
        tracking_number_local_str = NULL;
    }
    return NULL;

}
