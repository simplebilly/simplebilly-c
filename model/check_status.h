/*
 * check_status.h
 *
 * 
 */

#ifndef _check_status_H_
#define _check_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct check_status_t check_status_t;


// Enum  for check_status

typedef enum { simplebilly_api_check_status__NULL = 0, simplebilly_api_check_status__Ok, simplebilly_api_check_status__Warning, simplebilly_api_check_status__Error } simplebilly_api_check_status__e;

char* check_status_check_status_ToString(simplebilly_api_check_status__e check_status);

simplebilly_api_check_status__e check_status_check_status_FromString(char* check_status);

cJSON *check_status_convertToJSON(simplebilly_api_check_status__e check_status);

simplebilly_api_check_status__e check_status_parseFromJSON(cJSON *check_statusJSON);

#endif /* _check_status_H_ */

