# TimeEntriesAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TimeEntriesAPI_clockInTimeEntry**](TimeEntriesAPI.md#TimeEntriesAPI_clockInTimeEntry) | **POST** /api/v1/time-entries | Clock in for the authenticated user (resolved via their employee profile).
[**TimeEntriesAPI_clockOutTimeEntry**](TimeEntriesAPI.md#TimeEntriesAPI_clockOutTimeEntry) | **PATCH** /api/v1/time-entries/{id} | Clock out an entry: the entry&#39;s owner, or anyone with &#x60;time_entries:write&#x60;.
[**TimeEntriesAPI_getLaborCosts**](TimeEntriesAPI.md#TimeEntriesAPI_getLaborCosts) | **GET** /api/v1/labor-costs | Labor-cost report: worked hours aggregated per employee / order / day, valued at the employee&#39;s hourly cost rate.
[**TimeEntriesAPI_listTimeEntries**](TimeEntriesAPI.md#TimeEntriesAPI_listTimeEntries) | **GET** /api/v1/time-entries | List time entries with optional date-range / active / employee filters.


# **TimeEntriesAPI_clockInTimeEntry**
```c
// Clock in for the authenticated user (resolved via their employee profile).
//
time_entry_dto_t* TimeEntriesAPI_clockInTimeEntry(apiClient_t *apiClient, time_entry_clock_in_t *time_entry_clock_in);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**time_entry_clock_in** | **[time_entry_clock_in_t](time_entry_clock_in.md) \*** |  | 

### Return type

[time_entry_dto_t](time_entry_dto.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TimeEntriesAPI_clockOutTimeEntry**
```c
// Clock out an entry: the entry's owner, or anyone with `time_entries:write`.
//
time_entry_dto_t* TimeEntriesAPI_clockOutTimeEntry(apiClient_t *apiClient, char *id, time_entry_clock_out_t *time_entry_clock_out);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**time_entry_clock_out** | **[time_entry_clock_out_t](time_entry_clock_out.md) \*** |  | 

### Return type

[time_entry_dto_t](time_entry_dto.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TimeEntriesAPI_getLaborCosts**
```c
// Labor-cost report: worked hours aggregated per employee / order / day, valued at the employee's hourly cost rate.
//
list_t* TimeEntriesAPI_getLaborCosts(apiClient_t *apiClient, char from, char to, char *group_by);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**from** | **char** |  | 
**to** | **char** |  | 
**group_by** | **char \*** | One of \&quot;employee\&quot;, \&quot;order\&quot; or \&quot;day\&quot;. | 

### Return type

[list_t](labor_cost_row.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TimeEntriesAPI_listTimeEntries**
```c
// List time entries with optional date-range / active / employee filters.
//
list_t* TimeEntriesAPI_listTimeEntries(apiClient_t *apiClient, char from, char to, int *active, char *employee_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**from** | **char** |  | [optional] 
**to** | **char** |  | [optional] 
**active** | **int \*** | Only currently running shifts (clock_in set, clock_out null). | [optional] 
**employee_id** | **char \*** |  | [optional] 

### Return type

[list_t](time_entry_dto.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

