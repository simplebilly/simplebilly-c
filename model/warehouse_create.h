/*
 * warehouse_create.h
 *
 * 
 */

#ifndef _warehouse_create_H_
#define _warehouse_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct warehouse_create_t warehouse_create_t;

#include "any_type.h"
#include "country_code.h"



typedef struct warehouse_create_t {
    char *address_city; // string
    country_code_t *address_country; // custom
    char *address_street; // string
    char *address_zip; // string
    any_type_t *bin_locations; // custom
    char *code; // string
    int *is_active; //boolean
    int *is_default; //boolean
    char *name; // string
    char *notes; // string

    int _library_owned; // Is the library responsible for freeing this object?
} warehouse_create_t;

__attribute__((deprecated)) warehouse_create_t *warehouse_create_create(
    char *address_city,
    country_code_t *address_country,
    char *address_street,
    char *address_zip,
    any_type_t *bin_locations,
    char *code,
    int *is_active,
    int *is_default,
    char *name,
    char *notes
);

void warehouse_create_free(warehouse_create_t *warehouse_create);

warehouse_create_t *warehouse_create_parseFromJSON(cJSON *warehouse_createJSON);

cJSON *warehouse_create_convertToJSON(warehouse_create_t *warehouse_create);

#endif /* _warehouse_create_H_ */

