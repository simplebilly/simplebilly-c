# PackingAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PackingAPI_completePacking**](PackingAPI.md#PackingAPI_completePacking) | **POST** /api/v1/packing/{order_number}/complete | Mark packing as complete and transition order to shipped
[**PackingAPI_getPackingQueue**](PackingAPI.md#PackingAPI_getPackingQueue) | **GET** /api/v1/packing/queue | Get the packing queue - orders ready for packing
[**PackingAPI_printDeliveryNote**](PackingAPI.md#PackingAPI_printDeliveryNote) | **POST** /api/v1/packing/{order_number}/print-delivery-note | Print delivery note (Lieferschein) for an order
[**PackingAPI_printLabel**](PackingAPI.md#PackingAPI_printLabel) | **POST** /api/v1/packing/{order_number}/print-label | Print shipping label for an order
[**PackingAPI_recordPackingVideo**](PackingAPI.md#PackingAPI_recordPackingVideo) | **POST** /api/v1/packing/{order_number}/record-video | Record video of packing process


# **PackingAPI_completePacking**
```c
// Mark packing as complete and transition order to shipped
//
packing_complete_response_t* PackingAPI_completePacking(apiClient_t *apiClient, char *order_number, packing_complete_request_t *packing_complete_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_number** | **char \*** |  | 
**packing_complete_request** | **[packing_complete_request_t](packing_complete_request.md) \*** |  | 

### Return type

[packing_complete_response_t](packing_complete_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PackingAPI_getPackingQueue**
```c
// Get the packing queue - orders ready for packing
//
packing_queue_t* PackingAPI_getPackingQueue(apiClient_t *apiClient, int *page, int *page_size, char *search);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**search** | **char \*** |  | [optional] 

### Return type

[packing_queue_t](packing_queue.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PackingAPI_printDeliveryNote**
```c
// Print delivery note (Lieferschein) for an order
//
print_delivery_note_response_t* PackingAPI_printDeliveryNote(apiClient_t *apiClient, char *order_number);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_number** | **char \*** |  | 

### Return type

[print_delivery_note_response_t](print_delivery_note_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PackingAPI_printLabel**
```c
// Print shipping label for an order
//
print_label_response_t* PackingAPI_printLabel(apiClient_t *apiClient, char *order_number);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_number** | **char \*** |  | 

### Return type

[print_label_response_t](print_label_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PackingAPI_recordPackingVideo**
```c
// Record video of packing process
//
packing_video_response_t* PackingAPI_recordPackingVideo(apiClient_t *apiClient, char *order_number, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_number** | **char \*** |  | 
**body** |  |  | 

### Return type

[packing_video_response_t](packing_video_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

