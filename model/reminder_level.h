/*
 * reminder_level.h
 *
 * 
 */

#ifndef _reminder_level_H_
#define _reminder_level_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reminder_level_t reminder_level_t;


// Enum  for reminder_level

typedef enum { simplebilly_api_reminder_level__NULL = 0, simplebilly_api_reminder_level__none, simplebilly_api_reminder_level__due, simplebilly_api_reminder_level__level1, simplebilly_api_reminder_level__level2, simplebilly_api_reminder_level__level3 } simplebilly_api_reminder_level__e;

char* reminder_level_reminder_level_ToString(simplebilly_api_reminder_level__e reminder_level);

simplebilly_api_reminder_level__e reminder_level_reminder_level_FromString(char* reminder_level);

cJSON *reminder_level_convertToJSON(simplebilly_api_reminder_level__e reminder_level);

simplebilly_api_reminder_level__e reminder_level_parseFromJSON(cJSON *reminder_levelJSON);

#endif /* _reminder_level_H_ */

