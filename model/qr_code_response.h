/*
 * qr_code_response.h
 *
 * 
 */

#ifndef _qr_code_response_H_
#define _qr_code_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct qr_code_response_t qr_code_response_t;




typedef struct qr_code_response_t {
    char *content_type; // string
    char *qr_code_base64; // string

    int _library_owned; // Is the library responsible for freeing this object?
} qr_code_response_t;

__attribute__((deprecated)) qr_code_response_t *qr_code_response_create(
    char *content_type,
    char *qr_code_base64
);

void qr_code_response_free(qr_code_response_t *qr_code_response);

qr_code_response_t *qr_code_response_parseFromJSON(cJSON *qr_code_responseJSON);

cJSON *qr_code_response_convertToJSON(qr_code_response_t *qr_code_response);

#endif /* _qr_code_response_H_ */

