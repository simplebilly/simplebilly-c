/*
 * update_tenant_settings.h
 *
 * Request payload for updating tenant settings.
 */

#ifndef _update_tenant_settings_H_
#define _update_tenant_settings_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_tenant_settings_t update_tenant_settings_t;

#include "company_type.h"
#include "partial_feature_settings.h"



typedef struct update_tenant_settings_t {
    simplebilly_api_company_type__e company_type; //referenced enum
    struct partial_feature_settings_t *features; //model

    int _library_owned; // Is the library responsible for freeing this object?
} update_tenant_settings_t;

__attribute__((deprecated)) update_tenant_settings_t *update_tenant_settings_create(
    simplebilly_api_company_type__e company_type,
    partial_feature_settings_t *features
);

void update_tenant_settings_free(update_tenant_settings_t *update_tenant_settings);

update_tenant_settings_t *update_tenant_settings_parseFromJSON(cJSON *update_tenant_settingsJSON);

cJSON *update_tenant_settings_convertToJSON(update_tenant_settings_t *update_tenant_settings);

#endif /* _update_tenant_settings_H_ */

