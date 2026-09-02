#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ListOpenItemsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


list_t*
ListOpenItemsAPI_listOpenItemsApi(apiClient_t *apiClient, long reminder_level1_days, long reminder_level2_days, long reminder_level3_days, char *customer_id)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/open-items");





    // query parameters
    char *keyQuery_reminder_level1_days = NULL;
    char * valueQuery_reminder_level1_days ;
    keyValuePair_t *keyPairQuery_reminder_level1_days = 0;
    {
        keyQuery_reminder_level1_days = strdup("reminder_level1_days");
        valueQuery_reminder_level1_days = calloc(1,MAX_NUMBER_LENGTH_LONG);
        snprintf(valueQuery_reminder_level1_days, MAX_NUMBER_LENGTH_LONG, "%d", reminder_level1_days);
        keyPairQuery_reminder_level1_days = keyValuePair_create(keyQuery_reminder_level1_days, valueQuery_reminder_level1_days);
        list_addElement(localVarQueryParameters,keyPairQuery_reminder_level1_days);
    }

    // query parameters
    char *keyQuery_reminder_level2_days = NULL;
    char * valueQuery_reminder_level2_days ;
    keyValuePair_t *keyPairQuery_reminder_level2_days = 0;
    {
        keyQuery_reminder_level2_days = strdup("reminder_level2_days");
        valueQuery_reminder_level2_days = calloc(1,MAX_NUMBER_LENGTH_LONG);
        snprintf(valueQuery_reminder_level2_days, MAX_NUMBER_LENGTH_LONG, "%d", reminder_level2_days);
        keyPairQuery_reminder_level2_days = keyValuePair_create(keyQuery_reminder_level2_days, valueQuery_reminder_level2_days);
        list_addElement(localVarQueryParameters,keyPairQuery_reminder_level2_days);
    }

    // query parameters
    char *keyQuery_reminder_level3_days = NULL;
    char * valueQuery_reminder_level3_days ;
    keyValuePair_t *keyPairQuery_reminder_level3_days = 0;
    {
        keyQuery_reminder_level3_days = strdup("reminder_level3_days");
        valueQuery_reminder_level3_days = calloc(1,MAX_NUMBER_LENGTH_LONG);
        snprintf(valueQuery_reminder_level3_days, MAX_NUMBER_LENGTH_LONG, "%d", reminder_level3_days);
        keyPairQuery_reminder_level3_days = keyValuePair_create(keyQuery_reminder_level3_days, valueQuery_reminder_level3_days);
        list_addElement(localVarQueryParameters,keyPairQuery_reminder_level3_days);
    }

    // query parameters
    char *keyQuery_customer_id = NULL;
    char * valueQuery_customer_id = NULL;
    keyValuePair_t *keyPairQuery_customer_id = 0;
    if (customer_id)
    {
        keyQuery_customer_id = strdup("customer_id");
        valueQuery_customer_id = strdup((customer_id));
        keyPairQuery_customer_id = keyValuePair_create(keyQuery_customer_id, valueQuery_customer_id);
        list_addElement(localVarQueryParameters,keyPairQuery_customer_id);
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
    //    printf("%s\n","List of open invoices");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ListOpenItemsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ListOpenItemsAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ListOpenItemsAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ListOpenItemsAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
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
    if(keyQuery_reminder_level1_days){
        free(keyQuery_reminder_level1_days);
        keyQuery_reminder_level1_days = NULL;
    }
    if(keyPairQuery_reminder_level1_days){
        keyValuePair_free(keyPairQuery_reminder_level1_days);
        keyPairQuery_reminder_level1_days = NULL;
    }
    if(keyQuery_reminder_level2_days){
        free(keyQuery_reminder_level2_days);
        keyQuery_reminder_level2_days = NULL;
    }
    if(keyPairQuery_reminder_level2_days){
        keyValuePair_free(keyPairQuery_reminder_level2_days);
        keyPairQuery_reminder_level2_days = NULL;
    }
    if(keyQuery_reminder_level3_days){
        free(keyQuery_reminder_level3_days);
        keyQuery_reminder_level3_days = NULL;
    }
    if(keyPairQuery_reminder_level3_days){
        keyValuePair_free(keyPairQuery_reminder_level3_days);
        keyPairQuery_reminder_level3_days = NULL;
    }
    if(keyQuery_customer_id){
        free(keyQuery_customer_id);
        keyQuery_customer_id = NULL;
    }
    if(valueQuery_customer_id){
        free(valueQuery_customer_id);
        valueQuery_customer_id = NULL;
    }
    if(keyPairQuery_customer_id){
        keyValuePair_free(keyPairQuery_customer_id);
        keyPairQuery_customer_id = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

