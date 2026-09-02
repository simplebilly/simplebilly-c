/*
 * update_role_payload.h
 *
 * 
 */

#ifndef _update_role_payload_H_
#define _update_role_payload_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_role_payload_t update_role_payload_t;




typedef struct update_role_payload_t {
    char *role; // string
    int *sync_permissions; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} update_role_payload_t;

__attribute__((deprecated)) update_role_payload_t *update_role_payload_create(
    char *role,
    int *sync_permissions
);

void update_role_payload_free(update_role_payload_t *update_role_payload);

update_role_payload_t *update_role_payload_parseFromJSON(cJSON *update_role_payloadJSON);

cJSON *update_role_payload_convertToJSON(update_role_payload_t *update_role_payload);

#endif /* _update_role_payload_H_ */

