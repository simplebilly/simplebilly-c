/*
 * legal_document_upsert.h
 *
 * One document to upsert (&#x60;PUT /api/v1/legal/documents&#x60; body element).
 */

#ifndef _legal_document_upsert_H_
#define _legal_document_upsert_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct legal_document_upsert_t legal_document_upsert_t;




typedef struct legal_document_upsert_t {
    char *content; // string
    char *doc_type; // string
    char *lang; // string
    char *title; // string

    int _library_owned; // Is the library responsible for freeing this object?
} legal_document_upsert_t;

__attribute__((deprecated)) legal_document_upsert_t *legal_document_upsert_create(
    char *content,
    char *doc_type,
    char *lang,
    char *title
);

void legal_document_upsert_free(legal_document_upsert_t *legal_document_upsert);

legal_document_upsert_t *legal_document_upsert_parseFromJSON(cJSON *legal_document_upsertJSON);

cJSON *legal_document_upsert_convertToJSON(legal_document_upsert_t *legal_document_upsert);

#endif /* _legal_document_upsert_H_ */

