/*
 * movement_type.h
 *
 * Stock movement type.
 */

#ifndef _movement_type_H_
#define _movement_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct movement_type_t movement_type_t;


// Enum  for movement_type

typedef enum { simplebilly_api_movement_type__NULL = 0, simplebilly_api_movement_type__goods_receipt, simplebilly_api_movement_type__goods_receipt_reversal, simplebilly_api_movement_type__transfer_in, simplebilly_api_movement_type__transfer_out, simplebilly_api_movement_type__return_restock, simplebilly_api_movement_type__production_consumption, simplebilly_api_movement_type__production_completion, simplebilly_api_movement_type__inventory_adjustment, simplebilly_api_movement_type__sale, simplebilly_api_movement_type__other } simplebilly_api_movement_type__e;

char* movement_type_movement_type_ToString(simplebilly_api_movement_type__e movement_type);

simplebilly_api_movement_type__e movement_type_movement_type_FromString(char* movement_type);

cJSON *movement_type_convertToJSON(simplebilly_api_movement_type__e movement_type);

simplebilly_api_movement_type__e movement_type_parseFromJSON(cJSON *movement_typeJSON);

#endif /* _movement_type_H_ */

