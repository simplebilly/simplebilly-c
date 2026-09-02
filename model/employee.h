/*
 * employee.h
 *
 * 
 */

#ifndef _employee_H_
#define _employee_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct employee_t employee_t;

#include "country_code.h"
#include "employee_status.h"
#include "gender.h"



typedef struct employee_t {
    char *address; // string
    char *backup_employee_id; // string
    char *bic; // string
    char *city; // string
    country_code_t *country; // custom
    char *created_at; //date time
    char *date_of_birth; //date
    char *deleted_at; //date time
    char *department_id; // string
    char *email; // string
    char *first_name; // string
    gender_t *gender; // custom
    char *hire_date; //date
    char *hourly_cost; // string
    char *iban; // string
    char *id; // string
    char *job_title; // string
    char *last_login; //date time
    char *last_name; // string
    char *last_updated; //date time
    char *monthly_salary; // string
    char *phone; // string
    char *state; // string
    simplebilly_api_employee_status__e status; //referenced enum
    char *tenant_id; // string
    char *updated_at; //date time
    char *user_id; // string
    char *weekly_hours; // string
    char *zip; // string

    int _library_owned; // Is the library responsible for freeing this object?
} employee_t;

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
);

void employee_free(employee_t *employee);

employee_t *employee_parseFromJSON(cJSON *employeeJSON);

cJSON *employee_convertToJSON(employee_t *employee);

#endif /* _employee_H_ */

