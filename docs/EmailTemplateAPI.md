# EmailTemplateAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**EmailTemplateAPI_createEmailTemplate**](EmailTemplateAPI.md#EmailTemplateAPI_createEmailTemplate) | **POST** /api/v1/email-templates | 
[**EmailTemplateAPI_deleteEmailTemplate**](EmailTemplateAPI.md#EmailTemplateAPI_deleteEmailTemplate) | **DELETE** /api/v1/email-templates/{email_template_id} | 
[**EmailTemplateAPI_getEmailTemplate**](EmailTemplateAPI.md#EmailTemplateAPI_getEmailTemplate) | **GET** /api/v1/email-templates/{email_template_id} | 
[**EmailTemplateAPI_listEmailTemplates**](EmailTemplateAPI.md#EmailTemplateAPI_listEmailTemplates) | **GET** /api/v1/email-templates/ | 
[**EmailTemplateAPI_renderEmailTemplate**](EmailTemplateAPI.md#EmailTemplateAPI_renderEmailTemplate) | **POST** /api/v1/email-templates/{email_template_id}/render | 
[**EmailTemplateAPI_updateEmailTemplate**](EmailTemplateAPI.md#EmailTemplateAPI_updateEmailTemplate) | **PUT** /api/v1/email-templates/{email_template_id} | 


# **EmailTemplateAPI_createEmailTemplate**
```c
email_template_t* EmailTemplateAPI_createEmailTemplate(apiClient_t *apiClient, email_template_create_t *email_template_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**email_template_create** | **[email_template_create_t](email_template_create.md) \*** |  | 

### Return type

[email_template_t](email_template.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmailTemplateAPI_deleteEmailTemplate**
```c
void EmailTemplateAPI_deleteEmailTemplate(apiClient_t *apiClient, char *email_template_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**email_template_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmailTemplateAPI_getEmailTemplate**
```c
email_template_t* EmailTemplateAPI_getEmailTemplate(apiClient_t *apiClient, char *email_template_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**email_template_id** | **char \*** |  | 

### Return type

[email_template_t](email_template.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmailTemplateAPI_listEmailTemplates**
```c
list_t* EmailTemplateAPI_listEmailTemplates(apiClient_t *apiClient, int *page, int *pageSize, char *status, char *search);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**pageSize** | **int \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**search** | **char \*** |  | [optional] 

### Return type

[list_t](email_template.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmailTemplateAPI_renderEmailTemplate**
```c
any_type_t* EmailTemplateAPI_renderEmailTemplate(apiClient_t *apiClient, char *email_template_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**email_template_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmailTemplateAPI_updateEmailTemplate**
```c
email_template_t* EmailTemplateAPI_updateEmailTemplate(apiClient_t *apiClient, char *email_template_id, email_template_update_t *email_template_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**email_template_id** | **char \*** |  | 
**email_template_update** | **[email_template_update_t](email_template_update.md) \*** |  | 

### Return type

[email_template_t](email_template.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

