# supplier_condition_create_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**currency** | **char \*** | Currency for the minimum order value. | 
**delivery_terms** | **char \*** | Incoterms, e.g. \&quot;EXW\&quot;, \&quot;DAP\&quot;. | [optional] 
**early_payment_discount_percent** | **char \*** | Early-payment discount percentage (Skonto), e.g. 2.0. | [optional] 
**is_default** | **int** | Is this the default condition for the supplier? | [optional] 
**minimum_order_value** | **char \*** | Minimum order value required for this supplier. | [optional] 
**notes** | **char \*** |  | [optional] 
**payment_due_days** | **int** | Number of days within which payment is due. | [optional] 
**payment_terms** | **char \*** | Payment terms, e.g. \&quot;14 Tage, 2% Skonto\&quot;. | [optional] 
**supplier_contact_id** | **char \*** | The supplier this condition applies to (&#x60;contact_id&#x60;). References the supplier entity. | 
**supplier_name** | **char \*** | The name of the supplier, denormalized for easy listing. | [optional] 
**volume_discount_tiers** | **any_type_t \*** | Tiered discounts: JSON array of &#x60;{min_quantity, discount_percent}&#x60;. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


