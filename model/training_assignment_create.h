/*
 * training_assignment_create.h
 *
 * 
 */

#ifndef _training_assignment_create_H_
#define _training_assignment_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct training_assignment_create_t training_assignment_create_t;

#include "assignment_status.h"



typedef struct training_assignment_create_t {
    char *assigned_by; // string
    char *due_date; //date
    char *employee_id; // string
    char *notes; // string
    simplebilly_api_assignment_status__e status; //referenced enum
    char *training_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} training_assignment_create_t;

__attribute__((deprecated)) training_assignment_create_t *training_assignment_create_create(
    char *assigned_by,
    char *due_date,
    char *employee_id,
    char *notes,
    simplebilly_api_assignment_status__e status,
    char *training_id
);

void training_assignment_create_free(training_assignment_create_t *training_assignment_create);

training_assignment_create_t *training_assignment_create_parseFromJSON(cJSON *training_assignment_createJSON);

cJSON *training_assignment_create_convertToJSON(training_assignment_create_t *training_assignment_create);

#endif /* _training_assignment_create_H_ */

