/*
 * public_delivery_appointment_status_response.h
 *
 * 
 */

#ifndef _public_delivery_appointment_status_response_H_
#define _public_delivery_appointment_status_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct public_delivery_appointment_status_response_t public_delivery_appointment_status_response_t;




typedef struct public_delivery_appointment_status_response_t {
    char *appointment_id; // string
    char *requested_date; //date
    char *status; // string
    char *time_slot; // string
    char *warehouse_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} public_delivery_appointment_status_response_t;

__attribute__((deprecated)) public_delivery_appointment_status_response_t *public_delivery_appointment_status_response_create(
    char *appointment_id,
    char *requested_date,
    char *status,
    char *time_slot,
    char *warehouse_name
);

void public_delivery_appointment_status_response_free(public_delivery_appointment_status_response_t *public_delivery_appointment_status_response);

public_delivery_appointment_status_response_t *public_delivery_appointment_status_response_parseFromJSON(cJSON *public_delivery_appointment_status_responseJSON);

cJSON *public_delivery_appointment_status_response_convertToJSON(public_delivery_appointment_status_response_t *public_delivery_appointment_status_response);

#endif /* _public_delivery_appointment_status_response_H_ */

