/*
 * job.h
 *
 * 
 */

#ifndef _job_H_
#define _job_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct job_t job_t;

#include "any_type.h"
#include "job_status.h"



typedef struct job_t {
    int *attempts; //numeric
    char *job_type; // string
    int *max_attempts; //numeric
    any_type_t *payload; // custom
    char *run_at; //date time
    job_status_t *status; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} job_t;

__attribute__((deprecated)) job_t *job_create(
    int *attempts,
    char *job_type,
    int *max_attempts,
    any_type_t *payload,
    char *run_at,
    job_status_t *status
);

void job_free(job_t *job);

job_t *job_parseFromJSON(cJSON *jobJSON);

cJSON *job_convertToJSON(job_t *job);

#endif /* _job_H_ */

