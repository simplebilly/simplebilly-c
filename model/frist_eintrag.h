/*
 * frist_eintrag.h
 *
 * 
 */

#ifndef _frist_eintrag_H_
#define _frist_eintrag_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct frist_eintrag_t frist_eintrag_t;




typedef struct frist_eintrag_t {
    char *bezeichnung; // string
    char *faellig; // string
    char *faellig_original; // string
    char *hinweis; // string
    char *typ; // string
    char *zeitraum; // string

    int _library_owned; // Is the library responsible for freeing this object?
} frist_eintrag_t;

__attribute__((deprecated)) frist_eintrag_t *frist_eintrag_create(
    char *bezeichnung,
    char *faellig,
    char *faellig_original,
    char *hinweis,
    char *typ,
    char *zeitraum
);

void frist_eintrag_free(frist_eintrag_t *frist_eintrag);

frist_eintrag_t *frist_eintrag_parseFromJSON(cJSON *frist_eintragJSON);

cJSON *frist_eintrag_convertToJSON(frist_eintrag_t *frist_eintrag);

#endif /* _frist_eintrag_H_ */

