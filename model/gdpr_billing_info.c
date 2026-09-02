#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gdpr_billing_info.h"



static gdpr_billing_info_t *gdpr_billing_info_create_internal(
    char *current_period_end,
    char *current_period_start,
    char *plan,
    char *status,
    char *tenant_id
    ) {
    gdpr_billing_info_t *gdpr_billing_info_local_var = malloc(sizeof(gdpr_billing_info_t));
    if (!gdpr_billing_info_local_var) {
        return NULL;
    }
    memset(gdpr_billing_info_local_var, 0, sizeof(gdpr_billing_info_t));
    gdpr_billing_info_local_var->_library_owned = 1;
    gdpr_billing_info_local_var->current_period_end = current_period_end;
    gdpr_billing_info_local_var->current_period_start = current_period_start;
    gdpr_billing_info_local_var->plan = plan;
    gdpr_billing_info_local_var->status = status;
    gdpr_billing_info_local_var->tenant_id = tenant_id;
    return gdpr_billing_info_local_var;
}

__attribute__((deprecated)) gdpr_billing_info_t *gdpr_billing_info_create(
    char *current_period_end,
    char *current_period_start,
    char *plan,
    char *status,
    char *tenant_id
    ) {
    gdpr_billing_info_t *result = gdpr_billing_info_create_internal (
        current_period_end,
        current_period_start,
        plan,
        status,
        tenant_id
        );
    if (!result) {
    }
    return result;
}

void gdpr_billing_info_free(gdpr_billing_info_t *gdpr_billing_info) {
    if(NULL == gdpr_billing_info){
        return ;
    }
    if(gdpr_billing_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gdpr_billing_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gdpr_billing_info->current_period_end) {
        free(gdpr_billing_info->current_period_end);
        gdpr_billing_info->current_period_end = NULL;
    }
    if (gdpr_billing_info->current_period_start) {
        free(gdpr_billing_info->current_period_start);
        gdpr_billing_info->current_period_start = NULL;
    }
    if (gdpr_billing_info->plan) {
        free(gdpr_billing_info->plan);
        gdpr_billing_info->plan = NULL;
    }
    if (gdpr_billing_info->status) {
        free(gdpr_billing_info->status);
        gdpr_billing_info->status = NULL;
    }
    if (gdpr_billing_info->tenant_id) {
        free(gdpr_billing_info->tenant_id);
        gdpr_billing_info->tenant_id = NULL;
    }
    free(gdpr_billing_info);
}

cJSON *gdpr_billing_info_convertToJSON(gdpr_billing_info_t *gdpr_billing_info) {
    cJSON *item = cJSON_CreateObject();

    // gdpr_billing_info->current_period_end
    if(gdpr_billing_info->current_period_end) {
    if(cJSON_AddStringToObject(item, "currentPeriodEnd", gdpr_billing_info->current_period_end) == NULL) {
    goto fail; //Date-Time
    }
    }


    // gdpr_billing_info->current_period_start
    if(gdpr_billing_info->current_period_start) {
    if(cJSON_AddStringToObject(item, "currentPeriodStart", gdpr_billing_info->current_period_start) == NULL) {
    goto fail; //Date-Time
    }
    }


    // gdpr_billing_info->plan
    if(gdpr_billing_info->plan) {
    if(cJSON_AddStringToObject(item, "plan", gdpr_billing_info->plan) == NULL) {
    goto fail; //String
    }
    }


    // gdpr_billing_info->status
    if(gdpr_billing_info->status) {
    if(cJSON_AddStringToObject(item, "status", gdpr_billing_info->status) == NULL) {
    goto fail; //String
    }
    }


    // gdpr_billing_info->tenant_id
    if (!gdpr_billing_info->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenantId", gdpr_billing_info->tenant_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gdpr_billing_info_t *gdpr_billing_info_parseFromJSON(cJSON *gdpr_billing_infoJSON){

    gdpr_billing_info_t *gdpr_billing_info_local_var = NULL;

    char *current_period_end_local_str = NULL;

    char *current_period_start_local_str = NULL;

    char *plan_local_str = NULL;

    char *status_local_str = NULL;

    char *tenant_id_local_str = NULL;

    // gdpr_billing_info->current_period_end
    cJSON *current_period_end = cJSON_GetObjectItemCaseSensitive(gdpr_billing_infoJSON, "currentPeriodEnd");
    if (cJSON_IsNull(current_period_end)) {
        current_period_end = NULL;
    }
    if (current_period_end) { 
    if(!cJSON_IsString(current_period_end) && !cJSON_IsNull(current_period_end))
    {
    goto end; //DateTime
    }
    }

    // gdpr_billing_info->current_period_start
    cJSON *current_period_start = cJSON_GetObjectItemCaseSensitive(gdpr_billing_infoJSON, "currentPeriodStart");
    if (cJSON_IsNull(current_period_start)) {
        current_period_start = NULL;
    }
    if (current_period_start) { 
    if(!cJSON_IsString(current_period_start) && !cJSON_IsNull(current_period_start))
    {
    goto end; //DateTime
    }
    }

    // gdpr_billing_info->plan
    cJSON *plan = cJSON_GetObjectItemCaseSensitive(gdpr_billing_infoJSON, "plan");
    if (cJSON_IsNull(plan)) {
        plan = NULL;
    }
    if (plan) { 
    if(!cJSON_IsString(plan) && !cJSON_IsNull(plan))
    {
    goto end; //String
    }
    }

    // gdpr_billing_info->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(gdpr_billing_infoJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // gdpr_billing_info->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(gdpr_billing_infoJSON, "tenantId");
    if (cJSON_IsNull(tenant_id)) {
        tenant_id = NULL;
    }
    if (!tenant_id) {
        goto end;
    }

    
    if(!cJSON_IsString(tenant_id))
    {
    goto end; //String
    }


    if (current_period_end && !cJSON_IsNull(current_period_end)) current_period_end_local_str = strdup(current_period_end->valuestring);
    if (current_period_start && !cJSON_IsNull(current_period_start)) current_period_start_local_str = strdup(current_period_start->valuestring);
    if (plan && !cJSON_IsNull(plan)) plan_local_str = strdup(plan->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);

    gdpr_billing_info_local_var = gdpr_billing_info_create_internal (
        current_period_end_local_str,
        current_period_start_local_str,
        plan_local_str,
        status_local_str,
        tenant_id_local_str
        );

    if (!gdpr_billing_info_local_var) {
        goto end;
    }

    return gdpr_billing_info_local_var;
end:
    if (current_period_end_local_str) {
        free(current_period_end_local_str);
        current_period_end_local_str = NULL;
    }
    if (current_period_start_local_str) {
        free(current_period_start_local_str);
        current_period_start_local_str = NULL;
    }
    if (plan_local_str) {
        free(plan_local_str);
        plan_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    return NULL;

}
