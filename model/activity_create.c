#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_create.h"



static activity_create_t *activity_create_create_internal(
    activity_type_t *activity_type,
    char *assigned_to,
    char *contact_id,
    char *description,
    char *due_date,
    char *reminder_date,
    activity_status_t *status,
    char *subject
    ) {
    activity_create_t *activity_create_local_var = malloc(sizeof(activity_create_t));
    if (!activity_create_local_var) {
        return NULL;
    }
    memset(activity_create_local_var, 0, sizeof(activity_create_t));
    activity_create_local_var->_library_owned = 1;
    activity_create_local_var->activity_type = activity_type;
    activity_create_local_var->assigned_to = assigned_to;
    activity_create_local_var->contact_id = contact_id;
    activity_create_local_var->description = description;
    activity_create_local_var->due_date = due_date;
    activity_create_local_var->reminder_date = reminder_date;
    activity_create_local_var->status = status;
    activity_create_local_var->subject = subject;
    return activity_create_local_var;
}

__attribute__((deprecated)) activity_create_t *activity_create_create(
    activity_type_t *activity_type,
    char *assigned_to,
    char *contact_id,
    char *description,
    char *due_date,
    char *reminder_date,
    activity_status_t *status,
    char *subject
    ) {
    activity_create_t *result = activity_create_create_internal (
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

void activity_create_free(activity_create_t *activity_create) {
    if(NULL == activity_create){
        return ;
    }
    if(activity_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_create->activity_type) {
        activity_type_free(activity_create->activity_type);
        activity_create->activity_type = NULL;
    }
    if (activity_create->assigned_to) {
        free(activity_create->assigned_to);
        activity_create->assigned_to = NULL;
    }
    if (activity_create->contact_id) {
        free(activity_create->contact_id);
        activity_create->contact_id = NULL;
    }
    if (activity_create->description) {
        free(activity_create->description);
        activity_create->description = NULL;
    }
    if (activity_create->due_date) {
        free(activity_create->due_date);
        activity_create->due_date = NULL;
    }
    if (activity_create->reminder_date) {
        free(activity_create->reminder_date);
        activity_create->reminder_date = NULL;
    }
    if (activity_create->status) {
        activity_status_free(activity_create->status);
        activity_create->status = NULL;
    }
    if (activity_create->subject) {
        free(activity_create->subject);
        activity_create->subject = NULL;
    }
    free(activity_create);
}

cJSON *activity_create_convertToJSON(activity_create_t *activity_create) {
    cJSON *item = cJSON_CreateObject();

    // activity_create->activity_type
    if (!activity_create->activity_type) {
        goto fail;
    }
    cJSON *activity_type_local_JSON = activity_type_convertToJSON(activity_create->activity_type);
    if(activity_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "activityType", activity_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // activity_create->assigned_to
    if(activity_create->assigned_to) {
    if(cJSON_AddStringToObject(item, "assignedTo", activity_create->assigned_to) == NULL) {
    goto fail; //String
    }
    }


    // activity_create->contact_id
    if(activity_create->contact_id) {
    if(cJSON_AddStringToObject(item, "contactId", activity_create->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // activity_create->description
    if(activity_create->description) {
    if(cJSON_AddStringToObject(item, "description", activity_create->description) == NULL) {
    goto fail; //String
    }
    }


    // activity_create->due_date
    if(activity_create->due_date) {
    if(cJSON_AddStringToObject(item, "dueDate", activity_create->due_date) == NULL) {
    goto fail; //Date
    }
    }


    // activity_create->reminder_date
    if(activity_create->reminder_date) {
    if(cJSON_AddStringToObject(item, "reminderDate", activity_create->reminder_date) == NULL) {
    goto fail; //Date
    }
    }


    // activity_create->status
    if (!activity_create->status) {
        goto fail;
    }
    cJSON *status_local_JSON = activity_status_convertToJSON(activity_create->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // activity_create->subject
    if (!activity_create->subject) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "subject", activity_create->subject) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

activity_create_t *activity_create_parseFromJSON(cJSON *activity_createJSON){

    activity_create_t *activity_create_local_var = NULL;

    // define the local variable for activity_create->activity_type
    activity_type_t *activity_type_local_nonprim = NULL;

    char *assigned_to_local_str = NULL;

    char *contact_id_local_str = NULL;

    char *description_local_str = NULL;

    char *due_date_local_str = NULL;

    char *reminder_date_local_str = NULL;

    // define the local variable for activity_create->status
    activity_status_t *status_local_nonprim = NULL;

    char *subject_local_str = NULL;

    // activity_create->activity_type
    cJSON *activity_type = cJSON_GetObjectItemCaseSensitive(activity_createJSON, "activityType");
    if (cJSON_IsNull(activity_type)) {
        activity_type = NULL;
    }
    if (!activity_type) {
        goto end;
    }

    
    activity_type_local_nonprim = activity_type_parseFromJSON(activity_type); //custom

    // activity_create->assigned_to
    cJSON *assigned_to = cJSON_GetObjectItemCaseSensitive(activity_createJSON, "assignedTo");
    if (cJSON_IsNull(assigned_to)) {
        assigned_to = NULL;
    }
    if (assigned_to) { 
    if(!cJSON_IsString(assigned_to) && !cJSON_IsNull(assigned_to))
    {
    goto end; //String
    }
    }

    // activity_create->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(activity_createJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // activity_create->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(activity_createJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // activity_create->due_date
    cJSON *due_date = cJSON_GetObjectItemCaseSensitive(activity_createJSON, "dueDate");
    if (cJSON_IsNull(due_date)) {
        due_date = NULL;
    }
    if (due_date) { 
    if(!cJSON_IsString(due_date))
    {
    goto end; //Date
    }
    }

    // activity_create->reminder_date
    cJSON *reminder_date = cJSON_GetObjectItemCaseSensitive(activity_createJSON, "reminderDate");
    if (cJSON_IsNull(reminder_date)) {
        reminder_date = NULL;
    }
    if (reminder_date) { 
    if(!cJSON_IsString(reminder_date))
    {
    goto end; //Date
    }
    }

    // activity_create->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(activity_createJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = activity_status_parseFromJSON(status); //custom

    // activity_create->subject
    cJSON *subject = cJSON_GetObjectItemCaseSensitive(activity_createJSON, "subject");
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

    activity_create_local_var = activity_create_create_internal (
        activity_type_local_nonprim,
        assigned_to_local_str,
        contact_id_local_str,
        description_local_str,
        due_date_local_str,
        reminder_date_local_str,
        status_local_nonprim,
        subject_local_str
        );

    if (!activity_create_local_var) {
        goto end;
    }

    return activity_create_local_var;
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
