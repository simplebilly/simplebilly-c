# EmployeeAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**EmployeeAPI_createEmployee**](EmployeeAPI.md#EmployeeAPI_createEmployee) | **POST** /api/v1/employees | 
[**EmployeeAPI_deleteEmployee**](EmployeeAPI.md#EmployeeAPI_deleteEmployee) | **DELETE** /api/v1/employees/{id} | 
[**EmployeeAPI_employeeRestore**](EmployeeAPI.md#EmployeeAPI_employeeRestore) | **POST** /api/v1/employees/{id}/restore | 
[**EmployeeAPI_getEmployee**](EmployeeAPI.md#EmployeeAPI_getEmployee) | **GET** /api/v1/employees/{id} | 
[**EmployeeAPI_getEmployeePayrollSummary**](EmployeeAPI.md#EmployeeAPI_getEmployeePayrollSummary) | **GET** /api/v1/employees/{id}/payroll-summary | 
[**EmployeeAPI_getEmployees**](EmployeeAPI.md#EmployeeAPI_getEmployees) | **GET** /api/v1/employees/ | 
[**EmployeeAPI_updateEmployee**](EmployeeAPI.md#EmployeeAPI_updateEmployee) | **PUT** /api/v1/employees/{id} | 


# **EmployeeAPI_createEmployee**
```c
employee_t* EmployeeAPI_createEmployee(apiClient_t *apiClient, employee_create_t *employee_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**employee_create** | **[employee_create_t](employee_create.md) \*** |  | 

### Return type

[employee_t](employee.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmployeeAPI_deleteEmployee**
```c
void EmployeeAPI_deleteEmployee(apiClient_t *apiClient, char *id);
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

# **EmployeeAPI_employeeRestore**
```c
employee_t* EmployeeAPI_employeeRestore(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[employee_t](employee.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmployeeAPI_getEmployee**
```c
employee_t* EmployeeAPI_getEmployee(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[employee_t](employee.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmployeeAPI_getEmployeePayrollSummary**
```c
payroll_summary_t* EmployeeAPI_getEmployeePayrollSummary(apiClient_t *apiClient, char *id, int *year);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**year** | **int \*** | Fiscal year for the breakdown; defaults to the current year. | [optional] 

### Return type

[payroll_summary_t](payroll_summary.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmployeeAPI_getEmployees**
```c
list_t* EmployeeAPI_getEmployees(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);
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

[list_t](employee.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **EmployeeAPI_updateEmployee**
```c
employee_t* EmployeeAPI_updateEmployee(apiClient_t *apiClient, char *id, employee_update_t *employee_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**employee_update** | **[employee_update_t](employee_update.md) \*** |  | 

### Return type

[employee_t](employee.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

