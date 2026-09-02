# DeliveryDateAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DeliveryDateAPI_createDeliveryDate**](DeliveryDateAPI.md#DeliveryDateAPI_createDeliveryDate) | **POST** /api/v1/delivery-dates | 
[**DeliveryDateAPI_deleteDeliveryDate**](DeliveryDateAPI.md#DeliveryDateAPI_deleteDeliveryDate) | **DELETE** /api/v1/delivery-dates/{delivery_date_id} | 
[**DeliveryDateAPI_getDeliveryDate**](DeliveryDateAPI.md#DeliveryDateAPI_getDeliveryDate) | **GET** /api/v1/delivery-dates/{delivery_date_id} | 
[**DeliveryDateAPI_getDeliveryPerformance**](DeliveryDateAPI.md#DeliveryDateAPI_getDeliveryPerformance) | **GET** /api/v1/delivery-dates/performance | On-time performance summary: how many promised delivery dates were met within a period.
[**DeliveryDateAPI_listDeliveryDates**](DeliveryDateAPI.md#DeliveryDateAPI_listDeliveryDates) | **GET** /api/v1/delivery-dates/ | 
[**DeliveryDateAPI_updateDeliveryDate**](DeliveryDateAPI.md#DeliveryDateAPI_updateDeliveryDate) | **PUT** /api/v1/delivery-dates/{delivery_date_id} | 
[**DeliveryDateAPI_updateDeliveryDateStatus**](DeliveryDateAPI.md#DeliveryDateAPI_updateDeliveryDateStatus) | **PUT** /api/v1/delivery-dates/{delivery_date_id}/status | 


# **DeliveryDateAPI_createDeliveryDate**
```c
delivery_date_t* DeliveryDateAPI_createDeliveryDate(apiClient_t *apiClient, delivery_date_create_t *delivery_date_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delivery_date_create** | **[delivery_date_create_t](delivery_date_create.md) \*** |  | 

### Return type

[delivery_date_t](delivery_date.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryDateAPI_deleteDeliveryDate**
```c
void DeliveryDateAPI_deleteDeliveryDate(apiClient_t *apiClient, char *delivery_date_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delivery_date_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryDateAPI_getDeliveryDate**
```c
delivery_date_t* DeliveryDateAPI_getDeliveryDate(apiClient_t *apiClient, char *delivery_date_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delivery_date_id** | **char \*** |  | 

### Return type

[delivery_date_t](delivery_date.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryDateAPI_getDeliveryPerformance**
```c
// On-time performance summary: how many promised delivery dates were met within a period.
//
any_type_t* DeliveryDateAPI_getDeliveryPerformance(apiClient_t *apiClient, int *page, int *pageSize, char *orderNumber, char *status, char from, char to);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**pageSize** | **int \*** |  | [optional] 
**orderNumber** | **char \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**from** | **char** | Only dates on or after this date. | [optional] 
**to** | **char** | Only dates on or before this date. | [optional] 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryDateAPI_listDeliveryDates**
```c
list_t* DeliveryDateAPI_listDeliveryDates(apiClient_t *apiClient, int *page, int *pageSize, char *orderNumber, char *status, char from, char to);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**pageSize** | **int \*** |  | [optional] 
**orderNumber** | **char \*** |  | [optional] 
**status** | **char \*** |  | [optional] 
**from** | **char** | Only dates on or after this date. | [optional] 
**to** | **char** | Only dates on or before this date. | [optional] 

### Return type

[list_t](delivery_date.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryDateAPI_updateDeliveryDate**
```c
delivery_date_t* DeliveryDateAPI_updateDeliveryDate(apiClient_t *apiClient, char *delivery_date_id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delivery_date_id** | **char \*** |  | 
**body** |  |  | 

### Return type

[delivery_date_t](delivery_date.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeliveryDateAPI_updateDeliveryDateStatus**
```c
delivery_date_t* DeliveryDateAPI_updateDeliveryDateStatus(apiClient_t *apiClient, char *delivery_date_id, delivery_date_status_update_t *delivery_date_status_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delivery_date_id** | **char \*** |  | 
**delivery_date_status_update** | **[delivery_date_status_update_t](delivery_date_status_update.md) \*** |  | 

### Return type

[delivery_date_t](delivery_date.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

