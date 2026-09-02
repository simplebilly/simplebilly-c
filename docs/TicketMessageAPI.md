# TicketMessageAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TicketMessageAPI_listMessagesApi**](TicketMessageAPI.md#TicketMessageAPI_listMessagesApi) | **GET** /api/v1/support/tickets/{ticket_id}/messages | 
[**TicketMessageAPI_sendMessageApi**](TicketMessageAPI.md#TicketMessageAPI_sendMessageApi) | **POST** /api/v1/support/tickets/{ticket_id}/messages | 


# **TicketMessageAPI_listMessagesApi**
```c
list_t* TicketMessageAPI_listMessagesApi(apiClient_t *apiClient, char *ticket_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ticket_id** | **char \*** |  | 

### Return type

[list_t](ticket_message.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TicketMessageAPI_sendMessageApi**
```c
ticket_message_t* TicketMessageAPI_sendMessageApi(apiClient_t *apiClient, char *ticket_id, send_message_dto_t *send_message_dto);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ticket_id** | **char \*** |  | 
**send_message_dto** | **[send_message_dto_t](send_message_dto.md) \*** |  | 

### Return type

[ticket_message_t](ticket_message.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

