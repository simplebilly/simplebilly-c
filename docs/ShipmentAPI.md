# ShipmentAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ShipmentAPI_createShipment**](ShipmentAPI.md#ShipmentAPI_createShipment) | **POST** /api/v1/shipments | 
[**ShipmentAPI_createShipmentFromOrder**](ShipmentAPI.md#ShipmentAPI_createShipmentFromOrder) | **POST** /api/v1/orders/{order_number}/shipments | Create a real shipment for an order: calls the configured carrier&#39;s label API, stores the returned tracking/label on a new shipment row, and marks the order as shipped.
[**ShipmentAPI_deleteShipment**](ShipmentAPI.md#ShipmentAPI_deleteShipment) | **DELETE** /api/v1/shipments/{shipment_id} | 
[**ShipmentAPI_getShipment**](ShipmentAPI.md#ShipmentAPI_getShipment) | **GET** /api/v1/shipments/{shipment_id} | 
[**ShipmentAPI_listShipments**](ShipmentAPI.md#ShipmentAPI_listShipments) | **GET** /api/v1/shipments | 
[**ShipmentAPI_trackOrderPublic**](ShipmentAPI.md#ShipmentAPI_trackOrderPublic) | **POST** /api/v1/public/track | Customer-facing tracking lookup: order number + email → shipment status and live carrier events. No auth (public storefront API).
[**ShipmentAPI_trackShipmentApi**](ShipmentAPI.md#ShipmentAPI_trackShipmentApi) | **GET** /api/v1/shipments/{shipment_id}/tracking | 
[**ShipmentAPI_updateShipmentStatus**](ShipmentAPI.md#ShipmentAPI_updateShipmentStatus) | **PUT** /api/v1/shipments/{shipment_id}/status | 


# **ShipmentAPI_createShipment**
```c
shipment_t* ShipmentAPI_createShipment(apiClient_t *apiClient, shipment_t *shipment);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**shipment** | **[shipment_t](shipment.md) \*** |  | 

### Return type

[shipment_t](shipment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShipmentAPI_createShipmentFromOrder**
```c
// Create a real shipment for an order: calls the configured carrier's label API, stores the returned tracking/label on a new shipment row, and marks the order as shipped.
//
shipment_t* ShipmentAPI_createShipmentFromOrder(apiClient_t *apiClient, char *order_number, create_shipment_request_t *create_shipment_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_number** | **char \*** |  | 
**create_shipment_request** | **[create_shipment_request_t](create_shipment_request.md) \*** |  | 

### Return type

[shipment_t](shipment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShipmentAPI_deleteShipment**
```c
void ShipmentAPI_deleteShipment(apiClient_t *apiClient, char *shipment_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**shipment_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShipmentAPI_getShipment**
```c
shipment_t* ShipmentAPI_getShipment(apiClient_t *apiClient, char *shipment_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**shipment_id** | **char \*** |  | 

### Return type

[shipment_t](shipment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShipmentAPI_listShipments**
```c
list_t* ShipmentAPI_listShipments(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](shipment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShipmentAPI_trackOrderPublic**
```c
// Customer-facing tracking lookup: order number + email → shipment status and live carrier events. No auth (public storefront API).
//
track_order_response_t* ShipmentAPI_trackOrderPublic(apiClient_t *apiClient, track_order_request_t *track_order_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**track_order_request** | **[track_order_request_t](track_order_request.md) \*** |  | 

### Return type

[track_order_response_t](track_order_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShipmentAPI_trackShipmentApi**
```c
tracking_info_t* ShipmentAPI_trackShipmentApi(apiClient_t *apiClient, char *shipment_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**shipment_id** | **char \*** |  | 

### Return type

[tracking_info_t](tracking_info.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShipmentAPI_updateShipmentStatus**
```c
shipment_t* ShipmentAPI_updateShipmentStatus(apiClient_t *apiClient, char *shipment_id, shipment_status_update_t *shipment_status_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**shipment_id** | **char \*** |  | 
**shipment_status_update** | **[shipment_status_update_t](shipment_status_update.md) \*** |  | 

### Return type

[shipment_t](shipment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

