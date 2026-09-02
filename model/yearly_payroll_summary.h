/*
 * yearly_payroll_summary.h
 *
 * 
 */

#ifndef _yearly_payroll_summary_H_
#define _yearly_payroll_summary_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct yearly_payroll_summary_t yearly_payroll_summary_t;

#include "payroll_summary_item.h"



typedef struct yearly_payroll_summary_t {
    int *avg_employee_count; //numeric
    list_t *months; //nonprimitive container
    int *year; //numeric
    char *yearly_employer_cost; // string
    char *yearly_gross; // string
    char *yearly_net; // string

    int _library_owned; // Is the library responsible for freeing this object?
} yearly_payroll_summary_t;

__attribute__((deprecated)) yearly_payroll_summary_t *yearly_payroll_summary_create(
    int *avg_employee_count,
    list_t *months,
    int *year,
    char *yearly_employer_cost,
    char *yearly_gross,
    char *yearly_net
);

void yearly_payroll_summary_free(yearly_payroll_summary_t *yearly_payroll_summary);

yearly_payroll_summary_t *yearly_payroll_summary_parseFromJSON(cJSON *yearly_payroll_summaryJSON);

cJSON *yearly_payroll_summary_convertToJSON(yearly_payroll_summary_t *yearly_payroll_summary);

#endif /* _yearly_payroll_summary_H_ */

