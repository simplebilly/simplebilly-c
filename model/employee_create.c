#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "employee_create.h"



static employee_create_t *employee_create_create_internal(
    char *address,
    char *backup_employee_id,
    char *bic,
    char *city,
    country_code_t *country,
    char *date_of_birth,
    char *department_id,
    char *email,
    char *first_name,
    gender_t *gender,
    char *hire_date,
    char *hourly_cost,
    char *iban,
    char *job_title,
    char *last_login,
    char *last_name,
    char *last_updated,
    char *monthly_salary,
    char *phone,
    char *state,
    simplebilly_api_employee_status__e status,
    char *user_id,
    char *weekly_hours,
    char *zip
    ) {
    employee_create_t *employee_create_local_var = malloc(sizeof(employee_create_t));
    if (!employee_create_local_var) {
        return NULL;
    }
    memset(employee_create_local_var, 0, sizeof(employee_create_t));
    employee_create_local_var->_library_owned = 1;
    employee_create_local_var->address = address;
    employee_create_local_var->backup_employee_id = backup_employee_id;
    employee_create_local_var->bic = bic;
    employee_create_local_var->city = city;
    employee_create_local_var->country = country;
    employee_create_local_var->date_of_birth = date_of_birth;
    employee_create_local_var->department_id = department_id;
    employee_create_local_var->email = email;
    employee_create_local_var->first_name = first_name;
    employee_create_local_var->gender = gender;
    employee_create_local_var->hire_date = hire_date;
    employee_create_local_var->hourly_cost = hourly_cost;
    employee_create_local_var->iban = iban;
    employee_create_local_var->job_title = job_title;
    employee_create_local_var->last_login = last_login;
    employee_create_local_var->last_name = last_name;
    employee_create_local_var->last_updated = last_updated;
    employee_create_local_var->monthly_salary = monthly_salary;
    employee_create_local_var->phone = phone;
    employee_create_local_var->state = state;
    employee_create_local_var->status = status;
    employee_create_local_var->user_id = user_id;
    employee_create_local_var->weekly_hours = weekly_hours;
    employee_create_local_var->zip = zip;
    return employee_create_local_var;
}

__attribute__((deprecated)) employee_create_t *employee_create_create(
    char *address,
    char *backup_employee_id,
    char *bic,
    char *city,
    country_code_t *country,
    char *date_of_birth,
    char *department_id,
    char *email,
    char *first_name,
    gender_t *gender,
    char *hire_date,
    char *hourly_cost,
    char *iban,
    char *job_title,
    char *last_login,
    char *last_name,
    char *last_updated,
    char *monthly_salary,
    char *phone,
    char *state,
    simplebilly_api_employee_status__e status,
    char *user_id,
    char *weekly_hours,
    char *zip
    ) {
    employee_create_t *result = employee_create_create_internal (
        address,
        backup_employee_id,
        bic,
        city,
        country,
        date_of_birth,
        department_id,
        email,
        first_name,
        gender,
        hire_date,
        hourly_cost,
        iban,
        job_title,
        last_login,
        last_name,
        last_updated,
        monthly_salary,
        phone,
        state,
        status,
        user_id,
        weekly_hours,
        zip
        );
    if (!result) {
    }
    return result;
}

void employee_create_free(employee_create_t *employee_create) {
    if(NULL == employee_create){
        return ;
    }
    if(employee_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "employee_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (employee_create->address) {
        free(employee_create->address);
        employee_create->address = NULL;
    }
    if (employee_create->backup_employee_id) {
        free(employee_create->backup_employee_id);
        employee_create->backup_employee_id = NULL;
    }
    if (employee_create->bic) {
        free(employee_create->bic);
        employee_create->bic = NULL;
    }
    if (employee_create->city) {
        free(employee_create->city);
        employee_create->city = NULL;
    }
    if (employee_create->country) {
        country_code_free(employee_create->country);
        employee_create->country = NULL;
    }
    if (employee_create->date_of_birth) {
        free(employee_create->date_of_birth);
        employee_create->date_of_birth = NULL;
    }
    if (employee_create->department_id) {
        free(employee_create->department_id);
        employee_create->department_id = NULL;
    }
    if (employee_create->email) {
        free(employee_create->email);
        employee_create->email = NULL;
    }
    if (employee_create->first_name) {
        free(employee_create->first_name);
        employee_create->first_name = NULL;
    }
    if (employee_create->gender) {
        gender_free(employee_create->gender);
        employee_create->gender = NULL;
    }
    if (employee_create->hire_date) {
        free(employee_create->hire_date);
        employee_create->hire_date = NULL;
    }
    if (employee_create->hourly_cost) {
        free(employee_create->hourly_cost);
        employee_create->hourly_cost = NULL;
    }
    if (employee_create->iban) {
        free(employee_create->iban);
        employee_create->iban = NULL;
    }
    if (employee_create->job_title) {
        free(employee_create->job_title);
        employee_create->job_title = NULL;
    }
    if (employee_create->last_login) {
        free(employee_create->last_login);
        employee_create->last_login = NULL;
    }
    if (employee_create->last_name) {
        free(employee_create->last_name);
        employee_create->last_name = NULL;
    }
    if (employee_create->last_updated) {
        free(employee_create->last_updated);
        employee_create->last_updated = NULL;
    }
    if (employee_create->monthly_salary) {
        free(employee_create->monthly_salary);
        employee_create->monthly_salary = NULL;
    }
    if (employee_create->phone) {
        free(employee_create->phone);
        employee_create->phone = NULL;
    }
    if (employee_create->state) {
        free(employee_create->state);
        employee_create->state = NULL;
    }
    if (employee_create->user_id) {
        free(employee_create->user_id);
        employee_create->user_id = NULL;
    }
    if (employee_create->weekly_hours) {
        free(employee_create->weekly_hours);
        employee_create->weekly_hours = NULL;
    }
    if (employee_create->zip) {
        free(employee_create->zip);
        employee_create->zip = NULL;
    }
    free(employee_create);
}

cJSON *employee_create_convertToJSON(employee_create_t *employee_create) {
    cJSON *item = cJSON_CreateObject();

    // employee_create->address
    if(employee_create->address) {
    if(cJSON_AddStringToObject(item, "address", employee_create->address) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->backup_employee_id
    if(employee_create->backup_employee_id) {
    if(cJSON_AddStringToObject(item, "backupEmployeeId", employee_create->backup_employee_id) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->bic
    if(employee_create->bic) {
    if(cJSON_AddStringToObject(item, "bic", employee_create->bic) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->city
    if(employee_create->city) {
    if(cJSON_AddStringToObject(item, "city", employee_create->city) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->country
    if(employee_create->country) {
    cJSON *country_local_JSON = country_code_convertToJSON(employee_create->country);
    if(country_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "country", country_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // employee_create->date_of_birth
    if(employee_create->date_of_birth) {
    if(cJSON_AddStringToObject(item, "dateOfBirth", employee_create->date_of_birth) == NULL) {
    goto fail; //Date
    }
    }


    // employee_create->department_id
    if(employee_create->department_id) {
    if(cJSON_AddStringToObject(item, "departmentId", employee_create->department_id) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->email
    if(employee_create->email) {
    if(cJSON_AddStringToObject(item, "email", employee_create->email) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->first_name
    if(employee_create->first_name) {
    if(cJSON_AddStringToObject(item, "firstName", employee_create->first_name) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->gender
    if(employee_create->gender) {
    cJSON *gender_local_JSON = gender_convertToJSON(employee_create->gender);
    if(gender_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "gender", gender_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // employee_create->hire_date
    if(employee_create->hire_date) {
    if(cJSON_AddStringToObject(item, "hireDate", employee_create->hire_date) == NULL) {
    goto fail; //Date
    }
    }


    // employee_create->hourly_cost
    if(employee_create->hourly_cost) {
    if(cJSON_AddStringToObject(item, "hourlyCost", employee_create->hourly_cost) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->iban
    if(employee_create->iban) {
    if(cJSON_AddStringToObject(item, "iban", employee_create->iban) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->job_title
    if(employee_create->job_title) {
    if(cJSON_AddStringToObject(item, "jobTitle", employee_create->job_title) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->last_login
    if(employee_create->last_login) {
    if(cJSON_AddStringToObject(item, "lastLogin", employee_create->last_login) == NULL) {
    goto fail; //Date-Time
    }
    }


    // employee_create->last_name
    if(employee_create->last_name) {
    if(cJSON_AddStringToObject(item, "lastName", employee_create->last_name) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->last_updated
    if(employee_create->last_updated) {
    if(cJSON_AddStringToObject(item, "lastUpdated", employee_create->last_updated) == NULL) {
    goto fail; //Date-Time
    }
    }


    // employee_create->monthly_salary
    if(employee_create->monthly_salary) {
    if(cJSON_AddStringToObject(item, "monthlySalary", employee_create->monthly_salary) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->phone
    if(employee_create->phone) {
    if(cJSON_AddStringToObject(item, "phone", employee_create->phone) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->state
    if(employee_create->state) {
    if(cJSON_AddStringToObject(item, "state", employee_create->state) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->status
    if(employee_create->status != simplebilly_api_employee_status__NULL) {
    cJSON *status_local_JSON = employee_status_convertToJSON(employee_create->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // employee_create->user_id
    if(employee_create->user_id) {
    if(cJSON_AddStringToObject(item, "userId", employee_create->user_id) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->weekly_hours
    if(employee_create->weekly_hours) {
    if(cJSON_AddStringToObject(item, "weeklyHours", employee_create->weekly_hours) == NULL) {
    goto fail; //String
    }
    }


    // employee_create->zip
    if(employee_create->zip) {
    if(cJSON_AddStringToObject(item, "zip", employee_create->zip) == NULL) {
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

employee_create_t *employee_create_parseFromJSON(cJSON *employee_createJSON){

    employee_create_t *employee_create_local_var = NULL;

    char *address_local_str = NULL;

    char *backup_employee_id_local_str = NULL;

    char *bic_local_str = NULL;

    char *city_local_str = NULL;

    // define the local variable for employee_create->country
    country_code_t *country_local_nonprim = NULL;

    char *date_of_birth_local_str = NULL;

    char *department_id_local_str = NULL;

    char *email_local_str = NULL;

    char *first_name_local_str = NULL;

    // define the local variable for employee_create->gender
    gender_t *gender_local_nonprim = NULL;

    char *hire_date_local_str = NULL;

    char *hourly_cost_local_str = NULL;

    char *iban_local_str = NULL;

    char *job_title_local_str = NULL;

    char *last_login_local_str = NULL;

    char *last_name_local_str = NULL;

    char *last_updated_local_str = NULL;

    char *monthly_salary_local_str = NULL;

    char *phone_local_str = NULL;

    char *state_local_str = NULL;

    // define the local variable for employee_create->status
    simplebilly_api_employee_status__e status_local_nonprim = 0;

    char *user_id_local_str = NULL;

    char *weekly_hours_local_str = NULL;

    char *zip_local_str = NULL;

    // employee_create->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    if(!cJSON_IsString(address) && !cJSON_IsNull(address))
    {
    goto end; //String
    }
    }

    // employee_create->backup_employee_id
    cJSON *backup_employee_id = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "backupEmployeeId");
    if (cJSON_IsNull(backup_employee_id)) {
        backup_employee_id = NULL;
    }
    if (backup_employee_id) { 
    if(!cJSON_IsString(backup_employee_id) && !cJSON_IsNull(backup_employee_id))
    {
    goto end; //String
    }
    }

    // employee_create->bic
    cJSON *bic = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "bic");
    if (cJSON_IsNull(bic)) {
        bic = NULL;
    }
    if (bic) { 
    if(!cJSON_IsString(bic) && !cJSON_IsNull(bic))
    {
    goto end; //String
    }
    }

    // employee_create->city
    cJSON *city = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "city");
    if (cJSON_IsNull(city)) {
        city = NULL;
    }
    if (city) { 
    if(!cJSON_IsString(city) && !cJSON_IsNull(city))
    {
    goto end; //String
    }
    }

    // employee_create->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    country_local_nonprim = country_code_parseFromJSON(country); //custom
    }

    // employee_create->date_of_birth
    cJSON *date_of_birth = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "dateOfBirth");
    if (cJSON_IsNull(date_of_birth)) {
        date_of_birth = NULL;
    }
    if (date_of_birth) { 
    if(!cJSON_IsString(date_of_birth))
    {
    goto end; //Date
    }
    }

    // employee_create->department_id
    cJSON *department_id = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "departmentId");
    if (cJSON_IsNull(department_id)) {
        department_id = NULL;
    }
    if (department_id) { 
    if(!cJSON_IsString(department_id) && !cJSON_IsNull(department_id))
    {
    goto end; //String
    }
    }

    // employee_create->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // employee_create->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "firstName");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (first_name) { 
    if(!cJSON_IsString(first_name) && !cJSON_IsNull(first_name))
    {
    goto end; //String
    }
    }

    // employee_create->gender
    cJSON *gender = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "gender");
    if (cJSON_IsNull(gender)) {
        gender = NULL;
    }
    if (gender) { 
    gender_local_nonprim = gender_parseFromJSON(gender); //custom
    }

    // employee_create->hire_date
    cJSON *hire_date = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "hireDate");
    if (cJSON_IsNull(hire_date)) {
        hire_date = NULL;
    }
    if (hire_date) { 
    if(!cJSON_IsString(hire_date))
    {
    goto end; //Date
    }
    }

    // employee_create->hourly_cost
    cJSON *hourly_cost = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "hourlyCost");
    if (cJSON_IsNull(hourly_cost)) {
        hourly_cost = NULL;
    }
    if (hourly_cost) { 
    if(!cJSON_IsString(hourly_cost) && !cJSON_IsNull(hourly_cost))
    {
    goto end; //String
    }
    }

    // employee_create->iban
    cJSON *iban = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "iban");
    if (cJSON_IsNull(iban)) {
        iban = NULL;
    }
    if (iban) { 
    if(!cJSON_IsString(iban) && !cJSON_IsNull(iban))
    {
    goto end; //String
    }
    }

    // employee_create->job_title
    cJSON *job_title = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "jobTitle");
    if (cJSON_IsNull(job_title)) {
        job_title = NULL;
    }
    if (job_title) { 
    if(!cJSON_IsString(job_title) && !cJSON_IsNull(job_title))
    {
    goto end; //String
    }
    }

    // employee_create->last_login
    cJSON *last_login = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "lastLogin");
    if (cJSON_IsNull(last_login)) {
        last_login = NULL;
    }
    if (last_login) { 
    if(!cJSON_IsString(last_login) && !cJSON_IsNull(last_login))
    {
    goto end; //DateTime
    }
    }

    // employee_create->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "lastName");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // employee_create->last_updated
    cJSON *last_updated = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "lastUpdated");
    if (cJSON_IsNull(last_updated)) {
        last_updated = NULL;
    }
    if (last_updated) { 
    if(!cJSON_IsString(last_updated) && !cJSON_IsNull(last_updated))
    {
    goto end; //DateTime
    }
    }

    // employee_create->monthly_salary
    cJSON *monthly_salary = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "monthlySalary");
    if (cJSON_IsNull(monthly_salary)) {
        monthly_salary = NULL;
    }
    if (monthly_salary) { 
    if(!cJSON_IsString(monthly_salary) && !cJSON_IsNull(monthly_salary))
    {
    goto end; //String
    }
    }

    // employee_create->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // employee_create->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (state) { 
    if(!cJSON_IsString(state) && !cJSON_IsNull(state))
    {
    goto end; //String
    }
    }

    // employee_create->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = employee_status_parseFromJSON(status); //custom
    }

    // employee_create->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "userId");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (user_id) { 
    if(!cJSON_IsString(user_id) && !cJSON_IsNull(user_id))
    {
    goto end; //String
    }
    }

    // employee_create->weekly_hours
    cJSON *weekly_hours = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "weeklyHours");
    if (cJSON_IsNull(weekly_hours)) {
        weekly_hours = NULL;
    }
    if (weekly_hours) { 
    if(!cJSON_IsString(weekly_hours) && !cJSON_IsNull(weekly_hours))
    {
    goto end; //String
    }
    }

    // employee_create->zip
    cJSON *zip = cJSON_GetObjectItemCaseSensitive(employee_createJSON, "zip");
    if (cJSON_IsNull(zip)) {
        zip = NULL;
    }
    if (zip) { 
    if(!cJSON_IsString(zip) && !cJSON_IsNull(zip))
    {
    goto end; //String
    }
    }


    if (address && !cJSON_IsNull(address)) address_local_str = strdup(address->valuestring);
    if (backup_employee_id && !cJSON_IsNull(backup_employee_id)) backup_employee_id_local_str = strdup(backup_employee_id->valuestring);
    if (bic && !cJSON_IsNull(bic)) bic_local_str = strdup(bic->valuestring);
    if (city && !cJSON_IsNull(city)) city_local_str = strdup(city->valuestring);
    if (date_of_birth) date_of_birth_local_str = strdup(date_of_birth->valuestring);
    if (department_id && !cJSON_IsNull(department_id)) department_id_local_str = strdup(department_id->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (first_name && !cJSON_IsNull(first_name)) first_name_local_str = strdup(first_name->valuestring);
    if (hire_date) hire_date_local_str = strdup(hire_date->valuestring);
    if (hourly_cost && !cJSON_IsNull(hourly_cost)) hourly_cost_local_str = strdup(hourly_cost->valuestring);
    if (iban && !cJSON_IsNull(iban)) iban_local_str = strdup(iban->valuestring);
    if (job_title && !cJSON_IsNull(job_title)) job_title_local_str = strdup(job_title->valuestring);
    if (last_login && !cJSON_IsNull(last_login)) last_login_local_str = strdup(last_login->valuestring);
    if (last_name && !cJSON_IsNull(last_name)) last_name_local_str = strdup(last_name->valuestring);
    if (last_updated && !cJSON_IsNull(last_updated)) last_updated_local_str = strdup(last_updated->valuestring);
    if (monthly_salary && !cJSON_IsNull(monthly_salary)) monthly_salary_local_str = strdup(monthly_salary->valuestring);
    if (phone && !cJSON_IsNull(phone)) phone_local_str = strdup(phone->valuestring);
    if (state && !cJSON_IsNull(state)) state_local_str = strdup(state->valuestring);
    if (user_id && !cJSON_IsNull(user_id)) user_id_local_str = strdup(user_id->valuestring);
    if (weekly_hours && !cJSON_IsNull(weekly_hours)) weekly_hours_local_str = strdup(weekly_hours->valuestring);
    if (zip && !cJSON_IsNull(zip)) zip_local_str = strdup(zip->valuestring);

    employee_create_local_var = employee_create_create_internal (
        address_local_str,
        backup_employee_id_local_str,
        bic_local_str,
        city_local_str,
        country ? country_local_nonprim : NULL,
        date_of_birth_local_str,
        department_id_local_str,
        email_local_str,
        first_name_local_str,
        gender ? gender_local_nonprim : NULL,
        hire_date_local_str,
        hourly_cost_local_str,
        iban_local_str,
        job_title_local_str,
        last_login_local_str,
        last_name_local_str,
        last_updated_local_str,
        monthly_salary_local_str,
        phone_local_str,
        state_local_str,
        status ? status_local_nonprim : 0,
        user_id_local_str,
        weekly_hours_local_str,
        zip_local_str
        );

    if (!employee_create_local_var) {
        goto end;
    }

    return employee_create_local_var;
end:
    if (address_local_str) {
        free(address_local_str);
        address_local_str = NULL;
    }
    if (backup_employee_id_local_str) {
        free(backup_employee_id_local_str);
        backup_employee_id_local_str = NULL;
    }
    if (bic_local_str) {
        free(bic_local_str);
        bic_local_str = NULL;
    }
    if (city_local_str) {
        free(city_local_str);
        city_local_str = NULL;
    }
    if (country_local_nonprim) {
        country_code_free(country_local_nonprim);
        country_local_nonprim = NULL;
    }
    if (date_of_birth_local_str) {
        free(date_of_birth_local_str);
        date_of_birth_local_str = NULL;
    }
    if (department_id_local_str) {
        free(department_id_local_str);
        department_id_local_str = NULL;
    }
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (first_name_local_str) {
        free(first_name_local_str);
        first_name_local_str = NULL;
    }
    if (gender_local_nonprim) {
        gender_free(gender_local_nonprim);
        gender_local_nonprim = NULL;
    }
    if (hire_date_local_str) {
        free(hire_date_local_str);
        hire_date_local_str = NULL;
    }
    if (hourly_cost_local_str) {
        free(hourly_cost_local_str);
        hourly_cost_local_str = NULL;
    }
    if (iban_local_str) {
        free(iban_local_str);
        iban_local_str = NULL;
    }
    if (job_title_local_str) {
        free(job_title_local_str);
        job_title_local_str = NULL;
    }
    if (last_login_local_str) {
        free(last_login_local_str);
        last_login_local_str = NULL;
    }
    if (last_name_local_str) {
        free(last_name_local_str);
        last_name_local_str = NULL;
    }
    if (last_updated_local_str) {
        free(last_updated_local_str);
        last_updated_local_str = NULL;
    }
    if (monthly_salary_local_str) {
        free(monthly_salary_local_str);
        monthly_salary_local_str = NULL;
    }
    if (phone_local_str) {
        free(phone_local_str);
        phone_local_str = NULL;
    }
    if (state_local_str) {
        free(state_local_str);
        state_local_str = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    if (user_id_local_str) {
        free(user_id_local_str);
        user_id_local_str = NULL;
    }
    if (weekly_hours_local_str) {
        free(weekly_hours_local_str);
        weekly_hours_local_str = NULL;
    }
    if (zip_local_str) {
        free(zip_local_str);
        zip_local_str = NULL;
    }
    return NULL;

}
