# InventoryCountAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InventoryCountAPI_createInventoryCount**](InventoryCountAPI.md#InventoryCountAPI_createInventoryCount) | **POST** /api/v1/inventory-counts | 
[**InventoryCountAPI_deleteInventoryCount**](InventoryCountAPI.md#InventoryCountAPI_deleteInventoryCount) | **DELETE** /api/v1/inventory-counts/{inventory_count_id} | 
[**InventoryCountAPI_generateInventoryCount**](InventoryCountAPI.md#InventoryCountAPI_generateInventoryCount) | **POST** /api/v1/inventory-counts/generate | 
[**InventoryCountAPI_getInventoryCount**](InventoryCountAPI.md#InventoryCountAPI_getInventoryCount) | **GET** /api/v1/inventory-counts/{inventory_count_id} | 
[**InventoryCountAPI_listInventoryCounts**](InventoryCountAPI.md#InventoryCountAPI_listInventoryCounts) | **GET** /api/v1/inventory-counts/ | 
[**InventoryCountAPI_updateInventoryCount**](InventoryCountAPI.md#InventoryCountAPI_updateInventoryCount) | **PUT** /api/v1/inventory-counts/{inventory_count_id} | 
[**InventoryCountAPI_updateInventoryCountStatus**](InventoryCountAPI.md#InventoryCountAPI_updateInventoryCountStatus) | **PUT** /api/v1/inventory-counts/{inventory_count_id}/status | 


# **InventoryCountAPI_createInventoryCount**
```c
inventory_count_t* InventoryCountAPI_createInventoryCount(apiClient_t *apiClient, inventory_count_t *inventory_count);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**inventory_count** | **[inventory_count_t](inventory_count.md) \*** |  | 

### Return type

[inventory_count_t](inventory_count.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InventoryCountAPI_deleteInventoryCount**
```c
void InventoryCountAPI_deleteInventoryCount(apiClient_t *apiClient, char *inventory_count_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**inventory_count_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InventoryCountAPI_generateInventoryCount**
```c
inventory_count_t* InventoryCountAPI_generateInventoryCount(apiClient_t *apiClient, generate_count_request_t *generate_count_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**generate_count_request** | **[generate_count_request_t](generate_count_request.md) \*** |  | 

### Return type

[inventory_count_t](inventory_count.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InventoryCountAPI_getInventoryCount**
```c
inventory_count_t* InventoryCountAPI_getInventoryCount(apiClient_t *apiClient, char *inventory_count_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**inventory_count_id** | **char \*** |  | 

### Return type

[inventory_count_t](inventory_count.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InventoryCountAPI_listInventoryCounts**
```c
list_t* InventoryCountAPI_listInventoryCounts(apiClient_t *apiClient, int *page, int *page_size, char *status, char *warehouse_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**warehouse_id** | **char \*** |  | [optional] 

### Return type

[list_t](inventory_count.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InventoryCountAPI_updateInventoryCount**
```c
inventory_count_t* InventoryCountAPI_updateInventoryCount(apiClient_t *apiClient, char *inventory_count_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**inventory_count_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[inventory_count_t](inventory_count.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InventoryCountAPI_updateInventoryCountStatus**
```c
inventory_count_t* InventoryCountAPI_updateInventoryCountStatus(apiClient_t *apiClient, char *inventory_count_id, inventory_count_status_update_t *inventory_count_status_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**inventory_count_id** | **char \*** |  | 
**inventory_count_status_update** | **[inventory_count_status_update_t](inventory_count_status_update.md) \*** |  | 

### Return type

[inventory_count_t](inventory_count.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

