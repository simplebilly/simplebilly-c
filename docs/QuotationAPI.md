# QuotationAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**QuotationAPI_createQuotation**](QuotationAPI.md#QuotationAPI_createQuotation) | **POST** /api/v1/quotations | 
[**QuotationAPI_deleteQuotation**](QuotationAPI.md#QuotationAPI_deleteQuotation) | **DELETE** /api/v1/quotations/{quotation_id} | 
[**QuotationAPI_downloadQuotationPdf**](QuotationAPI.md#QuotationAPI_downloadQuotationPdf) | **GET** /api/v1/quotations/{quotation_id}/pdf | 
[**QuotationAPI_getQuotation**](QuotationAPI.md#QuotationAPI_getQuotation) | **GET** /api/v1/quotations/{quotation_id} | 
[**QuotationAPI_listQuotations**](QuotationAPI.md#QuotationAPI_listQuotations) | **GET** /api/v1/quotations/ | 
[**QuotationAPI_pursueQuotation**](QuotationAPI.md#QuotationAPI_pursueQuotation) | **POST** /api/v1/quotations/{quotation_id}/pursue | 
[**QuotationAPI_quotationRestore**](QuotationAPI.md#QuotationAPI_quotationRestore) | **POST** /api/v1/quotations/{quotation_id}/restore | 
[**QuotationAPI_updateQuotation**](QuotationAPI.md#QuotationAPI_updateQuotation) | **PUT** /api/v1/quotations/{quotation_id} | 


# **QuotationAPI_createQuotation**
```c
quotation_t* QuotationAPI_createQuotation(apiClient_t *apiClient, quotation_create_t *quotation_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**quotation_create** | **[quotation_create_t](quotation_create.md) \*** |  | 

### Return type

[quotation_t](quotation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QuotationAPI_deleteQuotation**
```c
void QuotationAPI_deleteQuotation(apiClient_t *apiClient, char *quotation_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**quotation_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QuotationAPI_downloadQuotationPdf**
```c
void QuotationAPI_downloadQuotationPdf(apiClient_t *apiClient, char *quotation_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**quotation_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/pdf, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QuotationAPI_getQuotation**
```c
quotation_t* QuotationAPI_getQuotation(apiClient_t *apiClient, char *quotation_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**quotation_id** | **char \*** |  | 

### Return type

[quotation_t](quotation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QuotationAPI_listQuotations**
```c
list_t* QuotationAPI_listQuotations(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](quotation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QuotationAPI_pursueQuotation**
```c
order_confirmation_t* QuotationAPI_pursueQuotation(apiClient_t *apiClient, char *quotation_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**quotation_id** | **char \*** |  | 

### Return type

[order_confirmation_t](order_confirmation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QuotationAPI_quotationRestore**
```c
quotation_t* QuotationAPI_quotationRestore(apiClient_t *apiClient, char *quotation_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**quotation_id** | **char \*** |  | 

### Return type

[quotation_t](quotation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **QuotationAPI_updateQuotation**
```c
quotation_t* QuotationAPI_updateQuotation(apiClient_t *apiClient, char *quotation_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**quotation_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[quotation_t](quotation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

