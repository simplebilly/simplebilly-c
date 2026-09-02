# return_order_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**customer_contact_id** | **char \*** | References the contact entity. | [optional] 
**customer_name** | **char \*** |  | [optional] 
**line_items** | **any_type_t \*** | JSON array of &#x60;{product_id, name, quantity, condition, restock, batch_number?}&#x60;. | [optional] 
**notes** | **char \*** |  | [optional] 
**order_id** | **char \*** | References the order entity. | [optional] 
**order_number** | **char \*** |  | [optional] 
**return_number** | **char \*** |  | 
**return_reason** | **char \*** |  | [optional] 
**status** | **return_order_status_t \*** | One of: requested | received | inspected | restocked | closed | 
**warehouse_id** | **char \*** | Warehouse into which restockable items are returned. References the warehouse entity. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


