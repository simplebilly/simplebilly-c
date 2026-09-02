# PayrollAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PayrollAPI_payrollApprove**](PayrollAPI.md#PayrollAPI_payrollApprove) | **POST** /api/v1/payroll/{id}/approve | 
[**PayrollAPI_payrollAutopay**](PayrollAPI.md#PayrollAPI_payrollAutopay) | **POST** /api/v1/payroll/{id}/autopay | 
[**PayrollAPI_payrollCalculate**](PayrollAPI.md#PayrollAPI_payrollCalculate) | **POST** /api/v1/payroll/{id}/calculate | 
[**PayrollAPI_payrollCreate**](PayrollAPI.md#PayrollAPI_payrollCreate) | **POST** /api/v1/payroll | 
[**PayrollAPI_payrollDelete**](PayrollAPI.md#PayrollAPI_payrollDelete) | **DELETE** /api/v1/payroll/{id} | 
[**PayrollAPI_payrollElsterExport**](PayrollAPI.md#PayrollAPI_payrollElsterExport) | **POST** /api/v1/payroll/{id}/elster-export | 
[**PayrollAPI_payrollEmail**](PayrollAPI.md#PayrollAPI_payrollEmail) | **POST** /api/v1/payroll/{id}/email | 
[**PayrollAPI_payrollEntryPdf**](PayrollAPI.md#PayrollAPI_payrollEntryPdf) | **GET** /api/v1/payroll/{id}/entries/{entry_id}/pdf | 
[**PayrollAPI_payrollGet**](PayrollAPI.md#PayrollAPI_payrollGet) | **GET** /api/v1/payroll/{id} | 
[**PayrollAPI_payrollList**](PayrollAPI.md#PayrollAPI_payrollList) | **GET** /api/v1/payroll | 
[**PayrollAPI_payrollPay**](PayrollAPI.md#PayrollAPI_payrollPay) | **POST** /api/v1/payroll/{id}/pay | 
[**PayrollAPI_payrollPdf**](PayrollAPI.md#PayrollAPI_payrollPdf) | **GET** /api/v1/payroll/{id}/pdf | 
[**PayrollAPI_payrollSummary**](PayrollAPI.md#PayrollAPI_payrollSummary) | **GET** /api/v1/payroll/summary/{year} | 
[**PayrollAPI_payrollSvMeldungen**](PayrollAPI.md#PayrollAPI_payrollSvMeldungen) | **POST** /api/v1/payroll/{id}/sv-meldungen | 


# **PayrollAPI_payrollApprove**
```c
payroll_run_api_t* PayrollAPI_payrollApprove(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[payroll_run_api_t](payroll_run_api.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollAutopay**
```c
any_type_t* PayrollAPI_payrollAutopay(apiClient_t *apiClient, char *id, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**body** |  |  | [optional] 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollCalculate**
```c
payroll_run_api_t* PayrollAPI_payrollCalculate(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[payroll_run_api_t](payroll_run_api.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollCreate**
```c
payroll_run_api_t* PayrollAPI_payrollCreate(apiClient_t *apiClient, payroll_create_payload_t *payroll_create_payload);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**payroll_create_payload** | **[payroll_create_payload_t](payroll_create_payload.md) \*** |  | 

### Return type

[payroll_run_api_t](payroll_run_api.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollDelete**
```c
void PayrollAPI_payrollDelete(apiClient_t *apiClient, char *id);
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
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollElsterExport**
```c
void PayrollAPI_payrollElsterExport(apiClient_t *apiClient, char *id);
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
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollEmail**
```c
any_type_t* PayrollAPI_payrollEmail(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollEntryPdf**
```c
void PayrollAPI_payrollEntryPdf(apiClient_t *apiClient, char *id, char *entry_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**entry_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/pdf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollGet**
```c
payroll_run_api_t* PayrollAPI_payrollGet(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[payroll_run_api_t](payroll_run_api.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollList**
```c
list_t* PayrollAPI_payrollList(apiClient_t *apiClient, int *year, char *status);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | [optional] 
**status** | **char \*** |  | [optional] 

### Return type

[list_t](payroll_run_api.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollPay**
```c
payroll_run_api_t* PayrollAPI_payrollPay(apiClient_t *apiClient, char *id, payroll_pay_payload_t *payroll_pay_payload);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**payroll_pay_payload** | **[payroll_pay_payload_t](payroll_pay_payload.md) \*** |  | 

### Return type

[payroll_run_api_t](payroll_run_api.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollPdf**
```c
void PayrollAPI_payrollPdf(apiClient_t *apiClient, char *id);
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
 - **Accept**: application/pdf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollSummary**
```c
yearly_payroll_summary_t* PayrollAPI_payrollSummary(apiClient_t *apiClient, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 

### Return type

[yearly_payroll_summary_t](yearly_payroll_summary.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PayrollAPI_payrollSvMeldungen**
```c
any_type_t* PayrollAPI_payrollSvMeldungen(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

