# BudgetsAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**BudgetsAPI_budgetsApi**](BudgetsAPI.md#BudgetsAPI_budgetsApi) | **GET** /api/v1/bookkeeping/budgets | 
[**BudgetsAPI_upsertBudgetGoalApi**](BudgetsAPI.md#BudgetsAPI_upsertBudgetGoalApi) | **PUT** /api/v1/bookkeeping/budgets/goals/{category} | 


# **BudgetsAPI_budgetsApi**
```c
budget_ergebnis_t* BudgetsAPI_budgetsApi(apiClient_t *apiClient, int *year, int *month);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**year** | **int \*** |  | 
**month** | **int \*** |  | 

### Return type

[budget_ergebnis_t](budget_ergebnis.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BudgetsAPI_upsertBudgetGoalApi**
```c
budget_t* BudgetsAPI_upsertBudgetGoalApi(apiClient_t *apiClient, char *category, budget_goal_request_t *budget_goal_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**category** | **char \*** |  | 
**budget_goal_request** | **[budget_goal_request_t](budget_goal_request.md) \*** |  | 

### Return type

[budget_t](budget.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

