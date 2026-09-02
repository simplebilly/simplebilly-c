#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "UstvaAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


jahres_ust_ergebnis_t*
UstvaAPI_jahresustApi(apiClient_t *apiClient, int *year)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/jahresust");





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
    //    printf("%s\n","Jahresumsatzsteuer Ergebnis");
    //}
    //nonprimitive not container
    jahres_ust_ergebnis_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *UstvaAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = jahres_ust_ergebnis_parseFromJSON(UstvaAPIlocalVarJSON);
        cJSON_Delete(UstvaAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

ustva_ergebnis_t*
UstvaAPI_ustvaApi(apiClient_t *apiClient, char *zeitraum)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/ustva");





    // query parameters
    char *keyQuery_zeitraum = NULL;
    char * valueQuery_zeitraum = NULL;
    keyValuePair_t *keyPairQuery_zeitraum = 0;
    if (zeitraum)
    {
        keyQuery_zeitraum = strdup("zeitraum");
        valueQuery_zeitraum = strdup((zeitraum));
        keyPairQuery_zeitraum = keyValuePair_create(keyQuery_zeitraum, valueQuery_zeitraum);
        list_addElement(localVarQueryParameters,keyPairQuery_zeitraum);
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
    //    printf("%s\n","UStVA Ergebnis");
    //}
    //nonprimitive not container
    ustva_ergebnis_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *UstvaAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = ustva_ergebnis_parseFromJSON(UstvaAPIlocalVarJSON);
        cJSON_Delete(UstvaAPIlocalVarJSON);
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
    if(keyQuery_zeitraum){
        free(keyQuery_zeitraum);
        keyQuery_zeitraum = NULL;
    }
    if(valueQuery_zeitraum){
        free(valueQuery_zeitraum);
        valueQuery_zeitraum = NULL;
    }
    if(keyPairQuery_zeitraum){
        keyValuePair_free(keyPairQuery_zeitraum);
        keyPairQuery_zeitraum = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

