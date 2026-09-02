# proforma_invoice_create_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**converted_at** | **char \*** |  | [optional] 
**converted_to_invoice_id** | **char \*** | Set when the proforma was converted into a real invoice. References the invoice entity. | [optional] 
**currency** | **currency_code_t \*** |  | 
**customer_id** | **char \*** | References the customer entity. | [optional] 
**customer_snapshot** | **any_type_t \*** | Snapshot of the recipient at issue time (address, VAT id, …). | [optional] 
**issue_date** | **char \*** |  | 
**line_items** | **any_type_t \*** |  | 
**notes** | **char \*** |  | [optional] 
**order_number** | **char \*** | Reference to the order/quote this proforma belongs to. | [optional] 
**payment_due_date** | **char \*** | Optional deadline the real invoice should carry after conversion. | [optional] 
**quotation_id** | **char \*** | References the quotation entity. | [optional] 
**status** | **proforma_invoice_status_t \*** | &#x60;draft&#x60; | &#x60;sent&#x60; | &#x60;converted&#x60;. | 
**subtotal** | **char \*** |  | 
**total_amount** | **char \*** |  | 
**total_tax** | **char \*** |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


