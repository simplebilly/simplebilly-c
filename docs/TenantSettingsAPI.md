# TenantSettingsAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TenantSettingsAPI_getTenantSettings**](TenantSettingsAPI.md#TenantSettingsAPI_getTenantSettings) | **GET** /api/v1/settings/tenant | 
[**TenantSettingsAPI_updateTenantSettings**](TenantSettingsAPI.md#TenantSettingsAPI_updateTenantSettings) | **PUT** /api/v1/settings/tenant | 


# **TenantSettingsAPI_getTenantSettings**
```c
tenant_settings_t* TenantSettingsAPI_getTenantSettings(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[tenant_settings_t](tenant_settings.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TenantSettingsAPI_updateTenantSettings**
```c
tenant_settings_t* TenantSettingsAPI_updateTenantSettings(apiClient_t *apiClient, update_tenant_settings_t *update_tenant_settings);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**update_tenant_settings** | **[update_tenant_settings_t](update_tenant_settings.md) \*** |  | 

### Return type

[tenant_settings_t](tenant_settings.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

