# AbsenceAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AbsenceAPI_createAbsence**](AbsenceAPI.md#AbsenceAPI_createAbsence) | **POST** /api/v1/absences | 
[**AbsenceAPI_deleteAbsence**](AbsenceAPI.md#AbsenceAPI_deleteAbsence) | **DELETE** /api/v1/absences/{id} | 
[**AbsenceAPI_getAbsence**](AbsenceAPI.md#AbsenceAPI_getAbsence) | **GET** /api/v1/absences/{id} | 
[**AbsenceAPI_getAbsences**](AbsenceAPI.md#AbsenceAPI_getAbsences) | **GET** /api/v1/absences/ | 
[**AbsenceAPI_updateAbsence**](AbsenceAPI.md#AbsenceAPI_updateAbsence) | **PUT** /api/v1/absences/{id} | 


# **AbsenceAPI_createAbsence**
```c
absence_t* AbsenceAPI_createAbsence(apiClient_t *apiClient, absence_create_t *absence_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**absence_create** | **[absence_create_t](absence_create.md) \*** |  | 

### Return type

[absence_t](absence.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AbsenceAPI_deleteAbsence**
```c
void AbsenceAPI_deleteAbsence(apiClient_t *apiClient, char *id);
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

# **AbsenceAPI_getAbsence**
```c
absence_t* AbsenceAPI_getAbsence(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[absence_t](absence.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AbsenceAPI_getAbsences**
```c
list_t* AbsenceAPI_getAbsences(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](absence.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AbsenceAPI_updateAbsence**
```c
absence_t* AbsenceAPI_updateAbsence(apiClient_t *apiClient, char *id, absence_update_t *absence_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**absence_update** | **[absence_update_t](absence_update.md) \*** |  | 

### Return type

[absence_t](absence.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

