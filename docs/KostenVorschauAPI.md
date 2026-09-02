# KostenVorschauAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**KostenVorschauAPI_kostenVorschauApi**](KostenVorschauAPI.md#KostenVorschauAPI_kostenVorschauApi) | **GET** /api/v1/bookkeeping/kosten-vorschau | 


# **KostenVorschauAPI_kostenVorschauApi**
```c
kosten_vorschau_t* KostenVorschauAPI_kostenVorschauApi(apiClient_t *apiClient, int *year, int *month);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 
**month** | **int \*** |  | 

### Return type

[kosten_vorschau_t](kosten_vorschau.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

