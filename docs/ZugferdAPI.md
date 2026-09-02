# ZugferdAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ZugferdAPI_generateZugferdApi**](ZugferdAPI.md#ZugferdAPI_generateZugferdApi) | **GET** /api/v1/invoices/{id}/zugferd | 


# **ZugferdAPI_generateZugferdApi**
```c
void ZugferdAPI_generateZugferdApi(apiClient_t *apiClient, char *id, char *supplier_name, char *supplier_street, char *supplier_city, char *supplier_zip, char *supplier_country, char *supplier_vat_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**supplier_name** | **char \*** |  | [optional] 
**supplier_street** | **char \*** |  | [optional] 
**supplier_city** | **char \*** |  | [optional] 
**supplier_zip** | **char \*** |  | [optional] 
**supplier_country** | **char \*** |  | [optional] 
**supplier_vat_id** | **char \*** |  | [optional] 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/pdf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

