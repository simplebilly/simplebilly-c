/*
 * create_shipment_request.h
 *
 * 
 */

#ifndef _create_shipment_request_H_
#define _create_shipment_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_shipment_request_t create_shipment_request_t;




typedef struct create_shipment_request_t {
    char *carrier; // string
    char *service; // string
    double *weight_kg; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} create_shipment_request_t;

__attribute__((deprecated)) create_shipment_request_t *create_shipment_request_create(
    char *carrier,
    char *service,
    double *weight_kg
);

void create_shipment_request_free(create_shipment_request_t *create_shipment_request);

create_shipment_request_t *create_shipment_request_parseFromJSON(cJSON *create_shipment_requestJSON);

cJSON *create_shipment_request_convertToJSON(create_shipment_request_t *create_shipment_request);

#endif /* _create_shipment_request_H_ */

