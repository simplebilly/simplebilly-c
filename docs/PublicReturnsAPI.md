# PublicReturnsAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PublicReturnsAPI_getPublicReturnStatus**](PublicReturnsAPI.md#PublicReturnsAPI_getPublicReturnStatus) | **GET** /api/v1/public/returns/status | Customer checks the status of a return (public, no auth). The return is only revealed when its linked order&#39;s email matches.
[**PublicReturnsAPI_listPublicReturns**](PublicReturnsAPI.md#PublicReturnsAPI_listPublicReturns) | **GET** /api/v1/public/returns/list | List all returns for an order (public, no auth).
[**PublicReturnsAPI_requestPublicReturn**](PublicReturnsAPI.md#PublicReturnsAPI_requestPublicReturn) | **POST** /api/v1/public/returns/request | Customer requests a return for an order (public, no auth).


# **PublicReturnsAPI_getPublicReturnStatus**
```c
// Customer checks the status of a return (public, no auth). The return is only revealed when its linked order's email matches.
//
public_return_status_response_t* PublicReturnsAPI_getPublicReturnStatus(apiClient_t *apiClient, char *email, char *returnNumber, char *returnOrderId, char *orderNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**email** | **char \*** |  | 
**returnNumber** | **char \*** | Either return_number or return_order_id must be provided. | [optional] 
**returnOrderId** | **char \*** |  | [optional] 
**orderNumber** | **char \*** |  | [optional] 

### Return type

[public_return_status_response_t](public_return_status_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PublicReturnsAPI_listPublicReturns**
```c
// List all returns for an order (public, no auth).
//
list_t* PublicReturnsAPI_listPublicReturns(apiClient_t *apiClient, char *orderNumber, char *email);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**orderNumber** | **char \*** |  | 
**email** | **char \*** |  | 

### Return type

[list_t](public_return_status_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PublicReturnsAPI_requestPublicReturn**
```c
// Customer requests a return for an order (public, no auth).
//
public_return_response_t* PublicReturnsAPI_requestPublicReturn(apiClient_t *apiClient, public_return_request_t *public_return_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**public_return_request** | **[public_return_request_t](public_return_request.md) \*** |  | 

### Return type

[public_return_response_t](public_return_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

