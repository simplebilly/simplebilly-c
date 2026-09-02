/*
 * quota_override_features.h
 *
 * 
 */

#ifndef _quota_override_features_H_
#define _quota_override_features_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct quota_override_features_t quota_override_features_t;




typedef struct quota_override_features_t {
    int *erp; //boolean
    int *fancy_reports; //boolean
    int *tax_automations; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} quota_override_features_t;

__attribute__((deprecated)) quota_override_features_t *quota_override_features_create(
    int *erp,
    int *fancy_reports,
    int *tax_automations
);

void quota_override_features_free(quota_override_features_t *quota_override_features);

quota_override_features_t *quota_override_features_parseFromJSON(cJSON *quota_override_featuresJSON);

cJSON *quota_override_features_convertToJSON(quota_override_features_t *quota_override_features);

#endif /* _quota_override_features_H_ */

