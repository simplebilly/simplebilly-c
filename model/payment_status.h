/*
 * payment_status.h
 *
 * Payment state of an invoice.
 */

#ifndef _payment_status_H_
#define _payment_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payment_status_t payment_status_t;


// Enum  for payment_status

typedef enum { simplebilly_api_payment_status__NULL = 0, simplebilly_api_payment_status__unpaid, simplebilly_api_payment_status__paid } simplebilly_api_payment_status__e;

char* payment_status_payment_status_ToString(simplebilly_api_payment_status__e payment_status);

simplebilly_api_payment_status__e payment_status_payment_status_FromString(char* payment_status);

cJSON *payment_status_convertToJSON(simplebilly_api_payment_status__e payment_status);

simplebilly_api_payment_status__e payment_status_parseFromJSON(cJSON *payment_statusJSON);

#endif /* _payment_status_H_ */

