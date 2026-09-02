#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job_posting_filter.h"



static job_posting_filter_t *job_posting_filter_create_internal(
    int *page,
    int *page_size,
    char *status
    ) {
    job_posting_filter_t *job_posting_filter_local_var = malloc(sizeof(job_posting_filter_t));
    if (!job_posting_filter_local_var) {
        return NULL;
    }
    memset(job_posting_filter_local_var, 0, sizeof(job_posting_filter_t));
    job_posting_filter_local_var->_library_owned = 1;
    job_posting_filter_local_var->page = page;
    job_posting_filter_local_var->page_size = page_size;
    job_posting_filter_local_var->status = status;
    return job_posting_filter_local_var;
}

__attribute__((deprecated)) job_posting_filter_t *job_posting_filter_create(
    int *page,
    int *page_size,
    char *status
    ) {
    int *page_copy = NULL;
    if (page) {
        page_copy = malloc(sizeof(int));
        if (page_copy) *page_copy = *page;
    }
    int *page_size_copy = NULL;
    if (page_size) {
        page_size_copy = malloc(sizeof(int));
        if (page_size_copy) *page_size_copy = *page_size;
    }
    job_posting_filter_t *result = job_posting_filter_create_internal (
        page_copy,
        page_size_copy,
        status
        );
    if (!result) {
        free(page_copy);
        free(page_size_copy);
    }
    return result;
}

void job_posting_filter_free(job_posting_filter_t *job_posting_filter) {
    if(NULL == job_posting_filter){
        return ;
    }
    if(job_posting_filter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "job_posting_filter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (job_posting_filter->page) {
        free(job_posting_filter->page);
        job_posting_filter->page = NULL;
    }
    if (job_posting_filter->page_size) {
        free(job_posting_filter->page_size);
        job_posting_filter->page_size = NULL;
    }
    if (job_posting_filter->status) {
        free(job_posting_filter->status);
        job_posting_filter->status = NULL;
    }
    free(job_posting_filter);
}

cJSON *job_posting_filter_convertToJSON(job_posting_filter_t *job_posting_filter) {
    cJSON *item = cJSON_CreateObject();

    // job_posting_filter->page
    if(job_posting_filter->page) {
    if(cJSON_AddNumberToObject(item, "page", *job_posting_filter->page) == NULL) {
    goto fail; //Numeric
    }
    }


    // job_posting_filter->page_size
    if(job_posting_filter->page_size) {
    if(cJSON_AddNumberToObject(item, "pageSize", *job_posting_filter->page_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // job_posting_filter->status
    if(job_posting_filter->status) {
    if(cJSON_AddStringToObject(item, "status", job_posting_filter->status) == NULL) {
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

job_posting_filter_t *job_posting_filter_parseFromJSON(cJSON *job_posting_filterJSON){

    job_posting_filter_t *job_posting_filter_local_var = NULL;

    // define the local variable for job_posting_filter->page
    int *page_local_var = NULL;

    // define the local variable for job_posting_filter->page_size
    int *page_size_local_var = NULL;

    char *status_local_str = NULL;

    // job_posting_filter->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(job_posting_filterJSON, "page");
    if (cJSON_IsNull(page)) {
        page = NULL;
    }
    if (page) { 
    if(!cJSON_IsNumber(page))
    {
    goto end; //Numeric
    }
    page_local_var = malloc(sizeof(int));
    if(!page_local_var)
    {
        goto end;
    }
    *page_local_var = page->valuedouble;
    }

    // job_posting_filter->page_size
    cJSON *page_size = cJSON_GetObjectItemCaseSensitive(job_posting_filterJSON, "pageSize");
    if (cJSON_IsNull(page_size)) {
        page_size = NULL;
    }
    if (page_size) { 
    if(!cJSON_IsNumber(page_size))
    {
    goto end; //Numeric
    }
    page_size_local_var = malloc(sizeof(int));
    if(!page_size_local_var)
    {
        goto end;
    }
    *page_size_local_var = page_size->valuedouble;
    }

    // job_posting_filter->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(job_posting_filterJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }


    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    job_posting_filter_local_var = job_posting_filter_create_internal (
        page_local_var,
        page_size_local_var,
        status_local_str
        );

    if (!job_posting_filter_local_var) {
        goto end;
    }

    return job_posting_filter_local_var;
end:
    if (page_local_var) {
        free(page_local_var);
        page_local_var = NULL;
    }
    if (page_size_local_var) {
        free(page_size_local_var);
        page_size_local_var = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
