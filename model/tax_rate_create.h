/*
 * tax_rate_create.h
 *
 * 
 */

#ifndef _tax_rate_create_H_
#define _tax_rate_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct tax_rate_create_t tax_rate_create_t;




typedef struct tax_rate_create_t {
    char *country_code; // string
    char *effective_from; //date
    int *is_default; //boolean
    char *name; // string
    long *rate_percent; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} tax_rate_create_t;

__attribute__((deprecated)) tax_rate_create_t *tax_rate_create_create(
    char *country_code,
    char *effective_from,
    int *is_default,
    char *name,
    long *rate_percent
);

void tax_rate_create_free(tax_rate_create_t *tax_rate_create);

tax_rate_create_t *tax_rate_create_parseFromJSON(cJSON *tax_rate_createJSON);

cJSON *tax_rate_create_convertToJSON(tax_rate_create_t *tax_rate_create);

#endif /* _tax_rate_create_H_ */

