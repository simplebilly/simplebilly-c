# JobPostingAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**JobPostingAPI_createJobPosting**](JobPostingAPI.md#JobPostingAPI_createJobPosting) | **POST** /api/v1/job-postings | 
[**JobPostingAPI_deleteJobPosting**](JobPostingAPI.md#JobPostingAPI_deleteJobPosting) | **DELETE** /api/v1/job-postings/{id} | 
[**JobPostingAPI_getJobPosting**](JobPostingAPI.md#JobPostingAPI_getJobPosting) | **GET** /api/v1/job-postings/{id} | 
[**JobPostingAPI_listJobPostings**](JobPostingAPI.md#JobPostingAPI_listJobPostings) | **GET** /api/v1/job-postings | 
[**JobPostingAPI_updateJobPosting**](JobPostingAPI.md#JobPostingAPI_updateJobPosting) | **PUT** /api/v1/job-postings/{id} | 


# **JobPostingAPI_createJobPosting**
```c
job_posting_t* JobPostingAPI_createJobPosting(apiClient_t *apiClient, job_posting_create_t *job_posting_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**job_posting_create** | **[job_posting_create_t](job_posting_create.md) \*** |  | 

### Return type

[job_posting_t](job_posting.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **JobPostingAPI_deleteJobPosting**
```c
void JobPostingAPI_deleteJobPosting(apiClient_t *apiClient, char *id);
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

# **JobPostingAPI_getJobPosting**
```c
job_posting_t* JobPostingAPI_getJobPosting(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[job_posting_t](job_posting.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **JobPostingAPI_listJobPostings**
```c
list_t* JobPostingAPI_listJobPostings(apiClient_t *apiClient, char *status, int *page, int *pageSize);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**status** | **char \*** |  | [optional] 
**page** | **int \*** |  | [optional] 
**pageSize** | **int \*** |  | [optional] 

### Return type

[list_t](job_posting.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **JobPostingAPI_updateJobPosting**
```c
job_posting_t* JobPostingAPI_updateJobPosting(apiClient_t *apiClient, char *id, job_posting_update_t *job_posting_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**job_posting_update** | **[job_posting_update_t](job_posting_update.md) \*** |  | 

### Return type

[job_posting_t](job_posting.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

