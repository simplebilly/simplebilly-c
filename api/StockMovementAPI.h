#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/stock_movement.h"


stock_movement_t*
StockMovementAPI_getStockMovement(apiClient_t *apiClient, char *movement_id);


list_t*
StockMovementAPI_listStockMovements(apiClient_t *apiClient, int *page, int *pageSize, char *productId, char *warehouseId, char *movementType, char from, char to);


