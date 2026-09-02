#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ReplenishmentAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Create one draft stock transfer per (source → target) pair carrying all suggested product lines for that pair.
//
any_type_t*
ReplenishmentAPI_applyReplenishments(apiClient_t *apiClient, char *targetWarehouseId, char *sourceWarehouseId)
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
    char *localVarPath = strdup("/api/v1/replenishments/apply");





    // query parameters
    char *keyQuery_targetWarehouseId = NULL;
    char * valueQuery_targetWarehouseId = NULL;
    keyValuePair_t *keyPairQuery_targetWarehouseId = 0;
    if (targetWarehouseId)
    {
        keyQuery_targetWarehouseId = strdup("targetWarehouseId");
        valueQuery_targetWarehouseId = strdup((targetWarehouseId));
        keyPairQuery_targetWarehouseId = keyValuePair_create(keyQuery_targetWarehouseId, valueQuery_targetWarehouseId);
        list_addElement(localVarQueryParameters,keyPairQuery_targetWarehouseId);
    }

    // query parameters
    char *keyQuery_sourceWarehouseId = NULL;
    char * valueQuery_sourceWarehouseId = NULL;
    keyValuePair_t *keyPairQuery_sourceWarehouseId = 0;
    if (sourceWarehouseId)
    {
        keyQuery_sourceWarehouseId = strdup("sourceWarehouseId");
        valueQuery_sourceWarehouseId = strdup((sourceWarehouseId));
        keyPairQuery_sourceWarehouseId = keyValuePair_create(keyQuery_sourceWarehouseId, valueQuery_sourceWarehouseId);
        list_addElement(localVarQueryParameters,keyPairQuery_sourceWarehouseId);
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
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Created");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    any_type_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ReplenishmentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = any_type_parseFromJSON(ReplenishmentAPIlocalVarJSON);
        cJSON_Delete(ReplenishmentAPIlocalVarJSON);
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
    if(keyQuery_targetWarehouseId){
        free(keyQuery_targetWarehouseId);
        keyQuery_targetWarehouseId = NULL;
    }
    if(valueQuery_targetWarehouseId){
        free(valueQuery_targetWarehouseId);
        valueQuery_targetWarehouseId = NULL;
    }
    if(keyPairQuery_targetWarehouseId){
        keyValuePair_free(keyPairQuery_targetWarehouseId);
        keyPairQuery_targetWarehouseId = NULL;
    }
    if(keyQuery_sourceWarehouseId){
        free(keyQuery_sourceWarehouseId);
        keyQuery_sourceWarehouseId = NULL;
    }
    if(valueQuery_sourceWarehouseId){
        free(valueQuery_sourceWarehouseId);
        valueQuery_sourceWarehouseId = NULL;
    }
    if(keyPairQuery_sourceWarehouseId){
        keyValuePair_free(keyPairQuery_sourceWarehouseId);
        keyPairQuery_sourceWarehouseId = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

replenishment_response_t*
ReplenishmentAPI_getReplenishments(apiClient_t *apiClient, char *targetWarehouseId, char *sourceWarehouseId)
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
    char *localVarPath = strdup("/api/v1/replenishments");





    // query parameters
    char *keyQuery_targetWarehouseId = NULL;
    char * valueQuery_targetWarehouseId = NULL;
    keyValuePair_t *keyPairQuery_targetWarehouseId = 0;
    if (targetWarehouseId)
    {
        keyQuery_targetWarehouseId = strdup("targetWarehouseId");
        valueQuery_targetWarehouseId = strdup((targetWarehouseId));
        keyPairQuery_targetWarehouseId = keyValuePair_create(keyQuery_targetWarehouseId, valueQuery_targetWarehouseId);
        list_addElement(localVarQueryParameters,keyPairQuery_targetWarehouseId);
    }

    // query parameters
    char *keyQuery_sourceWarehouseId = NULL;
    char * valueQuery_sourceWarehouseId = NULL;
    keyValuePair_t *keyPairQuery_sourceWarehouseId = 0;
    if (sourceWarehouseId)
    {
        keyQuery_sourceWarehouseId = strdup("sourceWarehouseId");
        valueQuery_sourceWarehouseId = strdup((sourceWarehouseId));
        keyPairQuery_sourceWarehouseId = keyValuePair_create(keyQuery_sourceWarehouseId, valueQuery_sourceWarehouseId);
        list_addElement(localVarQueryParameters,keyPairQuery_sourceWarehouseId);
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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    replenishment_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ReplenishmentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = replenishment_response_parseFromJSON(ReplenishmentAPIlocalVarJSON);
        cJSON_Delete(ReplenishmentAPIlocalVarJSON);
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
    if(keyQuery_targetWarehouseId){
        free(keyQuery_targetWarehouseId);
        keyQuery_targetWarehouseId = NULL;
    }
    if(valueQuery_targetWarehouseId){
        free(valueQuery_targetWarehouseId);
        valueQuery_targetWarehouseId = NULL;
    }
    if(keyPairQuery_targetWarehouseId){
        keyValuePair_free(keyPairQuery_targetWarehouseId);
        keyPairQuery_targetWarehouseId = NULL;
    }
    if(keyQuery_sourceWarehouseId){
        free(keyQuery_sourceWarehouseId);
        keyQuery_sourceWarehouseId = NULL;
    }
    if(valueQuery_sourceWarehouseId){
        free(valueQuery_sourceWarehouseId);
        valueQuery_sourceWarehouseId = NULL;
    }
    if(keyPairQuery_sourceWarehouseId){
        keyValuePair_free(keyPairQuery_sourceWarehouseId);
        keyPairQuery_sourceWarehouseId = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

