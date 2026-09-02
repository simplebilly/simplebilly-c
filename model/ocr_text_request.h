/*
 * ocr_text_request.h
 *
 * 
 */

#ifndef _ocr_text_request_H_
#define _ocr_text_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ocr_text_request_t ocr_text_request_t;




typedef struct ocr_text_request_t {
    char *ocr_text; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ocr_text_request_t;

__attribute__((deprecated)) ocr_text_request_t *ocr_text_request_create(
    char *ocr_text
);

void ocr_text_request_free(ocr_text_request_t *ocr_text_request);

ocr_text_request_t *ocr_text_request_parseFromJSON(cJSON *ocr_text_requestJSON);

cJSON *ocr_text_request_convertToJSON(ocr_text_request_t *ocr_text_request);

#endif /* _ocr_text_request_H_ */

