/*
 * sync_status.h
 *
 * Marketplace sync status.
 */

#ifndef _sync_status_H_
#define _sync_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sync_status_t sync_status_t;


// Enum  for sync_status

typedef enum { simplebilly_api_sync_status__NULL = 0, simplebilly_api_sync_status__pending, simplebilly_api_sync_status__connected, simplebilly_api_sync_status__success, simplebilly_api_sync_status__error } simplebilly_api_sync_status__e;

char* sync_status_sync_status_ToString(simplebilly_api_sync_status__e sync_status);

simplebilly_api_sync_status__e sync_status_sync_status_FromString(char* sync_status);

cJSON *sync_status_convertToJSON(simplebilly_api_sync_status__e sync_status);

simplebilly_api_sync_status__e sync_status_parseFromJSON(cJSON *sync_statusJSON);

#endif /* _sync_status_H_ */

