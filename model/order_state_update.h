/*
 * order_state_update.h
 *
 * 
 */

#ifndef _order_state_update_H_
#define _order_state_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct order_state_update_t order_state_update_t;




typedef struct order_state_update_t {
    int *send_state_to_shop; //boolean
    char *state; // string

    int _library_owned; // Is the library responsible for freeing this object?
} order_state_update_t;

__attribute__((deprecated)) order_state_update_t *order_state_update_create(
    int *send_state_to_shop,
    char *state
);

void order_state_update_free(order_state_update_t *order_state_update);

order_state_update_t *order_state_update_parseFromJSON(cJSON *order_state_updateJSON);

cJSON *order_state_update_convertToJSON(order_state_update_t *order_state_update);

#endif /* _order_state_update_H_ */

