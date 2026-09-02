# SupportTicketAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SupportTicketAPI_createTicketApi**](SupportTicketAPI.md#SupportTicketAPI_createTicketApi) | **POST** /api/v1/support/tickets | 
[**SupportTicketAPI_deleteTicketApi**](SupportTicketAPI.md#SupportTicketAPI_deleteTicketApi) | **DELETE** /api/v1/support/tickets/{ticket_id} | 
[**SupportTicketAPI_getTicketApi**](SupportTicketAPI.md#SupportTicketAPI_getTicketApi) | **GET** /api/v1/support/tickets/{ticket_id} | 
[**SupportTicketAPI_listTicketsApi**](SupportTicketAPI.md#SupportTicketAPI_listTicketsApi) | **GET** /api/v1/support/tickets | 
[**SupportTicketAPI_updateTicketApi**](SupportTicketAPI.md#SupportTicketAPI_updateTicketApi) | **PUT** /api/v1/support/tickets/{ticket_id} | 


# **SupportTicketAPI_createTicketApi**
```c
support_ticket_t* SupportTicketAPI_createTicketApi(apiClient_t *apiClient, create_ticket_request_t *create_ticket_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_ticket_request** | **[create_ticket_request_t](create_ticket_request.md) \*** |  | 

### Return type

[support_ticket_t](support_ticket.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupportTicketAPI_deleteTicketApi**
```c
void SupportTicketAPI_deleteTicketApi(apiClient_t *apiClient, char *ticket_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ticket_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupportTicketAPI_getTicketApi**
```c
support_ticket_t* SupportTicketAPI_getTicketApi(apiClient_t *apiClient, char *ticket_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ticket_id** | **char \*** |  | 

### Return type

[support_ticket_t](support_ticket.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupportTicketAPI_listTicketsApi**
```c
list_t* SupportTicketAPI_listTicketsApi(apiClient_t *apiClient, char *status, char *priority, char *assigned_to, char *channel_type, char *customer_id, char *search, int *page, int *page_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**status** | **char \*** |  | [optional] 
**priority** | **char \*** |  | [optional] 
**assigned_to** | **char \*** |  | [optional] 
**channel_type** | **char \*** |  | [optional] 
**customer_id** | **char \*** |  | [optional] 
**search** | **char \*** |  | [optional] 
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 

### Return type

[list_t](support_ticket.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupportTicketAPI_updateTicketApi**
```c
support_ticket_t* SupportTicketAPI_updateTicketApi(apiClient_t *apiClient, char *ticket_id, support_ticket_update_t *support_ticket_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ticket_id** | **char \*** |  | 
**support_ticket_update** | **[support_ticket_update_t](support_ticket_update.md) \*** |  | 

### Return type

[support_ticket_t](support_ticket.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

