/*
 * usage_snapshot.h
 *
 * Current usage for a tenant. &#x60;overage_seats&#x60; is what billing charges 5€/seat/month on.
 */

#ifndef _usage_snapshot_H_
#define _usage_snapshot_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct usage_snapshot_t usage_snapshot_t;




typedef struct usage_snapshot_t {
    long *connectors; //numeric
    long *invoices_this_month; //numeric
    long *overage_seats; //numeric
    long *users; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} usage_snapshot_t;

__attribute__((deprecated)) usage_snapshot_t *usage_snapshot_create(
    long *connectors,
    long *invoices_this_month,
    long *overage_seats,
    long *users
);

void usage_snapshot_free(usage_snapshot_t *usage_snapshot);

usage_snapshot_t *usage_snapshot_parseFromJSON(cJSON *usage_snapshotJSON);

cJSON *usage_snapshot_convertToJSON(usage_snapshot_t *usage_snapshot);

#endif /* _usage_snapshot_H_ */

