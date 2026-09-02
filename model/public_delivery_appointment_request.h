/*
 * public_delivery_appointment_request.h
 *
 * 
 */

#ifndef _public_delivery_appointment_request_H_
#define _public_delivery_appointment_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct public_delivery_appointment_request_t public_delivery_appointment_request_t;




typedef struct public_delivery_appointment_request_t {
    char *email; // string
    char *notes; // string
    char *requested_date; //date
    char *supplier_name; // string
    char *time_slot; // string
    char *warehouse_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} public_delivery_appointment_request_t;

__attribute__((deprecated)) public_delivery_appointment_request_t *public_delivery_appointment_request_create(
    char *email,
    char *notes,
    char *requested_date,
    char *supplier_name,
    char *time_slot,
    char *warehouse_code
);

void public_delivery_appointment_request_free(public_delivery_appointment_request_t *public_delivery_appointment_request);

public_delivery_appointment_request_t *public_delivery_appointment_request_parseFromJSON(cJSON *public_delivery_appointment_requestJSON);

cJSON *public_delivery_appointment_request_convertToJSON(public_delivery_appointment_request_t *public_delivery_appointment_request);

#endif /* _public_delivery_appointment_request_H_ */

