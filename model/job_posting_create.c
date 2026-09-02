#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job_posting_create.h"



static job_posting_create_t *job_posting_create_create_internal(
    char *currency,
    char *department,
    char *description,
    employment_type_t *employment_type,
    char *location,
    int *remote,
    any_type_t *required_skills,
    char *requirements,
    int *salary_max,
    int *salary_min,
    job_posting_status_t *status,
    char *title
    ) {
    job_posting_create_t *job_posting_create_local_var = malloc(sizeof(job_posting_create_t));
    if (!job_posting_create_local_var) {
        return NULL;
    }
    memset(job_posting_create_local_var, 0, sizeof(job_posting_create_t));
    job_posting_create_local_var->_library_owned = 1;
    job_posting_create_local_var->currency = currency;
    job_posting_create_local_var->department = department;
    job_posting_create_local_var->description = description;
    job_posting_create_local_var->employment_type = employment_type;
    job_posting_create_local_var->location = location;
    job_posting_create_local_var->remote = remote;
    job_posting_create_local_var->required_skills = required_skills;
    job_posting_create_local_var->requirements = requirements;
    job_posting_create_local_var->salary_max = salary_max;
    job_posting_create_local_var->salary_min = salary_min;
    job_posting_create_local_var->status = status;
    job_posting_create_local_var->title = title;
    return job_posting_create_local_var;
}

__attribute__((deprecated)) job_posting_create_t *job_posting_create_create(
    char *currency,
    char *department,
    char *description,
    employment_type_t *employment_type,
    char *location,
    int *remote,
    any_type_t *required_skills,
    char *requirements,
    int *salary_max,
    int *salary_min,
    job_posting_status_t *status,
    char *title
    ) {
    int *remote_copy = NULL;
    if (remote) {
        remote_copy = malloc(sizeof(int));
        if (remote_copy) *remote_copy = *remote;
    }
    int *salary_max_copy = NULL;
    if (salary_max) {
        salary_max_copy = malloc(sizeof(int));
        if (salary_max_copy) *salary_max_copy = *salary_max;
    }
    int *salary_min_copy = NULL;
    if (salary_min) {
        salary_min_copy = malloc(sizeof(int));
        if (salary_min_copy) *salary_min_copy = *salary_min;
    }
    job_posting_create_t *result = job_posting_create_create_internal (
        currency,
        department,
        description,
        employment_type,
        location,
        remote_copy,
        required_skills,
        requirements,
        salary_max_copy,
        salary_min_copy,
        status,
        title
        );
    if (!result) {
        free(remote_copy);
        free(salary_max_copy);
        free(salary_min_copy);
    }
    return result;
}

void job_posting_create_free(job_posting_create_t *job_posting_create) {
    if(NULL == job_posting_create){
        return ;
    }
    if(job_posting_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "job_posting_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (job_posting_create->currency) {
        free(job_posting_create->currency);
        job_posting_create->currency = NULL;
    }
    if (job_posting_create->department) {
        free(job_posting_create->department);
        job_posting_create->department = NULL;
    }
    if (job_posting_create->description) {
        free(job_posting_create->description);
        job_posting_create->description = NULL;
    }
    if (job_posting_create->employment_type) {
        employment_type_free(job_posting_create->employment_type);
        job_posting_create->employment_type = NULL;
    }
    if (job_posting_create->location) {
        free(job_posting_create->location);
        job_posting_create->location = NULL;
    }
    if (job_posting_create->remote) {
        free(job_posting_create->remote);
        job_posting_create->remote = NULL;
    }
    if (job_posting_create->required_skills) {
        _free(job_posting_create->required_skills);
        job_posting_create->required_skills = NULL;
    }
    if (job_posting_create->requirements) {
        free(job_posting_create->requirements);
        job_posting_create->requirements = NULL;
    }
    if (job_posting_create->salary_max) {
        free(job_posting_create->salary_max);
        job_posting_create->salary_max = NULL;
    }
    if (job_posting_create->salary_min) {
        free(job_posting_create->salary_min);
        job_posting_create->salary_min = NULL;
    }
    if (job_posting_create->status) {
        job_posting_status_free(job_posting_create->status);
        job_posting_create->status = NULL;
    }
    if (job_posting_create->title) {
        free(job_posting_create->title);
        job_posting_create->title = NULL;
    }
    free(job_posting_create);
}

cJSON *job_posting_create_convertToJSON(job_posting_create_t *job_posting_create) {
    cJSON *item = cJSON_CreateObject();

    // job_posting_create->currency
    if(job_posting_create->currency) {
    if(cJSON_AddStringToObject(item, "currency", job_posting_create->currency) == NULL) {
    goto fail; //String
    }
    }


    // job_posting_create->department
    if(job_posting_create->department) {
    if(cJSON_AddStringToObject(item, "department", job_posting_create->department) == NULL) {
    goto fail; //String
    }
    }


    // job_posting_create->description
    if (!job_posting_create->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", job_posting_create->description) == NULL) {
    goto fail; //String
    }


    // job_posting_create->employment_type
    if(job_posting_create->employment_type) {
    cJSON *employment_type_local_JSON = employment_type_convertToJSON(job_posting_create->employment_type);
    if(employment_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "employmentType", employment_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // job_posting_create->location
    if(job_posting_create->location) {
    if(cJSON_AddStringToObject(item, "location", job_posting_create->location) == NULL) {
    goto fail; //String
    }
    }


    // job_posting_create->remote
    if (!job_posting_create->remote) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "remote", *job_posting_create->remote) == NULL) {
    goto fail; //Bool
    }


    // job_posting_create->required_skills
    if (!job_posting_create->required_skills) {
        goto fail;
    }
    cJSON *required_skills_local_JSON = _convertToJSON(job_posting_create->required_skills);
    if(required_skills_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "requiredSkills", required_skills_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // job_posting_create->requirements
    if(job_posting_create->requirements) {
    if(cJSON_AddStringToObject(item, "requirements", job_posting_create->requirements) == NULL) {
    goto fail; //String
    }
    }


    // job_posting_create->salary_max
    if(job_posting_create->salary_max) {
    if(cJSON_AddNumberToObject(item, "salaryMax", *job_posting_create->salary_max) == NULL) {
    goto fail; //Numeric
    }
    }


    // job_posting_create->salary_min
    if(job_posting_create->salary_min) {
    if(cJSON_AddNumberToObject(item, "salaryMin", *job_posting_create->salary_min) == NULL) {
    goto fail; //Numeric
    }
    }


    // job_posting_create->status
    if (!job_posting_create->status) {
        goto fail;
    }
    cJSON *status_local_JSON = job_posting_status_convertToJSON(job_posting_create->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // job_posting_create->title
    if (!job_posting_create->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", job_posting_create->title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

job_posting_create_t *job_posting_create_parseFromJSON(cJSON *job_posting_createJSON){

    job_posting_create_t *job_posting_create_local_var = NULL;

    char *currency_local_str = NULL;

    char *department_local_str = NULL;

    char *description_local_str = NULL;

    // define the local variable for job_posting_create->employment_type
    employment_type_t *employment_type_local_nonprim = NULL;

    char *location_local_str = NULL;

    // define the local variable for job_posting_create->remote
    int *remote_local_var = NULL;

    // define the local variable for job_posting_create->required_skills
    _t *required_skills_local_nonprim = NULL;

    char *requirements_local_str = NULL;

    // define the local variable for job_posting_create->salary_max
    int *salary_max_local_var = NULL;

    // define the local variable for job_posting_create->salary_min
    int *salary_min_local_var = NULL;

    // define the local variable for job_posting_create->status
    job_posting_status_t *status_local_nonprim = NULL;

    char *title_local_str = NULL;

    // job_posting_create->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(job_posting_createJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // job_posting_create->department
    cJSON *department = cJSON_GetObjectItemCaseSensitive(job_posting_createJSON, "department");
    if (cJSON_IsNull(department)) {
        department = NULL;
    }
    if (department) { 
    if(!cJSON_IsString(department) && !cJSON_IsNull(department))
    {
    goto end; //String
    }
    }

    // job_posting_create->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(job_posting_createJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }

    // job_posting_create->employment_type
    cJSON *employment_type = cJSON_GetObjectItemCaseSensitive(job_posting_createJSON, "employmentType");
    if (cJSON_IsNull(employment_type)) {
        employment_type = NULL;
    }
    if (employment_type) { 
    employment_type_local_nonprim = employment_type_parseFromJSON(employment_type); //custom
    }

    // job_posting_create->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(job_posting_createJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (location) { 
    if(!cJSON_IsString(location) && !cJSON_IsNull(location))
    {
    goto end; //String
    }
    }

    // job_posting_create->remote
    cJSON *remote = cJSON_GetObjectItemCaseSensitive(job_posting_createJSON, "remote");
    if (cJSON_IsNull(remote)) {
        remote = NULL;
    }
    if (!remote) {
        goto end;
    }

    
    if(!cJSON_IsBool(remote))
    {
    goto end; //Bool
    }
    remote_local_var = malloc(sizeof(int));
    if(!remote_local_var)
    {
        goto end;
    }
    *remote_local_var = remote->valueint;

    // job_posting_create->required_skills
    cJSON *required_skills = cJSON_GetObjectItemCaseSensitive(job_posting_createJSON, "requiredSkills");
    if (cJSON_IsNull(required_skills)) {
        required_skills = NULL;
    }
    if (!required_skills) {
        goto end;
    }

    
    required_skills_local_nonprim = _parseFromJSON(required_skills); //custom

    // job_posting_create->requirements
    cJSON *requirements = cJSON_GetObjectItemCaseSensitive(job_posting_createJSON, "requirements");
    if (cJSON_IsNull(requirements)) {
        requirements = NULL;
    }
    if (requirements) { 
    if(!cJSON_IsString(requirements) && !cJSON_IsNull(requirements))
    {
    goto end; //String
    }
    }

    // job_posting_create->salary_max
    cJSON *salary_max = cJSON_GetObjectItemCaseSensitive(job_posting_createJSON, "salaryMax");
    if (cJSON_IsNull(salary_max)) {
        salary_max = NULL;
    }
    if (salary_max) { 
    if(!cJSON_IsNumber(salary_max))
    {
    goto end; //Numeric
    }
    salary_max_local_var = malloc(sizeof(int));
    if(!salary_max_local_var)
    {
        goto end;
    }
    *salary_max_local_var = salary_max->valuedouble;
    }

    // job_posting_create->salary_min
    cJSON *salary_min = cJSON_GetObjectItemCaseSensitive(job_posting_createJSON, "salaryMin");
    if (cJSON_IsNull(salary_min)) {
        salary_min = NULL;
    }
    if (salary_min) { 
    if(!cJSON_IsNumber(salary_min))
    {
    goto end; //Numeric
    }
    salary_min_local_var = malloc(sizeof(int));
    if(!salary_min_local_var)
    {
        goto end;
    }
    *salary_min_local_var = salary_min->valuedouble;
    }

    // job_posting_create->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(job_posting_createJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = job_posting_status_parseFromJSON(status); //custom

    // job_posting_create->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(job_posting_createJSON, "title");
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


    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (department && !cJSON_IsNull(department)) department_local_str = strdup(department->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (location && !cJSON_IsNull(location)) location_local_str = strdup(location->valuestring);
    if (requirements && !cJSON_IsNull(requirements)) requirements_local_str = strdup(requirements->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);

    job_posting_create_local_var = job_posting_create_create_internal (
        currency_local_str,
        department_local_str,
        description_local_str,
        employment_type ? employment_type_local_nonprim : NULL,
        location_local_str,
        remote_local_var,
        required_skills_local_nonprim,
        requirements_local_str,
        salary_max_local_var,
        salary_min_local_var,
        status_local_nonprim,
        title_local_str
        );

    if (!job_posting_create_local_var) {
        goto end;
    }

    return job_posting_create_local_var;
end:
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (department_local_str) {
        free(department_local_str);
        department_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (employment_type_local_nonprim) {
        employment_type_free(employment_type_local_nonprim);
        employment_type_local_nonprim = NULL;
    }
    if (location_local_str) {
        free(location_local_str);
        location_local_str = NULL;
    }
    if (remote_local_var) {
        free(remote_local_var);
        remote_local_var = NULL;
    }
    if (required_skills_local_nonprim) {
        _free(required_skills_local_nonprim);
        required_skills_local_nonprim = NULL;
    }
    if (requirements_local_str) {
        free(requirements_local_str);
        requirements_local_str = NULL;
    }
    if (salary_max_local_var) {
        free(salary_max_local_var);
        salary_max_local_var = NULL;
    }
    if (salary_min_local_var) {
        free(salary_min_local_var);
        salary_min_local_var = NULL;
    }
    if (status_local_nonprim) {
        job_posting_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    return NULL;

}
