# DeliveryAppointmentAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DeliveryAppointmentAPI_createDeliveryAppointment**](DeliveryAppointmentAPI.md#DeliveryAppointmentAPI_createDeliveryAppointment) | **POST** /api/v1/delivery-appointments | 
[**DeliveryAppointmentAPI_deleteDeliveryAppointment**](DeliveryAppointmentAPI.md#DeliveryAppointmentAPI_deleteDeliveryAppointment) | **DELETE** /api/v1/delivery-appointments/{appointment_id} | 
[**DeliveryAppointmentAPI_getDeliveryAppointment**](DeliveryAppointmentAPI.md#DeliveryAppointmentAPI_getDeliveryAppointment) | **GET** /api/v1/delivery-appointments/{appointment_id} | 
[**DeliveryAppointmentAPI_getPublicDeliveryAppointmentStatus**](DeliveryAppointmentAPI.md#DeliveryAppointmentAPI_getPublicDeliveryAppointmentStatus) | **GET** /api/v1/public/delivery-appointments/status | Supplier/carrier checks appointment status (public, no auth). The appointment is only revealed when email AND token match.
[**DeliveryAppointmentAPI_listDeliveryAppointments**](DeliveryAppointmentAPI.md#DeliveryAppointmentAPI_listDeliveryAppointments) | **GET** /api/v1/delivery-appointments | 
[**DeliveryAppointmentAPI_requestPublicDeliveryAppointment**](DeliveryAppointmentAPI.md#DeliveryAppointmentAPI_requestPublicDeliveryAppointment) | **POST** /api/v1/public/delivery-appointments/request | Supplier/carrier requests an inbound delivery slot (public, no auth). The tenant is derived from the warehouse found by &#x60;code&#x60; — never from the request.
[**DeliveryAppointmentAPI_updateDeliveryAppointment**](DeliveryAppointmentAPI.md#DeliveryAppointmentAPI_updateDeliveryAppointment) | **PUT** /api/v1/delivery-appointments/{appointment_id} | 
[**DeliveryAppointmentAPI_updateDeliveryAppointmentStatus**](DeliveryAppointmentAPI.md#DeliveryAppointmentAPI_updateDeliveryAppointmentStatus) | **PUT** /api/v1/delivery-appointments/{appointment_id}/status | 


# **DeliveryAppointmentAPI_createDeliveryAppointment**
```c
delivery_appointment_t* DeliveryAppointmentAPI_createDeliveryAppointment(apiClient_t *apiClient, delivery_appointment_create_t *delivery_appointment_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delivery_appointment_create** | **[delivery_appointment_create_t](delivery_appointment_create.md) \*** |  | 

### Return type

[delivery_appointment_t](delivery_appointment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryAppointmentAPI_deleteDeliveryAppointment**
```c
void DeliveryAppointmentAPI_deleteDeliveryAppointment(apiClient_t *apiClient, char *appointment_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**appointment_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryAppointmentAPI_getDeliveryAppointment**
```c
delivery_appointment_t* DeliveryAppointmentAPI_getDeliveryAppointment(apiClient_t *apiClient, char *appointment_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**appointment_id** | **char \*** |  | 

### Return type

[delivery_appointment_t](delivery_appointment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryAppointmentAPI_getPublicDeliveryAppointmentStatus**
```c
// Supplier/carrier checks appointment status (public, no auth). The appointment is only revealed when email AND token match.
//
public_delivery_appointment_status_response_t* DeliveryAppointmentAPI_getPublicDeliveryAppointmentStatus(apiClient_t *apiClient, char *appointmentId, char *email, char *token);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**appointmentId** | **char \*** |  | 
**email** | **char \*** |  | 
**token** | **char \*** |  | 

### Return type

[public_delivery_appointment_status_response_t](public_delivery_appointment_status_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryAppointmentAPI_listDeliveryAppointments**
```c
list_t* DeliveryAppointmentAPI_listDeliveryAppointments(apiClient_t *apiClient, int *page, int *page_size, char *status, char *warehouse_id, char from, char to);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**warehouse_id** | **char \*** |  | [optional] 
**from** | **char** |  | [optional] 
**to** | **char** |  | [optional] 

### Return type

[list_t](delivery_appointment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryAppointmentAPI_requestPublicDeliveryAppointment**
```c
// Supplier/carrier requests an inbound delivery slot (public, no auth). The tenant is derived from the warehouse found by `code` — never from the request.
//
public_delivery_appointment_response_t* DeliveryAppointmentAPI_requestPublicDeliveryAppointment(apiClient_t *apiClient, public_delivery_appointment_request_t *public_delivery_appointment_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**public_delivery_appointment_request** | **[public_delivery_appointment_request_t](public_delivery_appointment_request.md) \*** |  | 

### Return type

[public_delivery_appointment_response_t](public_delivery_appointment_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryAppointmentAPI_updateDeliveryAppointment**
```c
delivery_appointment_t* DeliveryAppointmentAPI_updateDeliveryAppointment(apiClient_t *apiClient, char *appointment_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**appointment_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[delivery_appointment_t](delivery_appointment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryAppointmentAPI_updateDeliveryAppointmentStatus**
```c
delivery_appointment_t* DeliveryAppointmentAPI_updateDeliveryAppointmentStatus(apiClient_t *apiClient, char *appointment_id, appointment_status_update_t *appointment_status_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**appointment_id** | **char \*** |  | 
**appointment_status_update** | **[appointment_status_update_t](appointment_status_update.md) \*** |  | 

### Return type

[delivery_appointment_t](delivery_appointment.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

