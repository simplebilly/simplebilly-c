/*
 * cashflow_report.h
 *
 * 
 */

#ifndef _cashflow_report_H_
#define _cashflow_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cashflow_report_t cashflow_report_t;




typedef struct cashflow_report_t {
    double *closing_balance; //numeric
    double *financing_cashflow; //numeric
    double *investing_cashflow; //numeric
    double *net_cashflow; //numeric
    double *opening_balance; //numeric
    double *operating_cashflow; //numeric
    char *period; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cashflow_report_t;

__attribute__((deprecated)) cashflow_report_t *cashflow_report_create(
    double *closing_balance,
    double *financing_cashflow,
    double *investing_cashflow,
    double *net_cashflow,
    double *opening_balance,
    double *operating_cashflow,
    char *period
);

void cashflow_report_free(cashflow_report_t *cashflow_report);

cashflow_report_t *cashflow_report_parseFromJSON(cJSON *cashflow_reportJSON);

cJSON *cashflow_report_convertToJSON(cashflow_report_t *cashflow_report);

#endif /* _cashflow_report_H_ */

