/*
 * institute_profile_update.h
 *
 * Partial update of the institute profile.
 */

#ifndef _institute_profile_update_H_
#define _institute_profile_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct institute_profile_update_t institute_profile_update_t;




typedef struct institute_profile_update_t {
    char *institute_type; // string
    int *kapitalmarktorientiert; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} institute_profile_update_t;

__attribute__((deprecated)) institute_profile_update_t *institute_profile_update_create(
    char *institute_type,
    int *kapitalmarktorientiert
);

void institute_profile_update_free(institute_profile_update_t *institute_profile_update);

institute_profile_update_t *institute_profile_update_parseFromJSON(cJSON *institute_profile_updateJSON);

cJSON *institute_profile_update_convertToJSON(institute_profile_update_t *institute_profile_update);

#endif /* _institute_profile_update_H_ */

