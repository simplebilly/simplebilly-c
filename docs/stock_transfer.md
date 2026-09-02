# stock_transfer_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**line_items** | **any_type_t \*** | JSON array of &#x60;{product_id, name, quantity, batch_number?}&#x60;. | 
**notes** | **char \*** |  | [optional] 
**source_warehouse_id** | **char \*** | References the warehouse entity. | 
**status** | **stock_transfer_status_t \*** | One of: draft | completed | cancelled | 
**target_warehouse_id** | **char \*** | References the warehouse entity. | 
**transfer_date** | **char \*** |  | 
**transfer_number** | **char \*** |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


