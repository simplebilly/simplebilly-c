# ProductVariantAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ProductVariantAPI_createProductVariant**](ProductVariantAPI.md#ProductVariantAPI_createProductVariant) | **POST** /api/v1/product-variants | 
[**ProductVariantAPI_deleteProductVariant**](ProductVariantAPI.md#ProductVariantAPI_deleteProductVariant) | **DELETE** /api/v1/product-variants/{variant_id} | 
[**ProductVariantAPI_generateProductVariants**](ProductVariantAPI.md#ProductVariantAPI_generateProductVariants) | **POST** /api/v1/product-variants/generate | 
[**ProductVariantAPI_getProductVariant**](ProductVariantAPI.md#ProductVariantAPI_getProductVariant) | **GET** /api/v1/product-variants/{variant_id} | 
[**ProductVariantAPI_listProductVariants**](ProductVariantAPI.md#ProductVariantAPI_listProductVariants) | **GET** /api/v1/product-variants/ | 
[**ProductVariantAPI_updateProductVariant**](ProductVariantAPI.md#ProductVariantAPI_updateProductVariant) | **PUT** /api/v1/product-variants/{variant_id} | 


# **ProductVariantAPI_createProductVariant**
```c
product_variant_t* ProductVariantAPI_createProductVariant(apiClient_t *apiClient, product_variant_t *product_variant);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**product_variant** | **[product_variant_t](product_variant.md) \*** |  | 

### Return type

[product_variant_t](product_variant.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductVariantAPI_deleteProductVariant**
```c
void ProductVariantAPI_deleteProductVariant(apiClient_t *apiClient, char *variant_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**variant_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductVariantAPI_generateProductVariants**
```c
list_t* ProductVariantAPI_generateProductVariants(apiClient_t *apiClient, generate_variants_request_t *generate_variants_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**generate_variants_request** | **[generate_variants_request_t](generate_variants_request.md) \*** |  | 

### Return type

[list_t](product_variant.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductVariantAPI_getProductVariant**
```c
product_variant_t* ProductVariantAPI_getProductVariant(apiClient_t *apiClient, char *variant_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**variant_id** | **char \*** |  | 

### Return type

[product_variant_t](product_variant.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductVariantAPI_listProductVariants**
```c
list_t* ProductVariantAPI_listProductVariants(apiClient_t *apiClient, int *page, int *page_size, char *product_id, int *is_active);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**product_id** | **char \*** |  | [optional] 
**is_active** | **int \*** |  | [optional] 

### Return type

[list_t](product_variant.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductVariantAPI_updateProductVariant**
```c
product_variant_t* ProductVariantAPI_updateProductVariant(apiClient_t *apiClient, char *variant_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**variant_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[product_variant_t](product_variant.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

