/*
 * lead.h
 *
 * 
 */

#ifndef _lead_H_
#define _lead_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lead_t lead_t;

#include "any_type.h"
#include "lead_status.h"



typedef struct lead_t {
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
    simplebilly_api_lead_status__e status; //referenced enum
    any_type_t *tags; // custom
    char *tenant_id; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} lead_t;

__attribute__((deprecated)) lead_t *lead_create(
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
    simplebilly_api_lead_status__e status,
    any_type_t *tags,
    char *tenant_id,
    char *updated_at
);

void lead_free(lead_t *lead);

lead_t *lead_parseFromJSON(cJSON *leadJSON);

cJSON *lead_convertToJSON(lead_t *lead);

#endif /* _lead_H_ */

