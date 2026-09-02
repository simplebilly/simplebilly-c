# RfqAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**RfqAPI_convertRfq**](RfqAPI.md#RfqAPI_convertRfq) | **POST** /api/v1/rfqs/{rfq_id}/convert | Convert an RFQ into a draft purchase order using the quoted unit prices (falling back to the requested prices, then leaving them blank). Marks the RFQ as &#x60;converted&#x60;.
[**RfqAPI_createRfq**](RfqAPI.md#RfqAPI_createRfq) | **POST** /api/v1/rfqs | 
[**RfqAPI_deleteRfq**](RfqAPI.md#RfqAPI_deleteRfq) | **DELETE** /api/v1/rfqs/{rfq_id} | 
[**RfqAPI_getRfq**](RfqAPI.md#RfqAPI_getRfq) | **GET** /api/v1/rfqs/{rfq_id} | 
[**RfqAPI_listRfqs**](RfqAPI.md#RfqAPI_listRfqs) | **GET** /api/v1/rfqs/ | 
[**RfqAPI_updateRfq**](RfqAPI.md#RfqAPI_updateRfq) | **PUT** /api/v1/rfqs/{rfq_id} | 
[**RfqAPI_updateRfqStatus**](RfqAPI.md#RfqAPI_updateRfqStatus) | **PUT** /api/v1/rfqs/{rfq_id}/status | 


# **RfqAPI_convertRfq**
```c
// Convert an RFQ into a draft purchase order using the quoted unit prices (falling back to the requested prices, then leaving them blank). Marks the RFQ as `converted`.
//
any_type_t* RfqAPI_convertRfq(apiClient_t *apiClient, char *rfq_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**rfq_id** | **char \*** |  | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RfqAPI_createRfq**
```c
rfq_t* RfqAPI_createRfq(apiClient_t *apiClient, rfq_t *rfq);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**rfq** | **[rfq_t](rfq.md) \*** |  | 

### Return type

[rfq_t](rfq.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RfqAPI_deleteRfq**
```c
void RfqAPI_deleteRfq(apiClient_t *apiClient, char *rfq_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**rfq_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RfqAPI_getRfq**
```c
rfq_t* RfqAPI_getRfq(apiClient_t *apiClient, char *rfq_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**rfq_id** | **char \*** |  | 

### Return type

[rfq_t](rfq.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RfqAPI_listRfqs**
```c
list_t* RfqAPI_listRfqs(apiClient_t *apiClient, int *page, int *page_size, char *status, char *supplier_name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**supplier_name** | **char \*** |  | [optional] 

### Return type

[list_t](rfq.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RfqAPI_updateRfq**
```c
rfq_t* RfqAPI_updateRfq(apiClient_t *apiClient, char *rfq_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**rfq_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[rfq_t](rfq.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RfqAPI_updateRfqStatus**
```c
rfq_t* RfqAPI_updateRfqStatus(apiClient_t *apiClient, char *rfq_id, rfq_status_update_t *rfq_status_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**rfq_id** | **char \*** |  | 
**rfq_status_update** | **[rfq_status_update_t](rfq_status_update.md) \*** |  | 

### Return type

[rfq_t](rfq.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

