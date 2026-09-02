/*
 * konzern_thresholds.h
 *
 * 
 */

#ifndef _konzern_thresholds_H_
#define _konzern_thresholds_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct konzern_thresholds_t konzern_thresholds_t;




typedef struct konzern_thresholds_t {
    char *bilanzsumme; // string
    long *mitarbeiter; //numeric
    char *netto_umsatz; // string

    int _library_owned; // Is the library responsible for freeing this object?
} konzern_thresholds_t;

__attribute__((deprecated)) konzern_thresholds_t *konzern_thresholds_create(
    char *bilanzsumme,
    long *mitarbeiter,
    char *netto_umsatz
);

void konzern_thresholds_free(konzern_thresholds_t *konzern_thresholds);

konzern_thresholds_t *konzern_thresholds_parseFromJSON(cJSON *konzern_thresholdsJSON);

cJSON *konzern_thresholds_convertToJSON(konzern_thresholds_t *konzern_thresholds);

#endif /* _konzern_thresholds_H_ */

