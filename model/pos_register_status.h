/*
 * pos_register_status.h
 *
 * POS register status.
 */

#ifndef _pos_register_status_H_
#define _pos_register_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pos_register_status_t pos_register_status_t;


// Enum  for pos_register_status

typedef enum { simplebilly_api_pos_register_status__NULL = 0, simplebilly_api_pos_register_status__active, simplebilly_api_pos_register_status__disabled } simplebilly_api_pos_register_status__e;

char* pos_register_status_pos_register_status_ToString(simplebilly_api_pos_register_status__e pos_register_status);

simplebilly_api_pos_register_status__e pos_register_status_pos_register_status_FromString(char* pos_register_status);

cJSON *pos_register_status_convertToJSON(simplebilly_api_pos_register_status__e pos_register_status);

simplebilly_api_pos_register_status__e pos_register_status_parseFromJSON(cJSON *pos_register_statusJSON);

#endif /* _pos_register_status_H_ */

