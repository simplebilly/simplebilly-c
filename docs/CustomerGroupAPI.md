# CustomerGroupAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CustomerGroupAPI_addGroupMembers**](CustomerGroupAPI.md#CustomerGroupAPI_addGroupMembers) | **POST** /api/v1/customer-groups/{customer_group_id}/members | 
[**CustomerGroupAPI_createCustomerGroup**](CustomerGroupAPI.md#CustomerGroupAPI_createCustomerGroup) | **POST** /api/v1/customer-groups | 
[**CustomerGroupAPI_deleteCustomerGroup**](CustomerGroupAPI.md#CustomerGroupAPI_deleteCustomerGroup) | **DELETE** /api/v1/customer-groups/{customer_group_id} | 
[**CustomerGroupAPI_getCustomerGroup**](CustomerGroupAPI.md#CustomerGroupAPI_getCustomerGroup) | **GET** /api/v1/customer-groups/{customer_group_id} | 
[**CustomerGroupAPI_listCustomerGroups**](CustomerGroupAPI.md#CustomerGroupAPI_listCustomerGroups) | **GET** /api/v1/customer-groups/ | 
[**CustomerGroupAPI_updateCustomerGroup**](CustomerGroupAPI.md#CustomerGroupAPI_updateCustomerGroup) | **PUT** /api/v1/customer-groups/{customer_group_id} | 


# **CustomerGroupAPI_addGroupMembers**
```c
customer_group_t* CustomerGroupAPI_addGroupMembers(apiClient_t *apiClient, char *customer_group_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**customer_group_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[customer_group_t](customer_group.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerGroupAPI_createCustomerGroup**
```c
customer_group_t* CustomerGroupAPI_createCustomerGroup(apiClient_t *apiClient, customer_group_create_t *customer_group_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**customer_group_create** | **[customer_group_create_t](customer_group_create.md) \*** |  | 

### Return type

[customer_group_t](customer_group.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerGroupAPI_deleteCustomerGroup**
```c
void CustomerGroupAPI_deleteCustomerGroup(apiClient_t *apiClient, char *customer_group_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**customer_group_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerGroupAPI_getCustomerGroup**
```c
customer_group_t* CustomerGroupAPI_getCustomerGroup(apiClient_t *apiClient, char *customer_group_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**customer_group_id** | **char \*** |  | 

### Return type

[customer_group_t](customer_group.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerGroupAPI_listCustomerGroups**
```c
list_t* CustomerGroupAPI_listCustomerGroups(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](customer_group.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerGroupAPI_updateCustomerGroup**
```c
customer_group_t* CustomerGroupAPI_updateCustomerGroup(apiClient_t *apiClient, char *customer_group_id, customer_group_update_t *customer_group_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**customer_group_id** | **char \*** |  | 
**customer_group_update** | **[customer_group_update_t](customer_group_update.md) \*** |  | 

### Return type

[customer_group_t](customer_group.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

