#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "KstAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


kst_ergebnis_t*
KstAPI_kstApi(apiClient_t *apiClient, int *year, char *gewinn)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/kst");





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
    char *keyQuery_gewinn = NULL;
    char * valueQuery_gewinn = NULL;
    keyValuePair_t *keyPairQuery_gewinn = 0;
    if (gewinn)
    {
        keyQuery_gewinn = strdup("gewinn");
        valueQuery_gewinn = strdup((gewinn));
        keyPairQuery_gewinn = keyValuePair_create(keyQuery_gewinn, valueQuery_gewinn);
        list_addElement(localVarQueryParameters,keyPairQuery_gewinn);
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
    //    printf("%s\n","Körperschaftsteuer Ergebnis");
    //}
    //nonprimitive not container
    kst_ergebnis_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *KstAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = kst_ergebnis_parseFromJSON(KstAPIlocalVarJSON);
        cJSON_Delete(KstAPIlocalVarJSON);
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
    if(keyQuery_gewinn){
        free(keyQuery_gewinn);
        keyQuery_gewinn = NULL;
    }
    if(valueQuery_gewinn){
        free(valueQuery_gewinn);
        valueQuery_gewinn = NULL;
    }
    if(keyPairQuery_gewinn){
        keyValuePair_free(keyPairQuery_gewinn);
        keyPairQuery_gewinn = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

