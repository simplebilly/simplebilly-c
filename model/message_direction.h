/*
 * message_direction.h
 *
 * Message direction relative to the business.
 */

#ifndef _message_direction_H_
#define _message_direction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_direction_t message_direction_t;


// Enum  for message_direction

typedef enum { simplebilly_api_message_direction__NULL = 0, simplebilly_api_message_direction__inbound, simplebilly_api_message_direction__outbound, simplebilly_api_message_direction__internal } simplebilly_api_message_direction__e;

char* message_direction_message_direction_ToString(simplebilly_api_message_direction__e message_direction);

simplebilly_api_message_direction__e message_direction_message_direction_FromString(char* message_direction);

cJSON *message_direction_convertToJSON(simplebilly_api_message_direction__e message_direction);

simplebilly_api_message_direction__e message_direction_parseFromJSON(cJSON *message_directionJSON);

#endif /* _message_direction_H_ */

