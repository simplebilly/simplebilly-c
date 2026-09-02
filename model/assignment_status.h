/*
 * assignment_status.h
 *
 * 
 */

#ifndef _assignment_status_H_
#define _assignment_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assignment_status_t assignment_status_t;


// Enum  for assignment_status

typedef enum { simplebilly_api_assignment_status__NULL = 0, simplebilly_api_assignment_status__required, simplebilly_api_assignment_status__completed, simplebilly_api_assignment_status__overdue, simplebilly_api_assignment_status__waived } simplebilly_api_assignment_status__e;

char* assignment_status_assignment_status_ToString(simplebilly_api_assignment_status__e assignment_status);

simplebilly_api_assignment_status__e assignment_status_assignment_status_FromString(char* assignment_status);

cJSON *assignment_status_convertToJSON(simplebilly_api_assignment_status__e assignment_status);

simplebilly_api_assignment_status__e assignment_status_parseFromJSON(cJSON *assignment_statusJSON);

#endif /* _assignment_status_H_ */

