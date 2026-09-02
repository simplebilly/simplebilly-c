# AutomationsAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AutomationsAPI_listAutomations**](AutomationsAPI.md#AutomationsAPI_listAutomations) | **GET** /api/v1/automations | 
[**AutomationsAPI_triggerAutomation**](AutomationsAPI.md#AutomationsAPI_triggerAutomation) | **POST** /api/v1/automations/{key}/trigger | 
[**AutomationsAPI_updateAutomation**](AutomationsAPI.md#AutomationsAPI_updateAutomation) | **PUT** /api/v1/automations/{key} | 


# **AutomationsAPI_listAutomations**
```c
list_t* AutomationsAPI_listAutomations(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](automation_dto.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AutomationsAPI_triggerAutomation**
```c
object_t* AutomationsAPI_triggerAutomation(apiClient_t *apiClient, char *key);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**key** | **char \*** |  | 

### Return type

[object_t](object.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AutomationsAPI_updateAutomation**
```c
automation_dto_t* AutomationsAPI_updateAutomation(apiClient_t *apiClient, char *key, update_automation_t *update_automation);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**key** | **char \*** |  | 
**update_automation** | **[update_automation_t](update_automation.md) \*** |  | 

### Return type

[automation_dto_t](automation_dto.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

