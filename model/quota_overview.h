/*
 * quota_overview.h
 *
 * 
 */

#ifndef _quota_overview_H_
#define _quota_overview_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct quota_overview_t quota_overview_t;

#include "metered_usage.h"
#include "plan_features.h"
#include "plan_limits.h"
#include "usage_snapshot.h"



typedef struct quota_overview_t {
    struct plan_features_t *features; //model
    int *is_trialing; //boolean
    struct plan_limits_t *limits; //model
    list_t *metered; //nonprimitive container
    char *plan; // string
    char *plan_name; // string
    char *trial_ends_at; //date time
    struct usage_snapshot_t *usage; //model

    int _library_owned; // Is the library responsible for freeing this object?
} quota_overview_t;

__attribute__((deprecated)) quota_overview_t *quota_overview_create(
    plan_features_t *features,
    int *is_trialing,
    plan_limits_t *limits,
    list_t *metered,
    char *plan,
    char *plan_name,
    char *trial_ends_at,
    usage_snapshot_t *usage
);

void quota_overview_free(quota_overview_t *quota_overview);

quota_overview_t *quota_overview_parseFromJSON(cJSON *quota_overviewJSON);

cJSON *quota_overview_convertToJSON(quota_overview_t *quota_overview);

#endif /* _quota_overview_H_ */

