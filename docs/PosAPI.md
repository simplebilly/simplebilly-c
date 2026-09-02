# PosAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PosAPI_posBilling**](PosAPI.md#PosAPI_posBilling) | **GET** /api/pos/billing | 
[**PosAPI_posCreateOrder**](PosAPI.md#PosAPI_posCreateOrder) | **POST** /api/pos/orders | 
[**PosAPI_posCreateRegister**](PosAPI.md#PosAPI_posCreateRegister) | **POST** /api/pos/registers | 
[**PosAPI_posCreateTable**](PosAPI.md#PosAPI_posCreateTable) | **POST** /api/pos/tables | 
[**PosAPI_posDisableRegister**](PosAPI.md#PosAPI_posDisableRegister) | **POST** /api/pos/registers/{id}/disable | 
[**PosAPI_posFreeTable**](PosAPI.md#PosAPI_posFreeTable) | **POST** /api/pos/tables/{id}/free | 
[**PosAPI_posKasseClosing**](PosAPI.md#PosAPI_posKasseClosing) | **POST** /api/pos/kasse/closing | 
[**PosAPI_posKasseEntries**](PosAPI.md#PosAPI_posKasseEntries) | **GET** /api/pos/kasse/entries | 
[**PosAPI_posKasseExport**](PosAPI.md#PosAPI_posKasseExport) | **GET** /api/pos/kasse/export | 
[**PosAPI_posKassePayInOut**](PosAPI.md#PosAPI_posKassePayInOut) | **POST** /api/pos/kasse/pay-in-out | 
[**PosAPI_posListOrders**](PosAPI.md#PosAPI_posListOrders) | **GET** /api/pos/orders | 
[**PosAPI_posListProducts**](PosAPI.md#PosAPI_posListProducts) | **GET** /api/pos/products | 
[**PosAPI_posListRegisters**](PosAPI.md#PosAPI_posListRegisters) | **GET** /api/pos/registers | 
[**PosAPI_posListTables**](PosAPI.md#PosAPI_posListTables) | **GET** /api/pos/tables | 
[**PosAPI_posOrderPrint**](PosAPI.md#PosAPI_posOrderPrint) | **GET** /api/pos/orders/{order_number}/print | 
[**PosAPI_posOrderReceipt**](PosAPI.md#PosAPI_posOrderReceipt) | **GET** /api/pos/orders/{order_number}/receipt | 
[**PosAPI_posPayOrder**](PosAPI.md#PosAPI_posPayOrder) | **POST** /api/pos/orders/{order_number}/pay | 
[**PosAPI_posSumupCheckout**](PosAPI.md#PosAPI_posSumupCheckout) | **POST** /api/pos/sumup/checkout | 


# **PosAPI_posBilling**
```c
any_type_t* PosAPI_posBilling(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posCreateOrder**
```c
any_type_t* PosAPI_posCreateOrder(apiClient_t *apiClient, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** |  |  | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posCreateRegister**
```c
pos_register_t* PosAPI_posCreateRegister(apiClient_t *apiClient, pos_register_create_t *pos_register_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**pos_register_create** | **[pos_register_create_t](pos_register_create.md) \*** |  | 

### Return type

[pos_register_t](pos_register.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posCreateTable**
```c
pos_table_t* PosAPI_posCreateTable(apiClient_t *apiClient, pos_table_create_t *pos_table_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**pos_table_create** | **[pos_table_create_t](pos_table_create.md) \*** |  | 

### Return type

[pos_table_t](pos_table.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posDisableRegister**
```c
pos_register_t* PosAPI_posDisableRegister(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[pos_register_t](pos_register.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posFreeTable**
```c
pos_table_t* PosAPI_posFreeTable(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** |  | 

### Return type

[pos_table_t](pos_table.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posKasseClosing**
```c
any_type_t* PosAPI_posKasseClosing(apiClient_t *apiClient, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** |  |  | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posKasseEntries**
```c
any_type_t* PosAPI_posKasseEntries(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posKasseExport**
```c
any_type_t* PosAPI_posKasseExport(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posKassePayInOut**
```c
any_type_t* PosAPI_posKassePayInOut(apiClient_t *apiClient, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** |  |  | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posListOrders**
```c
any_type_t* PosAPI_posListOrders(apiClient_t *apiClient, char *status);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**status** | **char \*** | Filter by order status | [optional] 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posListProducts**
```c
any_type_t* PosAPI_posListProducts(apiClient_t *apiClient, char *q);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**q** | **char \*** | Product search | [optional] 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posListRegisters**
```c
list_t* PosAPI_posListRegisters(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](pos_register.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posListTables**
```c
list_t* PosAPI_posListTables(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](pos_table.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posOrderPrint**
```c
any_type_t* PosAPI_posOrderPrint(apiClient_t *apiClient, char *order_number);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_number** | **char \*** |  | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posOrderReceipt**
```c
any_type_t* PosAPI_posOrderReceipt(apiClient_t *apiClient, char *order_number);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_number** | **char \*** |  | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posPayOrder**
```c
any_type_t* PosAPI_posPayOrder(apiClient_t *apiClient, char *order_number, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_number** | **char \*** |  | 
**body** |  |  | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PosAPI_posSumupCheckout**
```c
any_type_t* PosAPI_posSumupCheckout(apiClient_t *apiClient, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** |  |  | 

### Return type

[any_type_t](any_type.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

