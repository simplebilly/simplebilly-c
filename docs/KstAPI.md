# KstAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**KstAPI_kstApi**](KstAPI.md#KstAPI_kstApi) | **GET** /api/v1/bookkeeping/kst | 


# **KstAPI_kstApi**
```c
kst_ergebnis_t* KstAPI_kstApi(apiClient_t *apiClient, int *year, char *gewinn);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 
**gewinn** | **char \*** |  | [optional] 

### Return type

[kst_ergebnis_t](kst_ergebnis.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

