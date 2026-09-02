/*
 * communication_channel.h
 *
 * Channel the communication took place on.
 */

#ifndef _communication_channel_H_
#define _communication_channel_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct communication_channel_t communication_channel_t;


// Enum  for communication_channel

typedef enum { simplebilly_api_communication_channel__NULL = 0, simplebilly_api_communication_channel__email, simplebilly_api_communication_channel__call, simplebilly_api_communication_channel__meeting, simplebilly_api_communication_channel__chat, simplebilly_api_communication_channel__note } simplebilly_api_communication_channel__e;

char* communication_channel_communication_channel_ToString(simplebilly_api_communication_channel__e communication_channel);

simplebilly_api_communication_channel__e communication_channel_communication_channel_FromString(char* communication_channel);

cJSON *communication_channel_convertToJSON(simplebilly_api_communication_channel__e communication_channel);

simplebilly_api_communication_channel__e communication_channel_parseFromJSON(cJSON *communication_channelJSON);

#endif /* _communication_channel_H_ */

