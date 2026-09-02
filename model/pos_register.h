/*
 * pos_register.h
 *
 * A point-of-sale register (Kasse). Registers are the billable unit of the POS feature: each active register costs a monthly fee per tenant, billed through Paddle. &#x60;status&#x60;: &#x60;active&#x60; | &#x60;disabled&#x60;.
 */

#ifndef _pos_register_H_
#define _pos_register_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pos_register_t pos_register_t;

#include "pos_register_status.h"



typedef struct pos_register_t {
    char *name; // string
    simplebilly_api_pos_register_status__e status; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} pos_register_t;

__attribute__((deprecated)) pos_register_t *pos_register_create(
    char *name,
    simplebilly_api_pos_register_status__e status
);

void pos_register_free(pos_register_t *pos_register);

pos_register_t *pos_register_parseFromJSON(cJSON *pos_registerJSON);

cJSON *pos_register_convertToJSON(pos_register_t *pos_register);

#endif /* _pos_register_H_ */

