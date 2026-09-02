#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "recurring_template_create.h"



static recurring_template_create_t *recurring_template_create_create_internal(
    char *end_date,
    char *execution_interval,
    simplebilly_api_execution_status__e execution_status,
    int *finalize,
    char *last_executed_at,
    char *name,
    char *next_execution_at,
    char *start_date,
    simplebilly_api_recurring_template_type__e template_type,
    any_type_t *voucher_data
    ) {
    recurring_template_create_t *recurring_template_create_local_var = malloc(sizeof(recurring_template_create_t));
    if (!recurring_template_create_local_var) {
        return NULL;
    }
    memset(recurring_template_create_local_var, 0, sizeof(recurring_template_create_t));
    recurring_template_create_local_var->_library_owned = 1;
    recurring_template_create_local_var->end_date = end_date;
    recurring_template_create_local_var->execution_interval = execution_interval;
    recurring_template_create_local_var->execution_status = execution_status;
    recurring_template_create_local_var->finalize = finalize;
    recurring_template_create_local_var->last_executed_at = last_executed_at;
    recurring_template_create_local_var->name = name;
    recurring_template_create_local_var->next_execution_at = next_execution_at;
    recurring_template_create_local_var->start_date = start_date;
    recurring_template_create_local_var->template_type = template_type;
    recurring_template_create_local_var->voucher_data = voucher_data;
    return recurring_template_create_local_var;
}

__attribute__((deprecated)) recurring_template_create_t *recurring_template_create_create(
    char *end_date,
    char *execution_interval,
    simplebilly_api_execution_status__e execution_status,
    int *finalize,
    char *last_executed_at,
    char *name,
    char *next_execution_at,
    char *start_date,
    simplebilly_api_recurring_template_type__e template_type,
    any_type_t *voucher_data
    ) {
    int *finalize_copy = NULL;
    if (finalize) {
        finalize_copy = malloc(sizeof(int));
        if (finalize_copy) *finalize_copy = *finalize;
    }
    recurring_template_create_t *result = recurring_template_create_create_internal (
        end_date,
        execution_interval,
        execution_status,
        finalize_copy,
        last_executed_at,
        name,
        next_execution_at,
        start_date,
        template_type,
        voucher_data
        );
    if (!result) {
        free(finalize_copy);
    }
    return result;
}

void recurring_template_create_free(recurring_template_create_t *recurring_template_create) {
    if(NULL == recurring_template_create){
        return ;
    }
    if(recurring_template_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "recurring_template_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (recurring_template_create->end_date) {
        free(recurring_template_create->end_date);
        recurring_template_create->end_date = NULL;
    }
    if (recurring_template_create->execution_interval) {
        free(recurring_template_create->execution_interval);
        recurring_template_create->execution_interval = NULL;
    }
    if (recurring_template_create->finalize) {
        free(recurring_template_create->finalize);
        recurring_template_create->finalize = NULL;
    }
    if (recurring_template_create->last_executed_at) {
        free(recurring_template_create->last_executed_at);
        recurring_template_create->last_executed_at = NULL;
    }
    if (recurring_template_create->name) {
        free(recurring_template_create->name);
        recurring_template_create->name = NULL;
    }
    if (recurring_template_create->next_execution_at) {
        free(recurring_template_create->next_execution_at);
        recurring_template_create->next_execution_at = NULL;
    }
    if (recurring_template_create->start_date) {
        free(recurring_template_create->start_date);
        recurring_template_create->start_date = NULL;
    }
    if (recurring_template_create->voucher_data) {
        _free(recurring_template_create->voucher_data);
        recurring_template_create->voucher_data = NULL;
    }
    free(recurring_template_create);
}

cJSON *recurring_template_create_convertToJSON(recurring_template_create_t *recurring_template_create) {
    cJSON *item = cJSON_CreateObject();

    // recurring_template_create->end_date
    if(recurring_template_create->end_date) {
    if(cJSON_AddStringToObject(item, "endDate", recurring_template_create->end_date) == NULL) {
    goto fail; //Date
    }
    }


    // recurring_template_create->execution_interval
    if (!recurring_template_create->execution_interval) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "executionInterval", recurring_template_create->execution_interval) == NULL) {
    goto fail; //String
    }


    // recurring_template_create->execution_status
    if (simplebilly_api_execution_status__NULL == recurring_template_create->execution_status) {
        goto fail;
    }
    cJSON *execution_status_local_JSON = execution_status_convertToJSON(recurring_template_create->execution_status);
    if(execution_status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "executionStatus", execution_status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // recurring_template_create->finalize
    if(recurring_template_create->finalize) {
    if(cJSON_AddBoolToObject(item, "finalize", *recurring_template_create->finalize) == NULL) {
    goto fail; //Bool
    }
    }


    // recurring_template_create->last_executed_at
    if(recurring_template_create->last_executed_at) {
    if(cJSON_AddStringToObject(item, "lastExecutedAt", recurring_template_create->last_executed_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // recurring_template_create->name
    if (!recurring_template_create->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", recurring_template_create->name) == NULL) {
    goto fail; //String
    }


    // recurring_template_create->next_execution_at
    if(recurring_template_create->next_execution_at) {
    if(cJSON_AddStringToObject(item, "nextExecutionAt", recurring_template_create->next_execution_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // recurring_template_create->start_date
    if (!recurring_template_create->start_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "startDate", recurring_template_create->start_date) == NULL) {
    goto fail; //Date
    }


    // recurring_template_create->template_type
    if (simplebilly_api_recurring_template_type__NULL == recurring_template_create->template_type) {
        goto fail;
    }
    cJSON *template_type_local_JSON = recurring_template_type_convertToJSON(recurring_template_create->template_type);
    if(template_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "templateType", template_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // recurring_template_create->voucher_data
    if(recurring_template_create->voucher_data) {
    cJSON *voucher_data_local_JSON = _convertToJSON(recurring_template_create->voucher_data);
    if(voucher_data_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "voucherData", voucher_data_local_JSON);
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

recurring_template_create_t *recurring_template_create_parseFromJSON(cJSON *recurring_template_createJSON){

    recurring_template_create_t *recurring_template_create_local_var = NULL;

    char *end_date_local_str = NULL;

    char *execution_interval_local_str = NULL;

    // define the local variable for recurring_template_create->execution_status
    simplebilly_api_execution_status__e execution_status_local_nonprim = 0;

    // define the local variable for recurring_template_create->finalize
    int *finalize_local_var = NULL;

    char *last_executed_at_local_str = NULL;

    char *name_local_str = NULL;

    char *next_execution_at_local_str = NULL;

    char *start_date_local_str = NULL;

    // define the local variable for recurring_template_create->template_type
    simplebilly_api_recurring_template_type__e template_type_local_nonprim = 0;

    // define the local variable for recurring_template_create->voucher_data
    _t *voucher_data_local_nonprim = NULL;

    // recurring_template_create->end_date
    cJSON *end_date = cJSON_GetObjectItemCaseSensitive(recurring_template_createJSON, "endDate");
    if (cJSON_IsNull(end_date)) {
        end_date = NULL;
    }
    if (end_date) { 
    if(!cJSON_IsString(end_date))
    {
    goto end; //Date
    }
    }

    // recurring_template_create->execution_interval
    cJSON *execution_interval = cJSON_GetObjectItemCaseSensitive(recurring_template_createJSON, "executionInterval");
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

    // recurring_template_create->execution_status
    cJSON *execution_status = cJSON_GetObjectItemCaseSensitive(recurring_template_createJSON, "executionStatus");
    if (cJSON_IsNull(execution_status)) {
        execution_status = NULL;
    }
    if (!execution_status) {
        goto end;
    }

    
    execution_status_local_nonprim = execution_status_parseFromJSON(execution_status); //custom

    // recurring_template_create->finalize
    cJSON *finalize = cJSON_GetObjectItemCaseSensitive(recurring_template_createJSON, "finalize");
    if (cJSON_IsNull(finalize)) {
        finalize = NULL;
    }
    if (finalize) { 
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
    }

    // recurring_template_create->last_executed_at
    cJSON *last_executed_at = cJSON_GetObjectItemCaseSensitive(recurring_template_createJSON, "lastExecutedAt");
    if (cJSON_IsNull(last_executed_at)) {
        last_executed_at = NULL;
    }
    if (last_executed_at) { 
    if(!cJSON_IsString(last_executed_at) && !cJSON_IsNull(last_executed_at))
    {
    goto end; //DateTime
    }
    }

    // recurring_template_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(recurring_template_createJSON, "name");
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

    // recurring_template_create->next_execution_at
    cJSON *next_execution_at = cJSON_GetObjectItemCaseSensitive(recurring_template_createJSON, "nextExecutionAt");
    if (cJSON_IsNull(next_execution_at)) {
        next_execution_at = NULL;
    }
    if (next_execution_at) { 
    if(!cJSON_IsString(next_execution_at) && !cJSON_IsNull(next_execution_at))
    {
    goto end; //DateTime
    }
    }

    // recurring_template_create->start_date
    cJSON *start_date = cJSON_GetObjectItemCaseSensitive(recurring_template_createJSON, "startDate");
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

    // recurring_template_create->template_type
    cJSON *template_type = cJSON_GetObjectItemCaseSensitive(recurring_template_createJSON, "templateType");
    if (cJSON_IsNull(template_type)) {
        template_type = NULL;
    }
    if (!template_type) {
        goto end;
    }

    
    template_type_local_nonprim = recurring_template_type_parseFromJSON(template_type); //custom

    // recurring_template_create->voucher_data
    cJSON *voucher_data = cJSON_GetObjectItemCaseSensitive(recurring_template_createJSON, "voucherData");
    if (cJSON_IsNull(voucher_data)) {
        voucher_data = NULL;
    }
    if (voucher_data) { 
    voucher_data_local_nonprim = _parseFromJSON(voucher_data); //custom
    }


    if (end_date) end_date_local_str = strdup(end_date->valuestring);
    if (execution_interval && !cJSON_IsNull(execution_interval)) execution_interval_local_str = strdup(execution_interval->valuestring);
    if (last_executed_at && !cJSON_IsNull(last_executed_at)) last_executed_at_local_str = strdup(last_executed_at->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (next_execution_at && !cJSON_IsNull(next_execution_at)) next_execution_at_local_str = strdup(next_execution_at->valuestring);
    if (start_date) start_date_local_str = strdup(start_date->valuestring);

    recurring_template_create_local_var = recurring_template_create_create_internal (
        end_date_local_str,
        execution_interval_local_str,
        execution_status_local_nonprim,
        finalize_local_var,
        last_executed_at_local_str,
        name_local_str,
        next_execution_at_local_str,
        start_date_local_str,
        template_type_local_nonprim,
        voucher_data ? voucher_data_local_nonprim : NULL
        );

    if (!recurring_template_create_local_var) {
        goto end;
    }

    return recurring_template_create_local_var;
end:
    if (end_date_local_str) {
        free(end_date_local_str);
        end_date_local_str = NULL;
    }
    if (execution_interval_local_str) {
        free(execution_interval_local_str);
        execution_interval_local_str = NULL;
    }
    if (execution_status_local_nonprim) {
        execution_status_local_nonprim = 0;
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
    if (template_type_local_nonprim) {
        template_type_local_nonprim = 0;
    }
    if (voucher_data_local_nonprim) {
        _free(voucher_data_local_nonprim);
        voucher_data_local_nonprim = NULL;
    }
    return NULL;

}
