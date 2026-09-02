/*
 * sync_type.h
 *
 * Marketplace sync type.
 */

#ifndef _sync_type_H_
#define _sync_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sync_type_t sync_type_t;


// Enum  for sync_type

typedef enum { simplebilly_api_sync_type__NULL = 0, simplebilly_api_sync_type__orders, simplebilly_api_sync_type__products, simplebilly_api_sync_type__inventory, simplebilly_api_sync_type__invoices, simplebilly_api_sync_type__shipments, simplebilly_api_sync_type__contacts, simplebilly_api_sync_type__prices, simplebilly_api_sync_type__config, simplebilly_api_sync_type__branding, simplebilly_api_sync_type__legal } simplebilly_api_sync_type__e;

char* sync_type_sync_type_ToString(simplebilly_api_sync_type__e sync_type);

simplebilly_api_sync_type__e sync_type_sync_type_FromString(char* sync_type);

cJSON *sync_type_convertToJSON(simplebilly_api_sync_type__e sync_type);

simplebilly_api_sync_type__e sync_type_parseFromJSON(cJSON *sync_typeJSON);

#endif /* _sync_type_H_ */

