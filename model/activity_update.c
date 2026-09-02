#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_update.h"



static activity_update_t *activity_update_create_internal(
    activity_type_t *activity_type,
    char *assigned_to,
    char *contact_id,
    char *description,
    char *due_date,
    char *reminder_date,
    activity_status_t *status,
    char *subject
    ) {
    activity_update_t *activity_update_local_var = malloc(sizeof(activity_update_t));
    if (!activity_update_local_var) {
        return NULL;
    }
    memset(activity_update_local_var, 0, sizeof(activity_update_t));
    activity_update_local_var->_library_owned = 1;
    activity_update_local_var->activity_type = activity_type;
    activity_update_local_var->assigned_to = assigned_to;
    activity_update_local_var->contact_id = contact_id;
    activity_update_local_var->description = description;
    activity_update_local_var->due_date = due_date;
    activity_update_local_var->reminder_date = reminder_date;
    activity_update_local_var->status = status;
    activity_update_local_var->subject = subject;
    return activity_update_local_var;
}

__attribute__((deprecated)) activity_update_t *activity_update_create(
    activity_type_t *activity_type,
    char *assigned_to,
    char *contact_id,
    char *description,
    char *due_date,
    char *reminder_date,
    activity_status_t *status,
    char *subject
    ) {
    activity_update_t *result = activity_update_create_internal (
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

void activity_update_free(activity_update_t *activity_update) {
    if(NULL == activity_update){
        return ;
    }
    if(activity_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_update->activity_type) {
        activity_type_free(activity_update->activity_type);
        activity_update->activity_type = NULL;
    }
    if (activity_update->assigned_to) {
        free(activity_update->assigned_to);
        activity_update->assigned_to = NULL;
    }
    if (activity_update->contact_id) {
        free(activity_update->contact_id);
        activity_update->contact_id = NULL;
    }
    if (activity_update->description) {
        free(activity_update->description);
        activity_update->description = NULL;
    }
    if (activity_update->due_date) {
        free(activity_update->due_date);
        activity_update->due_date = NULL;
    }
    if (activity_update->reminder_date) {
        free(activity_update->reminder_date);
        activity_update->reminder_date = NULL;
    }
    if (activity_update->status) {
        activity_status_free(activity_update->status);
        activity_update->status = NULL;
    }
    if (activity_update->subject) {
        free(activity_update->subject);
        activity_update->subject = NULL;
    }
    free(activity_update);
}

cJSON *activity_update_convertToJSON(activity_update_t *activity_update) {
    cJSON *item = cJSON_CreateObject();

    // activity_update->activity_type
    if(activity_update->activity_type) {
    cJSON *activity_type_local_JSON = activity_type_convertToJSON(activity_update->activity_type);
    if(activity_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "activityType", activity_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // activity_update->assigned_to
    if(activity_update->assigned_to) {
    if(cJSON_AddStringToObject(item, "assignedTo", activity_update->assigned_to) == NULL) {
    goto fail; //String
    }
    }


    // activity_update->contact_id
    if(activity_update->contact_id) {
    if(cJSON_AddStringToObject(item, "contactId", activity_update->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // activity_update->description
    if(activity_update->description) {
    if(cJSON_AddStringToObject(item, "description", activity_update->description) == NULL) {
    goto fail; //String
    }
    }


    // activity_update->due_date
    if(activity_update->due_date) {
    if(cJSON_AddStringToObject(item, "dueDate", activity_update->due_date) == NULL) {
    goto fail; //Date
    }
    }


    // activity_update->reminder_date
    if(activity_update->reminder_date) {
    if(cJSON_AddStringToObject(item, "reminderDate", activity_update->reminder_date) == NULL) {
    goto fail; //Date
    }
    }


    // activity_update->status
    if(activity_update->status) {
    cJSON *status_local_JSON = activity_status_convertToJSON(activity_update->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // activity_update->subject
    if(activity_update->subject) {
    if(cJSON_AddStringToObject(item, "subject", activity_update->subject) == NULL) {
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

activity_update_t *activity_update_parseFromJSON(cJSON *activity_updateJSON){

    activity_update_t *activity_update_local_var = NULL;

    // define the local variable for activity_update->activity_type
    activity_type_t *activity_type_local_nonprim = NULL;

    char *assigned_to_local_str = NULL;

    char *contact_id_local_str = NULL;

    char *description_local_str = NULL;

    char *due_date_local_str = NULL;

    char *reminder_date_local_str = NULL;

    // define the local variable for activity_update->status
    activity_status_t *status_local_nonprim = NULL;

    char *subject_local_str = NULL;

    // activity_update->activity_type
    cJSON *activity_type = cJSON_GetObjectItemCaseSensitive(activity_updateJSON, "activityType");
    if (cJSON_IsNull(activity_type)) {
        activity_type = NULL;
    }
    if (activity_type) { 
    activity_type_local_nonprim = activity_type_parseFromJSON(activity_type); //custom
    }

    // activity_update->assigned_to
    cJSON *assigned_to = cJSON_GetObjectItemCaseSensitive(activity_updateJSON, "assignedTo");
    if (cJSON_IsNull(assigned_to)) {
        assigned_to = NULL;
    }
    if (assigned_to) { 
    if(!cJSON_IsString(assigned_to) && !cJSON_IsNull(assigned_to))
    {
    goto end; //String
    }
    }

    // activity_update->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(activity_updateJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // activity_update->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(activity_updateJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // activity_update->due_date
    cJSON *due_date = cJSON_GetObjectItemCaseSensitive(activity_updateJSON, "dueDate");
    if (cJSON_IsNull(due_date)) {
        due_date = NULL;
    }
    if (due_date) { 
    if(!cJSON_IsString(due_date))
    {
    goto end; //Date
    }
    }

    // activity_update->reminder_date
    cJSON *reminder_date = cJSON_GetObjectItemCaseSensitive(activity_updateJSON, "reminderDate");
    if (cJSON_IsNull(reminder_date)) {
        reminder_date = NULL;
    }
    if (reminder_date) { 
    if(!cJSON_IsString(reminder_date))
    {
    goto end; //Date
    }
    }

    // activity_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(activity_updateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = activity_status_parseFromJSON(status); //custom
    }

    // activity_update->subject
    cJSON *subject = cJSON_GetObjectItemCaseSensitive(activity_updateJSON, "subject");
    if (cJSON_IsNull(subject)) {
        subject = NULL;
    }
    if (subject) { 
    if(!cJSON_IsString(subject) && !cJSON_IsNull(subject))
    {
    goto end; //String
    }
    }


    if (assigned_to && !cJSON_IsNull(assigned_to)) assigned_to_local_str = strdup(assigned_to->valuestring);
    if (contact_id && !cJSON_IsNull(contact_id)) contact_id_local_str = strdup(contact_id->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (due_date) due_date_local_str = strdup(due_date->valuestring);
    if (reminder_date) reminder_date_local_str = strdup(reminder_date->valuestring);
    if (subject && !cJSON_IsNull(subject)) subject_local_str = strdup(subject->valuestring);

    activity_update_local_var = activity_update_create_internal (
        activity_type ? activity_type_local_nonprim : NULL,
        assigned_to_local_str,
        contact_id_local_str,
        description_local_str,
        due_date_local_str,
        reminder_date_local_str,
        status ? status_local_nonprim : NULL,
        subject_local_str
        );

    if (!activity_update_local_var) {
        goto end;
    }

    return activity_update_local_var;
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
