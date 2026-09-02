# AdminAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AdminAPI_triggerMirror**](AdminAPI.md#AdminAPI_triggerMirror) | **POST** /api/v1/admin/storage/mirror | 


# **AdminAPI_triggerMirror**
```c
mirror_trigger_response_t* AdminAPI_triggerMirror(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[mirror_trigger_response_t](mirror_trigger_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

