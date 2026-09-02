/*
 * proforma_invoice_status.h
 *
 * Lifecycle status of a proforma invoice.
 */

#ifndef _proforma_invoice_status_H_
#define _proforma_invoice_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct proforma_invoice_status_t proforma_invoice_status_t;


// Enum  for proforma_invoice_status

typedef enum { simplebilly_api_proforma_invoice_status__NULL = 0, simplebilly_api_proforma_invoice_status__draft, simplebilly_api_proforma_invoice_status__sent, simplebilly_api_proforma_invoice_status__converted } simplebilly_api_proforma_invoice_status__e;

char* proforma_invoice_status_proforma_invoice_status_ToString(simplebilly_api_proforma_invoice_status__e proforma_invoice_status);

simplebilly_api_proforma_invoice_status__e proforma_invoice_status_proforma_invoice_status_FromString(char* proforma_invoice_status);

cJSON *proforma_invoice_status_convertToJSON(simplebilly_api_proforma_invoice_status__e proforma_invoice_status);

simplebilly_api_proforma_invoice_status__e proforma_invoice_status_parseFromJSON(cJSON *proforma_invoice_statusJSON);

#endif /* _proforma_invoice_status_H_ */

