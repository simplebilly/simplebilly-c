/*
 * payroll_run_api.h
 *
 * 
 */

#ifndef _payroll_run_api_H_
#define _payroll_run_api_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payroll_run_api_t payroll_run_api_t;

#include "payroll_entry_api.h"
#include "payroll_run_status.h"



typedef struct payroll_run_api_t {
    char *approved_at; //date time
    char *approved_by; // string
    char *created_at; //date time
    list_t *entries; //nonprimitive container
    int *month; //numeric
    char *payment_date; //date
    char *period_label; // string
    char *run_id; // string
    simplebilly_api_payroll_run_status__e status; //referenced enum
    char *tenant_id; // string
    int *total_employee_count; //numeric
    char *total_employer_cost; // string
    char *total_gross; // string
    char *total_net; // string
    char *total_social_security; // string
    char *total_taxes; // string
    char *updated_at; //date time
    int *year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} payroll_run_api_t;

__attribute__((deprecated)) payroll_run_api_t *payroll_run_api_create(
    char *approved_at,
    char *approved_by,
    char *created_at,
    list_t *entries,
    int *month,
    char *payment_date,
    char *period_label,
    char *run_id,
    simplebilly_api_payroll_run_status__e status,
    char *tenant_id,
    int *total_employee_count,
    char *total_employer_cost,
    char *total_gross,
    char *total_net,
    char *total_social_security,
    char *total_taxes,
    char *updated_at,
    int *year
);

void payroll_run_api_free(payroll_run_api_t *payroll_run_api);

payroll_run_api_t *payroll_run_api_parseFromJSON(cJSON *payroll_run_apiJSON);

cJSON *payroll_run_api_convertToJSON(payroll_run_api_t *payroll_run_api);

#endif /* _payroll_run_api_H_ */

