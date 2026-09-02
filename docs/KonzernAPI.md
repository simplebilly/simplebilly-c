# KonzernAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**KonzernAPI_konzernExportApi**](KonzernAPI.md#KonzernAPI_konzernExportApi) | **GET** /api/v1/bookkeeping/konzern/status/export | 
[**KonzernAPI_konzernStatusApi**](KonzernAPI.md#KonzernAPI_konzernStatusApi) | **GET** /api/v1/bookkeeping/konzern/status | 


# **KonzernAPI_konzernExportApi**
```c
konzern_export_response_t* KonzernAPI_konzernExportApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[konzern_export_response_t](konzern_export_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **KonzernAPI_konzernStatusApi**
```c
konzern_status_t* KonzernAPI_konzernStatusApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[konzern_status_t](konzern_status.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

