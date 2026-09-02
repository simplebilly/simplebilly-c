/*
 * coupon.h
 *
 * 
 */

#ifndef _coupon_H_
#define _coupon_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct coupon_t coupon_t;

#include "any_type.h"
#include "discount_type.h"



typedef struct coupon_t {
    char *code; // string
    char *description; // string
    simplebilly_api_discount_type__e discount_type; //referenced enum
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
} coupon_t;

__attribute__((deprecated)) coupon_t *coupon_create(
    char *code,
    char *description,
    simplebilly_api_discount_type__e discount_type,
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

void coupon_free(coupon_t *coupon);

coupon_t *coupon_parseFromJSON(cJSON *couponJSON);

cJSON *coupon_convertToJSON(coupon_t *coupon);

#endif /* _coupon_H_ */

