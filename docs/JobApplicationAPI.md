# JobApplicationAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**JobApplicationAPI_applyPublic**](JobApplicationAPI.md#JobApplicationAPI_applyPublic) | **POST** /api/v1/public/jobs/{posting_id}/apply | 
[**JobApplicationAPI_deleteJobApplication**](JobApplicationAPI.md#JobApplicationAPI_deleteJobApplication) | **DELETE** /api/v1/job-applications/{application_id} | 
[**JobApplicationAPI_downloadCv**](JobApplicationAPI.md#JobApplicationAPI_downloadCv) | **GET** /api/v1/job-applications/{application_id}/cv | 
[**JobApplicationAPI_getJobApplication**](JobApplicationAPI.md#JobApplicationAPI_getJobApplication) | **GET** /api/v1/job-applications/{application_id} | 
[**JobApplicationAPI_inboundEmail**](JobApplicationAPI.md#JobApplicationAPI_inboundEmail) | **POST** /api/v1/public/jobs/inbound-email | Inbound CV email, mailgun/sendgrid inbound-parse style: multipart form with &#x60;from&#x60;, &#x60;subject&#x60;, &#x60;body-plain&#x60; and one or more &#x60;attachment-N&#x60; file fields. The subject may reference a posting as &#x60;[JOB-&lt;posting_id&gt;]&#x60;; without one the application lands in the general inbox.
[**JobApplicationAPI_listJobApplications**](JobApplicationAPI.md#JobApplicationAPI_listJobApplications) | **GET** /api/v1/job-applications | 
[**JobApplicationAPI_listPublicPostings**](JobApplicationAPI.md#JobApplicationAPI_listPublicPostings) | **GET** /api/v1/public/jobs | 
[**JobApplicationAPI_scoreJobApplication**](JobApplicationAPI.md#JobApplicationAPI_scoreJobApplication) | **POST** /api/v1/job-applications/{application_id}/score | 
[**JobApplicationAPI_updateJobApplicationStatus**](JobApplicationAPI.md#JobApplicationAPI_updateJobApplicationStatus) | **PATCH** /api/v1/job-applications/{application_id}/status | 


# **JobApplicationAPI_applyPublic**
```c
void JobApplicationAPI_applyPublic(apiClient_t *apiClient, char *posting_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**posting_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **JobApplicationAPI_deleteJobApplication**
```c
job_application_t* JobApplicationAPI_deleteJobApplication(apiClient_t *apiClient, char *application_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**application_id** | **char \*** |  | 

### Return type

[job_application_t](job_application.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **JobApplicationAPI_downloadCv**
```c
void JobApplicationAPI_downloadCv(apiClient_t *apiClient, char *application_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**application_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **JobApplicationAPI_getJobApplication**
```c
job_application_t* JobApplicationAPI_getJobApplication(apiClient_t *apiClient, char *application_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**application_id** | **char \*** |  | 

### Return type

[job_application_t](job_application.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **JobApplicationAPI_inboundEmail**
```c
// Inbound CV email, mailgun/sendgrid inbound-parse style: multipart form with `from`, `subject`, `body-plain` and one or more `attachment-N` file fields. The subject may reference a posting as `[JOB-<posting_id>]`; without one the application lands in the general inbox.
//
void JobApplicationAPI_inboundEmail(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **JobApplicationAPI_listJobApplications**
```c
list_t* JobApplicationAPI_listJobApplications(apiClient_t *apiClient, char *postingId, char *status, int *page, int *pageSize);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**postingId** | **char \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**page** | **int \*** |  | [optional] 
**pageSize** | **int \*** |  | [optional] 

### Return type

[list_t](job_application.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **JobApplicationAPI_listPublicPostings**
```c
list_t* JobApplicationAPI_listPublicPostings(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](public_posting.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **JobApplicationAPI_scoreJobApplication**
```c
job_application_t* JobApplicationAPI_scoreJobApplication(apiClient_t *apiClient, char *application_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**application_id** | **char \*** |  | 

### Return type

[job_application_t](job_application.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **JobApplicationAPI_updateJobApplicationStatus**
```c
job_application_t* JobApplicationAPI_updateJobApplicationStatus(apiClient_t *apiClient, char *application_id, application_status_dto_t *application_status_dto);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**application_id** | **char \*** |  | 
**application_status_dto** | **[application_status_dto_t](application_status_dto.md) \*** |  | 

### Return type

[job_application_t](job_application.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

