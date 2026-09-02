# StilleAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**StilleAPI_stilleExportApi**](StilleAPI.md#StilleAPI_stilleExportApi) | **GET** /api/v1/bookkeeping/stille/export | 
[**StilleAPI_stilleReportApi**](StilleAPI.md#StilleAPI_stilleReportApi) | **GET** /api/v1/bookkeeping/stille/report | 


# **StilleAPI_stilleExportApi**
```c
stille_export_response_t* StilleAPI_stilleExportApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[stille_export_response_t](stille_export_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StilleAPI_stilleReportApi**
```c
stille_report_t* StilleAPI_stilleReportApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[stille_report_t](stille_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

