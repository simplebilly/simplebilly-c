# DeliveryNoteAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DeliveryNoteAPI_createDeliveryNote**](DeliveryNoteAPI.md#DeliveryNoteAPI_createDeliveryNote) | **POST** /api/v1/delivery-notes | 
[**DeliveryNoteAPI_deleteDeliveryNote**](DeliveryNoteAPI.md#DeliveryNoteAPI_deleteDeliveryNote) | **DELETE** /api/v1/delivery-notes/{delivery_note_id} | 
[**DeliveryNoteAPI_deliverynoteRestore**](DeliveryNoteAPI.md#DeliveryNoteAPI_deliverynoteRestore) | **POST** /api/v1/delivery-notes/{delivery_note_id}/restore | 
[**DeliveryNoteAPI_downloadDeliveryNotePdf**](DeliveryNoteAPI.md#DeliveryNoteAPI_downloadDeliveryNotePdf) | **GET** /api/v1/delivery-notes/{delivery_note_id}/pdf | 
[**DeliveryNoteAPI_getDeliveryNote**](DeliveryNoteAPI.md#DeliveryNoteAPI_getDeliveryNote) | **GET** /api/v1/delivery-notes/{delivery_note_id} | 
[**DeliveryNoteAPI_listDeliveryNotes**](DeliveryNoteAPI.md#DeliveryNoteAPI_listDeliveryNotes) | **GET** /api/v1/delivery-notes/ | 
[**DeliveryNoteAPI_pursueDeliveryNote**](DeliveryNoteAPI.md#DeliveryNoteAPI_pursueDeliveryNote) | **POST** /api/v1/delivery-notes/{delivery_note_id}/pursue | 


# **DeliveryNoteAPI_createDeliveryNote**
```c
delivery_note_t* DeliveryNoteAPI_createDeliveryNote(apiClient_t *apiClient, delivery_note_create_t *delivery_note_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delivery_note_create** | **[delivery_note_create_t](delivery_note_create.md) \*** |  | 

### Return type

[delivery_note_t](delivery_note.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryNoteAPI_deleteDeliveryNote**
```c
void DeliveryNoteAPI_deleteDeliveryNote(apiClient_t *apiClient, char *delivery_note_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delivery_note_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryNoteAPI_deliverynoteRestore**
```c
delivery_note_t* DeliveryNoteAPI_deliverynoteRestore(apiClient_t *apiClient, char *delivery_note_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delivery_note_id** | **char \*** |  | 

### Return type

[delivery_note_t](delivery_note.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryNoteAPI_downloadDeliveryNotePdf**
```c
void DeliveryNoteAPI_downloadDeliveryNotePdf(apiClient_t *apiClient, char *delivery_note_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delivery_note_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/pdf, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryNoteAPI_getDeliveryNote**
```c
delivery_note_t* DeliveryNoteAPI_getDeliveryNote(apiClient_t *apiClient, char *delivery_note_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delivery_note_id** | **char \*** |  | 

### Return type

[delivery_note_t](delivery_note.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryNoteAPI_listDeliveryNotes**
```c
list_t* DeliveryNoteAPI_listDeliveryNotes(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](delivery_note.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryNoteAPI_pursueDeliveryNote**
```c
invoice_t* DeliveryNoteAPI_pursueDeliveryNote(apiClient_t *apiClient, char *delivery_note_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delivery_note_id** | **char \*** |  | 

### Return type

[invoice_t](invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

