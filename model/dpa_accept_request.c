#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dpa_accept_request.h"



static dpa_accept_request_t *dpa_accept_request_create_internal(
    char *accepted_by_name,
    char *version
    ) {
    dpa_accept_request_t *dpa_accept_request_local_var = malloc(sizeof(dpa_accept_request_t));
    if (!dpa_accept_request_local_var) {
        return NULL;
    }
    memset(dpa_accept_request_local_var, 0, sizeof(dpa_accept_request_t));
    dpa_accept_request_local_var->_library_owned = 1;
    dpa_accept_request_local_var->accepted_by_name = accepted_by_name;
    dpa_accept_request_local_var->version = version;
    return dpa_accept_request_local_var;
}

__attribute__((deprecated)) dpa_accept_request_t *dpa_accept_request_create(
    char *accepted_by_name,
    char *version
    ) {
    dpa_accept_request_t *result = dpa_accept_request_create_internal (
        accepted_by_name,
        version
        );
    if (!result) {
    }
    return result;
}

void dpa_accept_request_free(dpa_accept_request_t *dpa_accept_request) {
    if(NULL == dpa_accept_request){
        return ;
    }
    if(dpa_accept_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "dpa_accept_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (dpa_accept_request->accepted_by_name) {
        free(dpa_accept_request->accepted_by_name);
        dpa_accept_request->accepted_by_name = NULL;
    }
    if (dpa_accept_request->version) {
        free(dpa_accept_request->version);
        dpa_accept_request->version = NULL;
    }
    free(dpa_accept_request);
}

cJSON *dpa_accept_request_convertToJSON(dpa_accept_request_t *dpa_accept_request) {
    cJSON *item = cJSON_CreateObject();

    // dpa_accept_request->accepted_by_name
    if (!dpa_accept_request->accepted_by_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "acceptedByName", dpa_accept_request->accepted_by_name) == NULL) {
    goto fail; //String
    }


    // dpa_accept_request->version
    if (!dpa_accept_request->version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "version", dpa_accept_request->version) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

dpa_accept_request_t *dpa_accept_request_parseFromJSON(cJSON *dpa_accept_requestJSON){

    dpa_accept_request_t *dpa_accept_request_local_var = NULL;

    char *accepted_by_name_local_str = NULL;

    char *version_local_str = NULL;

    // dpa_accept_request->accepted_by_name
    cJSON *accepted_by_name = cJSON_GetObjectItemCaseSensitive(dpa_accept_requestJSON, "acceptedByName");
    if (cJSON_IsNull(accepted_by_name)) {
        accepted_by_name = NULL;
    }
    if (!accepted_by_name) {
        goto end;
    }

    
    if(!cJSON_IsString(accepted_by_name))
    {
    goto end; //String
    }

    // dpa_accept_request->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(dpa_accept_requestJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (!version) {
        goto end;
    }

    
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }


    if (accepted_by_name && !cJSON_IsNull(accepted_by_name)) accepted_by_name_local_str = strdup(accepted_by_name->valuestring);
    if (version && !cJSON_IsNull(version)) version_local_str = strdup(version->valuestring);

    dpa_accept_request_local_var = dpa_accept_request_create_internal (
        accepted_by_name_local_str,
        version_local_str
        );

    if (!dpa_accept_request_local_var) {
        goto end;
    }

    return dpa_accept_request_local_var;
end:
    if (accepted_by_name_local_str) {
        free(accepted_by_name_local_str);
        accepted_by_name_local_str = NULL;
    }
    if (version_local_str) {
        free(version_local_str);
        version_local_str = NULL;
    }
    return NULL;

}
