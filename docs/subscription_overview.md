# subscription_overview_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**current_period_end** | **char \*** |  | [optional] 
**features** | [**plan_features_t**](plan_features.md) \* |  | 
**is_trialing** | **int** |  | 
**limits** | [**plan_limits_t**](plan_limits.md) \* |  | 
**manage_url** | **char \*** |  | [optional] 
**plan** | **char \*** | Resolved plan id (free/starter/business/enterprise, or a custom override id). | 
**plan_name** | **char \*** |  | 
**price_eur** | **double** | Monthly price in EUR; &#x60;-1.0&#x60; &#x3D; custom pricing (enterprise). | 
**quantity** | **int** |  | [optional] 
**status** | **char \*** |  | [optional] 
**subscription_id** | **char \*** |  | [optional] 
**trial_ends_at** | **char \*** |  | [optional] 
**usage** | [**usage_snapshot_t**](usage_snapshot.md) \* |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


