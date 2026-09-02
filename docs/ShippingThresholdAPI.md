# ShippingThresholdAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ShippingThresholdAPI_createShippingThreshold**](ShippingThresholdAPI.md#ShippingThresholdAPI_createShippingThreshold) | **POST** /api/v1/shipping-thresholds | 
[**ShippingThresholdAPI_deleteShippingThreshold**](ShippingThresholdAPI.md#ShippingThresholdAPI_deleteShippingThreshold) | **DELETE** /api/v1/shipping-thresholds/{threshold_id} | 
[**ShippingThresholdAPI_getDeliverable**](ShippingThresholdAPI.md#ShippingThresholdAPI_getDeliverable) | **GET** /api/v1/shipping-thresholds/deliverable | 
[**ShippingThresholdAPI_getShippingThreshold**](ShippingThresholdAPI.md#ShippingThresholdAPI_getShippingThreshold) | **GET** /api/v1/shipping-thresholds/{threshold_id} | 
[**ShippingThresholdAPI_listShippingThresholds**](ShippingThresholdAPI.md#ShippingThresholdAPI_listShippingThresholds) | **GET** /api/v1/shipping-thresholds/ | 
[**ShippingThresholdAPI_updateShippingThreshold**](ShippingThresholdAPI.md#ShippingThresholdAPI_updateShippingThreshold) | **PUT** /api/v1/shipping-thresholds/{threshold_id} | 


# **ShippingThresholdAPI_createShippingThreshold**
```c
shipping_threshold_t* ShippingThresholdAPI_createShippingThreshold(apiClient_t *apiClient, shipping_threshold_create_t *shipping_threshold_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**shipping_threshold_create** | **[shipping_threshold_create_t](shipping_threshold_create.md) \*** |  | 

### Return type

[shipping_threshold_t](shipping_threshold.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShippingThresholdAPI_deleteShippingThreshold**
```c
void ShippingThresholdAPI_deleteShippingThreshold(apiClient_t *apiClient, char *threshold_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**threshold_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShippingThresholdAPI_getDeliverable**
```c
deliverable_response_t* ShippingThresholdAPI_getDeliverable(apiClient_t *apiClient, char *productId, char *warehouseId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**productId** | **char \*** |  | 
**warehouseId** | **char \*** |  | [optional] 

### Return type

[deliverable_response_t](deliverable_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShippingThresholdAPI_getShippingThreshold**
```c
shipping_threshold_t* ShippingThresholdAPI_getShippingThreshold(apiClient_t *apiClient, char *threshold_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**threshold_id** | **char \*** |  | 

### Return type

[shipping_threshold_t](shipping_threshold.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShippingThresholdAPI_listShippingThresholds**
```c
list_t* ShippingThresholdAPI_listShippingThresholds(apiClient_t *apiClient, int *page, int *page_size, char *product_id, char *warehouse_id, int *is_active);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**product_id** | **char \*** |  | [optional] 
**warehouse_id** | **char \*** |  | [optional] 
**is_active** | **int \*** |  | [optional] 

### Return type

[list_t](shipping_threshold.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShippingThresholdAPI_updateShippingThreshold**
```c
shipping_threshold_t* ShippingThresholdAPI_updateShippingThreshold(apiClient_t *apiClient, char *threshold_id, shipping_threshold_update_t *shipping_threshold_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**threshold_id** | **char \*** |  | 
**shipping_threshold_update** | **[shipping_threshold_update_t](shipping_threshold_update.md) \*** |  | 

### Return type

[shipping_threshold_t](shipping_threshold.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

