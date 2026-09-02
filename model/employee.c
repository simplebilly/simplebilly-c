#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "employee.h"



static employee_t *employee_create_internal(
    char *address,
    char *backup_employee_id,
    char *bic,
    char *city,
    country_code_t *country,
    char *created_at,
    char *date_of_birth,
    char *deleted_at,
    char *department_id,
    char *email,
    char *first_name,
    gender_t *gender,
    char *hire_date,
    char *hourly_cost,
    char *iban,
    char *id,
    char *job_title,
    char *last_login,
    char *last_name,
    char *last_updated,
    char *monthly_salary,
    char *phone,
    char *state,
    simplebilly_api_employee_status__e status,
    char *tenant_id,
    char *updated_at,
    char *user_id,
    char *weekly_hours,
    char *zip
    ) {
    employee_t *employee_local_var = malloc(sizeof(employee_t));
    if (!employee_local_var) {
        return NULL;
    }
    memset(employee_local_var, 0, sizeof(employee_t));
    employee_local_var->_library_owned = 1;
    employee_local_var->address = address;
    employee_local_var->backup_employee_id = backup_employee_id;
    employee_local_var->bic = bic;
    employee_local_var->city = city;
    employee_local_var->country = country;
    employee_local_var->created_at = created_at;
    employee_local_var->date_of_birth = date_of_birth;
    employee_local_var->deleted_at = deleted_at;
    employee_local_var->department_id = department_id;
    employee_local_var->email = email;
    employee_local_var->first_name = first_name;
    employee_local_var->gender = gender;
    employee_local_var->hire_date = hire_date;
    employee_local_var->hourly_cost = hourly_cost;
    employee_local_var->iban = iban;
    employee_local_var->id = id;
    employee_local_var->job_title = job_title;
    employee_local_var->last_login = last_login;
    employee_local_var->last_name = last_name;
    employee_local_var->last_updated = last_updated;
    employee_local_var->monthly_salary = monthly_salary;
    employee_local_var->phone = phone;
    employee_local_var->state = state;
    employee_local_var->status = status;
    employee_local_var->tenant_id = tenant_id;
    employee_local_var->updated_at = updated_at;
    employee_local_var->user_id = user_id;
    employee_local_var->weekly_hours = weekly_hours;
    employee_local_var->zip = zip;
    return employee_local_var;
}

__attribute__((deprecated)) employee_t *employee_create(
    char *address,
    char *backup_employee_id,
    char *bic,
    char *city,
    country_code_t *country,
    char *created_at,
    char *date_of_birth,
    char *deleted_at,
    char *department_id,
    char *email,
    char *first_name,
    gender_t *gender,
    char *hire_date,
    char *hourly_cost,
    char *iban,
    char *id,
    char *job_title,
    char *last_login,
    char *last_name,
    char *last_updated,
    char *monthly_salary,
    char *phone,
    char *state,
    simplebilly_api_employee_status__e status,
    char *tenant_id,
    char *updated_at,
    char *user_id,
    char *weekly_hours,
    char *zip
    ) {
    employee_t *result = employee_create_internal (
        address,
        backup_employee_id,
        bic,
        city,
        country,
        created_at,
        date_of_birth,
        deleted_at,
        department_id,
        email,
        first_name,
        gender,
        hire_date,
        hourly_cost,
        iban,
        id,
        job_title,
        last_login,
        last_name,
        last_updated,
        monthly_salary,
        phone,
        state,
        status,
        tenant_id,
        updated_at,
        user_id,
        weekly_hours,
        zip
        );
    if (!result) {
    }
    return result;
}

void employee_free(employee_t *employee) {
    if(NULL == employee){
        return ;
    }
    if(employee->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "employee_free");
        return ;
    }
    listEntry_t *listEntry;
    if (employee->address) {
        free(employee->address);
        employee->address = NULL;
    }
    if (employee->backup_employee_id) {
        free(employee->backup_employee_id);
        employee->backup_employee_id = NULL;
    }
    if (employee->bic) {
        free(employee->bic);
        employee->bic = NULL;
    }
    if (employee->city) {
        free(employee->city);
        employee->city = NULL;
    }
    if (employee->country) {
        country_code_free(employee->country);
        employee->country = NULL;
    }
    if (employee->created_at) {
        free(employee->created_at);
        employee->created_at = NULL;
    }
    if (employee->date_of_birth) {
        free(employee->date_of_birth);
        employee->date_of_birth = NULL;
    }
    if (employee->deleted_at) {
        free(employee->deleted_at);
        employee->deleted_at = NULL;
    }
    if (employee->department_id) {
        free(employee->department_id);
        employee->department_id = NULL;
    }
    if (employee->email) {
        free(employee->email);
        employee->email = NULL;
    }
    if (employee->first_name) {
        free(employee->first_name);
        employee->first_name = NULL;
    }
    if (employee->gender) {
        gender_free(employee->gender);
        employee->gender = NULL;
    }
    if (employee->hire_date) {
        free(employee->hire_date);
        employee->hire_date = NULL;
    }
    if (employee->hourly_cost) {
        free(employee->hourly_cost);
        employee->hourly_cost = NULL;
    }
    if (employee->iban) {
        free(employee->iban);
        employee->iban = NULL;
    }
    if (employee->id) {
        free(employee->id);
        employee->id = NULL;
    }
    if (employee->job_title) {
        free(employee->job_title);
        employee->job_title = NULL;
    }
    if (employee->last_login) {
        free(employee->last_login);
        employee->last_login = NULL;
    }
    if (employee->last_name) {
        free(employee->last_name);
        employee->last_name = NULL;
    }
    if (employee->last_updated) {
        free(employee->last_updated);
        employee->last_updated = NULL;
    }
    if (employee->monthly_salary) {
        free(employee->monthly_salary);
        employee->monthly_salary = NULL;
    }
    if (employee->phone) {
        free(employee->phone);
        employee->phone = NULL;
    }
    if (employee->state) {
        free(employee->state);
        employee->state = NULL;
    }
    if (employee->tenant_id) {
        free(employee->tenant_id);
        employee->tenant_id = NULL;
    }
    if (employee->updated_at) {
        free(employee->updated_at);
        employee->updated_at = NULL;
    }
    if (employee->user_id) {
        free(employee->user_id);
        employee->user_id = NULL;
    }
    if (employee->weekly_hours) {
        free(employee->weekly_hours);
        employee->weekly_hours = NULL;
    }
    if (employee->zip) {
        free(employee->zip);
        employee->zip = NULL;
    }
    free(employee);
}

cJSON *employee_convertToJSON(employee_t *employee) {
    cJSON *item = cJSON_CreateObject();

    // employee->address
    if(employee->address) {
    if(cJSON_AddStringToObject(item, "address", employee->address) == NULL) {
    goto fail; //String
    }
    }


    // employee->backup_employee_id
    if(employee->backup_employee_id) {
    if(cJSON_AddStringToObject(item, "backupEmployeeId", employee->backup_employee_id) == NULL) {
    goto fail; //String
    }
    }


    // employee->bic
    if(employee->bic) {
    if(cJSON_AddStringToObject(item, "bic", employee->bic) == NULL) {
    goto fail; //String
    }
    }


    // employee->city
    if(employee->city) {
    if(cJSON_AddStringToObject(item, "city", employee->city) == NULL) {
    goto fail; //String
    }
    }


    // employee->country
    if(employee->country) {
    cJSON *country_local_JSON = country_code_convertToJSON(employee->country);
    if(country_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "country", country_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // employee->created_at
    if(employee->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", employee->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // employee->date_of_birth
    if(employee->date_of_birth) {
    if(cJSON_AddStringToObject(item, "dateOfBirth", employee->date_of_birth) == NULL) {
    goto fail; //Date
    }
    }


    // employee->deleted_at
    if(employee->deleted_at) {
    if(cJSON_AddStringToObject(item, "deletedAt", employee->deleted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // employee->department_id
    if(employee->department_id) {
    if(cJSON_AddStringToObject(item, "departmentId", employee->department_id) == NULL) {
    goto fail; //String
    }
    }


    // employee->email
    if(employee->email) {
    if(cJSON_AddStringToObject(item, "email", employee->email) == NULL) {
    goto fail; //String
    }
    }


    // employee->first_name
    if(employee->first_name) {
    if(cJSON_AddStringToObject(item, "firstName", employee->first_name) == NULL) {
    goto fail; //String
    }
    }


    // employee->gender
    if(employee->gender) {
    cJSON *gender_local_JSON = gender_convertToJSON(employee->gender);
    if(gender_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "gender", gender_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // employee->hire_date
    if(employee->hire_date) {
    if(cJSON_AddStringToObject(item, "hireDate", employee->hire_date) == NULL) {
    goto fail; //Date
    }
    }


    // employee->hourly_cost
    if(employee->hourly_cost) {
    if(cJSON_AddStringToObject(item, "hourlyCost", employee->hourly_cost) == NULL) {
    goto fail; //String
    }
    }


    // employee->iban
    if(employee->iban) {
    if(cJSON_AddStringToObject(item, "iban", employee->iban) == NULL) {
    goto fail; //String
    }
    }


    // employee->id
    if(employee->id) {
    if(cJSON_AddStringToObject(item, "id", employee->id) == NULL) {
    goto fail; //String
    }
    }


    // employee->job_title
    if(employee->job_title) {
    if(cJSON_AddStringToObject(item, "jobTitle", employee->job_title) == NULL) {
    goto fail; //String
    }
    }


    // employee->last_login
    if(employee->last_login) {
    if(cJSON_AddStringToObject(item, "lastLogin", employee->last_login) == NULL) {
    goto fail; //Date-Time
    }
    }


    // employee->last_name
    if(employee->last_name) {
    if(cJSON_AddStringToObject(item, "lastName", employee->last_name) == NULL) {
    goto fail; //String
    }
    }


    // employee->last_updated
    if(employee->last_updated) {
    if(cJSON_AddStringToObject(item, "lastUpdated", employee->last_updated) == NULL) {
    goto fail; //Date-Time
    }
    }


    // employee->monthly_salary
    if(employee->monthly_salary) {
    if(cJSON_AddStringToObject(item, "monthlySalary", employee->monthly_salary) == NULL) {
    goto fail; //String
    }
    }


    // employee->phone
    if(employee->phone) {
    if(cJSON_AddStringToObject(item, "phone", employee->phone) == NULL) {
    goto fail; //String
    }
    }


    // employee->state
    if(employee->state) {
    if(cJSON_AddStringToObject(item, "state", employee->state) == NULL) {
    goto fail; //String
    }
    }


    // employee->status
    if(employee->status != simplebilly_api_employee_status__NULL) {
    cJSON *status_local_JSON = employee_status_convertToJSON(employee->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // employee->tenant_id
    if(employee->tenant_id) {
    if(cJSON_AddStringToObject(item, "tenantId", employee->tenant_id) == NULL) {
    goto fail; //String
    }
    }


    // employee->updated_at
    if(employee->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", employee->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // employee->user_id
    if(employee->user_id) {
    if(cJSON_AddStringToObject(item, "userId", employee->user_id) == NULL) {
    goto fail; //String
    }
    }


    // employee->weekly_hours
    if(employee->weekly_hours) {
    if(cJSON_AddStringToObject(item, "weeklyHours", employee->weekly_hours) == NULL) {
    goto fail; //String
    }
    }


    // employee->zip
    if(employee->zip) {
    if(cJSON_AddStringToObject(item, "zip", employee->zip) == NULL) {
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

employee_t *employee_parseFromJSON(cJSON *employeeJSON){

    employee_t *employee_local_var = NULL;

    char *address_local_str = NULL;

    char *backup_employee_id_local_str = NULL;

    char *bic_local_str = NULL;

    char *city_local_str = NULL;

    // define the local variable for employee->country
    country_code_t *country_local_nonprim = NULL;

    char *created_at_local_str = NULL;

    char *date_of_birth_local_str = NULL;

    char *deleted_at_local_str = NULL;

    char *department_id_local_str = NULL;

    char *email_local_str = NULL;

    char *first_name_local_str = NULL;

    // define the local variable for employee->gender
    gender_t *gender_local_nonprim = NULL;

    char *hire_date_local_str = NULL;

    char *hourly_cost_local_str = NULL;

    char *iban_local_str = NULL;

    char *id_local_str = NULL;

    char *job_title_local_str = NULL;

    char *last_login_local_str = NULL;

    char *last_name_local_str = NULL;

    char *last_updated_local_str = NULL;

    char *monthly_salary_local_str = NULL;

    char *phone_local_str = NULL;

    char *state_local_str = NULL;

    // define the local variable for employee->status
    simplebilly_api_employee_status__e status_local_nonprim = 0;

    char *tenant_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    char *user_id_local_str = NULL;

    char *weekly_hours_local_str = NULL;

    char *zip_local_str = NULL;

    // employee->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(employeeJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    if(!cJSON_IsString(address) && !cJSON_IsNull(address))
    {
    goto end; //String
    }
    }

    // employee->backup_employee_id
    cJSON *backup_employee_id = cJSON_GetObjectItemCaseSensitive(employeeJSON, "backupEmployeeId");
    if (cJSON_IsNull(backup_employee_id)) {
        backup_employee_id = NULL;
    }
    if (backup_employee_id) { 
    if(!cJSON_IsString(backup_employee_id) && !cJSON_IsNull(backup_employee_id))
    {
    goto end; //String
    }
    }

    // employee->bic
    cJSON *bic = cJSON_GetObjectItemCaseSensitive(employeeJSON, "bic");
    if (cJSON_IsNull(bic)) {
        bic = NULL;
    }
    if (bic) { 
    if(!cJSON_IsString(bic) && !cJSON_IsNull(bic))
    {
    goto end; //String
    }
    }

    // employee->city
    cJSON *city = cJSON_GetObjectItemCaseSensitive(employeeJSON, "city");
    if (cJSON_IsNull(city)) {
        city = NULL;
    }
    if (city) { 
    if(!cJSON_IsString(city) && !cJSON_IsNull(city))
    {
    goto end; //String
    }
    }

    // employee->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(employeeJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    country_local_nonprim = country_code_parseFromJSON(country); //custom
    }

    // employee->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(employeeJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // employee->date_of_birth
    cJSON *date_of_birth = cJSON_GetObjectItemCaseSensitive(employeeJSON, "dateOfBirth");
    if (cJSON_IsNull(date_of_birth)) {
        date_of_birth = NULL;
    }
    if (date_of_birth) { 
    if(!cJSON_IsString(date_of_birth))
    {
    goto end; //Date
    }
    }

    // employee->deleted_at
    cJSON *deleted_at = cJSON_GetObjectItemCaseSensitive(employeeJSON, "deletedAt");
    if (cJSON_IsNull(deleted_at)) {
        deleted_at = NULL;
    }
    if (deleted_at) { 
    if(!cJSON_IsString(deleted_at) && !cJSON_IsNull(deleted_at))
    {
    goto end; //DateTime
    }
    }

    // employee->department_id
    cJSON *department_id = cJSON_GetObjectItemCaseSensitive(employeeJSON, "departmentId");
    if (cJSON_IsNull(department_id)) {
        department_id = NULL;
    }
    if (department_id) { 
    if(!cJSON_IsString(department_id) && !cJSON_IsNull(department_id))
    {
    goto end; //String
    }
    }

    // employee->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(employeeJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // employee->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(employeeJSON, "firstName");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (first_name) { 
    if(!cJSON_IsString(first_name) && !cJSON_IsNull(first_name))
    {
    goto end; //String
    }
    }

    // employee->gender
    cJSON *gender = cJSON_GetObjectItemCaseSensitive(employeeJSON, "gender");
    if (cJSON_IsNull(gender)) {
        gender = NULL;
    }
    if (gender) { 
    gender_local_nonprim = gender_parseFromJSON(gender); //custom
    }

    // employee->hire_date
    cJSON *hire_date = cJSON_GetObjectItemCaseSensitive(employeeJSON, "hireDate");
    if (cJSON_IsNull(hire_date)) {
        hire_date = NULL;
    }
    if (hire_date) { 
    if(!cJSON_IsString(hire_date))
    {
    goto end; //Date
    }
    }

    // employee->hourly_cost
    cJSON *hourly_cost = cJSON_GetObjectItemCaseSensitive(employeeJSON, "hourlyCost");
    if (cJSON_IsNull(hourly_cost)) {
        hourly_cost = NULL;
    }
    if (hourly_cost) { 
    if(!cJSON_IsString(hourly_cost) && !cJSON_IsNull(hourly_cost))
    {
    goto end; //String
    }
    }

    // employee->iban
    cJSON *iban = cJSON_GetObjectItemCaseSensitive(employeeJSON, "iban");
    if (cJSON_IsNull(iban)) {
        iban = NULL;
    }
    if (iban) { 
    if(!cJSON_IsString(iban) && !cJSON_IsNull(iban))
    {
    goto end; //String
    }
    }

    // employee->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(employeeJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // employee->job_title
    cJSON *job_title = cJSON_GetObjectItemCaseSensitive(employeeJSON, "jobTitle");
    if (cJSON_IsNull(job_title)) {
        job_title = NULL;
    }
    if (job_title) { 
    if(!cJSON_IsString(job_title) && !cJSON_IsNull(job_title))
    {
    goto end; //String
    }
    }

    // employee->last_login
    cJSON *last_login = cJSON_GetObjectItemCaseSensitive(employeeJSON, "lastLogin");
    if (cJSON_IsNull(last_login)) {
        last_login = NULL;
    }
    if (last_login) { 
    if(!cJSON_IsString(last_login) && !cJSON_IsNull(last_login))
    {
    goto end; //DateTime
    }
    }

    // employee->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(employeeJSON, "lastName");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // employee->last_updated
    cJSON *last_updated = cJSON_GetObjectItemCaseSensitive(employeeJSON, "lastUpdated");
    if (cJSON_IsNull(last_updated)) {
        last_updated = NULL;
    }
    if (last_updated) { 
    if(!cJSON_IsString(last_updated) && !cJSON_IsNull(last_updated))
    {
    goto end; //DateTime
    }
    }

    // employee->monthly_salary
    cJSON *monthly_salary = cJSON_GetObjectItemCaseSensitive(employeeJSON, "monthlySalary");
    if (cJSON_IsNull(monthly_salary)) {
        monthly_salary = NULL;
    }
    if (monthly_salary) { 
    if(!cJSON_IsString(monthly_salary) && !cJSON_IsNull(monthly_salary))
    {
    goto end; //String
    }
    }

    // employee->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(employeeJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // employee->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(employeeJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (state) { 
    if(!cJSON_IsString(state) && !cJSON_IsNull(state))
    {
    goto end; //String
    }
    }

    // employee->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(employeeJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = employee_status_parseFromJSON(status); //custom
    }

    // employee->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(employeeJSON, "tenantId");
    if (cJSON_IsNull(tenant_id)) {
        tenant_id = NULL;
    }
    if (tenant_id) { 
    if(!cJSON_IsString(tenant_id) && !cJSON_IsNull(tenant_id))
    {
    goto end; //String
    }
    }

    // employee->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(employeeJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }

    // employee->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(employeeJSON, "userId");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (user_id) { 
    if(!cJSON_IsString(user_id) && !cJSON_IsNull(user_id))
    {
    goto end; //String
    }
    }

    // employee->weekly_hours
    cJSON *weekly_hours = cJSON_GetObjectItemCaseSensitive(employeeJSON, "weeklyHours");
    if (cJSON_IsNull(weekly_hours)) {
        weekly_hours = NULL;
    }
    if (weekly_hours) { 
    if(!cJSON_IsString(weekly_hours) && !cJSON_IsNull(weekly_hours))
    {
    goto end; //String
    }
    }

    // employee->zip
    cJSON *zip = cJSON_GetObjectItemCaseSensitive(employeeJSON, "zip");
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
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (date_of_birth) date_of_birth_local_str = strdup(date_of_birth->valuestring);
    if (deleted_at && !cJSON_IsNull(deleted_at)) deleted_at_local_str = strdup(deleted_at->valuestring);
    if (department_id && !cJSON_IsNull(department_id)) department_id_local_str = strdup(department_id->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (first_name && !cJSON_IsNull(first_name)) first_name_local_str = strdup(first_name->valuestring);
    if (hire_date) hire_date_local_str = strdup(hire_date->valuestring);
    if (hourly_cost && !cJSON_IsNull(hourly_cost)) hourly_cost_local_str = strdup(hourly_cost->valuestring);
    if (iban && !cJSON_IsNull(iban)) iban_local_str = strdup(iban->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (job_title && !cJSON_IsNull(job_title)) job_title_local_str = strdup(job_title->valuestring);
    if (last_login && !cJSON_IsNull(last_login)) last_login_local_str = strdup(last_login->valuestring);
    if (last_name && !cJSON_IsNull(last_name)) last_name_local_str = strdup(last_name->valuestring);
    if (last_updated && !cJSON_IsNull(last_updated)) last_updated_local_str = strdup(last_updated->valuestring);
    if (monthly_salary && !cJSON_IsNull(monthly_salary)) monthly_salary_local_str = strdup(monthly_salary->valuestring);
    if (phone && !cJSON_IsNull(phone)) phone_local_str = strdup(phone->valuestring);
    if (state && !cJSON_IsNull(state)) state_local_str = strdup(state->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);
    if (user_id && !cJSON_IsNull(user_id)) user_id_local_str = strdup(user_id->valuestring);
    if (weekly_hours && !cJSON_IsNull(weekly_hours)) weekly_hours_local_str = strdup(weekly_hours->valuestring);
    if (zip && !cJSON_IsNull(zip)) zip_local_str = strdup(zip->valuestring);

    employee_local_var = employee_create_internal (
        address_local_str,
        backup_employee_id_local_str,
        bic_local_str,
        city_local_str,
        country ? country_local_nonprim : NULL,
        created_at_local_str,
        date_of_birth_local_str,
        deleted_at_local_str,
        department_id_local_str,
        email_local_str,
        first_name_local_str,
        gender ? gender_local_nonprim : NULL,
        hire_date_local_str,
        hourly_cost_local_str,
        iban_local_str,
        id_local_str,
        job_title_local_str,
        last_login_local_str,
        last_name_local_str,
        last_updated_local_str,
        monthly_salary_local_str,
        phone_local_str,
        state_local_str,
        status ? status_local_nonprim : 0,
        tenant_id_local_str,
        updated_at_local_str,
        user_id_local_str,
        weekly_hours_local_str,
        zip_local_str
        );

    if (!employee_local_var) {
        goto end;
    }

    return employee_local_var;
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
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (date_of_birth_local_str) {
        free(date_of_birth_local_str);
        date_of_birth_local_str = NULL;
    }
    if (deleted_at_local_str) {
        free(deleted_at_local_str);
        deleted_at_local_str = NULL;
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
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
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
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
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
