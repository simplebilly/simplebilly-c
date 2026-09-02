# ReturnOrderAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ReturnOrderAPI_createReturnOrder**](ReturnOrderAPI.md#ReturnOrderAPI_createReturnOrder) | **POST** /api/v1/returns | 
[**ReturnOrderAPI_deleteReturnOrder**](ReturnOrderAPI.md#ReturnOrderAPI_deleteReturnOrder) | **DELETE** /api/v1/returns/{return_order_id} | 
[**ReturnOrderAPI_getReturnOrder**](ReturnOrderAPI.md#ReturnOrderAPI_getReturnOrder) | **GET** /api/v1/returns/{return_order_id} | 
[**ReturnOrderAPI_listReturnOrders**](ReturnOrderAPI.md#ReturnOrderAPI_listReturnOrders) | **GET** /api/v1/returns/ | 
[**ReturnOrderAPI_returnLogisticsQueue**](ReturnOrderAPI.md#ReturnOrderAPI_returnLogisticsQueue) | **GET** /api/v1/returns/logistics-queue | 
[**ReturnOrderAPI_returnLogisticsSummary**](ReturnOrderAPI.md#ReturnOrderAPI_returnLogisticsSummary) | **GET** /api/v1/returns/logistics-summary | Returns-logistics aggregation for the dashboard: quantities received, restocked and scrapped per warehouse.
[**ReturnOrderAPI_updateReturnOrder**](ReturnOrderAPI.md#ReturnOrderAPI_updateReturnOrder) | **PUT** /api/v1/returns/{return_order_id} | 
[**ReturnOrderAPI_updateReturnOrderStatus**](ReturnOrderAPI.md#ReturnOrderAPI_updateReturnOrderStatus) | **PUT** /api/v1/returns/{return_order_id}/status | 


# **ReturnOrderAPI_createReturnOrder**
```c
return_order_t* ReturnOrderAPI_createReturnOrder(apiClient_t *apiClient, return_order_t *return_order);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**return_order** | **[return_order_t](return_order.md) \*** |  | 

### Return type

[return_order_t](return_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReturnOrderAPI_deleteReturnOrder**
```c
void ReturnOrderAPI_deleteReturnOrder(apiClient_t *apiClient, char *return_order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**return_order_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReturnOrderAPI_getReturnOrder**
```c
return_order_t* ReturnOrderAPI_getReturnOrder(apiClient_t *apiClient, char *return_order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**return_order_id** | **char \*** |  | 

### Return type

[return_order_t](return_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReturnOrderAPI_listReturnOrders**
```c
list_t* ReturnOrderAPI_listReturnOrders(apiClient_t *apiClient, int *page, int *page_size, char *status, char *customer_name, char *order_number);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**customer_name** | **char \*** |  | [optional] 
**order_number** | **char \*** |  | [optional] 

### Return type

[list_t](return_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReturnOrderAPI_returnLogisticsQueue**
```c
list_t* ReturnOrderAPI_returnLogisticsQueue(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](return_logistics_queue_item.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReturnOrderAPI_returnLogisticsSummary**
```c
// Returns-logistics aggregation for the dashboard: quantities received, restocked and scrapped per warehouse.
//
return_logistics_summary_t* ReturnOrderAPI_returnLogisticsSummary(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[return_logistics_summary_t](return_logistics_summary.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReturnOrderAPI_updateReturnOrder**
```c
return_order_t* ReturnOrderAPI_updateReturnOrder(apiClient_t *apiClient, char *return_order_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**return_order_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[return_order_t](return_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReturnOrderAPI_updateReturnOrderStatus**
```c
return_order_t* ReturnOrderAPI_updateReturnOrderStatus(apiClient_t *apiClient, char *return_order_id, return_order_status_update_t *return_order_status_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**return_order_id** | **char \*** |  | 
**return_order_status_update** | **[return_order_status_update_t](return_order_status_update.md) \*** |  | 

### Return type

[return_order_t](return_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

