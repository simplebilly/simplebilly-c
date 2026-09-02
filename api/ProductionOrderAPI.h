#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/production_order.h"
#include "../model/production_order_costing.h"
#include "../model/production_order_status_update.h"


production_order_t*
ProductionOrderAPI_createProductionOrder(apiClient_t *apiClient, production_order_t *production_order);


void
ProductionOrderAPI_deleteProductionOrder(apiClient_t *apiClient, char *production_order_id);


production_order_t*
ProductionOrderAPI_getProductionOrder(apiClient_t *apiClient, char *production_order_id);


list_t*
ProductionOrderAPI_listProductionOrders(apiClient_t *apiClient, int *page, int *pageSize, char *search, char *status);


// Actual-costing report (Nachkalkulation) — material costs from BOM components at their purchase price plus the resulting per-unit cost and margin against the finished product's sale price.
//
production_order_costing_t*
ProductionOrderAPI_productionOrderCosting(apiClient_t *apiClient, char *production_order_id);


production_order_t*
ProductionOrderAPI_updateProductionOrder(apiClient_t *apiClient, char *production_order_id, production_order_t *production_order);


production_order_t*
ProductionOrderAPI_updateProductionOrderStatus(apiClient_t *apiClient, char *production_order_id, production_order_status_update_t *production_order_status_update);


