#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hr_training_overview.h"



static hr_training_overview_t *hr_training_overview_create_internal(
    long *assigned_count,
    char *code,
    long *completed_count,
    long *overdue_count,
    char *title,
    char *training_id
    ) {
    hr_training_overview_t *hr_training_overview_local_var = malloc(sizeof(hr_training_overview_t));
    if (!hr_training_overview_local_var) {
        return NULL;
    }
    memset(hr_training_overview_local_var, 0, sizeof(hr_training_overview_t));
    hr_training_overview_local_var->_library_owned = 1;
    hr_training_overview_local_var->assigned_count = assigned_count;
    hr_training_overview_local_var->code = code;
    hr_training_overview_local_var->completed_count = completed_count;
    hr_training_overview_local_var->overdue_count = overdue_count;
    hr_training_overview_local_var->title = title;
    hr_training_overview_local_var->training_id = training_id;
    return hr_training_overview_local_var;
}

__attribute__((deprecated)) hr_training_overview_t *hr_training_overview_create(
    long *assigned_count,
    char *code,
    long *completed_count,
    long *overdue_count,
    char *title,
    char *training_id
    ) {
    long *assigned_count_copy = NULL;
    if (assigned_count) {
        assigned_count_copy = malloc(sizeof(long));
        if (assigned_count_copy) *assigned_count_copy = *assigned_count;
    }
    long *completed_count_copy = NULL;
    if (completed_count) {
        completed_count_copy = malloc(sizeof(long));
        if (completed_count_copy) *completed_count_copy = *completed_count;
    }
    long *overdue_count_copy = NULL;
    if (overdue_count) {
        overdue_count_copy = malloc(sizeof(long));
        if (overdue_count_copy) *overdue_count_copy = *overdue_count;
    }
    hr_training_overview_t *result = hr_training_overview_create_internal (
        assigned_count_copy,
        code,
        completed_count_copy,
        overdue_count_copy,
        title,
        training_id
        );
    if (!result) {
        free(assigned_count_copy);
        free(completed_count_copy);
        free(overdue_count_copy);
    }
    return result;
}

void hr_training_overview_free(hr_training_overview_t *hr_training_overview) {
    if(NULL == hr_training_overview){
        return ;
    }
    if(hr_training_overview->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "hr_training_overview_free");
        return ;
    }
    listEntry_t *listEntry;
    if (hr_training_overview->assigned_count) {
        free(hr_training_overview->assigned_count);
        hr_training_overview->assigned_count = NULL;
    }
    if (hr_training_overview->code) {
        free(hr_training_overview->code);
        hr_training_overview->code = NULL;
    }
    if (hr_training_overview->completed_count) {
        free(hr_training_overview->completed_count);
        hr_training_overview->completed_count = NULL;
    }
    if (hr_training_overview->overdue_count) {
        free(hr_training_overview->overdue_count);
        hr_training_overview->overdue_count = NULL;
    }
    if (hr_training_overview->title) {
        free(hr_training_overview->title);
        hr_training_overview->title = NULL;
    }
    if (hr_training_overview->training_id) {
        free(hr_training_overview->training_id);
        hr_training_overview->training_id = NULL;
    }
    free(hr_training_overview);
}

cJSON *hr_training_overview_convertToJSON(hr_training_overview_t *hr_training_overview) {
    cJSON *item = cJSON_CreateObject();

    // hr_training_overview->assigned_count
    if (!hr_training_overview->assigned_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "assignedCount", *hr_training_overview->assigned_count) == NULL) {
    goto fail; //Numeric
    }


    // hr_training_overview->code
    if (!hr_training_overview->code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "code", hr_training_overview->code) == NULL) {
    goto fail; //String
    }


    // hr_training_overview->completed_count
    if (!hr_training_overview->completed_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "completedCount", *hr_training_overview->completed_count) == NULL) {
    goto fail; //Numeric
    }


    // hr_training_overview->overdue_count
    if (!hr_training_overview->overdue_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "overdueCount", *hr_training_overview->overdue_count) == NULL) {
    goto fail; //Numeric
    }


    // hr_training_overview->title
    if (!hr_training_overview->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", hr_training_overview->title) == NULL) {
    goto fail; //String
    }


    // hr_training_overview->training_id
    if (!hr_training_overview->training_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "trainingId", hr_training_overview->training_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

hr_training_overview_t *hr_training_overview_parseFromJSON(cJSON *hr_training_overviewJSON){

    hr_training_overview_t *hr_training_overview_local_var = NULL;

    // define the local variable for hr_training_overview->assigned_count
    long *assigned_count_local_var = NULL;

    char *code_local_str = NULL;

    // define the local variable for hr_training_overview->completed_count
    long *completed_count_local_var = NULL;

    // define the local variable for hr_training_overview->overdue_count
    long *overdue_count_local_var = NULL;

    char *title_local_str = NULL;

    char *training_id_local_str = NULL;

    // hr_training_overview->assigned_count
    cJSON *assigned_count = cJSON_GetObjectItemCaseSensitive(hr_training_overviewJSON, "assignedCount");
    if (cJSON_IsNull(assigned_count)) {
        assigned_count = NULL;
    }
    if (!assigned_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(assigned_count))
    {
    goto end; //Numeric
    }
    assigned_count_local_var = malloc(sizeof(long));
    if(!assigned_count_local_var)
    {
        goto end;
    }
    *assigned_count_local_var = assigned_count->valuedouble;

    // hr_training_overview->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(hr_training_overviewJSON, "code");
    if (cJSON_IsNull(code)) {
        code = NULL;
    }
    if (!code) {
        goto end;
    }

    
    if(!cJSON_IsString(code))
    {
    goto end; //String
    }

    // hr_training_overview->completed_count
    cJSON *completed_count = cJSON_GetObjectItemCaseSensitive(hr_training_overviewJSON, "completedCount");
    if (cJSON_IsNull(completed_count)) {
        completed_count = NULL;
    }
    if (!completed_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(completed_count))
    {
    goto end; //Numeric
    }
    completed_count_local_var = malloc(sizeof(long));
    if(!completed_count_local_var)
    {
        goto end;
    }
    *completed_count_local_var = completed_count->valuedouble;

    // hr_training_overview->overdue_count
    cJSON *overdue_count = cJSON_GetObjectItemCaseSensitive(hr_training_overviewJSON, "overdueCount");
    if (cJSON_IsNull(overdue_count)) {
        overdue_count = NULL;
    }
    if (!overdue_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(overdue_count))
    {
    goto end; //Numeric
    }
    overdue_count_local_var = malloc(sizeof(long));
    if(!overdue_count_local_var)
    {
        goto end;
    }
    *overdue_count_local_var = overdue_count->valuedouble;

    // hr_training_overview->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(hr_training_overviewJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // hr_training_overview->training_id
    cJSON *training_id = cJSON_GetObjectItemCaseSensitive(hr_training_overviewJSON, "trainingId");
    if (cJSON_IsNull(training_id)) {
        training_id = NULL;
    }
    if (!training_id) {
        goto end;
    }

    
    if(!cJSON_IsString(training_id))
    {
    goto end; //String
    }


    if (code && !cJSON_IsNull(code)) code_local_str = strdup(code->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (training_id && !cJSON_IsNull(training_id)) training_id_local_str = strdup(training_id->valuestring);

    hr_training_overview_local_var = hr_training_overview_create_internal (
        assigned_count_local_var,
        code_local_str,
        completed_count_local_var,
        overdue_count_local_var,
        title_local_str,
        training_id_local_str
        );

    if (!hr_training_overview_local_var) {
        goto end;
    }

    return hr_training_overview_local_var;
end:
    if (assigned_count_local_var) {
        free(assigned_count_local_var);
        assigned_count_local_var = NULL;
    }
    if (code_local_str) {
        free(code_local_str);
        code_local_str = NULL;
    }
    if (completed_count_local_var) {
        free(completed_count_local_var);
        completed_count_local_var = NULL;
    }
    if (overdue_count_local_var) {
        free(overdue_count_local_var);
        overdue_count_local_var = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    if (training_id_local_str) {
        free(training_id_local_str);
        training_id_local_str = NULL;
    }
    return NULL;

}
