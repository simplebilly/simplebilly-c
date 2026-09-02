/*
 * payment_gateway_create.h
 *
 * 
 */

#ifndef _payment_gateway_create_H_
#define _payment_gateway_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payment_gateway_create_t payment_gateway_create_t;

#include "any_type.h"
#include "gateway_type.h"



typedef struct payment_gateway_create_t {
    any_type_t *config; // custom
    char *created_at; //date time
    char *deleted_at; //date time
    int *enabled; //boolean
    simplebilly_api_gateway_type__e gateway_type; //referenced enum
    char *label; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} payment_gateway_create_t;

__attribute__((deprecated)) payment_gateway_create_t *payment_gateway_create_create(
    any_type_t *config,
    char *created_at,
    char *deleted_at,
    int *enabled,
    simplebilly_api_gateway_type__e gateway_type,
    char *label,
    char *updated_at
);

void payment_gateway_create_free(payment_gateway_create_t *payment_gateway_create);

payment_gateway_create_t *payment_gateway_create_parseFromJSON(cJSON *payment_gateway_createJSON);

cJSON *payment_gateway_create_convertToJSON(payment_gateway_create_t *payment_gateway_create);

#endif /* _payment_gateway_create_H_ */

