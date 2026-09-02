/*
 * address.h
 *
 * 
 */

#ifndef _address_H_
#define _address_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct address_t address_t;




typedef struct address_t {
    char *city; // string
    char *company; // string
    char *country; // string
    char *email; // string
    char *name; // string
    char *phone; // string
    char *street; // string
    char *street_number; // string
    char *zip; // string

    int _library_owned; // Is the library responsible for freeing this object?
} address_t;

__attribute__((deprecated)) address_t *address_create(
    char *city,
    char *company,
    char *country,
    char *email,
    char *name,
    char *phone,
    char *street,
    char *street_number,
    char *zip
);

void address_free(address_t *address);

address_t *address_parseFromJSON(cJSON *addressJSON);

cJSON *address_convertToJSON(address_t *address);

#endif /* _address_H_ */

