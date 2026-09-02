# emission_entry_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**activity_value** | **char \*** | Activity amount in &#x60;unit&#x60; (kWh, l, km, t, tkm, EUR). | 
**category_id** | **char \*** | GHG-Protocol category key, e.g. \&quot;purchased_goods\&quot;, \&quot;business_travel\&quot;. | 
**description** | **char \*** |  | 
**ef_source** | **char \*** | Emission-factor source, e.g. \&quot;UBA-2024\&quot;, \&quot;DEFRA-2024\&quot;. | 
**ef_version** | **char \*** |  | 
**method** | **emission_method_t \*** | \&quot;activity\&quot; | \&quot;spend\&quot; | \&quot;supplier\&quot;. | 
**scope** | **ghg_scope_t \*** | GHG scope: \&quot;1\&quot; | \&quot;2\&quot; | \&quot;3\&quot;. | 
**tco2e** | **char \*** | Computed server-side: activity * factor / 1000, rounded to 4 dp. | 
**unit** | **char \*** | Unit of the activity value. | 
**updated_at** | **char \*** |  | [optional] 
**year** | **int** | Reporting year. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


