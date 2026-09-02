# inventory_count_update_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**count_date** | **char \*** |  | [optional] 
**count_number** | **char \*** |  | [optional] 
**line_items** | **any_type_t \*** | JSON array of &#x60;{product_id, name, sku, expected_quantity, counted_quantity, bin_location?, batch_number?, variance}&#x60;. | [optional] 
**notes** | **char \*** |  | [optional] 
**status** | **inventory_count_status_t \*** | One of: draft | counting | reviewed | posted | [optional] 
**warehouse_id** | **char \*** | References the warehouse entity. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


