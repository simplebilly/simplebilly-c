#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/plugin_error.h"
#include "../model/warehouse.h"


warehouse_t*
WarehouseAPI_createWarehouse(apiClient_t *apiClient, warehouse_t *warehouse);


void
WarehouseAPI_deleteWarehouse(apiClient_t *apiClient, char *warehouse_id);


warehouse_t*
WarehouseAPI_getWarehouse(apiClient_t *apiClient, char *warehouse_id);


list_t*
WarehouseAPI_listWarehouses(apiClient_t *apiClient, int *page, int *page_size, char *search, int *is_active);


warehouse_t*
WarehouseAPI_updateWarehouse(apiClient_t *apiClient, char *warehouse_id, body);


