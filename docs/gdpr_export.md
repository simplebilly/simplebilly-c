# gdpr_export_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**activity_log** | [**list_t**](gdpr_activity.md) \* |  | 
**api_keys** | [**list_t**](gdpr_api_key.md) \* | Key identifiers and names only — never a usable credential. | 
**billing** | [**list_t**](gdpr_billing_info.md) \* |  | 
**exported_at** | **char \*** |  | 
**generated_by_ai** | **int** | Honesty field: this document is a plain data dump, never AI-generated. | 
**notifications** | [**list_t**](gdpr_notification.md) \* |  | 
**refresh_tokens** | [**list_t**](gdpr_refresh_token.md) \* | Session records: metadata only, never the token hash. | 
**tenants** | [**list_t**](gdpr_tenant.md) \* |  | 
**usage_events** | [**list_t**](gdpr_usage_event.md) \* |  | 
**user** | [**gdpr_user_t**](gdpr_user.md) \* |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


