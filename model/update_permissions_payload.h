/*
 * update_permissions_payload.h
 *
 * 
 */

#ifndef _update_permissions_payload_H_
#define _update_permissions_payload_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_permissions_payload_t update_permissions_payload_t;




typedef struct update_permissions_payload_t {
    list_t *permissions; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} update_permissions_payload_t;

__attribute__((deprecated)) update_permissions_payload_t *update_permissions_payload_create(
    list_t *permissions
);

void update_permissions_payload_free(update_permissions_payload_t *update_permissions_payload);

update_permissions_payload_t *update_permissions_payload_parseFromJSON(cJSON *update_permissions_payloadJSON);

cJSON *update_permissions_payload_convertToJSON(update_permissions_payload_t *update_permissions_payload);

#endif /* _update_permissions_payload_H_ */

