/*
 * severity.h
 *
 * 
 */

#ifndef _severity_H_
#define _severity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct severity_t severity_t;


// Enum  for severity

typedef enum { simplebilly_api_severity__NULL = 0, simplebilly_api_severity__Info, simplebilly_api_severity__Warning, simplebilly_api_severity__Critical } simplebilly_api_severity__e;

char* severity_severity_ToString(simplebilly_api_severity__e severity);

simplebilly_api_severity__e severity_severity_FromString(char* severity);

cJSON *severity_convertToJSON(simplebilly_api_severity__e severity);

simplebilly_api_severity__e severity_parseFromJSON(cJSON *severityJSON);

#endif /* _severity_H_ */

