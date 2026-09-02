#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "employee_update.h"



static employee_update_t *employee_update_create_internal(
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
    employee_status_t *status,
    char *user_id,
    char *weekly_hours,
    char *zip
    ) {
    employee_update_t *employee_update_local_var = malloc(sizeof(employee_update_t));
    if (!employee_update_local_var) {
        return NULL;
    }
    memset(employee_update_local_var, 0, sizeof(employee_update_t));
    employee_update_local_var->_library_owned = 1;
    employee_update_local_var->address = address;
    employee_update_local_var->backup_employee_id = backup_employee_id;
    employee_update_local_var->bic = bic;
    employee_update_local_var->city = city;
    employee_update_local_var->country = country;
    employee_update_local_var->date_of_birth = date_of_birth;
    employee_update_local_var->department_id = department_id;
    employee_update_local_var->email = email;
    employee_update_local_var->first_name = first_name;
    employee_update_local_var->gender = gender;
    employee_update_local_var->hire_date = hire_date;
    employee_update_local_var->hourly_cost = hourly_cost;
    employee_update_local_var->iban = iban;
    employee_update_local_var->job_title = job_title;
    employee_update_local_var->last_login = last_login;
    employee_update_local_var->last_name = last_name;
    employee_update_local_var->last_updated = last_updated;
    employee_update_local_var->monthly_salary = monthly_salary;
    employee_update_local_var->phone = phone;
    employee_update_local_var->state = state;
    employee_update_local_var->status = status;
    employee_update_local_var->user_id = user_id;
    employee_update_local_var->weekly_hours = weekly_hours;
    employee_update_local_var->zip = zip;
    return employee_update_local_var;
}

__attribute__((deprecated)) employee_update_t *employee_update_create(
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
    employee_status_t *status,
    char *user_id,
    char *weekly_hours,
    char *zip
    ) {
    employee_update_t *result = employee_update_create_internal (
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

void employee_update_free(employee_update_t *employee_update) {
    if(NULL == employee_update){
        return ;
    }
    if(employee_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "employee_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (employee_update->address) {
        free(employee_update->address);
        employee_update->address = NULL;
    }
    if (employee_update->backup_employee_id) {
        free(employee_update->backup_employee_id);
        employee_update->backup_employee_id = NULL;
    }
    if (employee_update->bic) {
        free(employee_update->bic);
        employee_update->bic = NULL;
    }
    if (employee_update->city) {
        free(employee_update->city);
        employee_update->city = NULL;
    }
    if (employee_update->country) {
        country_code_free(employee_update->country);
        employee_update->country = NULL;
    }
    if (employee_update->date_of_birth) {
        free(employee_update->date_of_birth);
        employee_update->date_of_birth = NULL;
    }
    if (employee_update->department_id) {
        free(employee_update->department_id);
        employee_update->department_id = NULL;
    }
    if (employee_update->email) {
        free(employee_update->email);
        employee_update->email = NULL;
    }
    if (employee_update->first_name) {
        free(employee_update->first_name);
        employee_update->first_name = NULL;
    }
    if (employee_update->gender) {
        gender_free(employee_update->gender);
        employee_update->gender = NULL;
    }
    if (employee_update->hire_date) {
        free(employee_update->hire_date);
        employee_update->hire_date = NULL;
    }
    if (employee_update->hourly_cost) {
        free(employee_update->hourly_cost);
        employee_update->hourly_cost = NULL;
    }
    if (employee_update->iban) {
        free(employee_update->iban);
        employee_update->iban = NULL;
    }
    if (employee_update->job_title) {
        free(employee_update->job_title);
        employee_update->job_title = NULL;
    }
    if (employee_update->last_login) {
        free(employee_update->last_login);
        employee_update->last_login = NULL;
    }
    if (employee_update->last_name) {
        free(employee_update->last_name);
        employee_update->last_name = NULL;
    }
    if (employee_update->last_updated) {
        free(employee_update->last_updated);
        employee_update->last_updated = NULL;
    }
    if (employee_update->monthly_salary) {
        free(employee_update->monthly_salary);
        employee_update->monthly_salary = NULL;
    }
    if (employee_update->phone) {
        free(employee_update->phone);
        employee_update->phone = NULL;
    }
    if (employee_update->state) {
        free(employee_update->state);
        employee_update->state = NULL;
    }
    if (employee_update->status) {
        employee_status_free(employee_update->status);
        employee_update->status = NULL;
    }
    if (employee_update->user_id) {
        free(employee_update->user_id);
        employee_update->user_id = NULL;
    }
    if (employee_update->weekly_hours) {
        free(employee_update->weekly_hours);
        employee_update->weekly_hours = NULL;
    }
    if (employee_update->zip) {
        free(employee_update->zip);
        employee_update->zip = NULL;
    }
    free(employee_update);
}

cJSON *employee_update_convertToJSON(employee_update_t *employee_update) {
    cJSON *item = cJSON_CreateObject();

    // employee_update->address
    if(employee_update->address) {
    if(cJSON_AddStringToObject(item, "address", employee_update->address) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->backup_employee_id
    if(employee_update->backup_employee_id) {
    if(cJSON_AddStringToObject(item, "backupEmployeeId", employee_update->backup_employee_id) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->bic
    if(employee_update->bic) {
    if(cJSON_AddStringToObject(item, "bic", employee_update->bic) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->city
    if(employee_update->city) {
    if(cJSON_AddStringToObject(item, "city", employee_update->city) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->country
    if(employee_update->country) {
    cJSON *country_local_JSON = country_code_convertToJSON(employee_update->country);
    if(country_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "country", country_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // employee_update->date_of_birth
    if(employee_update->date_of_birth) {
    if(cJSON_AddStringToObject(item, "dateOfBirth", employee_update->date_of_birth) == NULL) {
    goto fail; //Date
    }
    }


    // employee_update->department_id
    if(employee_update->department_id) {
    if(cJSON_AddStringToObject(item, "departmentId", employee_update->department_id) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->email
    if(employee_update->email) {
    if(cJSON_AddStringToObject(item, "email", employee_update->email) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->first_name
    if(employee_update->first_name) {
    if(cJSON_AddStringToObject(item, "firstName", employee_update->first_name) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->gender
    if(employee_update->gender) {
    cJSON *gender_local_JSON = gender_convertToJSON(employee_update->gender);
    if(gender_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "gender", gender_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // employee_update->hire_date
    if(employee_update->hire_date) {
    if(cJSON_AddStringToObject(item, "hireDate", employee_update->hire_date) == NULL) {
    goto fail; //Date
    }
    }


    // employee_update->hourly_cost
    if(employee_update->hourly_cost) {
    if(cJSON_AddStringToObject(item, "hourlyCost", employee_update->hourly_cost) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->iban
    if(employee_update->iban) {
    if(cJSON_AddStringToObject(item, "iban", employee_update->iban) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->job_title
    if(employee_update->job_title) {
    if(cJSON_AddStringToObject(item, "jobTitle", employee_update->job_title) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->last_login
    if(employee_update->last_login) {
    if(cJSON_AddStringToObject(item, "lastLogin", employee_update->last_login) == NULL) {
    goto fail; //Date-Time
    }
    }


    // employee_update->last_name
    if(employee_update->last_name) {
    if(cJSON_AddStringToObject(item, "lastName", employee_update->last_name) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->last_updated
    if(employee_update->last_updated) {
    if(cJSON_AddStringToObject(item, "lastUpdated", employee_update->last_updated) == NULL) {
    goto fail; //Date-Time
    }
    }


    // employee_update->monthly_salary
    if(employee_update->monthly_salary) {
    if(cJSON_AddStringToObject(item, "monthlySalary", employee_update->monthly_salary) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->phone
    if(employee_update->phone) {
    if(cJSON_AddStringToObject(item, "phone", employee_update->phone) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->state
    if(employee_update->state) {
    if(cJSON_AddStringToObject(item, "state", employee_update->state) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->status
    if(employee_update->status) {
    cJSON *status_local_JSON = employee_status_convertToJSON(employee_update->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // employee_update->user_id
    if(employee_update->user_id) {
    if(cJSON_AddStringToObject(item, "userId", employee_update->user_id) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->weekly_hours
    if(employee_update->weekly_hours) {
    if(cJSON_AddStringToObject(item, "weeklyHours", employee_update->weekly_hours) == NULL) {
    goto fail; //String
    }
    }


    // employee_update->zip
    if(employee_update->zip) {
    if(cJSON_AddStringToObject(item, "zip", employee_update->zip) == NULL) {
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

employee_update_t *employee_update_parseFromJSON(cJSON *employee_updateJSON){

    employee_update_t *employee_update_local_var = NULL;

    char *address_local_str = NULL;

    char *backup_employee_id_local_str = NULL;

    char *bic_local_str = NULL;

    char *city_local_str = NULL;

    // define the local variable for employee_update->country
    country_code_t *country_local_nonprim = NULL;

    char *date_of_birth_local_str = NULL;

    char *department_id_local_str = NULL;

    char *email_local_str = NULL;

    char *first_name_local_str = NULL;

    // define the local variable for employee_update->gender
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

    // define the local variable for employee_update->status
    employee_status_t *status_local_nonprim = NULL;

    char *user_id_local_str = NULL;

    char *weekly_hours_local_str = NULL;

    char *zip_local_str = NULL;

    // employee_update->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    if(!cJSON_IsString(address) && !cJSON_IsNull(address))
    {
    goto end; //String
    }
    }

    // employee_update->backup_employee_id
    cJSON *backup_employee_id = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "backupEmployeeId");
    if (cJSON_IsNull(backup_employee_id)) {
        backup_employee_id = NULL;
    }
    if (backup_employee_id) { 
    if(!cJSON_IsString(backup_employee_id) && !cJSON_IsNull(backup_employee_id))
    {
    goto end; //String
    }
    }

    // employee_update->bic
    cJSON *bic = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "bic");
    if (cJSON_IsNull(bic)) {
        bic = NULL;
    }
    if (bic) { 
    if(!cJSON_IsString(bic) && !cJSON_IsNull(bic))
    {
    goto end; //String
    }
    }

    // employee_update->city
    cJSON *city = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "city");
    if (cJSON_IsNull(city)) {
        city = NULL;
    }
    if (city) { 
    if(!cJSON_IsString(city) && !cJSON_IsNull(city))
    {
    goto end; //String
    }
    }

    // employee_update->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    country_local_nonprim = country_code_parseFromJSON(country); //custom
    }

    // employee_update->date_of_birth
    cJSON *date_of_birth = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "dateOfBirth");
    if (cJSON_IsNull(date_of_birth)) {
        date_of_birth = NULL;
    }
    if (date_of_birth) { 
    if(!cJSON_IsString(date_of_birth))
    {
    goto end; //Date
    }
    }

    // employee_update->department_id
    cJSON *department_id = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "departmentId");
    if (cJSON_IsNull(department_id)) {
        department_id = NULL;
    }
    if (department_id) { 
    if(!cJSON_IsString(department_id) && !cJSON_IsNull(department_id))
    {
    goto end; //String
    }
    }

    // employee_update->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // employee_update->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "firstName");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (first_name) { 
    if(!cJSON_IsString(first_name) && !cJSON_IsNull(first_name))
    {
    goto end; //String
    }
    }

    // employee_update->gender
    cJSON *gender = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "gender");
    if (cJSON_IsNull(gender)) {
        gender = NULL;
    }
    if (gender) { 
    gender_local_nonprim = gender_parseFromJSON(gender); //custom
    }

    // employee_update->hire_date
    cJSON *hire_date = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "hireDate");
    if (cJSON_IsNull(hire_date)) {
        hire_date = NULL;
    }
    if (hire_date) { 
    if(!cJSON_IsString(hire_date))
    {
    goto end; //Date
    }
    }

    // employee_update->hourly_cost
    cJSON *hourly_cost = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "hourlyCost");
    if (cJSON_IsNull(hourly_cost)) {
        hourly_cost = NULL;
    }
    if (hourly_cost) { 
    if(!cJSON_IsString(hourly_cost) && !cJSON_IsNull(hourly_cost))
    {
    goto end; //String
    }
    }

    // employee_update->iban
    cJSON *iban = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "iban");
    if (cJSON_IsNull(iban)) {
        iban = NULL;
    }
    if (iban) { 
    if(!cJSON_IsString(iban) && !cJSON_IsNull(iban))
    {
    goto end; //String
    }
    }

    // employee_update->job_title
    cJSON *job_title = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "jobTitle");
    if (cJSON_IsNull(job_title)) {
        job_title = NULL;
    }
    if (job_title) { 
    if(!cJSON_IsString(job_title) && !cJSON_IsNull(job_title))
    {
    goto end; //String
    }
    }

    // employee_update->last_login
    cJSON *last_login = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "lastLogin");
    if (cJSON_IsNull(last_login)) {
        last_login = NULL;
    }
    if (last_login) { 
    if(!cJSON_IsString(last_login) && !cJSON_IsNull(last_login))
    {
    goto end; //DateTime
    }
    }

    // employee_update->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "lastName");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // employee_update->last_updated
    cJSON *last_updated = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "lastUpdated");
    if (cJSON_IsNull(last_updated)) {
        last_updated = NULL;
    }
    if (last_updated) { 
    if(!cJSON_IsString(last_updated) && !cJSON_IsNull(last_updated))
    {
    goto end; //DateTime
    }
    }

    // employee_update->monthly_salary
    cJSON *monthly_salary = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "monthlySalary");
    if (cJSON_IsNull(monthly_salary)) {
        monthly_salary = NULL;
    }
    if (monthly_salary) { 
    if(!cJSON_IsString(monthly_salary) && !cJSON_IsNull(monthly_salary))
    {
    goto end; //String
    }
    }

    // employee_update->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // employee_update->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (state) { 
    if(!cJSON_IsString(state) && !cJSON_IsNull(state))
    {
    goto end; //String
    }
    }

    // employee_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = employee_status_parseFromJSON(status); //custom
    }

    // employee_update->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "userId");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (user_id) { 
    if(!cJSON_IsString(user_id) && !cJSON_IsNull(user_id))
    {
    goto end; //String
    }
    }

    // employee_update->weekly_hours
    cJSON *weekly_hours = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "weeklyHours");
    if (cJSON_IsNull(weekly_hours)) {
        weekly_hours = NULL;
    }
    if (weekly_hours) { 
    if(!cJSON_IsString(weekly_hours) && !cJSON_IsNull(weekly_hours))
    {
    goto end; //String
    }
    }

    // employee_update->zip
    cJSON *zip = cJSON_GetObjectItemCaseSensitive(employee_updateJSON, "zip");
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

    employee_update_local_var = employee_update_create_internal (
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
        status ? status_local_nonprim : NULL,
        user_id_local_str,
        weekly_hours_local_str,
        zip_local_str
        );

    if (!employee_update_local_var) {
        goto end;
    }

    return employee_update_local_var;
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
        employee_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
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
