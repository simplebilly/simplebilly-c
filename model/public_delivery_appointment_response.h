/*
 * public_delivery_appointment_response.h
 *
 * 
 */

#ifndef _public_delivery_appointment_response_H_
#define _public_delivery_appointment_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct public_delivery_appointment_response_t public_delivery_appointment_response_t;




typedef struct public_delivery_appointment_response_t {
    char *appointment_id; // string
    char *confirmation_hint; // string
    char *message; // string
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} public_delivery_appointment_response_t;

__attribute__((deprecated)) public_delivery_appointment_response_t *public_delivery_appointment_response_create(
    char *appointment_id,
    char *confirmation_hint,
    char *message,
    char *status
);

void public_delivery_appointment_response_free(public_delivery_appointment_response_t *public_delivery_appointment_response);

public_delivery_appointment_response_t *public_delivery_appointment_response_parseFromJSON(cJSON *public_delivery_appointment_responseJSON);

cJSON *public_delivery_appointment_response_convertToJSON(public_delivery_appointment_response_t *public_delivery_appointment_response);

#endif /* _public_delivery_appointment_response_H_ */

