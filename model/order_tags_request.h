/*
 * order_tags_request.h
 *
 * 
 */

#ifndef _order_tags_request_H_
#define _order_tags_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct order_tags_request_t order_tags_request_t;




typedef struct order_tags_request_t {
    list_t *tags; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} order_tags_request_t;

__attribute__((deprecated)) order_tags_request_t *order_tags_request_create(
    list_t *tags
);

void order_tags_request_free(order_tags_request_t *order_tags_request);

order_tags_request_t *order_tags_request_parseFromJSON(cJSON *order_tags_requestJSON);

cJSON *order_tags_request_convertToJSON(order_tags_request_t *order_tags_request);

#endif /* _order_tags_request_H_ */

