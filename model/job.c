#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job.h"



static job_t *job_create_internal(
    int *attempts,
    char *job_type,
    int *max_attempts,
    any_type_t *payload,
    char *run_at,
    job_status_t *status
    ) {
    job_t *job_local_var = malloc(sizeof(job_t));
    if (!job_local_var) {
        return NULL;
    }
    memset(job_local_var, 0, sizeof(job_t));
    job_local_var->_library_owned = 1;
    job_local_var->attempts = attempts;
    job_local_var->job_type = job_type;
    job_local_var->max_attempts = max_attempts;
    job_local_var->payload = payload;
    job_local_var->run_at = run_at;
    job_local_var->status = status;
    return job_local_var;
}

__attribute__((deprecated)) job_t *job_create(
    int *attempts,
    char *job_type,
    int *max_attempts,
    any_type_t *payload,
    char *run_at,
    job_status_t *status
    ) {
    int *attempts_copy = NULL;
    if (attempts) {
        attempts_copy = malloc(sizeof(int));
        if (attempts_copy) *attempts_copy = *attempts;
    }
    int *max_attempts_copy = NULL;
    if (max_attempts) {
        max_attempts_copy = malloc(sizeof(int));
        if (max_attempts_copy) *max_attempts_copy = *max_attempts;
    }
    job_t *result = job_create_internal (
        attempts_copy,
        job_type,
        max_attempts_copy,
        payload,
        run_at,
        status
        );
    if (!result) {
        free(attempts_copy);
        free(max_attempts_copy);
    }
    return result;
}

void job_free(job_t *job) {
    if(NULL == job){
        return ;
    }
    if(job->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "job_free");
        return ;
    }
    listEntry_t *listEntry;
    if (job->attempts) {
        free(job->attempts);
        job->attempts = NULL;
    }
    if (job->job_type) {
        free(job->job_type);
        job->job_type = NULL;
    }
    if (job->max_attempts) {
        free(job->max_attempts);
        job->max_attempts = NULL;
    }
    if (job->payload) {
        _free(job->payload);
        job->payload = NULL;
    }
    if (job->run_at) {
        free(job->run_at);
        job->run_at = NULL;
    }
    if (job->status) {
        job_status_free(job->status);
        job->status = NULL;
    }
    free(job);
}

cJSON *job_convertToJSON(job_t *job) {
    cJSON *item = cJSON_CreateObject();

    // job->attempts
    if(job->attempts) {
    if(cJSON_AddNumberToObject(item, "attempts", *job->attempts) == NULL) {
    goto fail; //Numeric
    }
    }


    // job->job_type
    if (!job->job_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "jobType", job->job_type) == NULL) {
    goto fail; //String
    }


    // job->max_attempts
    if (!job->max_attempts) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "maxAttempts", *job->max_attempts) == NULL) {
    goto fail; //Numeric
    }


    // job->payload
    if(job->payload) {
    cJSON *payload_local_JSON = _convertToJSON(job->payload);
    if(payload_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "payload", payload_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // job->run_at
    if(job->run_at) {
    if(cJSON_AddStringToObject(item, "runAt", job->run_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // job->status
    if (!job->status) {
        goto fail;
    }
    cJSON *status_local_JSON = job_status_convertToJSON(job->status);
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

job_t *job_parseFromJSON(cJSON *jobJSON){

    job_t *job_local_var = NULL;

    // define the local variable for job->attempts
    int *attempts_local_var = NULL;

    char *job_type_local_str = NULL;

    // define the local variable for job->max_attempts
    int *max_attempts_local_var = NULL;

    // define the local variable for job->payload
    _t *payload_local_nonprim = NULL;

    char *run_at_local_str = NULL;

    // define the local variable for job->status
    job_status_t *status_local_nonprim = NULL;

    // job->attempts
    cJSON *attempts = cJSON_GetObjectItemCaseSensitive(jobJSON, "attempts");
    if (cJSON_IsNull(attempts)) {
        attempts = NULL;
    }
    if (attempts) { 
    if(!cJSON_IsNumber(attempts))
    {
    goto end; //Numeric
    }
    attempts_local_var = malloc(sizeof(int));
    if(!attempts_local_var)
    {
        goto end;
    }
    *attempts_local_var = attempts->valuedouble;
    }

    // job->job_type
    cJSON *job_type = cJSON_GetObjectItemCaseSensitive(jobJSON, "jobType");
    if (cJSON_IsNull(job_type)) {
        job_type = NULL;
    }
    if (!job_type) {
        goto end;
    }

    
    if(!cJSON_IsString(job_type))
    {
    goto end; //String
    }

    // job->max_attempts
    cJSON *max_attempts = cJSON_GetObjectItemCaseSensitive(jobJSON, "maxAttempts");
    if (cJSON_IsNull(max_attempts)) {
        max_attempts = NULL;
    }
    if (!max_attempts) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max_attempts))
    {
    goto end; //Numeric
    }
    max_attempts_local_var = malloc(sizeof(int));
    if(!max_attempts_local_var)
    {
        goto end;
    }
    *max_attempts_local_var = max_attempts->valuedouble;

    // job->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(jobJSON, "payload");
    if (cJSON_IsNull(payload)) {
        payload = NULL;
    }
    if (payload) { 
    payload_local_nonprim = _parseFromJSON(payload); //custom
    }

    // job->run_at
    cJSON *run_at = cJSON_GetObjectItemCaseSensitive(jobJSON, "runAt");
    if (cJSON_IsNull(run_at)) {
        run_at = NULL;
    }
    if (run_at) { 
    if(!cJSON_IsString(run_at) && !cJSON_IsNull(run_at))
    {
    goto end; //DateTime
    }
    }

    // job->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(jobJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = job_status_parseFromJSON(status); //custom


    if (job_type && !cJSON_IsNull(job_type)) job_type_local_str = strdup(job_type->valuestring);
    if (run_at && !cJSON_IsNull(run_at)) run_at_local_str = strdup(run_at->valuestring);

    job_local_var = job_create_internal (
        attempts_local_var,
        job_type_local_str,
        max_attempts_local_var,
        payload ? payload_local_nonprim : NULL,
        run_at_local_str,
        status_local_nonprim
        );

    if (!job_local_var) {
        goto end;
    }

    return job_local_var;
end:
    if (attempts_local_var) {
        free(attempts_local_var);
        attempts_local_var = NULL;
    }
    if (job_type_local_str) {
        free(job_type_local_str);
        job_type_local_str = NULL;
    }
    if (max_attempts_local_var) {
        free(max_attempts_local_var);
        max_attempts_local_var = NULL;
    }
    if (payload_local_nonprim) {
        _free(payload_local_nonprim);
        payload_local_nonprim = NULL;
    }
    if (run_at_local_str) {
        free(run_at_local_str);
        run_at_local_str = NULL;
    }
    if (status_local_nonprim) {
        job_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
