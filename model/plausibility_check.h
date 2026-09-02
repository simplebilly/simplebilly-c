/*
 * plausibility_check.h
 *
 * 
 */

#ifndef _plausibility_check_H_
#define _plausibility_check_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plausibility_check_t plausibility_check_t;

#include "check_status.h"
#include "severity.h"



typedef struct plausibility_check_t {
    char *detail; // string
    char *id; // string
    char *name; // string
    simplebilly_api_severity__e severity; //referenced enum
    simplebilly_api_check_status__e status; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} plausibility_check_t;

__attribute__((deprecated)) plausibility_check_t *plausibility_check_create(
    char *detail,
    char *id,
    char *name,
    simplebilly_api_severity__e severity,
    simplebilly_api_check_status__e status
);

void plausibility_check_free(plausibility_check_t *plausibility_check);

plausibility_check_t *plausibility_check_parseFromJSON(cJSON *plausibility_checkJSON);

cJSON *plausibility_check_convertToJSON(plausibility_check_t *plausibility_check);

#endif /* _plausibility_check_H_ */

