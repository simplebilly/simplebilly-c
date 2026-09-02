#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dpa_status.h"



static dpa_status_t *dpa_status_create_internal(
    int *accepted,
    char *accepted_at,
    char *accepted_by,
    char *version
    ) {
    dpa_status_t *dpa_status_local_var = malloc(sizeof(dpa_status_t));
    if (!dpa_status_local_var) {
        return NULL;
    }
    memset(dpa_status_local_var, 0, sizeof(dpa_status_t));
    dpa_status_local_var->_library_owned = 1;
    dpa_status_local_var->accepted = accepted;
    dpa_status_local_var->accepted_at = accepted_at;
    dpa_status_local_var->accepted_by = accepted_by;
    dpa_status_local_var->version = version;
    return dpa_status_local_var;
}

__attribute__((deprecated)) dpa_status_t *dpa_status_create(
    int *accepted,
    char *accepted_at,
    char *accepted_by,
    char *version
    ) {
    int *accepted_copy = NULL;
    if (accepted) {
        accepted_copy = malloc(sizeof(int));
        if (accepted_copy) *accepted_copy = *accepted;
    }
    dpa_status_t *result = dpa_status_create_internal (
        accepted_copy,
        accepted_at,
        accepted_by,
        version
        );
    if (!result) {
        free(accepted_copy);
    }
    return result;
}

void dpa_status_free(dpa_status_t *dpa_status) {
    if(NULL == dpa_status){
        return ;
    }
    if(dpa_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "dpa_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (dpa_status->accepted) {
        free(dpa_status->accepted);
        dpa_status->accepted = NULL;
    }
    if (dpa_status->accepted_at) {
        free(dpa_status->accepted_at);
        dpa_status->accepted_at = NULL;
    }
    if (dpa_status->accepted_by) {
        free(dpa_status->accepted_by);
        dpa_status->accepted_by = NULL;
    }
    if (dpa_status->version) {
        free(dpa_status->version);
        dpa_status->version = NULL;
    }
    free(dpa_status);
}

cJSON *dpa_status_convertToJSON(dpa_status_t *dpa_status) {
    cJSON *item = cJSON_CreateObject();

    // dpa_status->accepted
    if (!dpa_status->accepted) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "accepted", *dpa_status->accepted) == NULL) {
    goto fail; //Bool
    }


    // dpa_status->accepted_at
    if(dpa_status->accepted_at) {
    if(cJSON_AddStringToObject(item, "acceptedAt", dpa_status->accepted_at) == NULL) {
    goto fail; //String
    }
    }


    // dpa_status->accepted_by
    if(dpa_status->accepted_by) {
    if(cJSON_AddStringToObject(item, "acceptedBy", dpa_status->accepted_by) == NULL) {
    goto fail; //String
    }
    }


    // dpa_status->version
    if(dpa_status->version) {
    if(cJSON_AddStringToObject(item, "version", dpa_status->version) == NULL) {
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

dpa_status_t *dpa_status_parseFromJSON(cJSON *dpa_statusJSON){

    dpa_status_t *dpa_status_local_var = NULL;

    // define the local variable for dpa_status->accepted
    int *accepted_local_var = NULL;

    char *accepted_at_local_str = NULL;

    char *accepted_by_local_str = NULL;

    char *version_local_str = NULL;

    // dpa_status->accepted
    cJSON *accepted = cJSON_GetObjectItemCaseSensitive(dpa_statusJSON, "accepted");
    if (cJSON_IsNull(accepted)) {
        accepted = NULL;
    }
    if (!accepted) {
        goto end;
    }

    
    if(!cJSON_IsBool(accepted))
    {
    goto end; //Bool
    }
    accepted_local_var = malloc(sizeof(int));
    if(!accepted_local_var)
    {
        goto end;
    }
    *accepted_local_var = accepted->valueint;

    // dpa_status->accepted_at
    cJSON *accepted_at = cJSON_GetObjectItemCaseSensitive(dpa_statusJSON, "acceptedAt");
    if (cJSON_IsNull(accepted_at)) {
        accepted_at = NULL;
    }
    if (accepted_at) { 
    if(!cJSON_IsString(accepted_at) && !cJSON_IsNull(accepted_at))
    {
    goto end; //String
    }
    }

    // dpa_status->accepted_by
    cJSON *accepted_by = cJSON_GetObjectItemCaseSensitive(dpa_statusJSON, "acceptedBy");
    if (cJSON_IsNull(accepted_by)) {
        accepted_by = NULL;
    }
    if (accepted_by) { 
    if(!cJSON_IsString(accepted_by) && !cJSON_IsNull(accepted_by))
    {
    goto end; //String
    }
    }

    // dpa_status->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(dpa_statusJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    if (accepted_at && !cJSON_IsNull(accepted_at)) accepted_at_local_str = strdup(accepted_at->valuestring);
    if (accepted_by && !cJSON_IsNull(accepted_by)) accepted_by_local_str = strdup(accepted_by->valuestring);
    if (version && !cJSON_IsNull(version)) version_local_str = strdup(version->valuestring);

    dpa_status_local_var = dpa_status_create_internal (
        accepted_local_var,
        accepted_at_local_str,
        accepted_by_local_str,
        version_local_str
        );

    if (!dpa_status_local_var) {
        goto end;
    }

    return dpa_status_local_var;
end:
    if (accepted_local_var) {
        free(accepted_local_var);
        accepted_local_var = NULL;
    }
    if (accepted_at_local_str) {
        free(accepted_at_local_str);
        accepted_at_local_str = NULL;
    }
    if (accepted_by_local_str) {
        free(accepted_by_local_str);
        accepted_by_local_str = NULL;
    }
    if (version_local_str) {
        free(version_local_str);
        version_local_str = NULL;
    }
    return NULL;

}
