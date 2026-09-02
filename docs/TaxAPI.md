# TaxAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TaxAPI_createTaxRate**](TaxAPI.md#TaxAPI_createTaxRate) | **POST** /api/v1/tax-rates | Create a tax rate (&#x60;admin:settings&#x60;).
[**TaxAPI_deleteTaxRate**](TaxAPI.md#TaxAPI_deleteTaxRate) | **DELETE** /api/v1/tax-rates/{id} | Delete a tax rate by id (&#x60;admin:settings&#x60;).
[**TaxAPI_listTaxRates**](TaxAPI.md#TaxAPI_listTaxRates) | **GET** /api/v1/tax-rates | List the calling tenant&#39;s tax rates.
[**TaxAPI_updateTaxRate**](TaxAPI.md#TaxAPI_updateTaxRate) | **PUT** /api/v1/tax-rates/{id} | Update a tax rate by id (&#x60;admin:settings&#x60;). Replaces all body fields.


# **TaxAPI_createTaxRate**
```c
// Create a tax rate (`admin:settings`).
//
void TaxAPI_createTaxRate(apiClient_t *apiClient, tax_rate_create_t *tax_rate_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**tax_rate_create** | **[tax_rate_create_t](tax_rate_create.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TaxAPI_deleteTaxRate**
```c
// Delete a tax rate by id (`admin:settings`).
//
void TaxAPI_deleteTaxRate(apiClient_t *apiClient, char *id);
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

# **TaxAPI_listTaxRates**
```c
// List the calling tenant's tax rates.
//
void TaxAPI_listTaxRates(apiClient_t *apiClient);
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

# **TaxAPI_updateTaxRate**
```c
// Update a tax rate by id (`admin:settings`). Replaces all body fields.
//
void TaxAPI_updateTaxRate(apiClient_t *apiClient, char *id, tax_rate_create_t *tax_rate_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 
**tax_rate_create** | **[tax_rate_create_t](tax_rate_create.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

