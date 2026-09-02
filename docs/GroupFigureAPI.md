# GroupFigureAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GroupFigureAPI_createGroupFigure**](GroupFigureAPI.md#GroupFigureAPI_createGroupFigure) | **POST** /api/v1/group-figures | 
[**GroupFigureAPI_deleteGroupFigure**](GroupFigureAPI.md#GroupFigureAPI_deleteGroupFigure) | **DELETE** /api/v1/group-figures/{year} | 
[**GroupFigureAPI_getGroupFigure**](GroupFigureAPI.md#GroupFigureAPI_getGroupFigure) | **GET** /api/v1/group-figures/{year} | 
[**GroupFigureAPI_getGroupFigures**](GroupFigureAPI.md#GroupFigureAPI_getGroupFigures) | **GET** /api/v1/group-figures/ | 
[**GroupFigureAPI_updateGroupFigure**](GroupFigureAPI.md#GroupFigureAPI_updateGroupFigure) | **PUT** /api/v1/group-figures/{year} | 


# **GroupFigureAPI_createGroupFigure**
```c
group_figure_t* GroupFigureAPI_createGroupFigure(apiClient_t *apiClient, group_figure_create_t *group_figure_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group_figure_create** | **[group_figure_create_t](group_figure_create.md) \*** |  | 

### Return type

[group_figure_t](group_figure.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **GroupFigureAPI_deleteGroupFigure**
```c
void GroupFigureAPI_deleteGroupFigure(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **GroupFigureAPI_getGroupFigure**
```c
group_figure_t* GroupFigureAPI_getGroupFigure(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[group_figure_t](group_figure.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **GroupFigureAPI_getGroupFigures**
```c
list_t* GroupFigureAPI_getGroupFigures(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](group_figure.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **GroupFigureAPI_updateGroupFigure**
```c
group_figure_t* GroupFigureAPI_updateGroupFigure(apiClient_t *apiClient, int *year, group_figure_update_t *group_figure_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 
**group_figure_update** | **[group_figure_update_t](group_figure_update.md) \*** |  | 

### Return type

[group_figure_t](group_figure.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

