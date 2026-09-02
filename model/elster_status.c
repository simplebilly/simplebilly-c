#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "elster_status.h"



static elster_status_t *elster_status_create_internal(
    int *cert_configured,
    int *eric_available,
    char *eric_version,
    int *feature_enabled,
    char *hint,
    char *mode,
    int *vendor_id_configured
    ) {
    elster_status_t *elster_status_local_var = malloc(sizeof(elster_status_t));
    if (!elster_status_local_var) {
        return NULL;
    }
    memset(elster_status_local_var, 0, sizeof(elster_status_t));
    elster_status_local_var->_library_owned = 1;
    elster_status_local_var->cert_configured = cert_configured;
    elster_status_local_var->eric_available = eric_available;
    elster_status_local_var->eric_version = eric_version;
    elster_status_local_var->feature_enabled = feature_enabled;
    elster_status_local_var->hint = hint;
    elster_status_local_var->mode = mode;
    elster_status_local_var->vendor_id_configured = vendor_id_configured;
    return elster_status_local_var;
}

__attribute__((deprecated)) elster_status_t *elster_status_create(
    int *cert_configured,
    int *eric_available,
    char *eric_version,
    int *feature_enabled,
    char *hint,
    char *mode,
    int *vendor_id_configured
    ) {
    int *cert_configured_copy = NULL;
    if (cert_configured) {
        cert_configured_copy = malloc(sizeof(int));
        if (cert_configured_copy) *cert_configured_copy = *cert_configured;
    }
    int *eric_available_copy = NULL;
    if (eric_available) {
        eric_available_copy = malloc(sizeof(int));
        if (eric_available_copy) *eric_available_copy = *eric_available;
    }
    int *feature_enabled_copy = NULL;
    if (feature_enabled) {
        feature_enabled_copy = malloc(sizeof(int));
        if (feature_enabled_copy) *feature_enabled_copy = *feature_enabled;
    }
    int *vendor_id_configured_copy = NULL;
    if (vendor_id_configured) {
        vendor_id_configured_copy = malloc(sizeof(int));
        if (vendor_id_configured_copy) *vendor_id_configured_copy = *vendor_id_configured;
    }
    elster_status_t *result = elster_status_create_internal (
        cert_configured_copy,
        eric_available_copy,
        eric_version,
        feature_enabled_copy,
        hint,
        mode,
        vendor_id_configured_copy
        );
    if (!result) {
        free(cert_configured_copy);
        free(eric_available_copy);
        free(feature_enabled_copy);
        free(vendor_id_configured_copy);
    }
    return result;
}

void elster_status_free(elster_status_t *elster_status) {
    if(NULL == elster_status){
        return ;
    }
    if(elster_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "elster_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (elster_status->cert_configured) {
        free(elster_status->cert_configured);
        elster_status->cert_configured = NULL;
    }
    if (elster_status->eric_available) {
        free(elster_status->eric_available);
        elster_status->eric_available = NULL;
    }
    if (elster_status->eric_version) {
        free(elster_status->eric_version);
        elster_status->eric_version = NULL;
    }
    if (elster_status->feature_enabled) {
        free(elster_status->feature_enabled);
        elster_status->feature_enabled = NULL;
    }
    if (elster_status->hint) {
        free(elster_status->hint);
        elster_status->hint = NULL;
    }
    if (elster_status->mode) {
        free(elster_status->mode);
        elster_status->mode = NULL;
    }
    if (elster_status->vendor_id_configured) {
        free(elster_status->vendor_id_configured);
        elster_status->vendor_id_configured = NULL;
    }
    free(elster_status);
}

cJSON *elster_status_convertToJSON(elster_status_t *elster_status) {
    cJSON *item = cJSON_CreateObject();

    // elster_status->cert_configured
    if (!elster_status->cert_configured) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "cert_configured", *elster_status->cert_configured) == NULL) {
    goto fail; //Bool
    }


    // elster_status->eric_available
    if (!elster_status->eric_available) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "eric_available", *elster_status->eric_available) == NULL) {
    goto fail; //Bool
    }


    // elster_status->eric_version
    if(elster_status->eric_version) {
    if(cJSON_AddStringToObject(item, "eric_version", elster_status->eric_version) == NULL) {
    goto fail; //String
    }
    }


    // elster_status->feature_enabled
    if (!elster_status->feature_enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "feature_enabled", *elster_status->feature_enabled) == NULL) {
    goto fail; //Bool
    }


    // elster_status->hint
    if (!elster_status->hint) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hint", elster_status->hint) == NULL) {
    goto fail; //String
    }


    // elster_status->mode
    if (!elster_status->mode) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mode", elster_status->mode) == NULL) {
    goto fail; //String
    }


    // elster_status->vendor_id_configured
    if (!elster_status->vendor_id_configured) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "vendor_id_configured", *elster_status->vendor_id_configured) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

elster_status_t *elster_status_parseFromJSON(cJSON *elster_statusJSON){

    elster_status_t *elster_status_local_var = NULL;

    // define the local variable for elster_status->cert_configured
    int *cert_configured_local_var = NULL;

    // define the local variable for elster_status->eric_available
    int *eric_available_local_var = NULL;

    char *eric_version_local_str = NULL;

    // define the local variable for elster_status->feature_enabled
    int *feature_enabled_local_var = NULL;

    char *hint_local_str = NULL;

    char *mode_local_str = NULL;

    // define the local variable for elster_status->vendor_id_configured
    int *vendor_id_configured_local_var = NULL;

    // elster_status->cert_configured
    cJSON *cert_configured = cJSON_GetObjectItemCaseSensitive(elster_statusJSON, "cert_configured");
    if (cJSON_IsNull(cert_configured)) {
        cert_configured = NULL;
    }
    if (!cert_configured) {
        goto end;
    }

    
    if(!cJSON_IsBool(cert_configured))
    {
    goto end; //Bool
    }
    cert_configured_local_var = malloc(sizeof(int));
    if(!cert_configured_local_var)
    {
        goto end;
    }
    *cert_configured_local_var = cert_configured->valueint;

    // elster_status->eric_available
    cJSON *eric_available = cJSON_GetObjectItemCaseSensitive(elster_statusJSON, "eric_available");
    if (cJSON_IsNull(eric_available)) {
        eric_available = NULL;
    }
    if (!eric_available) {
        goto end;
    }

    
    if(!cJSON_IsBool(eric_available))
    {
    goto end; //Bool
    }
    eric_available_local_var = malloc(sizeof(int));
    if(!eric_available_local_var)
    {
        goto end;
    }
    *eric_available_local_var = eric_available->valueint;

    // elster_status->eric_version
    cJSON *eric_version = cJSON_GetObjectItemCaseSensitive(elster_statusJSON, "eric_version");
    if (cJSON_IsNull(eric_version)) {
        eric_version = NULL;
    }
    if (eric_version) { 
    if(!cJSON_IsString(eric_version) && !cJSON_IsNull(eric_version))
    {
    goto end; //String
    }
    }

    // elster_status->feature_enabled
    cJSON *feature_enabled = cJSON_GetObjectItemCaseSensitive(elster_statusJSON, "feature_enabled");
    if (cJSON_IsNull(feature_enabled)) {
        feature_enabled = NULL;
    }
    if (!feature_enabled) {
        goto end;
    }

    
    if(!cJSON_IsBool(feature_enabled))
    {
    goto end; //Bool
    }
    feature_enabled_local_var = malloc(sizeof(int));
    if(!feature_enabled_local_var)
    {
        goto end;
    }
    *feature_enabled_local_var = feature_enabled->valueint;

    // elster_status->hint
    cJSON *hint = cJSON_GetObjectItemCaseSensitive(elster_statusJSON, "hint");
    if (cJSON_IsNull(hint)) {
        hint = NULL;
    }
    if (!hint) {
        goto end;
    }

    
    if(!cJSON_IsString(hint))
    {
    goto end; //String
    }

    // elster_status->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(elster_statusJSON, "mode");
    if (cJSON_IsNull(mode)) {
        mode = NULL;
    }
    if (!mode) {
        goto end;
    }

    
    if(!cJSON_IsString(mode))
    {
    goto end; //String
    }

    // elster_status->vendor_id_configured
    cJSON *vendor_id_configured = cJSON_GetObjectItemCaseSensitive(elster_statusJSON, "vendor_id_configured");
    if (cJSON_IsNull(vendor_id_configured)) {
        vendor_id_configured = NULL;
    }
    if (!vendor_id_configured) {
        goto end;
    }

    
    if(!cJSON_IsBool(vendor_id_configured))
    {
    goto end; //Bool
    }
    vendor_id_configured_local_var = malloc(sizeof(int));
    if(!vendor_id_configured_local_var)
    {
        goto end;
    }
    *vendor_id_configured_local_var = vendor_id_configured->valueint;


    if (eric_version && !cJSON_IsNull(eric_version)) eric_version_local_str = strdup(eric_version->valuestring);
    if (hint && !cJSON_IsNull(hint)) hint_local_str = strdup(hint->valuestring);
    if (mode && !cJSON_IsNull(mode)) mode_local_str = strdup(mode->valuestring);

    elster_status_local_var = elster_status_create_internal (
        cert_configured_local_var,
        eric_available_local_var,
        eric_version_local_str,
        feature_enabled_local_var,
        hint_local_str,
        mode_local_str,
        vendor_id_configured_local_var
        );

    if (!elster_status_local_var) {
        goto end;
    }

    return elster_status_local_var;
end:
    if (cert_configured_local_var) {
        free(cert_configured_local_var);
        cert_configured_local_var = NULL;
    }
    if (eric_available_local_var) {
        free(eric_available_local_var);
        eric_available_local_var = NULL;
    }
    if (eric_version_local_str) {
        free(eric_version_local_str);
        eric_version_local_str = NULL;
    }
    if (feature_enabled_local_var) {
        free(feature_enabled_local_var);
        feature_enabled_local_var = NULL;
    }
    if (hint_local_str) {
        free(hint_local_str);
        hint_local_str = NULL;
    }
    if (mode_local_str) {
        free(mode_local_str);
        mode_local_str = NULL;
    }
    if (vendor_id_configured_local_var) {
        free(vendor_id_configured_local_var);
        vendor_id_configured_local_var = NULL;
    }
    return NULL;

}
