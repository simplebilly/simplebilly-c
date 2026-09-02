/*
 * absence_status.h
 *
 * Absence request status.
 */

#ifndef _absence_status_H_
#define _absence_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct absence_status_t absence_status_t;


// Enum  for absence_status

typedef enum { simplebilly_api_absence_status__NULL = 0, simplebilly_api_absence_status__pending, simplebilly_api_absence_status__approved, simplebilly_api_absence_status__rejected, simplebilly_api_absence_status__cancelled } simplebilly_api_absence_status__e;

char* absence_status_absence_status_ToString(simplebilly_api_absence_status__e absence_status);

simplebilly_api_absence_status__e absence_status_absence_status_FromString(char* absence_status);

cJSON *absence_status_convertToJSON(simplebilly_api_absence_status__e absence_status);

simplebilly_api_absence_status__e absence_status_parseFromJSON(cJSON *absence_statusJSON);

#endif /* _absence_status_H_ */

