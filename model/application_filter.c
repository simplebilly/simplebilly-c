#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "application_filter.h"



static application_filter_t *application_filter_create_internal(
    int *page,
    int *page_size,
    char *posting_id,
    char *status
    ) {
    application_filter_t *application_filter_local_var = malloc(sizeof(application_filter_t));
    if (!application_filter_local_var) {
        return NULL;
    }
    memset(application_filter_local_var, 0, sizeof(application_filter_t));
    application_filter_local_var->_library_owned = 1;
    application_filter_local_var->page = page;
    application_filter_local_var->page_size = page_size;
    application_filter_local_var->posting_id = posting_id;
    application_filter_local_var->status = status;
    return application_filter_local_var;
}

__attribute__((deprecated)) application_filter_t *application_filter_create(
    int *page,
    int *page_size,
    char *posting_id,
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
    application_filter_t *result = application_filter_create_internal (
        page_copy,
        page_size_copy,
        posting_id,
        status
        );
    if (!result) {
        free(page_copy);
        free(page_size_copy);
    }
    return result;
}

void application_filter_free(application_filter_t *application_filter) {
    if(NULL == application_filter){
        return ;
    }
    if(application_filter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "application_filter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (application_filter->page) {
        free(application_filter->page);
        application_filter->page = NULL;
    }
    if (application_filter->page_size) {
        free(application_filter->page_size);
        application_filter->page_size = NULL;
    }
    if (application_filter->posting_id) {
        free(application_filter->posting_id);
        application_filter->posting_id = NULL;
    }
    if (application_filter->status) {
        free(application_filter->status);
        application_filter->status = NULL;
    }
    free(application_filter);
}

cJSON *application_filter_convertToJSON(application_filter_t *application_filter) {
    cJSON *item = cJSON_CreateObject();

    // application_filter->page
    if(application_filter->page) {
    if(cJSON_AddNumberToObject(item, "page", *application_filter->page) == NULL) {
    goto fail; //Numeric
    }
    }


    // application_filter->page_size
    if(application_filter->page_size) {
    if(cJSON_AddNumberToObject(item, "pageSize", *application_filter->page_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // application_filter->posting_id
    if(application_filter->posting_id) {
    if(cJSON_AddStringToObject(item, "postingId", application_filter->posting_id) == NULL) {
    goto fail; //String
    }
    }


    // application_filter->status
    if(application_filter->status) {
    if(cJSON_AddStringToObject(item, "status", application_filter->status) == NULL) {
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

application_filter_t *application_filter_parseFromJSON(cJSON *application_filterJSON){

    application_filter_t *application_filter_local_var = NULL;

    // define the local variable for application_filter->page
    int *page_local_var = NULL;

    // define the local variable for application_filter->page_size
    int *page_size_local_var = NULL;

    char *posting_id_local_str = NULL;

    char *status_local_str = NULL;

    // application_filter->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(application_filterJSON, "page");
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

    // application_filter->page_size
    cJSON *page_size = cJSON_GetObjectItemCaseSensitive(application_filterJSON, "pageSize");
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

    // application_filter->posting_id
    cJSON *posting_id = cJSON_GetObjectItemCaseSensitive(application_filterJSON, "postingId");
    if (cJSON_IsNull(posting_id)) {
        posting_id = NULL;
    }
    if (posting_id) { 
    if(!cJSON_IsString(posting_id) && !cJSON_IsNull(posting_id))
    {
    goto end; //String
    }
    }

    // application_filter->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(application_filterJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }


    if (posting_id && !cJSON_IsNull(posting_id)) posting_id_local_str = strdup(posting_id->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    application_filter_local_var = application_filter_create_internal (
        page_local_var,
        page_size_local_var,
        posting_id_local_str,
        status_local_str
        );

    if (!application_filter_local_var) {
        goto end;
    }

    return application_filter_local_var;
end:
    if (page_local_var) {
        free(page_local_var);
        page_local_var = NULL;
    }
    if (page_size_local_var) {
        free(page_size_local_var);
        page_size_local_var = NULL;
    }
    if (posting_id_local_str) {
        free(posting_id_local_str);
        posting_id_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
