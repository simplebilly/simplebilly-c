# ProposeAssignmentsAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ProposeAssignmentsAPI_proposeAssignmentsApi**](ProposeAssignmentsAPI.md#ProposeAssignmentsAPI_proposeAssignmentsApi) | **GET** /api/v1/bookkeeping/propose-assignments | 


# **ProposeAssignmentsAPI_proposeAssignmentsApi**
```c
list_t* ProposeAssignmentsAPI_proposeAssignmentsApi(apiClient_t *apiClient, double min_confidence, char *customer_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**min_confidence** | **double** |  | [optional] 
**customer_id** | **char \*** |  | [optional] 

### Return type

[list_t](proposed_assignment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

