# RecurringTemplateAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**RecurringTemplateAPI_createRecurringTemplate**](RecurringTemplateAPI.md#RecurringTemplateAPI_createRecurringTemplate) | **POST** /api/v1/recurring-templates | 
[**RecurringTemplateAPI_deleteRecurringTemplate**](RecurringTemplateAPI.md#RecurringTemplateAPI_deleteRecurringTemplate) | **DELETE** /api/v1/recurring-templates/{template_id} | 
[**RecurringTemplateAPI_getRecurringTemplate**](RecurringTemplateAPI.md#RecurringTemplateAPI_getRecurringTemplate) | **GET** /api/v1/recurring-templates/{template_id} | 
[**RecurringTemplateAPI_listRecurringTemplates**](RecurringTemplateAPI.md#RecurringTemplateAPI_listRecurringTemplates) | **GET** /api/v1/recurring-templates/ | 


# **RecurringTemplateAPI_createRecurringTemplate**
```c
recurring_template_t* RecurringTemplateAPI_createRecurringTemplate(apiClient_t *apiClient, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** |  |  | 

### Return type

[recurring_template_t](recurring_template.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RecurringTemplateAPI_deleteRecurringTemplate**
```c
void RecurringTemplateAPI_deleteRecurringTemplate(apiClient_t *apiClient, char *template_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**template_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RecurringTemplateAPI_getRecurringTemplate**
```c
recurring_template_t* RecurringTemplateAPI_getRecurringTemplate(apiClient_t *apiClient, char *template_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**template_id** | **char \*** |  | 

### Return type

[recurring_template_t](recurring_template.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RecurringTemplateAPI_listRecurringTemplates**
```c
list_t* RecurringTemplateAPI_listRecurringTemplates(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](recurring_template.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

