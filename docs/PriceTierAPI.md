# PriceTierAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PriceTierAPI_createPriceTier**](PriceTierAPI.md#PriceTierAPI_createPriceTier) | **POST** /api/v1/price-tiers | 
[**PriceTierAPI_deletePriceTier**](PriceTierAPI.md#PriceTierAPI_deletePriceTier) | **DELETE** /api/v1/price-tiers/{price_tier_id} | 
[**PriceTierAPI_getPriceTier**](PriceTierAPI.md#PriceTierAPI_getPriceTier) | **GET** /api/v1/price-tiers/{price_tier_id} | 
[**PriceTierAPI_getResolvedPrice**](PriceTierAPI.md#PriceTierAPI_getResolvedPrice) | **GET** /api/v1/price-tiers/resolved | 
[**PriceTierAPI_listPriceTiers**](PriceTierAPI.md#PriceTierAPI_listPriceTiers) | **GET** /api/v1/price-tiers/ | 
[**PriceTierAPI_updatePriceTier**](PriceTierAPI.md#PriceTierAPI_updatePriceTier) | **PUT** /api/v1/price-tiers/{price_tier_id} | 


# **PriceTierAPI_createPriceTier**
```c
price_tier_t* PriceTierAPI_createPriceTier(apiClient_t *apiClient, price_tier_create_t *price_tier_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**price_tier_create** | **[price_tier_create_t](price_tier_create.md) \*** |  | 

### Return type

[price_tier_t](price_tier.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PriceTierAPI_deletePriceTier**
```c
void PriceTierAPI_deletePriceTier(apiClient_t *apiClient, char *price_tier_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**price_tier_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PriceTierAPI_getPriceTier**
```c
price_tier_t* PriceTierAPI_getPriceTier(apiClient_t *apiClient, char *price_tier_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**price_tier_id** | **char \*** |  | 

### Return type

[price_tier_t](price_tier.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PriceTierAPI_getResolvedPrice**
```c
resolved_price_response_t* PriceTierAPI_getResolvedPrice(apiClient_t *apiClient, char *productId, long quantity, char *contactId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**productId** | **char \*** |  | 
**quantity** | **long** |  | [optional] 
**contactId** | **char \*** | Contact used to match customer-group-scoped tiers. | [optional] 

### Return type

[resolved_price_response_t](resolved_price_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PriceTierAPI_listPriceTiers**
```c
list_t* PriceTierAPI_listPriceTiers(apiClient_t *apiClient, int *page, int *page_size, char *product_id, char *customer_group_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**product_id** | **char \*** |  | [optional] 
**customer_group_id** | **char \*** |  | [optional] 

### Return type

[list_t](price_tier.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PriceTierAPI_updatePriceTier**
```c
price_tier_t* PriceTierAPI_updatePriceTier(apiClient_t *apiClient, char *price_tier_id, price_tier_update_t *price_tier_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**price_tier_id** | **char \*** |  | 
**price_tier_update** | **[price_tier_update_t](price_tier_update.md) \*** |  | 

### Return type

[price_tier_t](price_tier.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

