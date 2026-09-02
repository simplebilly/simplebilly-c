/*
 * invoice_status.h
 *
 * 
 */

#ifndef _invoice_status_H_
#define _invoice_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invoice_status_t invoice_status_t;


// Enum  for invoice_status

typedef enum { simplebilly_api_invoice_status__NULL = 0, simplebilly_api_invoice_status__Draft, simplebilly_api_invoice_status__Sent, simplebilly_api_invoice_status__PartiallyPaid, simplebilly_api_invoice_status__Paid, simplebilly_api_invoice_status__Overdue, simplebilly_api_invoice_status__Cancelled, simplebilly_api_invoice_status__Credited, simplebilly_api_invoice_status__Expired, simplebilly_api_invoice_status__Dunning, simplebilly_api_invoice_status__CollectDebt } simplebilly_api_invoice_status__e;

char* invoice_status_invoice_status_ToString(simplebilly_api_invoice_status__e invoice_status);

simplebilly_api_invoice_status__e invoice_status_invoice_status_FromString(char* invoice_status);

cJSON *invoice_status_convertToJSON(simplebilly_api_invoice_status__e invoice_status);

simplebilly_api_invoice_status__e invoice_status_parseFromJSON(cJSON *invoice_statusJSON);

#endif /* _invoice_status_H_ */

