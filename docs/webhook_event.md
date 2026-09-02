# webhook_event_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**attempts** | **int** |  | [optional] 
**channel** | **char \*** | source for inbound, target URL for outbound. | [optional] 
**direction** | **webhook_direction_t \*** | inbound | outbound | 
**event_type** | **char \*** |  | 
**last_error** | **char \*** |  | [optional] 
**payload** | **any_type_t \*** |  | [optional] 
**status** | **webhook_event_status_t \*** | accepted | delivered | failed | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


