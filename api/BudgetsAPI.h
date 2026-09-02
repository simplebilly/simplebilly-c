#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/budget.h"
#include "../model/budget_ergebnis.h"
#include "../model/budget_goal_request.h"
#include "../model/plugin_error.h"


budget_ergebnis_t*
BudgetsAPI_budgetsApi(apiClient_t *apiClient, int *year, int *month);


budget_t*
BudgetsAPI_upsertBudgetGoalApi(apiClient_t *apiClient, char *category, budget_goal_request_t *budget_goal_request);


