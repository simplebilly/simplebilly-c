# ServiceAssignmentAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ServiceAssignmentAPI_createServiceAssignment**](ServiceAssignmentAPI.md#ServiceAssignmentAPI_createServiceAssignment) | **POST** /api/v1/service-assignments | 
[**ServiceAssignmentAPI_deleteServiceAssignment**](ServiceAssignmentAPI.md#ServiceAssignmentAPI_deleteServiceAssignment) | **DELETE** /api/v1/service-assignments/{id} | 
[**ServiceAssignmentAPI_getServiceAssignment**](ServiceAssignmentAPI.md#ServiceAssignmentAPI_getServiceAssignment) | **GET** /api/v1/service-assignments/{id} | 
[**ServiceAssignmentAPI_getServiceAssignments**](ServiceAssignmentAPI.md#ServiceAssignmentAPI_getServiceAssignments) | **GET** /api/v1/service-assignments/ | 
[**ServiceAssignmentAPI_updateServiceAssignment**](ServiceAssignmentAPI.md#ServiceAssignmentAPI_updateServiceAssignment) | **PUT** /api/v1/service-assignments/{id} | 


# **ServiceAssignmentAPI_createServiceAssignment**
```c
service_assignment_t* ServiceAssignmentAPI_createServiceAssignment(apiClient_t *apiClient, service_assignment_create_t *service_assignment_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**service_assignment_create** | **[service_assignment_create_t](service_assignment_create.md) \*** |  | 

### Return type

[service_assignment_t](service_assignment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ServiceAssignmentAPI_deleteServiceAssignment**
```c
void ServiceAssignmentAPI_deleteServiceAssignment(apiClient_t *apiClient, char *id);
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

# **ServiceAssignmentAPI_getServiceAssignment**
```c
service_assignment_t* ServiceAssignmentAPI_getServiceAssignment(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[service_assignment_t](service_assignment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ServiceAssignmentAPI_getServiceAssignments**
```c
list_t* ServiceAssignmentAPI_getServiceAssignments(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](service_assignment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ServiceAssignmentAPI_updateServiceAssignment**
```c
service_assignment_t* ServiceAssignmentAPI_updateServiceAssignment(apiClient_t *apiClient, char *id, service_assignment_update_t *service_assignment_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**service_assignment_update** | **[service_assignment_update_t](service_assignment_update.md) \*** |  | 

### Return type

[service_assignment_t](service_assignment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

