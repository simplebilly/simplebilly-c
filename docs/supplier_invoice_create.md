# supplier_invoice_create_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**currency** | **char \*** |  | [optional] 
**goods_receipt_id** | **char \*** | References the goods receipt entity. | [optional] 
**invoice_date** | **char \*** |  | 
**invoice_number** | **char \*** |  | 
**line_items** | **any_type_t \*** | JSON array of &#x60;{product_id, name, quantity, unitPriceNet, taxRate}&#x60;. | 
**notes** | **char \*** |  | [optional] 
**purchase_order_id** | **char \*** | References the purchase order entity. | [optional] 
**status** | **supplier_invoice_status_t \*** | One of: draft | matched | has_variances | posted | cancelled | 
**supplier_contact_id** | **char \*** | References the supplier entity. | [optional] 
**supplier_name** | **char \*** |  | [optional] 
**total_gross_amount** | **char \*** |  | [optional] 
**total_net_amount** | **char \*** |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


