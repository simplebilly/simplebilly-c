# CustomerCommunicationAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CustomerCommunicationAPI_createCommunication**](CustomerCommunicationAPI.md#CustomerCommunicationAPI_createCommunication) | **POST** /api/v1/communications | 
[**CustomerCommunicationAPI_customercommunicationRestore**](CustomerCommunicationAPI.md#CustomerCommunicationAPI_customercommunicationRestore) | **POST** /api/v1/communications/{communication_id}/restore | 
[**CustomerCommunicationAPI_deleteCommunication**](CustomerCommunicationAPI.md#CustomerCommunicationAPI_deleteCommunication) | **DELETE** /api/v1/communications/{communication_id} | 
[**CustomerCommunicationAPI_getCommunication**](CustomerCommunicationAPI.md#CustomerCommunicationAPI_getCommunication) | **GET** /api/v1/communications/{communication_id} | 
[**CustomerCommunicationAPI_getContactHistory**](CustomerCommunicationAPI.md#CustomerCommunicationAPI_getContactHistory) | **GET** /api/v1/contacts/{contact_id}/communications | 
[**CustomerCommunicationAPI_listCommunications**](CustomerCommunicationAPI.md#CustomerCommunicationAPI_listCommunications) | **GET** /api/v1/communications/ | 
[**CustomerCommunicationAPI_updateCommunication**](CustomerCommunicationAPI.md#CustomerCommunicationAPI_updateCommunication) | **PUT** /api/v1/communications/{communication_id} | 


# **CustomerCommunicationAPI_createCommunication**
```c
customer_communication_t* CustomerCommunicationAPI_createCommunication(apiClient_t *apiClient, customer_communication_create_t *customer_communication_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**customer_communication_create** | **[customer_communication_create_t](customer_communication_create.md) \*** |  | 

### Return type

[customer_communication_t](customer_communication.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerCommunicationAPI_customercommunicationRestore**
```c
customer_communication_t* CustomerCommunicationAPI_customercommunicationRestore(apiClient_t *apiClient, char *communication_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**communication_id** | **char \*** |  | 

### Return type

[customer_communication_t](customer_communication.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerCommunicationAPI_deleteCommunication**
```c
void CustomerCommunicationAPI_deleteCommunication(apiClient_t *apiClient, char *communication_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**communication_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerCommunicationAPI_getCommunication**
```c
customer_communication_t* CustomerCommunicationAPI_getCommunication(apiClient_t *apiClient, char *communication_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**communication_id** | **char \*** |  | 

### Return type

[customer_communication_t](customer_communication.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerCommunicationAPI_getContactHistory**
```c
contact_history_response_t* CustomerCommunicationAPI_getContactHistory(apiClient_t *apiClient, char *contact_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**contact_id** | **char \*** |  | 

### Return type

[contact_history_response_t](contact_history_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerCommunicationAPI_listCommunications**
```c
list_t* CustomerCommunicationAPI_listCommunications(apiClient_t *apiClient, int *page, int *page_size, char *contact_id, channel, direction, char from, char to);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**contact_id** | **char \*** | Filter history to a single contact. | [optional] 
**channel** |  |  | [optional] 
**direction** |  |  | [optional] 
**from** | **char** | Only include communications after this ISO date (inclusive). | [optional] 
**to** | **char** | Only include communications before this ISO date (inclusive). | [optional] 

### Return type

[list_t](customer_communication.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomerCommunicationAPI_updateCommunication**
```c
customer_communication_t* CustomerCommunicationAPI_updateCommunication(apiClient_t *apiClient, char *communication_id, customer_communication_update_t *customer_communication_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**communication_id** | **char \*** |  | 
**customer_communication_update** | **[customer_communication_update_t](customer_communication_update.md) \*** |  | 

### Return type

[customer_communication_t](customer_communication.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

