# PlausibilityAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PlausibilityAPI_plausibilityCheckApi**](PlausibilityAPI.md#PlausibilityAPI_plausibilityCheckApi) | **GET** /api/v1/bookkeeping/plausibility | 


# **PlausibilityAPI_plausibilityCheckApi**
```c
plausibility_report_t* PlausibilityAPI_plausibilityCheckApi(apiClient_t *apiClient, char *date_from, char *date_to);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**date_from** | **char \*** |  | [optional] 
**date_to** | **char \*** |  | [optional] 

### Return type

[plausibility_report_t](plausibility_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

