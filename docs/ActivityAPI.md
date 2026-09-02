# ActivityAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ActivityAPI_createActivity**](ActivityAPI.md#ActivityAPI_createActivity) | **POST** /api/v1/activities | 
[**ActivityAPI_deleteActivity**](ActivityAPI.md#ActivityAPI_deleteActivity) | **DELETE** /api/v1/activities/{activity_id} | 
[**ActivityAPI_getActivity**](ActivityAPI.md#ActivityAPI_getActivity) | **GET** /api/v1/activities/{activity_id} | 
[**ActivityAPI_listActivities**](ActivityAPI.md#ActivityAPI_listActivities) | **GET** /api/v1/activities/ | 
[**ActivityAPI_updateActivity**](ActivityAPI.md#ActivityAPI_updateActivity) | **PUT** /api/v1/activities/{activity_id} | 
[**ActivityAPI_updateActivityStatus**](ActivityAPI.md#ActivityAPI_updateActivityStatus) | **PUT** /api/v1/activities/{activity_id}/status | 


# **ActivityAPI_createActivity**
```c
activity_t* ActivityAPI_createActivity(apiClient_t *apiClient, activity_t *activity);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**activity** | **[activity_t](activity.md) \*** |  | 

### Return type

[activity_t](activity.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityAPI_deleteActivity**
```c
void ActivityAPI_deleteActivity(apiClient_t *apiClient, char *activity_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**activity_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityAPI_getActivity**
```c
activity_t* ActivityAPI_getActivity(apiClient_t *apiClient, char *activity_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**activity_id** | **char \*** |  | 

### Return type

[activity_t](activity.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityAPI_listActivities**
```c
list_t* ActivityAPI_listActivities(apiClient_t *apiClient, int *page, int *pageSize, char *contactId, char *activityType, char *status, char *assignedTo, int *overdueOnly);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**pageSize** | **int \*** |  | [optional] 
**contactId** | **char \*** |  | [optional] 
**activityType** | **char \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**assignedTo** | **char \*** |  | [optional] 
**overdueOnly** | **int \*** | Only show overdue follow-ups. | [optional] 

### Return type

[list_t](activity.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityAPI_updateActivity**
```c
activity_t* ActivityAPI_updateActivity(apiClient_t *apiClient, char *activity_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**activity_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[activity_t](activity.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityAPI_updateActivityStatus**
```c
activity_t* ActivityAPI_updateActivityStatus(apiClient_t *apiClient, char *activity_id, activity_status_update_t *activity_status_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**activity_id** | **char \*** |  | 
**activity_status_update** | **[activity_status_update_t](activity_status_update.md) \*** |  | 

### Return type

[activity_t](activity.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

