#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mirror_trigger_response.h"



static mirror_trigger_response_t *mirror_trigger_response_create_internal(
    char *job_id
    ) {
    mirror_trigger_response_t *mirror_trigger_response_local_var = malloc(sizeof(mirror_trigger_response_t));
    if (!mirror_trigger_response_local_var) {
        return NULL;
    }
    memset(mirror_trigger_response_local_var, 0, sizeof(mirror_trigger_response_t));
    mirror_trigger_response_local_var->_library_owned = 1;
    mirror_trigger_response_local_var->job_id = job_id;
    return mirror_trigger_response_local_var;
}

__attribute__((deprecated)) mirror_trigger_response_t *mirror_trigger_response_create(
    char *job_id
    ) {
    mirror_trigger_response_t *result = mirror_trigger_response_create_internal (
        job_id
        );
    if (!result) {
    }
    return result;
}

void mirror_trigger_response_free(mirror_trigger_response_t *mirror_trigger_response) {
    if(NULL == mirror_trigger_response){
        return ;
    }
    if(mirror_trigger_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "mirror_trigger_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (mirror_trigger_response->job_id) {
        free(mirror_trigger_response->job_id);
        mirror_trigger_response->job_id = NULL;
    }
    free(mirror_trigger_response);
}

cJSON *mirror_trigger_response_convertToJSON(mirror_trigger_response_t *mirror_trigger_response) {
    cJSON *item = cJSON_CreateObject();

    // mirror_trigger_response->job_id
    if (!mirror_trigger_response->job_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "job_id", mirror_trigger_response->job_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

mirror_trigger_response_t *mirror_trigger_response_parseFromJSON(cJSON *mirror_trigger_responseJSON){

    mirror_trigger_response_t *mirror_trigger_response_local_var = NULL;

    char *job_id_local_str = NULL;

    // mirror_trigger_response->job_id
    cJSON *job_id = cJSON_GetObjectItemCaseSensitive(mirror_trigger_responseJSON, "job_id");
    if (cJSON_IsNull(job_id)) {
        job_id = NULL;
    }
    if (!job_id) {
        goto end;
    }

    
    if(!cJSON_IsString(job_id))
    {
    goto end; //String
    }


    if (job_id && !cJSON_IsNull(job_id)) job_id_local_str = strdup(job_id->valuestring);

    mirror_trigger_response_local_var = mirror_trigger_response_create_internal (
        job_id_local_str
        );

    if (!mirror_trigger_response_local_var) {
        goto end;
    }

    return mirror_trigger_response_local_var;
end:
    if (job_id_local_str) {
        free(job_id_local_str);
        job_id_local_str = NULL;
    }
    return NULL;

}
