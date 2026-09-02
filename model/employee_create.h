/*
 * employee_create.h
 *
 * 
 */

#ifndef _employee_create_H_
#define _employee_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct employee_create_t employee_create_t;

#include "country_code.h"
#include "employee_status.h"
#include "gender.h"



typedef struct employee_create_t {
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
    simplebilly_api_employee_status__e status; //referenced enum
    char *user_id; // string
    char *weekly_hours; // string
    char *zip; // string

    int _library_owned; // Is the library responsible for freeing this object?
} employee_create_t;

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
);

void employee_create_free(employee_create_t *employee_create);

employee_create_t *employee_create_parseFromJSON(cJSON *employee_createJSON);

cJSON *employee_create_convertToJSON(employee_create_t *employee_create);

#endif /* _employee_create_H_ */

