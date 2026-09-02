# GezAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GezAPI_gezApi**](GezAPI.md#GezAPI_gezApi) | **GET** /api/v1/bookkeeping/gez | 


# **GezAPI_gezApi**
```c
gez_report_t* GezAPI_gezApi(apiClient_t *apiClient, int *jahr, char *betriebsstaetten, long kfz, long hotelzimmer, long beschaefigte);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**jahr** | **int \*** |  | [optional] 
**betriebsstaetten** | **char \*** | Liste der Betriebsstätten als JSON, z.B. &#x60;[{\&quot;name\&quot;:\&quot;Filiale 1\&quot;,\&quot;beschaefigte\&quot;:12}]&#x60;. | [optional] 
**kfz** | **long** | Gesamtzahl der betrieblich genutzten Kfz (falls keine Betriebsstätten angegeben sind). | [optional] 
**hotelzimmer** | **long** | Gesamtzahl der Hotel-/Gästezimmer und Ferienwohnungen. | [optional] 
**beschaefigte** | **long** | Gesamtzahl der Beschäftigten (verwendet nur, wenn &#x60;betriebsstaetten&#x60; fehlt; dann wird eine einzelne Betriebsstätte angenommen). | [optional] 

### Return type

[gez_report_t](gez_report.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

