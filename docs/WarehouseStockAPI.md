# WarehouseStockAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**WarehouseStockAPI_createWarehouseStock**](WarehouseStockAPI.md#WarehouseStockAPI_createWarehouseStock) | **POST** /api/v1/warehouses/{warehouse_id}/stock | 
[**WarehouseStockAPI_deleteWarehouseStock**](WarehouseStockAPI.md#WarehouseStockAPI_deleteWarehouseStock) | **DELETE** /api/v1/warehouses/{warehouse_id}/stock/{product_id} | 
[**WarehouseStockAPI_listWarehouseStock**](WarehouseStockAPI.md#WarehouseStockAPI_listWarehouseStock) | **GET** /api/v1/warehouses/{warehouse_id}/stock | 
[**WarehouseStockAPI_updateWarehouseStock**](WarehouseStockAPI.md#WarehouseStockAPI_updateWarehouseStock) | **PUT** /api/v1/warehouses/{warehouse_id}/stock/{product_id} | 


# **WarehouseStockAPI_createWarehouseStock**
```c
warehouse_stock_t* WarehouseStockAPI_createWarehouseStock(apiClient_t *apiClient, char *warehouse_id, stock_adjustment_t *stock_adjustment);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**warehouse_id** | **char \*** |  | 
**stock_adjustment** | **[stock_adjustment_t](stock_adjustment.md) \*** |  | 

### Return type

[warehouse_stock_t](warehouse_stock.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WarehouseStockAPI_deleteWarehouseStock**
```c
void WarehouseStockAPI_deleteWarehouseStock(apiClient_t *apiClient, char *warehouse_id, char *product_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**warehouse_id** | **char \*** |  | 
**product_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WarehouseStockAPI_listWarehouseStock**
```c
list_t* WarehouseStockAPI_listWarehouseStock(apiClient_t *apiClient, char *warehouse_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**warehouse_id** | **char \*** |  | 

### Return type

[list_t](warehouse_stock.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WarehouseStockAPI_updateWarehouseStock**
```c
warehouse_stock_t* WarehouseStockAPI_updateWarehouseStock(apiClient_t *apiClient, char *warehouse_id, char *product_id, stock_adjustment_t *stock_adjustment);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**warehouse_id** | **char \*** |  | 
**product_id** | **char \*** |  | 
**stock_adjustment** | **[stock_adjustment_t](stock_adjustment.md) \*** |  | 

### Return type

[warehouse_stock_t](warehouse_stock.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

