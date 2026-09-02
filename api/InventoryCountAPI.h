#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/generate_count_request.h"
#include "../model/inventory_count.h"
#include "../model/inventory_count_status_update.h"
#include "../model/plugin_error.h"


inventory_count_t*
InventoryCountAPI_createInventoryCount(apiClient_t *apiClient, inventory_count_t *inventory_count);


void
InventoryCountAPI_deleteInventoryCount(apiClient_t *apiClient, char *inventory_count_id);


inventory_count_t*
InventoryCountAPI_generateInventoryCount(apiClient_t *apiClient, generate_count_request_t *generate_count_request);


inventory_count_t*
InventoryCountAPI_getInventoryCount(apiClient_t *apiClient, char *inventory_count_id);


list_t*
InventoryCountAPI_listInventoryCounts(apiClient_t *apiClient, int *page, int *page_size, char *status, char *warehouse_id);


inventory_count_t*
InventoryCountAPI_updateInventoryCount(apiClient_t *apiClient, char *inventory_count_id, body);


inventory_count_t*
InventoryCountAPI_updateInventoryCountStatus(apiClient_t *apiClient, char *inventory_count_id, inventory_count_status_update_t *inventory_count_status_update);


