# InventoryValueAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InventoryValueAPI_getInventoryValueApi**](InventoryValueAPI.md#InventoryValueAPI_getInventoryValueApi) | **GET** /api/v1/bookkeeping/inventory-value | 
[**InventoryValueAPI_recordInventoryValueApi**](InventoryValueAPI.md#InventoryValueAPI_recordInventoryValueApi) | **POST** /api/v1/bookkeeping/inventory-value/record | 


# **InventoryValueAPI_getInventoryValueApi**
```c
current_inventory_value_t* InventoryValueAPI_getInventoryValueApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[current_inventory_value_t](current_inventory_value.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InventoryValueAPI_recordInventoryValueApi**
```c
inventory_value_point_t* InventoryValueAPI_recordInventoryValueApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[inventory_value_point_t](inventory_value_point.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

