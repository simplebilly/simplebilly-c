/*
 * shipment.h
 *
 * 
 */

#ifndef _shipment_H_
#define _shipment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shipment_t shipment_t;

#include "any_type.h"



typedef struct shipment_t {
    char *delivered_at; //date time
    char *label_url; // string
    any_type_t *line_items_shipment; // custom
    char *order_id; // string
    any_type_t *recipient_address; // custom
    char *shipment_date; //date
    char *shipping_carrier; // string
    char *shipping_cost; // string
    char *shipping_method; // string
    char *signed_by; // string
    char *status; // string
    any_type_t *tracking_events; // custom
    char *tracking_number; // string
    char *tracking_url; // string
    double *weight_kg; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} shipment_t;

__attribute__((deprecated)) shipment_t *shipment_create(
    char *delivered_at,
    char *label_url,
    any_type_t *line_items_shipment,
    char *order_id,
    any_type_t *recipient_address,
    char *shipment_date,
    char *shipping_carrier,
    char *shipping_cost,
    char *shipping_method,
    char *signed_by,
    char *status,
    any_type_t *tracking_events,
    char *tracking_number,
    char *tracking_url,
    double *weight_kg
);

void shipment_free(shipment_t *shipment);

shipment_t *shipment_parseFromJSON(cJSON *shipmentJSON);

cJSON *shipment_convertToJSON(shipment_t *shipment);

#endif /* _shipment_H_ */

