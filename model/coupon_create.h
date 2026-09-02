/*
 * coupon_create.h
 *
 * 
 */

#ifndef _coupon_create_H_
#define _coupon_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct coupon_create_t coupon_create_t;

#include "any_type.h"
#include "discount_type.h"



typedef struct coupon_create_t {
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
} coupon_create_t;

__attribute__((deprecated)) coupon_create_t *coupon_create_create(
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

void coupon_create_free(coupon_create_t *coupon_create);

coupon_create_t *coupon_create_parseFromJSON(cJSON *coupon_createJSON);

cJSON *coupon_create_convertToJSON(coupon_create_t *coupon_create);

#endif /* _coupon_create_H_ */

