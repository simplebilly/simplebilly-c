#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "FristenAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


fristen_ergebnis_t*
FristenAPI_fristenApi(apiClient_t *apiClient, char *bundesland, char *voranmeldungsrhythmus, int *dauerfristverlaengerung, int *est_aktiv, int *gewst_aktiv, int *monate)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/fristen");





    // query parameters
    char *keyQuery_bundesland = NULL;
    char * valueQuery_bundesland = NULL;
    keyValuePair_t *keyPairQuery_bundesland = 0;
    if (bundesland)
    {
        keyQuery_bundesland = strdup("bundesland");
        valueQuery_bundesland = strdup((bundesland));
        keyPairQuery_bundesland = keyValuePair_create(keyQuery_bundesland, valueQuery_bundesland);
        list_addElement(localVarQueryParameters,keyPairQuery_bundesland);
    }

    // query parameters
    char *keyQuery_voranmeldungsrhythmus = NULL;
    char * valueQuery_voranmeldungsrhythmus = NULL;
    keyValuePair_t *keyPairQuery_voranmeldungsrhythmus = 0;
    if (voranmeldungsrhythmus)
    {
        keyQuery_voranmeldungsrhythmus = strdup("voranmeldungsrhythmus");
        valueQuery_voranmeldungsrhythmus = strdup((voranmeldungsrhythmus));
        keyPairQuery_voranmeldungsrhythmus = keyValuePair_create(keyQuery_voranmeldungsrhythmus, valueQuery_voranmeldungsrhythmus);
        list_addElement(localVarQueryParameters,keyPairQuery_voranmeldungsrhythmus);
    }

    // query parameters
    char *keyQuery_dauerfristverlaengerung = NULL;
    char * valueQuery_dauerfristverlaengerung = NULL;
    keyValuePair_t *keyPairQuery_dauerfristverlaengerung = 0;
    if (dauerfristverlaengerung)
    {
        keyQuery_dauerfristverlaengerung = strdup("dauerfristverlaengerung");
        valueQuery_dauerfristverlaengerung = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_dauerfristverlaengerung, MAX_NUMBER_LENGTH, "%d", *dauerfristverlaengerung);
        keyPairQuery_dauerfristverlaengerung = keyValuePair_create(keyQuery_dauerfristverlaengerung, valueQuery_dauerfristverlaengerung);
        list_addElement(localVarQueryParameters,keyPairQuery_dauerfristverlaengerung);
    }

    // query parameters
    char *keyQuery_est_aktiv = NULL;
    char * valueQuery_est_aktiv = NULL;
    keyValuePair_t *keyPairQuery_est_aktiv = 0;
    if (est_aktiv)
    {
        keyQuery_est_aktiv = strdup("est_aktiv");
        valueQuery_est_aktiv = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_est_aktiv, MAX_NUMBER_LENGTH, "%d", *est_aktiv);
        keyPairQuery_est_aktiv = keyValuePair_create(keyQuery_est_aktiv, valueQuery_est_aktiv);
        list_addElement(localVarQueryParameters,keyPairQuery_est_aktiv);
    }

    // query parameters
    char *keyQuery_gewst_aktiv = NULL;
    char * valueQuery_gewst_aktiv = NULL;
    keyValuePair_t *keyPairQuery_gewst_aktiv = 0;
    if (gewst_aktiv)
    {
        keyQuery_gewst_aktiv = strdup("gewst_aktiv");
        valueQuery_gewst_aktiv = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gewst_aktiv, MAX_NUMBER_LENGTH, "%d", *gewst_aktiv);
        keyPairQuery_gewst_aktiv = keyValuePair_create(keyQuery_gewst_aktiv, valueQuery_gewst_aktiv);
        list_addElement(localVarQueryParameters,keyPairQuery_gewst_aktiv);
    }

    // query parameters
    char *keyQuery_monate = NULL;
    char * valueQuery_monate = NULL;
    keyValuePair_t *keyPairQuery_monate = 0;
    if (monate)
    {
        keyQuery_monate = strdup("monate");
        valueQuery_monate = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_monate, MAX_NUMBER_LENGTH, "%d", *monate);
        keyPairQuery_monate = keyValuePair_create(keyQuery_monate, valueQuery_monate);
        list_addElement(localVarQueryParameters,keyPairQuery_monate);
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
    //    printf("%s\n","Steuerliche Fristen");
    //}
    //nonprimitive not container
    fristen_ergebnis_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FristenAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = fristen_ergebnis_parseFromJSON(FristenAPIlocalVarJSON);
        cJSON_Delete(FristenAPIlocalVarJSON);
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
    if(keyQuery_bundesland){
        free(keyQuery_bundesland);
        keyQuery_bundesland = NULL;
    }
    if(valueQuery_bundesland){
        free(valueQuery_bundesland);
        valueQuery_bundesland = NULL;
    }
    if(keyPairQuery_bundesland){
        keyValuePair_free(keyPairQuery_bundesland);
        keyPairQuery_bundesland = NULL;
    }
    if(keyQuery_voranmeldungsrhythmus){
        free(keyQuery_voranmeldungsrhythmus);
        keyQuery_voranmeldungsrhythmus = NULL;
    }
    if(valueQuery_voranmeldungsrhythmus){
        free(valueQuery_voranmeldungsrhythmus);
        valueQuery_voranmeldungsrhythmus = NULL;
    }
    if(keyPairQuery_voranmeldungsrhythmus){
        keyValuePair_free(keyPairQuery_voranmeldungsrhythmus);
        keyPairQuery_voranmeldungsrhythmus = NULL;
    }
    if(keyQuery_dauerfristverlaengerung){
        free(keyQuery_dauerfristverlaengerung);
        keyQuery_dauerfristverlaengerung = NULL;
    }
    if(valueQuery_dauerfristverlaengerung){
        free(valueQuery_dauerfristverlaengerung);
        valueQuery_dauerfristverlaengerung = NULL;
    }
    if(keyPairQuery_dauerfristverlaengerung){
        keyValuePair_free(keyPairQuery_dauerfristverlaengerung);
        keyPairQuery_dauerfristverlaengerung = NULL;
    }
    if(keyQuery_est_aktiv){
        free(keyQuery_est_aktiv);
        keyQuery_est_aktiv = NULL;
    }
    if(valueQuery_est_aktiv){
        free(valueQuery_est_aktiv);
        valueQuery_est_aktiv = NULL;
    }
    if(keyPairQuery_est_aktiv){
        keyValuePair_free(keyPairQuery_est_aktiv);
        keyPairQuery_est_aktiv = NULL;
    }
    if(keyQuery_gewst_aktiv){
        free(keyQuery_gewst_aktiv);
        keyQuery_gewst_aktiv = NULL;
    }
    if(valueQuery_gewst_aktiv){
        free(valueQuery_gewst_aktiv);
        valueQuery_gewst_aktiv = NULL;
    }
    if(keyPairQuery_gewst_aktiv){
        keyValuePair_free(keyPairQuery_gewst_aktiv);
        keyPairQuery_gewst_aktiv = NULL;
    }
    if(keyQuery_monate){
        free(keyQuery_monate);
        keyQuery_monate = NULL;
    }
    if(valueQuery_monate){
        free(valueQuery_monate);
        valueQuery_monate = NULL;
    }
    if(keyPairQuery_monate){
        keyValuePair_free(keyPairQuery_monate);
        keyPairQuery_monate = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

