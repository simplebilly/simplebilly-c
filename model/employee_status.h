/*
 * employee_status.h
 *
 * Employment status.
 */

#ifndef _employee_status_H_
#define _employee_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct employee_status_t employee_status_t;


// Enum  for employee_status

typedef enum { simplebilly_api_employee_status__NULL = 0, simplebilly_api_employee_status__active, simplebilly_api_employee_status__inactive, simplebilly_api_employee_status__terminated } simplebilly_api_employee_status__e;

char* employee_status_employee_status_ToString(simplebilly_api_employee_status__e employee_status);

simplebilly_api_employee_status__e employee_status_employee_status_FromString(char* employee_status);

cJSON *employee_status_convertToJSON(simplebilly_api_employee_status__e employee_status);

simplebilly_api_employee_status__e employee_status_parseFromJSON(cJSON *employee_statusJSON);

#endif /* _employee_status_H_ */

