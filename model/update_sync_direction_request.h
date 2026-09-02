/*
 * update_sync_direction_request.h
 *
 * 
 */

#ifndef _update_sync_direction_request_H_
#define _update_sync_direction_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_sync_direction_request_t update_sync_direction_request_t;




typedef struct update_sync_direction_request_t {
    list_t* directions; //map

    int _library_owned; // Is the library responsible for freeing this object?
} update_sync_direction_request_t;

__attribute__((deprecated)) update_sync_direction_request_t *update_sync_direction_request_create(
    list_t* directions
);

void update_sync_direction_request_free(update_sync_direction_request_t *update_sync_direction_request);

update_sync_direction_request_t *update_sync_direction_request_parseFromJSON(cJSON *update_sync_direction_requestJSON);

cJSON *update_sync_direction_request_convertToJSON(update_sync_direction_request_t *update_sync_direction_request);

#endif /* _update_sync_direction_request_H_ */

