/*
 * reference_type.h
 *
 * Stock movement reference type.
 */

#ifndef _reference_type_H_
#define _reference_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reference_type_t reference_type_t;


// Enum  for reference_type

typedef enum { simplebilly_api_reference_type__NULL = 0, simplebilly_api_reference_type__goods_receipt, simplebilly_api_reference_type__production_order, simplebilly_api_reference_type__transfer_in, simplebilly_api_reference_type__stock_transfer, simplebilly_api_reference_type__return_order, simplebilly_api_reference_type__inventory_count } simplebilly_api_reference_type__e;

char* reference_type_reference_type_ToString(simplebilly_api_reference_type__e reference_type);

simplebilly_api_reference_type__e reference_type_reference_type_FromString(char* reference_type);

cJSON *reference_type_convertToJSON(simplebilly_api_reference_type__e reference_type);

simplebilly_api_reference_type__e reference_type_parseFromJSON(cJSON *reference_typeJSON);

#endif /* _reference_type_H_ */

