/*
 * invoice_pdf_url_response.h
 *
 * 
 */

#ifndef _invoice_pdf_url_response_H_
#define _invoice_pdf_url_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invoice_pdf_url_response_t invoice_pdf_url_response_t;




typedef struct invoice_pdf_url_response_t {
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} invoice_pdf_url_response_t;

__attribute__((deprecated)) invoice_pdf_url_response_t *invoice_pdf_url_response_create(
    char *url
);

void invoice_pdf_url_response_free(invoice_pdf_url_response_t *invoice_pdf_url_response);

invoice_pdf_url_response_t *invoice_pdf_url_response_parseFromJSON(cJSON *invoice_pdf_url_responseJSON);

cJSON *invoice_pdf_url_response_convertToJSON(invoice_pdf_url_response_t *invoice_pdf_url_response);

#endif /* _invoice_pdf_url_response_H_ */

