#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "GewerbesteuerAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


gewerbesteuer_ergebnis_t*
GewerbesteuerAPI_gewerbesteuerApi(apiClient_t *apiClient, int *year, char *hebesatz, char *gewerbeertrag, char *country, char *gemeindeschluessel)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/gewerbesteuer");





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
    char *keyQuery_hebesatz = NULL;
    char * valueQuery_hebesatz = NULL;
    keyValuePair_t *keyPairQuery_hebesatz = 0;
    if (hebesatz)
    {
        keyQuery_hebesatz = strdup("hebesatz");
        valueQuery_hebesatz = strdup((hebesatz));
        keyPairQuery_hebesatz = keyValuePair_create(keyQuery_hebesatz, valueQuery_hebesatz);
        list_addElement(localVarQueryParameters,keyPairQuery_hebesatz);
    }

    // query parameters
    char *keyQuery_gewerbeertrag = NULL;
    char * valueQuery_gewerbeertrag = NULL;
    keyValuePair_t *keyPairQuery_gewerbeertrag = 0;
    if (gewerbeertrag)
    {
        keyQuery_gewerbeertrag = strdup("gewerbeertrag");
        valueQuery_gewerbeertrag = strdup((gewerbeertrag));
        keyPairQuery_gewerbeertrag = keyValuePair_create(keyQuery_gewerbeertrag, valueQuery_gewerbeertrag);
        list_addElement(localVarQueryParameters,keyPairQuery_gewerbeertrag);
    }

    // query parameters
    char *keyQuery_country = NULL;
    char * valueQuery_country = NULL;
    keyValuePair_t *keyPairQuery_country = 0;
    if (country)
    {
        keyQuery_country = strdup("country");
        valueQuery_country = strdup((country));
        keyPairQuery_country = keyValuePair_create(keyQuery_country, valueQuery_country);
        list_addElement(localVarQueryParameters,keyPairQuery_country);
    }

    // query parameters
    char *keyQuery_gemeindeschluessel = NULL;
    char * valueQuery_gemeindeschluessel = NULL;
    keyValuePair_t *keyPairQuery_gemeindeschluessel = 0;
    if (gemeindeschluessel)
    {
        keyQuery_gemeindeschluessel = strdup("gemeindeschluessel");
        valueQuery_gemeindeschluessel = strdup((gemeindeschluessel));
        keyPairQuery_gemeindeschluessel = keyValuePair_create(keyQuery_gemeindeschluessel, valueQuery_gemeindeschluessel);
        list_addElement(localVarQueryParameters,keyPairQuery_gemeindeschluessel);
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
    //    printf("%s\n","Gewerbesteuer / Trade Tax Ergebnis");
    //}
    //nonprimitive not container
    gewerbesteuer_ergebnis_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *GewerbesteuerAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = gewerbesteuer_ergebnis_parseFromJSON(GewerbesteuerAPIlocalVarJSON);
        cJSON_Delete(GewerbesteuerAPIlocalVarJSON);
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
    if(keyQuery_hebesatz){
        free(keyQuery_hebesatz);
        keyQuery_hebesatz = NULL;
    }
    if(valueQuery_hebesatz){
        free(valueQuery_hebesatz);
        valueQuery_hebesatz = NULL;
    }
    if(keyPairQuery_hebesatz){
        keyValuePair_free(keyPairQuery_hebesatz);
        keyPairQuery_hebesatz = NULL;
    }
    if(keyQuery_gewerbeertrag){
        free(keyQuery_gewerbeertrag);
        keyQuery_gewerbeertrag = NULL;
    }
    if(valueQuery_gewerbeertrag){
        free(valueQuery_gewerbeertrag);
        valueQuery_gewerbeertrag = NULL;
    }
    if(keyPairQuery_gewerbeertrag){
        keyValuePair_free(keyPairQuery_gewerbeertrag);
        keyPairQuery_gewerbeertrag = NULL;
    }
    if(keyQuery_country){
        free(keyQuery_country);
        keyQuery_country = NULL;
    }
    if(valueQuery_country){
        free(valueQuery_country);
        valueQuery_country = NULL;
    }
    if(keyPairQuery_country){
        keyValuePair_free(keyPairQuery_country);
        keyPairQuery_country = NULL;
    }
    if(keyQuery_gemeindeschluessel){
        free(keyQuery_gemeindeschluessel);
        keyQuery_gemeindeschluessel = NULL;
    }
    if(valueQuery_gemeindeschluessel){
        free(valueQuery_gemeindeschluessel);
        valueQuery_gemeindeschluessel = NULL;
    }
    if(keyPairQuery_gemeindeschluessel){
        keyValuePair_free(keyPairQuery_gemeindeschluessel);
        keyPairQuery_gemeindeschluessel = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

