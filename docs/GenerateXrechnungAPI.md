# GenerateXrechnungAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GenerateXrechnungAPI_generateXrechnungApi**](GenerateXrechnungAPI.md#GenerateXrechnungAPI_generateXrechnungApi) | **GET** /api/v1/invoices/{id}/xrechnung | 


# **GenerateXrechnungAPI_generateXrechnungApi**
```c
x_rechnung_response_t* GenerateXrechnungAPI_generateXrechnungApi(apiClient_t *apiClient, char *id, char *supplier_name, char *supplier_street, char *supplier_city, char *supplier_zip, char *supplier_country, char *supplier_vat_id);
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

[x_rechnung_response_t](x_rechnung_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

