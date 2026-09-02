/*
 * contact_info.h
 *
 * 
 */

#ifndef _contact_info_H_
#define _contact_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct contact_info_t contact_info_t;




typedef struct contact_info_t {
    char *hint; // string
    char *hint_en; // string
    char *role; // string
    char *role_en; // string

    int _library_owned; // Is the library responsible for freeing this object?
} contact_info_t;

__attribute__((deprecated)) contact_info_t *contact_info_create(
    char *hint,
    char *hint_en,
    char *role,
    char *role_en
);

void contact_info_free(contact_info_t *contact_info);

contact_info_t *contact_info_parseFromJSON(cJSON *contact_infoJSON);

cJSON *contact_info_convertToJSON(contact_info_t *contact_info);

#endif /* _contact_info_H_ */

