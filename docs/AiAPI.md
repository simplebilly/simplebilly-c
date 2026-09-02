# AiAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AiAPI_aiSuggestApi**](AiAPI.md#AiAPI_aiSuggestApi) | **POST** /api/v1/support/ai/suggest | 
[**AiAPI_createWorkerApi**](AiAPI.md#AiAPI_createWorkerApi) | **POST** /api/v1/support/ai/workers | 
[**AiAPI_listWorkersApi**](AiAPI.md#AiAPI_listWorkersApi) | **GET** /api/v1/support/ai/workers | 
[**AiAPI_runWorkerApi**](AiAPI.md#AiAPI_runWorkerApi) | **POST** /api/v1/support/ai/workers/{worker_id}/run | 


# **AiAPI_aiSuggestApi**
```c
ai_suggestion_t* AiAPI_aiSuggestApi(apiClient_t *apiClient, ai_suggestion_request_t *ai_suggestion_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ai_suggestion_request** | **[ai_suggestion_request_t](ai_suggestion_request.md) \*** |  | 

### Return type

[ai_suggestion_t](ai_suggestion.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AiAPI_createWorkerApi**
```c
ai_worker_config_t* AiAPI_createWorkerApi(apiClient_t *apiClient, ai_config_dto_t *ai_config_dto);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ai_config_dto** | **[ai_config_dto_t](ai_config_dto.md) \*** |  | 

### Return type

[ai_worker_config_t](ai_worker_config.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AiAPI_listWorkersApi**
```c
list_t* AiAPI_listWorkersApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](ai_worker_config.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AiAPI_runWorkerApi**
```c
ai_suggestion_t* AiAPI_runWorkerApi(apiClient_t *apiClient, char *worker_id, ai_suggestion_request_t *ai_suggestion_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**worker_id** | **char \*** |  | 
**ai_suggestion_request** | **[ai_suggestion_request_t](ai_suggestion_request.md) \*** |  | 

### Return type

[ai_suggestion_t](ai_suggestion.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

