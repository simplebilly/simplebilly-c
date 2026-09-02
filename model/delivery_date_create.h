/*
 * delivery_date_create.h
 *
 * 
 */

#ifndef _delivery_date_create_H_
#define _delivery_date_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delivery_date_create_t delivery_date_create_t;

#include "delivery_date_status.h"



typedef struct delivery_date_create_t {
    char *customer_id; // string
    char *fulfilled_date; //date
    char *note; // string
    char *order_number; // string
    char *original_date; //date
    char *product_id; // string
    char *promised_date; //date
    delivery_date_status_t *status; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} delivery_date_create_t;

__attribute__((deprecated)) delivery_date_create_t *delivery_date_create_create(
    char *customer_id,
    char *fulfilled_date,
    char *note,
    char *order_number,
    char *original_date,
    char *product_id,
    char *promised_date,
    delivery_date_status_t *status
);

void delivery_date_create_free(delivery_date_create_t *delivery_date_create);

delivery_date_create_t *delivery_date_create_parseFromJSON(cJSON *delivery_date_createJSON);

cJSON *delivery_date_create_convertToJSON(delivery_date_create_t *delivery_date_create);

#endif /* _delivery_date_create_H_ */

