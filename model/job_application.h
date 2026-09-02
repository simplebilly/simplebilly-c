/*
 * job_application.h
 *
 * 
 */

#ifndef _job_application_H_
#define _job_application_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct job_application_t job_application_t;

#include "application_status.h"



typedef struct job_application_t {
    char *cv_file; // string
    char *cv_text; // string
    char *email; // string
    char *match_reason; // string
    int *match_score; //numeric
    char *name; // string
    char *phone; // string
    char *posting_id; // string
    char *source; // string
    application_status_t *status; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} job_application_t;

__attribute__((deprecated)) job_application_t *job_application_create(
    char *cv_file,
    char *cv_text,
    char *email,
    char *match_reason,
    int *match_score,
    char *name,
    char *phone,
    char *posting_id,
    char *source,
    application_status_t *status
);

void job_application_free(job_application_t *job_application);

job_application_t *job_application_parseFromJSON(cJSON *job_applicationJSON);

cJSON *job_application_convertToJSON(job_application_t *job_application);

#endif /* _job_application_H_ */

