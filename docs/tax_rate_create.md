# tax_rate_create_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**country_code** | **char \*** | ISO 3166-1 alpha-2 country code. | 
**effective_from** | **char \*** | Date this rate took effect; &#x60;None&#x60; &#x3D; not date-bound. | [optional] 
**is_default** | **int** | Default rate for the country (one per country); fallback for lookups when no dated rate applies. | 
**name** | **char \*** | Human name, e.g. \&quot;VAT\&quot;. | 
**rate_percent** | **long** | Rate in hundredths of a percent: 1900 &#x3D; 19.00%. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


