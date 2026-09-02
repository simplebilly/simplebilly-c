# SupportChannelAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SupportChannelAPI_createChannelApi**](SupportChannelAPI.md#SupportChannelAPI_createChannelApi) | **POST** /api/v1/support/channels | 
[**SupportChannelAPI_deleteChannelApi**](SupportChannelAPI.md#SupportChannelAPI_deleteChannelApi) | **DELETE** /api/v1/support/channels/{channel_id} | 
[**SupportChannelAPI_listChannelsApi**](SupportChannelAPI.md#SupportChannelAPI_listChannelsApi) | **GET** /api/v1/support/channels | 
[**SupportChannelAPI_updateChannelApi**](SupportChannelAPI.md#SupportChannelAPI_updateChannelApi) | **PUT** /api/v1/support/channels/{channel_id} | 


# **SupportChannelAPI_createChannelApi**
```c
support_channel_t* SupportChannelAPI_createChannelApi(apiClient_t *apiClient, create_channel_dto_t *create_channel_dto);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_channel_dto** | **[create_channel_dto_t](create_channel_dto.md) \*** |  | 

### Return type

[support_channel_t](support_channel.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupportChannelAPI_deleteChannelApi**
```c
void SupportChannelAPI_deleteChannelApi(apiClient_t *apiClient, char *channel_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**channel_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupportChannelAPI_listChannelsApi**
```c
list_t* SupportChannelAPI_listChannelsApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](support_channel.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupportChannelAPI_updateChannelApi**
```c
support_channel_t* SupportChannelAPI_updateChannelApi(apiClient_t *apiClient, char *channel_id, update_channel_dto_t *update_channel_dto);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**channel_id** | **char \*** |  | 
**update_channel_dto** | **[update_channel_dto_t](update_channel_dto.md) \*** |  | 

### Return type

[support_channel_t](support_channel.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

