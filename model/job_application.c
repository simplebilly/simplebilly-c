#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job_application.h"



static job_application_t *job_application_create_internal(
    char *cv_file,
    char *cv_text,
    char *email,
    char *match_reason,
    int *match_score,
    char *name,
    char *phone,
    char *posting_id,
    char *source,
    application_status_t *status
    ) {
    job_application_t *job_application_local_var = malloc(sizeof(job_application_t));
    if (!job_application_local_var) {
        return NULL;
    }
    memset(job_application_local_var, 0, sizeof(job_application_t));
    job_application_local_var->_library_owned = 1;
    job_application_local_var->cv_file = cv_file;
    job_application_local_var->cv_text = cv_text;
    job_application_local_var->email = email;
    job_application_local_var->match_reason = match_reason;
    job_application_local_var->match_score = match_score;
    job_application_local_var->name = name;
    job_application_local_var->phone = phone;
    job_application_local_var->posting_id = posting_id;
    job_application_local_var->source = source;
    job_application_local_var->status = status;
    return job_application_local_var;
}

__attribute__((deprecated)) job_application_t *job_application_create(
    char *cv_file,
    char *cv_text,
    char *email,
    char *match_reason,
    int *match_score,
    char *name,
    char *phone,
    char *posting_id,
    char *source,
    application_status_t *status
    ) {
    int *match_score_copy = NULL;
    if (match_score) {
        match_score_copy = malloc(sizeof(int));
        if (match_score_copy) *match_score_copy = *match_score;
    }
    job_application_t *result = job_application_create_internal (
        cv_file,
        cv_text,
        email,
        match_reason,
        match_score_copy,
        name,
        phone,
        posting_id,
        source,
        status
        );
    if (!result) {
        free(match_score_copy);
    }
    return result;
}

void job_application_free(job_application_t *job_application) {
    if(NULL == job_application){
        return ;
    }
    if(job_application->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "job_application_free");
        return ;
    }
    listEntry_t *listEntry;
    if (job_application->cv_file) {
        free(job_application->cv_file);
        job_application->cv_file = NULL;
    }
    if (job_application->cv_text) {
        free(job_application->cv_text);
        job_application->cv_text = NULL;
    }
    if (job_application->email) {
        free(job_application->email);
        job_application->email = NULL;
    }
    if (job_application->match_reason) {
        free(job_application->match_reason);
        job_application->match_reason = NULL;
    }
    if (job_application->match_score) {
        free(job_application->match_score);
        job_application->match_score = NULL;
    }
    if (job_application->name) {
        free(job_application->name);
        job_application->name = NULL;
    }
    if (job_application->phone) {
        free(job_application->phone);
        job_application->phone = NULL;
    }
    if (job_application->posting_id) {
        free(job_application->posting_id);
        job_application->posting_id = NULL;
    }
    if (job_application->source) {
        free(job_application->source);
        job_application->source = NULL;
    }
    if (job_application->status) {
        application_status_free(job_application->status);
        job_application->status = NULL;
    }
    free(job_application);
}

cJSON *job_application_convertToJSON(job_application_t *job_application) {
    cJSON *item = cJSON_CreateObject();

    // job_application->cv_file
    if(job_application->cv_file) {
    if(cJSON_AddStringToObject(item, "cvFile", job_application->cv_file) == NULL) {
    goto fail; //String
    }
    }


    // job_application->cv_text
    if(job_application->cv_text) {
    if(cJSON_AddStringToObject(item, "cvText", job_application->cv_text) == NULL) {
    goto fail; //String
    }
    }


    // job_application->email
    if(job_application->email) {
    if(cJSON_AddStringToObject(item, "email", job_application->email) == NULL) {
    goto fail; //String
    }
    }


    // job_application->match_reason
    if(job_application->match_reason) {
    if(cJSON_AddStringToObject(item, "matchReason", job_application->match_reason) == NULL) {
    goto fail; //String
    }
    }


    // job_application->match_score
    if(job_application->match_score) {
    if(cJSON_AddNumberToObject(item, "matchScore", *job_application->match_score) == NULL) {
    goto fail; //Numeric
    }
    }


    // job_application->name
    if(job_application->name) {
    if(cJSON_AddStringToObject(item, "name", job_application->name) == NULL) {
    goto fail; //String
    }
    }


    // job_application->phone
    if(job_application->phone) {
    if(cJSON_AddStringToObject(item, "phone", job_application->phone) == NULL) {
    goto fail; //String
    }
    }


    // job_application->posting_id
    if(job_application->posting_id) {
    if(cJSON_AddStringToObject(item, "postingId", job_application->posting_id) == NULL) {
    goto fail; //String
    }
    }


    // job_application->source
    if (!job_application->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", job_application->source) == NULL) {
    goto fail; //String
    }


    // job_application->status
    if (!job_application->status) {
        goto fail;
    }
    cJSON *status_local_JSON = application_status_convertToJSON(job_application->status);
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

job_application_t *job_application_parseFromJSON(cJSON *job_applicationJSON){

    job_application_t *job_application_local_var = NULL;

    char *cv_file_local_str = NULL;

    char *cv_text_local_str = NULL;

    char *email_local_str = NULL;

    char *match_reason_local_str = NULL;

    // define the local variable for job_application->match_score
    int *match_score_local_var = NULL;

    char *name_local_str = NULL;

    char *phone_local_str = NULL;

    char *posting_id_local_str = NULL;

    char *source_local_str = NULL;

    // define the local variable for job_application->status
    application_status_t *status_local_nonprim = NULL;

    // job_application->cv_file
    cJSON *cv_file = cJSON_GetObjectItemCaseSensitive(job_applicationJSON, "cvFile");
    if (cJSON_IsNull(cv_file)) {
        cv_file = NULL;
    }
    if (cv_file) { 
    if(!cJSON_IsString(cv_file) && !cJSON_IsNull(cv_file))
    {
    goto end; //String
    }
    }

    // job_application->cv_text
    cJSON *cv_text = cJSON_GetObjectItemCaseSensitive(job_applicationJSON, "cvText");
    if (cJSON_IsNull(cv_text)) {
        cv_text = NULL;
    }
    if (cv_text) { 
    if(!cJSON_IsString(cv_text) && !cJSON_IsNull(cv_text))
    {
    goto end; //String
    }
    }

    // job_application->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(job_applicationJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // job_application->match_reason
    cJSON *match_reason = cJSON_GetObjectItemCaseSensitive(job_applicationJSON, "matchReason");
    if (cJSON_IsNull(match_reason)) {
        match_reason = NULL;
    }
    if (match_reason) { 
    if(!cJSON_IsString(match_reason) && !cJSON_IsNull(match_reason))
    {
    goto end; //String
    }
    }

    // job_application->match_score
    cJSON *match_score = cJSON_GetObjectItemCaseSensitive(job_applicationJSON, "matchScore");
    if (cJSON_IsNull(match_score)) {
        match_score = NULL;
    }
    if (match_score) { 
    if(!cJSON_IsNumber(match_score))
    {
    goto end; //Numeric
    }
    match_score_local_var = malloc(sizeof(int));
    if(!match_score_local_var)
    {
        goto end;
    }
    *match_score_local_var = match_score->valuedouble;
    }

    // job_application->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(job_applicationJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // job_application->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(job_applicationJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // job_application->posting_id
    cJSON *posting_id = cJSON_GetObjectItemCaseSensitive(job_applicationJSON, "postingId");
    if (cJSON_IsNull(posting_id)) {
        posting_id = NULL;
    }
    if (posting_id) { 
    if(!cJSON_IsString(posting_id) && !cJSON_IsNull(posting_id))
    {
    goto end; //String
    }
    }

    // job_application->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(job_applicationJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (!source) {
        goto end;
    }

    
    if(!cJSON_IsString(source))
    {
    goto end; //String
    }

    // job_application->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(job_applicationJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = application_status_parseFromJSON(status); //custom


    if (cv_file && !cJSON_IsNull(cv_file)) cv_file_local_str = strdup(cv_file->valuestring);
    if (cv_text && !cJSON_IsNull(cv_text)) cv_text_local_str = strdup(cv_text->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (match_reason && !cJSON_IsNull(match_reason)) match_reason_local_str = strdup(match_reason->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (phone && !cJSON_IsNull(phone)) phone_local_str = strdup(phone->valuestring);
    if (posting_id && !cJSON_IsNull(posting_id)) posting_id_local_str = strdup(posting_id->valuestring);
    if (source && !cJSON_IsNull(source)) source_local_str = strdup(source->valuestring);

    job_application_local_var = job_application_create_internal (
        cv_file_local_str,
        cv_text_local_str,
        email_local_str,
        match_reason_local_str,
        match_score_local_var,
        name_local_str,
        phone_local_str,
        posting_id_local_str,
        source_local_str,
        status_local_nonprim
        );

    if (!job_application_local_var) {
        goto end;
    }

    return job_application_local_var;
end:
    if (cv_file_local_str) {
        free(cv_file_local_str);
        cv_file_local_str = NULL;
    }
    if (cv_text_local_str) {
        free(cv_text_local_str);
        cv_text_local_str = NULL;
    }
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (match_reason_local_str) {
        free(match_reason_local_str);
        match_reason_local_str = NULL;
    }
    if (match_score_local_var) {
        free(match_score_local_var);
        match_score_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (phone_local_str) {
        free(phone_local_str);
        phone_local_str = NULL;
    }
    if (posting_id_local_str) {
        free(posting_id_local_str);
        posting_id_local_str = NULL;
    }
    if (source_local_str) {
        free(source_local_str);
        source_local_str = NULL;
    }
    if (status_local_nonprim) {
        application_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
