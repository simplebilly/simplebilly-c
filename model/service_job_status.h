/*
 * service_job_status.h
 *
 * Service job dispatch status.
 */

#ifndef _service_job_status_H_
#define _service_job_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct service_job_status_t service_job_status_t;


// Enum  for service_job_status

typedef enum { simplebilly_api_service_job_status__NULL = 0, simplebilly_api_service_job_status__pending, simplebilly_api_service_job_status__assigned, simplebilly_api_service_job_status__en_route, simplebilly_api_service_job_status__in_progress, simplebilly_api_service_job_status__completed, simplebilly_api_service_job_status__cancelled } simplebilly_api_service_job_status__e;

char* service_job_status_service_job_status_ToString(simplebilly_api_service_job_status__e service_job_status);

simplebilly_api_service_job_status__e service_job_status_service_job_status_FromString(char* service_job_status);

cJSON *service_job_status_convertToJSON(simplebilly_api_service_job_status__e service_job_status);

simplebilly_api_service_job_status__e service_job_status_parseFromJSON(cJSON *service_job_statusJSON);

#endif /* _service_job_status_H_ */

