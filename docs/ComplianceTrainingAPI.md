# ComplianceTrainingAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ComplianceTrainingAPI_createComplianceTraining**](ComplianceTrainingAPI.md#ComplianceTrainingAPI_createComplianceTraining) | **POST** /api/v1/compliance-trainings | 
[**ComplianceTrainingAPI_deleteComplianceTraining**](ComplianceTrainingAPI.md#ComplianceTrainingAPI_deleteComplianceTraining) | **DELETE** /api/v1/compliance-trainings/{id} | 
[**ComplianceTrainingAPI_getComplianceTraining**](ComplianceTrainingAPI.md#ComplianceTrainingAPI_getComplianceTraining) | **GET** /api/v1/compliance-trainings/{id} | 
[**ComplianceTrainingAPI_getComplianceTrainings**](ComplianceTrainingAPI.md#ComplianceTrainingAPI_getComplianceTrainings) | **GET** /api/v1/compliance-trainings/ | 
[**ComplianceTrainingAPI_updateComplianceTraining**](ComplianceTrainingAPI.md#ComplianceTrainingAPI_updateComplianceTraining) | **PUT** /api/v1/compliance-trainings/{id} | 


# **ComplianceTrainingAPI_createComplianceTraining**
```c
compliance_training_t* ComplianceTrainingAPI_createComplianceTraining(apiClient_t *apiClient, compliance_training_create_t *compliance_training_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**compliance_training_create** | **[compliance_training_create_t](compliance_training_create.md) \*** |  | 

### Return type

[compliance_training_t](compliance_training.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ComplianceTrainingAPI_deleteComplianceTraining**
```c
void ComplianceTrainingAPI_deleteComplianceTraining(apiClient_t *apiClient, char *id);
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

# **ComplianceTrainingAPI_getComplianceTraining**
```c
compliance_training_t* ComplianceTrainingAPI_getComplianceTraining(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[compliance_training_t](compliance_training.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ComplianceTrainingAPI_getComplianceTrainings**
```c
list_t* ComplianceTrainingAPI_getComplianceTrainings(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](compliance_training.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ComplianceTrainingAPI_updateComplianceTraining**
```c
compliance_training_t* ComplianceTrainingAPI_updateComplianceTraining(apiClient_t *apiClient, char *id, compliance_training_update_t *compliance_training_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**compliance_training_update** | **[compliance_training_update_t](compliance_training_update.md) \*** |  | 

### Return type

[compliance_training_t](compliance_training.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

