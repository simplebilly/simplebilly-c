# production_order_costing_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**cost_per_unit** | **char \*** | material_cost_total ÷ quantity. | 
**cost_source** | **char \*** | \&quot;actual\&quot; when costed from stock-movement consumption, else \&quot;planned\&quot;. | 
**lines** | [**list_t**](costing_line.md) \* |  | 
**margin_per_unit** | **char \*** | sale_price − cost_per_unit. | [optional] 
**margin_percent** | **char \*** | margin_per_unit ÷ cost_per_unit as a percentage. | [optional] 
**material_cost_total** | **char \*** | Total material cost for the whole order. | 
**order_number** | **char \*** |  | 
**production_order_id** | **char \*** |  | 
**quantity** | **long** |  | 
**sale_price** | **char \*** | Finished product&#39;s sale price per unit (used to compute margin). | [optional] 
**status** | **char \*** |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


