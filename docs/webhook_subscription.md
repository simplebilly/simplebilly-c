# webhook_subscription_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**event_type** | **char \*** | Event type to react to (e.g. \&quot;order.created\&quot;); \&quot;*\&quot; &#x3D; all events. | 
**is_active** | **int** |  | [optional] 
**name** | **char \*** | Human label (e.g. \&quot;Warehouse app\&quot;). | 
**secret** | **char \*** | Shared secret for HMAC-SHA256 signature, sent as X-Signature. | 
**url** | **char \*** |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


