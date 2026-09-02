/*
 * production_order_status.h
 *
 * Production order status.
 */

#ifndef _production_order_status_H_
#define _production_order_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct production_order_status_t production_order_status_t;


// Enum  for production_order_status

typedef enum { simplebilly_api_production_order_status__NULL = 0, simplebilly_api_production_order_status__planned, simplebilly_api_production_order_status__in_production, simplebilly_api_production_order_status__completed, simplebilly_api_production_order_status__cancelled } simplebilly_api_production_order_status__e;

char* production_order_status_production_order_status_ToString(simplebilly_api_production_order_status__e production_order_status);

simplebilly_api_production_order_status__e production_order_status_production_order_status_FromString(char* production_order_status);

cJSON *production_order_status_convertToJSON(simplebilly_api_production_order_status__e production_order_status);

simplebilly_api_production_order_status__e production_order_status_parseFromJSON(cJSON *production_order_statusJSON);

#endif /* _production_order_status_H_ */

