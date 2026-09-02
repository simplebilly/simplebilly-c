/*
 * pay_gap_report.h
 *
 * 
 */

#ifndef _pay_gap_report_H_
#define _pay_gap_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pay_gap_report_t pay_gap_report_t;

#include "job_title_gap.h"
#include "quartile_band.h"



typedef struct pay_gap_report_t {
    list_t *by_job_title; //nonprimitive container
    int *diverse_count; //numeric
    int *employee_count; //numeric
    int *female_count; //numeric
    int *male_count; //numeric
    double *mean_gap_pct; //numeric
    double *median_gap_pct; //numeric
    list_t *quartiles; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} pay_gap_report_t;

__attribute__((deprecated)) pay_gap_report_t *pay_gap_report_create(
    list_t *by_job_title,
    int *diverse_count,
    int *employee_count,
    int *female_count,
    int *male_count,
    double *mean_gap_pct,
    double *median_gap_pct,
    list_t *quartiles
);

void pay_gap_report_free(pay_gap_report_t *pay_gap_report);

pay_gap_report_t *pay_gap_report_parseFromJSON(cJSON *pay_gap_reportJSON);

cJSON *pay_gap_report_convertToJSON(pay_gap_report_t *pay_gap_report);

#endif /* _pay_gap_report_H_ */

