/*
 * shareholder_create.h
 *
 * 
 */

#ifndef _shareholder_create_H_
#define _shareholder_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shareholder_create_t shareholder_create_t;




typedef struct shareholder_create_t {
    char *address; // string
    char *birth_date; //date
    char *email; // string
    char *first_name; // string
    char *last_name; // string
    char *share_number; // string
    char *shares; // string

    int _library_owned; // Is the library responsible for freeing this object?
} shareholder_create_t;

__attribute__((deprecated)) shareholder_create_t *shareholder_create_create(
    char *address,
    char *birth_date,
    char *email,
    char *first_name,
    char *last_name,
    char *share_number,
    char *shares
);

void shareholder_create_free(shareholder_create_t *shareholder_create);

shareholder_create_t *shareholder_create_parseFromJSON(cJSON *shareholder_createJSON);

cJSON *shareholder_create_convertToJSON(shareholder_create_t *shareholder_create);

#endif /* _shareholder_create_H_ */

