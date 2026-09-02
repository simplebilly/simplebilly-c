#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "import_job_status.h"



static import_job_status_t *import_job_status_create_internal(
    char *error,
    char *job_id,
    long *processed,
    int *progress,
    char *provider,
    char *stage,
    char *status,
    long *total
    ) {
    import_job_status_t *import_job_status_local_var = malloc(sizeof(import_job_status_t));
    if (!import_job_status_local_var) {
        return NULL;
    }
    memset(import_job_status_local_var, 0, sizeof(import_job_status_t));
    import_job_status_local_var->_library_owned = 1;
    import_job_status_local_var->error = error;
    import_job_status_local_var->job_id = job_id;
    import_job_status_local_var->processed = processed;
    import_job_status_local_var->progress = progress;
    import_job_status_local_var->provider = provider;
    import_job_status_local_var->stage = stage;
    import_job_status_local_var->status = status;
    import_job_status_local_var->total = total;
    return import_job_status_local_var;
}

__attribute__((deprecated)) import_job_status_t *import_job_status_create(
    char *error,
    char *job_id,
    long *processed,
    int *progress,
    char *provider,
    char *stage,
    char *status,
    long *total
    ) {
    long *processed_copy = NULL;
    if (processed) {
        processed_copy = malloc(sizeof(long));
        if (processed_copy) *processed_copy = *processed;
    }
    int *progress_copy = NULL;
    if (progress) {
        progress_copy = malloc(sizeof(int));
        if (progress_copy) *progress_copy = *progress;
    }
    long *total_copy = NULL;
    if (total) {
        total_copy = malloc(sizeof(long));
        if (total_copy) *total_copy = *total;
    }
    import_job_status_t *result = import_job_status_create_internal (
        error,
        job_id,
        processed_copy,
        progress_copy,
        provider,
        stage,
        status,
        total_copy
        );
    if (!result) {
        free(processed_copy);
        free(progress_copy);
        free(total_copy);
    }
    return result;
}

void import_job_status_free(import_job_status_t *import_job_status) {
    if(NULL == import_job_status){
        return ;
    }
    if(import_job_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "import_job_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (import_job_status->error) {
        free(import_job_status->error);
        import_job_status->error = NULL;
    }
    if (import_job_status->job_id) {
        free(import_job_status->job_id);
        import_job_status->job_id = NULL;
    }
    if (import_job_status->processed) {
        free(import_job_status->processed);
        import_job_status->processed = NULL;
    }
    if (import_job_status->progress) {
        free(import_job_status->progress);
        import_job_status->progress = NULL;
    }
    if (import_job_status->provider) {
        free(import_job_status->provider);
        import_job_status->provider = NULL;
    }
    if (import_job_status->stage) {
        free(import_job_status->stage);
        import_job_status->stage = NULL;
    }
    if (import_job_status->status) {
        free(import_job_status->status);
        import_job_status->status = NULL;
    }
    if (import_job_status->total) {
        free(import_job_status->total);
        import_job_status->total = NULL;
    }
    free(import_job_status);
}

cJSON *import_job_status_convertToJSON(import_job_status_t *import_job_status) {
    cJSON *item = cJSON_CreateObject();

    // import_job_status->error
    if(import_job_status->error) {
    if(cJSON_AddStringToObject(item, "error", import_job_status->error) == NULL) {
    goto fail; //String
    }
    }


    // import_job_status->job_id
    if (!import_job_status->job_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "job_id", import_job_status->job_id) == NULL) {
    goto fail; //String
    }


    // import_job_status->processed
    if (!import_job_status->processed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "processed", *import_job_status->processed) == NULL) {
    goto fail; //Numeric
    }


    // import_job_status->progress
    if (!import_job_status->progress) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "progress", *import_job_status->progress) == NULL) {
    goto fail; //Numeric
    }


    // import_job_status->provider
    if(import_job_status->provider) {
    if(cJSON_AddStringToObject(item, "provider", import_job_status->provider) == NULL) {
    goto fail; //String
    }
    }


    // import_job_status->stage
    if (!import_job_status->stage) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "stage", import_job_status->stage) == NULL) {
    goto fail; //String
    }


    // import_job_status->status
    if (!import_job_status->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", import_job_status->status) == NULL) {
    goto fail; //String
    }


    // import_job_status->total
    if (!import_job_status->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", *import_job_status->total) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

import_job_status_t *import_job_status_parseFromJSON(cJSON *import_job_statusJSON){

    import_job_status_t *import_job_status_local_var = NULL;

    char *error_local_str = NULL;

    char *job_id_local_str = NULL;

    // define the local variable for import_job_status->processed
    long *processed_local_var = NULL;

    // define the local variable for import_job_status->progress
    int *progress_local_var = NULL;

    char *provider_local_str = NULL;

    char *stage_local_str = NULL;

    char *status_local_str = NULL;

    // define the local variable for import_job_status->total
    long *total_local_var = NULL;

    // import_job_status->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(import_job_statusJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // import_job_status->job_id
    cJSON *job_id = cJSON_GetObjectItemCaseSensitive(import_job_statusJSON, "job_id");
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

    // import_job_status->processed
    cJSON *processed = cJSON_GetObjectItemCaseSensitive(import_job_statusJSON, "processed");
    if (cJSON_IsNull(processed)) {
        processed = NULL;
    }
    if (!processed) {
        goto end;
    }

    
    if(!cJSON_IsNumber(processed))
    {
    goto end; //Numeric
    }
    processed_local_var = malloc(sizeof(long));
    if(!processed_local_var)
    {
        goto end;
    }
    *processed_local_var = processed->valuedouble;

    // import_job_status->progress
    cJSON *progress = cJSON_GetObjectItemCaseSensitive(import_job_statusJSON, "progress");
    if (cJSON_IsNull(progress)) {
        progress = NULL;
    }
    if (!progress) {
        goto end;
    }

    
    if(!cJSON_IsNumber(progress))
    {
    goto end; //Numeric
    }
    progress_local_var = malloc(sizeof(int));
    if(!progress_local_var)
    {
        goto end;
    }
    *progress_local_var = progress->valuedouble;

    // import_job_status->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(import_job_statusJSON, "provider");
    if (cJSON_IsNull(provider)) {
        provider = NULL;
    }
    if (provider) { 
    if(!cJSON_IsString(provider) && !cJSON_IsNull(provider))
    {
    goto end; //String
    }
    }

    // import_job_status->stage
    cJSON *stage = cJSON_GetObjectItemCaseSensitive(import_job_statusJSON, "stage");
    if (cJSON_IsNull(stage)) {
        stage = NULL;
    }
    if (!stage) {
        goto end;
    }

    
    if(!cJSON_IsString(stage))
    {
    goto end; //String
    }

    // import_job_status->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(import_job_statusJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // import_job_status->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(import_job_statusJSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (!total) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total))
    {
    goto end; //Numeric
    }
    total_local_var = malloc(sizeof(long));
    if(!total_local_var)
    {
        goto end;
    }
    *total_local_var = total->valuedouble;


    if (error && !cJSON_IsNull(error)) error_local_str = strdup(error->valuestring);
    if (job_id && !cJSON_IsNull(job_id)) job_id_local_str = strdup(job_id->valuestring);
    if (provider && !cJSON_IsNull(provider)) provider_local_str = strdup(provider->valuestring);
    if (stage && !cJSON_IsNull(stage)) stage_local_str = strdup(stage->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    import_job_status_local_var = import_job_status_create_internal (
        error_local_str,
        job_id_local_str,
        processed_local_var,
        progress_local_var,
        provider_local_str,
        stage_local_str,
        status_local_str,
        total_local_var
        );

    if (!import_job_status_local_var) {
        goto end;
    }

    return import_job_status_local_var;
end:
    if (error_local_str) {
        free(error_local_str);
        error_local_str = NULL;
    }
    if (job_id_local_str) {
        free(job_id_local_str);
        job_id_local_str = NULL;
    }
    if (processed_local_var) {
        free(processed_local_var);
        processed_local_var = NULL;
    }
    if (progress_local_var) {
        free(progress_local_var);
        progress_local_var = NULL;
    }
    if (provider_local_str) {
        free(provider_local_str);
        provider_local_str = NULL;
    }
    if (stage_local_str) {
        free(stage_local_str);
        stage_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (total_local_var) {
        free(total_local_var);
        total_local_var = NULL;
    }
    return NULL;

}
