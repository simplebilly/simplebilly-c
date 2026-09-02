# ProductCategoryAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ProductCategoryAPI_createProductCategory**](ProductCategoryAPI.md#ProductCategoryAPI_createProductCategory) | **POST** /api/v1/product-categories | 
[**ProductCategoryAPI_deleteProductCategory**](ProductCategoryAPI.md#ProductCategoryAPI_deleteProductCategory) | **DELETE** /api/v1/product-categories/{category_id} | 
[**ProductCategoryAPI_getProductCategory**](ProductCategoryAPI.md#ProductCategoryAPI_getProductCategory) | **GET** /api/v1/product-categories/{category_id} | 
[**ProductCategoryAPI_listProductCategories**](ProductCategoryAPI.md#ProductCategoryAPI_listProductCategories) | **GET** /api/v1/product-categories | 
[**ProductCategoryAPI_updateProductCategory**](ProductCategoryAPI.md#ProductCategoryAPI_updateProductCategory) | **PUT** /api/v1/product-categories/{category_id} | 


# **ProductCategoryAPI_createProductCategory**
```c
product_category_t* ProductCategoryAPI_createProductCategory(apiClient_t *apiClient, product_category_t *product_category);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**product_category** | **[product_category_t](product_category.md) \*** |  | 

### Return type

[product_category_t](product_category.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductCategoryAPI_deleteProductCategory**
```c
void ProductCategoryAPI_deleteProductCategory(apiClient_t *apiClient, char *category_id);
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

# **ProductCategoryAPI_getProductCategory**
```c
product_category_t* ProductCategoryAPI_getProductCategory(apiClient_t *apiClient, char *category_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**category_id** | **char \*** |  | 

### Return type

[product_category_t](product_category.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductCategoryAPI_listProductCategories**
```c
list_t* ProductCategoryAPI_listProductCategories(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](product_category.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductCategoryAPI_updateProductCategory**
```c
product_category_t* ProductCategoryAPI_updateProductCategory(apiClient_t *apiClient, char *category_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**category_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[product_category_t](product_category.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

