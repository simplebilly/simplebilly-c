# import_job_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**error** | **char \*** | Set only when the job failed. | [optional] 
**job_id** | **char \*** |  | 
**processed** | **long** |  | 
**progress** | **int** | 0–100 | 
**provider** | **char \*** | Which competitor the import came from (lexoffice | billbee); the frontend uses it to label the job. Absent for legacy jobs. | [optional] 
**stage** | **char \*** | queued | fetching | downloading | importing | done | 
**status** | **char \*** | pending | running | done | failed | 
**total** | **long** |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


