#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plausibility_check.h"



static plausibility_check_t *plausibility_check_create_internal(
    char *detail,
    char *id,
    char *name,
    simplebilly_api_severity__e severity,
    simplebilly_api_check_status__e status
    ) {
    plausibility_check_t *plausibility_check_local_var = malloc(sizeof(plausibility_check_t));
    if (!plausibility_check_local_var) {
        return NULL;
    }
    memset(plausibility_check_local_var, 0, sizeof(plausibility_check_t));
    plausibility_check_local_var->_library_owned = 1;
    plausibility_check_local_var->detail = detail;
    plausibility_check_local_var->id = id;
    plausibility_check_local_var->name = name;
    plausibility_check_local_var->severity = severity;
    plausibility_check_local_var->status = status;
    return plausibility_check_local_var;
}

__attribute__((deprecated)) plausibility_check_t *plausibility_check_create(
    char *detail,
    char *id,
    char *name,
    simplebilly_api_severity__e severity,
    simplebilly_api_check_status__e status
    ) {
    plausibility_check_t *result = plausibility_check_create_internal (
        detail,
        id,
        name,
        severity,
        status
        );
    if (!result) {
    }
    return result;
}

void plausibility_check_free(plausibility_check_t *plausibility_check) {
    if(NULL == plausibility_check){
        return ;
    }
    if(plausibility_check->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plausibility_check_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plausibility_check->detail) {
        free(plausibility_check->detail);
        plausibility_check->detail = NULL;
    }
    if (plausibility_check->id) {
        free(plausibility_check->id);
        plausibility_check->id = NULL;
    }
    if (plausibility_check->name) {
        free(plausibility_check->name);
        plausibility_check->name = NULL;
    }
    free(plausibility_check);
}

cJSON *plausibility_check_convertToJSON(plausibility_check_t *plausibility_check) {
    cJSON *item = cJSON_CreateObject();

    // plausibility_check->detail
    if (!plausibility_check->detail) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "detail", plausibility_check->detail) == NULL) {
    goto fail; //String
    }


    // plausibility_check->id
    if (!plausibility_check->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", plausibility_check->id) == NULL) {
    goto fail; //String
    }


    // plausibility_check->name
    if (!plausibility_check->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", plausibility_check->name) == NULL) {
    goto fail; //String
    }


    // plausibility_check->severity
    if (simplebilly_api_severity__NULL == plausibility_check->severity) {
        goto fail;
    }
    cJSON *severity_local_JSON = severity_convertToJSON(plausibility_check->severity);
    if(severity_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "severity", severity_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // plausibility_check->status
    if (simplebilly_api_check_status__NULL == plausibility_check->status) {
        goto fail;
    }
    cJSON *status_local_JSON = check_status_convertToJSON(plausibility_check->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
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

plausibility_check_t *plausibility_check_parseFromJSON(cJSON *plausibility_checkJSON){

    plausibility_check_t *plausibility_check_local_var = NULL;

    char *detail_local_str = NULL;

    char *id_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for plausibility_check->severity
    simplebilly_api_severity__e severity_local_nonprim = 0;

    // define the local variable for plausibility_check->status
    simplebilly_api_check_status__e status_local_nonprim = 0;

    // plausibility_check->detail
    cJSON *detail = cJSON_GetObjectItemCaseSensitive(plausibility_checkJSON, "detail");
    if (cJSON_IsNull(detail)) {
        detail = NULL;
    }
    if (!detail) {
        goto end;
    }

    
    if(!cJSON_IsString(detail))
    {
    goto end; //String
    }

    // plausibility_check->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(plausibility_checkJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // plausibility_check->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(plausibility_checkJSON, "name");
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

    // plausibility_check->severity
    cJSON *severity = cJSON_GetObjectItemCaseSensitive(plausibility_checkJSON, "severity");
    if (cJSON_IsNull(severity)) {
        severity = NULL;
    }
    if (!severity) {
        goto end;
    }

    
    severity_local_nonprim = severity_parseFromJSON(severity); //custom

    // plausibility_check->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(plausibility_checkJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = check_status_parseFromJSON(status); //custom


    if (detail && !cJSON_IsNull(detail)) detail_local_str = strdup(detail->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    plausibility_check_local_var = plausibility_check_create_internal (
        detail_local_str,
        id_local_str,
        name_local_str,
        severity_local_nonprim,
        status_local_nonprim
        );

    if (!plausibility_check_local_var) {
        goto end;
    }

    return plausibility_check_local_var;
end:
    if (detail_local_str) {
        free(detail_local_str);
        detail_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (severity_local_nonprim) {
        severity_local_nonprim = 0;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    return NULL;

}
