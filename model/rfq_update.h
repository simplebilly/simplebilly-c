/*
 * rfq_update.h
 *
 * 
 */

#ifndef _rfq_update_H_
#define _rfq_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct rfq_update_t rfq_update_t;

#include "any_type.h"
#include "rfq_status.h"



typedef struct rfq_update_t {
    char *currency; // string
    any_type_t *line_items; // custom
    char *notes; // string
    char *requested_date; //date
    char *response_date; //date
    char *rfq_number; // string
    rfq_status_t *status; // custom
    char *supplier_contact_id; // string
    char *supplier_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} rfq_update_t;

__attribute__((deprecated)) rfq_update_t *rfq_update_create(
    char *currency,
    any_type_t *line_items,
    char *notes,
    char *requested_date,
    char *response_date,
    char *rfq_number,
    rfq_status_t *status,
    char *supplier_contact_id,
    char *supplier_name
);

void rfq_update_free(rfq_update_t *rfq_update);

rfq_update_t *rfq_update_parseFromJSON(cJSON *rfq_updateJSON);

cJSON *rfq_update_convertToJSON(rfq_update_t *rfq_update);

#endif /* _rfq_update_H_ */

