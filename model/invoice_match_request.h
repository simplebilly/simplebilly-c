/*
 * invoice_match_request.h
 *
 * 
 */

#ifndef _invoice_match_request_H_
#define _invoice_match_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invoice_match_request_t invoice_match_request_t;




typedef struct invoice_match_request_t {
    char *supplier_invoice_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} invoice_match_request_t;

__attribute__((deprecated)) invoice_match_request_t *invoice_match_request_create(
    char *supplier_invoice_id
);

void invoice_match_request_free(invoice_match_request_t *invoice_match_request);

invoice_match_request_t *invoice_match_request_parseFromJSON(cJSON *invoice_match_requestJSON);

cJSON *invoice_match_request_convertToJSON(invoice_match_request_t *invoice_match_request);

#endif /* _invoice_match_request_H_ */

