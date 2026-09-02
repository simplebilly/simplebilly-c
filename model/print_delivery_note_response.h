/*
 * print_delivery_note_response.h
 *
 * 
 */

#ifndef _print_delivery_note_response_H_
#define _print_delivery_note_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct print_delivery_note_response_t print_delivery_note_response_t;




typedef struct print_delivery_note_response_t {
    char *message; // string
    char *pdf_url; // string
    int *success; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} print_delivery_note_response_t;

__attribute__((deprecated)) print_delivery_note_response_t *print_delivery_note_response_create(
    char *message,
    char *pdf_url,
    int *success
);

void print_delivery_note_response_free(print_delivery_note_response_t *print_delivery_note_response);

print_delivery_note_response_t *print_delivery_note_response_parseFromJSON(cJSON *print_delivery_note_responseJSON);

cJSON *print_delivery_note_response_convertToJSON(print_delivery_note_response_t *print_delivery_note_response);

#endif /* _print_delivery_note_response_H_ */

