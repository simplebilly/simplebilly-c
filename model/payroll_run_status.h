/*
 * payroll_run_status.h
 *
 * 
 */

#ifndef _payroll_run_status_H_
#define _payroll_run_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payroll_run_status_t payroll_run_status_t;


// Enum  for payroll_run_status

typedef enum { simplebilly_api_payroll_run_status__NULL = 0, simplebilly_api_payroll_run_status__draft, simplebilly_api_payroll_run_status__calculated, simplebilly_api_payroll_run_status__approved, simplebilly_api_payroll_run_status__paid } simplebilly_api_payroll_run_status__e;

char* payroll_run_status_payroll_run_status_ToString(simplebilly_api_payroll_run_status__e payroll_run_status);

simplebilly_api_payroll_run_status__e payroll_run_status_payroll_run_status_FromString(char* payroll_run_status);

cJSON *payroll_run_status_convertToJSON(simplebilly_api_payroll_run_status__e payroll_run_status);

simplebilly_api_payroll_run_status__e payroll_run_status_parseFromJSON(cJSON *payroll_run_statusJSON);

#endif /* _payroll_run_status_H_ */

