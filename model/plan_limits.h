/*
 * plan_limits.h
 *
 * Per-plan numeric limits. &#x60;-1&#x60; in any field means unlimited.
 */

#ifndef _plan_limits_H_
#define _plan_limits_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plan_limits_t plan_limits_t;




typedef struct plan_limits_t {
    int *max_connectors; //numeric
    long *max_invoices_per_month; //numeric
    int *max_users; //numeric
    list_t* metered; //map
    list_t *paid_connectors; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} plan_limits_t;

__attribute__((deprecated)) plan_limits_t *plan_limits_create(
    int *max_connectors,
    long *max_invoices_per_month,
    int *max_users,
    list_t* metered,
    list_t *paid_connectors
);

void plan_limits_free(plan_limits_t *plan_limits);

plan_limits_t *plan_limits_parseFromJSON(cJSON *plan_limitsJSON);

cJSON *plan_limits_convertToJSON(plan_limits_t *plan_limits);

#endif /* _plan_limits_H_ */

