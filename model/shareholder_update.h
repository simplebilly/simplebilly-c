/*
 * shareholder_update.h
 *
 * 
 */

#ifndef _shareholder_update_H_
#define _shareholder_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shareholder_update_t shareholder_update_t;




typedef struct shareholder_update_t {
    char *address; // string
    char *birth_date; //date
    char *email; // string
    char *first_name; // string
    char *last_name; // string
    char *share_number; // string
    char *shares; // string

    int _library_owned; // Is the library responsible for freeing this object?
} shareholder_update_t;

__attribute__((deprecated)) shareholder_update_t *shareholder_update_create(
    char *address,
    char *birth_date,
    char *email,
    char *first_name,
    char *last_name,
    char *share_number,
    char *shares
);

void shareholder_update_free(shareholder_update_t *shareholder_update);

shareholder_update_t *shareholder_update_parseFromJSON(cJSON *shareholder_updateJSON);

cJSON *shareholder_update_convertToJSON(shareholder_update_t *shareholder_update);

#endif /* _shareholder_update_H_ */

