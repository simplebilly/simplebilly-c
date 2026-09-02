/*
 * payroll_month.h
 *
 * 
 */

#ifndef _payroll_month_H_
#define _payroll_month_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payroll_month_t payroll_month_t;




typedef struct payroll_month_t {
    char *gross; // string
    int *month; //numeric
    char *net; // string

    int _library_owned; // Is the library responsible for freeing this object?
} payroll_month_t;

__attribute__((deprecated)) payroll_month_t *payroll_month_create(
    char *gross,
    int *month,
    char *net
);

void payroll_month_free(payroll_month_t *payroll_month);

payroll_month_t *payroll_month_parseFromJSON(cJSON *payroll_monthJSON);

cJSON *payroll_month_convertToJSON(payroll_month_t *payroll_month);

#endif /* _payroll_month_H_ */

