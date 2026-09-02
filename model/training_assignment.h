/*
 * training_assignment.h
 *
 * 
 */

#ifndef _training_assignment_H_
#define _training_assignment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct training_assignment_t training_assignment_t;

#include "assignment_status.h"



typedef struct training_assignment_t {
    char *assigned_by; // string
    char *created_at; //date time
    char *deleted_at; //date time
    char *due_date; //date
    char *employee_id; // string
    char *id; // string
    char *notes; // string
    simplebilly_api_assignment_status__e status; //referenced enum
    char *tenant_id; // string
    char *training_id; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} training_assignment_t;

__attribute__((deprecated)) training_assignment_t *training_assignment_create(
    char *assigned_by,
    char *created_at,
    char *deleted_at,
    char *due_date,
    char *employee_id,
    char *id,
    char *notes,
    simplebilly_api_assignment_status__e status,
    char *tenant_id,
    char *training_id,
    char *updated_at
);

void training_assignment_free(training_assignment_t *training_assignment);

training_assignment_t *training_assignment_parseFromJSON(cJSON *training_assignmentJSON);

cJSON *training_assignment_convertToJSON(training_assignment_t *training_assignment);

#endif /* _training_assignment_H_ */

