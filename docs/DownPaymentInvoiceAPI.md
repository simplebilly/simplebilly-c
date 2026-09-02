# DownPaymentInvoiceAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DownPaymentInvoiceAPI_downloadDownPaymentInvoicePdf**](DownPaymentInvoiceAPI.md#DownPaymentInvoiceAPI_downloadDownPaymentInvoicePdf) | **GET** /api/v1/down-payment-invoices/{id}/pdf | 
[**DownPaymentInvoiceAPI_getDownPaymentInvoice**](DownPaymentInvoiceAPI.md#DownPaymentInvoiceAPI_getDownPaymentInvoice) | **GET** /api/v1/down-payment-invoices/{id} | 
[**DownPaymentInvoiceAPI_listDownPaymentInvoices**](DownPaymentInvoiceAPI.md#DownPaymentInvoiceAPI_listDownPaymentInvoices) | **GET** /api/v1/down-payment-invoices/ | 


# **DownPaymentInvoiceAPI_downloadDownPaymentInvoicePdf**
```c
void DownPaymentInvoiceAPI_downloadDownPaymentInvoicePdf(apiClient_t *apiClient, char *id);
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

# **DownPaymentInvoiceAPI_getDownPaymentInvoice**
```c
down_payment_invoice_t* DownPaymentInvoiceAPI_getDownPaymentInvoice(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[down_payment_invoice_t](down_payment_invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DownPaymentInvoiceAPI_listDownPaymentInvoices**
```c
list_t* DownPaymentInvoiceAPI_listDownPaymentInvoices(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](down_payment_invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

