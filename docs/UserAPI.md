# UserAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**UserAPI_changePassword**](UserAPI.md#UserAPI_changePassword) | **POST** /user/change-password | Change the current user&#39;s password (requires the current password).
[**UserAPI_createTeam**](UserAPI.md#UserAPI_createTeam) | **POST** /user/teams | Create a new team within the current tenant
[**UserAPI_generateApiKey**](UserAPI.md#UserAPI_generateApiKey) | **POST** /user/api-key | Generate a new API key for the current user
[**UserAPI_inviteUser**](UserAPI.md#UserAPI_inviteUser) | **POST** /user/invite | Invite a user to the current tenant/organization
[**UserAPI_listTeams**](UserAPI.md#UserAPI_listTeams) | **GET** /user/teams | List all teams in the current tenant
[**UserAPI_removeUserFromOrg**](UserAPI.md#UserAPI_removeUserFromOrg) | **DELETE** /user/remove | Remove a user from the current organization
[**UserAPI_updateProfile**](UserAPI.md#UserAPI_updateProfile) | **PUT** /user/profile | Update the current user&#39;s profile
[**UserAPI_userProfile**](UserAPI.md#UserAPI_userProfile) | **GET** /user/profile | Get the current user&#39;s profile
[**UserAPI_userTenants**](UserAPI.md#UserAPI_userTenants) | **GET** /user/tenants | List all tenants (organizations) the current user belongs to


# **UserAPI_changePassword**
```c
// Change the current user's password (requires the current password).
//
void UserAPI_changePassword(apiClient_t *apiClient, change_password_request_t *change_password_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**change_password_request** | **[change_password_request_t](change_password_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UserAPI_createTeam**
```c
// Create a new team within the current tenant
//
api_response_team_t* UserAPI_createTeam(apiClient_t *apiClient, team_create_t *team_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**team_create** | **[team_create_t](team_create.md) \*** |  | 

### Return type

[api_response_team_t](api_response_team.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UserAPI_generateApiKey**
```c
// Generate a new API key for the current user
//
api_response_string_t* UserAPI_generateApiKey(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[api_response_string_t](api_response_string.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UserAPI_inviteUser**
```c
// Invite a user to the current tenant/organization
//
void UserAPI_inviteUser(apiClient_t *apiClient, invite_request_t *invite_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**invite_request** | **[invite_request_t](invite_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UserAPI_listTeams**
```c
// List all teams in the current tenant
//
api_response_vec_team_t* UserAPI_listTeams(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[api_response_vec_team_t](api_response_vec_team.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UserAPI_removeUserFromOrg**
```c
// Remove a user from the current organization
//
void UserAPI_removeUserFromOrg(apiClient_t *apiClient, remove_user_request_t *remove_user_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**remove_user_request** | **[remove_user_request_t](remove_user_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UserAPI_updateProfile**
```c
// Update the current user's profile
//
void UserAPI_updateProfile(apiClient_t *apiClient, update_profile_request_t *update_profile_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**update_profile_request** | **[update_profile_request_t](update_profile_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UserAPI_userProfile**
```c
// Get the current user's profile
//
api_response_user_profile_t* UserAPI_userProfile(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[api_response_user_profile_t](api_response_user_profile.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UserAPI_userTenants**
```c
// List all tenants (organizations) the current user belongs to
//
api_response_vec_user_tenant_info_t* UserAPI_userTenants(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[api_response_vec_user_tenant_info_t](api_response_vec_user_tenant_info.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

