# service_assignment_update_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**employee_id** | **char \*** | References the employees entity. | [optional] 
**job_id** | **char \*** | References the service_jobs entity. | [optional] 
**notes** | **char \*** |  | [optional] 
**scheduled_date** | **char \*** | Work day the assignment is scheduled for. | [optional] 
**scheduled_end** | **char \*** | Planned end time of the assignment. | [optional] 
**scheduled_start** | **char \*** | Planned start time of the assignment. | [optional] 
**status** | **service_assignment_status_t \*** | Assignment lifecycle status: \&quot;planned\&quot;, \&quot;confirmed\&quot;, \&quot;en_route\&quot;, \&quot;in_progress\&quot;, \&quot;completed\&quot; or \&quot;cancelled\&quot;. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


