# ShareholderAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ShareholderAPI_createShareholder**](ShareholderAPI.md#ShareholderAPI_createShareholder) | **POST** /api/v1/shareholders | 
[**ShareholderAPI_deleteShareholder**](ShareholderAPI.md#ShareholderAPI_deleteShareholder) | **DELETE** /api/v1/shareholders/{id} | 
[**ShareholderAPI_getShareholder**](ShareholderAPI.md#ShareholderAPI_getShareholder) | **GET** /api/v1/shareholders/{id} | 
[**ShareholderAPI_getShareholders**](ShareholderAPI.md#ShareholderAPI_getShareholders) | **GET** /api/v1/shareholders/ | 
[**ShareholderAPI_updateShareholder**](ShareholderAPI.md#ShareholderAPI_updateShareholder) | **PUT** /api/v1/shareholders/{id} | 


# **ShareholderAPI_createShareholder**
```c
shareholder_t* ShareholderAPI_createShareholder(apiClient_t *apiClient, shareholder_create_t *shareholder_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**shareholder_create** | **[shareholder_create_t](shareholder_create.md) \*** |  | 

### Return type

[shareholder_t](shareholder.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShareholderAPI_deleteShareholder**
```c
void ShareholderAPI_deleteShareholder(apiClient_t *apiClient, char *id);
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

# **ShareholderAPI_getShareholder**
```c
shareholder_t* ShareholderAPI_getShareholder(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[shareholder_t](shareholder.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShareholderAPI_getShareholders**
```c
list_t* ShareholderAPI_getShareholders(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](shareholder.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShareholderAPI_updateShareholder**
```c
shareholder_t* ShareholderAPI_updateShareholder(apiClient_t *apiClient, char *id, shareholder_update_t *shareholder_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**shareholder_update** | **[shareholder_update_t](shareholder_update.md) \*** |  | 

### Return type

[shareholder_t](shareholder.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

