/*
 * dpa_status.h
 *
 * DPA acceptance status of the tenant.
 */

#ifndef _dpa_status_H_
#define _dpa_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct dpa_status_t dpa_status_t;




typedef struct dpa_status_t {
    int *accepted; //boolean
    char *accepted_at; // string
    char *accepted_by; // string
    char *version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} dpa_status_t;

__attribute__((deprecated)) dpa_status_t *dpa_status_create(
    int *accepted,
    char *accepted_at,
    char *accepted_by,
    char *version
);

void dpa_status_free(dpa_status_t *dpa_status);

dpa_status_t *dpa_status_parseFromJSON(cJSON *dpa_statusJSON);

cJSON *dpa_status_convertToJSON(dpa_status_t *dpa_status);

#endif /* _dpa_status_H_ */

