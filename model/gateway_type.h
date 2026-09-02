/*
 * gateway_type.h
 *
 * 
 */

#ifndef _gateway_type_H_
#define _gateway_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gateway_type_t gateway_type_t;


// Enum  for gateway_type

typedef enum { simplebilly_api_gateway_type__NULL = 0, simplebilly_api_gateway_type__stripe, simplebilly_api_gateway_type__paypal, simplebilly_api_gateway_type__klarna, simplebilly_api_gateway_type__sofort, simplebilly_api_gateway_type__bancontact, simplebilly_api_gateway_type__ideal, simplebilly_api_gateway_type__bank_transfer, simplebilly_api_gateway_type__mollie, simplebilly_api_gateway_type__bitpay, simplebilly_api_gateway_type__braintree, simplebilly_api_gateway_type__adyen, simplebilly_api_gateway_type__paddle, simplebilly_api_gateway_type__viva_wallet, simplebilly_api_gateway_type__reepay, simplebilly_api_gateway_type__sumup, simplebilly_api_gateway_type__test } simplebilly_api_gateway_type__e;

char* gateway_type_gateway_type_ToString(simplebilly_api_gateway_type__e gateway_type);

simplebilly_api_gateway_type__e gateway_type_gateway_type_FromString(char* gateway_type);

cJSON *gateway_type_convertToJSON(simplebilly_api_gateway_type__e gateway_type);

simplebilly_api_gateway_type__e gateway_type_parseFromJSON(cJSON *gateway_typeJSON);

#endif /* _gateway_type_H_ */

