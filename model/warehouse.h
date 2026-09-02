/*
 * warehouse.h
 *
 * 
 */

#ifndef _warehouse_H_
#define _warehouse_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct warehouse_t warehouse_t;

#include "any_type.h"
#include "country_code.h"



typedef struct warehouse_t {
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
} warehouse_t;

__attribute__((deprecated)) warehouse_t *warehouse_create(
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

void warehouse_free(warehouse_t *warehouse);

warehouse_t *warehouse_parseFromJSON(cJSON *warehouseJSON);

cJSON *warehouse_convertToJSON(warehouse_t *warehouse);

#endif /* _warehouse_H_ */

