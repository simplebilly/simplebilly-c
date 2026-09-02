/*
 * invoice_type.h
 *
 * 
 */

#ifndef _invoice_type_H_
#define _invoice_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invoice_type_t invoice_type_t;


// Enum  for invoice_type

typedef enum { simplebilly_api_invoice_type__NULL = 0, simplebilly_api_invoice_type__Invoice, simplebilly_api_invoice_type__CreditNote, simplebilly_api_invoice_type__AdvancePayment, simplebilly_api_invoice_type__FinalSettlement, simplebilly_api_invoice_type__SpecialBilling, simplebilly_api_invoice_type__DownPaymentInvoice, simplebilly_api_invoice_type__Proforma, simplebilly_api_invoice_type__Recurring, simplebilly_api_invoice_type__CancellationInvoice } simplebilly_api_invoice_type__e;

char* invoice_type_invoice_type_ToString(simplebilly_api_invoice_type__e invoice_type);

simplebilly_api_invoice_type__e invoice_type_invoice_type_FromString(char* invoice_type);

cJSON *invoice_type_convertToJSON(simplebilly_api_invoice_type__e invoice_type);

simplebilly_api_invoice_type__e invoice_type_parseFromJSON(cJSON *invoice_typeJSON);

#endif /* _invoice_type_H_ */

