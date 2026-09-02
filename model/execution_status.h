/*
 * execution_status.h
 *
 * Recurring template execution status.
 */

#ifndef _execution_status_H_
#define _execution_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct execution_status_t execution_status_t;


// Enum  for execution_status

typedef enum { simplebilly_api_execution_status__NULL = 0, simplebilly_api_execution_status__ACTIVE, simplebilly_api_execution_status__PAUSED, simplebilly_api_execution_status__COMPLETED } simplebilly_api_execution_status__e;

char* execution_status_execution_status_ToString(simplebilly_api_execution_status__e execution_status);

simplebilly_api_execution_status__e execution_status_execution_status_FromString(char* execution_status);

cJSON *execution_status_convertToJSON(simplebilly_api_execution_status__e execution_status);

simplebilly_api_execution_status__e execution_status_parseFromJSON(cJSON *execution_statusJSON);

#endif /* _execution_status_H_ */

