# GenerateQrcodeAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GenerateQrcodeAPI_generateQrcodeApi**](GenerateQrcodeAPI.md#GenerateQrcodeAPI_generateQrcodeApi) | **GET** /api/v1/invoices/{id}/qrcode | 


# **GenerateQrcodeAPI_generateQrcodeApi**
```c
qr_code_response_t* GenerateQrcodeAPI_generateQrcodeApi(apiClient_t *apiClient, char *iban, char *id, char *holder_name, char *bic, char *amount, char *reference, char *purpose);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**iban** | **char \*** |  | 
**id** | **char \*** |  | 
**holder_name** | **char \*** |  | [optional] 
**bic** | **char \*** |  | [optional] 
**amount** | **char \*** |  | [optional] 
**reference** | **char \*** |  | [optional] 
**purpose** | **char \*** |  | [optional] 

### Return type

[qr_code_response_t](qr_code_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

