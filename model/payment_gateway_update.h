/*
 * payment_gateway_update.h
 *
 * 
 */

#ifndef _payment_gateway_update_H_
#define _payment_gateway_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payment_gateway_update_t payment_gateway_update_t;

#include "any_type.h"
#include "gateway_type.h"



typedef struct payment_gateway_update_t {
    any_type_t *config; // custom
    char *created_at; //date time
    char *deleted_at; //date time
    int *enabled; //boolean
    gateway_type_t *gateway_type; // custom
    char *label; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} payment_gateway_update_t;

__attribute__((deprecated)) payment_gateway_update_t *payment_gateway_update_create(
    any_type_t *config,
    char *created_at,
    char *deleted_at,
    int *enabled,
    gateway_type_t *gateway_type,
    char *label,
    char *updated_at
);

void payment_gateway_update_free(payment_gateway_update_t *payment_gateway_update);

payment_gateway_update_t *payment_gateway_update_parseFromJSON(cJSON *payment_gateway_updateJSON);

cJSON *payment_gateway_update_convertToJSON(payment_gateway_update_t *payment_gateway_update);

#endif /* _payment_gateway_update_H_ */

