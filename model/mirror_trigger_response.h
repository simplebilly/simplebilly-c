/*
 * mirror_trigger_response.h
 *
 * 
 */

#ifndef _mirror_trigger_response_H_
#define _mirror_trigger_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct mirror_trigger_response_t mirror_trigger_response_t;




typedef struct mirror_trigger_response_t {
    char *job_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} mirror_trigger_response_t;

__attribute__((deprecated)) mirror_trigger_response_t *mirror_trigger_response_create(
    char *job_id
);

void mirror_trigger_response_free(mirror_trigger_response_t *mirror_trigger_response);

mirror_trigger_response_t *mirror_trigger_response_parseFromJSON(cJSON *mirror_trigger_responseJSON);

cJSON *mirror_trigger_response_convertToJSON(mirror_trigger_response_t *mirror_trigger_response);

#endif /* _mirror_trigger_response_H_ */

