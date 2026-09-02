# BomAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**BomAPI_createBom**](BomAPI.md#BomAPI_createBom) | **POST** /api/v1/boms | 
[**BomAPI_deleteBom**](BomAPI.md#BomAPI_deleteBom) | **DELETE** /api/v1/boms/{bom_id} | 
[**BomAPI_getBom**](BomAPI.md#BomAPI_getBom) | **GET** /api/v1/boms/{bom_id} | 
[**BomAPI_listBoms**](BomAPI.md#BomAPI_listBoms) | **GET** /api/v1/boms/ | 
[**BomAPI_updateBom**](BomAPI.md#BomAPI_updateBom) | **PUT** /api/v1/boms/{bom_id} | 


# **BomAPI_createBom**
```c
bom_t* BomAPI_createBom(apiClient_t *apiClient, bom_create_t *bom_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**bom_create** | **[bom_create_t](bom_create.md) \*** |  | 

### Return type

[bom_t](bom.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BomAPI_deleteBom**
```c
void BomAPI_deleteBom(apiClient_t *apiClient, char *bom_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**bom_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BomAPI_getBom**
```c
bom_t* BomAPI_getBom(apiClient_t *apiClient, char *bom_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**bom_id** | **char \*** |  | 

### Return type

[bom_t](bom.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BomAPI_listBoms**
```c
list_t* BomAPI_listBoms(apiClient_t *apiClient, int *page, int *pageSize, char *search, char *productId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**pageSize** | **int \*** |  | [optional] 
**search** | **char \*** |  | [optional] 
**productId** | **char \*** | Filter by finished product id. | [optional] 

### Return type

[list_t](bom.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BomAPI_updateBom**
```c
bom_t* BomAPI_updateBom(apiClient_t *apiClient, char *bom_id, bom_update_t *bom_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**bom_id** | **char \*** |  | 
**bom_update** | **[bom_update_t](bom_update.md) \*** |  | 

### Return type

[bom_t](bom.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

