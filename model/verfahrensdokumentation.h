/*
 * verfahrensdokumentation.h
 *
 * 
 */

#ifndef _verfahrensdokumentation_H_
#define _verfahrensdokumentation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct verfahrensdokumentation_t verfahrensdokumentation_t;

#include "compliance_entry.h"



typedef struct verfahrensdokumentation_t {
    list_t *entries; //nonprimitive container
    char *generated_at; // string
    char *title; // string
    char *version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} verfahrensdokumentation_t;

__attribute__((deprecated)) verfahrensdokumentation_t *verfahrensdokumentation_create(
    list_t *entries,
    char *generated_at,
    char *title,
    char *version
);

void verfahrensdokumentation_free(verfahrensdokumentation_t *verfahrensdokumentation);

verfahrensdokumentation_t *verfahrensdokumentation_parseFromJSON(cJSON *verfahrensdokumentationJSON);

cJSON *verfahrensdokumentation_convertToJSON(verfahrensdokumentation_t *verfahrensdokumentation);

#endif /* _verfahrensdokumentation_H_ */

