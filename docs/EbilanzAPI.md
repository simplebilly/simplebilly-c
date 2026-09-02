# EbilanzAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**EbilanzAPI_ebilanzReportApi**](EbilanzAPI.md#EbilanzAPI_ebilanzReportApi) | **GET** /api/v1/bookkeeping/ebilanz | 
[**EbilanzAPI_ebilanzXbrlExportApi**](EbilanzAPI.md#EbilanzAPI_ebilanzXbrlExportApi) | **GET** /api/v1/bookkeeping/ebilanz/xbrl | 


# **EbilanzAPI_ebilanzReportApi**
```c
e_bilanz_report_t* EbilanzAPI_ebilanzReportApi(apiClient_t *apiClient, int *year, char *date_from, char *date_to);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | [optional] 
**date_from** | **char \*** |  | [optional] 
**date_to** | **char \*** |  | [optional] 

### Return type

[e_bilanz_report_t](e_bilanz_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EbilanzAPI_ebilanzXbrlExportApi**
```c
void EbilanzAPI_ebilanzXbrlExportApi(apiClient_t *apiClient, int *year, char *date_from, char *date_to);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | [optional] 
**date_from** | **char \*** |  | [optional] 
**date_to** | **char \*** |  | [optional] 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/xml

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

