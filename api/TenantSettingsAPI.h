#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/tenant_settings.h"
#include "../model/update_tenant_settings.h"


tenant_settings_t*
TenantSettingsAPI_getTenantSettings(apiClient_t *apiClient);


tenant_settings_t*
TenantSettingsAPI_updateTenantSettings(apiClient_t *apiClient, update_tenant_settings_t *update_tenant_settings);


