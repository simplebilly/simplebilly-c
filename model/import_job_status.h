/*
 * import_job_status.h
 *
 * 
 */

#ifndef _import_job_status_H_
#define _import_job_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct import_job_status_t import_job_status_t;




typedef struct import_job_status_t {
    char *error; // string
    char *job_id; // string
    long *processed; //numeric
    int *progress; //numeric
    char *provider; // string
    char *stage; // string
    char *status; // string
    long *total; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} import_job_status_t;

__attribute__((deprecated)) import_job_status_t *import_job_status_create(
    char *error,
    char *job_id,
    long *processed,
    int *progress,
    char *provider,
    char *stage,
    char *status,
    long *total
);

void import_job_status_free(import_job_status_t *import_job_status);

import_job_status_t *import_job_status_parseFromJSON(cJSON *import_job_statusJSON);

cJSON *import_job_status_convertToJSON(import_job_status_t *import_job_status);

#endif /* _import_job_status_H_ */

