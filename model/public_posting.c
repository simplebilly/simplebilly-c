#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "public_posting.h"



static public_posting_t *public_posting_create_internal(
    char *currency,
    char *description,
    char *employment_type,
    char *id,
    char *location,
    int *remote,
    list_t *required_skills,
    char *requirements,
    int *salary_max,
    int *salary_min,
    char *title
    ) {
    public_posting_t *public_posting_local_var = malloc(sizeof(public_posting_t));
    if (!public_posting_local_var) {
        return NULL;
    }
    memset(public_posting_local_var, 0, sizeof(public_posting_t));
    public_posting_local_var->_library_owned = 1;
    public_posting_local_var->currency = currency;
    public_posting_local_var->description = description;
    public_posting_local_var->employment_type = employment_type;
    public_posting_local_var->id = id;
    public_posting_local_var->location = location;
    public_posting_local_var->remote = remote;
    public_posting_local_var->required_skills = required_skills;
    public_posting_local_var->requirements = requirements;
    public_posting_local_var->salary_max = salary_max;
    public_posting_local_var->salary_min = salary_min;
    public_posting_local_var->title = title;
    return public_posting_local_var;
}

__attribute__((deprecated)) public_posting_t *public_posting_create(
    char *currency,
    char *description,
    char *employment_type,
    char *id,
    char *location,
    int *remote,
    list_t *required_skills,
    char *requirements,
    int *salary_max,
    int *salary_min,
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
    public_posting_t *result = public_posting_create_internal (
        currency,
        description,
        employment_type,
        id,
        location,
        remote_copy,
        required_skills,
        requirements,
        salary_max_copy,
        salary_min_copy,
        title
        );
    if (!result) {
        free(remote_copy);
        free(salary_max_copy);
        free(salary_min_copy);
    }
    return result;
}

void public_posting_free(public_posting_t *public_posting) {
    if(NULL == public_posting){
        return ;
    }
    if(public_posting->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "public_posting_free");
        return ;
    }
    listEntry_t *listEntry;
    if (public_posting->currency) {
        free(public_posting->currency);
        public_posting->currency = NULL;
    }
    if (public_posting->description) {
        free(public_posting->description);
        public_posting->description = NULL;
    }
    if (public_posting->employment_type) {
        free(public_posting->employment_type);
        public_posting->employment_type = NULL;
    }
    if (public_posting->id) {
        free(public_posting->id);
        public_posting->id = NULL;
    }
    if (public_posting->location) {
        free(public_posting->location);
        public_posting->location = NULL;
    }
    if (public_posting->remote) {
        free(public_posting->remote);
        public_posting->remote = NULL;
    }
    if (public_posting->required_skills) {
        list_ForEach(listEntry, public_posting->required_skills) {
            free(listEntry->data);
        }
        list_freeList(public_posting->required_skills);
        public_posting->required_skills = NULL;
    }
    if (public_posting->requirements) {
        free(public_posting->requirements);
        public_posting->requirements = NULL;
    }
    if (public_posting->salary_max) {
        free(public_posting->salary_max);
        public_posting->salary_max = NULL;
    }
    if (public_posting->salary_min) {
        free(public_posting->salary_min);
        public_posting->salary_min = NULL;
    }
    if (public_posting->title) {
        free(public_posting->title);
        public_posting->title = NULL;
    }
    free(public_posting);
}

cJSON *public_posting_convertToJSON(public_posting_t *public_posting) {
    cJSON *item = cJSON_CreateObject();

    // public_posting->currency
    if(public_posting->currency) {
    if(cJSON_AddStringToObject(item, "currency", public_posting->currency) == NULL) {
    goto fail; //String
    }
    }


    // public_posting->description
    if (!public_posting->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", public_posting->description) == NULL) {
    goto fail; //String
    }


    // public_posting->employment_type
    if(public_posting->employment_type) {
    if(cJSON_AddStringToObject(item, "employmentType", public_posting->employment_type) == NULL) {
    goto fail; //String
    }
    }


    // public_posting->id
    if (!public_posting->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", public_posting->id) == NULL) {
    goto fail; //String
    }


    // public_posting->location
    if(public_posting->location) {
    if(cJSON_AddStringToObject(item, "location", public_posting->location) == NULL) {
    goto fail; //String
    }
    }


    // public_posting->remote
    if (!public_posting->remote) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "remote", *public_posting->remote) == NULL) {
    goto fail; //Bool
    }


    // public_posting->required_skills
    if (!public_posting->required_skills) {
        goto fail;
    }
    cJSON *required_skills = cJSON_AddArrayToObject(item, "requiredSkills");
    if(required_skills == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *required_skillsListEntry;
    list_ForEach(required_skillsListEntry, public_posting->required_skills) {
    if(cJSON_AddStringToObject(required_skills, "", required_skillsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // public_posting->requirements
    if(public_posting->requirements) {
    if(cJSON_AddStringToObject(item, "requirements", public_posting->requirements) == NULL) {
    goto fail; //String
    }
    }


    // public_posting->salary_max
    if(public_posting->salary_max) {
    if(cJSON_AddNumberToObject(item, "salaryMax", *public_posting->salary_max) == NULL) {
    goto fail; //Numeric
    }
    }


    // public_posting->salary_min
    if(public_posting->salary_min) {
    if(cJSON_AddNumberToObject(item, "salaryMin", *public_posting->salary_min) == NULL) {
    goto fail; //Numeric
    }
    }


    // public_posting->title
    if (!public_posting->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", public_posting->title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

public_posting_t *public_posting_parseFromJSON(cJSON *public_postingJSON){

    public_posting_t *public_posting_local_var = NULL;

    char *currency_local_str = NULL;

    char *description_local_str = NULL;

    char *employment_type_local_str = NULL;

    char *id_local_str = NULL;

    char *location_local_str = NULL;

    // define the local variable for public_posting->remote
    int *remote_local_var = NULL;

    // define the local list for public_posting->required_skills
    list_t *required_skillsList = NULL;

    char *requirements_local_str = NULL;

    // define the local variable for public_posting->salary_max
    int *salary_max_local_var = NULL;

    // define the local variable for public_posting->salary_min
    int *salary_min_local_var = NULL;

    char *title_local_str = NULL;

    // public_posting->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(public_postingJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // public_posting->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(public_postingJSON, "description");
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

    // public_posting->employment_type
    cJSON *employment_type = cJSON_GetObjectItemCaseSensitive(public_postingJSON, "employmentType");
    if (cJSON_IsNull(employment_type)) {
        employment_type = NULL;
    }
    if (employment_type) { 
    if(!cJSON_IsString(employment_type) && !cJSON_IsNull(employment_type))
    {
    goto end; //String
    }
    }

    // public_posting->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(public_postingJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // public_posting->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(public_postingJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (location) { 
    if(!cJSON_IsString(location) && !cJSON_IsNull(location))
    {
    goto end; //String
    }
    }

    // public_posting->remote
    cJSON *remote = cJSON_GetObjectItemCaseSensitive(public_postingJSON, "remote");
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

    // public_posting->required_skills
    cJSON *required_skills = cJSON_GetObjectItemCaseSensitive(public_postingJSON, "requiredSkills");
    if (cJSON_IsNull(required_skills)) {
        required_skills = NULL;
    }
    if (!required_skills) {
        goto end;
    }

    
    cJSON *required_skills_local = NULL;
    if(!cJSON_IsArray(required_skills)) {
        goto end;//primitive container
    }
    required_skillsList = list_createList();

    cJSON_ArrayForEach(required_skills_local, required_skills)
    {
        if(!cJSON_IsString(required_skills_local))
        {
            goto end;
        }
        list_addElement(required_skillsList , strdup(required_skills_local->valuestring));
    }

    // public_posting->requirements
    cJSON *requirements = cJSON_GetObjectItemCaseSensitive(public_postingJSON, "requirements");
    if (cJSON_IsNull(requirements)) {
        requirements = NULL;
    }
    if (requirements) { 
    if(!cJSON_IsString(requirements) && !cJSON_IsNull(requirements))
    {
    goto end; //String
    }
    }

    // public_posting->salary_max
    cJSON *salary_max = cJSON_GetObjectItemCaseSensitive(public_postingJSON, "salaryMax");
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

    // public_posting->salary_min
    cJSON *salary_min = cJSON_GetObjectItemCaseSensitive(public_postingJSON, "salaryMin");
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

    // public_posting->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(public_postingJSON, "title");
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
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (employment_type && !cJSON_IsNull(employment_type)) employment_type_local_str = strdup(employment_type->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (location && !cJSON_IsNull(location)) location_local_str = strdup(location->valuestring);
    if (requirements && !cJSON_IsNull(requirements)) requirements_local_str = strdup(requirements->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);

    public_posting_local_var = public_posting_create_internal (
        currency_local_str,
        description_local_str,
        employment_type_local_str,
        id_local_str,
        location_local_str,
        remote_local_var,
        required_skillsList,
        requirements_local_str,
        salary_max_local_var,
        salary_min_local_var,
        title_local_str
        );

    if (!public_posting_local_var) {
        goto end;
    }

    return public_posting_local_var;
end:
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (employment_type_local_str) {
        free(employment_type_local_str);
        employment_type_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (location_local_str) {
        free(location_local_str);
        location_local_str = NULL;
    }
    if (remote_local_var) {
        free(remote_local_var);
        remote_local_var = NULL;
    }
    if (required_skillsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, required_skillsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(required_skillsList);
        required_skillsList = NULL;
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
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    return NULL;

}
