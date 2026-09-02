/*
 * deliverable_response.h
 *
 * 
 */

#ifndef _deliverable_response_H_
#define _deliverable_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct deliverable_response_t deliverable_response_t;




typedef struct deliverable_response_t {
    long *available_stock; //numeric
    long *deliverable_quantity; //numeric
    long *max_sellable; //numeric
    char *product_id; // string
    long *reserved_stock; //numeric
    char *warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} deliverable_response_t;

__attribute__((deprecated)) deliverable_response_t *deliverable_response_create(
    long *available_stock,
    long *deliverable_quantity,
    long *max_sellable,
    char *product_id,
    long *reserved_stock,
    char *warehouse_id
);

void deliverable_response_free(deliverable_response_t *deliverable_response);

deliverable_response_t *deliverable_response_parseFromJSON(cJSON *deliverable_responseJSON);

cJSON *deliverable_response_convertToJSON(deliverable_response_t *deliverable_response);

#endif /* _deliverable_response_H_ */

