/*
 * peppol_response.h
 *
 * 
 */

#ifndef _peppol_response_H_
#define _peppol_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct peppol_response_t peppol_response_t;




typedef struct peppol_response_t {
    char *content; // string
    char *content_type; // string
    char *filename; // string

    int _library_owned; // Is the library responsible for freeing this object?
} peppol_response_t;

__attribute__((deprecated)) peppol_response_t *peppol_response_create(
    char *content,
    char *content_type,
    char *filename
);

void peppol_response_free(peppol_response_t *peppol_response);

peppol_response_t *peppol_response_parseFromJSON(cJSON *peppol_responseJSON);

cJSON *peppol_response_convertToJSON(peppol_response_t *peppol_response);

#endif /* _peppol_response_H_ */

