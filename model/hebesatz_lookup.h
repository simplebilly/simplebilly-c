/*
 * hebesatz_lookup.h
 *
 * 
 */

#ifndef _hebesatz_lookup_H_
#define _hebesatz_lookup_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct hebesatz_lookup_t hebesatz_lookup_t;




typedef struct hebesatz_lookup_t {
    char *bundesland; // string
    char *country_code; // string
    char *gemeinde_name; // string
    char *gemeindeschluessel; // string
    double *hebesatz_gewerbesteuer; //numeric
    double *hebesatz_grundsteuer_b; //numeric
    int *jahr; //numeric
    char *landkreis; // string
    char *valid_from; // string
    char *valid_to; // string

    int _library_owned; // Is the library responsible for freeing this object?
} hebesatz_lookup_t;

__attribute__((deprecated)) hebesatz_lookup_t *hebesatz_lookup_create(
    char *bundesland,
    char *country_code,
    char *gemeinde_name,
    char *gemeindeschluessel,
    double *hebesatz_gewerbesteuer,
    double *hebesatz_grundsteuer_b,
    int *jahr,
    char *landkreis,
    char *valid_from,
    char *valid_to
);

void hebesatz_lookup_free(hebesatz_lookup_t *hebesatz_lookup);

hebesatz_lookup_t *hebesatz_lookup_parseFromJSON(cJSON *hebesatz_lookupJSON);

cJSON *hebesatz_lookup_convertToJSON(hebesatz_lookup_t *hebesatz_lookup);

#endif /* _hebesatz_lookup_H_ */

