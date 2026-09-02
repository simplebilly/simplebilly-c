/*
 * legal_document.h
 *
 * 
 */

#ifndef _legal_document_H_
#define _legal_document_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct legal_document_t legal_document_t;

#include "language_code.h"
#include "legal_doc_type.h"



typedef struct legal_document_t {
    char *content; // string
    simplebilly_api_legal_doc_type__e doc_type; //referenced enum
    simplebilly_api_language_code__e lang; //referenced enum
    char *title; // string

    int _library_owned; // Is the library responsible for freeing this object?
} legal_document_t;

__attribute__((deprecated)) legal_document_t *legal_document_create(
    char *content,
    simplebilly_api_legal_doc_type__e doc_type,
    simplebilly_api_language_code__e lang,
    char *title
);

void legal_document_free(legal_document_t *legal_document);

legal_document_t *legal_document_parseFromJSON(cJSON *legal_documentJSON);

cJSON *legal_document_convertToJSON(legal_document_t *legal_document);

#endif /* _legal_document_H_ */

