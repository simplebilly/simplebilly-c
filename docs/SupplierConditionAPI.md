# SupplierConditionAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SupplierConditionAPI_createSupplierCondition**](SupplierConditionAPI.md#SupplierConditionAPI_createSupplierCondition) | **POST** /api/v1/supplier-conditions | 
[**SupplierConditionAPI_deleteSupplierCondition**](SupplierConditionAPI.md#SupplierConditionAPI_deleteSupplierCondition) | **DELETE** /api/v1/supplier-conditions/{supplier_condition_id} | 
[**SupplierConditionAPI_getSupplierCondition**](SupplierConditionAPI.md#SupplierConditionAPI_getSupplierCondition) | **GET** /api/v1/supplier-conditions/{supplier_condition_id} | 
[**SupplierConditionAPI_listSupplierConditions**](SupplierConditionAPI.md#SupplierConditionAPI_listSupplierConditions) | **GET** /api/v1/supplier-conditions/ | 
[**SupplierConditionAPI_updateSupplierCondition**](SupplierConditionAPI.md#SupplierConditionAPI_updateSupplierCondition) | **PUT** /api/v1/supplier-conditions/{supplier_condition_id} | 


# **SupplierConditionAPI_createSupplierCondition**
```c
supplier_condition_t* SupplierConditionAPI_createSupplierCondition(apiClient_t *apiClient, supplier_condition_create_t *supplier_condition_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**supplier_condition_create** | **[supplier_condition_create_t](supplier_condition_create.md) \*** |  | 

### Return type

[supplier_condition_t](supplier_condition.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupplierConditionAPI_deleteSupplierCondition**
```c
void SupplierConditionAPI_deleteSupplierCondition(apiClient_t *apiClient, char *supplier_condition_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**supplier_condition_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupplierConditionAPI_getSupplierCondition**
```c
supplier_condition_t* SupplierConditionAPI_getSupplierCondition(apiClient_t *apiClient, char *supplier_condition_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**supplier_condition_id** | **char \*** |  | 

### Return type

[supplier_condition_t](supplier_condition.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupplierConditionAPI_listSupplierConditions**
```c
list_t* SupplierConditionAPI_listSupplierConditions(apiClient_t *apiClient, int *page, int *page_size, char *supplier_contact_id, char *search);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**supplier_contact_id** | **char \*** |  | [optional] 
**search** | **char \*** |  | [optional] 

### Return type

[list_t](supplier_condition.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupplierConditionAPI_updateSupplierCondition**
```c
supplier_condition_t* SupplierConditionAPI_updateSupplierCondition(apiClient_t *apiClient, char *supplier_condition_id, supplier_condition_update_t *supplier_condition_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**supplier_condition_id** | **char \*** |  | 
**supplier_condition_update** | **[supplier_condition_update_t](supplier_condition_update.md) \*** |  | 

### Return type

[supplier_condition_t](supplier_condition.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

