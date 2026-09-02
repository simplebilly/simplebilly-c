/*
 * delivery_date_status.h
 *
 * Delivery date status.
 */

#ifndef _delivery_date_status_H_
#define _delivery_date_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delivery_date_status_t delivery_date_status_t;


// Enum  for delivery_date_status

typedef enum { simplebilly_api_delivery_date_status__NULL = 0, simplebilly_api_delivery_date_status__promised, simplebilly_api_delivery_date_status__confirmed, simplebilly_api_delivery_date_status__rescheduled, simplebilly_api_delivery_date_status__fulfilled, simplebilly_api_delivery_date_status__late, simplebilly_api_delivery_date_status__cancelled } simplebilly_api_delivery_date_status__e;

char* delivery_date_status_delivery_date_status_ToString(simplebilly_api_delivery_date_status__e delivery_date_status);

simplebilly_api_delivery_date_status__e delivery_date_status_delivery_date_status_FromString(char* delivery_date_status);

cJSON *delivery_date_status_convertToJSON(simplebilly_api_delivery_date_status__e delivery_date_status);

simplebilly_api_delivery_date_status__e delivery_date_status_parseFromJSON(cJSON *delivery_date_statusJSON);

#endif /* _delivery_date_status_H_ */

