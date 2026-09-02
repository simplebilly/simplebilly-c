/*
 * eks_monats_wert.h
 *
 * 
 */

#ifndef _eks_monats_wert_H_
#define _eks_monats_wert_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct eks_monats_wert_t eks_monats_wert_t;




typedef struct eks_monats_wert_t {
    char *ausgaben; // string
    char *einnahmen; // string
    char *ergebnis; // string
    char *monat; // string

    int _library_owned; // Is the library responsible for freeing this object?
} eks_monats_wert_t;

__attribute__((deprecated)) eks_monats_wert_t *eks_monats_wert_create(
    char *ausgaben,
    char *einnahmen,
    char *ergebnis,
    char *monat
);

void eks_monats_wert_free(eks_monats_wert_t *eks_monats_wert);

eks_monats_wert_t *eks_monats_wert_parseFromJSON(cJSON *eks_monats_wertJSON);

cJSON *eks_monats_wert_convertToJSON(eks_monats_wert_t *eks_monats_wert);

#endif /* _eks_monats_wert_H_ */

