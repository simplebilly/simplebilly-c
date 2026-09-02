/*
 * budget_goal_request.h
 *
 * 
 */

#ifndef _budget_goal_request_H_
#define _budget_goal_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct budget_goal_request_t budget_goal_request_t;




typedef struct budget_goal_request_t {
    char *monthly_goal; // string
    int *year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} budget_goal_request_t;

__attribute__((deprecated)) budget_goal_request_t *budget_goal_request_create(
    char *monthly_goal,
    int *year
);

void budget_goal_request_free(budget_goal_request_t *budget_goal_request);

budget_goal_request_t *budget_goal_request_parseFromJSON(cJSON *budget_goal_requestJSON);

cJSON *budget_goal_request_convertToJSON(budget_goal_request_t *budget_goal_request);

#endif /* _budget_goal_request_H_ */

