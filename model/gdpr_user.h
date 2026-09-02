/*
 * gdpr_user.h
 *
 * 
 */

#ifndef _gdpr_user_H_
#define _gdpr_user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gdpr_user_t gdpr_user_t;




typedef struct gdpr_user_t {
    char *created_at; //date time
    char *email; // string
    char *id; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gdpr_user_t;

__attribute__((deprecated)) gdpr_user_t *gdpr_user_create(
    char *created_at,
    char *email,
    char *id,
    char *name
);

void gdpr_user_free(gdpr_user_t *gdpr_user);

gdpr_user_t *gdpr_user_parseFromJSON(cJSON *gdpr_userJSON);

cJSON *gdpr_user_convertToJSON(gdpr_user_t *gdpr_user);

#endif /* _gdpr_user_H_ */

