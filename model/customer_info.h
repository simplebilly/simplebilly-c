/*
 * customer_info.h
 *
 * Additional information about the customer placing the shipment.
 */

#ifndef _customer_info_H_
#define _customer_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct customer_info_t customer_info_t;




typedef struct customer_info_t {
    int *annual_volume; //numeric
    int *is_registered; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} customer_info_t;

__attribute__((deprecated)) customer_info_t *customer_info_create(
    int *annual_volume,
    int *is_registered
);

void customer_info_free(customer_info_t *customer_info);

customer_info_t *customer_info_parseFromJSON(cJSON *customer_infoJSON);

cJSON *customer_info_convertToJSON(customer_info_t *customer_info);

#endif /* _customer_info_H_ */

