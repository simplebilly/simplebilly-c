/*
 * lead_update.h
 *
 * 
 */

#ifndef _lead_update_H_
#define _lead_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lead_update_t lead_update_t;

#include "any_type.h"
#include "lead_status.h"



typedef struct lead_update_t {
    char *company; // string
    char *converted_at; //date time
    char *created_at; //date time
    char *email; // string
    char *first_contact_at; //date time
    char *name; // string
    char *notes; // string
    char *phone; // string
    int *score; //numeric
    char *source; // string
    lead_status_t *status; // custom
    any_type_t *tags; // custom
    char *tenant_id; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} lead_update_t;

__attribute__((deprecated)) lead_update_t *lead_update_create(
    char *company,
    char *converted_at,
    char *created_at,
    char *email,
    char *first_contact_at,
    char *name,
    char *notes,
    char *phone,
    int *score,
    char *source,
    lead_status_t *status,
    any_type_t *tags,
    char *tenant_id,
    char *updated_at
);

void lead_update_free(lead_update_t *lead_update);

lead_update_t *lead_update_parseFromJSON(cJSON *lead_updateJSON);

cJSON *lead_update_convertToJSON(lead_update_t *lead_update);

#endif /* _lead_update_H_ */

