# InvoiceAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InvoiceAPI_createInvoice**](InvoiceAPI.md#InvoiceAPI_createInvoice) | **POST** /api/v1/invoices | 
[**InvoiceAPI_deleteInvoice**](InvoiceAPI.md#InvoiceAPI_deleteInvoice) | **DELETE** /api/v1/invoices/{id} | 
[**InvoiceAPI_downloadInvoicePdf**](InvoiceAPI.md#InvoiceAPI_downloadInvoicePdf) | **GET** /api/v1/invoices/{id}/pdf | 
[**InvoiceAPI_getInvoice**](InvoiceAPI.md#InvoiceAPI_getInvoice) | **GET** /api/v1/invoices/{id} | 
[**InvoiceAPI_getInvoicePdfUrl**](InvoiceAPI.md#InvoiceAPI_getInvoicePdfUrl) | **GET** /api/v1/invoices/{id}/pdf-url | 
[**InvoiceAPI_getInvoices**](InvoiceAPI.md#InvoiceAPI_getInvoices) | **GET** /api/v1/invoices/ | 
[**InvoiceAPI_invoiceRestore**](InvoiceAPI.md#InvoiceAPI_invoiceRestore) | **POST** /api/v1/invoices/{id}/restore | 
[**InvoiceAPI_updateInvoice**](InvoiceAPI.md#InvoiceAPI_updateInvoice) | **PUT** /api/v1/invoices/{id} | 


# **InvoiceAPI_createInvoice**
```c
invoice_t* InvoiceAPI_createInvoice(apiClient_t *apiClient, invoice_create_t *invoice_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**invoice_create** | **[invoice_create_t](invoice_create.md) \*** |  | 

### Return type

[invoice_t](invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvoiceAPI_deleteInvoice**
```c
void InvoiceAPI_deleteInvoice(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvoiceAPI_downloadInvoicePdf**
```c
void InvoiceAPI_downloadInvoicePdf(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/pdf, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvoiceAPI_getInvoice**
```c
invoice_t* InvoiceAPI_getInvoice(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[invoice_t](invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvoiceAPI_getInvoicePdfUrl**
```c
invoice_pdf_url_response_t* InvoiceAPI_getInvoicePdfUrl(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[invoice_pdf_url_response_t](invoice_pdf_url_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvoiceAPI_getInvoices**
```c
list_t* InvoiceAPI_getInvoices(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**search** | **char \*** |  | [optional] 
**include_deleted** | **int \*** | Soft-delete entities: set true to include rows with &#x60;deleted_at&#x60; set. | [optional] 

### Return type

[list_t](invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvoiceAPI_invoiceRestore**
```c
invoice_t* InvoiceAPI_invoiceRestore(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[invoice_t](invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvoiceAPI_updateInvoice**
```c
invoice_t* InvoiceAPI_updateInvoice(apiClient_t *apiClient, char *id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**body** |  |  | 

### Return type

[invoice_t](invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

