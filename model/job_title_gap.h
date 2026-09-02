/*
 * job_title_gap.h
 *
 * 
 */

#ifndef _job_title_gap_H_
#define _job_title_gap_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct job_title_gap_t job_title_gap_t;




typedef struct job_title_gap_t {
    int *employee_count; //numeric
    char *female_mean_hourly; // string
    char *job_title; // string
    char *male_mean_hourly; // string
    double *mean_gap_pct; //numeric
    double *median_gap_pct; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} job_title_gap_t;

__attribute__((deprecated)) job_title_gap_t *job_title_gap_create(
    int *employee_count,
    char *female_mean_hourly,
    char *job_title,
    char *male_mean_hourly,
    double *mean_gap_pct,
    double *median_gap_pct
);

void job_title_gap_free(job_title_gap_t *job_title_gap);

job_title_gap_t *job_title_gap_parseFromJSON(cJSON *job_title_gapJSON);

cJSON *job_title_gap_convertToJSON(job_title_gap_t *job_title_gap);

#endif /* _job_title_gap_H_ */

