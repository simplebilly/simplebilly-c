#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_assignment.h"



static service_assignment_t *service_assignment_create_internal(
    char *employee_id,
    char *job_id,
    char *notes,
    char *scheduled_date,
    char *scheduled_end,
    char *scheduled_start,
    service_assignment_status_t *status
    ) {
    service_assignment_t *service_assignment_local_var = malloc(sizeof(service_assignment_t));
    if (!service_assignment_local_var) {
        return NULL;
    }
    memset(service_assignment_local_var, 0, sizeof(service_assignment_t));
    service_assignment_local_var->_library_owned = 1;
    service_assignment_local_var->employee_id = employee_id;
    service_assignment_local_var->job_id = job_id;
    service_assignment_local_var->notes = notes;
    service_assignment_local_var->scheduled_date = scheduled_date;
    service_assignment_local_var->scheduled_end = scheduled_end;
    service_assignment_local_var->scheduled_start = scheduled_start;
    service_assignment_local_var->status = status;
    return service_assignment_local_var;
}

__attribute__((deprecated)) service_assignment_t *service_assignment_create(
    char *employee_id,
    char *job_id,
    char *notes,
    char *scheduled_date,
    char *scheduled_end,
    char *scheduled_start,
    service_assignment_status_t *status
    ) {
    service_assignment_t *result = service_assignment_create_internal (
        employee_id,
        job_id,
        notes,
        scheduled_date,
        scheduled_end,
        scheduled_start,
        status
        );
    if (!result) {
    }
    return result;
}

void service_assignment_free(service_assignment_t *service_assignment) {
    if(NULL == service_assignment){
        return ;
    }
    if(service_assignment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "service_assignment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (service_assignment->employee_id) {
        free(service_assignment->employee_id);
        service_assignment->employee_id = NULL;
    }
    if (service_assignment->job_id) {
        free(service_assignment->job_id);
        service_assignment->job_id = NULL;
    }
    if (service_assignment->notes) {
        free(service_assignment->notes);
        service_assignment->notes = NULL;
    }
    if (service_assignment->scheduled_date) {
        free(service_assignment->scheduled_date);
        service_assignment->scheduled_date = NULL;
    }
    if (service_assignment->scheduled_end) {
        free(service_assignment->scheduled_end);
        service_assignment->scheduled_end = NULL;
    }
    if (service_assignment->scheduled_start) {
        free(service_assignment->scheduled_start);
        service_assignment->scheduled_start = NULL;
    }
    if (service_assignment->status) {
        service_assignment_status_free(service_assignment->status);
        service_assignment->status = NULL;
    }
    free(service_assignment);
}

cJSON *service_assignment_convertToJSON(service_assignment_t *service_assignment) {
    cJSON *item = cJSON_CreateObject();

    // service_assignment->employee_id
    if(service_assignment->employee_id) {
    if(cJSON_AddStringToObject(item, "employeeId", service_assignment->employee_id) == NULL) {
    goto fail; //String
    }
    }


    // service_assignment->job_id
    if(service_assignment->job_id) {
    if(cJSON_AddStringToObject(item, "jobId", service_assignment->job_id) == NULL) {
    goto fail; //String
    }
    }


    // service_assignment->notes
    if(service_assignment->notes) {
    if(cJSON_AddStringToObject(item, "notes", service_assignment->notes) == NULL) {
    goto fail; //String
    }
    }


    // service_assignment->scheduled_date
    if(service_assignment->scheduled_date) {
    if(cJSON_AddStringToObject(item, "scheduledDate", service_assignment->scheduled_date) == NULL) {
    goto fail; //Date
    }
    }


    // service_assignment->scheduled_end
    if(service_assignment->scheduled_end) {
    if(cJSON_AddStringToObject(item, "scheduledEnd", service_assignment->scheduled_end) == NULL) {
    goto fail; //String
    }
    }


    // service_assignment->scheduled_start
    if(service_assignment->scheduled_start) {
    if(cJSON_AddStringToObject(item, "scheduledStart", service_assignment->scheduled_start) == NULL) {
    goto fail; //String
    }
    }


    // service_assignment->status
    if(service_assignment->status) {
    cJSON *status_local_JSON = service_assignment_status_convertToJSON(service_assignment->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

service_assignment_t *service_assignment_parseFromJSON(cJSON *service_assignmentJSON){

    service_assignment_t *service_assignment_local_var = NULL;

    char *employee_id_local_str = NULL;

    char *job_id_local_str = NULL;

    char *notes_local_str = NULL;

    char *scheduled_date_local_str = NULL;

    char *scheduled_end_local_str = NULL;

    char *scheduled_start_local_str = NULL;

    // define the local variable for service_assignment->status
    service_assignment_status_t *status_local_nonprim = NULL;

    // service_assignment->employee_id
    cJSON *employee_id = cJSON_GetObjectItemCaseSensitive(service_assignmentJSON, "employeeId");
    if (cJSON_IsNull(employee_id)) {
        employee_id = NULL;
    }
    if (employee_id) { 
    if(!cJSON_IsString(employee_id) && !cJSON_IsNull(employee_id))
    {
    goto end; //String
    }
    }

    // service_assignment->job_id
    cJSON *job_id = cJSON_GetObjectItemCaseSensitive(service_assignmentJSON, "jobId");
    if (cJSON_IsNull(job_id)) {
        job_id = NULL;
    }
    if (job_id) { 
    if(!cJSON_IsString(job_id) && !cJSON_IsNull(job_id))
    {
    goto end; //String
    }
    }

    // service_assignment->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(service_assignmentJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // service_assignment->scheduled_date
    cJSON *scheduled_date = cJSON_GetObjectItemCaseSensitive(service_assignmentJSON, "scheduledDate");
    if (cJSON_IsNull(scheduled_date)) {
        scheduled_date = NULL;
    }
    if (scheduled_date) { 
    if(!cJSON_IsString(scheduled_date))
    {
    goto end; //Date
    }
    }

    // service_assignment->scheduled_end
    cJSON *scheduled_end = cJSON_GetObjectItemCaseSensitive(service_assignmentJSON, "scheduledEnd");
    if (cJSON_IsNull(scheduled_end)) {
        scheduled_end = NULL;
    }
    if (scheduled_end) { 
    if(!cJSON_IsString(scheduled_end) && !cJSON_IsNull(scheduled_end))
    {
    goto end; //String
    }
    }

    // service_assignment->scheduled_start
    cJSON *scheduled_start = cJSON_GetObjectItemCaseSensitive(service_assignmentJSON, "scheduledStart");
    if (cJSON_IsNull(scheduled_start)) {
        scheduled_start = NULL;
    }
    if (scheduled_start) { 
    if(!cJSON_IsString(scheduled_start) && !cJSON_IsNull(scheduled_start))
    {
    goto end; //String
    }
    }

    // service_assignment->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(service_assignmentJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = service_assignment_status_parseFromJSON(status); //custom
    }


    if (employee_id && !cJSON_IsNull(employee_id)) employee_id_local_str = strdup(employee_id->valuestring);
    if (job_id && !cJSON_IsNull(job_id)) job_id_local_str = strdup(job_id->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (scheduled_date) scheduled_date_local_str = strdup(scheduled_date->valuestring);
    if (scheduled_end && !cJSON_IsNull(scheduled_end)) scheduled_end_local_str = strdup(scheduled_end->valuestring);
    if (scheduled_start && !cJSON_IsNull(scheduled_start)) scheduled_start_local_str = strdup(scheduled_start->valuestring);

    service_assignment_local_var = service_assignment_create_internal (
        employee_id_local_str,
        job_id_local_str,
        notes_local_str,
        scheduled_date_local_str,
        scheduled_end_local_str,
        scheduled_start_local_str,
        status ? status_local_nonprim : NULL
        );

    if (!service_assignment_local_var) {
        goto end;
    }

    return service_assignment_local_var;
end:
    if (employee_id_local_str) {
        free(employee_id_local_str);
        employee_id_local_str = NULL;
    }
    if (job_id_local_str) {
        free(job_id_local_str);
        job_id_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (scheduled_date_local_str) {
        free(scheduled_date_local_str);
        scheduled_date_local_str = NULL;
    }
    if (scheduled_end_local_str) {
        free(scheduled_end_local_str);
        scheduled_end_local_str = NULL;
    }
    if (scheduled_start_local_str) {
        free(scheduled_start_local_str);
        scheduled_start_local_str = NULL;
    }
    if (status_local_nonprim) {
        service_assignment_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
