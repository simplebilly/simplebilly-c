# ProductAttributeAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ProductAttributeAPI_createProductAttribute**](ProductAttributeAPI.md#ProductAttributeAPI_createProductAttribute) | **POST** /api/v1/product-attributes | 
[**ProductAttributeAPI_deleteProductAttribute**](ProductAttributeAPI.md#ProductAttributeAPI_deleteProductAttribute) | **DELETE** /api/v1/product-attributes/{attribute_id} | 
[**ProductAttributeAPI_getProductAttribute**](ProductAttributeAPI.md#ProductAttributeAPI_getProductAttribute) | **GET** /api/v1/product-attributes/{attribute_id} | 
[**ProductAttributeAPI_listProductAttributes**](ProductAttributeAPI.md#ProductAttributeAPI_listProductAttributes) | **GET** /api/v1/product-attributes/ | 
[**ProductAttributeAPI_updateProductAttribute**](ProductAttributeAPI.md#ProductAttributeAPI_updateProductAttribute) | **PUT** /api/v1/product-attributes/{attribute_id} | 


# **ProductAttributeAPI_createProductAttribute**
```c
product_attribute_t* ProductAttributeAPI_createProductAttribute(apiClient_t *apiClient, product_attribute_create_t *product_attribute_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**product_attribute_create** | **[product_attribute_create_t](product_attribute_create.md) \*** |  | 

### Return type

[product_attribute_t](product_attribute.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductAttributeAPI_deleteProductAttribute**
```c
void ProductAttributeAPI_deleteProductAttribute(apiClient_t *apiClient, char *attribute_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**attribute_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductAttributeAPI_getProductAttribute**
```c
product_attribute_t* ProductAttributeAPI_getProductAttribute(apiClient_t *apiClient, char *attribute_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**attribute_id** | **char \*** |  | 

### Return type

[product_attribute_t](product_attribute.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductAttributeAPI_listProductAttributes**
```c
list_t* ProductAttributeAPI_listProductAttributes(apiClient_t *apiClient, int *page, int *page_size, char *product_id, int *is_filterable, char *search);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**product_id** | **char \*** |  | [optional] 
**is_filterable** | **int \*** |  | [optional] 
**search** | **char \*** |  | [optional] 

### Return type

[list_t](product_attribute.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductAttributeAPI_updateProductAttribute**
```c
product_attribute_t* ProductAttributeAPI_updateProductAttribute(apiClient_t *apiClient, char *attribute_id, product_attribute_update_t *product_attribute_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**attribute_id** | **char \*** |  | 
**product_attribute_update** | **[product_attribute_update_t](product_attribute_update.md) \*** |  | 

### Return type

[product_attribute_t](product_attribute.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

