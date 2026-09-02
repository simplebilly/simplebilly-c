# FristenAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**FristenAPI_fristenApi**](FristenAPI.md#FristenAPI_fristenApi) | **GET** /api/v1/bookkeeping/fristen | 


# **FristenAPI_fristenApi**
```c
fristen_ergebnis_t* FristenAPI_fristenApi(apiClient_t *apiClient, char *bundesland, char *voranmeldungsrhythmus, int *dauerfristverlaengerung, int *est_aktiv, int *gewst_aktiv, int *monate);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**bundesland** | **char \*** |  | [optional] 
**voranmeldungsrhythmus** | **char \*** |  | [optional] 
**dauerfristverlaengerung** | **int \*** |  | [optional] 
**est_aktiv** | **int \*** |  | [optional] 
**gewst_aktiv** | **int \*** |  | [optional] 
**monate** | **int \*** |  | [optional] 

### Return type

[fristen_ergebnis_t](fristen_ergebnis.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

