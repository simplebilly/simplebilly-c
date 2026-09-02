# BankingAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**BankingAPI_bankLookupApi**](BankingAPI.md#BankingAPI_bankLookupApi) | **GET** /api/v1/bookkeeping/banking/lookup | 
[**BankingAPI_bankTransactionsApi**](BankingAPI.md#BankingAPI_bankTransactionsApi) | **GET** /api/v1/bookkeeping/banking/transactions | 
[**BankingAPI_hebesatzLookupApi**](BankingAPI.md#BankingAPI_hebesatzLookupApi) | **GET** /api/v1/bookkeeping/hebesatz | 


# **BankingAPI_bankLookupApi**
```c
bank_lookup_t* BankingAPI_bankLookupApi(apiClient_t *apiClient, char *iban);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**iban** | **char \*** |  | 

### Return type

[bank_lookup_t](bank_lookup.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BankingAPI_bankTransactionsApi**
```c
void BankingAPI_bankTransactionsApi(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BankingAPI_hebesatzLookupApi**
```c
list_t* BankingAPI_hebesatzLookupApi(apiClient_t *apiClient, char *gemeindeschluessel, char *plz, char *name, char *stichtag, char *country_code);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**gemeindeschluessel** | **char \*** |  | [optional] 
**plz** | **char \*** |  | [optional] 
**name** | **char \*** |  | [optional] 
**stichtag** | **char \*** | Stichtag for validity (YYYY-MM-DD); defaults to today. Picks row where valid_from &lt;&#x3D; date &lt;&#x3D; valid_to. | [optional] 
**country_code** | **char \*** |  | [optional] 

### Return type

[list_t](hebesatz_lookup.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

