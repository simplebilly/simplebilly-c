/*
 * quota_override.h
 *
 * Schema of the &#x60;tenants.quotas&#x60; JSON override column. Any field that is present overrides the plan-derived value.
 */

#ifndef _quota_override_H_
#define _quota_override_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct quota_override_t quota_override_t;

#include "quota_override_features.h"



typedef struct quota_override_t {
    struct quota_override_features_t *features; //model
    int *max_connectors; //numeric
    long *max_invoices_per_month; //numeric
    int *max_users; //numeric
    list_t* metered; //map
    char *plan; // string

    int _library_owned; // Is the library responsible for freeing this object?
} quota_override_t;

__attribute__((deprecated)) quota_override_t *quota_override_create(
    quota_override_features_t *features,
    int *max_connectors,
    long *max_invoices_per_month,
    int *max_users,
    list_t* metered,
    char *plan
);

void quota_override_free(quota_override_t *quota_override);

quota_override_t *quota_override_parseFromJSON(cJSON *quota_overrideJSON);

cJSON *quota_override_convertToJSON(quota_override_t *quota_override);

#endif /* _quota_override_H_ */

