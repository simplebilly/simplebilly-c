#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "labor_cost_row.h"



static labor_cost_row_t *labor_cost_row_create_internal(
    char *cost,
    char *employee_id,
    char *group_key,
    char *hours,
    char *name
    ) {
    labor_cost_row_t *labor_cost_row_local_var = malloc(sizeof(labor_cost_row_t));
    if (!labor_cost_row_local_var) {
        return NULL;
    }
    memset(labor_cost_row_local_var, 0, sizeof(labor_cost_row_t));
    labor_cost_row_local_var->_library_owned = 1;
    labor_cost_row_local_var->cost = cost;
    labor_cost_row_local_var->employee_id = employee_id;
    labor_cost_row_local_var->group_key = group_key;
    labor_cost_row_local_var->hours = hours;
    labor_cost_row_local_var->name = name;
    return labor_cost_row_local_var;
}

__attribute__((deprecated)) labor_cost_row_t *labor_cost_row_create(
    char *cost,
    char *employee_id,
    char *group_key,
    char *hours,
    char *name
    ) {
    labor_cost_row_t *result = labor_cost_row_create_internal (
        cost,
        employee_id,
        group_key,
        hours,
        name
        );
    if (!result) {
    }
    return result;
}

void labor_cost_row_free(labor_cost_row_t *labor_cost_row) {
    if(NULL == labor_cost_row){
        return ;
    }
    if(labor_cost_row->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "labor_cost_row_free");
        return ;
    }
    listEntry_t *listEntry;
    if (labor_cost_row->cost) {
        free(labor_cost_row->cost);
        labor_cost_row->cost = NULL;
    }
    if (labor_cost_row->employee_id) {
        free(labor_cost_row->employee_id);
        labor_cost_row->employee_id = NULL;
    }
    if (labor_cost_row->group_key) {
        free(labor_cost_row->group_key);
        labor_cost_row->group_key = NULL;
    }
    if (labor_cost_row->hours) {
        free(labor_cost_row->hours);
        labor_cost_row->hours = NULL;
    }
    if (labor_cost_row->name) {
        free(labor_cost_row->name);
        labor_cost_row->name = NULL;
    }
    free(labor_cost_row);
}

cJSON *labor_cost_row_convertToJSON(labor_cost_row_t *labor_cost_row) {
    cJSON *item = cJSON_CreateObject();

    // labor_cost_row->cost
    if (!labor_cost_row->cost) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "cost", labor_cost_row->cost) == NULL) {
    goto fail; //String
    }


    // labor_cost_row->employee_id
    if(labor_cost_row->employee_id) {
    if(cJSON_AddStringToObject(item, "employeeId", labor_cost_row->employee_id) == NULL) {
    goto fail; //String
    }
    }


    // labor_cost_row->group_key
    if (!labor_cost_row->group_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "groupKey", labor_cost_row->group_key) == NULL) {
    goto fail; //String
    }


    // labor_cost_row->hours
    if (!labor_cost_row->hours) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hours", labor_cost_row->hours) == NULL) {
    goto fail; //String
    }


    // labor_cost_row->name
    if(labor_cost_row->name) {
    if(cJSON_AddStringToObject(item, "name", labor_cost_row->name) == NULL) {
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

labor_cost_row_t *labor_cost_row_parseFromJSON(cJSON *labor_cost_rowJSON){

    labor_cost_row_t *labor_cost_row_local_var = NULL;

    char *cost_local_str = NULL;

    char *employee_id_local_str = NULL;

    char *group_key_local_str = NULL;

    char *hours_local_str = NULL;

    char *name_local_str = NULL;

    // labor_cost_row->cost
    cJSON *cost = cJSON_GetObjectItemCaseSensitive(labor_cost_rowJSON, "cost");
    if (cJSON_IsNull(cost)) {
        cost = NULL;
    }
    if (!cost) {
        goto end;
    }

    
    if(!cJSON_IsString(cost))
    {
    goto end; //String
    }

    // labor_cost_row->employee_id
    cJSON *employee_id = cJSON_GetObjectItemCaseSensitive(labor_cost_rowJSON, "employeeId");
    if (cJSON_IsNull(employee_id)) {
        employee_id = NULL;
    }
    if (employee_id) { 
    if(!cJSON_IsString(employee_id) && !cJSON_IsNull(employee_id))
    {
    goto end; //String
    }
    }

    // labor_cost_row->group_key
    cJSON *group_key = cJSON_GetObjectItemCaseSensitive(labor_cost_rowJSON, "groupKey");
    if (cJSON_IsNull(group_key)) {
        group_key = NULL;
    }
    if (!group_key) {
        goto end;
    }

    
    if(!cJSON_IsString(group_key))
    {
    goto end; //String
    }

    // labor_cost_row->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(labor_cost_rowJSON, "hours");
    if (cJSON_IsNull(hours)) {
        hours = NULL;
    }
    if (!hours) {
        goto end;
    }

    
    if(!cJSON_IsString(hours))
    {
    goto end; //String
    }

    // labor_cost_row->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(labor_cost_rowJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    if (cost && !cJSON_IsNull(cost)) cost_local_str = strdup(cost->valuestring);
    if (employee_id && !cJSON_IsNull(employee_id)) employee_id_local_str = strdup(employee_id->valuestring);
    if (group_key && !cJSON_IsNull(group_key)) group_key_local_str = strdup(group_key->valuestring);
    if (hours && !cJSON_IsNull(hours)) hours_local_str = strdup(hours->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    labor_cost_row_local_var = labor_cost_row_create_internal (
        cost_local_str,
        employee_id_local_str,
        group_key_local_str,
        hours_local_str,
        name_local_str
        );

    if (!labor_cost_row_local_var) {
        goto end;
    }

    return labor_cost_row_local_var;
end:
    if (cost_local_str) {
        free(cost_local_str);
        cost_local_str = NULL;
    }
    if (employee_id_local_str) {
        free(employee_id_local_str);
        employee_id_local_str = NULL;
    }
    if (group_key_local_str) {
        free(group_key_local_str);
        group_key_local_str = NULL;
    }
    if (hours_local_str) {
        free(hours_local_str);
        hours_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
