/*
 * webhook_direction.h
 *
 * Webhook event direction: inbound | outbound.
 */

#ifndef _webhook_direction_H_
#define _webhook_direction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct webhook_direction_t webhook_direction_t;


// Enum  for webhook_direction

typedef enum { simplebilly_api_webhook_direction__NULL = 0, simplebilly_api_webhook_direction__inbound, simplebilly_api_webhook_direction__outbound } simplebilly_api_webhook_direction__e;

char* webhook_direction_webhook_direction_ToString(simplebilly_api_webhook_direction__e webhook_direction);

simplebilly_api_webhook_direction__e webhook_direction_webhook_direction_FromString(char* webhook_direction);

cJSON *webhook_direction_convertToJSON(simplebilly_api_webhook_direction__e webhook_direction);

simplebilly_api_webhook_direction__e webhook_direction_parseFromJSON(cJSON *webhook_directionJSON);

#endif /* _webhook_direction_H_ */

