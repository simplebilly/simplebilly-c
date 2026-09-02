/*
 * pay_gap_info_response.h
 *
 * 
 */

#ifndef _pay_gap_info_response_H_
#define _pay_gap_info_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pay_gap_info_response_t pay_gap_info_response_t;




typedef struct pay_gap_info_response_t {
    char *employee_id; // string
    char *first_name; // string
    char *gender; // string
    double *group_median_hourly; //numeric
    double *group_median_monthly; //numeric
    int *group_size; //numeric
    char *job_title; // string
    char *last_name; // string
    double *overall_median_hourly; //numeric
    double *own_hourly_gross; //numeric
    double *own_monthly_gross; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} pay_gap_info_response_t;

__attribute__((deprecated)) pay_gap_info_response_t *pay_gap_info_response_create(
    char *employee_id,
    char *first_name,
    char *gender,
    double *group_median_hourly,
    double *group_median_monthly,
    int *group_size,
    char *job_title,
    char *last_name,
    double *overall_median_hourly,
    double *own_hourly_gross,
    double *own_monthly_gross
);

void pay_gap_info_response_free(pay_gap_info_response_t *pay_gap_info_response);

pay_gap_info_response_t *pay_gap_info_response_parseFromJSON(cJSON *pay_gap_info_responseJSON);

cJSON *pay_gap_info_response_convertToJSON(pay_gap_info_response_t *pay_gap_info_response);

#endif /* _pay_gap_info_response_H_ */

