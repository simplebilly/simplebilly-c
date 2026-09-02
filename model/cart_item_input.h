/*
 * cart_item_input.h
 *
 * 
 */

#ifndef _cart_item_input_H_
#define _cart_item_input_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cart_item_input_t cart_item_input_t;




typedef struct cart_item_input_t {
    char *product_id; // string
    int *quantity; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} cart_item_input_t;

__attribute__((deprecated)) cart_item_input_t *cart_item_input_create(
    char *product_id,
    int *quantity
);

void cart_item_input_free(cart_item_input_t *cart_item_input);

cart_item_input_t *cart_item_input_parseFromJSON(cJSON *cart_item_inputJSON);

cJSON *cart_item_input_convertToJSON(cart_item_input_t *cart_item_input);

#endif /* _cart_item_input_H_ */

