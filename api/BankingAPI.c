#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "BankingAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


bank_lookup_t*
BankingAPI_bankLookupApi(apiClient_t *apiClient, char *iban)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/banking/lookup");





    // query parameters
    char *keyQuery_iban = NULL;
    char * valueQuery_iban = NULL;
    keyValuePair_t *keyPairQuery_iban = 0;
    if (iban)
    {
        keyQuery_iban = strdup("iban");
        valueQuery_iban = strdup((iban));
        keyPairQuery_iban = keyValuePair_create(keyQuery_iban, valueQuery_iban);
        list_addElement(localVarQueryParameters,keyPairQuery_iban);
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
    //    printf("%s\n","Bank-Lookup Ergebnis");
    //}
    //nonprimitive not container
    bank_lookup_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *BankingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = bank_lookup_parseFromJSON(BankingAPIlocalVarJSON);
        cJSON_Delete(BankingAPIlocalVarJSON);
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
    if(keyQuery_iban){
        free(keyQuery_iban);
        keyQuery_iban = NULL;
    }
    if(valueQuery_iban){
        free(valueQuery_iban);
        valueQuery_iban = NULL;
    }
    if(keyPairQuery_iban){
        keyValuePair_free(keyPairQuery_iban);
        keyPairQuery_iban = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
BankingAPI_bankTransactionsApi(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/bookkeeping/banking/transactions");




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
    //    printf("%s\n","Bank-Transaktionen");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    
    free(localVarPath);

}

list_t*
BankingAPI_hebesatzLookupApi(apiClient_t *apiClient, char *gemeindeschluessel, char *plz, char *name, char *stichtag, char *country_code)
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
    char *localVarPath = strdup("/api/v1/bookkeeping/hebesatz");





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

    // query parameters
    char *keyQuery_plz = NULL;
    char * valueQuery_plz = NULL;
    keyValuePair_t *keyPairQuery_plz = 0;
    if (plz)
    {
        keyQuery_plz = strdup("plz");
        valueQuery_plz = strdup((plz));
        keyPairQuery_plz = keyValuePair_create(keyQuery_plz, valueQuery_plz);
        list_addElement(localVarQueryParameters,keyPairQuery_plz);
    }

    // query parameters
    char *keyQuery_name = NULL;
    char * valueQuery_name = NULL;
    keyValuePair_t *keyPairQuery_name = 0;
    if (name)
    {
        keyQuery_name = strdup("name");
        valueQuery_name = strdup((name));
        keyPairQuery_name = keyValuePair_create(keyQuery_name, valueQuery_name);
        list_addElement(localVarQueryParameters,keyPairQuery_name);
    }

    // query parameters
    char *keyQuery_stichtag = NULL;
    char * valueQuery_stichtag = NULL;
    keyValuePair_t *keyPairQuery_stichtag = 0;
    if (stichtag)
    {
        keyQuery_stichtag = strdup("stichtag");
        valueQuery_stichtag = strdup((stichtag));
        keyPairQuery_stichtag = keyValuePair_create(keyQuery_stichtag, valueQuery_stichtag);
        list_addElement(localVarQueryParameters,keyPairQuery_stichtag);
    }

    // query parameters
    char *keyQuery_country_code = NULL;
    char * valueQuery_country_code = NULL;
    keyValuePair_t *keyPairQuery_country_code = 0;
    if (country_code)
    {
        keyQuery_country_code = strdup("country_code");
        valueQuery_country_code = strdup((country_code));
        keyPairQuery_country_code = keyValuePair_create(keyQuery_country_code, valueQuery_country_code);
        list_addElement(localVarQueryParameters,keyPairQuery_country_code);
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
    //    printf("%s\n","Hebesatz Lookup");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *BankingAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(BankingAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, BankingAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( BankingAPIlocalVarJSON);
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
    if(keyQuery_plz){
        free(keyQuery_plz);
        keyQuery_plz = NULL;
    }
    if(valueQuery_plz){
        free(valueQuery_plz);
        valueQuery_plz = NULL;
    }
    if(keyPairQuery_plz){
        keyValuePair_free(keyPairQuery_plz);
        keyPairQuery_plz = NULL;
    }
    if(keyQuery_name){
        free(keyQuery_name);
        keyQuery_name = NULL;
    }
    if(valueQuery_name){
        free(valueQuery_name);
        valueQuery_name = NULL;
    }
    if(keyPairQuery_name){
        keyValuePair_free(keyPairQuery_name);
        keyPairQuery_name = NULL;
    }
    if(keyQuery_stichtag){
        free(keyQuery_stichtag);
        keyQuery_stichtag = NULL;
    }
    if(valueQuery_stichtag){
        free(valueQuery_stichtag);
        valueQuery_stichtag = NULL;
    }
    if(keyPairQuery_stichtag){
        keyValuePair_free(keyPairQuery_stichtag);
        keyPairQuery_stichtag = NULL;
    }
    if(keyQuery_country_code){
        free(keyQuery_country_code);
        keyQuery_country_code = NULL;
    }
    if(valueQuery_country_code){
        free(valueQuery_country_code);
        valueQuery_country_code = NULL;
    }
    if(keyPairQuery_country_code){
        keyValuePair_free(keyPairQuery_country_code);
        keyPairQuery_country_code = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

