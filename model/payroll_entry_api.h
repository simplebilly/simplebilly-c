/*
 * payroll_entry_api.h
 *
 * 
 */

#ifndef _payroll_entry_api_H_
#define _payroll_entry_api_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payroll_entry_api_t payroll_entry_api_t;

#include "employee.h"
#include "payroll_run_status.h"



typedef struct payroll_entry_api_t {
    char *av_employee; // string
    char *av_employer; // string
    char *church_tax_amount; // string
    struct employee_t *employee; //model
    char *employee_id; // string
    char *entry_id; // string
    char *extra_payment_reason; // string
    char *extra_payments; // string
    char *gross_salary; // string
    char *kv_employee; // string
    char *kv_employer; // string
    char *lohnsteuer; // string
    char *net_salary; // string
    char *notes; // string
    char *pv_employee; // string
    char *pv_employer; // string
    char *run_id; // string
    char *rv_employee; // string
    char *rv_employer; // string
    int *sick_days; //numeric
    char *soli; // string
    simplebilly_api_payroll_run_status__e status; //referenced enum
    char *total_deductions; // string
    char *total_employer_cost; // string
    int *vacation_days_used; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} payroll_entry_api_t;

__attribute__((deprecated)) payroll_entry_api_t *payroll_entry_api_create(
    char *av_employee,
    char *av_employer,
    char *church_tax_amount,
    employee_t *employee,
    char *employee_id,
    char *entry_id,
    char *extra_payment_reason,
    char *extra_payments,
    char *gross_salary,
    char *kv_employee,
    char *kv_employer,
    char *lohnsteuer,
    char *net_salary,
    char *notes,
    char *pv_employee,
    char *pv_employer,
    char *run_id,
    char *rv_employee,
    char *rv_employer,
    int *sick_days,
    char *soli,
    simplebilly_api_payroll_run_status__e status,
    char *total_deductions,
    char *total_employer_cost,
    int *vacation_days_used
);

void payroll_entry_api_free(payroll_entry_api_t *payroll_entry_api);

payroll_entry_api_t *payroll_entry_api_parseFromJSON(cJSON *payroll_entry_apiJSON);

cJSON *payroll_entry_api_convertToJSON(payroll_entry_api_t *payroll_entry_api);

#endif /* _payroll_entry_api_H_ */

