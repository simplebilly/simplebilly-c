# ReplenishmentAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ReplenishmentAPI_applyReplenishments**](ReplenishmentAPI.md#ReplenishmentAPI_applyReplenishments) | **POST** /api/v1/replenishments/apply | Create one draft stock transfer per (source → target) pair carrying all suggested product lines for that pair.
[**ReplenishmentAPI_getReplenishments**](ReplenishmentAPI.md#ReplenishmentAPI_getReplenishments) | **GET** /api/v1/replenishments | 


# **ReplenishmentAPI_applyReplenishments**
```c
// Create one draft stock transfer per (source → target) pair carrying all suggested product lines for that pair.
//
any_type_t* ReplenishmentAPI_applyReplenishments(apiClient_t *apiClient, char *targetWarehouseId, char *sourceWarehouseId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**targetWarehouseId** | **char \*** | Warehouse to be replenished. Defaults to the tenant&#39;s default warehouse. | [optional] 
**sourceWarehouseId** | **char \*** | Restrict source warehouses to this id. | [optional] 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReplenishmentAPI_getReplenishments**
```c
replenishment_response_t* ReplenishmentAPI_getReplenishments(apiClient_t *apiClient, char *targetWarehouseId, char *sourceWarehouseId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**targetWarehouseId** | **char \*** | Warehouse to be replenished. Defaults to the tenant&#39;s default warehouse. | [optional] 
**sourceWarehouseId** | **char \*** | Restrict source warehouses to this id. | [optional] 

### Return type

[replenishment_response_t](replenishment_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

