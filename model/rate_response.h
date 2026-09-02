/*
 * rate_response.h
 *
 * 
 */

#ifndef _rate_response_H_
#define _rate_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct rate_response_t rate_response_t;

#include "shipping_rate.h"



typedef struct rate_response_t {
    list_t *rates; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} rate_response_t;

__attribute__((deprecated)) rate_response_t *rate_response_create(
    list_t *rates
);

void rate_response_free(rate_response_t *rate_response);

rate_response_t *rate_response_parseFromJSON(cJSON *rate_responseJSON);

cJSON *rate_response_convertToJSON(rate_response_t *rate_response);

#endif /* _rate_response_H_ */

