# UserManagementAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**UserManagementAPI_getUser**](UserManagementAPI.md#UserManagementAPI_getUser) | **GET** /api/v1/users/{user_id} | 
[**UserManagementAPI_listUsers**](UserManagementAPI.md#UserManagementAPI_listUsers) | **GET** /api/v1/users | 
[**UserManagementAPI_removeUser**](UserManagementAPI.md#UserManagementAPI_removeUser) | **DELETE** /api/v1/users/{user_id} | 
[**UserManagementAPI_updateUserPermissions**](UserManagementAPI.md#UserManagementAPI_updateUserPermissions) | **PUT** /api/v1/users/{user_id}/permissions | 
[**UserManagementAPI_updateUserRole**](UserManagementAPI.md#UserManagementAPI_updateUserRole) | **PUT** /api/v1/users/{user_id}/role | 


# **UserManagementAPI_getUser**
```c
tenant_user_t* UserManagementAPI_getUser(apiClient_t *apiClient, char *user_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**user_id** | **char \*** |  | 

### Return type

[tenant_user_t](tenant_user.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UserManagementAPI_listUsers**
```c
list_t* UserManagementAPI_listUsers(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](tenant_user.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UserManagementAPI_removeUser**
```c
void UserManagementAPI_removeUser(apiClient_t *apiClient, char *user_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**user_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UserManagementAPI_updateUserPermissions**
```c
void UserManagementAPI_updateUserPermissions(apiClient_t *apiClient, char *user_id, update_permissions_payload_t *update_permissions_payload);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**user_id** | **char \*** |  | 
**update_permissions_payload** | **[update_permissions_payload_t](update_permissions_payload.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UserManagementAPI_updateUserRole**
```c
void UserManagementAPI_updateUserRole(apiClient_t *apiClient, char *user_id, update_role_payload_t *update_role_payload);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**user_id** | **char \*** |  | 
**update_role_payload** | **[update_role_payload_t](update_role_payload.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

