# ProformaInvoiceAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ProformaInvoiceAPI_convertProformaToInvoice**](ProformaInvoiceAPI.md#ProformaInvoiceAPI_convertProformaToInvoice) | **POST** /api/v1/proforma-invoices/{proforma_id}/convert | 
[**ProformaInvoiceAPI_createProformaInvoice**](ProformaInvoiceAPI.md#ProformaInvoiceAPI_createProformaInvoice) | **POST** /api/v1/proforma-invoices | 
[**ProformaInvoiceAPI_deleteProformaInvoice**](ProformaInvoiceAPI.md#ProformaInvoiceAPI_deleteProformaInvoice) | **DELETE** /api/v1/proforma-invoices/{proforma_id} | 
[**ProformaInvoiceAPI_getProformaInvoice**](ProformaInvoiceAPI.md#ProformaInvoiceAPI_getProformaInvoice) | **GET** /api/v1/proforma-invoices/{proforma_id} | 
[**ProformaInvoiceAPI_listProformaInvoices**](ProformaInvoiceAPI.md#ProformaInvoiceAPI_listProformaInvoices) | **GET** /api/v1/proforma-invoices/ | 
[**ProformaInvoiceAPI_updateProformaInvoice**](ProformaInvoiceAPI.md#ProformaInvoiceAPI_updateProformaInvoice) | **PUT** /api/v1/proforma-invoices/{proforma_id} | 


# **ProformaInvoiceAPI_convertProformaToInvoice**
```c
convert_response_t* ProformaInvoiceAPI_convertProformaToInvoice(apiClient_t *apiClient, char *proforma_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**proforma_id** | **char \*** |  | 

### Return type

[convert_response_t](convert_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProformaInvoiceAPI_createProformaInvoice**
```c
proforma_invoice_t* ProformaInvoiceAPI_createProformaInvoice(apiClient_t *apiClient, proforma_invoice_t *proforma_invoice);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**proforma_invoice** | **[proforma_invoice_t](proforma_invoice.md) \*** |  | 

### Return type

[proforma_invoice_t](proforma_invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProformaInvoiceAPI_deleteProformaInvoice**
```c
void ProformaInvoiceAPI_deleteProformaInvoice(apiClient_t *apiClient, char *proforma_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**proforma_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProformaInvoiceAPI_getProformaInvoice**
```c
proforma_invoice_t* ProformaInvoiceAPI_getProformaInvoice(apiClient_t *apiClient, char *proforma_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**proforma_id** | **char \*** |  | 

### Return type

[proforma_invoice_t](proforma_invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProformaInvoiceAPI_listProformaInvoices**
```c
list_t* ProformaInvoiceAPI_listProformaInvoices(apiClient_t *apiClient, int *page, int *page_size, char *status, char *customer_id, char *order_number);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**customer_id** | **char \*** |  | [optional] 
**order_number** | **char \*** |  | [optional] 

### Return type

[list_t](proforma_invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProformaInvoiceAPI_updateProformaInvoice**
```c
proforma_invoice_t* ProformaInvoiceAPI_updateProformaInvoice(apiClient_t *apiClient, char *proforma_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**proforma_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[proforma_invoice_t](proforma_invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

