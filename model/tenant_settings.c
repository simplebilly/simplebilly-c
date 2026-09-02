#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tenant_settings.h"



static tenant_settings_t *tenant_settings_create_internal(
    simplebilly_api_company_type__e company_type,
    char *dpa_accepted_at,
    char *dpa_accepted_by,
    char *dpa_version,
    any_type_t *features
    ) {
    tenant_settings_t *tenant_settings_local_var = malloc(sizeof(tenant_settings_t));
    if (!tenant_settings_local_var) {
        return NULL;
    }
    memset(tenant_settings_local_var, 0, sizeof(tenant_settings_t));
    tenant_settings_local_var->_library_owned = 1;
    tenant_settings_local_var->company_type = company_type;
    tenant_settings_local_var->dpa_accepted_at = dpa_accepted_at;
    tenant_settings_local_var->dpa_accepted_by = dpa_accepted_by;
    tenant_settings_local_var->dpa_version = dpa_version;
    tenant_settings_local_var->features = features;
    return tenant_settings_local_var;
}

__attribute__((deprecated)) tenant_settings_t *tenant_settings_create(
    simplebilly_api_company_type__e company_type,
    char *dpa_accepted_at,
    char *dpa_accepted_by,
    char *dpa_version,
    any_type_t *features
    ) {
    tenant_settings_t *result = tenant_settings_create_internal (
        company_type,
        dpa_accepted_at,
        dpa_accepted_by,
        dpa_version,
        features
        );
    if (!result) {
    }
    return result;
}

void tenant_settings_free(tenant_settings_t *tenant_settings) {
    if(NULL == tenant_settings){
        return ;
    }
    if(tenant_settings->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "tenant_settings_free");
        return ;
    }
    listEntry_t *listEntry;
    if (tenant_settings->dpa_accepted_at) {
        free(tenant_settings->dpa_accepted_at);
        tenant_settings->dpa_accepted_at = NULL;
    }
    if (tenant_settings->dpa_accepted_by) {
        free(tenant_settings->dpa_accepted_by);
        tenant_settings->dpa_accepted_by = NULL;
    }
    if (tenant_settings->dpa_version) {
        free(tenant_settings->dpa_version);
        tenant_settings->dpa_version = NULL;
    }
    if (tenant_settings->features) {
        _free(tenant_settings->features);
        tenant_settings->features = NULL;
    }
    free(tenant_settings);
}

cJSON *tenant_settings_convertToJSON(tenant_settings_t *tenant_settings) {
    cJSON *item = cJSON_CreateObject();

    // tenant_settings->company_type
    if (simplebilly_api_company_type__NULL == tenant_settings->company_type) {
        goto fail;
    }
    cJSON *company_type_local_JSON = company_type_convertToJSON(tenant_settings->company_type);
    if(company_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "companyType", company_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // tenant_settings->dpa_accepted_at
    if(tenant_settings->dpa_accepted_at) {
    if(cJSON_AddStringToObject(item, "dpaAcceptedAt", tenant_settings->dpa_accepted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // tenant_settings->dpa_accepted_by
    if(tenant_settings->dpa_accepted_by) {
    if(cJSON_AddStringToObject(item, "dpaAcceptedBy", tenant_settings->dpa_accepted_by) == NULL) {
    goto fail; //String
    }
    }


    // tenant_settings->dpa_version
    if(tenant_settings->dpa_version) {
    if(cJSON_AddStringToObject(item, "dpaVersion", tenant_settings->dpa_version) == NULL) {
    goto fail; //String
    }
    }


    // tenant_settings->features
    if (!tenant_settings->features) {
        goto fail;
    }
    cJSON *features_local_JSON = _convertToJSON(tenant_settings->features);
    if(features_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "features", features_local_JSON);
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

tenant_settings_t *tenant_settings_parseFromJSON(cJSON *tenant_settingsJSON){

    tenant_settings_t *tenant_settings_local_var = NULL;

    // define the local variable for tenant_settings->company_type
    simplebilly_api_company_type__e company_type_local_nonprim = 0;

    char *dpa_accepted_at_local_str = NULL;

    char *dpa_accepted_by_local_str = NULL;

    char *dpa_version_local_str = NULL;

    // define the local variable for tenant_settings->features
    _t *features_local_nonprim = NULL;

    // tenant_settings->company_type
    cJSON *company_type = cJSON_GetObjectItemCaseSensitive(tenant_settingsJSON, "companyType");
    if (cJSON_IsNull(company_type)) {
        company_type = NULL;
    }
    if (!company_type) {
        goto end;
    }

    
    company_type_local_nonprim = company_type_parseFromJSON(company_type); //custom

    // tenant_settings->dpa_accepted_at
    cJSON *dpa_accepted_at = cJSON_GetObjectItemCaseSensitive(tenant_settingsJSON, "dpaAcceptedAt");
    if (cJSON_IsNull(dpa_accepted_at)) {
        dpa_accepted_at = NULL;
    }
    if (dpa_accepted_at) { 
    if(!cJSON_IsString(dpa_accepted_at) && !cJSON_IsNull(dpa_accepted_at))
    {
    goto end; //DateTime
    }
    }

    // tenant_settings->dpa_accepted_by
    cJSON *dpa_accepted_by = cJSON_GetObjectItemCaseSensitive(tenant_settingsJSON, "dpaAcceptedBy");
    if (cJSON_IsNull(dpa_accepted_by)) {
        dpa_accepted_by = NULL;
    }
    if (dpa_accepted_by) { 
    if(!cJSON_IsString(dpa_accepted_by) && !cJSON_IsNull(dpa_accepted_by))
    {
    goto end; //String
    }
    }

    // tenant_settings->dpa_version
    cJSON *dpa_version = cJSON_GetObjectItemCaseSensitive(tenant_settingsJSON, "dpaVersion");
    if (cJSON_IsNull(dpa_version)) {
        dpa_version = NULL;
    }
    if (dpa_version) { 
    if(!cJSON_IsString(dpa_version) && !cJSON_IsNull(dpa_version))
    {
    goto end; //String
    }
    }

    // tenant_settings->features
    cJSON *features = cJSON_GetObjectItemCaseSensitive(tenant_settingsJSON, "features");
    if (cJSON_IsNull(features)) {
        features = NULL;
    }
    if (!features) {
        goto end;
    }

    
    features_local_nonprim = _parseFromJSON(features); //custom


    if (dpa_accepted_at && !cJSON_IsNull(dpa_accepted_at)) dpa_accepted_at_local_str = strdup(dpa_accepted_at->valuestring);
    if (dpa_accepted_by && !cJSON_IsNull(dpa_accepted_by)) dpa_accepted_by_local_str = strdup(dpa_accepted_by->valuestring);
    if (dpa_version && !cJSON_IsNull(dpa_version)) dpa_version_local_str = strdup(dpa_version->valuestring);

    tenant_settings_local_var = tenant_settings_create_internal (
        company_type_local_nonprim,
        dpa_accepted_at_local_str,
        dpa_accepted_by_local_str,
        dpa_version_local_str,
        features_local_nonprim
        );

    if (!tenant_settings_local_var) {
        goto end;
    }

    return tenant_settings_local_var;
end:
    if (company_type_local_nonprim) {
        company_type_local_nonprim = 0;
    }
    if (dpa_accepted_at_local_str) {
        free(dpa_accepted_at_local_str);
        dpa_accepted_at_local_str = NULL;
    }
    if (dpa_accepted_by_local_str) {
        free(dpa_accepted_by_local_str);
        dpa_accepted_by_local_str = NULL;
    }
    if (dpa_version_local_str) {
        free(dpa_version_local_str);
        dpa_version_local_str = NULL;
    }
    if (features_local_nonprim) {
        _free(features_local_nonprim);
        features_local_nonprim = NULL;
    }
    return NULL;

}
