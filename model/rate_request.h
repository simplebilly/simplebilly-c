/*
 * rate_request.h
 *
 * 
 */

#ifndef _rate_request_H_
#define _rate_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct rate_request_t rate_request_t;

#include "address.h"
#include "customer_info.h"
#include "package.h"



typedef struct rate_request_t {
    struct customer_info_t *customer; //model
    list_t *packages; //nonprimitive container
    struct address_t *recipient; //model
    struct address_t *sender; //model

    int _library_owned; // Is the library responsible for freeing this object?
} rate_request_t;

__attribute__((deprecated)) rate_request_t *rate_request_create(
    customer_info_t *customer,
    list_t *packages,
    address_t *recipient,
    address_t *sender
);

void rate_request_free(rate_request_t *rate_request);

rate_request_t *rate_request_parseFromJSON(cJSON *rate_requestJSON);

cJSON *rate_request_convertToJSON(rate_request_t *rate_request);

#endif /* _rate_request_H_ */

