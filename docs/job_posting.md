# job_posting_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**currency** | **char \*** |  | [optional] 
**department** | **char \*** |  | [optional] 
**description** | **char \*** | What the job is; markdown/HTML. | 
**employment_type** | **employment_type_t \*** | full_time | part_time | contract | internship | temporary | [optional] 
**location** | **char \*** |  | [optional] 
**remote** | **int** |  | 
**required_skills** | **any_type_t \*** | List of required skill names (JSON array of strings). | 
**requirements** | **char \*** | Structured profile of the required candidate (skills, experience). | [optional] 
**salary_max** | **int** |  | [optional] 
**salary_min** | **int** |  | [optional] 
**status** | **job_posting_status_t \*** | draft | published | closed | 
**title** | **char \*** |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


