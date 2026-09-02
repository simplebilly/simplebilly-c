#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/goods_receipt.h"
#include "../model/plugin_error.h"


goods_receipt_t*
GoodsReceiptAPI_createGoodsReceipt(apiClient_t *apiClient, goods_receipt_t *goods_receipt);


void
GoodsReceiptAPI_deleteGoodsReceipt(apiClient_t *apiClient, char *goods_receipt_id);


goods_receipt_t*
GoodsReceiptAPI_getGoodsReceipt(apiClient_t *apiClient, char *goods_receipt_id);


list_t*
GoodsReceiptAPI_listGoodsReceipts(apiClient_t *apiClient, int *page, int *page_size, char *purchase_order_id, char *supplier_name, char *warehouse_id);


