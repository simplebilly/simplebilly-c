/*
 * api_response_vec_plan.h
 *
 * 
 */

#ifndef _api_response_vec_plan_H_
#define _api_response_vec_plan_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_response_vec_plan_t api_response_vec_plan_t;

#include "api_response_vec_plan_data_inner.h"



typedef struct api_response_vec_plan_t {
    list_t *data; //nonprimitive container
    char *error; // string
    char *message; // string
    int *success; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} api_response_vec_plan_t;

__attribute__((deprecated)) api_response_vec_plan_t *api_response_vec_plan_create(
    list_t *data,
    char *error,
    char *message,
    int *success
);

void api_response_vec_plan_free(api_response_vec_plan_t *api_response_vec_plan);

api_response_vec_plan_t *api_response_vec_plan_parseFromJSON(cJSON *api_response_vec_planJSON);

cJSON *api_response_vec_plan_convertToJSON(api_response_vec_plan_t *api_response_vec_plan);

#endif /* _api_response_vec_plan_H_ */

