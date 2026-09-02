# CreditNoteAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CreditNoteAPI_createCreditNote**](CreditNoteAPI.md#CreditNoteAPI_createCreditNote) | **POST** /api/v1/credit-notes | 
[**CreditNoteAPI_downloadCreditNotePdf**](CreditNoteAPI.md#CreditNoteAPI_downloadCreditNotePdf) | **GET** /api/v1/credit-notes/{credit_note_id}/pdf | 
[**CreditNoteAPI_getCreditNote**](CreditNoteAPI.md#CreditNoteAPI_getCreditNote) | **GET** /api/v1/credit-notes/{credit_note_id} | 
[**CreditNoteAPI_listCreditNotes**](CreditNoteAPI.md#CreditNoteAPI_listCreditNotes) | **GET** /api/v1/credit-notes/ | 


# **CreditNoteAPI_createCreditNote**
```c
invoice_t* CreditNoteAPI_createCreditNote(apiClient_t *apiClient, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** |  |  | 

### Return type

[invoice_t](invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CreditNoteAPI_downloadCreditNotePdf**
```c
void CreditNoteAPI_downloadCreditNotePdf(apiClient_t *apiClient, char *credit_note_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**credit_note_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/pdf, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CreditNoteAPI_getCreditNote**
```c
invoice_t* CreditNoteAPI_getCreditNote(apiClient_t *apiClient, char *credit_note_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**credit_note_id** | **char \*** |  | 

### Return type

[invoice_t](invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CreditNoteAPI_listCreditNotes**
```c
list_t* CreditNoteAPI_listCreditNotes(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

