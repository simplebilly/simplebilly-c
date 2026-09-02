/*
 * training_assignment_update.h
 *
 * 
 */

#ifndef _training_assignment_update_H_
#define _training_assignment_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct training_assignment_update_t training_assignment_update_t;

#include "assignment_status.h"



typedef struct training_assignment_update_t {
    char *assigned_by; // string
    char *due_date; //date
    char *employee_id; // string
    char *notes; // string
    assignment_status_t *status; // custom
    char *training_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} training_assignment_update_t;

__attribute__((deprecated)) training_assignment_update_t *training_assignment_update_create(
    char *assigned_by,
    char *due_date,
    char *employee_id,
    char *notes,
    assignment_status_t *status,
    char *training_id
);

void training_assignment_update_free(training_assignment_update_t *training_assignment_update);

training_assignment_update_t *training_assignment_update_parseFromJSON(cJSON *training_assignment_updateJSON);

cJSON *training_assignment_update_convertToJSON(training_assignment_update_t *training_assignment_update);

#endif /* _training_assignment_update_H_ */

