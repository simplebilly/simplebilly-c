# employee_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**address** | **char \*** |  | [optional] 
**backup_employee_id** | **char \*** | References another employee who covers when this employee is absent. | [optional] 
**bic** | **char \*** |  | [optional] 
**city** | **char \*** |  | [optional] 
**country** | **country_code_t \*** |  | [optional] 
**created_at** | **char \*** |  | [optional] 
**date_of_birth** | **char \*** |  | [optional] 
**deleted_at** | **char \*** |  | [optional] 
**department_id** | **char \*** | References the department entity. | [optional] 
**email** | **char \*** |  | [optional] 
**first_name** | **char \*** |  | [optional] 
**gender** | **gender_t \*** | Gender for pay-transparency reporting: \&quot;male\&quot;, \&quot;female\&quot; or \&quot;diverse\&quot;. | [optional] 
**hire_date** | **char \*** |  | [optional] 
**hourly_cost** | **char \*** | Hourly cost rate in EUR for labor-cost reporting; when unset the rate is derived from &#x60;monthly_salary / (weekly_hours * 4.33)&#x60;. | [optional] 
**iban** | **char \*** |  | [optional] 
**id** | **char \*** |  | [optional] 
**job_title** | **char \*** |  | [optional] 
**last_login** | **char \*** |  | [optional] 
**last_name** | **char \*** |  | [optional] 
**last_updated** | **char \*** |  | [optional] 
**monthly_salary** | **char \*** | Gross monthly salary in EUR for pay-transparency reporting. | [optional] 
**phone** | **char \*** |  | [optional] 
**state** | **char \*** |  | [optional] 
**status** | **employee_status_t \*** |  | [optional] 
**tenant_id** | **char \*** |  | [optional] 
**updated_at** | **char \*** |  | [optional] 
**user_id** | **char \*** | References the user entity. | [optional] 
**weekly_hours** | **char \*** | Contractual weekly working hours for pay-transparency normalization. | [optional] 
**zip** | **char \*** |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


