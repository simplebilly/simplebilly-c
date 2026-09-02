/*
 * betriebsstaette.h
 *
 * Eine Betriebsstätte mit der Anzahl der sozialversicherungspflichtig Beschäftigten (Jahresdurchschnitt des Vorjahres).
 */

#ifndef _betriebsstaette_H_
#define _betriebsstaette_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct betriebsstaette_t betriebsstaette_t;




typedef struct betriebsstaette_t {
    long *beschaefigte; //numeric
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} betriebsstaette_t;

__attribute__((deprecated)) betriebsstaette_t *betriebsstaette_create(
    long *beschaefigte,
    char *name
);

void betriebsstaette_free(betriebsstaette_t *betriebsstaette);

betriebsstaette_t *betriebsstaette_parseFromJSON(cJSON *betriebsstaetteJSON);

cJSON *betriebsstaette_convertToJSON(betriebsstaette_t *betriebsstaette);

#endif /* _betriebsstaette_H_ */

