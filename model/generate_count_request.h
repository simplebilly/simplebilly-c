/*
 * generate_count_request.h
 *
 * Body for the cycle-count generator: create a draft count document for a warehouse, optionally restricted to a set of product ids.
 */

#ifndef _generate_count_request_H_
#define _generate_count_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct generate_count_request_t generate_count_request_t;




typedef struct generate_count_request_t {
    char *notes; // string
    list_t *product_ids; //primitive container
    char *warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} generate_count_request_t;

__attribute__((deprecated)) generate_count_request_t *generate_count_request_create(
    char *notes,
    list_t *product_ids,
    char *warehouse_id
);

void generate_count_request_free(generate_count_request_t *generate_count_request);

generate_count_request_t *generate_count_request_parseFromJSON(cJSON *generate_count_requestJSON);

cJSON *generate_count_request_convertToJSON(generate_count_request_t *generate_count_request);

#endif /* _generate_count_request_H_ */

