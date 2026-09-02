#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/create_shipment_request.h"
#include "../model/plugin_error.h"
#include "../model/shipment.h"
#include "../model/shipment_status_update.h"
#include "../model/track_order_request.h"
#include "../model/track_order_response.h"
#include "../model/tracking_info.h"


shipment_t*
ShipmentAPI_createShipment(apiClient_t *apiClient, shipment_t *shipment);


// Create a real shipment for an order: calls the configured carrier's label API, stores the returned tracking/label on a new shipment row, and marks the order as shipped.
//
shipment_t*
ShipmentAPI_createShipmentFromOrder(apiClient_t *apiClient, char *order_number, create_shipment_request_t *create_shipment_request);


void
ShipmentAPI_deleteShipment(apiClient_t *apiClient, char *shipment_id);


shipment_t*
ShipmentAPI_getShipment(apiClient_t *apiClient, char *shipment_id);


list_t*
ShipmentAPI_listShipments(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


// Customer-facing tracking lookup: order number + email → shipment status and live carrier events. No auth (public storefront API).
//
track_order_response_t*
ShipmentAPI_trackOrderPublic(apiClient_t *apiClient, track_order_request_t *track_order_request);


tracking_info_t*
ShipmentAPI_trackShipmentApi(apiClient_t *apiClient, char *shipment_id);


shipment_t*
ShipmentAPI_updateShipmentStatus(apiClient_t *apiClient, char *shipment_id, shipment_status_update_t *shipment_status_update);


