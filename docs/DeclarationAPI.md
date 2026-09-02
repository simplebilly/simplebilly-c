# DeclarationAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DeclarationAPI_createDeclaration**](DeclarationAPI.md#DeclarationAPI_createDeclaration) | **POST** /api/v1/declarations | 
[**DeclarationAPI_declarationRestore**](DeclarationAPI.md#DeclarationAPI_declarationRestore) | **POST** /api/v1/declarations/{id}/restore | 
[**DeclarationAPI_deleteDeclaration**](DeclarationAPI.md#DeclarationAPI_deleteDeclaration) | **DELETE** /api/v1/declarations/{id} | 
[**DeclarationAPI_getDeclaration**](DeclarationAPI.md#DeclarationAPI_getDeclaration) | **GET** /api/v1/declarations/{id} | 
[**DeclarationAPI_getDeclarations**](DeclarationAPI.md#DeclarationAPI_getDeclarations) | **GET** /api/v1/declarations/ | 
[**DeclarationAPI_updateDeclaration**](DeclarationAPI.md#DeclarationAPI_updateDeclaration) | **PUT** /api/v1/declarations/{id} | 


# **DeclarationAPI_createDeclaration**
```c
declaration_t* DeclarationAPI_createDeclaration(apiClient_t *apiClient, declaration_create_t *declaration_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**declaration_create** | **[declaration_create_t](declaration_create.md) \*** |  | 

### Return type

[declaration_t](declaration.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeclarationAPI_declarationRestore**
```c
declaration_t* DeclarationAPI_declarationRestore(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[declaration_t](declaration.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeclarationAPI_deleteDeclaration**
```c
void DeclarationAPI_deleteDeclaration(apiClient_t *apiClient, char *id);
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

# **DeclarationAPI_getDeclaration**
```c
declaration_t* DeclarationAPI_getDeclaration(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[declaration_t](declaration.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeclarationAPI_getDeclarations**
```c
list_t* DeclarationAPI_getDeclarations(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](declaration.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeclarationAPI_updateDeclaration**
```c
declaration_t* DeclarationAPI_updateDeclaration(apiClient_t *apiClient, char *id, declaration_update_t *declaration_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**declaration_update** | **[declaration_update_t](declaration_update.md) \*** |  | 

### Return type

[declaration_t](declaration.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

