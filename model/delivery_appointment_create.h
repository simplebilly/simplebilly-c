/*
 * delivery_appointment_create.h
 *
 * 
 */

#ifndef _delivery_appointment_create_H_
#define _delivery_appointment_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delivery_appointment_create_t delivery_appointment_create_t;

#include "delivery_appointment_status.h"



typedef struct delivery_appointment_create_t {
    char *email; // string
    char *notes; // string
    char *phone; // string
    char *requested_date; //date
    delivery_appointment_status_t *status; // custom
    char *supplier_name; // string
    char *time_slot; // string
    char *warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} delivery_appointment_create_t;

__attribute__((deprecated)) delivery_appointment_create_t *delivery_appointment_create_create(
    char *email,
    char *notes,
    char *phone,
    char *requested_date,
    delivery_appointment_status_t *status,
    char *supplier_name,
    char *time_slot,
    char *warehouse_id
);

void delivery_appointment_create_free(delivery_appointment_create_t *delivery_appointment_create);

delivery_appointment_create_t *delivery_appointment_create_parseFromJSON(cJSON *delivery_appointment_createJSON);

cJSON *delivery_appointment_create_convertToJSON(delivery_appointment_create_t *delivery_appointment_create);

#endif /* _delivery_appointment_create_H_ */

