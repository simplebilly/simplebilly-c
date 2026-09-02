# rfq_update_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**currency** | **char \*** |  | [optional] 
**line_items** | **any_type_t \*** | JSON array of &#x60;{product_id, name, sku, quantity, requested_unit_price?, quoted_unit_price?}&#x60;. | [optional] 
**notes** | **char \*** |  | [optional] 
**requested_date** | **char \*** |  | [optional] 
**response_date** | **char \*** |  | [optional] 
**rfq_number** | **char \*** |  | [optional] 
**status** | **rfq_status_t \*** | One of: draft | sent | offer_received | rejected | converted | [optional] 
**supplier_contact_id** | **char \*** | References the supplier entity. | [optional] 
**supplier_name** | **char \*** |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


