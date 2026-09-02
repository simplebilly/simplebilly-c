# ContactAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ContactAPI_contactSchema**](ContactAPI.md#ContactAPI_contactSchema) | **GET** /api/v1/contacts/schema | Serve JSON Schema for client-side validation
[**ContactAPI_contactTimeline**](ContactAPI.md#ContactAPI_contactTimeline) | **GET** /api/v1/contacts/{contact_id}/timeline | Get the full per-contact timeline (Xentral §4.6/4.7).
[**ContactAPI_createContact**](ContactAPI.md#ContactAPI_createContact) | **POST** /api/v1/contacts | Create contact
[**ContactAPI_deleteContact**](ContactAPI.md#ContactAPI_deleteContact) | **DELETE** /api/v1/contacts/{contact_id} | Soft-delete contact
[**ContactAPI_getContact**](ContactAPI.md#ContactAPI_getContact) | **GET** /api/v1/contacts/{contact_id} | Get single contact
[**ContactAPI_listContacts**](ContactAPI.md#ContactAPI_listContacts) | **GET** /api/v1/contacts | List contacts with search, type filter, and pagination
[**ContactAPI_salesVolume**](ContactAPI.md#ContactAPI_salesVolume) | **GET** /api/v1/contacts/sales-volume | Sales volume per contact
[**ContactAPI_updateContact**](ContactAPI.md#ContactAPI_updateContact) | **PUT** /api/v1/contacts/{contact_id} | Update contact


# **ContactAPI_contactSchema**
```c
// Serve JSON Schema for client-side validation
//
any_type_t* ContactAPI_contactSchema(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ContactAPI_contactTimeline**
```c
// Get the full per-contact timeline (Xentral §4.6/4.7).
//
// Aggregates communications, quotations, orders, invoices and uploaded documents for a contact, merged into a single reverse-chronological feed.
//
contact_timeline_response_t* ContactAPI_contactTimeline(apiClient_t *apiClient, char *contact_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**contact_id** | **char \*** |  | 

### Return type

[contact_timeline_response_t](contact_timeline_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ContactAPI_createContact**
```c
// Create contact
//
contact_t* ContactAPI_createContact(apiClient_t *apiClient, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** |  |  | 

### Return type

[contact_t](contact.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ContactAPI_deleteContact**
```c
// Soft-delete contact
//
void ContactAPI_deleteContact(apiClient_t *apiClient, char *contact_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**contact_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ContactAPI_getContact**
```c
// Get single contact
//
contact_t* ContactAPI_getContact(apiClient_t *apiClient, char *contact_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**contact_id** | **char \*** |  | 

### Return type

[contact_t](contact.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ContactAPI_listContacts**
```c
// List contacts with search, type filter, and pagination
//
list_t* ContactAPI_listContacts(apiClient_t *apiClient, int *page, int *page_size, char *search, char *contact_type, char *tag);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**search** | **char \*** |  | [optional] 
**contact_type** | **char \*** |  | [optional] 
**tag** | **char \*** |  | [optional] 

### Return type

[list_t](contact.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ContactAPI_salesVolume**
```c
// Sales volume per contact
//
sales_volume_report_t* ContactAPI_salesVolume(apiClient_t *apiClient, int *page, int *page_size, char *search, char *contact_type, char *tag);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**search** | **char \*** |  | [optional] 
**contact_type** | **char \*** |  | [optional] 
**tag** | **char \*** |  | [optional] 

### Return type

[sales_volume_report_t](sales_volume_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ContactAPI_updateContact**
```c
// Update contact
//
contact_t* ContactAPI_updateContact(apiClient_t *apiClient, char *contact_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**contact_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[contact_t](contact.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

