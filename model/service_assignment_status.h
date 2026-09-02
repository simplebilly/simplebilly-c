/*
 * service_assignment_status.h
 *
 * Service assignment status.
 */

#ifndef _service_assignment_status_H_
#define _service_assignment_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct service_assignment_status_t service_assignment_status_t;


// Enum  for service_assignment_status

typedef enum { simplebilly_api_service_assignment_status__NULL = 0, simplebilly_api_service_assignment_status__planned, simplebilly_api_service_assignment_status__confirmed, simplebilly_api_service_assignment_status__en_route, simplebilly_api_service_assignment_status__in_progress, simplebilly_api_service_assignment_status__completed, simplebilly_api_service_assignment_status__cancelled } simplebilly_api_service_assignment_status__e;

char* service_assignment_status_service_assignment_status_ToString(simplebilly_api_service_assignment_status__e service_assignment_status);

simplebilly_api_service_assignment_status__e service_assignment_status_service_assignment_status_FromString(char* service_assignment_status);

cJSON *service_assignment_status_convertToJSON(simplebilly_api_service_assignment_status__e service_assignment_status);

simplebilly_api_service_assignment_status__e service_assignment_status_parseFromJSON(cJSON *service_assignment_statusJSON);

#endif /* _service_assignment_status_H_ */

