/*
 * job_posting_status.h
 *
 * Job posting status.
 */

#ifndef _job_posting_status_H_
#define _job_posting_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct job_posting_status_t job_posting_status_t;


// Enum  for job_posting_status

typedef enum { simplebilly_api_job_posting_status__NULL = 0, simplebilly_api_job_posting_status__draft, simplebilly_api_job_posting_status__published, simplebilly_api_job_posting_status__closed } simplebilly_api_job_posting_status__e;

char* job_posting_status_job_posting_status_ToString(simplebilly_api_job_posting_status__e job_posting_status);

simplebilly_api_job_posting_status__e job_posting_status_job_posting_status_FromString(char* job_posting_status);

cJSON *job_posting_status_convertToJSON(simplebilly_api_job_posting_status__e job_posting_status);

simplebilly_api_job_posting_status__e job_posting_status_parseFromJSON(cJSON *job_posting_statusJSON);

#endif /* _job_posting_status_H_ */

