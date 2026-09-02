# CustomerAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CustomerAPI_createCustomer**](CustomerAPI.md#CustomerAPI_createCustomer) | **POST** /api/v1/customers | 
[**CustomerAPI_customerRestore**](CustomerAPI.md#CustomerAPI_customerRestore) | **POST** /api/v1/customers/{customer_id}/restore | 
[**CustomerAPI_deleteCustomer**](CustomerAPI.md#CustomerAPI_deleteCustomer) | **DELETE** /api/v1/customers/{customer_id} | 
[**CustomerAPI_getCustomer**](CustomerAPI.md#CustomerAPI_getCustomer) | **GET** /api/v1/customers/{customer_id} | 
[**CustomerAPI_getCustomers**](CustomerAPI.md#CustomerAPI_getCustomers) | **GET** /api/v1/customers/ | 
[**CustomerAPI_updateCustomer**](CustomerAPI.md#CustomerAPI_updateCustomer) | **PUT** /api/v1/customers/{customer_id} | 


# **CustomerAPI_createCustomer**
```c
customer_t* CustomerAPI_createCustomer(apiClient_t *apiClient, customer_create_t *customer_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**customer_create** | **[customer_create_t](customer_create.md) \*** |  | 

### Return type

[customer_t](customer.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerAPI_customerRestore**
```c
customer_t* CustomerAPI_customerRestore(apiClient_t *apiClient, char *customer_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**customer_id** | **char \*** |  | 

### Return type

[customer_t](customer.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerAPI_deleteCustomer**
```c
void CustomerAPI_deleteCustomer(apiClient_t *apiClient, char *customer_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**customer_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerAPI_getCustomer**
```c
customer_t* CustomerAPI_getCustomer(apiClient_t *apiClient, char *customer_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**customer_id** | **char \*** |  | 

### Return type

[customer_t](customer.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerAPI_getCustomers**
```c
list_t* CustomerAPI_getCustomers(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](customer.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerAPI_updateCustomer**
```c
customer_t* CustomerAPI_updateCustomer(apiClient_t *apiClient, char *customer_id, customer_update_t *customer_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**customer_id** | **char \*** |  | 
**customer_update** | **[customer_update_t](customer_update.md) \*** |  | 

### Return type

[customer_t](customer.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

