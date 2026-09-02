/*
 * coupon_update.h
 *
 * 
 */

#ifndef _coupon_update_H_
#define _coupon_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct coupon_update_t coupon_update_t;

#include "any_type.h"
#include "discount_type.h"



typedef struct coupon_update_t {
    char *code; // string
    char *description; // string
    discount_type_t *discount_type; // custom
    char *discount_value; // string
    char *expires_at; //date time
    int *is_active; //boolean
    int *is_combineable; //boolean
    char *max_discount_amount; // string
    int *max_uses; //numeric
    int *max_uses_per_customer; //numeric
    char *min_order_amount; // string
    any_type_t *product_ids; // custom
    char *starts_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} coupon_update_t;

__attribute__((deprecated)) coupon_update_t *coupon_update_create(
    char *code,
    char *description,
    discount_type_t *discount_type,
    char *discount_value,
    char *expires_at,
    int *is_active,
    int *is_combineable,
    char *max_discount_amount,
    int *max_uses,
    int *max_uses_per_customer,
    char *min_order_amount,
    any_type_t *product_ids,
    char *starts_at
);

void coupon_update_free(coupon_update_t *coupon_update);

coupon_update_t *coupon_update_parseFromJSON(cJSON *coupon_updateJSON);

cJSON *coupon_update_convertToJSON(coupon_update_t *coupon_update);

#endif /* _coupon_update_H_ */

