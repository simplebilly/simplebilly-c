# ShippingRuleAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ShippingRuleAPI_createShippingRule**](ShippingRuleAPI.md#ShippingRuleAPI_createShippingRule) | **POST** /api/v1/shipping-rules | 
[**ShippingRuleAPI_deleteShippingRule**](ShippingRuleAPI.md#ShippingRuleAPI_deleteShippingRule) | **DELETE** /api/v1/shipping-rules/{rule_id} | 
[**ShippingRuleAPI_getShippingRule**](ShippingRuleAPI.md#ShippingRuleAPI_getShippingRule) | **GET** /api/v1/shipping-rules/{rule_id} | 
[**ShippingRuleAPI_listShippingRules**](ShippingRuleAPI.md#ShippingRuleAPI_listShippingRules) | **GET** /api/v1/shipping-rules/ | 
[**ShippingRuleAPI_updateShippingRule**](ShippingRuleAPI.md#ShippingRuleAPI_updateShippingRule) | **PUT** /api/v1/shipping-rules/{rule_id} | 


# **ShippingRuleAPI_createShippingRule**
```c
shipping_rule_t* ShippingRuleAPI_createShippingRule(apiClient_t *apiClient, shipping_rule_create_t *shipping_rule_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**shipping_rule_create** | **[shipping_rule_create_t](shipping_rule_create.md) \*** |  | 

### Return type

[shipping_rule_t](shipping_rule.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShippingRuleAPI_deleteShippingRule**
```c
void ShippingRuleAPI_deleteShippingRule(apiClient_t *apiClient, char *rule_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**rule_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShippingRuleAPI_getShippingRule**
```c
shipping_rule_t* ShippingRuleAPI_getShippingRule(apiClient_t *apiClient, char *rule_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**rule_id** | **char \*** |  | 

### Return type

[shipping_rule_t](shipping_rule.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShippingRuleAPI_listShippingRules**
```c
list_t* ShippingRuleAPI_listShippingRules(apiClient_t *apiClient, int *page, int *page_size, char *country);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**country** | **char \*** |  | [optional] 

### Return type

[list_t](shipping_rule.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ShippingRuleAPI_updateShippingRule**
```c
shipping_rule_t* ShippingRuleAPI_updateShippingRule(apiClient_t *apiClient, char *rule_id, shipping_rule_update_t *shipping_rule_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**rule_id** | **char \*** |  | 
**shipping_rule_update** | **[shipping_rule_update_t](shipping_rule_update.md) \*** |  | 

### Return type

[shipping_rule_t](shipping_rule.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

