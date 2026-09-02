# VoucherAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**VoucherAPI_createVoucher**](VoucherAPI.md#VoucherAPI_createVoucher) | **POST** /api/v1/vouchers | 
[**VoucherAPI_deleteVoucher**](VoucherAPI.md#VoucherAPI_deleteVoucher) | **DELETE** /api/v1/vouchers/{voucher_id} | 
[**VoucherAPI_getVoucher**](VoucherAPI.md#VoucherAPI_getVoucher) | **GET** /api/v1/vouchers/{voucher_id} | 
[**VoucherAPI_listVouchers**](VoucherAPI.md#VoucherAPI_listVouchers) | **GET** /api/v1/vouchers/ | 
[**VoucherAPI_updateVoucher**](VoucherAPI.md#VoucherAPI_updateVoucher) | **PUT** /api/v1/vouchers/{voucher_id} | 
[**VoucherAPI_voucherRestore**](VoucherAPI.md#VoucherAPI_voucherRestore) | **POST** /api/v1/vouchers/{voucher_id}/restore | 


# **VoucherAPI_createVoucher**
```c
voucher_t* VoucherAPI_createVoucher(apiClient_t *apiClient, voucher_create_t *voucher_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**voucher_create** | **[voucher_create_t](voucher_create.md) \*** |  | 

### Return type

[voucher_t](voucher.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **VoucherAPI_deleteVoucher**
```c
void VoucherAPI_deleteVoucher(apiClient_t *apiClient, char *voucher_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**voucher_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **VoucherAPI_getVoucher**
```c
voucher_t* VoucherAPI_getVoucher(apiClient_t *apiClient, char *voucher_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**voucher_id** | **char \*** |  | 

### Return type

[voucher_t](voucher.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **VoucherAPI_listVouchers**
```c
list_t* VoucherAPI_listVouchers(apiClient_t *apiClient, int *page, int *page_size, char *voucher_type, char *voucher_status, char *contact_name, char date_from, char date_to);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**voucher_type** | **char \*** |  | [optional] 
**voucher_status** | **char \*** |  | [optional] 
**contact_name** | **char \*** |  | [optional] 
**date_from** | **char** |  | [optional] 
**date_to** | **char** |  | [optional] 

### Return type

[list_t](voucher.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **VoucherAPI_updateVoucher**
```c
voucher_t* VoucherAPI_updateVoucher(apiClient_t *apiClient, char *voucher_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**voucher_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[voucher_t](voucher.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **VoucherAPI_voucherRestore**
```c
voucher_t* VoucherAPI_voucherRestore(apiClient_t *apiClient, char *voucher_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**voucher_id** | **char \*** |  | 

### Return type

[voucher_t](voucher.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

