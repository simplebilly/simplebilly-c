# SilentPartnerAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SilentPartnerAPI_createSilentPartner**](SilentPartnerAPI.md#SilentPartnerAPI_createSilentPartner) | **POST** /api/v1/silent-partners | 
[**SilentPartnerAPI_deleteSilentPartner**](SilentPartnerAPI.md#SilentPartnerAPI_deleteSilentPartner) | **DELETE** /api/v1/silent-partners/{id} | 
[**SilentPartnerAPI_getSilentPartner**](SilentPartnerAPI.md#SilentPartnerAPI_getSilentPartner) | **GET** /api/v1/silent-partners/{id} | 
[**SilentPartnerAPI_getSilentPartners**](SilentPartnerAPI.md#SilentPartnerAPI_getSilentPartners) | **GET** /api/v1/silent-partners/ | 
[**SilentPartnerAPI_updateSilentPartner**](SilentPartnerAPI.md#SilentPartnerAPI_updateSilentPartner) | **PUT** /api/v1/silent-partners/{id} | 


# **SilentPartnerAPI_createSilentPartner**
```c
silent_partner_t* SilentPartnerAPI_createSilentPartner(apiClient_t *apiClient, silent_partner_create_t *silent_partner_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**silent_partner_create** | **[silent_partner_create_t](silent_partner_create.md) \*** |  | 

### Return type

[silent_partner_t](silent_partner.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SilentPartnerAPI_deleteSilentPartner**
```c
void SilentPartnerAPI_deleteSilentPartner(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SilentPartnerAPI_getSilentPartner**
```c
silent_partner_t* SilentPartnerAPI_getSilentPartner(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[silent_partner_t](silent_partner.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SilentPartnerAPI_getSilentPartners**
```c
list_t* SilentPartnerAPI_getSilentPartners(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**search** | **char \*** |  | [optional] 
**include_deleted** | **int \*** | Soft-delete entities: set true to include rows with &#x60;deleted_at&#x60; set. | [optional] 

### Return type

[list_t](silent_partner.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SilentPartnerAPI_updateSilentPartner**
```c
silent_partner_t* SilentPartnerAPI_updateSilentPartner(apiClient_t *apiClient, char *id, silent_partner_update_t *silent_partner_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**silent_partner_update** | **[silent_partner_update_t](silent_partner_update.md) \*** |  | 

### Return type

[silent_partner_t](silent_partner.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

