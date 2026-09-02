#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "import_start_response.h"



static import_start_response_t *import_start_response_create_internal(
    char *job_id
    ) {
    import_start_response_t *import_start_response_local_var = malloc(sizeof(import_start_response_t));
    if (!import_start_response_local_var) {
        return NULL;
    }
    memset(import_start_response_local_var, 0, sizeof(import_start_response_t));
    import_start_response_local_var->_library_owned = 1;
    import_start_response_local_var->job_id = job_id;
    return import_start_response_local_var;
}

__attribute__((deprecated)) import_start_response_t *import_start_response_create(
    char *job_id
    ) {
    import_start_response_t *result = import_start_response_create_internal (
        job_id
        );
    if (!result) {
    }
    return result;
}

void import_start_response_free(import_start_response_t *import_start_response) {
    if(NULL == import_start_response){
        return ;
    }
    if(import_start_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "import_start_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (import_start_response->job_id) {
        free(import_start_response->job_id);
        import_start_response->job_id = NULL;
    }
    free(import_start_response);
}

cJSON *import_start_response_convertToJSON(import_start_response_t *import_start_response) {
    cJSON *item = cJSON_CreateObject();

    // import_start_response->job_id
    if (!import_start_response->job_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "job_id", import_start_response->job_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

import_start_response_t *import_start_response_parseFromJSON(cJSON *import_start_responseJSON){

    import_start_response_t *import_start_response_local_var = NULL;

    char *job_id_local_str = NULL;

    // import_start_response->job_id
    cJSON *job_id = cJSON_GetObjectItemCaseSensitive(import_start_responseJSON, "job_id");
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

    import_start_response_local_var = import_start_response_create_internal (
        job_id_local_str
        );

    if (!import_start_response_local_var) {
        goto end;
    }

    return import_start_response_local_var;
end:
    if (job_id_local_str) {
        free(job_id_local_str);
        job_id_local_str = NULL;
    }
    return NULL;

}
