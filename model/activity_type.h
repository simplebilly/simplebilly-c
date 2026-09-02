/*
 * activity_type.h
 *
 * Activity type.
 */

#ifndef _activity_type_H_
#define _activity_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_type_t activity_type_t;


// Enum  for activity_type

typedef enum { simplebilly_api_activity_type__NULL = 0, simplebilly_api_activity_type__call, simplebilly_api_activity_type__email, simplebilly_api_activity_type__meeting, simplebilly_api_activity_type__task, simplebilly_api_activity_type__note } simplebilly_api_activity_type__e;

char* activity_type_activity_type_ToString(simplebilly_api_activity_type__e activity_type);

simplebilly_api_activity_type__e activity_type_activity_type_FromString(char* activity_type);

cJSON *activity_type_convertToJSON(simplebilly_api_activity_type__e activity_type);

simplebilly_api_activity_type__e activity_type_parseFromJSON(cJSON *activity_typeJSON);

#endif /* _activity_type_H_ */

