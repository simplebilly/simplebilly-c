/*
 * replenishment_response.h
 *
 * 
 */

#ifndef _replenishment_response_H_
#define _replenishment_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct replenishment_response_t replenishment_response_t;

#include "replenishment_suggestion_line.h"



typedef struct replenishment_response_t {
    char *generated_at; //date time
    list_t *lines; //nonprimitive container
    char *target_warehouse_id; // string
    long *total_suggested_quantity; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} replenishment_response_t;

__attribute__((deprecated)) replenishment_response_t *replenishment_response_create(
    char *generated_at,
    list_t *lines,
    char *target_warehouse_id,
    long *total_suggested_quantity
);

void replenishment_response_free(replenishment_response_t *replenishment_response);

replenishment_response_t *replenishment_response_parseFromJSON(cJSON *replenishment_responseJSON);

cJSON *replenishment_response_convertToJSON(replenishment_response_t *replenishment_response);

#endif /* _replenishment_response_H_ */

