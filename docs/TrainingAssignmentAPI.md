# TrainingAssignmentAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TrainingAssignmentAPI_createTrainingAssignment**](TrainingAssignmentAPI.md#TrainingAssignmentAPI_createTrainingAssignment) | **POST** /api/v1/training-assignments | 
[**TrainingAssignmentAPI_deleteTrainingAssignment**](TrainingAssignmentAPI.md#TrainingAssignmentAPI_deleteTrainingAssignment) | **DELETE** /api/v1/training-assignments/{id} | 
[**TrainingAssignmentAPI_getTrainingAssignment**](TrainingAssignmentAPI.md#TrainingAssignmentAPI_getTrainingAssignment) | **GET** /api/v1/training-assignments/{id} | 
[**TrainingAssignmentAPI_getTrainingAssignments**](TrainingAssignmentAPI.md#TrainingAssignmentAPI_getTrainingAssignments) | **GET** /api/v1/training-assignments/ | 
[**TrainingAssignmentAPI_updateTrainingAssignment**](TrainingAssignmentAPI.md#TrainingAssignmentAPI_updateTrainingAssignment) | **PUT** /api/v1/training-assignments/{id} | 


# **TrainingAssignmentAPI_createTrainingAssignment**
```c
training_assignment_t* TrainingAssignmentAPI_createTrainingAssignment(apiClient_t *apiClient, training_assignment_create_t *training_assignment_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**training_assignment_create** | **[training_assignment_create_t](training_assignment_create.md) \*** |  | 

### Return type

[training_assignment_t](training_assignment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TrainingAssignmentAPI_deleteTrainingAssignment**
```c
void TrainingAssignmentAPI_deleteTrainingAssignment(apiClient_t *apiClient, char *id);
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

# **TrainingAssignmentAPI_getTrainingAssignment**
```c
training_assignment_t* TrainingAssignmentAPI_getTrainingAssignment(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[training_assignment_t](training_assignment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TrainingAssignmentAPI_getTrainingAssignments**
```c
list_t* TrainingAssignmentAPI_getTrainingAssignments(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](training_assignment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TrainingAssignmentAPI_updateTrainingAssignment**
```c
training_assignment_t* TrainingAssignmentAPI_updateTrainingAssignment(apiClient_t *apiClient, char *id, training_assignment_update_t *training_assignment_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**training_assignment_update** | **[training_assignment_update_t](training_assignment_update.md) \*** |  | 

### Return type

[training_assignment_t](training_assignment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

