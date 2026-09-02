/*
 * institute_profile.h
 *
 * 
 */

#ifndef _institute_profile_H_
#define _institute_profile_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct institute_profile_t institute_profile_t;

#include "institute_type.h"



typedef struct institute_profile_t {
    institute_type_t *institute_type; // custom
    int *kapitalmarktorientiert; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} institute_profile_t;

__attribute__((deprecated)) institute_profile_t *institute_profile_create(
    institute_type_t *institute_type,
    int *kapitalmarktorientiert
);

void institute_profile_free(institute_profile_t *institute_profile);

institute_profile_t *institute_profile_parseFromJSON(cJSON *institute_profileJSON);

cJSON *institute_profile_convertToJSON(institute_profile_t *institute_profile);

#endif /* _institute_profile_H_ */

