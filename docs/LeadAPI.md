# LeadAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**LeadAPI_listLeadsApi**](LeadAPI.md#LeadAPI_listLeadsApi) | **GET** /api/v1/support/leads | 
[**LeadAPI_updateLeadApi**](LeadAPI.md#LeadAPI_updateLeadApi) | **PUT** /api/v1/support/leads/{lead_id} | 


# **LeadAPI_listLeadsApi**
```c
list_t* LeadAPI_listLeadsApi(apiClient_t *apiClient, char *status, char *source, char *search, int *page, int *page_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**status** | **char \*** |  | [optional] 
**source** | **char \*** |  | [optional] 
**search** | **char \*** |  | [optional] 
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 

### Return type

[list_t](lead.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **LeadAPI_updateLeadApi**
```c
lead_t* LeadAPI_updateLeadApi(apiClient_t *apiClient, char *lead_id, lead_update_t *lead_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**lead_id** | **char \*** |  | 
**lead_update** | **[lead_update_t](lead_update.md) \*** |  | 

### Return type

[lead_t](lead.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

