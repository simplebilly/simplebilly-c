/*
 * resolved_price_response.h
 *
 * 
 */

#ifndef _resolved_price_response_H_
#define _resolved_price_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct resolved_price_response_t resolved_price_response_t;




typedef struct resolved_price_response_t {
    int *is_list_price; //boolean
    char *price_tier_id; // string
    char *product_id; // string
    long *quantity; //numeric
    char *unit_price; // string

    int _library_owned; // Is the library responsible for freeing this object?
} resolved_price_response_t;

__attribute__((deprecated)) resolved_price_response_t *resolved_price_response_create(
    int *is_list_price,
    char *price_tier_id,
    char *product_id,
    long *quantity,
    char *unit_price
);

void resolved_price_response_free(resolved_price_response_t *resolved_price_response);

resolved_price_response_t *resolved_price_response_parseFromJSON(cJSON *resolved_price_responseJSON);

cJSON *resolved_price_response_convertToJSON(resolved_price_response_t *resolved_price_response);

#endif /* _resolved_price_response_H_ */

