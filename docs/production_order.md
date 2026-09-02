# production_order_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**bom_id** | **char \*** | References the BOM entity. | [optional] 
**components** | **any_type_t \*** | JSON snapshot of the BOM components at creation time. | [optional] 
**end_date** | **char \*** |  | [optional] 
**notes** | **char \*** |  | [optional] 
**order_number** | **char \*** |  | 
**product_id** | **char \*** | The finished product to manufacture. References the product entity. | 
**quantity** | **long** | Quantity of finished product to produce. | 
**source_warehouse_id** | **char \*** | Warehouse components are consumed from. References the warehouse entity. | [optional] 
**start_date** | **char \*** |  | [optional] 
**status** | **production_order_status_t \*** | One of: planned | in_production | completed | cancelled | [optional] 
**target_warehouse_id** | **char \*** | Warehouse the finished product is added to. References the warehouse entity. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


