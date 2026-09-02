/*
 * institute_deadlines.h
 *
 * 
 */

#ifndef _institute_deadlines_H_
#define _institute_deadlines_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct institute_deadlines_t institute_deadlines_t;




typedef struct institute_deadlines_t {
    int *abschlusspruefung_months; //numeric
    int *jahresabschluss_bafin_months; //numeric
    int *offenlegung_months; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} institute_deadlines_t;

__attribute__((deprecated)) institute_deadlines_t *institute_deadlines_create(
    int *abschlusspruefung_months,
    int *jahresabschluss_bafin_months,
    int *offenlegung_months
);

void institute_deadlines_free(institute_deadlines_t *institute_deadlines);

institute_deadlines_t *institute_deadlines_parseFromJSON(cJSON *institute_deadlinesJSON);

cJSON *institute_deadlines_convertToJSON(institute_deadlines_t *institute_deadlines);

#endif /* _institute_deadlines_H_ */

