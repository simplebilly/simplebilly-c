#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ReorderProposalAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Convert a reorder proposal into a draft purchase order.
//
// Returns the created purchase order id. Suggested line items are generated with the current reorder quantity per product.
//
any_type_t*
ReorderProposalAPI_applyReorderProposal(apiClient_t *apiClient, int *configuredOnly, char *warehouseId)
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
    char *localVarPath = strdup("/api/v1/reorder-proposals/apply");





    // query parameters
    char *keyQuery_configuredOnly = NULL;
    char * valueQuery_configuredOnly = NULL;
    keyValuePair_t *keyPairQuery_configuredOnly = 0;
    if (configuredOnly)
    {
        keyQuery_configuredOnly = strdup("configuredOnly");
        valueQuery_configuredOnly = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_configuredOnly, MAX_NUMBER_LENGTH, "%d", *configuredOnly);
        keyPairQuery_configuredOnly = keyValuePair_create(keyQuery_configuredOnly, valueQuery_configuredOnly);
        list_addElement(localVarQueryParameters,keyPairQuery_configuredOnly);
    }

    // query parameters
    char *keyQuery_warehouseId = NULL;
    char * valueQuery_warehouseId = NULL;
    keyValuePair_t *keyPairQuery_warehouseId = 0;
    if (warehouseId)
    {
        keyQuery_warehouseId = strdup("warehouseId");
        valueQuery_warehouseId = strdup((warehouseId));
        keyPairQuery_warehouseId = keyValuePair_create(keyQuery_warehouseId, valueQuery_warehouseId);
        list_addElement(localVarQueryParameters,keyPairQuery_warehouseId);
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
        cJSON *ReorderProposalAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = any_type_parseFromJSON(ReorderProposalAPIlocalVarJSON);
        cJSON_Delete(ReorderProposalAPIlocalVarJSON);
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
    if(keyQuery_configuredOnly){
        free(keyQuery_configuredOnly);
        keyQuery_configuredOnly = NULL;
    }
    if(valueQuery_configuredOnly){
        free(valueQuery_configuredOnly);
        valueQuery_configuredOnly = NULL;
    }
    if(keyPairQuery_configuredOnly){
        keyValuePair_free(keyPairQuery_configuredOnly);
        keyPairQuery_configuredOnly = NULL;
    }
    if(keyQuery_warehouseId){
        free(keyQuery_warehouseId);
        keyQuery_warehouseId = NULL;
    }
    if(valueQuery_warehouseId){
        free(valueQuery_warehouseId);
        valueQuery_warehouseId = NULL;
    }
    if(keyPairQuery_warehouseId){
        keyValuePair_free(keyPairQuery_warehouseId);
        keyPairQuery_warehouseId = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

reorder_proposal_response_t*
ReorderProposalAPI_getReorderProposal(apiClient_t *apiClient, int *configuredOnly, char *warehouseId)
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
    char *localVarPath = strdup("/api/v1/reorder-proposals");





    // query parameters
    char *keyQuery_configuredOnly = NULL;
    char * valueQuery_configuredOnly = NULL;
    keyValuePair_t *keyPairQuery_configuredOnly = 0;
    if (configuredOnly)
    {
        keyQuery_configuredOnly = strdup("configuredOnly");
        valueQuery_configuredOnly = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_configuredOnly, MAX_NUMBER_LENGTH, "%d", *configuredOnly);
        keyPairQuery_configuredOnly = keyValuePair_create(keyQuery_configuredOnly, valueQuery_configuredOnly);
        list_addElement(localVarQueryParameters,keyPairQuery_configuredOnly);
    }

    // query parameters
    char *keyQuery_warehouseId = NULL;
    char * valueQuery_warehouseId = NULL;
    keyValuePair_t *keyPairQuery_warehouseId = 0;
    if (warehouseId)
    {
        keyQuery_warehouseId = strdup("warehouseId");
        valueQuery_warehouseId = strdup((warehouseId));
        keyPairQuery_warehouseId = keyValuePair_create(keyQuery_warehouseId, valueQuery_warehouseId);
        list_addElement(localVarQueryParameters,keyPairQuery_warehouseId);
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
    reorder_proposal_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ReorderProposalAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = reorder_proposal_response_parseFromJSON(ReorderProposalAPIlocalVarJSON);
        cJSON_Delete(ReorderProposalAPIlocalVarJSON);
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
    if(keyQuery_configuredOnly){
        free(keyQuery_configuredOnly);
        keyQuery_configuredOnly = NULL;
    }
    if(valueQuery_configuredOnly){
        free(valueQuery_configuredOnly);
        valueQuery_configuredOnly = NULL;
    }
    if(keyPairQuery_configuredOnly){
        keyValuePair_free(keyPairQuery_configuredOnly);
        keyPairQuery_configuredOnly = NULL;
    }
    if(keyQuery_warehouseId){
        free(keyQuery_warehouseId);
        keyQuery_warehouseId = NULL;
    }
    if(valueQuery_warehouseId){
        free(valueQuery_warehouseId);
        valueQuery_warehouseId = NULL;
    }
    if(keyPairQuery_warehouseId){
        keyValuePair_free(keyPairQuery_warehouseId);
        keyPairQuery_warehouseId = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

