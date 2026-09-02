# ProductionOrderAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ProductionOrderAPI_createProductionOrder**](ProductionOrderAPI.md#ProductionOrderAPI_createProductionOrder) | **POST** /api/v1/production-orders | 
[**ProductionOrderAPI_deleteProductionOrder**](ProductionOrderAPI.md#ProductionOrderAPI_deleteProductionOrder) | **DELETE** /api/v1/production-orders/{production_order_id} | 
[**ProductionOrderAPI_getProductionOrder**](ProductionOrderAPI.md#ProductionOrderAPI_getProductionOrder) | **GET** /api/v1/production-orders/{production_order_id} | 
[**ProductionOrderAPI_listProductionOrders**](ProductionOrderAPI.md#ProductionOrderAPI_listProductionOrders) | **GET** /api/v1/production-orders/ | 
[**ProductionOrderAPI_productionOrderCosting**](ProductionOrderAPI.md#ProductionOrderAPI_productionOrderCosting) | **GET** /api/v1/production-orders/{production_order_id}/costing | Actual-costing report (Nachkalkulation) — material costs from BOM components at their purchase price plus the resulting per-unit cost and margin against the finished product&#39;s sale price.
[**ProductionOrderAPI_updateProductionOrder**](ProductionOrderAPI.md#ProductionOrderAPI_updateProductionOrder) | **PUT** /api/v1/production-orders/{production_order_id} | 
[**ProductionOrderAPI_updateProductionOrderStatus**](ProductionOrderAPI.md#ProductionOrderAPI_updateProductionOrderStatus) | **PUT** /api/v1/production-orders/{production_order_id}/status | 


# **ProductionOrderAPI_createProductionOrder**
```c
production_order_t* ProductionOrderAPI_createProductionOrder(apiClient_t *apiClient, production_order_t *production_order);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**production_order** | **[production_order_t](production_order.md) \*** |  | 

### Return type

[production_order_t](production_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductionOrderAPI_deleteProductionOrder**
```c
void ProductionOrderAPI_deleteProductionOrder(apiClient_t *apiClient, char *production_order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**production_order_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductionOrderAPI_getProductionOrder**
```c
production_order_t* ProductionOrderAPI_getProductionOrder(apiClient_t *apiClient, char *production_order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**production_order_id** | **char \*** |  | 

### Return type

[production_order_t](production_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductionOrderAPI_listProductionOrders**
```c
list_t* ProductionOrderAPI_listProductionOrders(apiClient_t *apiClient, int *page, int *pageSize, char *search, char *status);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**pageSize** | **int \*** |  | [optional] 
**search** | **char \*** |  | [optional] 
**status** | **char \*** | Filter by status. | [optional] 

### Return type

[list_t](production_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductionOrderAPI_productionOrderCosting**
```c
// Actual-costing report (Nachkalkulation) — material costs from BOM components at their purchase price plus the resulting per-unit cost and margin against the finished product's sale price.
//
production_order_costing_t* ProductionOrderAPI_productionOrderCosting(apiClient_t *apiClient, char *production_order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**production_order_id** | **char \*** |  | 

### Return type

[production_order_costing_t](production_order_costing.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductionOrderAPI_updateProductionOrder**
```c
production_order_t* ProductionOrderAPI_updateProductionOrder(apiClient_t *apiClient, char *production_order_id, production_order_t *production_order);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**production_order_id** | **char \*** |  | 
**production_order** | **[production_order_t](production_order.md) \*** |  | 

### Return type

[production_order_t](production_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductionOrderAPI_updateProductionOrderStatus**
```c
production_order_t* ProductionOrderAPI_updateProductionOrderStatus(apiClient_t *apiClient, char *production_order_id, production_order_status_update_t *production_order_status_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**production_order_id** | **char \*** |  | 
**production_order_status_update** | **[production_order_status_update_t](production_order_status_update.md) \*** |  | 

### Return type

[production_order_t](production_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

