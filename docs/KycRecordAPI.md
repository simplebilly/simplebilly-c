# KycRecordAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**KycRecordAPI_createKycRecord**](KycRecordAPI.md#KycRecordAPI_createKycRecord) | **POST** /api/v1/kyc-records | 
[**KycRecordAPI_deleteKycRecord**](KycRecordAPI.md#KycRecordAPI_deleteKycRecord) | **DELETE** /api/v1/kyc-records/{id} | 
[**KycRecordAPI_getKycRecord**](KycRecordAPI.md#KycRecordAPI_getKycRecord) | **GET** /api/v1/kyc-records/{id} | 
[**KycRecordAPI_getKycRecords**](KycRecordAPI.md#KycRecordAPI_getKycRecords) | **GET** /api/v1/kyc-records/ | 
[**KycRecordAPI_updateKycRecord**](KycRecordAPI.md#KycRecordAPI_updateKycRecord) | **PUT** /api/v1/kyc-records/{id} | 


# **KycRecordAPI_createKycRecord**
```c
kyc_record_t* KycRecordAPI_createKycRecord(apiClient_t *apiClient, kyc_record_create_t *kyc_record_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**kyc_record_create** | **[kyc_record_create_t](kyc_record_create.md) \*** |  | 

### Return type

[kyc_record_t](kyc_record.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **KycRecordAPI_deleteKycRecord**
```c
void KycRecordAPI_deleteKycRecord(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **KycRecordAPI_getKycRecord**
```c
kyc_record_t* KycRecordAPI_getKycRecord(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[kyc_record_t](kyc_record.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **KycRecordAPI_getKycRecords**
```c
list_t* KycRecordAPI_getKycRecords(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](kyc_record.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **KycRecordAPI_updateKycRecord**
```c
kyc_record_t* KycRecordAPI_updateKycRecord(apiClient_t *apiClient, char *id, kyc_record_update_t *kyc_record_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**kyc_record_update** | **[kyc_record_update_t](kyc_record_update.md) \*** |  | 

### Return type

[kyc_record_t](kyc_record.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

