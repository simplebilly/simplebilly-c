/*
 * employee_update.h
 *
 * 
 */

#ifndef _employee_update_H_
#define _employee_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct employee_update_t employee_update_t;

#include "country_code.h"
#include "employee_status.h"
#include "gender.h"



typedef struct employee_update_t {
    char *address; // string
    char *backup_employee_id; // string
    char *bic; // string
    char *city; // string
    country_code_t *country; // custom
    char *date_of_birth; //date
    char *department_id; // string
    char *email; // string
    char *first_name; // string
    gender_t *gender; // custom
    char *hire_date; //date
    char *hourly_cost; // string
    char *iban; // string
    char *job_title; // string
    char *last_login; //date time
    char *last_name; // string
    char *last_updated; //date time
    char *monthly_salary; // string
    char *phone; // string
    char *state; // string
    employee_status_t *status; // custom
    char *user_id; // string
    char *weekly_hours; // string
    char *zip; // string

    int _library_owned; // Is the library responsible for freeing this object?
} employee_update_t;

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
);

void employee_update_free(employee_update_t *employee_update);

employee_update_t *employee_update_parseFromJSON(cJSON *employee_updateJSON);

cJSON *employee_update_convertToJSON(employee_update_t *employee_update);

#endif /* _employee_update_H_ */

