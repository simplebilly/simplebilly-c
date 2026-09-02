# ProductAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ProductAPI_createProductApi**](ProductAPI.md#ProductAPI_createProductApi) | **POST** /api/v1/products | 
[**ProductAPI_deleteProductApi**](ProductAPI.md#ProductAPI_deleteProductApi) | **DELETE** /api/v1/products/{product_id} | 
[**ProductAPI_getProductApi**](ProductAPI.md#ProductAPI_getProductApi) | **GET** /api/v1/products/{product_id} | 
[**ProductAPI_getProductStockApi**](ProductAPI.md#ProductAPI_getProductStockApi) | **GET** /api/v1/products/{product_id}/stock | 
[**ProductAPI_getProductsApi**](ProductAPI.md#ProductAPI_getProductsApi) | **GET** /api/v1/products/ | 
[**ProductAPI_listLowStockProductsApi**](ProductAPI.md#ProductAPI_listLowStockProductsApi) | **GET** /api/v1/products/low-stock | 
[**ProductAPI_productRestore**](ProductAPI.md#ProductAPI_productRestore) | **POST** /api/v1/products/{product_id}/restore | 
[**ProductAPI_updateProductApi**](ProductAPI.md#ProductAPI_updateProductApi) | **PUT** /api/v1/products/{product_id} | 
[**ProductAPI_updateProductStockApi**](ProductAPI.md#ProductAPI_updateProductStockApi) | **PUT** /api/v1/products/{product_id}/stock | 


# **ProductAPI_createProductApi**
```c
product_t* ProductAPI_createProductApi(apiClient_t *apiClient, product_create_t *product_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**product_create** | **[product_create_t](product_create.md) \*** |  | 

### Return type

[product_t](product.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductAPI_deleteProductApi**
```c
void ProductAPI_deleteProductApi(apiClient_t *apiClient, char *product_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**product_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductAPI_getProductApi**
```c
product_t* ProductAPI_getProductApi(apiClient_t *apiClient, char *product_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**product_id** | **char \*** |  | 

### Return type

[product_t](product.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductAPI_getProductStockApi**
```c
product_stock_t* ProductAPI_getProductStockApi(apiClient_t *apiClient, char *product_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**product_id** | **char \*** |  | 

### Return type

[product_stock_t](product_stock.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductAPI_getProductsApi**
```c
list_t* ProductAPI_getProductsApi(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](product.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductAPI_listLowStockProductsApi**
```c
list_t* ProductAPI_listLowStockProductsApi(apiClient_t *apiClient, long threshold);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**threshold** | **long** |  | [optional] 

### Return type

[list_t](product_stock.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductAPI_productRestore**
```c
product_t* ProductAPI_productRestore(apiClient_t *apiClient, char *product_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**product_id** | **char \*** |  | 

### Return type

[product_t](product.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductAPI_updateProductApi**
```c
product_t* ProductAPI_updateProductApi(apiClient_t *apiClient, char *product_id, product_update_t *product_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**product_id** | **char \*** |  | 
**product_update** | **[product_update_t](product_update.md) \*** |  | 

### Return type

[product_t](product.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProductAPI_updateProductStockApi**
```c
product_stock_t* ProductAPI_updateProductStockApi(apiClient_t *apiClient, char *product_id, stock_update_request_t *stock_update_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**product_id** | **char \*** |  | 
**stock_update_request** | **[stock_update_request_t](stock_update_request.md) \*** |  | 

### Return type

[product_stock_t](product_stock.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

