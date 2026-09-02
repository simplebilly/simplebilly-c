/*
 * document_type.h
 *
 * Document kind of the invoice record.
 */

#ifndef _document_type_H_
#define _document_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct document_type_t document_type_t;


// Enum  for document_type

typedef enum { simplebilly_api_document_type__NULL = 0, simplebilly_api_document_type__invoice, simplebilly_api_document_type__creditnote, simplebilly_api_document_type__advancepayment, simplebilly_api_document_type__downpaymentinvoice, simplebilly_api_document_type__deliverynote, simplebilly_api_document_type__orderconfirmation, simplebilly_api_document_type__quotation, simplebilly_api_document_type__proformainvoice } simplebilly_api_document_type__e;

char* document_type_document_type_ToString(simplebilly_api_document_type__e document_type);

simplebilly_api_document_type__e document_type_document_type_FromString(char* document_type);

cJSON *document_type_convertToJSON(simplebilly_api_document_type__e document_type);

simplebilly_api_document_type__e document_type_parseFromJSON(cJSON *document_typeJSON);

#endif /* _document_type_H_ */

