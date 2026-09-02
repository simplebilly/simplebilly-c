/*
 * service_assignment.h
 *
 * 
 */

#ifndef _service_assignment_H_
#define _service_assignment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct service_assignment_t service_assignment_t;

#include "service_assignment_status.h"



typedef struct service_assignment_t {
    char *employee_id; // string
    char *job_id; // string
    char *notes; // string
    char *scheduled_date; //date
    char *scheduled_end; // string
    char *scheduled_start; // string
    service_assignment_status_t *status; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} service_assignment_t;

__attribute__((deprecated)) service_assignment_t *service_assignment_create(
    char *employee_id,
    char *job_id,
    char *notes,
    char *scheduled_date,
    char *scheduled_end,
    char *scheduled_start,
    service_assignment_status_t *status
);

void service_assignment_free(service_assignment_t *service_assignment);

service_assignment_t *service_assignment_parseFromJSON(cJSON *service_assignmentJSON);

cJSON *service_assignment_convertToJSON(service_assignment_t *service_assignment);

#endif /* _service_assignment_H_ */

