#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tracking_event.h"



static tracking_event_t *tracking_event_create_internal(
    char *date,
    char *description,
    char *location,
    char *status
    ) {
    tracking_event_t *tracking_event_local_var = malloc(sizeof(tracking_event_t));
    if (!tracking_event_local_var) {
        return NULL;
    }
    memset(tracking_event_local_var, 0, sizeof(tracking_event_t));
    tracking_event_local_var->_library_owned = 1;
    tracking_event_local_var->date = date;
    tracking_event_local_var->description = description;
    tracking_event_local_var->location = location;
    tracking_event_local_var->status = status;
    return tracking_event_local_var;
}

__attribute__((deprecated)) tracking_event_t *tracking_event_create(
    char *date,
    char *description,
    char *location,
    char *status
    ) {
    tracking_event_t *result = tracking_event_create_internal (
        date,
        description,
        location,
        status
        );
    if (!result) {
    }
    return result;
}

void tracking_event_free(tracking_event_t *tracking_event) {
    if(NULL == tracking_event){
        return ;
    }
    if(tracking_event->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "tracking_event_free");
        return ;
    }
    listEntry_t *listEntry;
    if (tracking_event->date) {
        free(tracking_event->date);
        tracking_event->date = NULL;
    }
    if (tracking_event->description) {
        free(tracking_event->description);
        tracking_event->description = NULL;
    }
    if (tracking_event->location) {
        free(tracking_event->location);
        tracking_event->location = NULL;
    }
    if (tracking_event->status) {
        free(tracking_event->status);
        tracking_event->status = NULL;
    }
    free(tracking_event);
}

cJSON *tracking_event_convertToJSON(tracking_event_t *tracking_event) {
    cJSON *item = cJSON_CreateObject();

    // tracking_event->date
    if (!tracking_event->date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "date", tracking_event->date) == NULL) {
    goto fail; //String
    }


    // tracking_event->description
    if (!tracking_event->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", tracking_event->description) == NULL) {
    goto fail; //String
    }


    // tracking_event->location
    if (!tracking_event->location) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "location", tracking_event->location) == NULL) {
    goto fail; //String
    }


    // tracking_event->status
    if (!tracking_event->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", tracking_event->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

tracking_event_t *tracking_event_parseFromJSON(cJSON *tracking_eventJSON){

    tracking_event_t *tracking_event_local_var = NULL;

    char *date_local_str = NULL;

    char *description_local_str = NULL;

    char *location_local_str = NULL;

    char *status_local_str = NULL;

    // tracking_event->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(tracking_eventJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsString(date))
    {
    goto end; //String
    }

    // tracking_event->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(tracking_eventJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }

    // tracking_event->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(tracking_eventJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (!location) {
        goto end;
    }

    
    if(!cJSON_IsString(location))
    {
    goto end; //String
    }

    // tracking_event->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(tracking_eventJSON, "status");
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


    if (date && !cJSON_IsNull(date)) date_local_str = strdup(date->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (location && !cJSON_IsNull(location)) location_local_str = strdup(location->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    tracking_event_local_var = tracking_event_create_internal (
        date_local_str,
        description_local_str,
        location_local_str,
        status_local_str
        );

    if (!tracking_event_local_var) {
        goto end;
    }

    return tracking_event_local_var;
end:
    if (date_local_str) {
        free(date_local_str);
        date_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (location_local_str) {
        free(location_local_str);
        location_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
