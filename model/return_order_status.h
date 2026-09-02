/*
 * return_order_status.h
 *
 * Return order status.
 */

#ifndef _return_order_status_H_
#define _return_order_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct return_order_status_t return_order_status_t;


// Enum  for return_order_status

typedef enum { simplebilly_api_return_order_status__NULL = 0, simplebilly_api_return_order_status__requested, simplebilly_api_return_order_status__received, simplebilly_api_return_order_status__inspected, simplebilly_api_return_order_status__restocked, simplebilly_api_return_order_status__closed } simplebilly_api_return_order_status__e;

char* return_order_status_return_order_status_ToString(simplebilly_api_return_order_status__e return_order_status);

simplebilly_api_return_order_status__e return_order_status_return_order_status_FromString(char* return_order_status);

cJSON *return_order_status_convertToJSON(simplebilly_api_return_order_status__e return_order_status);

simplebilly_api_return_order_status__e return_order_status_parseFromJSON(cJSON *return_order_statusJSON);

#endif /* _return_order_status_H_ */

