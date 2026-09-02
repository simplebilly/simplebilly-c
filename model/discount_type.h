/*
 * discount_type.h
 *
 * Coupon discount type.
 */

#ifndef _discount_type_H_
#define _discount_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct discount_type_t discount_type_t;


// Enum  for discount_type

typedef enum { simplebilly_api_discount_type__NULL = 0, simplebilly_api_discount_type__percentage, simplebilly_api_discount_type__fixed_amount } simplebilly_api_discount_type__e;

char* discount_type_discount_type_ToString(simplebilly_api_discount_type__e discount_type);

simplebilly_api_discount_type__e discount_type_discount_type_FromString(char* discount_type);

cJSON *discount_type_convertToJSON(simplebilly_api_discount_type__e discount_type);

simplebilly_api_discount_type__e discount_type_parseFromJSON(cJSON *discount_typeJSON);

#endif /* _discount_type_H_ */

