# activity_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**activity_type** | **activity_type_t \*** | One of: call | email | meeting | task | note | 
**assigned_to** | **char \*** | User responsible (&#x60;employee.employee_id&#x60;). | [optional] 
**contact_id** | **char \*** | Contact this activity belongs to (&#x60;contact.contact_id&#x60;). References the contact entity. | [optional] 
**description** | **char \*** |  | [optional] 
**due_date** | **char \*** | Follow-up / Wiedervorlage date. Open activities with a due date in the past are overdue. | [optional] 
**reminder_date** | **char \*** | When to remind about the follow-up. | [optional] 
**status** | **activity_status_t \*** | One of: open | done | cancelled | 
**subject** | **char \*** | Short subject line. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


