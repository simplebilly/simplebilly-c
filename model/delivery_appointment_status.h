/*
 * delivery_appointment_status.h
 *
 * Delivery appointment status.
 */

#ifndef _delivery_appointment_status_H_
#define _delivery_appointment_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delivery_appointment_status_t delivery_appointment_status_t;


// Enum  for delivery_appointment_status

typedef enum { simplebilly_api_delivery_appointment_status__NULL = 0, simplebilly_api_delivery_appointment_status__requested, simplebilly_api_delivery_appointment_status__confirmed, simplebilly_api_delivery_appointment_status__arrived, simplebilly_api_delivery_appointment_status__cancelled, simplebilly_api_delivery_appointment_status__completed } simplebilly_api_delivery_appointment_status__e;

char* delivery_appointment_status_delivery_appointment_status_ToString(simplebilly_api_delivery_appointment_status__e delivery_appointment_status);

simplebilly_api_delivery_appointment_status__e delivery_appointment_status_delivery_appointment_status_FromString(char* delivery_appointment_status);

cJSON *delivery_appointment_status_convertToJSON(simplebilly_api_delivery_appointment_status__e delivery_appointment_status);

simplebilly_api_delivery_appointment_status__e delivery_appointment_status_parseFromJSON(cJSON *delivery_appointment_statusJSON);

#endif /* _delivery_appointment_status_H_ */

