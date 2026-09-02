/*
 * rfq_status_update.h
 *
 * 
 */

#ifndef _rfq_status_update_H_
#define _rfq_status_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct rfq_status_update_t rfq_status_update_t;




typedef struct rfq_status_update_t {
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} rfq_status_update_t;

__attribute__((deprecated)) rfq_status_update_t *rfq_status_update_create(
    char *status
);

void rfq_status_update_free(rfq_status_update_t *rfq_status_update);

rfq_status_update_t *rfq_status_update_parseFromJSON(cJSON *rfq_status_updateJSON);

cJSON *rfq_status_update_convertToJSON(rfq_status_update_t *rfq_status_update);

#endif /* _rfq_status_update_H_ */

