/*
 * preceding_sales_voucher_type.h
 *
 * Type of the sales voucher that preceded this document.
 */

#ifndef _preceding_sales_voucher_type_H_
#define _preceding_sales_voucher_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct preceding_sales_voucher_type_t preceding_sales_voucher_type_t;


// Enum  for preceding_sales_voucher_type

typedef enum { simplebilly_api_preceding_sales_voucher_type__NULL = 0, simplebilly_api_preceding_sales_voucher_type__order_confirmation, simplebilly_api_preceding_sales_voucher_type__quotation, simplebilly_api_preceding_sales_voucher_type__proforma_invoice } simplebilly_api_preceding_sales_voucher_type__e;

char* preceding_sales_voucher_type_preceding_sales_voucher_type_ToString(simplebilly_api_preceding_sales_voucher_type__e preceding_sales_voucher_type);

simplebilly_api_preceding_sales_voucher_type__e preceding_sales_voucher_type_preceding_sales_voucher_type_FromString(char* preceding_sales_voucher_type);

cJSON *preceding_sales_voucher_type_convertToJSON(simplebilly_api_preceding_sales_voucher_type__e preceding_sales_voucher_type);

simplebilly_api_preceding_sales_voucher_type__e preceding_sales_voucher_type_parseFromJSON(cJSON *preceding_sales_voucher_typeJSON);

#endif /* _preceding_sales_voucher_type_H_ */

