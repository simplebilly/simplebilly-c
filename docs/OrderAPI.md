# OrderAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**OrderAPI_addOrderTags**](OrderAPI.md#OrderAPI_addOrderTags) | **POST** /api/v1/orders/{order_id}/tags | 
[**OrderAPI_findOrderByExternalRef**](OrderAPI.md#OrderAPI_findOrderByExternalRef) | **GET** /api/v1/orders/by-ext-ref/{ext_ref} | 
[**OrderAPI_getOrder**](OrderAPI.md#OrderAPI_getOrder) | **GET** /api/v1/order/{order_number} | 
[**OrderAPI_getOrders**](OrderAPI.md#OrderAPI_getOrders) | **GET** /api/v1/orders | 
[**OrderAPI_patchOrder**](OrderAPI.md#OrderAPI_patchOrder) | **PATCH** /api/v1/orders/{order_id} | 
[**OrderAPI_replaceOrderTags**](OrderAPI.md#OrderAPI_replaceOrderTags) | **PUT** /api/v1/orders/{order_id}/tags | 
[**OrderAPI_updateOrderState**](OrderAPI.md#OrderAPI_updateOrderState) | **PUT** /api/v1/orders/{order_id}/state | 


# **OrderAPI_addOrderTags**
```c
order_t* OrderAPI_addOrderTags(apiClient_t *apiClient, char *order_id, order_tags_request_t *order_tags_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** |  | 
**order_tags_request** | **[order_tags_request_t](order_tags_request.md) \*** |  | 

### Return type

[order_t](order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OrderAPI_findOrderByExternalRef**
```c
order_t* OrderAPI_findOrderByExternalRef(apiClient_t *apiClient, char *ext_ref);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ext_ref** | **char \*** |  | 

### Return type

[order_t](order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OrderAPI_getOrder**
```c
order_t* OrderAPI_getOrder(apiClient_t *apiClient, char *order_number);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_number** | **char \*** |  | 

### Return type

[order_t](order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OrderAPI_getOrders**
```c
list_t* OrderAPI_getOrders(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**search** | **char \*** |  | [optional] 
**include_deleted** | **int \*** | Soft-delete entities: set true to include rows with &#x60;deleted_at&#x60; set. | [optional] 

### Return type

[list_t](order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OrderAPI_patchOrder**
```c
order_t* OrderAPI_patchOrder(apiClient_t *apiClient, char *order_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[order_t](order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OrderAPI_replaceOrderTags**
```c
order_t* OrderAPI_replaceOrderTags(apiClient_t *apiClient, char *order_id, order_tags_request_t *order_tags_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** |  | 
**order_tags_request** | **[order_tags_request_t](order_tags_request.md) \*** |  | 

### Return type

[order_t](order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OrderAPI_updateOrderState**
```c
order_t* OrderAPI_updateOrderState(apiClient_t *apiClient, char *order_id, order_state_update_t *order_state_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** |  | 
**order_state_update** | **[order_state_update_t](order_state_update.md) \*** |  | 

### Return type

[order_t](order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

