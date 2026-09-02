/*
 * track_order_request.h
 *
 * Refresh tracking for a shipment from the live carrier API and store the latest status + events on the shipment row.
 */

#ifndef _track_order_request_H_
#define _track_order_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct track_order_request_t track_order_request_t;




typedef struct track_order_request_t {
    char *email; // string
    char *order_number; // string

    int _library_owned; // Is the library responsible for freeing this object?
} track_order_request_t;

__attribute__((deprecated)) track_order_request_t *track_order_request_create(
    char *email,
    char *order_number
);

void track_order_request_free(track_order_request_t *track_order_request);

track_order_request_t *track_order_request_parseFromJSON(cJSON *track_order_requestJSON);

cJSON *track_order_request_convertToJSON(track_order_request_t *track_order_request);

#endif /* _track_order_request_H_ */

