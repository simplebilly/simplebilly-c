# MarketplaceApiAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**MarketplaceApiAPI_createConnectionApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_createConnectionApi) | **POST** /api/v1/marketplace/connections | Create a new connection (for API-key based platforms)
[**MarketplaceApiAPI_deleteConnectionApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_deleteConnectionApi) | **DELETE** /api/v1/marketplace/connections/{connection_id} | Soft-delete a connection
[**MarketplaceApiAPI_getConnectionApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_getConnectionApi) | **GET** /api/v1/marketplace/connections/{connection_id} | Get a single connection
[**MarketplaceApiAPI_getSyncDirectionApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_getSyncDirectionApi) | **GET** /api/v1/marketplace/connections/{connection_id}/directions | Get current sync direction configuration for a connection
[**MarketplaceApiAPI_getSyncLogsApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_getSyncLogsApi) | **GET** /api/v1/marketplace/connections/{connection_id}/logs | Get sync logs for a connection
[**MarketplaceApiAPI_listConnectionsApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_listConnectionsApi) | **GET** /api/v1/marketplace/connections | List connections for the current tenant
[**MarketplaceApiAPI_listPlatformsApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_listPlatformsApi) | **GET** /api/v1/marketplace/platforms | List all supported platforms
[**MarketplaceApiAPI_oauthAuthorizeApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_oauthAuthorizeApi) | **POST** /api/v1/marketplace/oauth/authorize | OAuth: initiate authorization flow
[**MarketplaceApiAPI_oauthCallbackApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_oauthCallbackApi) | **POST** /api/v1/marketplace/oauth/callback | OAuth: handle callback after authorization
[**MarketplaceApiAPI_triggerSyncApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_triggerSyncApi) | **POST** /api/v1/marketplace/connections/{connection_id}/sync | Trigger sync for a connection
[**MarketplaceApiAPI_updateConnectionApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_updateConnectionApi) | **PUT** /api/v1/marketplace/connections/{connection_id} | Update a connection
[**MarketplaceApiAPI_updateSyncDirectionApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_updateSyncDirectionApi) | **PUT** /api/v1/marketplace/connections/{connection_id}/directions | Update per-entity sync direction configuration for a connection
[**MarketplaceApiAPI_webhookReceiverApi**](MarketplaceApiAPI.md#MarketplaceApiAPI_webhookReceiverApi) | **POST** /api/v1/marketplace/webhook/{platform}/{connection_id} | Webhook receiver


# **MarketplaceApiAPI_createConnectionApi**
```c
// Create a new connection (for API-key based platforms)
//
marketplace_connection_t* MarketplaceApiAPI_createConnectionApi(apiClient_t *apiClient, create_connection_request_t *create_connection_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_connection_request** | **[create_connection_request_t](create_connection_request.md) \*** |  | 

### Return type

[marketplace_connection_t](marketplace_connection.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **MarketplaceApiAPI_deleteConnectionApi**
```c
// Soft-delete a connection
//
void MarketplaceApiAPI_deleteConnectionApi(apiClient_t *apiClient, char *connection_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**connection_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **MarketplaceApiAPI_getConnectionApi**
```c
// Get a single connection
//
marketplace_connection_t* MarketplaceApiAPI_getConnectionApi(apiClient_t *apiClient, char *connection_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**connection_id** | **char \*** |  | 

### Return type

[marketplace_connection_t](marketplace_connection.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **MarketplaceApiAPI_getSyncDirectionApi**
```c
// Get current sync direction configuration for a connection
//
void MarketplaceApiAPI_getSyncDirectionApi(apiClient_t *apiClient, char *connection_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**connection_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **MarketplaceApiAPI_getSyncLogsApi**
```c
// Get sync logs for a connection
//
list_t* MarketplaceApiAPI_getSyncLogsApi(apiClient_t *apiClient, char *connection_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**connection_id** | **char \*** |  | 

### Return type

[list_t](sync_log.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **MarketplaceApiAPI_listConnectionsApi**
```c
// List connections for the current tenant
//
list_t* MarketplaceApiAPI_listConnectionsApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](marketplace_connection.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **MarketplaceApiAPI_listPlatformsApi**
```c
// List all supported platforms
//
list_t* MarketplaceApiAPI_listPlatformsApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](platform_info.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **MarketplaceApiAPI_oauthAuthorizeApi**
```c
// OAuth: initiate authorization flow
//
o_auth_authorize_response_t* MarketplaceApiAPI_oauthAuthorizeApi(apiClient_t *apiClient, o_auth_authorize_request_t *o_auth_authorize_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**o_auth_authorize_request** | **[o_auth_authorize_request_t](o_auth_authorize_request.md) \*** |  | 

### Return type

[o_auth_authorize_response_t](o_auth_authorize_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **MarketplaceApiAPI_oauthCallbackApi**
```c
// OAuth: handle callback after authorization
//
marketplace_connection_t* MarketplaceApiAPI_oauthCallbackApi(apiClient_t *apiClient, o_auth_callback_request_t *o_auth_callback_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**o_auth_callback_request** | **[o_auth_callback_request_t](o_auth_callback_request.md) \*** |  | 

### Return type

[marketplace_connection_t](marketplace_connection.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **MarketplaceApiAPI_triggerSyncApi**
```c
// Trigger sync for a connection
//
sync_summary_t* MarketplaceApiAPI_triggerSyncApi(apiClient_t *apiClient, char *connection_id, char *sync_type, char *direction);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**connection_id** | **char \*** |  | 
**sync_type** | **char \*** |  | [optional] 
**direction** | **char \*** |  | [optional] 

### Return type

[sync_summary_t](sync_summary.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **MarketplaceApiAPI_updateConnectionApi**
```c
// Update a connection
//
marketplace_connection_t* MarketplaceApiAPI_updateConnectionApi(apiClient_t *apiClient, char *connection_id, update_connection_request_t *update_connection_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**connection_id** | **char \*** |  | 
**update_connection_request** | **[update_connection_request_t](update_connection_request.md) \*** |  | 

### Return type

[marketplace_connection_t](marketplace_connection.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **MarketplaceApiAPI_updateSyncDirectionApi**
```c
// Update per-entity sync direction configuration for a connection
//
void MarketplaceApiAPI_updateSyncDirectionApi(apiClient_t *apiClient, char *connection_id, update_sync_direction_request_t *update_sync_direction_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**connection_id** | **char \*** |  | 
**update_sync_direction_request** | **[update_sync_direction_request_t](update_sync_direction_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **MarketplaceApiAPI_webhookReceiverApi**
```c
// Webhook receiver
//
void MarketplaceApiAPI_webhookReceiverApi(apiClient_t *apiClient, char *platform, char *connection_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**platform** | **char \*** |  | 
**connection_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

