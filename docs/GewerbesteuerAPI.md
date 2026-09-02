# GewerbesteuerAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GewerbesteuerAPI_gewerbesteuerApi**](GewerbesteuerAPI.md#GewerbesteuerAPI_gewerbesteuerApi) | **GET** /api/v1/bookkeeping/gewerbesteuer | 


# **GewerbesteuerAPI_gewerbesteuerApi**
```c
gewerbesteuer_ergebnis_t* GewerbesteuerAPI_gewerbesteuerApi(apiClient_t *apiClient, int *year, char *hebesatz, char *gewerbeertrag, char *country, char *gemeindeschluessel);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 
**hebesatz** | **char \*** |  | [optional] 
**gewerbeertrag** | **char \*** |  | [optional] 
**country** | **char \*** |  | [optional] 
**gemeindeschluessel** | **char \*** |  | [optional] 

### Return type

[gewerbesteuer_ergebnis_t](gewerbesteuer_ergebnis.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

