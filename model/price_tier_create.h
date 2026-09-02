/*
 * price_tier_create.h
 *
 * 
 */

#ifndef _price_tier_create_H_
#define _price_tier_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct price_tier_create_t price_tier_create_t;




typedef struct price_tier_create_t {
    char *customer_group_id; // string
    long *min_quantity; //numeric
    char *product_id; // string
    char *unit_price; // string

    int _library_owned; // Is the library responsible for freeing this object?
} price_tier_create_t;

__attribute__((deprecated)) price_tier_create_t *price_tier_create_create(
    char *customer_group_id,
    long *min_quantity,
    char *product_id,
    char *unit_price
);

void price_tier_create_free(price_tier_create_t *price_tier_create);

price_tier_create_t *price_tier_create_parseFromJSON(cJSON *price_tier_createJSON);

cJSON *price_tier_create_convertToJSON(price_tier_create_t *price_tier_create);

#endif /* _price_tier_create_H_ */

