#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job_posting.h"



static job_posting_t *job_posting_create_internal(
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
    job_posting_t *job_posting_local_var = malloc(sizeof(job_posting_t));
    if (!job_posting_local_var) {
        return NULL;
    }
    memset(job_posting_local_var, 0, sizeof(job_posting_t));
    job_posting_local_var->_library_owned = 1;
    job_posting_local_var->currency = currency;
    job_posting_local_var->department = department;
    job_posting_local_var->description = description;
    job_posting_local_var->employment_type = employment_type;
    job_posting_local_var->location = location;
    job_posting_local_var->remote = remote;
    job_posting_local_var->required_skills = required_skills;
    job_posting_local_var->requirements = requirements;
    job_posting_local_var->salary_max = salary_max;
    job_posting_local_var->salary_min = salary_min;
    job_posting_local_var->status = status;
    job_posting_local_var->title = title;
    return job_posting_local_var;
}

__attribute__((deprecated)) job_posting_t *job_posting_create(
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
    job_posting_t *result = job_posting_create_internal (
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

void job_posting_free(job_posting_t *job_posting) {
    if(NULL == job_posting){
        return ;
    }
    if(job_posting->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "job_posting_free");
        return ;
    }
    listEntry_t *listEntry;
    if (job_posting->currency) {
        free(job_posting->currency);
        job_posting->currency = NULL;
    }
    if (job_posting->department) {
        free(job_posting->department);
        job_posting->department = NULL;
    }
    if (job_posting->description) {
        free(job_posting->description);
        job_posting->description = NULL;
    }
    if (job_posting->employment_type) {
        employment_type_free(job_posting->employment_type);
        job_posting->employment_type = NULL;
    }
    if (job_posting->location) {
        free(job_posting->location);
        job_posting->location = NULL;
    }
    if (job_posting->remote) {
        free(job_posting->remote);
        job_posting->remote = NULL;
    }
    if (job_posting->required_skills) {
        _free(job_posting->required_skills);
        job_posting->required_skills = NULL;
    }
    if (job_posting->requirements) {
        free(job_posting->requirements);
        job_posting->requirements = NULL;
    }
    if (job_posting->salary_max) {
        free(job_posting->salary_max);
        job_posting->salary_max = NULL;
    }
    if (job_posting->salary_min) {
        free(job_posting->salary_min);
        job_posting->salary_min = NULL;
    }
    if (job_posting->status) {
        job_posting_status_free(job_posting->status);
        job_posting->status = NULL;
    }
    if (job_posting->title) {
        free(job_posting->title);
        job_posting->title = NULL;
    }
    free(job_posting);
}

cJSON *job_posting_convertToJSON(job_posting_t *job_posting) {
    cJSON *item = cJSON_CreateObject();

    // job_posting->currency
    if(job_posting->currency) {
    if(cJSON_AddStringToObject(item, "currency", job_posting->currency) == NULL) {
    goto fail; //String
    }
    }


    // job_posting->department
    if(job_posting->department) {
    if(cJSON_AddStringToObject(item, "department", job_posting->department) == NULL) {
    goto fail; //String
    }
    }


    // job_posting->description
    if (!job_posting->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", job_posting->description) == NULL) {
    goto fail; //String
    }


    // job_posting->employment_type
    if(job_posting->employment_type) {
    cJSON *employment_type_local_JSON = employment_type_convertToJSON(job_posting->employment_type);
    if(employment_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "employmentType", employment_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // job_posting->location
    if(job_posting->location) {
    if(cJSON_AddStringToObject(item, "location", job_posting->location) == NULL) {
    goto fail; //String
    }
    }


    // job_posting->remote
    if (!job_posting->remote) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "remote", *job_posting->remote) == NULL) {
    goto fail; //Bool
    }


    // job_posting->required_skills
    if (!job_posting->required_skills) {
        goto fail;
    }
    cJSON *required_skills_local_JSON = _convertToJSON(job_posting->required_skills);
    if(required_skills_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "requiredSkills", required_skills_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // job_posting->requirements
    if(job_posting->requirements) {
    if(cJSON_AddStringToObject(item, "requirements", job_posting->requirements) == NULL) {
    goto fail; //String
    }
    }


    // job_posting->salary_max
    if(job_posting->salary_max) {
    if(cJSON_AddNumberToObject(item, "salaryMax", *job_posting->salary_max) == NULL) {
    goto fail; //Numeric
    }
    }


    // job_posting->salary_min
    if(job_posting->salary_min) {
    if(cJSON_AddNumberToObject(item, "salaryMin", *job_posting->salary_min) == NULL) {
    goto fail; //Numeric
    }
    }


    // job_posting->status
    if (!job_posting->status) {
        goto fail;
    }
    cJSON *status_local_JSON = job_posting_status_convertToJSON(job_posting->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // job_posting->title
    if (!job_posting->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", job_posting->title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

job_posting_t *job_posting_parseFromJSON(cJSON *job_postingJSON){

    job_posting_t *job_posting_local_var = NULL;

    char *currency_local_str = NULL;

    char *department_local_str = NULL;

    char *description_local_str = NULL;

    // define the local variable for job_posting->employment_type
    employment_type_t *employment_type_local_nonprim = NULL;

    char *location_local_str = NULL;

    // define the local variable for job_posting->remote
    int *remote_local_var = NULL;

    // define the local variable for job_posting->required_skills
    _t *required_skills_local_nonprim = NULL;

    char *requirements_local_str = NULL;

    // define the local variable for job_posting->salary_max
    int *salary_max_local_var = NULL;

    // define the local variable for job_posting->salary_min
    int *salary_min_local_var = NULL;

    // define the local variable for job_posting->status
    job_posting_status_t *status_local_nonprim = NULL;

    char *title_local_str = NULL;

    // job_posting->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(job_postingJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // job_posting->department
    cJSON *department = cJSON_GetObjectItemCaseSensitive(job_postingJSON, "department");
    if (cJSON_IsNull(department)) {
        department = NULL;
    }
    if (department) { 
    if(!cJSON_IsString(department) && !cJSON_IsNull(department))
    {
    goto end; //String
    }
    }

    // job_posting->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(job_postingJSON, "description");
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

    // job_posting->employment_type
    cJSON *employment_type = cJSON_GetObjectItemCaseSensitive(job_postingJSON, "employmentType");
    if (cJSON_IsNull(employment_type)) {
        employment_type = NULL;
    }
    if (employment_type) { 
    employment_type_local_nonprim = employment_type_parseFromJSON(employment_type); //custom
    }

    // job_posting->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(job_postingJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (location) { 
    if(!cJSON_IsString(location) && !cJSON_IsNull(location))
    {
    goto end; //String
    }
    }

    // job_posting->remote
    cJSON *remote = cJSON_GetObjectItemCaseSensitive(job_postingJSON, "remote");
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

    // job_posting->required_skills
    cJSON *required_skills = cJSON_GetObjectItemCaseSensitive(job_postingJSON, "requiredSkills");
    if (cJSON_IsNull(required_skills)) {
        required_skills = NULL;
    }
    if (!required_skills) {
        goto end;
    }

    
    required_skills_local_nonprim = _parseFromJSON(required_skills); //custom

    // job_posting->requirements
    cJSON *requirements = cJSON_GetObjectItemCaseSensitive(job_postingJSON, "requirements");
    if (cJSON_IsNull(requirements)) {
        requirements = NULL;
    }
    if (requirements) { 
    if(!cJSON_IsString(requirements) && !cJSON_IsNull(requirements))
    {
    goto end; //String
    }
    }

    // job_posting->salary_max
    cJSON *salary_max = cJSON_GetObjectItemCaseSensitive(job_postingJSON, "salaryMax");
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

    // job_posting->salary_min
    cJSON *salary_min = cJSON_GetObjectItemCaseSensitive(job_postingJSON, "salaryMin");
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

    // job_posting->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(job_postingJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = job_posting_status_parseFromJSON(status); //custom

    // job_posting->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(job_postingJSON, "title");
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

    job_posting_local_var = job_posting_create_internal (
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

    if (!job_posting_local_var) {
        goto end;
    }

    return job_posting_local_var;
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
