#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/stock_transfer.h"
#include "../model/stock_transfer_status_update.h"


stock_transfer_t*
StockTransferAPI_createStockTransfer(apiClient_t *apiClient, stock_transfer_t *stock_transfer);


void
StockTransferAPI_deleteStockTransfer(apiClient_t *apiClient, char *stock_transfer_id);


stock_transfer_t*
StockTransferAPI_getStockTransfer(apiClient_t *apiClient, char *stock_transfer_id);


list_t*
StockTransferAPI_listStockTransfers(apiClient_t *apiClient, int *page, int *page_size, char *status, char *warehouse_id);


stock_transfer_t*
StockTransferAPI_updateStockTransferStatus(apiClient_t *apiClient, char *stock_transfer_id, stock_transfer_status_update_t *stock_transfer_status_update);


