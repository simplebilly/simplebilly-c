/*
 * message_type.h
 *
 * Body format of a ticket message.
 */

#ifndef _message_type_H_
#define _message_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_type_t message_type_t;


// Enum  for message_type

typedef enum { simplebilly_api_message_type__NULL = 0, simplebilly_api_message_type__text, simplebilly_api_message_type__html } simplebilly_api_message_type__e;

char* message_type_message_type_ToString(simplebilly_api_message_type__e message_type);

simplebilly_api_message_type__e message_type_message_type_FromString(char* message_type);

cJSON *message_type_convertToJSON(simplebilly_api_message_type__e message_type);

simplebilly_api_message_type__e message_type_parseFromJSON(cJSON *message_typeJSON);

#endif /* _message_type_H_ */

