/*
 * dpa_accept_request.h
 *
 * Request body to record DPA acceptance (&#x60;PUT /api/v1/gdpr/dpa&#x60;).
 */

#ifndef _dpa_accept_request_H_
#define _dpa_accept_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct dpa_accept_request_t dpa_accept_request_t;




typedef struct dpa_accept_request_t {
    char *accepted_by_name; // string
    char *version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} dpa_accept_request_t;

__attribute__((deprecated)) dpa_accept_request_t *dpa_accept_request_create(
    char *accepted_by_name,
    char *version
);

void dpa_accept_request_free(dpa_accept_request_t *dpa_accept_request);

dpa_accept_request_t *dpa_accept_request_parseFromJSON(cJSON *dpa_accept_requestJSON);

cJSON *dpa_accept_request_convertToJSON(dpa_accept_request_t *dpa_accept_request);

#endif /* _dpa_accept_request_H_ */

