/*
 * plan.h
 *
 * One canonical plan. &#x60;price_eur &#x3D;&#x3D; -1.0&#x60; means custom pricing.
 */

#ifndef _plan_H_
#define _plan_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plan_t plan_t;

#include "plan_features.h"
#include "plan_limits.h"



typedef struct plan_t {
    struct plan_features_t *features; //model
    char *id; // string
    struct plan_limits_t *limits; //model
    char *name; // string
    double *price_eur; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} plan_t;

__attribute__((deprecated)) plan_t *plan_create(
    plan_features_t *features,
    char *id,
    plan_limits_t *limits,
    char *name,
    double *price_eur
);

void plan_free(plan_t *plan);

plan_t *plan_parseFromJSON(cJSON *planJSON);

cJSON *plan_convertToJSON(plan_t *plan);

#endif /* _plan_H_ */

