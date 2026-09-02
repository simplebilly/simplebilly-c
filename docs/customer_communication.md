# customer_communication_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**body** | **char \*** | The message body, call summary or note text. | [optional] 
**channel** | **communication_channel_t \*** |  | 
**contact_id** | **char \*** | The contact (customer/supplier) this communication belongs to. References the contact entity. | 
**counterparty** | **char \*** | Email/phone of the counterparty, if applicable. | [optional] 
**direction** | **communication_direction_t \*** |  | 
**occurred_at** | **char \*** | When the communication happened (defaults to now on create). | [optional] 
**subject** | **char \*** |  | [optional] 
**tags** | **any_type_t \*** | Free-form tags, e.g. &#x60;[\&quot;follow-up-required\&quot;]&#x60;. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


