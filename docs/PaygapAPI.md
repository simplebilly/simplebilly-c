# PaygapAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PaygapAPI_paygapAuskunftApi**](PaygapAPI.md#PaygapAPI_paygapAuskunftApi) | **GET** /api/v1/bookkeeping/paygap/auskunft/{employee_id} | 
[**PaygapAPI_paygapExportApi**](PaygapAPI.md#PaygapAPI_paygapExportApi) | **GET** /api/v1/bookkeeping/paygap/export | 
[**PaygapAPI_paygapReportApi**](PaygapAPI.md#PaygapAPI_paygapReportApi) | **GET** /api/v1/bookkeeping/paygap/report | 


# **PaygapAPI_paygapAuskunftApi**
```c
pay_gap_info_response_t* PaygapAPI_paygapAuskunftApi(apiClient_t *apiClient, char *employee_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**employee_id** | **char \*** |  | 

### Return type

[pay_gap_info_response_t](pay_gap_info_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PaygapAPI_paygapExportApi**
```c
pay_gap_export_response_t* PaygapAPI_paygapExportApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[pay_gap_export_response_t](pay_gap_export_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PaygapAPI_paygapReportApi**
```c
pay_gap_report_t* PaygapAPI_paygapReportApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[pay_gap_report_t](pay_gap_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

