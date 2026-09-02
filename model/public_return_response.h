/*
 * public_return_response.h
 *
 * 
 */

#ifndef _public_return_response_H_
#define _public_return_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct public_return_response_t public_return_response_t;

#include "any_type.h"



typedef struct public_return_response_t {
    char *created_at; //date time
    any_type_t *items; // custom
    char *notes; // string
    char *order_number; // string
    char *return_number; // string
    char *return_order_id; // string
    char *status; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} public_return_response_t;

__attribute__((deprecated)) public_return_response_t *public_return_response_create(
    char *created_at,
    any_type_t *items,
    char *notes,
    char *order_number,
    char *return_number,
    char *return_order_id,
    char *status,
    char *updated_at
);

void public_return_response_free(public_return_response_t *public_return_response);

public_return_response_t *public_return_response_parseFromJSON(cJSON *public_return_responseJSON);

cJSON *public_return_response_convertToJSON(public_return_response_t *public_return_response);

#endif /* _public_return_response_H_ */

