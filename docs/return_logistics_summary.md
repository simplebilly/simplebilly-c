# return_logistics_summary_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**by_status** | **any_type_t \*** | Number of return orders per status. | 
**by_warehouse** | [**list_t**](return_warehouse_summary.md) \* | Per-warehouse aggregation. | 
**items_restocked** | **long** | Sum of &#x60;restock: true&#x60; line-item quantities. | 
**items_scrapped** | **long** | Sum of &#x60;restock: false&#x60; line-item quantities (scrapped/disposed). | 
**total_items** | **long** | Sum of all line-item quantities across returns. | 
**total_returns** | **long** | Total number of return orders (excluding soft-deleted). | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


