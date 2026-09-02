/*
 * coupon_validation.h
 *
 * 
 */

#ifndef _coupon_validation_H_
#define _coupon_validation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct coupon_validation_t coupon_validation_t;




typedef struct coupon_validation_t {
    char *code; // string
    char *discount_type; // string
    char *discount_value; // string
    char *discounted_amount; // string
    char *max_discount_amount; // string
    char *reason; // string
    int *valid; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} coupon_validation_t;

__attribute__((deprecated)) coupon_validation_t *coupon_validation_create(
    char *code,
    char *discount_type,
    char *discount_value,
    char *discounted_amount,
    char *max_discount_amount,
    char *reason,
    int *valid
);

void coupon_validation_free(coupon_validation_t *coupon_validation);

coupon_validation_t *coupon_validation_parseFromJSON(cJSON *coupon_validationJSON);

cJSON *coupon_validation_convertToJSON(coupon_validation_t *coupon_validation);

#endif /* _coupon_validation_H_ */

