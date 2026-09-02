# job_application_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**cv_file** | **char \*** | Relative path of the stored CV file under the upload dir. | [optional] 
**cv_text** | **char \*** | Extracted CV text, used for match-scoring. | [optional] 
**email** | **char \*** |  | [optional] 
**match_reason** | **char \*** |  | [optional] 
**match_score** | **int** | 0-100 LLM match score against the posting&#39;s required profile. | [optional] 
**name** | **char \*** |  | [optional] 
**phone** | **char \*** |  | [optional] 
**posting_id** | **char \*** | References the job_posting entity. | [optional] 
**source** | **char \*** | website | email | board | 
**status** | **application_status_t \*** | new | reviewing | interview | hired | rejected | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


