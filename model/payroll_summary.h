/*
 * payroll_summary.h
 *
 * 
 */

#ifndef _payroll_summary_H_
#define _payroll_summary_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payroll_summary_t payroll_summary_t;

#include "payroll_month.h"



typedef struct payroll_summary_t {
    char *first_name; // string
    char *hourly_gross; // string
    char *id; // string
    char *job_title; // string
    char *last_name; // string
    char *monthly_salary; // string
    list_t *months; //nonprimitive container
    char *weekly_hours; // string
    int *year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} payroll_summary_t;

__attribute__((deprecated)) payroll_summary_t *payroll_summary_create(
    char *first_name,
    char *hourly_gross,
    char *id,
    char *job_title,
    char *last_name,
    char *monthly_salary,
    list_t *months,
    char *weekly_hours,
    int *year
);

void payroll_summary_free(payroll_summary_t *payroll_summary);

payroll_summary_t *payroll_summary_parseFromJSON(cJSON *payroll_summaryJSON);

cJSON *payroll_summary_convertToJSON(payroll_summary_t *payroll_summary);

#endif /* _payroll_summary_H_ */

