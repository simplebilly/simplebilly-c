/*
 * purchase_order_status.h
 *
 * Purchase order status.
 */

#ifndef _purchase_order_status_H_
#define _purchase_order_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct purchase_order_status_t purchase_order_status_t;


// Enum  for purchase_order_status

typedef enum { simplebilly_api_purchase_order_status__NULL = 0, simplebilly_api_purchase_order_status__draft, simplebilly_api_purchase_order_status__ordered, simplebilly_api_purchase_order_status__partially_received, simplebilly_api_purchase_order_status__received, simplebilly_api_purchase_order_status__cancelled } simplebilly_api_purchase_order_status__e;

char* purchase_order_status_purchase_order_status_ToString(simplebilly_api_purchase_order_status__e purchase_order_status);

simplebilly_api_purchase_order_status__e purchase_order_status_purchase_order_status_FromString(char* purchase_order_status);

cJSON *purchase_order_status_convertToJSON(simplebilly_api_purchase_order_status__e purchase_order_status);

simplebilly_api_purchase_order_status__e purchase_order_status_parseFromJSON(cJSON *purchase_order_statusJSON);

#endif /* _purchase_order_status_H_ */

