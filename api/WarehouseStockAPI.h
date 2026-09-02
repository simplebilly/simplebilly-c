#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/stock_adjustment.h"
#include "../model/warehouse_stock.h"


warehouse_stock_t*
WarehouseStockAPI_createWarehouseStock(apiClient_t *apiClient, char *warehouse_id, stock_adjustment_t *stock_adjustment);


void
WarehouseStockAPI_deleteWarehouseStock(apiClient_t *apiClient, char *warehouse_id, char *product_id);


list_t*
WarehouseStockAPI_listWarehouseStock(apiClient_t *apiClient, char *warehouse_id);


warehouse_stock_t*
WarehouseStockAPI_updateWarehouseStock(apiClient_t *apiClient, char *warehouse_id, char *product_id, stock_adjustment_t *stock_adjustment);


