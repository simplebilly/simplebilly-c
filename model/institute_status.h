/*
 * institute_status.h
 *
 * 
 */

#ifndef _institute_status_H_
#define _institute_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct institute_status_t institute_status_t;

#include "institute_check_item.h"
#include "institute_deadlines.h"



typedef struct institute_status_t {
    list_t *checklist; //nonprimitive container
    struct institute_deadlines_t *deadlines; //model
    char *institute_type; // string
    int *kapitalmarktorientiert; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} institute_status_t;

__attribute__((deprecated)) institute_status_t *institute_status_create(
    list_t *checklist,
    institute_deadlines_t *deadlines,
    char *institute_type,
    int *kapitalmarktorientiert
);

void institute_status_free(institute_status_t *institute_status);

institute_status_t *institute_status_parseFromJSON(cJSON *institute_statusJSON);

cJSON *institute_status_convertToJSON(institute_status_t *institute_status);

#endif /* _institute_status_H_ */

