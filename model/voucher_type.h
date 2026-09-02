/*
 * voucher_type.h
 *
 * Kind of booking voucher.
 */

#ifndef _voucher_type_H_
#define _voucher_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct voucher_type_t voucher_type_t;


// Enum  for voucher_type

typedef enum { simplebilly_api_voucher_type__NULL = 0, simplebilly_api_voucher_type__invoice } simplebilly_api_voucher_type__e;

char* voucher_type_voucher_type_ToString(simplebilly_api_voucher_type__e voucher_type);

simplebilly_api_voucher_type__e voucher_type_voucher_type_FromString(char* voucher_type);

cJSON *voucher_type_convertToJSON(simplebilly_api_voucher_type__e voucher_type);

simplebilly_api_voucher_type__e voucher_type_parseFromJSON(cJSON *voucher_typeJSON);

#endif /* _voucher_type_H_ */

