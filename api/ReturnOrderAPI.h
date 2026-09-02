#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/plugin_error.h"
#include "../model/return_logistics_queue_item.h"
#include "../model/return_logistics_summary.h"
#include "../model/return_order.h"
#include "../model/return_order_status_update.h"


return_order_t*
ReturnOrderAPI_createReturnOrder(apiClient_t *apiClient, return_order_t *return_order);


void
ReturnOrderAPI_deleteReturnOrder(apiClient_t *apiClient, char *return_order_id);


return_order_t*
ReturnOrderAPI_getReturnOrder(apiClient_t *apiClient, char *return_order_id);


list_t*
ReturnOrderAPI_listReturnOrders(apiClient_t *apiClient, int *page, int *page_size, char *status, char *customer_name, char *order_number);


list_t*
ReturnOrderAPI_returnLogisticsQueue(apiClient_t *apiClient);


// Returns-logistics aggregation for the dashboard: quantities received, restocked and scrapped per warehouse.
//
return_logistics_summary_t*
ReturnOrderAPI_returnLogisticsSummary(apiClient_t *apiClient);


return_order_t*
ReturnOrderAPI_updateReturnOrder(apiClient_t *apiClient, char *return_order_id, body);


return_order_t*
ReturnOrderAPI_updateReturnOrderStatus(apiClient_t *apiClient, char *return_order_id, return_order_status_update_t *return_order_status_update);


