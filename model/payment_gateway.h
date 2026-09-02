/*
 * payment_gateway.h
 *
 * 
 */

#ifndef _payment_gateway_H_
#define _payment_gateway_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payment_gateway_t payment_gateway_t;

#include "any_type.h"
#include "gateway_type.h"



typedef struct payment_gateway_t {
    any_type_t *config; // custom
    char *created_at; //date time
    char *deleted_at; //date time
    int *enabled; //boolean
    char *gateway_id; // string
    simplebilly_api_gateway_type__e gateway_type; //referenced enum
    char *label; // string
    char *tenant_id; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} payment_gateway_t;

__attribute__((deprecated)) payment_gateway_t *payment_gateway_create(
    any_type_t *config,
    char *created_at,
    char *deleted_at,
    int *enabled,
    char *gateway_id,
    simplebilly_api_gateway_type__e gateway_type,
    char *label,
    char *tenant_id,
    char *updated_at
);

void payment_gateway_free(payment_gateway_t *payment_gateway);

payment_gateway_t *payment_gateway_parseFromJSON(cJSON *payment_gatewayJSON);

cJSON *payment_gateway_convertToJSON(payment_gateway_t *payment_gateway);

#endif /* _payment_gateway_H_ */

