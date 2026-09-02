# purchase_order_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**currency** | **char \*** |  | [optional] 
**delivery_address** | **any_type_t \*** |  | [optional] 
**expected_delivery_date** | **char \*** |  | [optional] 
**line_items** | **any_type_t \*** | JSON array of &#x60;{product_id, name, quantity, unit_price_net, tax_rate, delivery_date}&#x60;. | [optional] 
**notes** | **char \*** |  | [optional] 
**order_date** | **char \*** |  | 
**po_number** | **char \*** |  | 
**status** | **purchase_order_status_t \*** | One of: draft | ordered | partially_received | received | cancelled | 
**supplier_contact_id** | **char \*** | References the supplier entity. | [optional] 
**supplier_name** | **char \*** |  | [optional] 
**total_gross_amount** | **char \*** |  | [optional] 
**total_net_amount** | **char \*** |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


