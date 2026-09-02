/*
 * order_status.h
 *
 * 
 */

#ifndef _order_status_H_
#define _order_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct order_status_t order_status_t;


// Enum  for order_status

typedef enum { simplebilly_api_order_status__NULL = 0, simplebilly_api_order_status__pending, simplebilly_api_order_status__ordered, simplebilly_api_order_status__confirmed, simplebilly_api_order_status__processing, simplebilly_api_order_status__paid, simplebilly_api_order_status__shipped, simplebilly_api_order_status__completed, simplebilly_api_order_status__closed, simplebilly_api_order_status__cancelled, simplebilly_api_order_status__refunded, simplebilly_api_order_status__failed } simplebilly_api_order_status__e;

char* order_status_order_status_ToString(simplebilly_api_order_status__e order_status);

simplebilly_api_order_status__e order_status_order_status_FromString(char* order_status);

cJSON *order_status_convertToJSON(simplebilly_api_order_status__e order_status);

simplebilly_api_order_status__e order_status_parseFromJSON(cJSON *order_statusJSON);

#endif /* _order_status_H_ */

