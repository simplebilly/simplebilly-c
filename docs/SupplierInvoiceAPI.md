# SupplierInvoiceAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SupplierInvoiceAPI_createSupplierInvoice**](SupplierInvoiceAPI.md#SupplierInvoiceAPI_createSupplierInvoice) | **POST** /api/v1/supplier-invoices | 
[**SupplierInvoiceAPI_deleteSupplierInvoice**](SupplierInvoiceAPI.md#SupplierInvoiceAPI_deleteSupplierInvoice) | **DELETE** /api/v1/supplier-invoices/{supplier_invoice_id} | 
[**SupplierInvoiceAPI_getSupplierInvoice**](SupplierInvoiceAPI.md#SupplierInvoiceAPI_getSupplierInvoice) | **GET** /api/v1/supplier-invoices/{supplier_invoice_id} | 
[**SupplierInvoiceAPI_listSupplierInvoices**](SupplierInvoiceAPI.md#SupplierInvoiceAPI_listSupplierInvoices) | **GET** /api/v1/supplier-invoices/ | 
[**SupplierInvoiceAPI_updateSupplierInvoice**](SupplierInvoiceAPI.md#SupplierInvoiceAPI_updateSupplierInvoice) | **PUT** /api/v1/supplier-invoices/{supplier_invoice_id} | 
[**SupplierInvoiceAPI_updateSupplierInvoiceStatus**](SupplierInvoiceAPI.md#SupplierInvoiceAPI_updateSupplierInvoiceStatus) | **PUT** /api/v1/supplier-invoices/{supplier_invoice_id}/status | 


# **SupplierInvoiceAPI_createSupplierInvoice**
```c
supplier_invoice_t* SupplierInvoiceAPI_createSupplierInvoice(apiClient_t *apiClient, supplier_invoice_t *supplier_invoice);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**supplier_invoice** | **[supplier_invoice_t](supplier_invoice.md) \*** |  | 

### Return type

[supplier_invoice_t](supplier_invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupplierInvoiceAPI_deleteSupplierInvoice**
```c
void SupplierInvoiceAPI_deleteSupplierInvoice(apiClient_t *apiClient, char *supplier_invoice_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**supplier_invoice_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupplierInvoiceAPI_getSupplierInvoice**
```c
supplier_invoice_t* SupplierInvoiceAPI_getSupplierInvoice(apiClient_t *apiClient, char *supplier_invoice_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**supplier_invoice_id** | **char \*** |  | 

### Return type

[supplier_invoice_t](supplier_invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupplierInvoiceAPI_listSupplierInvoices**
```c
list_t* SupplierInvoiceAPI_listSupplierInvoices(apiClient_t *apiClient, int *page, int *page_size, char *status, char *purchase_order_id, char *supplier_name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**purchase_order_id** | **char \*** |  | [optional] 
**supplier_name** | **char \*** |  | [optional] 

### Return type

[list_t](supplier_invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupplierInvoiceAPI_updateSupplierInvoice**
```c
supplier_invoice_t* SupplierInvoiceAPI_updateSupplierInvoice(apiClient_t *apiClient, char *supplier_invoice_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**supplier_invoice_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[supplier_invoice_t](supplier_invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SupplierInvoiceAPI_updateSupplierInvoiceStatus**
```c
supplier_invoice_t* SupplierInvoiceAPI_updateSupplierInvoiceStatus(apiClient_t *apiClient, char *supplier_invoice_id, supplier_invoice_status_update_t *supplier_invoice_status_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**supplier_invoice_id** | **char \*** |  | 
**supplier_invoice_status_update** | **[supplier_invoice_status_update_t](supplier_invoice_status_update.md) \*** |  | 

### Return type

[supplier_invoice_t](supplier_invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

