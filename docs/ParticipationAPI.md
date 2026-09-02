# ParticipationAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ParticipationAPI_createParticipation**](ParticipationAPI.md#ParticipationAPI_createParticipation) | **POST** /api/v1/participations | 
[**ParticipationAPI_deleteParticipation**](ParticipationAPI.md#ParticipationAPI_deleteParticipation) | **DELETE** /api/v1/participations/{id} | 
[**ParticipationAPI_getParticipation**](ParticipationAPI.md#ParticipationAPI_getParticipation) | **GET** /api/v1/participations/{id} | 
[**ParticipationAPI_getParticipations**](ParticipationAPI.md#ParticipationAPI_getParticipations) | **GET** /api/v1/participations/ | 
[**ParticipationAPI_updateParticipation**](ParticipationAPI.md#ParticipationAPI_updateParticipation) | **PUT** /api/v1/participations/{id} | 


# **ParticipationAPI_createParticipation**
```c
participation_t* ParticipationAPI_createParticipation(apiClient_t *apiClient, participation_create_t *participation_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**participation_create** | **[participation_create_t](participation_create.md) \*** |  | 

### Return type

[participation_t](participation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ParticipationAPI_deleteParticipation**
```c
void ParticipationAPI_deleteParticipation(apiClient_t *apiClient, char *id);
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

# **ParticipationAPI_getParticipation**
```c
participation_t* ParticipationAPI_getParticipation(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[participation_t](participation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ParticipationAPI_getParticipations**
```c
list_t* ParticipationAPI_getParticipations(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](participation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ParticipationAPI_updateParticipation**
```c
participation_t* ParticipationAPI_updateParticipation(apiClient_t *apiClient, char *id, participation_update_t *participation_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**participation_update** | **[participation_update_t](participation_update.md) \*** |  | 

### Return type

[participation_t](participation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

