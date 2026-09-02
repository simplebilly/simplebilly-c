# StockTransferAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**StockTransferAPI_createStockTransfer**](StockTransferAPI.md#StockTransferAPI_createStockTransfer) | **POST** /api/v1/stock-transfers | 
[**StockTransferAPI_deleteStockTransfer**](StockTransferAPI.md#StockTransferAPI_deleteStockTransfer) | **DELETE** /api/v1/stock-transfers/{stock_transfer_id} | 
[**StockTransferAPI_getStockTransfer**](StockTransferAPI.md#StockTransferAPI_getStockTransfer) | **GET** /api/v1/stock-transfers/{stock_transfer_id} | 
[**StockTransferAPI_listStockTransfers**](StockTransferAPI.md#StockTransferAPI_listStockTransfers) | **GET** /api/v1/stock-transfers/ | 
[**StockTransferAPI_updateStockTransferStatus**](StockTransferAPI.md#StockTransferAPI_updateStockTransferStatus) | **PUT** /api/v1/stock-transfers/{stock_transfer_id}/status | 


# **StockTransferAPI_createStockTransfer**
```c
stock_transfer_t* StockTransferAPI_createStockTransfer(apiClient_t *apiClient, stock_transfer_t *stock_transfer);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**stock_transfer** | **[stock_transfer_t](stock_transfer.md) \*** |  | 

### Return type

[stock_transfer_t](stock_transfer.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StockTransferAPI_deleteStockTransfer**
```c
void StockTransferAPI_deleteStockTransfer(apiClient_t *apiClient, char *stock_transfer_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**stock_transfer_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StockTransferAPI_getStockTransfer**
```c
stock_transfer_t* StockTransferAPI_getStockTransfer(apiClient_t *apiClient, char *stock_transfer_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**stock_transfer_id** | **char \*** |  | 

### Return type

[stock_transfer_t](stock_transfer.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StockTransferAPI_listStockTransfers**
```c
list_t* StockTransferAPI_listStockTransfers(apiClient_t *apiClient, int *page, int *page_size, char *status, char *warehouse_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**warehouse_id** | **char \*** |  | [optional] 

### Return type

[list_t](stock_transfer.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StockTransferAPI_updateStockTransferStatus**
```c
stock_transfer_t* StockTransferAPI_updateStockTransferStatus(apiClient_t *apiClient, char *stock_transfer_id, stock_transfer_status_update_t *stock_transfer_status_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**stock_transfer_id** | **char \*** |  | 
**stock_transfer_status_update** | **[stock_transfer_status_update_t](stock_transfer_status_update.md) \*** |  | 

### Return type

[stock_transfer_t](stock_transfer.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

