# BookkeepingAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**BookkeepingAPI_allocatePaymentApi**](BookkeepingAPI.md#BookkeepingAPI_allocatePaymentApi) | **POST** /api/v1/payments/allocate | Allocate a payment to an invoice
[**BookkeepingAPI_bwaReportApi**](BookkeepingAPI.md#BookkeepingAPI_bwaReportApi) | **GET** /api/v1/bookkeeping/bwa | Get BWA (Betriebswirtschaftliche Auswertung) report
[**BookkeepingAPI_elsterStatusApi**](BookkeepingAPI.md#BookkeepingAPI_elsterStatusApi) | **GET** /api/v1/bookkeeping/elster/status | 
[**BookkeepingAPI_elsterValidateApi**](BookkeepingAPI.md#BookkeepingAPI_elsterValidateApi) | **POST** /api/v1/bookkeeping/ustva/elster-validate | 
[**BookkeepingAPI_elsterXmlApi**](BookkeepingAPI.md#BookkeepingAPI_elsterXmlApi) | **GET** /api/v1/bookkeeping/ustva/elster-xml | 
[**BookkeepingAPI_getCashflow**](BookkeepingAPI.md#BookkeepingAPI_getCashflow) | **GET** /api/v1/bookkeeping/cashflow | GET /api/v1/bookkeeping/cashflow Returns operating, investing, and financing cashflow for the given period.
[**BookkeepingAPI_getLiquidity**](BookkeepingAPI.md#BookkeepingAPI_getLiquidity) | **GET** /api/v1/bookkeeping/liquidity | GET /api/v1/bookkeeping/liquidity Returns current liquidity position with ratios.
[**BookkeepingAPI_getOpenInvoicesApi**](BookkeepingAPI.md#BookkeepingAPI_getOpenInvoicesApi) | **GET** /api/v1/payments/open-invoices/{customer_id} | Get open invoices for a customer
[**BookkeepingAPI_getVerfahrensdokumentation**](BookkeepingAPI.md#BookkeepingAPI_getVerfahrensdokumentation) | **GET** /api/v1/bookkeeping/verfahrensdokumentation | GET /api/v1/bookkeeping/verfahrensdokumentation Returns the complete compliance catalog of all documented modules.
[**BookkeepingAPI_runDunningApi**](BookkeepingAPI.md#BookkeepingAPI_runDunningApi) | **POST** /api/v1/bookkeeping/dunning | 


# **BookkeepingAPI_allocatePaymentApi**
```c
// Allocate a payment to an invoice
//
void BookkeepingAPI_allocatePaymentApi(apiClient_t *apiClient, allocate_payment_request_t *allocate_payment_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**allocate_payment_request** | **[allocate_payment_request_t](allocate_payment_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BookkeepingAPI_bwaReportApi**
```c
// Get BWA (Betriebswirtschaftliche Auswertung) report
//
bwa_report_t* BookkeepingAPI_bwaReportApi(apiClient_t *apiClient, int *year, int *month);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | [optional] 
**month** | **int \*** |  | [optional] 

### Return type

[bwa_report_t](bwa_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BookkeepingAPI_elsterStatusApi**
```c
elster_status_t* BookkeepingAPI_elsterStatusApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[elster_status_t](elster_status.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BookkeepingAPI_elsterValidateApi**
```c
void BookkeepingAPI_elsterValidateApi(apiClient_t *apiClient, char *zeitraum);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**zeitraum** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BookkeepingAPI_elsterXmlApi**
```c
void BookkeepingAPI_elsterXmlApi(apiClient_t *apiClient, char *zeitraum);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**zeitraum** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BookkeepingAPI_getCashflow**
```c
// GET /api/v1/bookkeeping/cashflow Returns operating, investing, and financing cashflow for the given period.
//
cashflow_report_t* BookkeepingAPI_getCashflow(apiClient_t *apiClient, int *year, int *month);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | [optional] 
**month** | **int \*** |  | [optional] 

### Return type

[cashflow_report_t](cashflow_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BookkeepingAPI_getLiquidity**
```c
// GET /api/v1/bookkeeping/liquidity Returns current liquidity position with ratios.
//
liquidity_position_t* BookkeepingAPI_getLiquidity(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[liquidity_position_t](liquidity_position.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BookkeepingAPI_getOpenInvoicesApi**
```c
// Get open invoices for a customer
//
list_t* BookkeepingAPI_getOpenInvoicesApi(apiClient_t *apiClient, char *customer_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**customer_id** | **char \*** |  | 

### Return type

[list_t](invoice.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BookkeepingAPI_getVerfahrensdokumentation**
```c
// GET /api/v1/bookkeeping/verfahrensdokumentation Returns the complete compliance catalog of all documented modules.
//
verfahrensdokumentation_t* BookkeepingAPI_getVerfahrensdokumentation(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[verfahrensdokumentation_t](verfahrensdokumentation.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BookkeepingAPI_runDunningApi**
```c
dunning_result_t* BookkeepingAPI_runDunningApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[dunning_result_t](dunning_result.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

