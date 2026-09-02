# emissions_report_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**by_category** | [**list_t**](category_total.md) \* |  | 
**by_scope** | [**list_t**](scope_total.md) \* |  | 
**by_year** | [**list_t**](year_total.md) \* |  | 
**data_quality** | [**data_quality_t**](data_quality.md) \* |  | 
**intensity_per_employee** | **double** |  | [optional] 
**intensity_per_revenue_mio** | **double** | tCO2e per million EUR net revenue. | [optional] 
**net_revenue** | **double** | Sum of paid/sent/partially-paid invoices (EUR net) in the year. | [optional] 
**spend_based_estimate_tco2e** | **double** | Spend-based estimate from bookkeeping payments (EXIOBASE factor). | [optional] 
**targets** | [**list_t**](target_progress.md) \* |  | 
**total_tco2e** | **char \*** |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


