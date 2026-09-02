/*
 * user_tenant_info.h
 *
 * 
 */

#ifndef _user_tenant_info_H_
#define _user_tenant_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_tenant_info_t user_tenant_info_t;




typedef struct user_tenant_info_t {
    char *custom_domain; // string
    char *role; // string
    char *subdomain; // string
    char *tenant_id; // string
    char *tenant_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} user_tenant_info_t;

__attribute__((deprecated)) user_tenant_info_t *user_tenant_info_create(
    char *custom_domain,
    char *role,
    char *subdomain,
    char *tenant_id,
    char *tenant_name
);

void user_tenant_info_free(user_tenant_info_t *user_tenant_info);

user_tenant_info_t *user_tenant_info_parseFromJSON(cJSON *user_tenant_infoJSON);

cJSON *user_tenant_info_convertToJSON(user_tenant_info_t *user_tenant_info);

#endif /* _user_tenant_info_H_ */

