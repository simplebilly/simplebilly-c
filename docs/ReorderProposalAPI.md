# ReorderProposalAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ReorderProposalAPI_applyReorderProposal**](ReorderProposalAPI.md#ReorderProposalAPI_applyReorderProposal) | **POST** /api/v1/reorder-proposals/apply | Convert a reorder proposal into a draft purchase order.
[**ReorderProposalAPI_getReorderProposal**](ReorderProposalAPI.md#ReorderProposalAPI_getReorderProposal) | **GET** /api/v1/reorder-proposals | 


# **ReorderProposalAPI_applyReorderProposal**
```c
// Convert a reorder proposal into a draft purchase order.
//
// Returns the created purchase order id. Suggested line items are generated with the current reorder quantity per product.
//
any_type_t* ReorderProposalAPI_applyReorderProposal(apiClient_t *apiClient, int *configuredOnly, char *warehouseId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**configuredOnly** | **int \*** | Only include products with a reorder point configured (&#x60;min_stock&#x60;). | [optional] 
**warehouseId** | **char \*** | Limit to a single warehouse id. | [optional] 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReorderProposalAPI_getReorderProposal**
```c
reorder_proposal_response_t* ReorderProposalAPI_getReorderProposal(apiClient_t *apiClient, int *configuredOnly, char *warehouseId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**configuredOnly** | **int \*** | Only include products with a reorder point configured (&#x60;min_stock&#x60;). | [optional] 
**warehouseId** | **char \*** | Limit to a single warehouse id. | [optional] 

### Return type

[reorder_proposal_response_t](reorder_proposal_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

