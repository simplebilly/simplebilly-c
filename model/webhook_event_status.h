/*
 * webhook_event_status.h
 *
 * Webhook event delivery status: accepted | delivered | failed.
 */

#ifndef _webhook_event_status_H_
#define _webhook_event_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct webhook_event_status_t webhook_event_status_t;


// Enum  for webhook_event_status

typedef enum { simplebilly_api_webhook_event_status__NULL = 0, simplebilly_api_webhook_event_status__accepted, simplebilly_api_webhook_event_status__delivered, simplebilly_api_webhook_event_status__failed, simplebilly_api_webhook_event_status__received } simplebilly_api_webhook_event_status__e;

char* webhook_event_status_webhook_event_status_ToString(simplebilly_api_webhook_event_status__e webhook_event_status);

simplebilly_api_webhook_event_status__e webhook_event_status_webhook_event_status_FromString(char* webhook_event_status);

cJSON *webhook_event_status_convertToJSON(simplebilly_api_webhook_event_status__e webhook_event_status);

simplebilly_api_webhook_event_status__e webhook_event_status_parseFromJSON(cJSON *webhook_event_statusJSON);

#endif /* _webhook_event_status_H_ */

