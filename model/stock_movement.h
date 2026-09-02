/*
 * stock_movement.h
 *
 * 
 */

#ifndef _stock_movement_H_
#define _stock_movement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stock_movement_t stock_movement_t;

#include "movement_type.h"
#include "reference_type.h"



typedef struct stock_movement_t {
    long *delta; //numeric
    movement_type_t *movement_type; // custom
    char *product_id; // string
    long *quantity; //numeric
    char *reason; // string
    char *reference_id; // string
    reference_type_t *reference_type; // custom
    char *warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} stock_movement_t;

__attribute__((deprecated)) stock_movement_t *stock_movement_create(
    long *delta,
    movement_type_t *movement_type,
    char *product_id,
    long *quantity,
    char *reason,
    char *reference_id,
    reference_type_t *reference_type,
    char *warehouse_id
);

void stock_movement_free(stock_movement_t *stock_movement);

stock_movement_t *stock_movement_parseFromJSON(cJSON *stock_movementJSON);

cJSON *stock_movement_convertToJSON(stock_movement_t *stock_movement);

#endif /* _stock_movement_H_ */

