/*
 * stock_update_request.h
 *
 * 
 */

#ifndef _stock_update_request_H_
#define _stock_update_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stock_update_request_t stock_update_request_t;




typedef struct stock_update_request_t {
    long *quantity; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} stock_update_request_t;

__attribute__((deprecated)) stock_update_request_t *stock_update_request_create(
    long *quantity
);

void stock_update_request_free(stock_update_request_t *stock_update_request);

stock_update_request_t *stock_update_request_parseFromJSON(cJSON *stock_update_requestJSON);

cJSON *stock_update_request_convertToJSON(stock_update_request_t *stock_update_request);

#endif /* _stock_update_request_H_ */

