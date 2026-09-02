# ImportRunnerAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ImportRunnerAPI_getImportStatus**](ImportRunnerAPI.md#ImportRunnerAPI_getImportStatus) | **GET** /api/v1/import/{job_id} | 
[**ImportRunnerAPI_startImport**](ImportRunnerAPI.md#ImportRunnerAPI_startImport) | **POST** /api/v1/import/start | 
[**ImportRunnerAPI_testImportConnection**](ImportRunnerAPI.md#ImportRunnerAPI_testImportConnection) | **POST** /api/v1/import/test | 


# **ImportRunnerAPI_getImportStatus**
```c
import_job_status_t* ImportRunnerAPI_getImportStatus(apiClient_t *apiClient, char *job_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**job_id** | **char \*** |  | 

### Return type

[import_job_status_t](import_job_status.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ImportRunnerAPI_startImport**
```c
import_start_response_t* ImportRunnerAPI_startImport(apiClient_t *apiClient, import_start_request_t *import_start_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**import_start_request** | **[import_start_request_t](import_start_request.md) \*** |  | 

### Return type

[import_start_response_t](import_start_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ImportRunnerAPI_testImportConnection**
```c
import_test_response_t* ImportRunnerAPI_testImportConnection(apiClient_t *apiClient, import_test_request_t *import_test_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**import_test_request** | **[import_test_request_t](import_test_request.md) \*** |  | 

### Return type

[import_test_response_t](import_test_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

