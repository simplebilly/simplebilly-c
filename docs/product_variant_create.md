# product_variant_create_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**barcode** | **char \*** |  | [optional] 
**image_link** | **char \*** |  | [optional] 
**is_active** | **int** |  | [optional] 
**name** | **char \*** | Human-readable variant label, e.g. \&quot;Red / M\&quot;. | [optional] 
**option_values** | **any_type_t \*** | Option name → value map, e.g. &#x60;{\&quot;Color\&quot;: \&quot;Red\&quot;, \&quot;Size\&quot;: \&quot;M\&quot;}&#x60;. | [optional] 
**price** | **char \*** | Explicit override price for this variant (takes precedence over parent price + delta). | [optional] 
**price_delta** | **char \*** | Price adjustment relative to the parent product&#39;s &#x60;default_price&#x60;. | [optional] 
**product_id** | **char \*** | The parent product this variant belongs to. References the product entity. | 
**sku** | **char \*** | Variant-specific SKU (must be unique per tenant). | 
**stock_quantity** | **long** | Variant-level stock (optional — may be tracked on the parent only). | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


