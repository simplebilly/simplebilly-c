/*
 * public_return_request.h
 *
 * 
 */

#ifndef _public_return_request_H_
#define _public_return_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct public_return_request_t public_return_request_t;

#include "public_return_item.h"



typedef struct public_return_request_t {
    char *email; // string
    list_t *items; //nonprimitive container
    char *notes; // string
    char *order_number; // string

    int _library_owned; // Is the library responsible for freeing this object?
} public_return_request_t;

__attribute__((deprecated)) public_return_request_t *public_return_request_create(
    char *email,
    list_t *items,
    char *notes,
    char *order_number
);

void public_return_request_free(public_return_request_t *public_return_request);

public_return_request_t *public_return_request_parseFromJSON(cJSON *public_return_requestJSON);

cJSON *public_return_request_convertToJSON(public_return_request_t *public_return_request);

#endif /* _public_return_request_H_ */

