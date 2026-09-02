# DatevAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DatevAPI_datevExportApi**](DatevAPI.md#DatevAPI_datevExportApi) | **GET** /api/v1/bookkeeping/datev/export | Export bookkeeping data as DATEV CSV
[**DatevAPI_datevPreviewApi**](DatevAPI.md#DatevAPI_datevPreviewApi) | **GET** /api/v1/bookkeeping/datev/preview | Exported_datev_bookings: returns formed bookings for review


# **DatevAPI_datevExportApi**
```c
// Export bookkeeping data as DATEV CSV
//
datev_export_response_t* DatevAPI_datevExportApi(apiClient_t *apiClient, char *account_schema, char *date_from, char *date_to, int *page, int *page_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**account_schema** | **char \*** |  | [optional] 
**date_from** | **char \*** |  | [optional] 
**date_to** | **char \*** |  | [optional] 
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 

### Return type

[datev_export_response_t](datev_export_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DatevAPI_datevPreviewApi**
```c
// Exported_datev_bookings: returns formed bookings for review
//
list_t* DatevAPI_datevPreviewApi(apiClient_t *apiClient, char *account_schema, char *date_from, char *date_to, int *page, int *page_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**account_schema** | **char \*** |  | [optional] 
**date_from** | **char \*** |  | [optional] 
**date_to** | **char \*** |  | [optional] 
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 

### Return type

[list_t](datev_booking_preview.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

