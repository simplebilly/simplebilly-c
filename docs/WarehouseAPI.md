# WarehouseAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**WarehouseAPI_createWarehouse**](WarehouseAPI.md#WarehouseAPI_createWarehouse) | **POST** /api/v1/warehouses | 
[**WarehouseAPI_deleteWarehouse**](WarehouseAPI.md#WarehouseAPI_deleteWarehouse) | **DELETE** /api/v1/warehouses/{warehouse_id} | 
[**WarehouseAPI_getWarehouse**](WarehouseAPI.md#WarehouseAPI_getWarehouse) | **GET** /api/v1/warehouses/{warehouse_id} | 
[**WarehouseAPI_listWarehouses**](WarehouseAPI.md#WarehouseAPI_listWarehouses) | **GET** /api/v1/warehouses/ | 
[**WarehouseAPI_updateWarehouse**](WarehouseAPI.md#WarehouseAPI_updateWarehouse) | **PUT** /api/v1/warehouses/{warehouse_id} | 


# **WarehouseAPI_createWarehouse**
```c
warehouse_t* WarehouseAPI_createWarehouse(apiClient_t *apiClient, warehouse_t *warehouse);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**warehouse** | **[warehouse_t](warehouse.md) \*** |  | 

### Return type

[warehouse_t](warehouse.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WarehouseAPI_deleteWarehouse**
```c
void WarehouseAPI_deleteWarehouse(apiClient_t *apiClient, char *warehouse_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**warehouse_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WarehouseAPI_getWarehouse**
```c
warehouse_t* WarehouseAPI_getWarehouse(apiClient_t *apiClient, char *warehouse_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**warehouse_id** | **char \*** |  | 

### Return type

[warehouse_t](warehouse.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WarehouseAPI_listWarehouses**
```c
list_t* WarehouseAPI_listWarehouses(apiClient_t *apiClient, int *page, int *page_size, char *search, int *is_active);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**search** | **char \*** |  | [optional] 
**is_active** | **int \*** |  | [optional] 

### Return type

[list_t](warehouse.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WarehouseAPI_updateWarehouse**
```c
warehouse_t* WarehouseAPI_updateWarehouse(apiClient_t *apiClient, char *warehouse_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**warehouse_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[warehouse_t](warehouse.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

