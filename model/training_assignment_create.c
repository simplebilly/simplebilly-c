#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "training_assignment_create.h"



static training_assignment_create_t *training_assignment_create_create_internal(
    char *assigned_by,
    char *due_date,
    char *employee_id,
    char *notes,
    simplebilly_api_assignment_status__e status,
    char *training_id
    ) {
    training_assignment_create_t *training_assignment_create_local_var = malloc(sizeof(training_assignment_create_t));
    if (!training_assignment_create_local_var) {
        return NULL;
    }
    memset(training_assignment_create_local_var, 0, sizeof(training_assignment_create_t));
    training_assignment_create_local_var->_library_owned = 1;
    training_assignment_create_local_var->assigned_by = assigned_by;
    training_assignment_create_local_var->due_date = due_date;
    training_assignment_create_local_var->employee_id = employee_id;
    training_assignment_create_local_var->notes = notes;
    training_assignment_create_local_var->status = status;
    training_assignment_create_local_var->training_id = training_id;
    return training_assignment_create_local_var;
}

__attribute__((deprecated)) training_assignment_create_t *training_assignment_create_create(
    char *assigned_by,
    char *due_date,
    char *employee_id,
    char *notes,
    simplebilly_api_assignment_status__e status,
    char *training_id
    ) {
    training_assignment_create_t *result = training_assignment_create_create_internal (
        assigned_by,
        due_date,
        employee_id,
        notes,
        status,
        training_id
        );
    if (!result) {
    }
    return result;
}

void training_assignment_create_free(training_assignment_create_t *training_assignment_create) {
    if(NULL == training_assignment_create){
        return ;
    }
    if(training_assignment_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "training_assignment_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (training_assignment_create->assigned_by) {
        free(training_assignment_create->assigned_by);
        training_assignment_create->assigned_by = NULL;
    }
    if (training_assignment_create->due_date) {
        free(training_assignment_create->due_date);
        training_assignment_create->due_date = NULL;
    }
    if (training_assignment_create->employee_id) {
        free(training_assignment_create->employee_id);
        training_assignment_create->employee_id = NULL;
    }
    if (training_assignment_create->notes) {
        free(training_assignment_create->notes);
        training_assignment_create->notes = NULL;
    }
    if (training_assignment_create->training_id) {
        free(training_assignment_create->training_id);
        training_assignment_create->training_id = NULL;
    }
    free(training_assignment_create);
}

cJSON *training_assignment_create_convertToJSON(training_assignment_create_t *training_assignment_create) {
    cJSON *item = cJSON_CreateObject();

    // training_assignment_create->assigned_by
    if(training_assignment_create->assigned_by) {
    if(cJSON_AddStringToObject(item, "assignedBy", training_assignment_create->assigned_by) == NULL) {
    goto fail; //String
    }
    }


    // training_assignment_create->due_date
    if(training_assignment_create->due_date) {
    if(cJSON_AddStringToObject(item, "dueDate", training_assignment_create->due_date) == NULL) {
    goto fail; //Date
    }
    }


    // training_assignment_create->employee_id
    if(training_assignment_create->employee_id) {
    if(cJSON_AddStringToObject(item, "employeeId", training_assignment_create->employee_id) == NULL) {
    goto fail; //String
    }
    }


    // training_assignment_create->notes
    if(training_assignment_create->notes) {
    if(cJSON_AddStringToObject(item, "notes", training_assignment_create->notes) == NULL) {
    goto fail; //String
    }
    }


    // training_assignment_create->status
    if(training_assignment_create->status != simplebilly_api_assignment_status__NULL) {
    cJSON *status_local_JSON = assignment_status_convertToJSON(training_assignment_create->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // training_assignment_create->training_id
    if(training_assignment_create->training_id) {
    if(cJSON_AddStringToObject(item, "trainingId", training_assignment_create->training_id) == NULL) {
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

training_assignment_create_t *training_assignment_create_parseFromJSON(cJSON *training_assignment_createJSON){

    training_assignment_create_t *training_assignment_create_local_var = NULL;

    char *assigned_by_local_str = NULL;

    char *due_date_local_str = NULL;

    char *employee_id_local_str = NULL;

    char *notes_local_str = NULL;

    // define the local variable for training_assignment_create->status
    simplebilly_api_assignment_status__e status_local_nonprim = 0;

    char *training_id_local_str = NULL;

    // training_assignment_create->assigned_by
    cJSON *assigned_by = cJSON_GetObjectItemCaseSensitive(training_assignment_createJSON, "assignedBy");
    if (cJSON_IsNull(assigned_by)) {
        assigned_by = NULL;
    }
    if (assigned_by) { 
    if(!cJSON_IsString(assigned_by) && !cJSON_IsNull(assigned_by))
    {
    goto end; //String
    }
    }

    // training_assignment_create->due_date
    cJSON *due_date = cJSON_GetObjectItemCaseSensitive(training_assignment_createJSON, "dueDate");
    if (cJSON_IsNull(due_date)) {
        due_date = NULL;
    }
    if (due_date) { 
    if(!cJSON_IsString(due_date))
    {
    goto end; //Date
    }
    }

    // training_assignment_create->employee_id
    cJSON *employee_id = cJSON_GetObjectItemCaseSensitive(training_assignment_createJSON, "employeeId");
    if (cJSON_IsNull(employee_id)) {
        employee_id = NULL;
    }
    if (employee_id) { 
    if(!cJSON_IsString(employee_id) && !cJSON_IsNull(employee_id))
    {
    goto end; //String
    }
    }

    // training_assignment_create->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(training_assignment_createJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // training_assignment_create->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(training_assignment_createJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = assignment_status_parseFromJSON(status); //custom
    }

    // training_assignment_create->training_id
    cJSON *training_id = cJSON_GetObjectItemCaseSensitive(training_assignment_createJSON, "trainingId");
    if (cJSON_IsNull(training_id)) {
        training_id = NULL;
    }
    if (training_id) { 
    if(!cJSON_IsString(training_id) && !cJSON_IsNull(training_id))
    {
    goto end; //String
    }
    }


    if (assigned_by && !cJSON_IsNull(assigned_by)) assigned_by_local_str = strdup(assigned_by->valuestring);
    if (due_date) due_date_local_str = strdup(due_date->valuestring);
    if (employee_id && !cJSON_IsNull(employee_id)) employee_id_local_str = strdup(employee_id->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (training_id && !cJSON_IsNull(training_id)) training_id_local_str = strdup(training_id->valuestring);

    training_assignment_create_local_var = training_assignment_create_create_internal (
        assigned_by_local_str,
        due_date_local_str,
        employee_id_local_str,
        notes_local_str,
        status ? status_local_nonprim : 0,
        training_id_local_str
        );

    if (!training_assignment_create_local_var) {
        goto end;
    }

    return training_assignment_create_local_var;
end:
    if (assigned_by_local_str) {
        free(assigned_by_local_str);
        assigned_by_local_str = NULL;
    }
    if (due_date_local_str) {
        free(due_date_local_str);
        due_date_local_str = NULL;
    }
    if (employee_id_local_str) {
        free(employee_id_local_str);
        employee_id_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    if (training_id_local_str) {
        free(training_id_local_str);
        training_id_local_str = NULL;
    }
    return NULL;

}
