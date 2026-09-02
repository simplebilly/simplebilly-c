# WebhooksAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**WebhooksAPI_createSubscription**](WebhooksAPI.md#WebhooksAPI_createSubscription) | **POST** /api/v1/webhook-subscriptions | Create a webhook subscription (outbound hook).
[**WebhooksAPI_deleteSubscription**](WebhooksAPI.md#WebhooksAPI_deleteSubscription) | **DELETE** /api/v1/webhook-subscriptions/{subscription_id} | Delete a webhook subscription.
[**WebhooksAPI_emitApi**](WebhooksAPI.md#WebhooksAPI_emitApi) | **POST** /api/v1/webhooks/emit | Manually fire an event against matching hooks (for testing/flows).
[**WebhooksAPI_listEvent**](WebhooksAPI.md#WebhooksAPI_listEvent) | **GET** /api/v1/webhook-events | List webhook events (inbound + outbound log).
[**WebhooksAPI_listSubscriptions**](WebhooksAPI.md#WebhooksAPI_listSubscriptions) | **GET** /api/v1/webhook-subscriptions | List webhook subscriptions for the tenant.
[**WebhooksAPI_updateSubscription**](WebhooksAPI.md#WebhooksAPI_updateSubscription) | **PUT** /api/v1/webhook-subscriptions/{subscription_id} | Update a webhook subscription.


# **WebhooksAPI_createSubscription**
```c
// Create a webhook subscription (outbound hook).
//
webhook_subscription_t* WebhooksAPI_createSubscription(apiClient_t *apiClient, create_subscription_request_t *create_subscription_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_subscription_request** | **[create_subscription_request_t](create_subscription_request.md) \*** |  | 

### Return type

[webhook_subscription_t](webhook_subscription.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WebhooksAPI_deleteSubscription**
```c
// Delete a webhook subscription.
//
void WebhooksAPI_deleteSubscription(apiClient_t *apiClient, char *subscription_id);
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
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WebhooksAPI_emitApi**
```c
// Manually fire an event against matching hooks (for testing/flows).
//
void WebhooksAPI_emitApi(apiClient_t *apiClient, emit_event_request_t *emit_event_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**emit_event_request** | **[emit_event_request_t](emit_event_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WebhooksAPI_listEvent**
```c
// List webhook events (inbound + outbound log).
//
list_t* WebhooksAPI_listEvent(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](webhook_event.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WebhooksAPI_listSubscriptions**
```c
// List webhook subscriptions for the tenant.
//
list_t* WebhooksAPI_listSubscriptions(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](webhook_subscription.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WebhooksAPI_updateSubscription**
```c
// Update a webhook subscription.
//
webhook_subscription_t* WebhooksAPI_updateSubscription(apiClient_t *apiClient, char *subscription_id, update_subscription_request_t *update_subscription_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**subscription_id** | **char \*** |  | 
**update_subscription_request** | **[update_subscription_request_t](update_subscription_request.md) \*** |  | 

### Return type

[webhook_subscription_t](webhook_subscription.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

