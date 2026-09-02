# bom_create_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**components** | **any_type_t \*** | JSON array of &#x60;{product_id, name, quantity, unit, scrap_rate}&#x60;. | [optional] 
**description** | **char \*** |  | [optional] 
**name** | **char \*** |  | 
**output_quantity** | **long** | Output quantity per production run (defaults to 1). | [optional] 
**product_id** | **char \*** | The finished product this BOM produces. References the product entity. | 
**status** | **bom_status_t \*** | One of: draft | active | archived | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


