/*
 * suitability_request.h
 *
 * 
 */

#ifndef _suitability_request_H_
#define _suitability_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct suitability_request_t suitability_request_t;

#include "address.h"
#include "cart_item_input.h"



typedef struct suitability_request_t {
    int *customer_annual_volume; //numeric
    list_t *items; //nonprimitive container
    struct address_t *recipient; //model
    struct address_t *sender; //model

    int _library_owned; // Is the library responsible for freeing this object?
} suitability_request_t;

__attribute__((deprecated)) suitability_request_t *suitability_request_create(
    int *customer_annual_volume,
    list_t *items,
    address_t *recipient,
    address_t *sender
);

void suitability_request_free(suitability_request_t *suitability_request);

suitability_request_t *suitability_request_parseFromJSON(cJSON *suitability_requestJSON);

cJSON *suitability_request_convertToJSON(suitability_request_t *suitability_request);

#endif /* _suitability_request_H_ */

