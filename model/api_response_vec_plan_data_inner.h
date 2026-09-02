/*
 * api_response_vec_plan_data_inner.h
 *
 * One canonical plan. &#x60;price_eur &#x3D;&#x3D; -1.0&#x60; means custom pricing.
 */

#ifndef _api_response_vec_plan_data_inner_H_
#define _api_response_vec_plan_data_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_response_vec_plan_data_inner_t api_response_vec_plan_data_inner_t;

#include "plan_features.h"
#include "plan_limits.h"



typedef struct api_response_vec_plan_data_inner_t {
    struct plan_features_t *features; //model
    char *id; // string
    struct plan_limits_t *limits; //model
    char *name; // string
    double *price_eur; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} api_response_vec_plan_data_inner_t;

__attribute__((deprecated)) api_response_vec_plan_data_inner_t *api_response_vec_plan_data_inner_create(
    plan_features_t *features,
    char *id,
    plan_limits_t *limits,
    char *name,
    double *price_eur
);

void api_response_vec_plan_data_inner_free(api_response_vec_plan_data_inner_t *api_response_vec_plan_data_inner);

api_response_vec_plan_data_inner_t *api_response_vec_plan_data_inner_parseFromJSON(cJSON *api_response_vec_plan_data_innerJSON);

cJSON *api_response_vec_plan_data_inner_convertToJSON(api_response_vec_plan_data_inner_t *api_response_vec_plan_data_inner);

#endif /* _api_response_vec_plan_data_inner_H_ */

