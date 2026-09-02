/*
 * print_label_response.h
 *
 * 
 */

#ifndef _print_label_response_H_
#define _print_label_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct print_label_response_t print_label_response_t;




typedef struct print_label_response_t {
    char *label_url; // string
    char *message; // string
    char *sscc; // string
    int *success; //boolean
    char *tracking_number; // string

    int _library_owned; // Is the library responsible for freeing this object?
} print_label_response_t;

__attribute__((deprecated)) print_label_response_t *print_label_response_create(
    char *label_url,
    char *message,
    char *sscc,
    int *success,
    char *tracking_number
);

void print_label_response_free(print_label_response_t *print_label_response);

print_label_response_t *print_label_response_parseFromJSON(cJSON *print_label_responseJSON);

cJSON *print_label_response_convertToJSON(print_label_response_t *print_label_response);

#endif /* _print_label_response_H_ */

