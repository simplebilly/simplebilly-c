# GoodsReceiptAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GoodsReceiptAPI_createGoodsReceipt**](GoodsReceiptAPI.md#GoodsReceiptAPI_createGoodsReceipt) | **POST** /api/v1/goods-receipts | 
[**GoodsReceiptAPI_deleteGoodsReceipt**](GoodsReceiptAPI.md#GoodsReceiptAPI_deleteGoodsReceipt) | **DELETE** /api/v1/goods-receipts/{goods_receipt_id} | 
[**GoodsReceiptAPI_getGoodsReceipt**](GoodsReceiptAPI.md#GoodsReceiptAPI_getGoodsReceipt) | **GET** /api/v1/goods-receipts/{goods_receipt_id} | 
[**GoodsReceiptAPI_listGoodsReceipts**](GoodsReceiptAPI.md#GoodsReceiptAPI_listGoodsReceipts) | **GET** /api/v1/goods-receipts/ | 


# **GoodsReceiptAPI_createGoodsReceipt**
```c
goods_receipt_t* GoodsReceiptAPI_createGoodsReceipt(apiClient_t *apiClient, goods_receipt_t *goods_receipt);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**goods_receipt** | **[goods_receipt_t](goods_receipt.md) \*** |  | 

### Return type

[goods_receipt_t](goods_receipt.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **GoodsReceiptAPI_deleteGoodsReceipt**
```c
void GoodsReceiptAPI_deleteGoodsReceipt(apiClient_t *apiClient, char *goods_receipt_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**goods_receipt_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **GoodsReceiptAPI_getGoodsReceipt**
```c
goods_receipt_t* GoodsReceiptAPI_getGoodsReceipt(apiClient_t *apiClient, char *goods_receipt_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**goods_receipt_id** | **char \*** |  | 

### Return type

[goods_receipt_t](goods_receipt.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **GoodsReceiptAPI_listGoodsReceipts**
```c
list_t* GoodsReceiptAPI_listGoodsReceipts(apiClient_t *apiClient, int *page, int *page_size, char *purchase_order_id, char *supplier_name, char *warehouse_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**purchase_order_id** | **char \*** |  | [optional] 
**supplier_name** | **char \*** |  | [optional] 
**warehouse_id** | **char \*** |  | [optional] 

### Return type

[list_t](goods_receipt.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

