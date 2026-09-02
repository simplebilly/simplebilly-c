# StockMovementAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**StockMovementAPI_getStockMovement**](StockMovementAPI.md#StockMovementAPI_getStockMovement) | **GET** /api/v1/stock-movements/{movement_id} | 
[**StockMovementAPI_listStockMovements**](StockMovementAPI.md#StockMovementAPI_listStockMovements) | **GET** /api/v1/stock-movements/ | 


# **StockMovementAPI_getStockMovement**
```c
stock_movement_t* StockMovementAPI_getStockMovement(apiClient_t *apiClient, char *movement_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**movement_id** | **char \*** |  | 

### Return type

[stock_movement_t](stock_movement.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StockMovementAPI_listStockMovements**
```c
list_t* StockMovementAPI_listStockMovements(apiClient_t *apiClient, int *page, int *pageSize, char *productId, char *warehouseId, char *movementType, char from, char to);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**pageSize** | **int \*** |  | [optional] 
**productId** | **char \*** |  | [optional] 
**warehouseId** | **char \*** |  | [optional] 
**movementType** | **char \*** |  | [optional] 
**from** | **char** | Only movements on or after this date (inclusive). | [optional] 
**to** | **char** | Only movements on or before this date (inclusive). | [optional] 

### Return type

[list_t](stock_movement.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

