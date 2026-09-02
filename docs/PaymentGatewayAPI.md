# PaymentGatewayAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PaymentGatewayAPI_createPaymentGatewayApi**](PaymentGatewayAPI.md#PaymentGatewayAPI_createPaymentGatewayApi) | **POST** /api/v1/payment-gateways | 
[**PaymentGatewayAPI_deletePaymentGatewayApi**](PaymentGatewayAPI.md#PaymentGatewayAPI_deletePaymentGatewayApi) | **DELETE** /api/v1/payment-gateways/{gateway_id} | 
[**PaymentGatewayAPI_listPaymentGatewaysApi**](PaymentGatewayAPI.md#PaymentGatewayAPI_listPaymentGatewaysApi) | **GET** /api/v1/payment-gateways/ | 
[**PaymentGatewayAPI_oauthAuthorizeApi**](PaymentGatewayAPI.md#PaymentGatewayAPI_oauthAuthorizeApi) | **POST** /api/v1/payment-gateways/oauth/authorize | 
[**PaymentGatewayAPI_oauthCallbackApi**](PaymentGatewayAPI.md#PaymentGatewayAPI_oauthCallbackApi) | **POST** /api/v1/payment-gateways/oauth/callback | 
[**PaymentGatewayAPI_updatePaymentGatewayApi**](PaymentGatewayAPI.md#PaymentGatewayAPI_updatePaymentGatewayApi) | **PUT** /api/v1/payment-gateways/{gateway_id} | 


# **PaymentGatewayAPI_createPaymentGatewayApi**
```c
payment_gateway_t* PaymentGatewayAPI_createPaymentGatewayApi(apiClient_t *apiClient, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** |  |  | 

### Return type

[payment_gateway_t](payment_gateway.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PaymentGatewayAPI_deletePaymentGatewayApi**
```c
void PaymentGatewayAPI_deletePaymentGatewayApi(apiClient_t *apiClient, char *gateway_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**gateway_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PaymentGatewayAPI_listPaymentGatewaysApi**
```c
list_t* PaymentGatewayAPI_listPaymentGatewaysApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](payment_gateway.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PaymentGatewayAPI_oauthAuthorizeApi**
```c
gateway_o_auth_authorize_response_t* PaymentGatewayAPI_oauthAuthorizeApi(apiClient_t *apiClient, gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**gateway_o_auth_authorize_request** | **[gateway_o_auth_authorize_request_t](gateway_o_auth_authorize_request.md) \*** |  | 

### Return type

[gateway_o_auth_authorize_response_t](gateway_o_auth_authorize_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PaymentGatewayAPI_oauthCallbackApi**
```c
payment_gateway_t* PaymentGatewayAPI_oauthCallbackApi(apiClient_t *apiClient, gateway_o_auth_callback_request_t *gateway_o_auth_callback_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**gateway_o_auth_callback_request** | **[gateway_o_auth_callback_request_t](gateway_o_auth_callback_request.md) \*** |  | 

### Return type

[payment_gateway_t](payment_gateway.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PaymentGatewayAPI_updatePaymentGatewayApi**
```c
payment_gateway_t* PaymentGatewayAPI_updatePaymentGatewayApi(apiClient_t *apiClient, char *gateway_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**gateway_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[payment_gateway_t](payment_gateway.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

