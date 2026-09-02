#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job_title_gap.h"



static job_title_gap_t *job_title_gap_create_internal(
    int *employee_count,
    char *female_mean_hourly,
    char *job_title,
    char *male_mean_hourly,
    double *mean_gap_pct,
    double *median_gap_pct
    ) {
    job_title_gap_t *job_title_gap_local_var = malloc(sizeof(job_title_gap_t));
    if (!job_title_gap_local_var) {
        return NULL;
    }
    memset(job_title_gap_local_var, 0, sizeof(job_title_gap_t));
    job_title_gap_local_var->_library_owned = 1;
    job_title_gap_local_var->employee_count = employee_count;
    job_title_gap_local_var->female_mean_hourly = female_mean_hourly;
    job_title_gap_local_var->job_title = job_title;
    job_title_gap_local_var->male_mean_hourly = male_mean_hourly;
    job_title_gap_local_var->mean_gap_pct = mean_gap_pct;
    job_title_gap_local_var->median_gap_pct = median_gap_pct;
    return job_title_gap_local_var;
}

__attribute__((deprecated)) job_title_gap_t *job_title_gap_create(
    int *employee_count,
    char *female_mean_hourly,
    char *job_title,
    char *male_mean_hourly,
    double *mean_gap_pct,
    double *median_gap_pct
    ) {
    int *employee_count_copy = NULL;
    if (employee_count) {
        employee_count_copy = malloc(sizeof(int));
        if (employee_count_copy) *employee_count_copy = *employee_count;
    }
    double *mean_gap_pct_copy = NULL;
    if (mean_gap_pct) {
        mean_gap_pct_copy = malloc(sizeof(double));
        if (mean_gap_pct_copy) *mean_gap_pct_copy = *mean_gap_pct;
    }
    double *median_gap_pct_copy = NULL;
    if (median_gap_pct) {
        median_gap_pct_copy = malloc(sizeof(double));
        if (median_gap_pct_copy) *median_gap_pct_copy = *median_gap_pct;
    }
    job_title_gap_t *result = job_title_gap_create_internal (
        employee_count_copy,
        female_mean_hourly,
        job_title,
        male_mean_hourly,
        mean_gap_pct_copy,
        median_gap_pct_copy
        );
    if (!result) {
        free(employee_count_copy);
        free(mean_gap_pct_copy);
        free(median_gap_pct_copy);
    }
    return result;
}

void job_title_gap_free(job_title_gap_t *job_title_gap) {
    if(NULL == job_title_gap){
        return ;
    }
    if(job_title_gap->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "job_title_gap_free");
        return ;
    }
    listEntry_t *listEntry;
    if (job_title_gap->employee_count) {
        free(job_title_gap->employee_count);
        job_title_gap->employee_count = NULL;
    }
    if (job_title_gap->female_mean_hourly) {
        free(job_title_gap->female_mean_hourly);
        job_title_gap->female_mean_hourly = NULL;
    }
    if (job_title_gap->job_title) {
        free(job_title_gap->job_title);
        job_title_gap->job_title = NULL;
    }
    if (job_title_gap->male_mean_hourly) {
        free(job_title_gap->male_mean_hourly);
        job_title_gap->male_mean_hourly = NULL;
    }
    if (job_title_gap->mean_gap_pct) {
        free(job_title_gap->mean_gap_pct);
        job_title_gap->mean_gap_pct = NULL;
    }
    if (job_title_gap->median_gap_pct) {
        free(job_title_gap->median_gap_pct);
        job_title_gap->median_gap_pct = NULL;
    }
    free(job_title_gap);
}

cJSON *job_title_gap_convertToJSON(job_title_gap_t *job_title_gap) {
    cJSON *item = cJSON_CreateObject();

    // job_title_gap->employee_count
    if (!job_title_gap->employee_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "employee_count", *job_title_gap->employee_count) == NULL) {
    goto fail; //Numeric
    }


    // job_title_gap->female_mean_hourly
    if (!job_title_gap->female_mean_hourly) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "female_mean_hourly", job_title_gap->female_mean_hourly) == NULL) {
    goto fail; //String
    }


    // job_title_gap->job_title
    if (!job_title_gap->job_title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "job_title", job_title_gap->job_title) == NULL) {
    goto fail; //String
    }


    // job_title_gap->male_mean_hourly
    if (!job_title_gap->male_mean_hourly) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "male_mean_hourly", job_title_gap->male_mean_hourly) == NULL) {
    goto fail; //String
    }


    // job_title_gap->mean_gap_pct
    if (!job_title_gap->mean_gap_pct) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "mean_gap_pct", *job_title_gap->mean_gap_pct) == NULL) {
    goto fail; //Numeric
    }


    // job_title_gap->median_gap_pct
    if (!job_title_gap->median_gap_pct) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "median_gap_pct", *job_title_gap->median_gap_pct) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

job_title_gap_t *job_title_gap_parseFromJSON(cJSON *job_title_gapJSON){

    job_title_gap_t *job_title_gap_local_var = NULL;

    // define the local variable for job_title_gap->employee_count
    int *employee_count_local_var = NULL;

    char *female_mean_hourly_local_str = NULL;

    char *job_title_local_str = NULL;

    char *male_mean_hourly_local_str = NULL;

    // define the local variable for job_title_gap->mean_gap_pct
    double *mean_gap_pct_local_var = NULL;

    // define the local variable for job_title_gap->median_gap_pct
    double *median_gap_pct_local_var = NULL;

    // job_title_gap->employee_count
    cJSON *employee_count = cJSON_GetObjectItemCaseSensitive(job_title_gapJSON, "employee_count");
    if (cJSON_IsNull(employee_count)) {
        employee_count = NULL;
    }
    if (!employee_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(employee_count))
    {
    goto end; //Numeric
    }
    employee_count_local_var = malloc(sizeof(int));
    if(!employee_count_local_var)
    {
        goto end;
    }
    *employee_count_local_var = employee_count->valuedouble;

    // job_title_gap->female_mean_hourly
    cJSON *female_mean_hourly = cJSON_GetObjectItemCaseSensitive(job_title_gapJSON, "female_mean_hourly");
    if (cJSON_IsNull(female_mean_hourly)) {
        female_mean_hourly = NULL;
    }
    if (!female_mean_hourly) {
        goto end;
    }

    
    if(!cJSON_IsString(female_mean_hourly))
    {
    goto end; //String
    }

    // job_title_gap->job_title
    cJSON *job_title = cJSON_GetObjectItemCaseSensitive(job_title_gapJSON, "job_title");
    if (cJSON_IsNull(job_title)) {
        job_title = NULL;
    }
    if (!job_title) {
        goto end;
    }

    
    if(!cJSON_IsString(job_title))
    {
    goto end; //String
    }

    // job_title_gap->male_mean_hourly
    cJSON *male_mean_hourly = cJSON_GetObjectItemCaseSensitive(job_title_gapJSON, "male_mean_hourly");
    if (cJSON_IsNull(male_mean_hourly)) {
        male_mean_hourly = NULL;
    }
    if (!male_mean_hourly) {
        goto end;
    }

    
    if(!cJSON_IsString(male_mean_hourly))
    {
    goto end; //String
    }

    // job_title_gap->mean_gap_pct
    cJSON *mean_gap_pct = cJSON_GetObjectItemCaseSensitive(job_title_gapJSON, "mean_gap_pct");
    if (cJSON_IsNull(mean_gap_pct)) {
        mean_gap_pct = NULL;
    }
    if (!mean_gap_pct) {
        goto end;
    }

    
    if(!cJSON_IsNumber(mean_gap_pct))
    {
    goto end; //Numeric
    }
    mean_gap_pct_local_var = malloc(sizeof(double));
    if(!mean_gap_pct_local_var)
    {
        goto end;
    }
    *mean_gap_pct_local_var = mean_gap_pct->valuedouble;

    // job_title_gap->median_gap_pct
    cJSON *median_gap_pct = cJSON_GetObjectItemCaseSensitive(job_title_gapJSON, "median_gap_pct");
    if (cJSON_IsNull(median_gap_pct)) {
        median_gap_pct = NULL;
    }
    if (!median_gap_pct) {
        goto end;
    }

    
    if(!cJSON_IsNumber(median_gap_pct))
    {
    goto end; //Numeric
    }
    median_gap_pct_local_var = malloc(sizeof(double));
    if(!median_gap_pct_local_var)
    {
        goto end;
    }
    *median_gap_pct_local_var = median_gap_pct->valuedouble;


    if (female_mean_hourly && !cJSON_IsNull(female_mean_hourly)) female_mean_hourly_local_str = strdup(female_mean_hourly->valuestring);
    if (job_title && !cJSON_IsNull(job_title)) job_title_local_str = strdup(job_title->valuestring);
    if (male_mean_hourly && !cJSON_IsNull(male_mean_hourly)) male_mean_hourly_local_str = strdup(male_mean_hourly->valuestring);

    job_title_gap_local_var = job_title_gap_create_internal (
        employee_count_local_var,
        female_mean_hourly_local_str,
        job_title_local_str,
        male_mean_hourly_local_str,
        mean_gap_pct_local_var,
        median_gap_pct_local_var
        );

    if (!job_title_gap_local_var) {
        goto end;
    }

    return job_title_gap_local_var;
end:
    if (employee_count_local_var) {
        free(employee_count_local_var);
        employee_count_local_var = NULL;
    }
    if (female_mean_hourly_local_str) {
        free(female_mean_hourly_local_str);
        female_mean_hourly_local_str = NULL;
    }
    if (job_title_local_str) {
        free(job_title_local_str);
        job_title_local_str = NULL;
    }
    if (male_mean_hourly_local_str) {
        free(male_mean_hourly_local_str);
        male_mean_hourly_local_str = NULL;
    }
    if (mean_gap_pct_local_var) {
        free(mean_gap_pct_local_var);
        mean_gap_pct_local_var = NULL;
    }
    if (median_gap_pct_local_var) {
        free(median_gap_pct_local_var);
        median_gap_pct_local_var = NULL;
    }
    return NULL;

}
