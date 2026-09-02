#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/order.h"
#include "../model/order_state_update.h"
#include "../model/order_tags_request.h"
#include "../model/plugin_error.h"


order_t*
OrderAPI_addOrderTags(apiClient_t *apiClient, char *order_id, order_tags_request_t *order_tags_request);


order_t*
OrderAPI_findOrderByExternalRef(apiClient_t *apiClient, char *ext_ref);


order_t*
OrderAPI_getOrder(apiClient_t *apiClient, char *order_number);


list_t*
OrderAPI_getOrders(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


order_t*
OrderAPI_patchOrder(apiClient_t *apiClient, char *order_id, body);


order_t*
OrderAPI_replaceOrderTags(apiClient_t *apiClient, char *order_id, order_tags_request_t *order_tags_request);


order_t*
OrderAPI_updateOrderState(apiClient_t *apiClient, char *order_id, order_state_update_t *order_state_update);


