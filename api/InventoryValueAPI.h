#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/current_inventory_value.h"
#include "../model/inventory_value_point.h"
#include "../model/plugin_error.h"


current_inventory_value_t*
InventoryValueAPI_getInventoryValueApi(apiClient_t *apiClient);


inventory_value_point_t*
InventoryValueAPI_recordInventoryValueApi(apiClient_t *apiClient);


