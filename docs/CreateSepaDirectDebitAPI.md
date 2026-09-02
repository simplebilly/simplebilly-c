# CreateSepaDirectDebitAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CreateSepaDirectDebitAPI_createSepaDirectDebitApi**](CreateSepaDirectDebitAPI.md#CreateSepaDirectDebitAPI_createSepaDirectDebitApi) | **POST** /api/v1/bookkeeping/sepa-direct-debit | 


# **CreateSepaDirectDebitAPI_createSepaDirectDebitApi**
```c
sepa_direct_debit_response_t* CreateSepaDirectDebitAPI_createSepaDirectDebitApi(apiClient_t *apiClient, char *creditor_name, char *creditor_iban, char *creditor_id, char *mandate_id, char *mandate_date, char *debtor_name, char *debtor_iban, char *amount, char *collection_date, char *creditor_bic, char *debtor_bic, char *description);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**creditor_name** | **char \*** |  | 
**creditor_iban** | **char \*** |  | 
**creditor_id** | **char \*** |  | 
**mandate_id** | **char \*** |  | 
**mandate_date** | **char \*** |  | 
**debtor_name** | **char \*** |  | 
**debtor_iban** | **char \*** |  | 
**amount** | **char \*** |  | 
**collection_date** | **char \*** |  | 
**creditor_bic** | **char \*** |  | [optional] 
**debtor_bic** | **char \*** |  | [optional] 
**description** | **char \*** |  | [optional] 

### Return type

[sepa_direct_debit_response_t](sepa_direct_debit_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

