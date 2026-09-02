# UstvaAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**UstvaAPI_jahresustApi**](UstvaAPI.md#UstvaAPI_jahresustApi) | **GET** /api/v1/bookkeeping/jahresust | 
[**UstvaAPI_ustvaApi**](UstvaAPI.md#UstvaAPI_ustvaApi) | **GET** /api/v1/bookkeeping/ustva | 


# **UstvaAPI_jahresustApi**
```c
jahres_ust_ergebnis_t* UstvaAPI_jahresustApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[jahres_ust_ergebnis_t](jahres_ust_ergebnis.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UstvaAPI_ustvaApi**
```c
ustva_ergebnis_t* UstvaAPI_ustvaApi(apiClient_t *apiClient, char *zeitraum);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**zeitraum** | **char \*** |  | 

### Return type

[ustva_ergebnis_t](ustva_ergebnis.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

