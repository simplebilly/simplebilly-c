# ListOpenItemsAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ListOpenItemsAPI_listOpenItemsApi**](ListOpenItemsAPI.md#ListOpenItemsAPI_listOpenItemsApi) | **GET** /api/v1/bookkeeping/open-items | 


# **ListOpenItemsAPI_listOpenItemsApi**
```c
list_t* ListOpenItemsAPI_listOpenItemsApi(apiClient_t *apiClient, long reminder_level1_days, long reminder_level2_days, long reminder_level3_days, char *customer_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**reminder_level1_days** | **long** |  | [optional] 
**reminder_level2_days** | **long** |  | [optional] 
**reminder_level3_days** | **long** |  | [optional] 
**customer_id** | **char \*** |  | [optional] 

### Return type

[list_t](open_item.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

