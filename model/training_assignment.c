#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "training_assignment.h"



static training_assignment_t *training_assignment_create_internal(
    char *assigned_by,
    char *created_at,
    char *deleted_at,
    char *due_date,
    char *employee_id,
    char *id,
    char *notes,
    simplebilly_api_assignment_status__e status,
    char *tenant_id,
    char *training_id,
    char *updated_at
    ) {
    training_assignment_t *training_assignment_local_var = malloc(sizeof(training_assignment_t));
    if (!training_assignment_local_var) {
        return NULL;
    }
    memset(training_assignment_local_var, 0, sizeof(training_assignment_t));
    training_assignment_local_var->_library_owned = 1;
    training_assignment_local_var->assigned_by = assigned_by;
    training_assignment_local_var->created_at = created_at;
    training_assignment_local_var->deleted_at = deleted_at;
    training_assignment_local_var->due_date = due_date;
    training_assignment_local_var->employee_id = employee_id;
    training_assignment_local_var->id = id;
    training_assignment_local_var->notes = notes;
    training_assignment_local_var->status = status;
    training_assignment_local_var->tenant_id = tenant_id;
    training_assignment_local_var->training_id = training_id;
    training_assignment_local_var->updated_at = updated_at;
    return training_assignment_local_var;
}

__attribute__((deprecated)) training_assignment_t *training_assignment_create(
    char *assigned_by,
    char *created_at,
    char *deleted_at,
    char *due_date,
    char *employee_id,
    char *id,
    char *notes,
    simplebilly_api_assignment_status__e status,
    char *tenant_id,
    char *training_id,
    char *updated_at
    ) {
    training_assignment_t *result = training_assignment_create_internal (
        assigned_by,
        created_at,
        deleted_at,
        due_date,
        employee_id,
        id,
        notes,
        status,
        tenant_id,
        training_id,
        updated_at
        );
    if (!result) {
    }
    return result;
}

void training_assignment_free(training_assignment_t *training_assignment) {
    if(NULL == training_assignment){
        return ;
    }
    if(training_assignment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "training_assignment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (training_assignment->assigned_by) {
        free(training_assignment->assigned_by);
        training_assignment->assigned_by = NULL;
    }
    if (training_assignment->created_at) {
        free(training_assignment->created_at);
        training_assignment->created_at = NULL;
    }
    if (training_assignment->deleted_at) {
        free(training_assignment->deleted_at);
        training_assignment->deleted_at = NULL;
    }
    if (training_assignment->due_date) {
        free(training_assignment->due_date);
        training_assignment->due_date = NULL;
    }
    if (training_assignment->employee_id) {
        free(training_assignment->employee_id);
        training_assignment->employee_id = NULL;
    }
    if (training_assignment->id) {
        free(training_assignment->id);
        training_assignment->id = NULL;
    }
    if (training_assignment->notes) {
        free(training_assignment->notes);
        training_assignment->notes = NULL;
    }
    if (training_assignment->tenant_id) {
        free(training_assignment->tenant_id);
        training_assignment->tenant_id = NULL;
    }
    if (training_assignment->training_id) {
        free(training_assignment->training_id);
        training_assignment->training_id = NULL;
    }
    if (training_assignment->updated_at) {
        free(training_assignment->updated_at);
        training_assignment->updated_at = NULL;
    }
    free(training_assignment);
}

cJSON *training_assignment_convertToJSON(training_assignment_t *training_assignment) {
    cJSON *item = cJSON_CreateObject();

    // training_assignment->assigned_by
    if(training_assignment->assigned_by) {
    if(cJSON_AddStringToObject(item, "assignedBy", training_assignment->assigned_by) == NULL) {
    goto fail; //String
    }
    }


    // training_assignment->created_at
    if(training_assignment->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", training_assignment->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // training_assignment->deleted_at
    if(training_assignment->deleted_at) {
    if(cJSON_AddStringToObject(item, "deletedAt", training_assignment->deleted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // training_assignment->due_date
    if(training_assignment->due_date) {
    if(cJSON_AddStringToObject(item, "dueDate", training_assignment->due_date) == NULL) {
    goto fail; //Date
    }
    }


    // training_assignment->employee_id
    if(training_assignment->employee_id) {
    if(cJSON_AddStringToObject(item, "employeeId", training_assignment->employee_id) == NULL) {
    goto fail; //String
    }
    }


    // training_assignment->id
    if(training_assignment->id) {
    if(cJSON_AddStringToObject(item, "id", training_assignment->id) == NULL) {
    goto fail; //String
    }
    }


    // training_assignment->notes
    if(training_assignment->notes) {
    if(cJSON_AddStringToObject(item, "notes", training_assignment->notes) == NULL) {
    goto fail; //String
    }
    }


    // training_assignment->status
    if(training_assignment->status != simplebilly_api_assignment_status__NULL) {
    cJSON *status_local_JSON = assignment_status_convertToJSON(training_assignment->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // training_assignment->tenant_id
    if(training_assignment->tenant_id) {
    if(cJSON_AddStringToObject(item, "tenantId", training_assignment->tenant_id) == NULL) {
    goto fail; //String
    }
    }


    // training_assignment->training_id
    if(training_assignment->training_id) {
    if(cJSON_AddStringToObject(item, "trainingId", training_assignment->training_id) == NULL) {
    goto fail; //String
    }
    }


    // training_assignment->updated_at
    if(training_assignment->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", training_assignment->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

training_assignment_t *training_assignment_parseFromJSON(cJSON *training_assignmentJSON){

    training_assignment_t *training_assignment_local_var = NULL;

    char *assigned_by_local_str = NULL;

    char *created_at_local_str = NULL;

    char *deleted_at_local_str = NULL;

    char *due_date_local_str = NULL;

    char *employee_id_local_str = NULL;

    char *id_local_str = NULL;

    char *notes_local_str = NULL;

    // define the local variable for training_assignment->status
    simplebilly_api_assignment_status__e status_local_nonprim = 0;

    char *tenant_id_local_str = NULL;

    char *training_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    // training_assignment->assigned_by
    cJSON *assigned_by = cJSON_GetObjectItemCaseSensitive(training_assignmentJSON, "assignedBy");
    if (cJSON_IsNull(assigned_by)) {
        assigned_by = NULL;
    }
    if (assigned_by) { 
    if(!cJSON_IsString(assigned_by) && !cJSON_IsNull(assigned_by))
    {
    goto end; //String
    }
    }

    // training_assignment->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(training_assignmentJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // training_assignment->deleted_at
    cJSON *deleted_at = cJSON_GetObjectItemCaseSensitive(training_assignmentJSON, "deletedAt");
    if (cJSON_IsNull(deleted_at)) {
        deleted_at = NULL;
    }
    if (deleted_at) { 
    if(!cJSON_IsString(deleted_at) && !cJSON_IsNull(deleted_at))
    {
    goto end; //DateTime
    }
    }

    // training_assignment->due_date
    cJSON *due_date = cJSON_GetObjectItemCaseSensitive(training_assignmentJSON, "dueDate");
    if (cJSON_IsNull(due_date)) {
        due_date = NULL;
    }
    if (due_date) { 
    if(!cJSON_IsString(due_date))
    {
    goto end; //Date
    }
    }

    // training_assignment->employee_id
    cJSON *employee_id = cJSON_GetObjectItemCaseSensitive(training_assignmentJSON, "employeeId");
    if (cJSON_IsNull(employee_id)) {
        employee_id = NULL;
    }
    if (employee_id) { 
    if(!cJSON_IsString(employee_id) && !cJSON_IsNull(employee_id))
    {
    goto end; //String
    }
    }

    // training_assignment->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(training_assignmentJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // training_assignment->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(training_assignmentJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // training_assignment->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(training_assignmentJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = assignment_status_parseFromJSON(status); //custom
    }

    // training_assignment->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(training_assignmentJSON, "tenantId");
    if (cJSON_IsNull(tenant_id)) {
        tenant_id = NULL;
    }
    if (tenant_id) { 
    if(!cJSON_IsString(tenant_id) && !cJSON_IsNull(tenant_id))
    {
    goto end; //String
    }
    }

    // training_assignment->training_id
    cJSON *training_id = cJSON_GetObjectItemCaseSensitive(training_assignmentJSON, "trainingId");
    if (cJSON_IsNull(training_id)) {
        training_id = NULL;
    }
    if (training_id) { 
    if(!cJSON_IsString(training_id) && !cJSON_IsNull(training_id))
    {
    goto end; //String
    }
    }

    // training_assignment->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(training_assignmentJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    if (assigned_by && !cJSON_IsNull(assigned_by)) assigned_by_local_str = strdup(assigned_by->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (deleted_at && !cJSON_IsNull(deleted_at)) deleted_at_local_str = strdup(deleted_at->valuestring);
    if (due_date) due_date_local_str = strdup(due_date->valuestring);
    if (employee_id && !cJSON_IsNull(employee_id)) employee_id_local_str = strdup(employee_id->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (training_id && !cJSON_IsNull(training_id)) training_id_local_str = strdup(training_id->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    training_assignment_local_var = training_assignment_create_internal (
        assigned_by_local_str,
        created_at_local_str,
        deleted_at_local_str,
        due_date_local_str,
        employee_id_local_str,
        id_local_str,
        notes_local_str,
        status ? status_local_nonprim : 0,
        tenant_id_local_str,
        training_id_local_str,
        updated_at_local_str
        );

    if (!training_assignment_local_var) {
        goto end;
    }

    return training_assignment_local_var;
end:
    if (assigned_by_local_str) {
        free(assigned_by_local_str);
        assigned_by_local_str = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (deleted_at_local_str) {
        free(deleted_at_local_str);
        deleted_at_local_str = NULL;
    }
    if (due_date_local_str) {
        free(due_date_local_str);
        due_date_local_str = NULL;
    }
    if (employee_id_local_str) {
        free(employee_id_local_str);
        employee_id_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (training_id_local_str) {
        free(training_id_local_str);
        training_id_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    return NULL;

}
