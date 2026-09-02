# TrainingsAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TrainingsAPI_getMyTrainings**](TrainingsAPI.md#TrainingsAPI_getMyTrainings) | **GET** /api/v1/trainings/me | 
[**TrainingsAPI_getTrainingContent**](TrainingsAPI.md#TrainingsAPI_getTrainingContent) | **GET** /api/v1/trainings/content/{code} | 
[**TrainingsAPI_getTrainingOverview**](TrainingsAPI.md#TrainingsAPI_getTrainingOverview) | **GET** /api/v1/trainings/overview | 
[**TrainingsAPI_submitTrainingResult**](TrainingsAPI.md#TrainingsAPI_submitTrainingResult) | **POST** /api/v1/trainings/submit-result | 


# **TrainingsAPI_getMyTrainings**
```c
list_t* TrainingsAPI_getMyTrainings(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](my_training_item.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TrainingsAPI_getTrainingContent**
```c
training_content_t* TrainingsAPI_getTrainingContent(apiClient_t *apiClient, char *code);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**code** | **char \*** | Training code, e.g. data_privacy | 

### Return type

[training_content_t](training_content.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TrainingsAPI_getTrainingOverview**
```c
list_t* TrainingsAPI_getTrainingOverview(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](hr_training_overview.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TrainingsAPI_submitTrainingResult**
```c
submit_result_response_t* TrainingsAPI_submitTrainingResult(apiClient_t *apiClient, submit_result_dto_t *submit_result_dto);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**submit_result_dto** | **[submit_result_dto_t](submit_result_dto.md) \*** |  | 

### Return type

[submit_result_response_t](submit_result_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

