/*
 * x_rechnung_response.h
 *
 * 
 */

#ifndef _x_rechnung_response_H_
#define _x_rechnung_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct x_rechnung_response_t x_rechnung_response_t;




typedef struct x_rechnung_response_t {
    char *content; // string
    char *content_type; // string
    char *filename; // string

    int _library_owned; // Is the library responsible for freeing this object?
} x_rechnung_response_t;

__attribute__((deprecated)) x_rechnung_response_t *x_rechnung_response_create(
    char *content,
    char *content_type,
    char *filename
);

void x_rechnung_response_free(x_rechnung_response_t *x_rechnung_response);

x_rechnung_response_t *x_rechnung_response_parseFromJSON(cJSON *x_rechnung_responseJSON);

cJSON *x_rechnung_response_convertToJSON(x_rechnung_response_t *x_rechnung_response);

#endif /* _x_rechnung_response_H_ */

