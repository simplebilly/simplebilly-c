/*
 * job_posting_update.h
 *
 * 
 */

#ifndef _job_posting_update_H_
#define _job_posting_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct job_posting_update_t job_posting_update_t;

#include "any_type.h"
#include "employment_type.h"
#include "job_posting_status.h"



typedef struct job_posting_update_t {
    char *currency; // string
    char *department; // string
    char *description; // string
    employment_type_t *employment_type; // custom
    char *location; // string
    int *remote; //boolean
    any_type_t *required_skills; // custom
    char *requirements; // string
    int *salary_max; //numeric
    int *salary_min; //numeric
    job_posting_status_t *status; // custom
    char *title; // string

    int _library_owned; // Is the library responsible for freeing this object?
} job_posting_update_t;

__attribute__((deprecated)) job_posting_update_t *job_posting_update_create(
    char *currency,
    char *department,
    char *description,
    employment_type_t *employment_type,
    char *location,
    int *remote,
    any_type_t *required_skills,
    char *requirements,
    int *salary_max,
    int *salary_min,
    job_posting_status_t *status,
    char *title
);

void job_posting_update_free(job_posting_update_t *job_posting_update);

job_posting_update_t *job_posting_update_parseFromJSON(cJSON *job_posting_updateJSON);

cJSON *job_posting_update_convertToJSON(job_posting_update_t *job_posting_update);

#endif /* _job_posting_update_H_ */

