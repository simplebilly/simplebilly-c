/*
 * sync_log.h
 *
 * 
 */

#ifndef _sync_log_H_
#define _sync_log_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sync_log_t sync_log_t;




typedef struct sync_log_t {
    char *completed_at; //date time
    char *connection_id; // string
    char *error_message; // string
    int *items_failed; //numeric
    int *items_synced; //numeric
    char *log_id; // string
    char *platform; // string
    char *started_at; //date time
    char *status; // string
    char *sync_type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} sync_log_t;

__attribute__((deprecated)) sync_log_t *sync_log_create(
    char *completed_at,
    char *connection_id,
    char *error_message,
    int *items_failed,
    int *items_synced,
    char *log_id,
    char *platform,
    char *started_at,
    char *status,
    char *sync_type
);

void sync_log_free(sync_log_t *sync_log);

sync_log_t *sync_log_parseFromJSON(cJSON *sync_logJSON);

cJSON *sync_log_convertToJSON(sync_log_t *sync_log);

#endif /* _sync_log_H_ */

