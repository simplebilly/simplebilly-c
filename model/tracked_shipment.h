/*
 * tracked_shipment.h
 *
 * 
 */

#ifndef _tracked_shipment_H_
#define _tracked_shipment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct tracked_shipment_t tracked_shipment_t;

#include "tracking_event.h"



typedef struct tracked_shipment_t {
    char *carrier; // string
    list_t *events; //nonprimitive container
    char *label_url; // string
    char *status; // string
    char *tracking_number; // string
    char *tracking_url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} tracked_shipment_t;

__attribute__((deprecated)) tracked_shipment_t *tracked_shipment_create(
    char *carrier,
    list_t *events,
    char *label_url,
    char *status,
    char *tracking_number,
    char *tracking_url
);

void tracked_shipment_free(tracked_shipment_t *tracked_shipment);

tracked_shipment_t *tracked_shipment_parseFromJSON(cJSON *tracked_shipmentJSON);

cJSON *tracked_shipment_convertToJSON(tracked_shipment_t *tracked_shipment);

#endif /* _tracked_shipment_H_ */

