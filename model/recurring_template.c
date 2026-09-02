#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "recurring_template.h"



static recurring_template_t *recurring_template_create_internal(
    char *created_at,
    char *deleted_at,
    char *end_date,
    char *execution_interval,
    char *execution_status,
    int *finalize,
    char *last_executed_at,
    char *name,
    char *next_execution_at,
    char *start_date,
    char *template_id,
    char *template_type,
    char *updated_at,
    any_type_t *voucher_data
    ) {
    recurring_template_t *recurring_template_local_var = malloc(sizeof(recurring_template_t));
    if (!recurring_template_local_var) {
        return NULL;
    }
    memset(recurring_template_local_var, 0, sizeof(recurring_template_t));
    recurring_template_local_var->_library_owned = 1;
    recurring_template_local_var->created_at = created_at;
    recurring_template_local_var->deleted_at = deleted_at;
    recurring_template_local_var->end_date = end_date;
    recurring_template_local_var->execution_interval = execution_interval;
    recurring_template_local_var->execution_status = execution_status;
    recurring_template_local_var->finalize = finalize;
    recurring_template_local_var->last_executed_at = last_executed_at;
    recurring_template_local_var->name = name;
    recurring_template_local_var->next_execution_at = next_execution_at;
    recurring_template_local_var->start_date = start_date;
    recurring_template_local_var->template_id = template_id;
    recurring_template_local_var->template_type = template_type;
    recurring_template_local_var->updated_at = updated_at;
    recurring_template_local_var->voucher_data = voucher_data;
    return recurring_template_local_var;
}

__attribute__((deprecated)) recurring_template_t *recurring_template_create(
    char *created_at,
    char *deleted_at,
    char *end_date,
    char *execution_interval,
    char *execution_status,
    int *finalize,
    char *last_executed_at,
    char *name,
    char *next_execution_at,
    char *start_date,
    char *template_id,
    char *template_type,
    char *updated_at,
    any_type_t *voucher_data
    ) {
    int *finalize_copy = NULL;
    if (finalize) {
        finalize_copy = malloc(sizeof(int));
        if (finalize_copy) *finalize_copy = *finalize;
    }
    recurring_template_t *result = recurring_template_create_internal (
        created_at,
        deleted_at,
        end_date,
        execution_interval,
        execution_status,
        finalize_copy,
        last_executed_at,
        name,
        next_execution_at,
        start_date,
        template_id,
        template_type,
        updated_at,
        voucher_data
        );
    if (!result) {
        free(finalize_copy);
    }
    return result;
}

void recurring_template_free(recurring_template_t *recurring_template) {
    if(NULL == recurring_template){
        return ;
    }
    if(recurring_template->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "recurring_template_free");
        return ;
    }
    listEntry_t *listEntry;
    if (recurring_template->created_at) {
        free(recurring_template->created_at);
        recurring_template->created_at = NULL;
    }
    if (recurring_template->deleted_at) {
        free(recurring_template->deleted_at);
        recurring_template->deleted_at = NULL;
    }
    if (recurring_template->end_date) {
        free(recurring_template->end_date);
        recurring_template->end_date = NULL;
    }
    if (recurring_template->execution_interval) {
        free(recurring_template->execution_interval);
        recurring_template->execution_interval = NULL;
    }
    if (recurring_template->execution_status) {
        free(recurring_template->execution_status);
        recurring_template->execution_status = NULL;
    }
    if (recurring_template->finalize) {
        free(recurring_template->finalize);
        recurring_template->finalize = NULL;
    }
    if (recurring_template->last_executed_at) {
        free(recurring_template->last_executed_at);
        recurring_template->last_executed_at = NULL;
    }
    if (recurring_template->name) {
        free(recurring_template->name);
        recurring_template->name = NULL;
    }
    if (recurring_template->next_execution_at) {
        free(recurring_template->next_execution_at);
        recurring_template->next_execution_at = NULL;
    }
    if (recurring_template->start_date) {
        free(recurring_template->start_date);
        recurring_template->start_date = NULL;
    }
    if (recurring_template->template_id) {
        free(recurring_template->template_id);
        recurring_template->template_id = NULL;
    }
    if (recurring_template->template_type) {
        free(recurring_template->template_type);
        recurring_template->template_type = NULL;
    }
    if (recurring_template->updated_at) {
        free(recurring_template->updated_at);
        recurring_template->updated_at = NULL;
    }
    if (recurring_template->voucher_data) {
        _free(recurring_template->voucher_data);
        recurring_template->voucher_data = NULL;
    }
    free(recurring_template);
}

cJSON *recurring_template_convertToJSON(recurring_template_t *recurring_template) {
    cJSON *item = cJSON_CreateObject();

    // recurring_template->created_at
    if (!recurring_template->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", recurring_template->created_at) == NULL) {
    goto fail; //String
    }


    // recurring_template->deleted_at
    if(recurring_template->deleted_at) {
    if(cJSON_AddStringToObject(item, "deleted_at", recurring_template->deleted_at) == NULL) {
    goto fail; //String
    }
    }


    // recurring_template->end_date
    if(recurring_template->end_date) {
    if(cJSON_AddStringToObject(item, "end_date", recurring_template->end_date) == NULL) {
    goto fail; //Date
    }
    }


    // recurring_template->execution_interval
    if (!recurring_template->execution_interval) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "execution_interval", recurring_template->execution_interval) == NULL) {
    goto fail; //String
    }


    // recurring_template->execution_status
    if (!recurring_template->execution_status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "execution_status", recurring_template->execution_status) == NULL) {
    goto fail; //String
    }


    // recurring_template->finalize
    if (!recurring_template->finalize) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "finalize", *recurring_template->finalize) == NULL) {
    goto fail; //Bool
    }


    // recurring_template->last_executed_at
    if(recurring_template->last_executed_at) {
    if(cJSON_AddStringToObject(item, "last_executed_at", recurring_template->last_executed_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // recurring_template->name
    if (!recurring_template->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", recurring_template->name) == NULL) {
    goto fail; //String
    }


    // recurring_template->next_execution_at
    if(recurring_template->next_execution_at) {
    if(cJSON_AddStringToObject(item, "next_execution_at", recurring_template->next_execution_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // recurring_template->start_date
    if (!recurring_template->start_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "start_date", recurring_template->start_date) == NULL) {
    goto fail; //Date
    }


    // recurring_template->template_id
    if (!recurring_template->template_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "template_id", recurring_template->template_id) == NULL) {
    goto fail; //String
    }


    // recurring_template->template_type
    if (!recurring_template->template_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "template_type", recurring_template->template_type) == NULL) {
    goto fail; //String
    }


    // recurring_template->updated_at
    if(recurring_template->updated_at) {
    if(cJSON_AddStringToObject(item, "updated_at", recurring_template->updated_at) == NULL) {
    goto fail; //String
    }
    }


    // recurring_template->voucher_data
    if (!recurring_template->voucher_data) {
        goto fail;
    }
    cJSON *voucher_data_local_JSON = _convertToJSON(recurring_template->voucher_data);
    if(voucher_data_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "voucher_data", voucher_data_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

recurring_template_t *recurring_template_parseFromJSON(cJSON *recurring_templateJSON){

    recurring_template_t *recurring_template_local_var = NULL;

    char *created_at_local_str = NULL;

    char *deleted_at_local_str = NULL;

    char *end_date_local_str = NULL;

    char *execution_interval_local_str = NULL;

    char *execution_status_local_str = NULL;

    // define the local variable for recurring_template->finalize
    int *finalize_local_var = NULL;

    char *last_executed_at_local_str = NULL;

    char *name_local_str = NULL;

    char *next_execution_at_local_str = NULL;

    char *start_date_local_str = NULL;

    char *template_id_local_str = NULL;

    char *template_type_local_str = NULL;

    char *updated_at_local_str = NULL;

    // define the local variable for recurring_template->voucher_data
    _t *voucher_data_local_nonprim = NULL;

    // recurring_template->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "created_at");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at))
    {
    goto end; //String
    }

    // recurring_template->deleted_at
    cJSON *deleted_at = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "deleted_at");
    if (cJSON_IsNull(deleted_at)) {
        deleted_at = NULL;
    }
    if (deleted_at) { 
    if(!cJSON_IsString(deleted_at) && !cJSON_IsNull(deleted_at))
    {
    goto end; //String
    }
    }

    // recurring_template->end_date
    cJSON *end_date = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "end_date");
    if (cJSON_IsNull(end_date)) {
        end_date = NULL;
    }
    if (end_date) { 
    if(!cJSON_IsString(end_date))
    {
    goto end; //Date
    }
    }

    // recurring_template->execution_interval
    cJSON *execution_interval = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "execution_interval");
    if (cJSON_IsNull(execution_interval)) {
        execution_interval = NULL;
    }
    if (!execution_interval) {
        goto end;
    }

    
    if(!cJSON_IsString(execution_interval))
    {
    goto end; //String
    }

    // recurring_template->execution_status
    cJSON *execution_status = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "execution_status");
    if (cJSON_IsNull(execution_status)) {
        execution_status = NULL;
    }
    if (!execution_status) {
        goto end;
    }

    
    if(!cJSON_IsString(execution_status))
    {
    goto end; //String
    }

    // recurring_template->finalize
    cJSON *finalize = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "finalize");
    if (cJSON_IsNull(finalize)) {
        finalize = NULL;
    }
    if (!finalize) {
        goto end;
    }

    
    if(!cJSON_IsBool(finalize))
    {
    goto end; //Bool
    }
    finalize_local_var = malloc(sizeof(int));
    if(!finalize_local_var)
    {
        goto end;
    }
    *finalize_local_var = finalize->valueint;

    // recurring_template->last_executed_at
    cJSON *last_executed_at = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "last_executed_at");
    if (cJSON_IsNull(last_executed_at)) {
        last_executed_at = NULL;
    }
    if (last_executed_at) { 
    if(!cJSON_IsString(last_executed_at) && !cJSON_IsNull(last_executed_at))
    {
    goto end; //DateTime
    }
    }

    // recurring_template->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // recurring_template->next_execution_at
    cJSON *next_execution_at = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "next_execution_at");
    if (cJSON_IsNull(next_execution_at)) {
        next_execution_at = NULL;
    }
    if (next_execution_at) { 
    if(!cJSON_IsString(next_execution_at) && !cJSON_IsNull(next_execution_at))
    {
    goto end; //DateTime
    }
    }

    // recurring_template->start_date
    cJSON *start_date = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "start_date");
    if (cJSON_IsNull(start_date)) {
        start_date = NULL;
    }
    if (!start_date) {
        goto end;
    }

    
    if(!cJSON_IsString(start_date))
    {
    goto end; //Date
    }

    // recurring_template->template_id
    cJSON *template_id = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "template_id");
    if (cJSON_IsNull(template_id)) {
        template_id = NULL;
    }
    if (!template_id) {
        goto end;
    }

    
    if(!cJSON_IsString(template_id))
    {
    goto end; //String
    }

    // recurring_template->template_type
    cJSON *template_type = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "template_type");
    if (cJSON_IsNull(template_type)) {
        template_type = NULL;
    }
    if (!template_type) {
        goto end;
    }

    
    if(!cJSON_IsString(template_type))
    {
    goto end; //String
    }

    // recurring_template->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "updated_at");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //String
    }
    }

    // recurring_template->voucher_data
    cJSON *voucher_data = cJSON_GetObjectItemCaseSensitive(recurring_templateJSON, "voucher_data");
    if (cJSON_IsNull(voucher_data)) {
        voucher_data = NULL;
    }
    if (!voucher_data) {
        goto end;
    }

    
    voucher_data_local_nonprim = _parseFromJSON(voucher_data); //custom


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (deleted_at && !cJSON_IsNull(deleted_at)) deleted_at_local_str = strdup(deleted_at->valuestring);
    if (end_date) end_date_local_str = strdup(end_date->valuestring);
    if (execution_interval && !cJSON_IsNull(execution_interval)) execution_interval_local_str = strdup(execution_interval->valuestring);
    if (execution_status && !cJSON_IsNull(execution_status)) execution_status_local_str = strdup(execution_status->valuestring);
    if (last_executed_at && !cJSON_IsNull(last_executed_at)) last_executed_at_local_str = strdup(last_executed_at->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (next_execution_at && !cJSON_IsNull(next_execution_at)) next_execution_at_local_str = strdup(next_execution_at->valuestring);
    if (start_date) start_date_local_str = strdup(start_date->valuestring);
    if (template_id && !cJSON_IsNull(template_id)) template_id_local_str = strdup(template_id->valuestring);
    if (template_type && !cJSON_IsNull(template_type)) template_type_local_str = strdup(template_type->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    recurring_template_local_var = recurring_template_create_internal (
        created_at_local_str,
        deleted_at_local_str,
        end_date_local_str,
        execution_interval_local_str,
        execution_status_local_str,
        finalize_local_var,
        last_executed_at_local_str,
        name_local_str,
        next_execution_at_local_str,
        start_date_local_str,
        template_id_local_str,
        template_type_local_str,
        updated_at_local_str,
        voucher_data_local_nonprim
        );

    if (!recurring_template_local_var) {
        goto end;
    }

    return recurring_template_local_var;
end:
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (deleted_at_local_str) {
        free(deleted_at_local_str);
        deleted_at_local_str = NULL;
    }
    if (end_date_local_str) {
        free(end_date_local_str);
        end_date_local_str = NULL;
    }
    if (execution_interval_local_str) {
        free(execution_interval_local_str);
        execution_interval_local_str = NULL;
    }
    if (execution_status_local_str) {
        free(execution_status_local_str);
        execution_status_local_str = NULL;
    }
    if (finalize_local_var) {
        free(finalize_local_var);
        finalize_local_var = NULL;
    }
    if (last_executed_at_local_str) {
        free(last_executed_at_local_str);
        last_executed_at_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (next_execution_at_local_str) {
        free(next_execution_at_local_str);
        next_execution_at_local_str = NULL;
    }
    if (start_date_local_str) {
        free(start_date_local_str);
        start_date_local_str = NULL;
    }
    if (template_id_local_str) {
        free(template_id_local_str);
        template_id_local_str = NULL;
    }
    if (template_type_local_str) {
        free(template_type_local_str);
        template_type_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    if (voucher_data_local_nonprim) {
        _free(voucher_data_local_nonprim);
        voucher_data_local_nonprim = NULL;
    }
    return NULL;

}
