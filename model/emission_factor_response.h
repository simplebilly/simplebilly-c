/*
 * emission_factor_response.h
 *
 * 
 */

#ifndef _emission_factor_response_H_
#define _emission_factor_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct emission_factor_response_t emission_factor_response_t;




typedef struct emission_factor_response_t {
    char *category_id; // string
    double *kg_co2e_per_unit; //numeric
    char *name_de; // string
    char *source; // string
    char *unit; // string
    char *version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} emission_factor_response_t;

__attribute__((deprecated)) emission_factor_response_t *emission_factor_response_create(
    char *category_id,
    double *kg_co2e_per_unit,
    char *name_de,
    char *source,
    char *unit,
    char *version
);

void emission_factor_response_free(emission_factor_response_t *emission_factor_response);

emission_factor_response_t *emission_factor_response_parseFromJSON(cJSON *emission_factor_responseJSON);

cJSON *emission_factor_response_convertToJSON(emission_factor_response_t *emission_factor_response);

#endif /* _emission_factor_response_H_ */

