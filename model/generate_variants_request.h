/*
 * generate_variants_request.h
 *
 * Request body for generating the full variant set from option values.
 */

#ifndef _generate_variants_request_H_
#define _generate_variants_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct generate_variants_request_t generate_variants_request_t;




typedef struct generate_variants_request_t {
    list_t* options; //map
    char *price_delta; // string
    char *product_id; // string
    char *sku_prefix; // string

    int _library_owned; // Is the library responsible for freeing this object?
} generate_variants_request_t;

__attribute__((deprecated)) generate_variants_request_t *generate_variants_request_create(
    list_t* options,
    char *price_delta,
    char *product_id,
    char *sku_prefix
);

void generate_variants_request_free(generate_variants_request_t *generate_variants_request);

generate_variants_request_t *generate_variants_request_parseFromJSON(cJSON *generate_variants_requestJSON);

cJSON *generate_variants_request_convertToJSON(generate_variants_request_t *generate_variants_request);

#endif /* _generate_variants_request_H_ */

