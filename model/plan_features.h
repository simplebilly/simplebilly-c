/*
 * plan_features.h
 *
 * Feature flags per plan.
 */

#ifndef _plan_features_H_
#define _plan_features_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plan_features_t plan_features_t;




typedef struct plan_features_t {
    int *connectors; //boolean
    int *erp; //boolean
    int *fancy_reports; //boolean
    int *tax_automations; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} plan_features_t;

__attribute__((deprecated)) plan_features_t *plan_features_create(
    int *connectors,
    int *erp,
    int *fancy_reports,
    int *tax_automations
);

void plan_features_free(plan_features_t *plan_features);

plan_features_t *plan_features_parseFromJSON(cJSON *plan_featuresJSON);

cJSON *plan_features_convertToJSON(plan_features_t *plan_features);

#endif /* _plan_features_H_ */

