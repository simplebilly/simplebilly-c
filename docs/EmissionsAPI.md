# EmissionsAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**EmissionsAPI_createEmissionEntryApi**](EmissionsAPI.md#EmissionsAPI_createEmissionEntryApi) | **POST** /api/v1/bookkeeping/emissions/entries | 
[**EmissionsAPI_createEmissionTargetApi**](EmissionsAPI.md#EmissionsAPI_createEmissionTargetApi) | **POST** /api/v1/bookkeeping/emissions/targets | 
[**EmissionsAPI_deleteEmissionEntryApi**](EmissionsAPI.md#EmissionsAPI_deleteEmissionEntryApi) | **DELETE** /api/v1/bookkeeping/emissions/entries/{id} | 
[**EmissionsAPI_deleteEmissionTargetApi**](EmissionsAPI.md#EmissionsAPI_deleteEmissionTargetApi) | **DELETE** /api/v1/bookkeeping/emissions/targets/{id} | 
[**EmissionsAPI_emissionsEntriesApi**](EmissionsAPI.md#EmissionsAPI_emissionsEntriesApi) | **GET** /api/v1/bookkeeping/emissions/entries | 
[**EmissionsAPI_emissionsExportApi**](EmissionsAPI.md#EmissionsAPI_emissionsExportApi) | **GET** /api/v1/bookkeeping/emissions/export | 
[**EmissionsAPI_emissionsFactorsApi**](EmissionsAPI.md#EmissionsAPI_emissionsFactorsApi) | **GET** /api/v1/bookkeeping/emissions/factors | 
[**EmissionsAPI_emissionsReportApi**](EmissionsAPI.md#EmissionsAPI_emissionsReportApi) | **GET** /api/v1/bookkeeping/emissions/report | 
[**EmissionsAPI_emissionsTargetsApi**](EmissionsAPI.md#EmissionsAPI_emissionsTargetsApi) | **GET** /api/v1/bookkeeping/emissions/targets | 


# **EmissionsAPI_createEmissionEntryApi**
```c
emission_entry_t* EmissionsAPI_createEmissionEntryApi(apiClient_t *apiClient, create_emission_entry_t *create_emission_entry);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_emission_entry** | **[create_emission_entry_t](create_emission_entry.md) \*** |  | 

### Return type

[emission_entry_t](emission_entry.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmissionsAPI_createEmissionTargetApi**
```c
emission_target_t* EmissionsAPI_createEmissionTargetApi(apiClient_t *apiClient, create_emission_target_t *create_emission_target);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_emission_target** | **[create_emission_target_t](create_emission_target.md) \*** |  | 

### Return type

[emission_target_t](emission_target.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmissionsAPI_deleteEmissionEntryApi**
```c
void EmissionsAPI_deleteEmissionEntryApi(apiClient_t *apiClient, char *id);
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

# **EmissionsAPI_deleteEmissionTargetApi**
```c
void EmissionsAPI_deleteEmissionTargetApi(apiClient_t *apiClient, char *id);
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

# **EmissionsAPI_emissionsEntriesApi**
```c
list_t* EmissionsAPI_emissionsEntriesApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[list_t](emission_entry.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmissionsAPI_emissionsExportApi**
```c
emissions_export_response_t* EmissionsAPI_emissionsExportApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[emissions_export_response_t](emissions_export_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmissionsAPI_emissionsFactorsApi**
```c
list_t* EmissionsAPI_emissionsFactorsApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](emission_factor_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmissionsAPI_emissionsReportApi**
```c
emissions_report_t* EmissionsAPI_emissionsReportApi(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[emissions_report_t](emissions_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmissionsAPI_emissionsTargetsApi**
```c
list_t* EmissionsAPI_emissionsTargetsApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](emission_target.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

