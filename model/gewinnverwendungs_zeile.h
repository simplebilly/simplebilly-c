/*
 * gewinnverwendungs_zeile.h
 *
 * 
 */

#ifndef _gewinnverwendungs_zeile_H_
#define _gewinnverwendungs_zeile_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gewinnverwendungs_zeile_t gewinnverwendungs_zeile_t;




typedef struct gewinnverwendungs_zeile_t {
    char *betrag; // string
    char *label; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gewinnverwendungs_zeile_t;

__attribute__((deprecated)) gewinnverwendungs_zeile_t *gewinnverwendungs_zeile_create(
    char *betrag,
    char *label
);

void gewinnverwendungs_zeile_free(gewinnverwendungs_zeile_t *gewinnverwendungs_zeile);

gewinnverwendungs_zeile_t *gewinnverwendungs_zeile_parseFromJSON(cJSON *gewinnverwendungs_zeileJSON);

cJSON *gewinnverwendungs_zeile_convertToJSON(gewinnverwendungs_zeile_t *gewinnverwendungs_zeile);

#endif /* _gewinnverwendungs_zeile_H_ */

