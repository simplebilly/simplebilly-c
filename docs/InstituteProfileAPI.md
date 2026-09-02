# InstituteProfileAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InstituteProfileAPI_getInstituteProfile**](InstituteProfileAPI.md#InstituteProfileAPI_getInstituteProfile) | **GET** /api/v1/institute-profile | Current institute profile (created with defaults when missing).
[**InstituteProfileAPI_updateInstituteProfile**](InstituteProfileAPI.md#InstituteProfileAPI_updateInstituteProfile) | **PUT** /api/v1/institute-profile | Update the institute profile (institute_type and/or kapitalmarktorientiert).


# **InstituteProfileAPI_getInstituteProfile**
```c
// Current institute profile (created with defaults when missing).
//
institute_profile_t* InstituteProfileAPI_getInstituteProfile(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[institute_profile_t](institute_profile.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstituteProfileAPI_updateInstituteProfile**
```c
// Update the institute profile (institute_type and/or kapitalmarktorientiert).
//
institute_profile_t* InstituteProfileAPI_updateInstituteProfile(apiClient_t *apiClient, institute_profile_update_t *institute_profile_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**institute_profile_update** | **[institute_profile_update_t](institute_profile_update.md) \*** |  | 

### Return type

[institute_profile_t](institute_profile.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

