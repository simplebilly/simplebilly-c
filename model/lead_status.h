/*
 * lead_status.h
 *
 * Lead status.
 */

#ifndef _lead_status_H_
#define _lead_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lead_status_t lead_status_t;


// Enum  for lead_status

typedef enum { simplebilly_api_lead_status__NULL = 0, simplebilly_api_lead_status___new, simplebilly_api_lead_status__qualified } simplebilly_api_lead_status__e;

char* lead_status_lead_status_ToString(simplebilly_api_lead_status__e lead_status);

simplebilly_api_lead_status__e lead_status_lead_status_FromString(char* lead_status);

cJSON *lead_status_convertToJSON(simplebilly_api_lead_status__e lead_status);

simplebilly_api_lead_status__e lead_status_parseFromJSON(cJSON *lead_statusJSON);

#endif /* _lead_status_H_ */

