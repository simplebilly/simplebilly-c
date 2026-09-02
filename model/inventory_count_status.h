/*
 * inventory_count_status.h
 *
 * Inventory count status.
 */

#ifndef _inventory_count_status_H_
#define _inventory_count_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inventory_count_status_t inventory_count_status_t;


// Enum  for inventory_count_status

typedef enum { simplebilly_api_inventory_count_status__NULL = 0, simplebilly_api_inventory_count_status__draft, simplebilly_api_inventory_count_status__counting, simplebilly_api_inventory_count_status__reviewed, simplebilly_api_inventory_count_status__posted } simplebilly_api_inventory_count_status__e;

char* inventory_count_status_inventory_count_status_ToString(simplebilly_api_inventory_count_status__e inventory_count_status);

simplebilly_api_inventory_count_status__e inventory_count_status_inventory_count_status_FromString(char* inventory_count_status);

cJSON *inventory_count_status_convertToJSON(simplebilly_api_inventory_count_status__e inventory_count_status);

simplebilly_api_inventory_count_status__e inventory_count_status_parseFromJSON(cJSON *inventory_count_statusJSON);

#endif /* _inventory_count_status_H_ */

