#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "absence_create.h"



static absence_create_t *absence_create_create_internal(
    absence_type_t *absence_type,
    char *approved_at,
    char *approved_by,
    char *employee_id,
    char *end_date,
    char *notes,
    char *start_date,
    absence_status_t *status
    ) {
    absence_create_t *absence_create_local_var = malloc(sizeof(absence_create_t));
    if (!absence_create_local_var) {
        return NULL;
    }
    memset(absence_create_local_var, 0, sizeof(absence_create_t));
    absence_create_local_var->_library_owned = 1;
    absence_create_local_var->absence_type = absence_type;
    absence_create_local_var->approved_at = approved_at;
    absence_create_local_var->approved_by = approved_by;
    absence_create_local_var->employee_id = employee_id;
    absence_create_local_var->end_date = end_date;
    absence_create_local_var->notes = notes;
    absence_create_local_var->start_date = start_date;
    absence_create_local_var->status = status;
    return absence_create_local_var;
}

__attribute__((deprecated)) absence_create_t *absence_create_create(
    absence_type_t *absence_type,
    char *approved_at,
    char *approved_by,
    char *employee_id,
    char *end_date,
    char *notes,
    char *start_date,
    absence_status_t *status
    ) {
    absence_create_t *result = absence_create_create_internal (
        absence_type,
        approved_at,
        approved_by,
        employee_id,
        end_date,
        notes,
        start_date,
        status
        );
    if (!result) {
    }
    return result;
}

void absence_create_free(absence_create_t *absence_create) {
    if(NULL == absence_create){
        return ;
    }
    if(absence_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "absence_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (absence_create->absence_type) {
        absence_type_free(absence_create->absence_type);
        absence_create->absence_type = NULL;
    }
    if (absence_create->approved_at) {
        free(absence_create->approved_at);
        absence_create->approved_at = NULL;
    }
    if (absence_create->approved_by) {
        free(absence_create->approved_by);
        absence_create->approved_by = NULL;
    }
    if (absence_create->employee_id) {
        free(absence_create->employee_id);
        absence_create->employee_id = NULL;
    }
    if (absence_create->end_date) {
        free(absence_create->end_date);
        absence_create->end_date = NULL;
    }
    if (absence_create->notes) {
        free(absence_create->notes);
        absence_create->notes = NULL;
    }
    if (absence_create->start_date) {
        free(absence_create->start_date);
        absence_create->start_date = NULL;
    }
    if (absence_create->status) {
        absence_status_free(absence_create->status);
        absence_create->status = NULL;
    }
    free(absence_create);
}

cJSON *absence_create_convertToJSON(absence_create_t *absence_create) {
    cJSON *item = cJSON_CreateObject();

    // absence_create->absence_type
    if(absence_create->absence_type) {
    cJSON *absence_type_local_JSON = absence_type_convertToJSON(absence_create->absence_type);
    if(absence_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "absenceType", absence_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // absence_create->approved_at
    if(absence_create->approved_at) {
    if(cJSON_AddStringToObject(item, "approvedAt", absence_create->approved_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // absence_create->approved_by
    if(absence_create->approved_by) {
    if(cJSON_AddStringToObject(item, "approvedBy", absence_create->approved_by) == NULL) {
    goto fail; //String
    }
    }


    // absence_create->employee_id
    if(absence_create->employee_id) {
    if(cJSON_AddStringToObject(item, "employeeId", absence_create->employee_id) == NULL) {
    goto fail; //String
    }
    }


    // absence_create->end_date
    if(absence_create->end_date) {
    if(cJSON_AddStringToObject(item, "endDate", absence_create->end_date) == NULL) {
    goto fail; //Date
    }
    }


    // absence_create->notes
    if(absence_create->notes) {
    if(cJSON_AddStringToObject(item, "notes", absence_create->notes) == NULL) {
    goto fail; //String
    }
    }


    // absence_create->start_date
    if(absence_create->start_date) {
    if(cJSON_AddStringToObject(item, "startDate", absence_create->start_date) == NULL) {
    goto fail; //Date
    }
    }


    // absence_create->status
    if(absence_create->status) {
    cJSON *status_local_JSON = absence_status_convertToJSON(absence_create->status);
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

absence_create_t *absence_create_parseFromJSON(cJSON *absence_createJSON){

    absence_create_t *absence_create_local_var = NULL;

    // define the local variable for absence_create->absence_type
    absence_type_t *absence_type_local_nonprim = NULL;

    char *approved_at_local_str = NULL;

    char *approved_by_local_str = NULL;

    char *employee_id_local_str = NULL;

    char *end_date_local_str = NULL;

    char *notes_local_str = NULL;

    char *start_date_local_str = NULL;

    // define the local variable for absence_create->status
    absence_status_t *status_local_nonprim = NULL;

    // absence_create->absence_type
    cJSON *absence_type = cJSON_GetObjectItemCaseSensitive(absence_createJSON, "absenceType");
    if (cJSON_IsNull(absence_type)) {
        absence_type = NULL;
    }
    if (absence_type) { 
    absence_type_local_nonprim = absence_type_parseFromJSON(absence_type); //custom
    }

    // absence_create->approved_at
    cJSON *approved_at = cJSON_GetObjectItemCaseSensitive(absence_createJSON, "approvedAt");
    if (cJSON_IsNull(approved_at)) {
        approved_at = NULL;
    }
    if (approved_at) { 
    if(!cJSON_IsString(approved_at) && !cJSON_IsNull(approved_at))
    {
    goto end; //DateTime
    }
    }

    // absence_create->approved_by
    cJSON *approved_by = cJSON_GetObjectItemCaseSensitive(absence_createJSON, "approvedBy");
    if (cJSON_IsNull(approved_by)) {
        approved_by = NULL;
    }
    if (approved_by) { 
    if(!cJSON_IsString(approved_by) && !cJSON_IsNull(approved_by))
    {
    goto end; //String
    }
    }

    // absence_create->employee_id
    cJSON *employee_id = cJSON_GetObjectItemCaseSensitive(absence_createJSON, "employeeId");
    if (cJSON_IsNull(employee_id)) {
        employee_id = NULL;
    }
    if (employee_id) { 
    if(!cJSON_IsString(employee_id) && !cJSON_IsNull(employee_id))
    {
    goto end; //String
    }
    }

    // absence_create->end_date
    cJSON *end_date = cJSON_GetObjectItemCaseSensitive(absence_createJSON, "endDate");
    if (cJSON_IsNull(end_date)) {
        end_date = NULL;
    }
    if (end_date) { 
    if(!cJSON_IsString(end_date))
    {
    goto end; //Date
    }
    }

    // absence_create->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(absence_createJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // absence_create->start_date
    cJSON *start_date = cJSON_GetObjectItemCaseSensitive(absence_createJSON, "startDate");
    if (cJSON_IsNull(start_date)) {
        start_date = NULL;
    }
    if (start_date) { 
    if(!cJSON_IsString(start_date))
    {
    goto end; //Date
    }
    }

    // absence_create->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(absence_createJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = absence_status_parseFromJSON(status); //custom
    }


    if (approved_at && !cJSON_IsNull(approved_at)) approved_at_local_str = strdup(approved_at->valuestring);
    if (approved_by && !cJSON_IsNull(approved_by)) approved_by_local_str = strdup(approved_by->valuestring);
    if (employee_id && !cJSON_IsNull(employee_id)) employee_id_local_str = strdup(employee_id->valuestring);
    if (end_date) end_date_local_str = strdup(end_date->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (start_date) start_date_local_str = strdup(start_date->valuestring);

    absence_create_local_var = absence_create_create_internal (
        absence_type ? absence_type_local_nonprim : NULL,
        approved_at_local_str,
        approved_by_local_str,
        employee_id_local_str,
        end_date_local_str,
        notes_local_str,
        start_date_local_str,
        status ? status_local_nonprim : NULL
        );

    if (!absence_create_local_var) {
        goto end;
    }

    return absence_create_local_var;
end:
    if (absence_type_local_nonprim) {
        absence_type_free(absence_type_local_nonprim);
        absence_type_local_nonprim = NULL;
    }
    if (approved_at_local_str) {
        free(approved_at_local_str);
        approved_at_local_str = NULL;
    }
    if (approved_by_local_str) {
        free(approved_by_local_str);
        approved_by_local_str = NULL;
    }
    if (employee_id_local_str) {
        free(employee_id_local_str);
        employee_id_local_str = NULL;
    }
    if (end_date_local_str) {
        free(end_date_local_str);
        end_date_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (start_date_local_str) {
        free(start_date_local_str);
        start_date_local_str = NULL;
    }
    if (status_local_nonprim) {
        absence_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
