# AttachmentAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AttachmentAPI_attachmentRestore**](AttachmentAPI.md#AttachmentAPI_attachmentRestore) | **POST** /api/v1/attachments/{id}/restore | 
[**AttachmentAPI_createAttachment**](AttachmentAPI.md#AttachmentAPI_createAttachment) | **POST** /api/v1/attachments | 
[**AttachmentAPI_deleteAttachment**](AttachmentAPI.md#AttachmentAPI_deleteAttachment) | **DELETE** /api/v1/attachments/{id} | 
[**AttachmentAPI_getAttachment**](AttachmentAPI.md#AttachmentAPI_getAttachment) | **GET** /api/v1/attachments/{id} | 
[**AttachmentAPI_listAttachments**](AttachmentAPI.md#AttachmentAPI_listAttachments) | **GET** /api/v1/attachments/ | 
[**AttachmentAPI_saveAttachmentOcrText**](AttachmentAPI.md#AttachmentAPI_saveAttachmentOcrText) | **PUT** /api/v1/attachments/{attachment_id}/ocr-text | Persist client-side OCR output for an attachment.


# **AttachmentAPI_attachmentRestore**
```c
attachment_t* AttachmentAPI_attachmentRestore(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[attachment_t](attachment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AttachmentAPI_createAttachment**
```c
attachment_t* AttachmentAPI_createAttachment(apiClient_t *apiClient, attachment_create_t *attachment_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**attachment_create** | **[attachment_create_t](attachment_create.md) \*** |  | 

### Return type

[attachment_t](attachment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AttachmentAPI_deleteAttachment**
```c
void AttachmentAPI_deleteAttachment(apiClient_t *apiClient, char *id);
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

# **AttachmentAPI_getAttachment**
```c
attachment_t* AttachmentAPI_getAttachment(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[attachment_t](attachment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AttachmentAPI_listAttachments**
```c
list_t* AttachmentAPI_listAttachments(apiClient_t *apiClient, int *page, int *pageSize, char *contactId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**pageSize** | **int \*** |  | [optional] 
**contactId** | **char \*** |  | [optional] 

### Return type

[list_t](attachment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AttachmentAPI_saveAttachmentOcrText**
```c
// Persist client-side OCR output for an attachment.
//
attachment_t* AttachmentAPI_saveAttachmentOcrText(apiClient_t *apiClient, char *attachment_id, ocr_text_request_t *ocr_text_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**attachment_id** | **char \*** |  | 
**ocr_text_request** | **[ocr_text_request_t](ocr_text_request.md) \*** |  | 

### Return type

[attachment_t](attachment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

