#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "BudgetsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


budget_ergebnis_t*
BudgetsAPI_budgetsApi(apiClient_t *apiClient, int *year, int *month)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/bookkeeping/budgets");





    // query parameters
    char *keyQuery_year = NULL;
    char * valueQuery_year = NULL;
    keyValuePair_t *keyPairQuery_year = 0;
    if (year)
    {
        keyQuery_year = strdup("year");
        valueQuery_year = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_year, MAX_NUMBER_LENGTH, "%d", *year);
        keyPairQuery_year = keyValuePair_create(keyQuery_year, valueQuery_year);
        list_addElement(localVarQueryParameters,keyPairQuery_year);
    }

    // query parameters
    char *keyQuery_month = NULL;
    char * valueQuery_month = NULL;
    keyValuePair_t *keyPairQuery_month = 0;
    if (month)
    {
        keyQuery_month = strdup("month");
        valueQuery_month = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_month, MAX_NUMBER_LENGTH, "%d", *month);
        keyPairQuery_month = keyValuePair_create(keyQuery_month, valueQuery_month);
        list_addElement(localVarQueryParameters,keyPairQuery_month);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Monats-Budget + Prognose");
    //}
    //nonprimitive not container
    budget_ergebnis_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *BudgetsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = budget_ergebnis_parseFromJSON(BudgetsAPIlocalVarJSON);
        cJSON_Delete(BudgetsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_year){
        free(keyQuery_year);
        keyQuery_year = NULL;
    }
    if(valueQuery_year){
        free(valueQuery_year);
        valueQuery_year = NULL;
    }
    if(keyPairQuery_year){
        keyValuePair_free(keyPairQuery_year);
        keyPairQuery_year = NULL;
    }
    if(keyQuery_month){
        free(keyQuery_month);
        keyQuery_month = NULL;
    }
    if(valueQuery_month){
        free(valueQuery_month);
        valueQuery_month = NULL;
    }
    if(keyPairQuery_month){
        keyValuePair_free(keyPairQuery_month);
        keyPairQuery_month = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

budget_t*
BudgetsAPI_upsertBudgetGoalApi(apiClient_t *apiClient, char *category, budget_goal_request_t *budget_goal_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/bookkeeping/budgets/goals/{category}");

    if(!category)
        goto end;


    // Path Params
    long sizeOfPathParams_category = strlen(category)+3 + sizeof("{ category }") - 1;
    if(category == NULL) {
        goto end;
    }
    char* localVarToReplace_category = malloc(sizeOfPathParams_category);
    sprintf(localVarToReplace_category, "{%s}", "category");

    localVarPath = strReplace(localVarPath, localVarToReplace_category, category);



    // Body Param
    cJSON *localVarSingleItemJSON_budget_goal_request = NULL;
    if (budget_goal_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_budget_goal_request = budget_goal_request_convertToJSON(budget_goal_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_budget_goal_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Budget goal saved (upsert)");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Negative goal");
    //}
    //nonprimitive not container
    budget_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *BudgetsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = budget_parseFromJSON(BudgetsAPIlocalVarJSON);
        cJSON_Delete(BudgetsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_category);
    if (localVarSingleItemJSON_budget_goal_request) {
        cJSON_Delete(localVarSingleItemJSON_budget_goal_request);
        localVarSingleItemJSON_budget_goal_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

