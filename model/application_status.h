/*
 * application_status.h
 *
 * Application status.
 */

#ifndef _application_status_H_
#define _application_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct application_status_t application_status_t;


// Enum  for application_status

typedef enum { simplebilly_api_application_status__NULL = 0, simplebilly_api_application_status___new, simplebilly_api_application_status__reviewing, simplebilly_api_application_status__interview, simplebilly_api_application_status__hired, simplebilly_api_application_status__rejected } simplebilly_api_application_status__e;

char* application_status_application_status_ToString(simplebilly_api_application_status__e application_status);

simplebilly_api_application_status__e application_status_application_status_FromString(char* application_status);

cJSON *application_status_convertToJSON(simplebilly_api_application_status__e application_status);

simplebilly_api_application_status__e application_status_parseFromJSON(cJSON *application_statusJSON);

#endif /* _application_status_H_ */

