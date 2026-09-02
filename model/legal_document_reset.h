/*
 * legal_document_reset.h
 *
 * Optional filter for &#x60;POST /api/v1/legal/documents/reset&#x60;; empty body restores every document of the tenant.
 */

#ifndef _legal_document_reset_H_
#define _legal_document_reset_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct legal_document_reset_t legal_document_reset_t;




typedef struct legal_document_reset_t {
    char *doc_type; // string
    char *lang; // string

    int _library_owned; // Is the library responsible for freeing this object?
} legal_document_reset_t;

__attribute__((deprecated)) legal_document_reset_t *legal_document_reset_create(
    char *doc_type,
    char *lang
);

void legal_document_reset_free(legal_document_reset_t *legal_document_reset);

legal_document_reset_t *legal_document_reset_parseFromJSON(cJSON *legal_document_resetJSON);

cJSON *legal_document_reset_convertToJSON(legal_document_reset_t *legal_document_reset);

#endif /* _legal_document_reset_H_ */

