# WorkflowsAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**WorkflowsAPI_listWorkflowsApi**](WorkflowsAPI.md#WorkflowsAPI_listWorkflowsApi) | **GET** /api/v1/workflows | 
[**WorkflowsAPI_setWorkflowEnabledApi**](WorkflowsAPI.md#WorkflowsAPI_setWorkflowEnabledApi) | **PUT** /api/v1/workflows/{workflow_id}/enabled | 


# **WorkflowsAPI_listWorkflowsApi**
```c
list_t* WorkflowsAPI_listWorkflowsApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](workflow.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WorkflowsAPI_setWorkflowEnabledApi**
```c
workflow_t* WorkflowsAPI_setWorkflowEnabledApi(apiClient_t *apiClient, char *workflow_id, workflow_enabled_update_t *workflow_enabled_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**workflow_id** | **char \*** |  | 
**workflow_enabled_update** | **[workflow_enabled_update_t](workflow_enabled_update.md) \*** |  | 

### Return type

[workflow_t](workflow.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

