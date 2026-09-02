# shipping_rule_create_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**carrier** | **char \*** | Provider that auto-filled this rule (e.g. \&quot;ups\&quot;), if any. | [optional] 
**country** | **country_code_t \*** | None &#x3D; applies to all countries. | [optional] 
**delivery_time** | **char \*** | Delivery time text, e.g. \&quot;1-3\&quot;. | [optional] 
**is_active** | **int** |  | [optional] 
**max_weight_kg** | **double** |  | [optional] 
**min_weight_kg** | **double** |  | [optional] 
**name** | **char \*** | Delivery-method label, e.g. \&quot;Standardversand\&quot;. | 
**notes** | **char \*** |  | [optional] 
**price** | **char \*** | Shipping cost in the shop&#39;s currency. | 
**priority** | **int** | Lower wins when multiple rules match. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


