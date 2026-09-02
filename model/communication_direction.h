/*
 * communication_direction.h
 *
 * Direction of the communication relative to the business.
 */

#ifndef _communication_direction_H_
#define _communication_direction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct communication_direction_t communication_direction_t;


// Enum  for communication_direction

typedef enum { simplebilly_api_communication_direction__NULL = 0, simplebilly_api_communication_direction__inbound, simplebilly_api_communication_direction__outbound } simplebilly_api_communication_direction__e;

char* communication_direction_communication_direction_ToString(simplebilly_api_communication_direction__e communication_direction);

simplebilly_api_communication_direction__e communication_direction_communication_direction_FromString(char* communication_direction);

cJSON *communication_direction_convertToJSON(simplebilly_api_communication_direction__e communication_direction);

simplebilly_api_communication_direction__e communication_direction_parseFromJSON(cJSON *communication_directionJSON);

#endif /* _communication_direction_H_ */

