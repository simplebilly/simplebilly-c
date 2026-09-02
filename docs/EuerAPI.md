# EuerAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**EuerAPI_euerApi**](EuerAPI.md#EuerAPI_euerApi) | **GET** /api/v1/bookkeeping/euer | 
[**EuerAPI_euerKategorienApi**](EuerAPI.md#EuerAPI_euerKategorienApi) | **GET** /api/v1/bookkeeping/euer/kategorien | 


# **EuerAPI_euerApi**
```c
euer_ergebnis_t* EuerAPI_euerApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[euer_ergebnis_t](euer_ergebnis.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EuerAPI_euerKategorienApi**
```c
euer_detail_ergebnis_t* EuerAPI_euerKategorienApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[euer_detail_ergebnis_t](euer_detail_ergebnis.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

