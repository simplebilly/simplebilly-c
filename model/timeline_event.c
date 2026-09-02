#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "timeline_event.h"



static timeline_event_t *timeline_event_create_internal(
    char *date,
    char *detail,
    char *id,
    char *status,
    char *title,
    char *type
    ) {
    timeline_event_t *timeline_event_local_var = malloc(sizeof(timeline_event_t));
    if (!timeline_event_local_var) {
        return NULL;
    }
    memset(timeline_event_local_var, 0, sizeof(timeline_event_t));
    timeline_event_local_var->_library_owned = 1;
    timeline_event_local_var->date = date;
    timeline_event_local_var->detail = detail;
    timeline_event_local_var->id = id;
    timeline_event_local_var->status = status;
    timeline_event_local_var->title = title;
    timeline_event_local_var->type = type;
    return timeline_event_local_var;
}

__attribute__((deprecated)) timeline_event_t *timeline_event_create(
    char *date,
    char *detail,
    char *id,
    char *status,
    char *title,
    char *type
    ) {
    timeline_event_t *result = timeline_event_create_internal (
        date,
        detail,
        id,
        status,
        title,
        type
        );
    if (!result) {
    }
    return result;
}

void timeline_event_free(timeline_event_t *timeline_event) {
    if(NULL == timeline_event){
        return ;
    }
    if(timeline_event->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "timeline_event_free");
        return ;
    }
    listEntry_t *listEntry;
    if (timeline_event->date) {
        free(timeline_event->date);
        timeline_event->date = NULL;
    }
    if (timeline_event->detail) {
        free(timeline_event->detail);
        timeline_event->detail = NULL;
    }
    if (timeline_event->id) {
        free(timeline_event->id);
        timeline_event->id = NULL;
    }
    if (timeline_event->status) {
        free(timeline_event->status);
        timeline_event->status = NULL;
    }
    if (timeline_event->title) {
        free(timeline_event->title);
        timeline_event->title = NULL;
    }
    if (timeline_event->type) {
        free(timeline_event->type);
        timeline_event->type = NULL;
    }
    free(timeline_event);
}

cJSON *timeline_event_convertToJSON(timeline_event_t *timeline_event) {
    cJSON *item = cJSON_CreateObject();

    // timeline_event->date
    if (!timeline_event->date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "date", timeline_event->date) == NULL) {
    goto fail; //String
    }


    // timeline_event->detail
    if(timeline_event->detail) {
    if(cJSON_AddStringToObject(item, "detail", timeline_event->detail) == NULL) {
    goto fail; //String
    }
    }


    // timeline_event->id
    if (!timeline_event->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", timeline_event->id) == NULL) {
    goto fail; //String
    }


    // timeline_event->status
    if(timeline_event->status) {
    if(cJSON_AddStringToObject(item, "status", timeline_event->status) == NULL) {
    goto fail; //String
    }
    }


    // timeline_event->title
    if (!timeline_event->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", timeline_event->title) == NULL) {
    goto fail; //String
    }


    // timeline_event->type
    if (!timeline_event->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", timeline_event->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

timeline_event_t *timeline_event_parseFromJSON(cJSON *timeline_eventJSON){

    timeline_event_t *timeline_event_local_var = NULL;

    char *date_local_str = NULL;

    char *detail_local_str = NULL;

    char *id_local_str = NULL;

    char *status_local_str = NULL;

    char *title_local_str = NULL;

    char *type_local_str = NULL;

    // timeline_event->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(timeline_eventJSON, "date");
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

    // timeline_event->detail
    cJSON *detail = cJSON_GetObjectItemCaseSensitive(timeline_eventJSON, "detail");
    if (cJSON_IsNull(detail)) {
        detail = NULL;
    }
    if (detail) { 
    if(!cJSON_IsString(detail) && !cJSON_IsNull(detail))
    {
    goto end; //String
    }
    }

    // timeline_event->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(timeline_eventJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // timeline_event->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(timeline_eventJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // timeline_event->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(timeline_eventJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // timeline_event->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(timeline_eventJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    if (date && !cJSON_IsNull(date)) date_local_str = strdup(date->valuestring);
    if (detail && !cJSON_IsNull(detail)) detail_local_str = strdup(detail->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (type && !cJSON_IsNull(type)) type_local_str = strdup(type->valuestring);

    timeline_event_local_var = timeline_event_create_internal (
        date_local_str,
        detail_local_str,
        id_local_str,
        status_local_str,
        title_local_str,
        type_local_str
        );

    if (!timeline_event_local_var) {
        goto end;
    }

    return timeline_event_local_var;
end:
    if (date_local_str) {
        free(date_local_str);
        date_local_str = NULL;
    }
    if (detail_local_str) {
        free(detail_local_str);
        detail_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    if (type_local_str) {
        free(type_local_str);
        type_local_str = NULL;
    }
    return NULL;

}
