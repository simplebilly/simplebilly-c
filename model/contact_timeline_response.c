#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "contact_timeline_response.h"



static contact_timeline_response_t *contact_timeline_response_create_internal(
    char *contact_id,
    list_t *events
    ) {
    contact_timeline_response_t *contact_timeline_response_local_var = malloc(sizeof(contact_timeline_response_t));
    if (!contact_timeline_response_local_var) {
        return NULL;
    }
    memset(contact_timeline_response_local_var, 0, sizeof(contact_timeline_response_t));
    contact_timeline_response_local_var->_library_owned = 1;
    contact_timeline_response_local_var->contact_id = contact_id;
    contact_timeline_response_local_var->events = events;
    return contact_timeline_response_local_var;
}

__attribute__((deprecated)) contact_timeline_response_t *contact_timeline_response_create(
    char *contact_id,
    list_t *events
    ) {
    contact_timeline_response_t *result = contact_timeline_response_create_internal (
        contact_id,
        events
        );
    if (!result) {
    }
    return result;
}

void contact_timeline_response_free(contact_timeline_response_t *contact_timeline_response) {
    if(NULL == contact_timeline_response){
        return ;
    }
    if(contact_timeline_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "contact_timeline_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (contact_timeline_response->contact_id) {
        free(contact_timeline_response->contact_id);
        contact_timeline_response->contact_id = NULL;
    }
    if (contact_timeline_response->events) {
        list_ForEach(listEntry, contact_timeline_response->events) {
            timeline_event_free(listEntry->data);
        }
        list_freeList(contact_timeline_response->events);
        contact_timeline_response->events = NULL;
    }
    free(contact_timeline_response);
}

cJSON *contact_timeline_response_convertToJSON(contact_timeline_response_t *contact_timeline_response) {
    cJSON *item = cJSON_CreateObject();

    // contact_timeline_response->contact_id
    if (!contact_timeline_response->contact_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "contactId", contact_timeline_response->contact_id) == NULL) {
    goto fail; //String
    }


    // contact_timeline_response->events
    if (!contact_timeline_response->events) {
        goto fail;
    }
    cJSON *events = cJSON_AddArrayToObject(item, "events");
    if(events == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *eventsListEntry;
    if (contact_timeline_response->events) {
    list_ForEach(eventsListEntry, contact_timeline_response->events) {
    cJSON *itemLocal = timeline_event_convertToJSON(eventsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(events, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

contact_timeline_response_t *contact_timeline_response_parseFromJSON(cJSON *contact_timeline_responseJSON){

    contact_timeline_response_t *contact_timeline_response_local_var = NULL;

    char *contact_id_local_str = NULL;

    // define the local list for contact_timeline_response->events
    list_t *eventsList = NULL;

    // contact_timeline_response->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(contact_timeline_responseJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (!contact_id) {
        goto end;
    }

    
    if(!cJSON_IsString(contact_id))
    {
    goto end; //String
    }

    // contact_timeline_response->events
    cJSON *events = cJSON_GetObjectItemCaseSensitive(contact_timeline_responseJSON, "events");
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
        timeline_event_t *eventsItem = timeline_event_parseFromJSON(events_local_nonprimitive);

        list_addElement(eventsList, eventsItem);
    }


    if (contact_id && !cJSON_IsNull(contact_id)) contact_id_local_str = strdup(contact_id->valuestring);

    contact_timeline_response_local_var = contact_timeline_response_create_internal (
        contact_id_local_str,
        eventsList
        );

    if (!contact_timeline_response_local_var) {
        goto end;
    }

    return contact_timeline_response_local_var;
end:
    if (contact_id_local_str) {
        free(contact_id_local_str);
        contact_id_local_str = NULL;
    }
    if (eventsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, eventsList) {
            timeline_event_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(eventsList);
        eventsList = NULL;
    }
    return NULL;

}
