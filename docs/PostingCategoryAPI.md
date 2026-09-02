# PostingCategoryAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PostingCategoryAPI_createPostingCategory**](PostingCategoryAPI.md#PostingCategoryAPI_createPostingCategory) | **POST** /api/v1/posting-categories | 
[**PostingCategoryAPI_deletePostingCategory**](PostingCategoryAPI.md#PostingCategoryAPI_deletePostingCategory) | **DELETE** /api/v1/posting-categories/{category_id} | 
[**PostingCategoryAPI_listPostingCategories**](PostingCategoryAPI.md#PostingCategoryAPI_listPostingCategories) | **GET** /api/v1/posting-categories | 
[**PostingCategoryAPI_seedPostingCategories**](PostingCategoryAPI.md#PostingCategoryAPI_seedPostingCategories) | **POST** /api/v1/posting-categories/seed/{skr_version} | 
[**PostingCategoryAPI_updatePostingCategory**](PostingCategoryAPI.md#PostingCategoryAPI_updatePostingCategory) | **PUT** /api/v1/posting-categories/{category_id} | 


# **PostingCategoryAPI_createPostingCategory**
```c
posting_category_t* PostingCategoryAPI_createPostingCategory(apiClient_t *apiClient, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** |  |  | 

### Return type

[posting_category_t](posting_category.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PostingCategoryAPI_deletePostingCategory**
```c
void PostingCategoryAPI_deletePostingCategory(apiClient_t *apiClient, char *category_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**category_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PostingCategoryAPI_listPostingCategories**
```c
list_t* PostingCategoryAPI_listPostingCategories(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](posting_category.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PostingCategoryAPI_seedPostingCategories**
```c
void PostingCategoryAPI_seedPostingCategories(apiClient_t *apiClient, char *skr_version);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**skr_version** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PostingCategoryAPI_updatePostingCategory**
```c
posting_category_t* PostingCategoryAPI_updatePostingCategory(apiClient_t *apiClient, char *category_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**category_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[posting_category_t](posting_category.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

