# ServiceJobAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ServiceJobAPI_createServiceJob**](ServiceJobAPI.md#ServiceJobAPI_createServiceJob) | **POST** /api/v1/service-jobs | 
[**ServiceJobAPI_deleteServiceJob**](ServiceJobAPI.md#ServiceJobAPI_deleteServiceJob) | **DELETE** /api/v1/service-jobs/{id} | 
[**ServiceJobAPI_getServiceJob**](ServiceJobAPI.md#ServiceJobAPI_getServiceJob) | **GET** /api/v1/service-jobs/{id} | 
[**ServiceJobAPI_getServiceJobs**](ServiceJobAPI.md#ServiceJobAPI_getServiceJobs) | **GET** /api/v1/service-jobs/ | 
[**ServiceJobAPI_updateServiceJob**](ServiceJobAPI.md#ServiceJobAPI_updateServiceJob) | **PUT** /api/v1/service-jobs/{id} | 


# **ServiceJobAPI_createServiceJob**
```c
service_job_t* ServiceJobAPI_createServiceJob(apiClient_t *apiClient, service_job_create_t *service_job_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**service_job_create** | **[service_job_create_t](service_job_create.md) \*** |  | 

### Return type

[service_job_t](service_job.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ServiceJobAPI_deleteServiceJob**
```c
void ServiceJobAPI_deleteServiceJob(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ServiceJobAPI_getServiceJob**
```c
service_job_t* ServiceJobAPI_getServiceJob(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[service_job_t](service_job.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ServiceJobAPI_getServiceJobs**
```c
list_t* ServiceJobAPI_getServiceJobs(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**search** | **char \*** |  | [optional] 
**include_deleted** | **int \*** | Soft-delete entities: set true to include rows with &#x60;deleted_at&#x60; set. | [optional] 

### Return type

[list_t](service_job.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ServiceJobAPI_updateServiceJob**
```c
service_job_t* ServiceJobAPI_updateServiceJob(apiClient_t *apiClient, char *id, service_job_update_t *service_job_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**service_job_update** | **[service_job_update_t](service_job_update.md) \*** |  | 

### Return type

[service_job_t](service_job.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

