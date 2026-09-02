/*
 * tenant_user.h
 *
 * 
 */

#ifndef _tenant_user_H_
#define _tenant_user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct tenant_user_t tenant_user_t;




typedef struct tenant_user_t {
    char *email; // string
    int *email_verified; //boolean
    int *is_active; //boolean
    char *joined_at; //date time
    char *last_login; //date time
    char *name; // string
    list_t *permissions; //primitive container
    char *role; // string
    char *user_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} tenant_user_t;

__attribute__((deprecated)) tenant_user_t *tenant_user_create(
    char *email,
    int *email_verified,
    int *is_active,
    char *joined_at,
    char *last_login,
    char *name,
    list_t *permissions,
    char *role,
    char *user_id
);

void tenant_user_free(tenant_user_t *tenant_user);

tenant_user_t *tenant_user_parseFromJSON(cJSON *tenant_userJSON);

cJSON *tenant_user_convertToJSON(tenant_user_t *tenant_user);

#endif /* _tenant_user_H_ */

