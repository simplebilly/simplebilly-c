/*
 * tenant_settings.h
 *
 * 
 */

#ifndef _tenant_settings_H_
#define _tenant_settings_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct tenant_settings_t tenant_settings_t;

#include "any_type.h"
#include "company_type.h"



typedef struct tenant_settings_t {
    simplebilly_api_company_type__e company_type; //referenced enum
    char *dpa_accepted_at; //date time
    char *dpa_accepted_by; // string
    char *dpa_version; // string
    any_type_t *features; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} tenant_settings_t;

__attribute__((deprecated)) tenant_settings_t *tenant_settings_create(
    simplebilly_api_company_type__e company_type,
    char *dpa_accepted_at,
    char *dpa_accepted_by,
    char *dpa_version,
    any_type_t *features
);

void tenant_settings_free(tenant_settings_t *tenant_settings);

tenant_settings_t *tenant_settings_parseFromJSON(cJSON *tenant_settingsJSON);

cJSON *tenant_settings_convertToJSON(tenant_settings_t *tenant_settings);

#endif /* _tenant_settings_H_ */

