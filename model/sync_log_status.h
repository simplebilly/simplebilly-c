/*
 * sync_log_status.h
 *
 * Marketplace sync log status.
 */

#ifndef _sync_log_status_H_
#define _sync_log_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sync_log_status_t sync_log_status_t;


// Enum  for sync_log_status

typedef enum { simplebilly_api_sync_log_status__NULL = 0, simplebilly_api_sync_log_status__running, simplebilly_api_sync_log_status__success, simplebilly_api_sync_log_status__error } simplebilly_api_sync_log_status__e;

char* sync_log_status_sync_log_status_ToString(simplebilly_api_sync_log_status__e sync_log_status);

simplebilly_api_sync_log_status__e sync_log_status_sync_log_status_FromString(char* sync_log_status);

cJSON *sync_log_status_convertToJSON(simplebilly_api_sync_log_status__e sync_log_status);

simplebilly_api_sync_log_status__e sync_log_status_parseFromJSON(cJSON *sync_log_statusJSON);

#endif /* _sync_log_status_H_ */

