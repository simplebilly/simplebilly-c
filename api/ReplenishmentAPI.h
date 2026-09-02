#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/plugin_error.h"
#include "../model/replenishment_response.h"


// Create one draft stock transfer per (source → target) pair carrying all suggested product lines for that pair.
//
any_type_t*
ReplenishmentAPI_applyReplenishments(apiClient_t *apiClient, char *targetWarehouseId, char *sourceWarehouseId);


replenishment_response_t*
ReplenishmentAPI_getReplenishments(apiClient_t *apiClient, char *targetWarehouseId, char *sourceWarehouseId);


