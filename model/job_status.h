/*
 * job_status.h
 *
 * Job queue status.
 */

#ifndef _job_status_H_
#define _job_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct job_status_t job_status_t;


// Enum  for job_status

typedef enum { simplebilly_api_job_status__NULL = 0, simplebilly_api_job_status__pending, simplebilly_api_job_status__running, simplebilly_api_job_status__done, simplebilly_api_job_status__failed } simplebilly_api_job_status__e;

char* job_status_job_status_ToString(simplebilly_api_job_status__e job_status);

simplebilly_api_job_status__e job_status_job_status_FromString(char* job_status);

cJSON *job_status_convertToJSON(simplebilly_api_job_status__e job_status);

simplebilly_api_job_status__e job_status_parseFromJSON(cJSON *job_statusJSON);

#endif /* _job_status_H_ */

