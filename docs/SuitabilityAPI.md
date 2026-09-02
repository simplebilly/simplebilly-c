# SuitabilityAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SuitabilityAPI_shippingSuitabilityApi**](SuitabilityAPI.md#SuitabilityAPI_shippingSuitabilityApi) | **POST** /api/v1/shipping/suitability | 


# **SuitabilityAPI_shippingSuitabilityApi**
```c
suitability_result_t* SuitabilityAPI_shippingSuitabilityApi(apiClient_t *apiClient, suitability_request_t *suitability_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**suitability_request** | **[suitability_request_t](suitability_request.md) \*** |  | 

### Return type

[suitability_result_t](suitability_result.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

