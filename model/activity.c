#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity.h"



static activity_t *activity_create_internal(
    activity_type_t *activity_type,
    char *assigned_to,
    char *contact_id,
    char *description,
    char *due_date,
    char *reminder_date,
    activity_status_t *status,
    char *subject
    ) {
    activity_t *activity_local_var = malloc(sizeof(activity_t));
    if (!activity_local_var) {
        return NULL;
    }
    memset(activity_local_var, 0, sizeof(activity_t));
    activity_local_var->_library_owned = 1;
    activity_local_var->activity_type = activity_type;
    activity_local_var->assigned_to = assigned_to;
    activity_local_var->contact_id = contact_id;
    activity_local_var->description = description;
    activity_local_var->due_date = due_date;
    activity_local_var->reminder_date = reminder_date;
    activity_local_var->status = status;
    activity_local_var->subject = subject;
    return activity_local_var;
}

__attribute__((deprecated)) activity_t *activity_create(
    activity_type_t *activity_type,
    char *assigned_to,
    char *contact_id,
    char *description,
    char *due_date,
    char *reminder_date,
    activity_status_t *status,
    char *subject
    ) {
    activity_t *result = activity_create_internal (
        activity_type,
        assigned_to,
        contact_id,
        description,
        due_date,
        reminder_date,
        status,
        subject
        );
    if (!result) {
    }
    return result;
}

void activity_free(activity_t *activity) {
    if(NULL == activity){
        return ;
    }
    if(activity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity->activity_type) {
        activity_type_free(activity->activity_type);
        activity->activity_type = NULL;
    }
    if (activity->assigned_to) {
        free(activity->assigned_to);
        activity->assigned_to = NULL;
    }
    if (activity->contact_id) {
        free(activity->contact_id);
        activity->contact_id = NULL;
    }
    if (activity->description) {
        free(activity->description);
        activity->description = NULL;
    }
    if (activity->due_date) {
        free(activity->due_date);
        activity->due_date = NULL;
    }
    if (activity->reminder_date) {
        free(activity->reminder_date);
        activity->reminder_date = NULL;
    }
    if (activity->status) {
        activity_status_free(activity->status);
        activity->status = NULL;
    }
    if (activity->subject) {
        free(activity->subject);
        activity->subject = NULL;
    }
    free(activity);
}

cJSON *activity_convertToJSON(activity_t *activity) {
    cJSON *item = cJSON_CreateObject();

    // activity->activity_type
    if (!activity->activity_type) {
        goto fail;
    }
    cJSON *activity_type_local_JSON = activity_type_convertToJSON(activity->activity_type);
    if(activity_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "activityType", activity_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // activity->assigned_to
    if(activity->assigned_to) {
    if(cJSON_AddStringToObject(item, "assignedTo", activity->assigned_to) == NULL) {
    goto fail; //String
    }
    }


    // activity->contact_id
    if(activity->contact_id) {
    if(cJSON_AddStringToObject(item, "contactId", activity->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // activity->description
    if(activity->description) {
    if(cJSON_AddStringToObject(item, "description", activity->description) == NULL) {
    goto fail; //String
    }
    }


    // activity->due_date
    if(activity->due_date) {
    if(cJSON_AddStringToObject(item, "dueDate", activity->due_date) == NULL) {
    goto fail; //Date
    }
    }


    // activity->reminder_date
    if(activity->reminder_date) {
    if(cJSON_AddStringToObject(item, "reminderDate", activity->reminder_date) == NULL) {
    goto fail; //Date
    }
    }


    // activity->status
    if (!activity->status) {
        goto fail;
    }
    cJSON *status_local_JSON = activity_status_convertToJSON(activity->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // activity->subject
    if (!activity->subject) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "subject", activity->subject) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

activity_t *activity_parseFromJSON(cJSON *activityJSON){

    activity_t *activity_local_var = NULL;

    // define the local variable for activity->activity_type
    activity_type_t *activity_type_local_nonprim = NULL;

    char *assigned_to_local_str = NULL;

    char *contact_id_local_str = NULL;

    char *description_local_str = NULL;

    char *due_date_local_str = NULL;

    char *reminder_date_local_str = NULL;

    // define the local variable for activity->status
    activity_status_t *status_local_nonprim = NULL;

    char *subject_local_str = NULL;

    // activity->activity_type
    cJSON *activity_type = cJSON_GetObjectItemCaseSensitive(activityJSON, "activityType");
    if (cJSON_IsNull(activity_type)) {
        activity_type = NULL;
    }
    if (!activity_type) {
        goto end;
    }

    
    activity_type_local_nonprim = activity_type_parseFromJSON(activity_type); //custom

    // activity->assigned_to
    cJSON *assigned_to = cJSON_GetObjectItemCaseSensitive(activityJSON, "assignedTo");
    if (cJSON_IsNull(assigned_to)) {
        assigned_to = NULL;
    }
    if (assigned_to) { 
    if(!cJSON_IsString(assigned_to) && !cJSON_IsNull(assigned_to))
    {
    goto end; //String
    }
    }

    // activity->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(activityJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // activity->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(activityJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // activity->due_date
    cJSON *due_date = cJSON_GetObjectItemCaseSensitive(activityJSON, "dueDate");
    if (cJSON_IsNull(due_date)) {
        due_date = NULL;
    }
    if (due_date) { 
    if(!cJSON_IsString(due_date))
    {
    goto end; //Date
    }
    }

    // activity->reminder_date
    cJSON *reminder_date = cJSON_GetObjectItemCaseSensitive(activityJSON, "reminderDate");
    if (cJSON_IsNull(reminder_date)) {
        reminder_date = NULL;
    }
    if (reminder_date) { 
    if(!cJSON_IsString(reminder_date))
    {
    goto end; //Date
    }
    }

    // activity->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(activityJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = activity_status_parseFromJSON(status); //custom

    // activity->subject
    cJSON *subject = cJSON_GetObjectItemCaseSensitive(activityJSON, "subject");
    if (cJSON_IsNull(subject)) {
        subject = NULL;
    }
    if (!subject) {
        goto end;
    }

    
    if(!cJSON_IsString(subject))
    {
    goto end; //String
    }


    if (assigned_to && !cJSON_IsNull(assigned_to)) assigned_to_local_str = strdup(assigned_to->valuestring);
    if (contact_id && !cJSON_IsNull(contact_id)) contact_id_local_str = strdup(contact_id->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (due_date) due_date_local_str = strdup(due_date->valuestring);
    if (reminder_date) reminder_date_local_str = strdup(reminder_date->valuestring);
    if (subject && !cJSON_IsNull(subject)) subject_local_str = strdup(subject->valuestring);

    activity_local_var = activity_create_internal (
        activity_type_local_nonprim,
        assigned_to_local_str,
        contact_id_local_str,
        description_local_str,
        due_date_local_str,
        reminder_date_local_str,
        status_local_nonprim,
        subject_local_str
        );

    if (!activity_local_var) {
        goto end;
    }

    return activity_local_var;
end:
    if (activity_type_local_nonprim) {
        activity_type_free(activity_type_local_nonprim);
        activity_type_local_nonprim = NULL;
    }
    if (assigned_to_local_str) {
        free(assigned_to_local_str);
        assigned_to_local_str = NULL;
    }
    if (contact_id_local_str) {
        free(contact_id_local_str);
        contact_id_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (due_date_local_str) {
        free(due_date_local_str);
        due_date_local_str = NULL;
    }
    if (reminder_date_local_str) {
        free(reminder_date_local_str);
        reminder_date_local_str = NULL;
    }
    if (status_local_nonprim) {
        activity_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (subject_local_str) {
        free(subject_local_str);
        subject_local_str = NULL;
    }
    return NULL;

}
