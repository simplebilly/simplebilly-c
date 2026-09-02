/*
 * konzern_beteiligung.h
 *
 * 
 */

#ifndef _konzern_beteiligung_H_
#define _konzern_beteiligung_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct konzern_beteiligung_t konzern_beteiligung_t;




typedef struct konzern_beteiligung_t {
    char *company_name; // string
    list_t *control_basis; //primitive container
    int *controlled; //boolean
    char *ownership_pct; // string

    int _library_owned; // Is the library responsible for freeing this object?
} konzern_beteiligung_t;

__attribute__((deprecated)) konzern_beteiligung_t *konzern_beteiligung_create(
    char *company_name,
    list_t *control_basis,
    int *controlled,
    char *ownership_pct
);

void konzern_beteiligung_free(konzern_beteiligung_t *konzern_beteiligung);

konzern_beteiligung_t *konzern_beteiligung_parseFromJSON(cJSON *konzern_beteiligungJSON);

cJSON *konzern_beteiligung_convertToJSON(konzern_beteiligung_t *konzern_beteiligung);

#endif /* _konzern_beteiligung_H_ */

