/*
 * marketplace_sync_log.h
 *
 * 
 */

#ifndef _marketplace_sync_log_H_
#define _marketplace_sync_log_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct marketplace_sync_log_t marketplace_sync_log_t;

#include "sync_log_status.h"
#include "sync_type.h"



typedef struct marketplace_sync_log_t {
    char *completed_at; //date time
    char *connection_id; // string
    char *error_message; // string
    int *items_failed; //numeric
    int *items_synced; //numeric
    char *platform; // string
    char *started_at; //date time
    simplebilly_api_sync_log_status__e status; //referenced enum
    simplebilly_api_sync_type__e sync_type; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} marketplace_sync_log_t;

__attribute__((deprecated)) marketplace_sync_log_t *marketplace_sync_log_create(
    char *completed_at,
    char *connection_id,
    char *error_message,
    int *items_failed,
    int *items_synced,
    char *platform,
    char *started_at,
    simplebilly_api_sync_log_status__e status,
    simplebilly_api_sync_type__e sync_type
);

void marketplace_sync_log_free(marketplace_sync_log_t *marketplace_sync_log);

marketplace_sync_log_t *marketplace_sync_log_parseFromJSON(cJSON *marketplace_sync_logJSON);

cJSON *marketplace_sync_log_convertToJSON(marketplace_sync_log_t *marketplace_sync_log);

#endif /* _marketplace_sync_log_H_ */

