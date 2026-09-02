# LegalDocumentAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**LegalDocumentAPI_getLegalDocuments**](LegalDocumentAPI.md#LegalDocumentAPI_getLegalDocuments) | **GET** /api/v1/legal/documents | List all legal documents of the tenant. Missing documents are seeded from the default texts (with tenant placeholders replaced) on first access.
[**LegalDocumentAPI_resetLegalDocuments**](LegalDocumentAPI.md#LegalDocumentAPI_resetLegalDocuments) | **POST** /api/v1/legal/documents/reset | Restore default texts for all documents (or a single doc_type/lang when the optional filter is given). Returns the full tenant list.
[**LegalDocumentAPI_upsertLegalDocuments**](LegalDocumentAPI.md#LegalDocumentAPI_upsertLegalDocuments) | **PUT** /api/v1/legal/documents | Upsert legal documents per (doc_type, lang). Returns the full tenant list.


# **LegalDocumentAPI_getLegalDocuments**
```c
// List all legal documents of the tenant. Missing documents are seeded from the default texts (with tenant placeholders replaced) on first access.
//
list_t* LegalDocumentAPI_getLegalDocuments(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](legal_document.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **LegalDocumentAPI_resetLegalDocuments**
```c
// Restore default texts for all documents (or a single doc_type/lang when the optional filter is given). Returns the full tenant list.
//
list_t* LegalDocumentAPI_resetLegalDocuments(apiClient_t *apiClient, legal_document_reset_t *legal_document_reset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**legal_document_reset** | **[legal_document_reset_t](legal_document_reset.md) \*** |  | 

### Return type

[list_t](legal_document.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **LegalDocumentAPI_upsertLegalDocuments**
```c
// Upsert legal documents per (doc_type, lang). Returns the full tenant list.
//
list_t* LegalDocumentAPI_upsertLegalDocuments(apiClient_t *apiClient, list_t *legal_document_upsert);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**legal_document_upsert** | **[list_t](legal_document_upsert.md) \*** |  | 

### Return type

[list_t](legal_document.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

