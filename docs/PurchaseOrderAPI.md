# PurchaseOrderAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PurchaseOrderAPI_createPurchaseOrder**](PurchaseOrderAPI.md#PurchaseOrderAPI_createPurchaseOrder) | **POST** /api/v1/purchase-orders | 
[**PurchaseOrderAPI_deletePurchaseOrder**](PurchaseOrderAPI.md#PurchaseOrderAPI_deletePurchaseOrder) | **DELETE** /api/v1/purchase-orders/{purchase_order_id} | 
[**PurchaseOrderAPI_getPurchaseOrder**](PurchaseOrderAPI.md#PurchaseOrderAPI_getPurchaseOrder) | **GET** /api/v1/purchase-orders/{purchase_order_id} | 
[**PurchaseOrderAPI_listPurchaseOrders**](PurchaseOrderAPI.md#PurchaseOrderAPI_listPurchaseOrders) | **GET** /api/v1/purchase-orders/ | 
[**PurchaseOrderAPI_matchInvoice**](PurchaseOrderAPI.md#PurchaseOrderAPI_matchInvoice) | **POST** /api/v1/purchase-orders/{purchase_order_id}/match-invoice | 3-way invoice check (Rechnungsprüfung): compares the purchase order line items, the quantities received via goods receipts, and the supplier invoice line items, reporting quantity and price variances per product.
[**PurchaseOrderAPI_updatePurchaseOrder**](PurchaseOrderAPI.md#PurchaseOrderAPI_updatePurchaseOrder) | **PUT** /api/v1/purchase-orders/{purchase_order_id} | 
[**PurchaseOrderAPI_updatePurchaseOrderStatus**](PurchaseOrderAPI.md#PurchaseOrderAPI_updatePurchaseOrderStatus) | **PUT** /api/v1/purchase-orders/{purchase_order_id}/status | 


# **PurchaseOrderAPI_createPurchaseOrder**
```c
purchase_order_t* PurchaseOrderAPI_createPurchaseOrder(apiClient_t *apiClient, purchase_order_t *purchase_order);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**purchase_order** | **[purchase_order_t](purchase_order.md) \*** |  | 

### Return type

[purchase_order_t](purchase_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PurchaseOrderAPI_deletePurchaseOrder**
```c
void PurchaseOrderAPI_deletePurchaseOrder(apiClient_t *apiClient, char *purchase_order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**purchase_order_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PurchaseOrderAPI_getPurchaseOrder**
```c
purchase_order_t* PurchaseOrderAPI_getPurchaseOrder(apiClient_t *apiClient, char *purchase_order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**purchase_order_id** | **char \*** |  | 

### Return type

[purchase_order_t](purchase_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PurchaseOrderAPI_listPurchaseOrders**
```c
list_t* PurchaseOrderAPI_listPurchaseOrders(apiClient_t *apiClient, int *page, int *page_size, char *status, char *supplier_name, char *search);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**supplier_name** | **char \*** |  | [optional] 
**search** | **char \*** |  | [optional] 

### Return type

[list_t](purchase_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PurchaseOrderAPI_matchInvoice**
```c
// 3-way invoice check (Rechnungsprüfung): compares the purchase order line items, the quantities received via goods receipts, and the supplier invoice line items, reporting quantity and price variances per product.
//
any_type_t* PurchaseOrderAPI_matchInvoice(apiClient_t *apiClient, char *purchase_order_id, invoice_match_request_t *invoice_match_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**purchase_order_id** | **char \*** |  | 
**invoice_match_request** | **[invoice_match_request_t](invoice_match_request.md) \*** |  | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PurchaseOrderAPI_updatePurchaseOrder**
```c
purchase_order_t* PurchaseOrderAPI_updatePurchaseOrder(apiClient_t *apiClient, char *purchase_order_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**purchase_order_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[purchase_order_t](purchase_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PurchaseOrderAPI_updatePurchaseOrderStatus**
```c
purchase_order_t* PurchaseOrderAPI_updatePurchaseOrderStatus(apiClient_t *apiClient, char *purchase_order_id, purchase_order_status_update_t *purchase_order_status_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**purchase_order_id** | **char \*** |  | 
**purchase_order_status_update** | **[purchase_order_status_update_t](purchase_order_status_update.md) \*** |  | 

### Return type

[purchase_order_t](purchase_order.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

