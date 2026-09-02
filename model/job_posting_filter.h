/*
 * job_posting_filter.h
 *
 * 
 */

#ifndef _job_posting_filter_H_
#define _job_posting_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct job_posting_filter_t job_posting_filter_t;




typedef struct job_posting_filter_t {
    int *page; //numeric
    int *page_size; //numeric
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} job_posting_filter_t;

__attribute__((deprecated)) job_posting_filter_t *job_posting_filter_create(
    int *page,
    int *page_size,
    char *status
);

void job_posting_filter_free(job_posting_filter_t *job_posting_filter);

job_posting_filter_t *job_posting_filter_parseFromJSON(cJSON *job_posting_filterJSON);

cJSON *job_posting_filter_convertToJSON(job_posting_filter_t *job_posting_filter);

#endif /* _job_posting_filter_H_ */

