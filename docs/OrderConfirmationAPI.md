# OrderConfirmationAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**OrderConfirmationAPI_createConfirmation**](OrderConfirmationAPI.md#OrderConfirmationAPI_createConfirmation) | **POST** /api/v1/order-confirmations | 
[**OrderConfirmationAPI_deleteConfirmation**](OrderConfirmationAPI.md#OrderConfirmationAPI_deleteConfirmation) | **DELETE** /api/v1/order-confirmations/{confirmation_id} | 
[**OrderConfirmationAPI_downloadConfirmationPdf**](OrderConfirmationAPI.md#OrderConfirmationAPI_downloadConfirmationPdf) | **GET** /api/v1/order-confirmations/{confirmation_id}/pdf | 
[**OrderConfirmationAPI_getConfirmation**](OrderConfirmationAPI.md#OrderConfirmationAPI_getConfirmation) | **GET** /api/v1/order-confirmations/{confirmation_id} | 
[**OrderConfirmationAPI_listConfirmations**](OrderConfirmationAPI.md#OrderConfirmationAPI_listConfirmations) | **GET** /api/v1/order-confirmations/ | 
[**OrderConfirmationAPI_orderconfirmationRestore**](OrderConfirmationAPI.md#OrderConfirmationAPI_orderconfirmationRestore) | **POST** /api/v1/order-confirmations/{confirmation_id}/restore | 
[**OrderConfirmationAPI_pursueConfirmation**](OrderConfirmationAPI.md#OrderConfirmationAPI_pursueConfirmation) | **POST** /api/v1/order-confirmations/{confirmation_id}/pursue | 


# **OrderConfirmationAPI_createConfirmation**
```c
order_confirmation_t* OrderConfirmationAPI_createConfirmation(apiClient_t *apiClient, order_confirmation_create_t *order_confirmation_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_confirmation_create** | **[order_confirmation_create_t](order_confirmation_create.md) \*** |  | 

### Return type

[order_confirmation_t](order_confirmation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OrderConfirmationAPI_deleteConfirmation**
```c
void OrderConfirmationAPI_deleteConfirmation(apiClient_t *apiClient, char *confirmation_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**confirmation_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OrderConfirmationAPI_downloadConfirmationPdf**
```c
void OrderConfirmationAPI_downloadConfirmationPdf(apiClient_t *apiClient, char *confirmation_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**confirmation_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/pdf, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OrderConfirmationAPI_getConfirmation**
```c
order_confirmation_t* OrderConfirmationAPI_getConfirmation(apiClient_t *apiClient, char *confirmation_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**confirmation_id** | **char \*** |  | 

### Return type

[order_confirmation_t](order_confirmation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OrderConfirmationAPI_listConfirmations**
```c
list_t* OrderConfirmationAPI_listConfirmations(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](order_confirmation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OrderConfirmationAPI_orderconfirmationRestore**
```c
order_confirmation_t* OrderConfirmationAPI_orderconfirmationRestore(apiClient_t *apiClient, char *confirmation_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**confirmation_id** | **char \*** |  | 

### Return type

[order_confirmation_t](order_confirmation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OrderConfirmationAPI_pursueConfirmation**
```c
delivery_note_t* OrderConfirmationAPI_pursueConfirmation(apiClient_t *apiClient, char *confirmation_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**confirmation_id** | **char \*** |  | 

### Return type

[delivery_note_t](delivery_note.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

