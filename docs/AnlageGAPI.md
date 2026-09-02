# AnlageGAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AnlageGAPI_anlageGApi**](AnlageGAPI.md#AnlageGAPI_anlageGApi) | **GET** /api/v1/bookkeeping/anlage-g | 


# **AnlageGAPI_anlageGApi**
```c
anlage_g_ergebnis_t* AnlageGAPI_anlageGApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[anlage_g_ergebnis_t](anlage_g_ergebnis.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

