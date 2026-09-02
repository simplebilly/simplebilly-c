/*
 * gdpr_tenant.h
 *
 * 
 */

#ifndef _gdpr_tenant_H_
#define _gdpr_tenant_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gdpr_tenant_t gdpr_tenant_t;




typedef struct gdpr_tenant_t {
    char *name; // string
    char *role; // string
    char *tenant_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gdpr_tenant_t;

__attribute__((deprecated)) gdpr_tenant_t *gdpr_tenant_create(
    char *name,
    char *role,
    char *tenant_id
);

void gdpr_tenant_free(gdpr_tenant_t *gdpr_tenant);

gdpr_tenant_t *gdpr_tenant_parseFromJSON(cJSON *gdpr_tenantJSON);

cJSON *gdpr_tenant_convertToJSON(gdpr_tenant_t *gdpr_tenant);

#endif /* _gdpr_tenant_H_ */

