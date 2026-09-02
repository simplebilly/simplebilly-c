# ReportsAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ReportsAPI_bilanzReportApi**](ReportsAPI.md#ReportsAPI_bilanzReportApi) | **GET** /api/v1/bookkeeping/reports/bilanz | Bilanz (Balance Sheet)
[**ReportsAPI_guvReportApi**](ReportsAPI.md#ReportsAPI_guvReportApi) | **GET** /api/v1/bookkeeping/reports/guv | Gewinn- und Verlustrechnung (P&amp;L statement)
[**ReportsAPI_kontenansichtReportApi**](ReportsAPI.md#ReportsAPI_kontenansichtReportApi) | **GET** /api/v1/bookkeeping/reports/kontenansicht | Kontenansicht (Account Overview)
[**ReportsAPI_umsatzsteuerReportApi**](ReportsAPI.md#ReportsAPI_umsatzsteuerReportApi) | **GET** /api/v1/bookkeeping/reports/umsatzsteuer | Umsatzsteuer-Voranmeldung (VAT report)


# **ReportsAPI_bilanzReportApi**
```c
// Bilanz (Balance Sheet)
//
bilanz_report_t* ReportsAPI_bilanzReportApi(apiClient_t *apiClient, int *year, int *month, char *date_from, char *date_to, int *page, int *page_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | [optional] 
**month** | **int \*** |  | [optional] 
**date_from** | **char \*** |  | [optional] 
**date_to** | **char \*** |  | [optional] 
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 

### Return type

[bilanz_report_t](bilanz_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReportsAPI_guvReportApi**
```c
// Gewinn- und Verlustrechnung (P&L statement)
//
gu_v_report_t* ReportsAPI_guvReportApi(apiClient_t *apiClient, int *year, int *month, char *date_from, char *date_to, int *page, int *page_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | [optional] 
**month** | **int \*** |  | [optional] 
**date_from** | **char \*** |  | [optional] 
**date_to** | **char \*** |  | [optional] 
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 

### Return type

[gu_v_report_t](gu_v_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReportsAPI_kontenansichtReportApi**
```c
// Kontenansicht (Account Overview)
//
konto_report_t* ReportsAPI_kontenansichtReportApi(apiClient_t *apiClient, int *year, int *month, char *date_from, char *date_to, int *page, int *page_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | [optional] 
**month** | **int \*** |  | [optional] 
**date_from** | **char \*** |  | [optional] 
**date_to** | **char \*** |  | [optional] 
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 

### Return type

[konto_report_t](konto_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReportsAPI_umsatzsteuerReportApi**
```c
// Umsatzsteuer-Voranmeldung (VAT report)
//
umsatzsteuer_report_t* ReportsAPI_umsatzsteuerReportApi(apiClient_t *apiClient, int *year, int *month, char *date_from, char *date_to, int *page, int *page_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | [optional] 
**month** | **int \*** |  | [optional] 
**date_from** | **char \*** |  | [optional] 
**date_to** | **char \*** |  | [optional] 
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 

### Return type

[umsatzsteuer_report_t](umsatzsteuer_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

