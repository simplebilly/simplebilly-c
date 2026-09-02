# goods_receipt_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**gr_number** | **char \*** |  | 
**line_items** | **any_type_t \*** | JSON array of &#x60;{product_id, name, quantity, batch_number?, expiry_date?, bin_location?}&#x60;. | 
**notes** | **char \*** |  | [optional] 
**purchase_order_id** | **char \*** | References the purchase order entity. | [optional] 
**receipt_date** | **char \*** |  | 
**supplier_contact_id** | **char \*** | References the supplier entity. | [optional] 
**supplier_name** | **char \*** |  | [optional] 
**warehouse_id** | **char \*** | References the warehouse entity. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


