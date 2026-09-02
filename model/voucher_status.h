/*
 * voucher_status.h
 *
 * Lifecycle status of a voucher.
 */

#ifndef _voucher_status_H_
#define _voucher_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct voucher_status_t voucher_status_t;


// Enum  for voucher_status

typedef enum { simplebilly_api_voucher_status__NULL = 0, simplebilly_api_voucher_status__open, simplebilly_api_voucher_status__paid, simplebilly_api_voucher_status__invoiced } simplebilly_api_voucher_status__e;

char* voucher_status_voucher_status_ToString(simplebilly_api_voucher_status__e voucher_status);

simplebilly_api_voucher_status__e voucher_status_voucher_status_FromString(char* voucher_status);

cJSON *voucher_status_convertToJSON(simplebilly_api_voucher_status__e voucher_status);

simplebilly_api_voucher_status__e voucher_status_parseFromJSON(cJSON *voucher_statusJSON);

#endif /* _voucher_status_H_ */

