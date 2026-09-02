/*
 * activity_status.h
 *
 * Activity status.
 */

#ifndef _activity_status_H_
#define _activity_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_status_t activity_status_t;


// Enum  for activity_status

typedef enum { simplebilly_api_activity_status__NULL = 0, simplebilly_api_activity_status__open, simplebilly_api_activity_status__done, simplebilly_api_activity_status__cancelled } simplebilly_api_activity_status__e;

char* activity_status_activity_status_ToString(simplebilly_api_activity_status__e activity_status);

simplebilly_api_activity_status__e activity_status_activity_status_FromString(char* activity_status);

cJSON *activity_status_convertToJSON(simplebilly_api_activity_status__e activity_status);

simplebilly_api_activity_status__e activity_status_parseFromJSON(cJSON *activity_statusJSON);

#endif /* _activity_status_H_ */

