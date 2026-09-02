# OnlineshopAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**OnlineshopAPI_getSmtpConfigApi**](OnlineshopAPI.md#OnlineshopAPI_getSmtpConfigApi) | **GET** /api/v1/settings/smtp | 
[**OnlineshopAPI_saveSmtpConfigApi**](OnlineshopAPI.md#OnlineshopAPI_saveSmtpConfigApi) | **PUT** /api/v1/settings/smtp | 


# **OnlineshopAPI_getSmtpConfigApi**
```c
smtp_config_t* OnlineshopAPI_getSmtpConfigApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[smtp_config_t](smtp_config.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **OnlineshopAPI_saveSmtpConfigApi**
```c
smtp_config_t* OnlineshopAPI_saveSmtpConfigApi(apiClient_t *apiClient, smtp_config_t *smtp_config);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**smtp_config** | **[smtp_config_t](smtp_config.md) \*** |  | [optional] 

### Return type

[smtp_config_t](smtp_config.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

