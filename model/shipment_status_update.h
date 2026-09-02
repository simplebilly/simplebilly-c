/*
 * shipment_status_update.h
 *
 * 
 */

#ifndef _shipment_status_update_H_
#define _shipment_status_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shipment_status_update_t shipment_status_update_t;




typedef struct shipment_status_update_t {
    char *delivered_at; // string
    char *signed_by; // string
    char *status; // string
    char *tracking_number; // string

    int _library_owned; // Is the library responsible for freeing this object?
} shipment_status_update_t;

__attribute__((deprecated)) shipment_status_update_t *shipment_status_update_create(
    char *delivered_at,
    char *signed_by,
    char *status,
    char *tracking_number
);

void shipment_status_update_free(shipment_status_update_t *shipment_status_update);

shipment_status_update_t *shipment_status_update_parseFromJSON(cJSON *shipment_status_updateJSON);

cJSON *shipment_status_update_convertToJSON(shipment_status_update_t *shipment_status_update);

#endif /* _shipment_status_update_H_ */

