# EventSubscriptionAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**EventSubscriptionAPI_createEventSubscription**](EventSubscriptionAPI.md#EventSubscriptionAPI_createEventSubscription) | **POST** /api/v1/event-subscriptions | 
[**EventSubscriptionAPI_deleteEventSubscription**](EventSubscriptionAPI.md#EventSubscriptionAPI_deleteEventSubscription) | **DELETE** /api/v1/event-subscriptions/{subscription_id} | 
[**EventSubscriptionAPI_listEventSubscriptions**](EventSubscriptionAPI.md#EventSubscriptionAPI_listEventSubscriptions) | **GET** /api/v1/event-subscriptions/ | 


# **EventSubscriptionAPI_createEventSubscription**
```c
event_subscription_t* EventSubscriptionAPI_createEventSubscription(apiClient_t *apiClient, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** |  |  | 

### Return type

[event_subscription_t](event_subscription.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EventSubscriptionAPI_deleteEventSubscription**
```c
void EventSubscriptionAPI_deleteEventSubscription(apiClient_t *apiClient, char *subscription_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**subscription_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EventSubscriptionAPI_listEventSubscriptions**
```c
list_t* EventSubscriptionAPI_listEventSubscriptions(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](event_subscription.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

