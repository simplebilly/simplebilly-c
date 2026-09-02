# AttachmentVersionAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AttachmentVersionAPI_createAttachmentVersion**](AttachmentVersionAPI.md#AttachmentVersionAPI_createAttachmentVersion) | **POST** /api/v1/attachments/{attachment_id}/versions | 
[**AttachmentVersionAPI_listAttachmentVersions**](AttachmentVersionAPI.md#AttachmentVersionAPI_listAttachmentVersions) | **GET** /api/v1/attachments/{attachment_id}/versions | 
[**AttachmentVersionAPI_restoreAttachmentVersion**](AttachmentVersionAPI.md#AttachmentVersionAPI_restoreAttachmentVersion) | **POST** /api/v1/attachments/{attachment_id}/versions/{version_id}/restore | 


# **AttachmentVersionAPI_createAttachmentVersion**
```c
attachment_version_t* AttachmentVersionAPI_createAttachmentVersion(apiClient_t *apiClient, char *attachment_id, new_version_request_t *new_version_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**attachment_id** | **char \*** |  | 
**new_version_request** | **[new_version_request_t](new_version_request.md) \*** |  | 

### Return type

[attachment_version_t](attachment_version.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AttachmentVersionAPI_listAttachmentVersions**
```c
list_t* AttachmentVersionAPI_listAttachmentVersions(apiClient_t *apiClient, char *attachment_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**attachment_id** | **char \*** |  | 

### Return type

[list_t](attachment_version.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AttachmentVersionAPI_restoreAttachmentVersion**
```c
attachment_t* AttachmentVersionAPI_restoreAttachmentVersion(apiClient_t *apiClient, char *attachment_id, char *version_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**attachment_id** | **char \*** |  | 
**version_id** | **char \*** |  | 

### Return type

[attachment_t](attachment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

