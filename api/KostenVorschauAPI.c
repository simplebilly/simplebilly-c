#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "KostenVorschauAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


kosten_vorschau_t*
KostenVorschauAPI_kostenVorschauApi(apiClient_t *apiClient, int *year, int *month)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/kosten-vorschau");





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
    //    printf("%s\n","Kosten-Vorschau für den Monat");
    //}
    //nonprimitive not container
    kosten_vorschau_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *KostenVorschauAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = kosten_vorschau_parseFromJSON(KostenVorschauAPIlocalVarJSON);
        cJSON_Delete(KostenVorschauAPIlocalVarJSON);
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

