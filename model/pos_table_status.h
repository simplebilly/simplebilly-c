/*
 * pos_table_status.h
 *
 * POS table status.
 */

#ifndef _pos_table_status_H_
#define _pos_table_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pos_table_status_t pos_table_status_t;


// Enum  for pos_table_status

typedef enum { simplebilly_api_pos_table_status__NULL = 0, simplebilly_api_pos_table_status__free, simplebilly_api_pos_table_status__occupied } simplebilly_api_pos_table_status__e;

char* pos_table_status_pos_table_status_ToString(simplebilly_api_pos_table_status__e pos_table_status);

simplebilly_api_pos_table_status__e pos_table_status_pos_table_status_FromString(char* pos_table_status);

cJSON *pos_table_status_convertToJSON(simplebilly_api_pos_table_status__e pos_table_status);

simplebilly_api_pos_table_status__e pos_table_status_parseFromJSON(cJSON *pos_table_statusJSON);

#endif /* _pos_table_status_H_ */

