# GewinnverwendungAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GewinnverwendungAPI_gewinnverwendungApi**](GewinnverwendungAPI.md#GewinnverwendungAPI_gewinnverwendungApi) | **GET** /api/v1/bookkeeping/gewinnverwendung | 
[**GewinnverwendungAPI_gewinnverwendungExportApi**](GewinnverwendungAPI.md#GewinnverwendungAPI_gewinnverwendungExportApi) | **GET** /api/v1/bookkeeping/gewinnverwendung/export | 


# **GewinnverwendungAPI_gewinnverwendungApi**
```c
gewinnverwendungs_report_t* GewinnverwendungAPI_gewinnverwendungApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[gewinnverwendungs_report_t](gewinnverwendungs_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **GewinnverwendungAPI_gewinnverwendungExportApi**
```c
gewinnverwendungs_export_response_t* GewinnverwendungAPI_gewinnverwendungExportApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[gewinnverwendungs_export_response_t](gewinnverwendungs_export_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

