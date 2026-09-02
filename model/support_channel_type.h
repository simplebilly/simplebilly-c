/*
 * support_channel_type.h
 *
 * Support channel type: email or chat.
 */

#ifndef _support_channel_type_H_
#define _support_channel_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct support_channel_type_t support_channel_type_t;


// Enum  for support_channel_type

typedef enum { simplebilly_api_support_channel_type__NULL = 0, simplebilly_api_support_channel_type__email, simplebilly_api_support_channel_type__chat } simplebilly_api_support_channel_type__e;

char* support_channel_type_support_channel_type_ToString(simplebilly_api_support_channel_type__e support_channel_type);

simplebilly_api_support_channel_type__e support_channel_type_support_channel_type_FromString(char* support_channel_type);

cJSON *support_channel_type_convertToJSON(simplebilly_api_support_channel_type__e support_channel_type);

simplebilly_api_support_channel_type__e support_channel_type_parseFromJSON(cJSON *support_channel_typeJSON);

#endif /* _support_channel_type_H_ */

