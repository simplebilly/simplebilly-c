# stock_movement_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**delta** | **long** | Signed movement: positive &#x3D; into stock, negative &#x3D; out of stock. | 
**movement_type** | **movement_type_t \*** | One of the &#x60;MOVEMENT_*&#x60; constants. | 
**product_id** | **char \*** | References the product entity. | 
**quantity** | **long** | Absolute quantity moved (always &gt;&#x3D; 0). | 
**reason** | **char \*** |  | [optional] 
**reference_id** | **char \*** | Primary-key of the referencing entity. | [optional] 
**reference_type** | **reference_type_t \*** | Entity that caused the movement, e.g. &#x60;goods_receipt&#x60;, &#x60;stock_transfer&#x60;. | [optional] 
**warehouse_id** | **char \*** | References the warehouse entity. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


