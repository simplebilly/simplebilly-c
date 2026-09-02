#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "PublicReturnsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Customer checks the status of a return (public, no auth). The return is only revealed when its linked order's email matches.
//
public_return_status_response_t*
PublicReturnsAPI_getPublicReturnStatus(apiClient_t *apiClient, char *email, char *returnNumber, char *returnOrderId, char *orderNumber)
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
    char *localVarPath = strdup("/api/v1/public/returns/status");





    // query parameters
    char *keyQuery_returnNumber = NULL;
    char * valueQuery_returnNumber = NULL;
    keyValuePair_t *keyPairQuery_returnNumber = 0;
    if (returnNumber)
    {
        keyQuery_returnNumber = strdup("returnNumber");
        valueQuery_returnNumber = strdup((returnNumber));
        keyPairQuery_returnNumber = keyValuePair_create(keyQuery_returnNumber, valueQuery_returnNumber);
        list_addElement(localVarQueryParameters,keyPairQuery_returnNumber);
    }

    // query parameters
    char *keyQuery_returnOrderId = NULL;
    char * valueQuery_returnOrderId = NULL;
    keyValuePair_t *keyPairQuery_returnOrderId = 0;
    if (returnOrderId)
    {
        keyQuery_returnOrderId = strdup("returnOrderId");
        valueQuery_returnOrderId = strdup((returnOrderId));
        keyPairQuery_returnOrderId = keyValuePair_create(keyQuery_returnOrderId, valueQuery_returnOrderId);
        list_addElement(localVarQueryParameters,keyPairQuery_returnOrderId);
    }

    // query parameters
    char *keyQuery_email = NULL;
    char * valueQuery_email = NULL;
    keyValuePair_t *keyPairQuery_email = 0;
    if (email)
    {
        keyQuery_email = strdup("email");
        valueQuery_email = strdup((email));
        keyPairQuery_email = keyValuePair_create(keyQuery_email, valueQuery_email);
        list_addElement(localVarQueryParameters,keyPairQuery_email);
    }

    // query parameters
    char *keyQuery_orderNumber = NULL;
    char * valueQuery_orderNumber = NULL;
    keyValuePair_t *keyPairQuery_orderNumber = 0;
    if (orderNumber)
    {
        keyQuery_orderNumber = strdup("orderNumber");
        valueQuery_orderNumber = strdup((orderNumber));
        keyPairQuery_orderNumber = keyValuePair_create(keyQuery_orderNumber, valueQuery_orderNumber);
        list_addElement(localVarQueryParameters,keyPairQuery_orderNumber);
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
    //    printf("%s\n","Return status");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request (missing return identifier)");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Return not found or email mismatch");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    public_return_status_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *PublicReturnsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = public_return_status_response_parseFromJSON(PublicReturnsAPIlocalVarJSON);
        cJSON_Delete(PublicReturnsAPIlocalVarJSON);
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
    if(keyQuery_returnNumber){
        free(keyQuery_returnNumber);
        keyQuery_returnNumber = NULL;
    }
    if(valueQuery_returnNumber){
        free(valueQuery_returnNumber);
        valueQuery_returnNumber = NULL;
    }
    if(keyPairQuery_returnNumber){
        keyValuePair_free(keyPairQuery_returnNumber);
        keyPairQuery_returnNumber = NULL;
    }
    if(keyQuery_returnOrderId){
        free(keyQuery_returnOrderId);
        keyQuery_returnOrderId = NULL;
    }
    if(valueQuery_returnOrderId){
        free(valueQuery_returnOrderId);
        valueQuery_returnOrderId = NULL;
    }
    if(keyPairQuery_returnOrderId){
        keyValuePair_free(keyPairQuery_returnOrderId);
        keyPairQuery_returnOrderId = NULL;
    }
    if(keyQuery_email){
        free(keyQuery_email);
        keyQuery_email = NULL;
    }
    if(valueQuery_email){
        free(valueQuery_email);
        valueQuery_email = NULL;
    }
    if(keyPairQuery_email){
        keyValuePair_free(keyPairQuery_email);
        keyPairQuery_email = NULL;
    }
    if(keyQuery_orderNumber){
        free(keyQuery_orderNumber);
        keyQuery_orderNumber = NULL;
    }
    if(valueQuery_orderNumber){
        free(valueQuery_orderNumber);
        valueQuery_orderNumber = NULL;
    }
    if(keyPairQuery_orderNumber){
        keyValuePair_free(keyPairQuery_orderNumber);
        keyPairQuery_orderNumber = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List all returns for an order (public, no auth).
//
list_t*
PublicReturnsAPI_listPublicReturns(apiClient_t *apiClient, char *orderNumber, char *email)
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
    char *localVarPath = strdup("/api/v1/public/returns/list");





    // query parameters
    char *keyQuery_orderNumber = NULL;
    char * valueQuery_orderNumber = NULL;
    keyValuePair_t *keyPairQuery_orderNumber = 0;
    if (orderNumber)
    {
        keyQuery_orderNumber = strdup("orderNumber");
        valueQuery_orderNumber = strdup((orderNumber));
        keyPairQuery_orderNumber = keyValuePair_create(keyQuery_orderNumber, valueQuery_orderNumber);
        list_addElement(localVarQueryParameters,keyPairQuery_orderNumber);
    }

    // query parameters
    char *keyQuery_email = NULL;
    char * valueQuery_email = NULL;
    keyValuePair_t *keyPairQuery_email = 0;
    if (email)
    {
        keyQuery_email = strdup("email");
        valueQuery_email = strdup((email));
        keyPairQuery_email = keyValuePair_create(keyQuery_email, valueQuery_email);
        list_addElement(localVarQueryParameters,keyPairQuery_email);
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
    //    printf("%s\n","Returns for the order");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Order not found or email mismatch");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *PublicReturnsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(PublicReturnsAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, PublicReturnsAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( PublicReturnsAPIlocalVarJSON);
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
    if(keyQuery_orderNumber){
        free(keyQuery_orderNumber);
        keyQuery_orderNumber = NULL;
    }
    if(valueQuery_orderNumber){
        free(valueQuery_orderNumber);
        valueQuery_orderNumber = NULL;
    }
    if(keyPairQuery_orderNumber){
        keyValuePair_free(keyPairQuery_orderNumber);
        keyPairQuery_orderNumber = NULL;
    }
    if(keyQuery_email){
        free(keyQuery_email);
        keyQuery_email = NULL;
    }
    if(valueQuery_email){
        free(valueQuery_email);
        valueQuery_email = NULL;
    }
    if(keyPairQuery_email){
        keyValuePair_free(keyPairQuery_email);
        keyPairQuery_email = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Customer requests a return for an order (public, no auth).
//
public_return_response_t*
PublicReturnsAPI_requestPublicReturn(apiClient_t *apiClient, public_return_request_t *public_return_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/public/returns/request");





    // Body Param
    cJSON *localVarSingleItemJSON_public_return_request = NULL;
    if (public_return_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_public_return_request = public_return_request_convertToJSON(public_return_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_public_return_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
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
    //    printf("%s\n","Return requested");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request (item not in order / quantity too high)");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Order not found or email mismatch");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    public_return_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *PublicReturnsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = public_return_response_parseFromJSON(PublicReturnsAPIlocalVarJSON);
        cJSON_Delete(PublicReturnsAPIlocalVarJSON);
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
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_public_return_request) {
        cJSON_Delete(localVarSingleItemJSON_public_return_request);
        localVarSingleItemJSON_public_return_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

