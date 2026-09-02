#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pay_gap_info_response.h"



static pay_gap_info_response_t *pay_gap_info_response_create_internal(
    char *employee_id,
    char *first_name,
    char *gender,
    double *group_median_hourly,
    double *group_median_monthly,
    int *group_size,
    char *job_title,
    char *last_name,
    double *overall_median_hourly,
    double *own_hourly_gross,
    double *own_monthly_gross
    ) {
    pay_gap_info_response_t *pay_gap_info_response_local_var = malloc(sizeof(pay_gap_info_response_t));
    if (!pay_gap_info_response_local_var) {
        return NULL;
    }
    memset(pay_gap_info_response_local_var, 0, sizeof(pay_gap_info_response_t));
    pay_gap_info_response_local_var->_library_owned = 1;
    pay_gap_info_response_local_var->employee_id = employee_id;
    pay_gap_info_response_local_var->first_name = first_name;
    pay_gap_info_response_local_var->gender = gender;
    pay_gap_info_response_local_var->group_median_hourly = group_median_hourly;
    pay_gap_info_response_local_var->group_median_monthly = group_median_monthly;
    pay_gap_info_response_local_var->group_size = group_size;
    pay_gap_info_response_local_var->job_title = job_title;
    pay_gap_info_response_local_var->last_name = last_name;
    pay_gap_info_response_local_var->overall_median_hourly = overall_median_hourly;
    pay_gap_info_response_local_var->own_hourly_gross = own_hourly_gross;
    pay_gap_info_response_local_var->own_monthly_gross = own_monthly_gross;
    return pay_gap_info_response_local_var;
}

__attribute__((deprecated)) pay_gap_info_response_t *pay_gap_info_response_create(
    char *employee_id,
    char *first_name,
    char *gender,
    double *group_median_hourly,
    double *group_median_monthly,
    int *group_size,
    char *job_title,
    char *last_name,
    double *overall_median_hourly,
    double *own_hourly_gross,
    double *own_monthly_gross
    ) {
    double *group_median_hourly_copy = NULL;
    if (group_median_hourly) {
        group_median_hourly_copy = malloc(sizeof(double));
        if (group_median_hourly_copy) *group_median_hourly_copy = *group_median_hourly;
    }
    double *group_median_monthly_copy = NULL;
    if (group_median_monthly) {
        group_median_monthly_copy = malloc(sizeof(double));
        if (group_median_monthly_copy) *group_median_monthly_copy = *group_median_monthly;
    }
    int *group_size_copy = NULL;
    if (group_size) {
        group_size_copy = malloc(sizeof(int));
        if (group_size_copy) *group_size_copy = *group_size;
    }
    double *overall_median_hourly_copy = NULL;
    if (overall_median_hourly) {
        overall_median_hourly_copy = malloc(sizeof(double));
        if (overall_median_hourly_copy) *overall_median_hourly_copy = *overall_median_hourly;
    }
    double *own_hourly_gross_copy = NULL;
    if (own_hourly_gross) {
        own_hourly_gross_copy = malloc(sizeof(double));
        if (own_hourly_gross_copy) *own_hourly_gross_copy = *own_hourly_gross;
    }
    double *own_monthly_gross_copy = NULL;
    if (own_monthly_gross) {
        own_monthly_gross_copy = malloc(sizeof(double));
        if (own_monthly_gross_copy) *own_monthly_gross_copy = *own_monthly_gross;
    }
    pay_gap_info_response_t *result = pay_gap_info_response_create_internal (
        employee_id,
        first_name,
        gender,
        group_median_hourly_copy,
        group_median_monthly_copy,
        group_size_copy,
        job_title,
        last_name,
        overall_median_hourly_copy,
        own_hourly_gross_copy,
        own_monthly_gross_copy
        );
    if (!result) {
        free(group_median_hourly_copy);
        free(group_median_monthly_copy);
        free(group_size_copy);
        free(overall_median_hourly_copy);
        free(own_hourly_gross_copy);
        free(own_monthly_gross_copy);
    }
    return result;
}

void pay_gap_info_response_free(pay_gap_info_response_t *pay_gap_info_response) {
    if(NULL == pay_gap_info_response){
        return ;
    }
    if(pay_gap_info_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pay_gap_info_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pay_gap_info_response->employee_id) {
        free(pay_gap_info_response->employee_id);
        pay_gap_info_response->employee_id = NULL;
    }
    if (pay_gap_info_response->first_name) {
        free(pay_gap_info_response->first_name);
        pay_gap_info_response->first_name = NULL;
    }
    if (pay_gap_info_response->gender) {
        free(pay_gap_info_response->gender);
        pay_gap_info_response->gender = NULL;
    }
    if (pay_gap_info_response->group_median_hourly) {
        free(pay_gap_info_response->group_median_hourly);
        pay_gap_info_response->group_median_hourly = NULL;
    }
    if (pay_gap_info_response->group_median_monthly) {
        free(pay_gap_info_response->group_median_monthly);
        pay_gap_info_response->group_median_monthly = NULL;
    }
    if (pay_gap_info_response->group_size) {
        free(pay_gap_info_response->group_size);
        pay_gap_info_response->group_size = NULL;
    }
    if (pay_gap_info_response->job_title) {
        free(pay_gap_info_response->job_title);
        pay_gap_info_response->job_title = NULL;
    }
    if (pay_gap_info_response->last_name) {
        free(pay_gap_info_response->last_name);
        pay_gap_info_response->last_name = NULL;
    }
    if (pay_gap_info_response->overall_median_hourly) {
        free(pay_gap_info_response->overall_median_hourly);
        pay_gap_info_response->overall_median_hourly = NULL;
    }
    if (pay_gap_info_response->own_hourly_gross) {
        free(pay_gap_info_response->own_hourly_gross);
        pay_gap_info_response->own_hourly_gross = NULL;
    }
    if (pay_gap_info_response->own_monthly_gross) {
        free(pay_gap_info_response->own_monthly_gross);
        pay_gap_info_response->own_monthly_gross = NULL;
    }
    free(pay_gap_info_response);
}

cJSON *pay_gap_info_response_convertToJSON(pay_gap_info_response_t *pay_gap_info_response) {
    cJSON *item = cJSON_CreateObject();

    // pay_gap_info_response->employee_id
    if (!pay_gap_info_response->employee_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "employee_id", pay_gap_info_response->employee_id) == NULL) {
    goto fail; //String
    }


    // pay_gap_info_response->first_name
    if (!pay_gap_info_response->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", pay_gap_info_response->first_name) == NULL) {
    goto fail; //String
    }


    // pay_gap_info_response->gender
    if(pay_gap_info_response->gender) {
    if(cJSON_AddStringToObject(item, "gender", pay_gap_info_response->gender) == NULL) {
    goto fail; //String
    }
    }


    // pay_gap_info_response->group_median_hourly
    if(pay_gap_info_response->group_median_hourly) {
    if(cJSON_AddNumberToObject(item, "group_median_hourly", *pay_gap_info_response->group_median_hourly) == NULL) {
    goto fail; //Numeric
    }
    }


    // pay_gap_info_response->group_median_monthly
    if(pay_gap_info_response->group_median_monthly) {
    if(cJSON_AddNumberToObject(item, "group_median_monthly", *pay_gap_info_response->group_median_monthly) == NULL) {
    goto fail; //Numeric
    }
    }


    // pay_gap_info_response->group_size
    if (!pay_gap_info_response->group_size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "group_size", *pay_gap_info_response->group_size) == NULL) {
    goto fail; //Numeric
    }


    // pay_gap_info_response->job_title
    if (!pay_gap_info_response->job_title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "job_title", pay_gap_info_response->job_title) == NULL) {
    goto fail; //String
    }


    // pay_gap_info_response->last_name
    if (!pay_gap_info_response->last_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "last_name", pay_gap_info_response->last_name) == NULL) {
    goto fail; //String
    }


    // pay_gap_info_response->overall_median_hourly
    if(pay_gap_info_response->overall_median_hourly) {
    if(cJSON_AddNumberToObject(item, "overall_median_hourly", *pay_gap_info_response->overall_median_hourly) == NULL) {
    goto fail; //Numeric
    }
    }


    // pay_gap_info_response->own_hourly_gross
    if(pay_gap_info_response->own_hourly_gross) {
    if(cJSON_AddNumberToObject(item, "own_hourly_gross", *pay_gap_info_response->own_hourly_gross) == NULL) {
    goto fail; //Numeric
    }
    }


    // pay_gap_info_response->own_monthly_gross
    if(pay_gap_info_response->own_monthly_gross) {
    if(cJSON_AddNumberToObject(item, "own_monthly_gross", *pay_gap_info_response->own_monthly_gross) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pay_gap_info_response_t *pay_gap_info_response_parseFromJSON(cJSON *pay_gap_info_responseJSON){

    pay_gap_info_response_t *pay_gap_info_response_local_var = NULL;

    char *employee_id_local_str = NULL;

    char *first_name_local_str = NULL;

    char *gender_local_str = NULL;

    // define the local variable for pay_gap_info_response->group_median_hourly
    double *group_median_hourly_local_var = NULL;

    // define the local variable for pay_gap_info_response->group_median_monthly
    double *group_median_monthly_local_var = NULL;

    // define the local variable for pay_gap_info_response->group_size
    int *group_size_local_var = NULL;

    char *job_title_local_str = NULL;

    char *last_name_local_str = NULL;

    // define the local variable for pay_gap_info_response->overall_median_hourly
    double *overall_median_hourly_local_var = NULL;

    // define the local variable for pay_gap_info_response->own_hourly_gross
    double *own_hourly_gross_local_var = NULL;

    // define the local variable for pay_gap_info_response->own_monthly_gross
    double *own_monthly_gross_local_var = NULL;

    // pay_gap_info_response->employee_id
    cJSON *employee_id = cJSON_GetObjectItemCaseSensitive(pay_gap_info_responseJSON, "employee_id");
    if (cJSON_IsNull(employee_id)) {
        employee_id = NULL;
    }
    if (!employee_id) {
        goto end;
    }

    
    if(!cJSON_IsString(employee_id))
    {
    goto end; //String
    }

    // pay_gap_info_response->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(pay_gap_info_responseJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (!first_name) {
        goto end;
    }

    
    if(!cJSON_IsString(first_name))
    {
    goto end; //String
    }

    // pay_gap_info_response->gender
    cJSON *gender = cJSON_GetObjectItemCaseSensitive(pay_gap_info_responseJSON, "gender");
    if (cJSON_IsNull(gender)) {
        gender = NULL;
    }
    if (gender) { 
    if(!cJSON_IsString(gender) && !cJSON_IsNull(gender))
    {
    goto end; //String
    }
    }

    // pay_gap_info_response->group_median_hourly
    cJSON *group_median_hourly = cJSON_GetObjectItemCaseSensitive(pay_gap_info_responseJSON, "group_median_hourly");
    if (cJSON_IsNull(group_median_hourly)) {
        group_median_hourly = NULL;
    }
    if (group_median_hourly) { 
    if(!cJSON_IsNumber(group_median_hourly))
    {
    goto end; //Numeric
    }
    group_median_hourly_local_var = malloc(sizeof(double));
    if(!group_median_hourly_local_var)
    {
        goto end;
    }
    *group_median_hourly_local_var = group_median_hourly->valuedouble;
    }

    // pay_gap_info_response->group_median_monthly
    cJSON *group_median_monthly = cJSON_GetObjectItemCaseSensitive(pay_gap_info_responseJSON, "group_median_monthly");
    if (cJSON_IsNull(group_median_monthly)) {
        group_median_monthly = NULL;
    }
    if (group_median_monthly) { 
    if(!cJSON_IsNumber(group_median_monthly))
    {
    goto end; //Numeric
    }
    group_median_monthly_local_var = malloc(sizeof(double));
    if(!group_median_monthly_local_var)
    {
        goto end;
    }
    *group_median_monthly_local_var = group_median_monthly->valuedouble;
    }

    // pay_gap_info_response->group_size
    cJSON *group_size = cJSON_GetObjectItemCaseSensitive(pay_gap_info_responseJSON, "group_size");
    if (cJSON_IsNull(group_size)) {
        group_size = NULL;
    }
    if (!group_size) {
        goto end;
    }

    
    if(!cJSON_IsNumber(group_size))
    {
    goto end; //Numeric
    }
    group_size_local_var = malloc(sizeof(int));
    if(!group_size_local_var)
    {
        goto end;
    }
    *group_size_local_var = group_size->valuedouble;

    // pay_gap_info_response->job_title
    cJSON *job_title = cJSON_GetObjectItemCaseSensitive(pay_gap_info_responseJSON, "job_title");
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

    // pay_gap_info_response->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(pay_gap_info_responseJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (!last_name) {
        goto end;
    }

    
    if(!cJSON_IsString(last_name))
    {
    goto end; //String
    }

    // pay_gap_info_response->overall_median_hourly
    cJSON *overall_median_hourly = cJSON_GetObjectItemCaseSensitive(pay_gap_info_responseJSON, "overall_median_hourly");
    if (cJSON_IsNull(overall_median_hourly)) {
        overall_median_hourly = NULL;
    }
    if (overall_median_hourly) { 
    if(!cJSON_IsNumber(overall_median_hourly))
    {
    goto end; //Numeric
    }
    overall_median_hourly_local_var = malloc(sizeof(double));
    if(!overall_median_hourly_local_var)
    {
        goto end;
    }
    *overall_median_hourly_local_var = overall_median_hourly->valuedouble;
    }

    // pay_gap_info_response->own_hourly_gross
    cJSON *own_hourly_gross = cJSON_GetObjectItemCaseSensitive(pay_gap_info_responseJSON, "own_hourly_gross");
    if (cJSON_IsNull(own_hourly_gross)) {
        own_hourly_gross = NULL;
    }
    if (own_hourly_gross) { 
    if(!cJSON_IsNumber(own_hourly_gross))
    {
    goto end; //Numeric
    }
    own_hourly_gross_local_var = malloc(sizeof(double));
    if(!own_hourly_gross_local_var)
    {
        goto end;
    }
    *own_hourly_gross_local_var = own_hourly_gross->valuedouble;
    }

    // pay_gap_info_response->own_monthly_gross
    cJSON *own_monthly_gross = cJSON_GetObjectItemCaseSensitive(pay_gap_info_responseJSON, "own_monthly_gross");
    if (cJSON_IsNull(own_monthly_gross)) {
        own_monthly_gross = NULL;
    }
    if (own_monthly_gross) { 
    if(!cJSON_IsNumber(own_monthly_gross))
    {
    goto end; //Numeric
    }
    own_monthly_gross_local_var = malloc(sizeof(double));
    if(!own_monthly_gross_local_var)
    {
        goto end;
    }
    *own_monthly_gross_local_var = own_monthly_gross->valuedouble;
    }


    if (employee_id && !cJSON_IsNull(employee_id)) employee_id_local_str = strdup(employee_id->valuestring);
    if (first_name && !cJSON_IsNull(first_name)) first_name_local_str = strdup(first_name->valuestring);
    if (gender && !cJSON_IsNull(gender)) gender_local_str = strdup(gender->valuestring);
    if (job_title && !cJSON_IsNull(job_title)) job_title_local_str = strdup(job_title->valuestring);
    if (last_name && !cJSON_IsNull(last_name)) last_name_local_str = strdup(last_name->valuestring);

    pay_gap_info_response_local_var = pay_gap_info_response_create_internal (
        employee_id_local_str,
        first_name_local_str,
        gender_local_str,
        group_median_hourly_local_var,
        group_median_monthly_local_var,
        group_size_local_var,
        job_title_local_str,
        last_name_local_str,
        overall_median_hourly_local_var,
        own_hourly_gross_local_var,
        own_monthly_gross_local_var
        );

    if (!pay_gap_info_response_local_var) {
        goto end;
    }

    return pay_gap_info_response_local_var;
end:
    if (employee_id_local_str) {
        free(employee_id_local_str);
        employee_id_local_str = NULL;
    }
    if (first_name_local_str) {
        free(first_name_local_str);
        first_name_local_str = NULL;
    }
    if (gender_local_str) {
        free(gender_local_str);
        gender_local_str = NULL;
    }
    if (group_median_hourly_local_var) {
        free(group_median_hourly_local_var);
        group_median_hourly_local_var = NULL;
    }
    if (group_median_monthly_local_var) {
        free(group_median_monthly_local_var);
        group_median_monthly_local_var = NULL;
    }
    if (group_size_local_var) {
        free(group_size_local_var);
        group_size_local_var = NULL;
    }
    if (job_title_local_str) {
        free(job_title_local_str);
        job_title_local_str = NULL;
    }
    if (last_name_local_str) {
        free(last_name_local_str);
        last_name_local_str = NULL;
    }
    if (overall_median_hourly_local_var) {
        free(overall_median_hourly_local_var);
        overall_median_hourly_local_var = NULL;
    }
    if (own_hourly_gross_local_var) {
        free(own_hourly_gross_local_var);
        own_hourly_gross_local_var = NULL;
    }
    if (own_monthly_gross_local_var) {
        free(own_monthly_gross_local_var);
        own_monthly_gross_local_var = NULL;
    }
    return NULL;

}
