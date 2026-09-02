/*
 * price_tier_update.h
 *
 * 
 */

#ifndef _price_tier_update_H_
#define _price_tier_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct price_tier_update_t price_tier_update_t;




typedef struct price_tier_update_t {
    char *customer_group_id; // string
    long *min_quantity; //numeric
    char *product_id; // string
    char *unit_price; // string

    int _library_owned; // Is the library responsible for freeing this object?
} price_tier_update_t;

__attribute__((deprecated)) price_tier_update_t *price_tier_update_create(
    char *customer_group_id,
    long *min_quantity,
    char *product_id,
    char *unit_price
);

void price_tier_update_free(price_tier_update_t *price_tier_update);

price_tier_update_t *price_tier_update_parseFromJSON(cJSON *price_tier_updateJSON);

cJSON *price_tier_update_convertToJSON(price_tier_update_t *price_tier_update);

#endif /* _price_tier_update_H_ */

