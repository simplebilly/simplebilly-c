#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/invoice_match_request.h"
#include "../model/plugin_error.h"
#include "../model/purchase_order.h"
#include "../model/purchase_order_status_update.h"


purchase_order_t*
PurchaseOrderAPI_createPurchaseOrder(apiClient_t *apiClient, purchase_order_t *purchase_order);


void
PurchaseOrderAPI_deletePurchaseOrder(apiClient_t *apiClient, char *purchase_order_id);


purchase_order_t*
PurchaseOrderAPI_getPurchaseOrder(apiClient_t *apiClient, char *purchase_order_id);


list_t*
PurchaseOrderAPI_listPurchaseOrders(apiClient_t *apiClient, int *page, int *page_size, char *status, char *supplier_name, char *search);


// 3-way invoice check (Rechnungsprüfung): compares the purchase order line items, the quantities received via goods receipts, and the supplier invoice line items, reporting quantity and price variances per product.
//
any_type_t*
PurchaseOrderAPI_matchInvoice(apiClient_t *apiClient, char *purchase_order_id, invoice_match_request_t *invoice_match_request);


purchase_order_t*
PurchaseOrderAPI_updatePurchaseOrder(apiClient_t *apiClient, char *purchase_order_id, body);


purchase_order_t*
PurchaseOrderAPI_updatePurchaseOrderStatus(apiClient_t *apiClient, char *purchase_order_id, purchase_order_status_update_t *purchase_order_status_update);


