# konzern_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**groessenbefreit** | **int** |  | 
**kapitalmarktorientiert** | **int** |  | 
**konzernabschlusspflicht** | **int** |  | 
**missing_group_figures** | **int** | Keine group_figures-Zeile für das Jahr vorhanden → keine Größenbefreiung. | 
**mutterunternehmen** | **int** | Mutterunternehmen: mindestens eine beherrschte Beteiligung (§ 290 Abs. 1 HGB). | 
**parent_name** | **char \*** | Mutterunternehmen für die Zwischenholding-Befreiung (§ 291 HGB). | [optional] 
**parent_situs** | **char \*** |  | [optional] 
**participations** | [**list_t**](konzern_beteiligung.md) \* |  | 
**thresholds** | [**konzern_thresholds_t**](konzern_thresholds.md) \* |  | 
**year** | **int** |  | 
**zwischenholding_befreit** | **int** |  | 
**zwischenholding_hinweis** | **char \*** | Hinweis zu den § 291-Voraussetzungen (EU/EWR-Sitz, geprüfter Konzernabschluss). | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


