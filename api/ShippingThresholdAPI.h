#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/deliverable_response.h"
#include "../model/plugin_error.h"
#include "../model/shipping_threshold.h"
#include "../model/shipping_threshold_create.h"
#include "../model/shipping_threshold_update.h"


shipping_threshold_t*
ShippingThresholdAPI_createShippingThreshold(apiClient_t *apiClient, shipping_threshold_create_t *shipping_threshold_create);


void
ShippingThresholdAPI_deleteShippingThreshold(apiClient_t *apiClient, char *threshold_id);


deliverable_response_t*
ShippingThresholdAPI_getDeliverable(apiClient_t *apiClient, char *productId, char *warehouseId);


shipping_threshold_t*
ShippingThresholdAPI_getShippingThreshold(apiClient_t *apiClient, char *threshold_id);


list_t*
ShippingThresholdAPI_listShippingThresholds(apiClient_t *apiClient, int *page, int *page_size, char *product_id, char *warehouse_id, int *is_active);


shipping_threshold_t*
ShippingThresholdAPI_updateShippingThreshold(apiClient_t *apiClient, char *threshold_id, shipping_threshold_update_t *shipping_threshold_update);


