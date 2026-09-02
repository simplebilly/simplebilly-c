/*
 * shipping_threshold_create.h
 *
 * 
 */

#ifndef _shipping_threshold_create_H_
#define _shipping_threshold_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shipping_threshold_create_t shipping_threshold_create_t;




typedef struct shipping_threshold_create_t {
    int *is_active; //boolean
    long *max_sellable; //numeric
    char *name; // string
    char *notes; // string
    char *product_id; // string
    long *reserve_stock; //numeric
    char *warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} shipping_threshold_create_t;

__attribute__((deprecated)) shipping_threshold_create_t *shipping_threshold_create_create(
    int *is_active,
    long *max_sellable,
    char *name,
    char *notes,
    char *product_id,
    long *reserve_stock,
    char *warehouse_id
);

void shipping_threshold_create_free(shipping_threshold_create_t *shipping_threshold_create);

shipping_threshold_create_t *shipping_threshold_create_parseFromJSON(cJSON *shipping_threshold_createJSON);

cJSON *shipping_threshold_create_convertToJSON(shipping_threshold_create_t *shipping_threshold_create);

#endif /* _shipping_threshold_create_H_ */

