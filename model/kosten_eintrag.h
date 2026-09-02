/*
 * kosten_eintrag.h
 *
 * 
 */

#ifndef _kosten_eintrag_H_
#define _kosten_eintrag_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct kosten_eintrag_t kosten_eintrag_t;




typedef struct kosten_eintrag_t {
    char *beschreibung; // string
    char *betrag; // string
    char *datum; // string
    char *typ; // string

    int _library_owned; // Is the library responsible for freeing this object?
} kosten_eintrag_t;

__attribute__((deprecated)) kosten_eintrag_t *kosten_eintrag_create(
    char *beschreibung,
    char *betrag,
    char *datum,
    char *typ
);

void kosten_eintrag_free(kosten_eintrag_t *kosten_eintrag);

kosten_eintrag_t *kosten_eintrag_parseFromJSON(cJSON *kosten_eintragJSON);

cJSON *kosten_eintrag_convertToJSON(kosten_eintrag_t *kosten_eintrag);

#endif /* _kosten_eintrag_H_ */

