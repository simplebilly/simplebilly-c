# inventory_count_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**count_date** | **char \*** |  | 
**count_number** | **char \*** |  | 
**line_items** | **any_type_t \*** | JSON array of &#x60;{product_id, name, sku, expected_quantity, counted_quantity, bin_location?, batch_number?, variance}&#x60;. | 
**notes** | **char \*** |  | [optional] 
**status** | **inventory_count_status_t \*** | One of: draft | counting | reviewed | posted | 
**warehouse_id** | **char \*** | References the warehouse entity. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


