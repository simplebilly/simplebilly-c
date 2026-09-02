/*
 * update_profile_request.h
 *
 * 
 */

#ifndef _update_profile_request_H_
#define _update_profile_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_profile_request_t update_profile_request_t;




typedef struct update_profile_request_t {
    char *avatar_url; // string
    char *first_name; // string
    char *last_name; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} update_profile_request_t;

__attribute__((deprecated)) update_profile_request_t *update_profile_request_create(
    char *avatar_url,
    char *first_name,
    char *last_name,
    char *name
);

void update_profile_request_free(update_profile_request_t *update_profile_request);

update_profile_request_t *update_profile_request_parseFromJSON(cJSON *update_profile_requestJSON);

cJSON *update_profile_request_convertToJSON(update_profile_request_t *update_profile_request);

#endif /* _update_profile_request_H_ */

