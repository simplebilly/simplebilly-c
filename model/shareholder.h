/*
 * shareholder.h
 *
 * 
 */

#ifndef _shareholder_H_
#define _shareholder_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shareholder_t shareholder_t;




typedef struct shareholder_t {
    char *address; // string
    char *birth_date; //date
    char *email; // string
    char *first_name; // string
    char *last_name; // string
    char *share_number; // string
    char *shares; // string

    int _library_owned; // Is the library responsible for freeing this object?
} shareholder_t;

__attribute__((deprecated)) shareholder_t *shareholder_create(
    char *address,
    char *birth_date,
    char *email,
    char *first_name,
    char *last_name,
    char *share_number,
    char *shares
);

void shareholder_free(shareholder_t *shareholder);

shareholder_t *shareholder_parseFromJSON(cJSON *shareholderJSON);

cJSON *shareholder_convertToJSON(shareholder_t *shareholder);

#endif /* _shareholder_H_ */

