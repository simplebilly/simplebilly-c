/*
 * track_order_response.h
 *
 * 
 */

#ifndef _track_order_response_H_
#define _track_order_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct track_order_response_t track_order_response_t;

#include "tracked_shipment.h"



typedef struct track_order_response_t {
    char *order_number; // string
    char *order_status; // string
    list_t *shipments; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} track_order_response_t;

__attribute__((deprecated)) track_order_response_t *track_order_response_create(
    char *order_number,
    char *order_status,
    list_t *shipments
);

void track_order_response_free(track_order_response_t *track_order_response);

track_order_response_t *track_order_response_parseFromJSON(cJSON *track_order_responseJSON);

cJSON *track_order_response_convertToJSON(track_order_response_t *track_order_response);

#endif /* _track_order_response_H_ */

