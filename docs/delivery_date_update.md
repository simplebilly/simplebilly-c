# delivery_date_update_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**customer_id** | **char \*** | References the customer entity. | [optional] 
**fulfilled_date** | **char \*** | Date actually delivered (set on fulfillment). | [optional] 
**note** | **char \*** |  | [optional] 
**order_number** | **char \*** | Sales order number (&#x60;order.order_number&#x60;). | [optional] 
**original_date** | **char \*** | Original date promised before rescheduling. | [optional] 
**product_id** | **char \*** | Product line item this date applies to, if per-item. References the product entity. | [optional] 
**promised_date** | **char \*** | Date promised to the customer. | [optional] 
**status** | **delivery_date_status_t \*** | One of: promised | confirmed | rescheduled | fulfilled | late | cancelled | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


