#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/product.h"
#include "../model/product_create.h"
#include "../model/product_stock.h"
#include "../model/product_update.h"
#include "../model/stock_update_request.h"


product_t*
ProductAPI_createProductApi(apiClient_t *apiClient, product_create_t *product_create);


void
ProductAPI_deleteProductApi(apiClient_t *apiClient, char *product_id);


product_t*
ProductAPI_getProductApi(apiClient_t *apiClient, char *product_id);


product_stock_t*
ProductAPI_getProductStockApi(apiClient_t *apiClient, char *product_id);


list_t*
ProductAPI_getProductsApi(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


list_t*
ProductAPI_listLowStockProductsApi(apiClient_t *apiClient, long threshold);


product_t*
ProductAPI_productRestore(apiClient_t *apiClient, char *product_id);


product_t*
ProductAPI_updateProductApi(apiClient_t *apiClient, char *product_id, product_update_t *product_update);


product_stock_t*
ProductAPI_updateProductStockApi(apiClient_t *apiClient, char *product_id, stock_update_request_t *stock_update_request);


