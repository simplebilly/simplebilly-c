/*
 * supplier_invoice_status.h
 *
 * Supplier invoice status.
 */

#ifndef _supplier_invoice_status_H_
#define _supplier_invoice_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct supplier_invoice_status_t supplier_invoice_status_t;


// Enum  for supplier_invoice_status

typedef enum { simplebilly_api_supplier_invoice_status__NULL = 0, simplebilly_api_supplier_invoice_status__draft, simplebilly_api_supplier_invoice_status__matched, simplebilly_api_supplier_invoice_status__has_variances, simplebilly_api_supplier_invoice_status__posted, simplebilly_api_supplier_invoice_status__cancelled } simplebilly_api_supplier_invoice_status__e;

char* supplier_invoice_status_supplier_invoice_status_ToString(simplebilly_api_supplier_invoice_status__e supplier_invoice_status);

simplebilly_api_supplier_invoice_status__e supplier_invoice_status_supplier_invoice_status_FromString(char* supplier_invoice_status);

cJSON *supplier_invoice_status_convertToJSON(simplebilly_api_supplier_invoice_status__e supplier_invoice_status);

simplebilly_api_supplier_invoice_status__e supplier_invoice_status_parseFromJSON(cJSON *supplier_invoice_statusJSON);

#endif /* _supplier_invoice_status_H_ */

