#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "time_entry_dto.h"



static time_entry_dto_t *time_entry_dto_create_internal(
    char *clock_in,
    char *clock_out,
    char *created_at,
    char *date,
    char *employee_id,
    char *hours,
    char *notes,
    char *time_entry_id
    ) {
    time_entry_dto_t *time_entry_dto_local_var = malloc(sizeof(time_entry_dto_t));
    if (!time_entry_dto_local_var) {
        return NULL;
    }
    memset(time_entry_dto_local_var, 0, sizeof(time_entry_dto_t));
    time_entry_dto_local_var->_library_owned = 1;
    time_entry_dto_local_var->clock_in = clock_in;
    time_entry_dto_local_var->clock_out = clock_out;
    time_entry_dto_local_var->created_at = created_at;
    time_entry_dto_local_var->date = date;
    time_entry_dto_local_var->employee_id = employee_id;
    time_entry_dto_local_var->hours = hours;
    time_entry_dto_local_var->notes = notes;
    time_entry_dto_local_var->time_entry_id = time_entry_id;
    return time_entry_dto_local_var;
}

__attribute__((deprecated)) time_entry_dto_t *time_entry_dto_create(
    char *clock_in,
    char *clock_out,
    char *created_at,
    char *date,
    char *employee_id,
    char *hours,
    char *notes,
    char *time_entry_id
    ) {
    time_entry_dto_t *result = time_entry_dto_create_internal (
        clock_in,
        clock_out,
        created_at,
        date,
        employee_id,
        hours,
        notes,
        time_entry_id
        );
    if (!result) {
    }
    return result;
}

void time_entry_dto_free(time_entry_dto_t *time_entry_dto) {
    if(NULL == time_entry_dto){
        return ;
    }
    if(time_entry_dto->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "time_entry_dto_free");
        return ;
    }
    listEntry_t *listEntry;
    if (time_entry_dto->clock_in) {
        free(time_entry_dto->clock_in);
        time_entry_dto->clock_in = NULL;
    }
    if (time_entry_dto->clock_out) {
        free(time_entry_dto->clock_out);
        time_entry_dto->clock_out = NULL;
    }
    if (time_entry_dto->created_at) {
        free(time_entry_dto->created_at);
        time_entry_dto->created_at = NULL;
    }
    if (time_entry_dto->date) {
        free(time_entry_dto->date);
        time_entry_dto->date = NULL;
    }
    if (time_entry_dto->employee_id) {
        free(time_entry_dto->employee_id);
        time_entry_dto->employee_id = NULL;
    }
    if (time_entry_dto->hours) {
        free(time_entry_dto->hours);
        time_entry_dto->hours = NULL;
    }
    if (time_entry_dto->notes) {
        free(time_entry_dto->notes);
        time_entry_dto->notes = NULL;
    }
    if (time_entry_dto->time_entry_id) {
        free(time_entry_dto->time_entry_id);
        time_entry_dto->time_entry_id = NULL;
    }
    free(time_entry_dto);
}

cJSON *time_entry_dto_convertToJSON(time_entry_dto_t *time_entry_dto) {
    cJSON *item = cJSON_CreateObject();

    // time_entry_dto->clock_in
    if(time_entry_dto->clock_in) {
    if(cJSON_AddStringToObject(item, "clock_in", time_entry_dto->clock_in) == NULL) {
    goto fail; //Date-Time
    }
    }


    // time_entry_dto->clock_out
    if(time_entry_dto->clock_out) {
    if(cJSON_AddStringToObject(item, "clock_out", time_entry_dto->clock_out) == NULL) {
    goto fail; //Date-Time
    }
    }


    // time_entry_dto->created_at
    if (!time_entry_dto->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", time_entry_dto->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // time_entry_dto->date
    if (!time_entry_dto->date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "date", time_entry_dto->date) == NULL) {
    goto fail; //Date
    }


    // time_entry_dto->employee_id
    if (!time_entry_dto->employee_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "employee_id", time_entry_dto->employee_id) == NULL) {
    goto fail; //String
    }


    // time_entry_dto->hours
    if(time_entry_dto->hours) {
    if(cJSON_AddStringToObject(item, "hours", time_entry_dto->hours) == NULL) {
    goto fail; //String
    }
    }


    // time_entry_dto->notes
    if(time_entry_dto->notes) {
    if(cJSON_AddStringToObject(item, "notes", time_entry_dto->notes) == NULL) {
    goto fail; //String
    }
    }


    // time_entry_dto->time_entry_id
    if (!time_entry_dto->time_entry_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "time_entry_id", time_entry_dto->time_entry_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

time_entry_dto_t *time_entry_dto_parseFromJSON(cJSON *time_entry_dtoJSON){

    time_entry_dto_t *time_entry_dto_local_var = NULL;

    char *clock_in_local_str = NULL;

    char *clock_out_local_str = NULL;

    char *created_at_local_str = NULL;

    char *date_local_str = NULL;

    char *employee_id_local_str = NULL;

    char *hours_local_str = NULL;

    char *notes_local_str = NULL;

    char *time_entry_id_local_str = NULL;

    // time_entry_dto->clock_in
    cJSON *clock_in = cJSON_GetObjectItemCaseSensitive(time_entry_dtoJSON, "clock_in");
    if (cJSON_IsNull(clock_in)) {
        clock_in = NULL;
    }
    if (clock_in) { 
    if(!cJSON_IsString(clock_in) && !cJSON_IsNull(clock_in))
    {
    goto end; //DateTime
    }
    }

    // time_entry_dto->clock_out
    cJSON *clock_out = cJSON_GetObjectItemCaseSensitive(time_entry_dtoJSON, "clock_out");
    if (cJSON_IsNull(clock_out)) {
        clock_out = NULL;
    }
    if (clock_out) { 
    if(!cJSON_IsString(clock_out) && !cJSON_IsNull(clock_out))
    {
    goto end; //DateTime
    }
    }

    // time_entry_dto->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(time_entry_dtoJSON, "created_at");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // time_entry_dto->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(time_entry_dtoJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsString(date))
    {
    goto end; //Date
    }

    // time_entry_dto->employee_id
    cJSON *employee_id = cJSON_GetObjectItemCaseSensitive(time_entry_dtoJSON, "employee_id");
    if (cJSON_IsNull(employee_id)) {
        employee_id = NULL;
    }
    if (!employee_id) {
        goto end;
    }

    
    if(!cJSON_IsString(employee_id))
    {
    goto end; //String
    }

    // time_entry_dto->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(time_entry_dtoJSON, "hours");
    if (cJSON_IsNull(hours)) {
        hours = NULL;
    }
    if (hours) { 
    if(!cJSON_IsString(hours) && !cJSON_IsNull(hours))
    {
    goto end; //String
    }
    }

    // time_entry_dto->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(time_entry_dtoJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // time_entry_dto->time_entry_id
    cJSON *time_entry_id = cJSON_GetObjectItemCaseSensitive(time_entry_dtoJSON, "time_entry_id");
    if (cJSON_IsNull(time_entry_id)) {
        time_entry_id = NULL;
    }
    if (!time_entry_id) {
        goto end;
    }

    
    if(!cJSON_IsString(time_entry_id))
    {
    goto end; //String
    }


    if (clock_in && !cJSON_IsNull(clock_in)) clock_in_local_str = strdup(clock_in->valuestring);
    if (clock_out && !cJSON_IsNull(clock_out)) clock_out_local_str = strdup(clock_out->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (date) date_local_str = strdup(date->valuestring);
    if (employee_id && !cJSON_IsNull(employee_id)) employee_id_local_str = strdup(employee_id->valuestring);
    if (hours && !cJSON_IsNull(hours)) hours_local_str = strdup(hours->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (time_entry_id && !cJSON_IsNull(time_entry_id)) time_entry_id_local_str = strdup(time_entry_id->valuestring);

    time_entry_dto_local_var = time_entry_dto_create_internal (
        clock_in_local_str,
        clock_out_local_str,
        created_at_local_str,
        date_local_str,
        employee_id_local_str,
        hours_local_str,
        notes_local_str,
        time_entry_id_local_str
        );

    if (!time_entry_dto_local_var) {
        goto end;
    }

    return time_entry_dto_local_var;
end:
    if (clock_in_local_str) {
        free(clock_in_local_str);
        clock_in_local_str = NULL;
    }
    if (clock_out_local_str) {
        free(clock_out_local_str);
        clock_out_local_str = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (date_local_str) {
        free(date_local_str);
        date_local_str = NULL;
    }
    if (employee_id_local_str) {
        free(employee_id_local_str);
        employee_id_local_str = NULL;
    }
    if (hours_local_str) {
        free(hours_local_str);
        hours_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (time_entry_id_local_str) {
        free(time_entry_id_local_str);
        time_entry_id_local_str = NULL;
    }
    return NULL;

}
