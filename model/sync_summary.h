/*
 * sync_summary.h
 *
 * Result of a sync/export run — what the app reports back to the admin UI.
 */

#ifndef _sync_summary_H_
#define _sync_summary_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sync_summary_t sync_summary_t;




typedef struct sync_summary_t {
    char *error_message; // string
    int *items_failed; //numeric
    int *items_synced; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} sync_summary_t;

__attribute__((deprecated)) sync_summary_t *sync_summary_create(
    char *error_message,
    int *items_failed,
    int *items_synced
);

void sync_summary_free(sync_summary_t *sync_summary);

sync_summary_t *sync_summary_parseFromJSON(cJSON *sync_summaryJSON);

cJSON *sync_summary_convertToJSON(sync_summary_t *sync_summary);

#endif /* _sync_summary_H_ */

