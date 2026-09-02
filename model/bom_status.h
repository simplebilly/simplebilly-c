/*
 * bom_status.h
 *
 * BOM lifecycle status.
 */

#ifndef _bom_status_H_
#define _bom_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bom_status_t bom_status_t;


// Enum  for bom_status

typedef enum { simplebilly_api_bom_status__NULL = 0, simplebilly_api_bom_status__draft, simplebilly_api_bom_status__active, simplebilly_api_bom_status__archived } simplebilly_api_bom_status__e;

char* bom_status_bom_status_ToString(simplebilly_api_bom_status__e bom_status);

simplebilly_api_bom_status__e bom_status_bom_status_FromString(char* bom_status);

cJSON *bom_status_convertToJSON(simplebilly_api_bom_status__e bom_status);

simplebilly_api_bom_status__e bom_status_parseFromJSON(cJSON *bom_statusJSON);

#endif /* _bom_status_H_ */

