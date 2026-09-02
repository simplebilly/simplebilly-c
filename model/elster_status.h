/*
 * elster_status.h
 *
 * 
 */

#ifndef _elster_status_H_
#define _elster_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct elster_status_t elster_status_t;




typedef struct elster_status_t {
    int *cert_configured; //boolean
    int *eric_available; //boolean
    char *eric_version; // string
    int *feature_enabled; //boolean
    char *hint; // string
    char *mode; // string
    int *vendor_id_configured; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} elster_status_t;

__attribute__((deprecated)) elster_status_t *elster_status_create(
    int *cert_configured,
    int *eric_available,
    char *eric_version,
    int *feature_enabled,
    char *hint,
    char *mode,
    int *vendor_id_configured
);

void elster_status_free(elster_status_t *elster_status);

elster_status_t *elster_status_parseFromJSON(cJSON *elster_statusJSON);

cJSON *elster_status_convertToJSON(elster_status_t *elster_status);

#endif /* _elster_status_H_ */

