/*
 * payment_method.h
 *
 * 
 */

#ifndef _payment_method_H_
#define _payment_method_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payment_method_t payment_method_t;


// Enum  for payment_method

typedef enum { simplebilly_api_payment_method__NULL = 0, simplebilly_api_payment_method__bank_transfer, simplebilly_api_payment_method__sepa_direct_debit, simplebilly_api_payment_method__cash, simplebilly_api_payment_method__credit_card, simplebilly_api_payment_method__paypal, simplebilly_api_payment_method__sumup, simplebilly_api_payment_method__viva_wallet, simplebilly_api_payment_method__reepay, simplebilly_api_payment_method__none } simplebilly_api_payment_method__e;

char* payment_method_payment_method_ToString(simplebilly_api_payment_method__e payment_method);

simplebilly_api_payment_method__e payment_method_payment_method_FromString(char* payment_method);

cJSON *payment_method_convertToJSON(simplebilly_api_payment_method__e payment_method);

simplebilly_api_payment_method__e payment_method_parseFromJSON(cJSON *payment_methodJSON);

#endif /* _payment_method_H_ */

