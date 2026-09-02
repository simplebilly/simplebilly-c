#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "absence.h"



static absence_t *absence_create_internal(
    absence_type_t *absence_type,
    char *approved_at,
    char *approved_by,
    char *created_at,
    char *deleted_at,
    char *employee_id,
    char *end_date,
    char *id,
    char *notes,
    char *start_date,
    absence_status_t *status,
    char *tenant_id,
    char *updated_at
    ) {
    absence_t *absence_local_var = malloc(sizeof(absence_t));
    if (!absence_local_var) {
        return NULL;
    }
    memset(absence_local_var, 0, sizeof(absence_t));
    absence_local_var->_library_owned = 1;
    absence_local_var->absence_type = absence_type;
    absence_local_var->approved_at = approved_at;
    absence_local_var->approved_by = approved_by;
    absence_local_var->created_at = created_at;
    absence_local_var->deleted_at = deleted_at;
    absence_local_var->employee_id = employee_id;
    absence_local_var->end_date = end_date;
    absence_local_var->id = id;
    absence_local_var->notes = notes;
    absence_local_var->start_date = start_date;
    absence_local_var->status = status;
    absence_local_var->tenant_id = tenant_id;
    absence_local_var->updated_at = updated_at;
    return absence_local_var;
}

__attribute__((deprecated)) absence_t *absence_create(
    absence_type_t *absence_type,
    char *approved_at,
    char *approved_by,
    char *created_at,
    char *deleted_at,
    char *employee_id,
    char *end_date,
    char *id,
    char *notes,
    char *start_date,
    absence_status_t *status,
    char *tenant_id,
    char *updated_at
    ) {
    absence_t *result = absence_create_internal (
        absence_type,
        approved_at,
        approved_by,
        created_at,
        deleted_at,
        employee_id,
        end_date,
        id,
        notes,
        start_date,
        status,
        tenant_id,
        updated_at
        );
    if (!result) {
    }
    return result;
}

void absence_free(absence_t *absence) {
    if(NULL == absence){
        return ;
    }
    if(absence->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "absence_free");
        return ;
    }
    listEntry_t *listEntry;
    if (absence->absence_type) {
        absence_type_free(absence->absence_type);
        absence->absence_type = NULL;
    }
    if (absence->approved_at) {
        free(absence->approved_at);
        absence->approved_at = NULL;
    }
    if (absence->approved_by) {
        free(absence->approved_by);
        absence->approved_by = NULL;
    }
    if (absence->created_at) {
        free(absence->created_at);
        absence->created_at = NULL;
    }
    if (absence->deleted_at) {
        free(absence->deleted_at);
        absence->deleted_at = NULL;
    }
    if (absence->employee_id) {
        free(absence->employee_id);
        absence->employee_id = NULL;
    }
    if (absence->end_date) {
        free(absence->end_date);
        absence->end_date = NULL;
    }
    if (absence->id) {
        free(absence->id);
        absence->id = NULL;
    }
    if (absence->notes) {
        free(absence->notes);
        absence->notes = NULL;
    }
    if (absence->start_date) {
        free(absence->start_date);
        absence->start_date = NULL;
    }
    if (absence->status) {
        absence_status_free(absence->status);
        absence->status = NULL;
    }
    if (absence->tenant_id) {
        free(absence->tenant_id);
        absence->tenant_id = NULL;
    }
    if (absence->updated_at) {
        free(absence->updated_at);
        absence->updated_at = NULL;
    }
    free(absence);
}

cJSON *absence_convertToJSON(absence_t *absence) {
    cJSON *item = cJSON_CreateObject();

    // absence->absence_type
    if(absence->absence_type) {
    cJSON *absence_type_local_JSON = absence_type_convertToJSON(absence->absence_type);
    if(absence_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "absenceType", absence_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // absence->approved_at
    if(absence->approved_at) {
    if(cJSON_AddStringToObject(item, "approvedAt", absence->approved_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // absence->approved_by
    if(absence->approved_by) {
    if(cJSON_AddStringToObject(item, "approvedBy", absence->approved_by) == NULL) {
    goto fail; //String
    }
    }


    // absence->created_at
    if(absence->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", absence->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // absence->deleted_at
    if(absence->deleted_at) {
    if(cJSON_AddStringToObject(item, "deletedAt", absence->deleted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // absence->employee_id
    if(absence->employee_id) {
    if(cJSON_AddStringToObject(item, "employeeId", absence->employee_id) == NULL) {
    goto fail; //String
    }
    }


    // absence->end_date
    if(absence->end_date) {
    if(cJSON_AddStringToObject(item, "endDate", absence->end_date) == NULL) {
    goto fail; //Date
    }
    }


    // absence->id
    if(absence->id) {
    if(cJSON_AddStringToObject(item, "id", absence->id) == NULL) {
    goto fail; //String
    }
    }


    // absence->notes
    if(absence->notes) {
    if(cJSON_AddStringToObject(item, "notes", absence->notes) == NULL) {
    goto fail; //String
    }
    }


    // absence->start_date
    if(absence->start_date) {
    if(cJSON_AddStringToObject(item, "startDate", absence->start_date) == NULL) {
    goto fail; //Date
    }
    }


    // absence->status
    if(absence->status) {
    cJSON *status_local_JSON = absence_status_convertToJSON(absence->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // absence->tenant_id
    if(absence->tenant_id) {
    if(cJSON_AddStringToObject(item, "tenantId", absence->tenant_id) == NULL) {
    goto fail; //String
    }
    }


    // absence->updated_at
    if(absence->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", absence->updated_at) == NULL) {
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

absence_t *absence_parseFromJSON(cJSON *absenceJSON){

    absence_t *absence_local_var = NULL;

    // define the local variable for absence->absence_type
    absence_type_t *absence_type_local_nonprim = NULL;

    char *approved_at_local_str = NULL;

    char *approved_by_local_str = NULL;

    char *created_at_local_str = NULL;

    char *deleted_at_local_str = NULL;

    char *employee_id_local_str = NULL;

    char *end_date_local_str = NULL;

    char *id_local_str = NULL;

    char *notes_local_str = NULL;

    char *start_date_local_str = NULL;

    // define the local variable for absence->status
    absence_status_t *status_local_nonprim = NULL;

    char *tenant_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    // absence->absence_type
    cJSON *absence_type = cJSON_GetObjectItemCaseSensitive(absenceJSON, "absenceType");
    if (cJSON_IsNull(absence_type)) {
        absence_type = NULL;
    }
    if (absence_type) { 
    absence_type_local_nonprim = absence_type_parseFromJSON(absence_type); //custom
    }

    // absence->approved_at
    cJSON *approved_at = cJSON_GetObjectItemCaseSensitive(absenceJSON, "approvedAt");
    if (cJSON_IsNull(approved_at)) {
        approved_at = NULL;
    }
    if (approved_at) { 
    if(!cJSON_IsString(approved_at) && !cJSON_IsNull(approved_at))
    {
    goto end; //DateTime
    }
    }

    // absence->approved_by
    cJSON *approved_by = cJSON_GetObjectItemCaseSensitive(absenceJSON, "approvedBy");
    if (cJSON_IsNull(approved_by)) {
        approved_by = NULL;
    }
    if (approved_by) { 
    if(!cJSON_IsString(approved_by) && !cJSON_IsNull(approved_by))
    {
    goto end; //String
    }
    }

    // absence->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(absenceJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // absence->deleted_at
    cJSON *deleted_at = cJSON_GetObjectItemCaseSensitive(absenceJSON, "deletedAt");
    if (cJSON_IsNull(deleted_at)) {
        deleted_at = NULL;
    }
    if (deleted_at) { 
    if(!cJSON_IsString(deleted_at) && !cJSON_IsNull(deleted_at))
    {
    goto end; //DateTime
    }
    }

    // absence->employee_id
    cJSON *employee_id = cJSON_GetObjectItemCaseSensitive(absenceJSON, "employeeId");
    if (cJSON_IsNull(employee_id)) {
        employee_id = NULL;
    }
    if (employee_id) { 
    if(!cJSON_IsString(employee_id) && !cJSON_IsNull(employee_id))
    {
    goto end; //String
    }
    }

    // absence->end_date
    cJSON *end_date = cJSON_GetObjectItemCaseSensitive(absenceJSON, "endDate");
    if (cJSON_IsNull(end_date)) {
        end_date = NULL;
    }
    if (end_date) { 
    if(!cJSON_IsString(end_date))
    {
    goto end; //Date
    }
    }

    // absence->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(absenceJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // absence->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(absenceJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // absence->start_date
    cJSON *start_date = cJSON_GetObjectItemCaseSensitive(absenceJSON, "startDate");
    if (cJSON_IsNull(start_date)) {
        start_date = NULL;
    }
    if (start_date) { 
    if(!cJSON_IsString(start_date))
    {
    goto end; //Date
    }
    }

    // absence->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(absenceJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = absence_status_parseFromJSON(status); //custom
    }

    // absence->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(absenceJSON, "tenantId");
    if (cJSON_IsNull(tenant_id)) {
        tenant_id = NULL;
    }
    if (tenant_id) { 
    if(!cJSON_IsString(tenant_id) && !cJSON_IsNull(tenant_id))
    {
    goto end; //String
    }
    }

    // absence->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(absenceJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    if (approved_at && !cJSON_IsNull(approved_at)) approved_at_local_str = strdup(approved_at->valuestring);
    if (approved_by && !cJSON_IsNull(approved_by)) approved_by_local_str = strdup(approved_by->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (deleted_at && !cJSON_IsNull(deleted_at)) deleted_at_local_str = strdup(deleted_at->valuestring);
    if (employee_id && !cJSON_IsNull(employee_id)) employee_id_local_str = strdup(employee_id->valuestring);
    if (end_date) end_date_local_str = strdup(end_date->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (start_date) start_date_local_str = strdup(start_date->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    absence_local_var = absence_create_internal (
        absence_type ? absence_type_local_nonprim : NULL,
        approved_at_local_str,
        approved_by_local_str,
        created_at_local_str,
        deleted_at_local_str,
        employee_id_local_str,
        end_date_local_str,
        id_local_str,
        notes_local_str,
        start_date_local_str,
        status ? status_local_nonprim : NULL,
        tenant_id_local_str,
        updated_at_local_str
        );

    if (!absence_local_var) {
        goto end;
    }

    return absence_local_var;
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
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (deleted_at_local_str) {
        free(deleted_at_local_str);
        deleted_at_local_str = NULL;
    }
    if (employee_id_local_str) {
        free(employee_id_local_str);
        employee_id_local_str = NULL;
    }
    if (end_date_local_str) {
        free(end_date_local_str);
        end_date_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
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
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    return NULL;

}
