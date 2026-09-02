/*
 * payroll_summary_item.h
 *
 * 
 */

#ifndef _payroll_summary_item_H_
#define _payroll_summary_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payroll_summary_item_t payroll_summary_item_t;

#include "payroll_run_status.h"



typedef struct payroll_summary_item_t {
    int *employee_count; //numeric
    char *month; // string
    simplebilly_api_payroll_run_status__e status; //referenced enum
    char *total_employer_cost; // string
    char *total_gross; // string
    char *total_net; // string
    int *year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} payroll_summary_item_t;

__attribute__((deprecated)) payroll_summary_item_t *payroll_summary_item_create(
    int *employee_count,
    char *month,
    simplebilly_api_payroll_run_status__e status,
    char *total_employer_cost,
    char *total_gross,
    char *total_net,
    int *year
);

void payroll_summary_item_free(payroll_summary_item_t *payroll_summary_item);

payroll_summary_item_t *payroll_summary_item_parseFromJSON(cJSON *payroll_summary_itemJSON);

cJSON *payroll_summary_item_convertToJSON(payroll_summary_item_t *payroll_summary_item);

#endif /* _payroll_summary_item_H_ */

