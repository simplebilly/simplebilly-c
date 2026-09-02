# job_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**attempts** | **int** |  | [optional] 
**job_type** | **char \*** | Discriminator the worker dispatches on (e.g. \&quot;webhook.deliver\&quot;). | 
**max_attempts** | **int** |  | 
**payload** | **any_type_t \*** |  | [optional] 
**run_at** | **char \*** | Earliest execution time; None &#x3D; run now. | [optional] 
**status** | **job_status_t \*** | pending | running | done | failed | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


