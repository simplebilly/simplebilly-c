# ShippingAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ShippingAPI_getCredentialsApi**](ShippingAPI.md#ShippingAPI_getCredentialsApi) | **GET** /api/v1/shipping/credentials | 
[**ShippingAPI_getRatesApi**](ShippingAPI.md#ShippingAPI_getRatesApi) | **POST** /api/v1/shipping/rates | 
[**ShippingAPI_listProvidersApi**](ShippingAPI.md#ShippingAPI_listProvidersApi) | **GET** /api/v1/shipping/providers | 
[**ShippingAPI_saveCredentialsApi**](ShippingAPI.md#ShippingAPI_saveCredentialsApi) | **PUT** /api/v1/shipping/credentials | 


# **ShippingAPI_getCredentialsApi**
```c
shipping_credentials_t* ShippingAPI_getCredentialsApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[shipping_credentials_t](shipping_credentials.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShippingAPI_getRatesApi**
```c
rate_response_t* ShippingAPI_getRatesApi(apiClient_t *apiClient, rate_request_t *rate_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**rate_request** | **[rate_request_t](rate_request.md) \*** |  | 

### Return type

[rate_response_t](rate_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShippingAPI_listProvidersApi**
```c
list_t* ShippingAPI_listProvidersApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](provider_info.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShippingAPI_saveCredentialsApi**
```c
shipping_credentials_t* ShippingAPI_saveCredentialsApi(apiClient_t *apiClient, shipping_credentials_t *shipping_credentials);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**shipping_credentials** | **[shipping_credentials_t](shipping_credentials.md) \*** |  | 

### Return type

[shipping_credentials_t](shipping_credentials.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

