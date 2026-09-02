/*
 * kosten_vorschau.h
 *
 * 
 */

#ifndef _kosten_vorschau_H_
#define _kosten_vorschau_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct kosten_vorschau_t kosten_vorschau_t;

#include "kosten_eintrag.h"



typedef struct kosten_vorschau_t {
    list_t *eintraege; //nonprimitive container
    char *gesamt; // string

    int _library_owned; // Is the library responsible for freeing this object?
} kosten_vorschau_t;

__attribute__((deprecated)) kosten_vorschau_t *kosten_vorschau_create(
    list_t *eintraege,
    char *gesamt
);

void kosten_vorschau_free(kosten_vorschau_t *kosten_vorschau);

kosten_vorschau_t *kosten_vorschau_parseFromJSON(cJSON *kosten_vorschauJSON);

cJSON *kosten_vorschau_convertToJSON(kosten_vorschau_t *kosten_vorschau);

#endif /* _kosten_vorschau_H_ */

