#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data_quality.h"



static data_quality_t *data_quality_create_internal(
    int *activity_lines,
    double *activity_share_pct,
    int *spend_lines
    ) {
    data_quality_t *data_quality_local_var = malloc(sizeof(data_quality_t));
    if (!data_quality_local_var) {
        return NULL;
    }
    memset(data_quality_local_var, 0, sizeof(data_quality_t));
    data_quality_local_var->_library_owned = 1;
    data_quality_local_var->activity_lines = activity_lines;
    data_quality_local_var->activity_share_pct = activity_share_pct;
    data_quality_local_var->spend_lines = spend_lines;
    return data_quality_local_var;
}

__attribute__((deprecated)) data_quality_t *data_quality_create(
    int *activity_lines,
    double *activity_share_pct,
    int *spend_lines
    ) {
    int *activity_lines_copy = NULL;
    if (activity_lines) {
        activity_lines_copy = malloc(sizeof(int));
        if (activity_lines_copy) *activity_lines_copy = *activity_lines;
    }
    double *activity_share_pct_copy = NULL;
    if (activity_share_pct) {
        activity_share_pct_copy = malloc(sizeof(double));
        if (activity_share_pct_copy) *activity_share_pct_copy = *activity_share_pct;
    }
    int *spend_lines_copy = NULL;
    if (spend_lines) {
        spend_lines_copy = malloc(sizeof(int));
        if (spend_lines_copy) *spend_lines_copy = *spend_lines;
    }
    data_quality_t *result = data_quality_create_internal (
        activity_lines_copy,
        activity_share_pct_copy,
        spend_lines_copy
        );
    if (!result) {
        free(activity_lines_copy);
        free(activity_share_pct_copy);
        free(spend_lines_copy);
    }
    return result;
}

void data_quality_free(data_quality_t *data_quality) {
    if(NULL == data_quality){
        return ;
    }
    if(data_quality->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "data_quality_free");
        return ;
    }
    listEntry_t *listEntry;
    if (data_quality->activity_lines) {
        free(data_quality->activity_lines);
        data_quality->activity_lines = NULL;
    }
    if (data_quality->activity_share_pct) {
        free(data_quality->activity_share_pct);
        data_quality->activity_share_pct = NULL;
    }
    if (data_quality->spend_lines) {
        free(data_quality->spend_lines);
        data_quality->spend_lines = NULL;
    }
    free(data_quality);
}

cJSON *data_quality_convertToJSON(data_quality_t *data_quality) {
    cJSON *item = cJSON_CreateObject();

    // data_quality->activity_lines
    if (!data_quality->activity_lines) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "activity_lines", *data_quality->activity_lines) == NULL) {
    goto fail; //Numeric
    }


    // data_quality->activity_share_pct
    if (!data_quality->activity_share_pct) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "activity_share_pct", *data_quality->activity_share_pct) == NULL) {
    goto fail; //Numeric
    }


    // data_quality->spend_lines
    if (!data_quality->spend_lines) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "spend_lines", *data_quality->spend_lines) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

data_quality_t *data_quality_parseFromJSON(cJSON *data_qualityJSON){

    data_quality_t *data_quality_local_var = NULL;

    // define the local variable for data_quality->activity_lines
    int *activity_lines_local_var = NULL;

    // define the local variable for data_quality->activity_share_pct
    double *activity_share_pct_local_var = NULL;

    // define the local variable for data_quality->spend_lines
    int *spend_lines_local_var = NULL;

    // data_quality->activity_lines
    cJSON *activity_lines = cJSON_GetObjectItemCaseSensitive(data_qualityJSON, "activity_lines");
    if (cJSON_IsNull(activity_lines)) {
        activity_lines = NULL;
    }
    if (!activity_lines) {
        goto end;
    }

    
    if(!cJSON_IsNumber(activity_lines))
    {
    goto end; //Numeric
    }
    activity_lines_local_var = malloc(sizeof(int));
    if(!activity_lines_local_var)
    {
        goto end;
    }
    *activity_lines_local_var = activity_lines->valuedouble;

    // data_quality->activity_share_pct
    cJSON *activity_share_pct = cJSON_GetObjectItemCaseSensitive(data_qualityJSON, "activity_share_pct");
    if (cJSON_IsNull(activity_share_pct)) {
        activity_share_pct = NULL;
    }
    if (!activity_share_pct) {
        goto end;
    }

    
    if(!cJSON_IsNumber(activity_share_pct))
    {
    goto end; //Numeric
    }
    activity_share_pct_local_var = malloc(sizeof(double));
    if(!activity_share_pct_local_var)
    {
        goto end;
    }
    *activity_share_pct_local_var = activity_share_pct->valuedouble;

    // data_quality->spend_lines
    cJSON *spend_lines = cJSON_GetObjectItemCaseSensitive(data_qualityJSON, "spend_lines");
    if (cJSON_IsNull(spend_lines)) {
        spend_lines = NULL;
    }
    if (!spend_lines) {
        goto end;
    }

    
    if(!cJSON_IsNumber(spend_lines))
    {
    goto end; //Numeric
    }
    spend_lines_local_var = malloc(sizeof(int));
    if(!spend_lines_local_var)
    {
        goto end;
    }
    *spend_lines_local_var = spend_lines->valuedouble;



    data_quality_local_var = data_quality_create_internal (
        activity_lines_local_var,
        activity_share_pct_local_var,
        spend_lines_local_var
        );

    if (!data_quality_local_var) {
        goto end;
    }

    return data_quality_local_var;
end:
    if (activity_lines_local_var) {
        free(activity_lines_local_var);
        activity_lines_local_var = NULL;
    }
    if (activity_share_pct_local_var) {
        free(activity_share_pct_local_var);
        activity_share_pct_local_var = NULL;
    }
    if (spend_lines_local_var) {
        free(spend_lines_local_var);
        spend_lines_local_var = NULL;
    }
    return NULL;

}
