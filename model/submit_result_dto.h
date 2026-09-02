/*
 * submit_result_dto.h
 *
 * 
 */

#ifndef _submit_result_dto_H_
#define _submit_result_dto_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct submit_result_dto_t submit_result_dto_t;




typedef struct submit_result_dto_t {
    list_t *answers; //primitive container
    char *assignment_id; // string
    int *score; //numeric
    char *training_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} submit_result_dto_t;

__attribute__((deprecated)) submit_result_dto_t *submit_result_dto_create(
    list_t *answers,
    char *assignment_id,
    int *score,
    char *training_code
);

void submit_result_dto_free(submit_result_dto_t *submit_result_dto);

submit_result_dto_t *submit_result_dto_parseFromJSON(cJSON *submit_result_dtoJSON);

cJSON *submit_result_dto_convertToJSON(submit_result_dto_t *submit_result_dto);

#endif /* _submit_result_dto_H_ */

