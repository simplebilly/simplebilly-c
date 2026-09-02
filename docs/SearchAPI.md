# SearchAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SearchAPI_globalSearch**](SearchAPI.md#SearchAPI_globalSearch) | **GET** /api/v1/search | GET /api/v1/search?q&#x3D;...
[**SearchAPI_myPermissions**](SearchAPI.md#SearchAPI_myPermissions) | **GET** /api/v1/me/permissions | GET /api/v1/me/permissions — resolved permissions from the auth token, used by the frontend to show/hide admin navigation.


# **SearchAPI_globalSearch**
```c
// GET /api/v1/search?q=...
//
any_type_t* SearchAPI_globalSearch(apiClient_t *apiClient, char *q);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**q** | **char \*** | Search text (min 2 chars) | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SearchAPI_myPermissions**
```c
// GET /api/v1/me/permissions — resolved permissions from the auth token, used by the frontend to show/hide admin navigation.
//
any_type_t* SearchAPI_myPermissions(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

