/*
 * legal_doc_type.h
 *
 * Legal document type (matches &#x60;DOC_TYPES&#x60; in legal_defaults.rs).
 */

#ifndef _legal_doc_type_H_
#define _legal_doc_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct legal_doc_type_t legal_doc_type_t;


// Enum  for legal_doc_type

typedef enum { simplebilly_api_legal_doc_type__NULL = 0, simplebilly_api_legal_doc_type__imprint, simplebilly_api_legal_doc_type__privacy, simplebilly_api_legal_doc_type__terms, simplebilly_api_legal_doc_type__withdrawal, simplebilly_api_legal_doc_type__refund, simplebilly_api_legal_doc_type__shipping, simplebilly_api_legal_doc_type__gpsr, simplebilly_api_legal_doc_type__cookie_notice } simplebilly_api_legal_doc_type__e;

char* legal_doc_type_legal_doc_type_ToString(simplebilly_api_legal_doc_type__e legal_doc_type);

simplebilly_api_legal_doc_type__e legal_doc_type_legal_doc_type_FromString(char* legal_doc_type);

cJSON *legal_doc_type_convertToJSON(simplebilly_api_legal_doc_type__e legal_doc_type);

simplebilly_api_legal_doc_type__e legal_doc_type_parseFromJSON(cJSON *legal_doc_typeJSON);

#endif /* _legal_doc_type_H_ */

