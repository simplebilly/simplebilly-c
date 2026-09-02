#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "GezAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


gez_report_t*
GezAPI_gezApi(apiClient_t *apiClient, int *jahr, char *betriebsstaetten, long kfz, long hotelzimmer, long beschaefigte)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/gez");





    // query parameters
    char *keyQuery_jahr = NULL;
    char * valueQuery_jahr = NULL;
    keyValuePair_t *keyPairQuery_jahr = 0;
    if (jahr)
    {
        keyQuery_jahr = strdup("jahr");
        valueQuery_jahr = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_jahr, MAX_NUMBER_LENGTH, "%d", *jahr);
        keyPairQuery_jahr = keyValuePair_create(keyQuery_jahr, valueQuery_jahr);
        list_addElement(localVarQueryParameters,keyPairQuery_jahr);
    }

    // query parameters
    char *keyQuery_betriebsstaetten = NULL;
    char * valueQuery_betriebsstaetten = NULL;
    keyValuePair_t *keyPairQuery_betriebsstaetten = 0;
    if (betriebsstaetten)
    {
        keyQuery_betriebsstaetten = strdup("betriebsstaetten");
        valueQuery_betriebsstaetten = strdup((betriebsstaetten));
        keyPairQuery_betriebsstaetten = keyValuePair_create(keyQuery_betriebsstaetten, valueQuery_betriebsstaetten);
        list_addElement(localVarQueryParameters,keyPairQuery_betriebsstaetten);
    }

    // query parameters
    char *keyQuery_kfz = NULL;
    char * valueQuery_kfz ;
    keyValuePair_t *keyPairQuery_kfz = 0;
    {
        keyQuery_kfz = strdup("kfz");
        valueQuery_kfz = calloc(1,MAX_NUMBER_LENGTH_LONG);
        snprintf(valueQuery_kfz, MAX_NUMBER_LENGTH_LONG, "%d", kfz);
        keyPairQuery_kfz = keyValuePair_create(keyQuery_kfz, valueQuery_kfz);
        list_addElement(localVarQueryParameters,keyPairQuery_kfz);
    }

    // query parameters
    char *keyQuery_hotelzimmer = NULL;
    char * valueQuery_hotelzimmer ;
    keyValuePair_t *keyPairQuery_hotelzimmer = 0;
    {
        keyQuery_hotelzimmer = strdup("hotelzimmer");
        valueQuery_hotelzimmer = calloc(1,MAX_NUMBER_LENGTH_LONG);
        snprintf(valueQuery_hotelzimmer, MAX_NUMBER_LENGTH_LONG, "%d", hotelzimmer);
        keyPairQuery_hotelzimmer = keyValuePair_create(keyQuery_hotelzimmer, valueQuery_hotelzimmer);
        list_addElement(localVarQueryParameters,keyPairQuery_hotelzimmer);
    }

    // query parameters
    char *keyQuery_beschaefigte = NULL;
    char * valueQuery_beschaefigte ;
    keyValuePair_t *keyPairQuery_beschaefigte = 0;
    {
        keyQuery_beschaefigte = strdup("beschaefigte");
        valueQuery_beschaefigte = calloc(1,MAX_NUMBER_LENGTH_LONG);
        snprintf(valueQuery_beschaefigte, MAX_NUMBER_LENGTH_LONG, "%d", beschaefigte);
        keyPairQuery_beschaefigte = keyValuePair_create(keyQuery_beschaefigte, valueQuery_beschaefigte);
        list_addElement(localVarQueryParameters,keyPairQuery_beschaefigte);
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
    //    printf("%s\n","Rundfunkbeitrag (GEZ) Berechnung nach § 5 RBStV");
    //}
    //nonprimitive not container
    gez_report_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *GezAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = gez_report_parseFromJSON(GezAPIlocalVarJSON);
        cJSON_Delete(GezAPIlocalVarJSON);
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
    if(keyQuery_jahr){
        free(keyQuery_jahr);
        keyQuery_jahr = NULL;
    }
    if(valueQuery_jahr){
        free(valueQuery_jahr);
        valueQuery_jahr = NULL;
    }
    if(keyPairQuery_jahr){
        keyValuePair_free(keyPairQuery_jahr);
        keyPairQuery_jahr = NULL;
    }
    if(keyQuery_betriebsstaetten){
        free(keyQuery_betriebsstaetten);
        keyQuery_betriebsstaetten = NULL;
    }
    if(valueQuery_betriebsstaetten){
        free(valueQuery_betriebsstaetten);
        valueQuery_betriebsstaetten = NULL;
    }
    if(keyPairQuery_betriebsstaetten){
        keyValuePair_free(keyPairQuery_betriebsstaetten);
        keyPairQuery_betriebsstaetten = NULL;
    }
    if(keyQuery_kfz){
        free(keyQuery_kfz);
        keyQuery_kfz = NULL;
    }
    if(keyPairQuery_kfz){
        keyValuePair_free(keyPairQuery_kfz);
        keyPairQuery_kfz = NULL;
    }
    if(keyQuery_hotelzimmer){
        free(keyQuery_hotelzimmer);
        keyQuery_hotelzimmer = NULL;
    }
    if(keyPairQuery_hotelzimmer){
        keyValuePair_free(keyPairQuery_hotelzimmer);
        keyPairQuery_hotelzimmer = NULL;
    }
    if(keyQuery_beschaefigte){
        free(keyQuery_beschaefigte);
        keyQuery_beschaefigte = NULL;
    }
    if(keyPairQuery_beschaefigte){
        keyValuePair_free(keyPairQuery_beschaefigte);
        keyPairQuery_beschaefigte = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

