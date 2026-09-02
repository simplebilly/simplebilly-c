/*
 * rfq_create.h
 *
 * 
 */

#ifndef _rfq_create_H_
#define _rfq_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct rfq_create_t rfq_create_t;

#include "any_type.h"
#include "rfq_status.h"



typedef struct rfq_create_t {
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
} rfq_create_t;

__attribute__((deprecated)) rfq_create_t *rfq_create_create(
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

void rfq_create_free(rfq_create_t *rfq_create);

rfq_create_t *rfq_create_parseFromJSON(cJSON *rfq_createJSON);

cJSON *rfq_create_convertToJSON(rfq_create_t *rfq_create);

#endif /* _rfq_create_H_ */

