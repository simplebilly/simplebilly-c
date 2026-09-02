/*
 * submit_result_response.h
 *
 * 
 */

#ifndef _submit_result_response_H_
#define _submit_result_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct submit_result_response_t submit_result_response_t;




typedef struct submit_result_response_t {
    char *certificate_id; // string
    char *completion_id; // string
    int *pass_score; //numeric
    int *passed; //boolean
    int *score; //numeric
    char *valid_until; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} submit_result_response_t;

__attribute__((deprecated)) submit_result_response_t *submit_result_response_create(
    char *certificate_id,
    char *completion_id,
    int *pass_score,
    int *passed,
    int *score,
    char *valid_until
);

void submit_result_response_free(submit_result_response_t *submit_result_response);

submit_result_response_t *submit_result_response_parseFromJSON(cJSON *submit_result_responseJSON);

cJSON *submit_result_response_convertToJSON(submit_result_response_t *submit_result_response);

#endif /* _submit_result_response_H_ */

