#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "StockMovementAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


stock_movement_t*
StockMovementAPI_getStockMovement(apiClient_t *apiClient, char *movement_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/stock-movements/{movement_id}");

    if(!movement_id)
        goto end;


    // Path Params
    long sizeOfPathParams_movement_id = strlen(movement_id)+3 + sizeof("{ movement_id }") - 1;
    if(movement_id == NULL) {
        goto end;
    }
    char* localVarToReplace_movement_id = malloc(sizeOfPathParams_movement_id);
    sprintf(localVarToReplace_movement_id, "{%s}", "movement_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_movement_id, movement_id);


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
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    stock_movement_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StockMovementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = stock_movement_parseFromJSON(StockMovementAPIlocalVarJSON);
        cJSON_Delete(StockMovementAPIlocalVarJSON);
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
    
    free(localVarPath);
    free(localVarToReplace_movement_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
StockMovementAPI_listStockMovements(apiClient_t *apiClient, int *page, int *pageSize, char *productId, char *warehouseId, char *movementType, char from, char to)
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
    char *localVarPath = strdup("/api/v1/stock-movements/");





    // query parameters
    char *keyQuery_page = NULL;
    char * valueQuery_page = NULL;
    keyValuePair_t *keyPairQuery_page = 0;
    if (page)
    {
        keyQuery_page = strdup("page");
        valueQuery_page = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_page, MAX_NUMBER_LENGTH, "%d", *page);
        keyPairQuery_page = keyValuePair_create(keyQuery_page, valueQuery_page);
        list_addElement(localVarQueryParameters,keyPairQuery_page);
    }

    // query parameters
    char *keyQuery_pageSize = NULL;
    char * valueQuery_pageSize = NULL;
    keyValuePair_t *keyPairQuery_pageSize = 0;
    if (pageSize)
    {
        keyQuery_pageSize = strdup("pageSize");
        valueQuery_pageSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_pageSize, MAX_NUMBER_LENGTH, "%d", *pageSize);
        keyPairQuery_pageSize = keyValuePair_create(keyQuery_pageSize, valueQuery_pageSize);
        list_addElement(localVarQueryParameters,keyPairQuery_pageSize);
    }

    // query parameters
    char *keyQuery_productId = NULL;
    char * valueQuery_productId = NULL;
    keyValuePair_t *keyPairQuery_productId = 0;
    if (productId)
    {
        keyQuery_productId = strdup("productId");
        valueQuery_productId = strdup((productId));
        keyPairQuery_productId = keyValuePair_create(keyQuery_productId, valueQuery_productId);
        list_addElement(localVarQueryParameters,keyPairQuery_productId);
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

    // query parameters
    char *keyQuery_movementType = NULL;
    char * valueQuery_movementType = NULL;
    keyValuePair_t *keyPairQuery_movementType = 0;
    if (movementType)
    {
        keyQuery_movementType = strdup("movementType");
        valueQuery_movementType = strdup((movementType));
        keyPairQuery_movementType = keyValuePair_create(keyQuery_movementType, valueQuery_movementType);
        list_addElement(localVarQueryParameters,keyPairQuery_movementType);
    }

    // query parameters
    char *keyQuery_from = NULL;
    char valueQuery_from ;
    keyValuePair_t *keyPairQuery_from = 0;
    if (from)
    {
        keyQuery_from = strdup("from");
        valueQuery_from = (from);
        keyPairQuery_from = keyValuePair_create(keyQuery_from, &valueQuery_from);
        list_addElement(localVarQueryParameters,keyPairQuery_from);
    }

    // query parameters
    char *keyQuery_to = NULL;
    char valueQuery_to ;
    keyValuePair_t *keyPairQuery_to = 0;
    if (to)
    {
        keyQuery_to = strdup("to");
        valueQuery_to = (to);
        keyPairQuery_to = keyValuePair_create(keyQuery_to, &valueQuery_to);
        list_addElement(localVarQueryParameters,keyPairQuery_to);
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
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StockMovementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(StockMovementAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, StockMovementAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( StockMovementAPIlocalVarJSON);
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
    if(keyQuery_page){
        free(keyQuery_page);
        keyQuery_page = NULL;
    }
    if(valueQuery_page){
        free(valueQuery_page);
        valueQuery_page = NULL;
    }
    if(keyPairQuery_page){
        keyValuePair_free(keyPairQuery_page);
        keyPairQuery_page = NULL;
    }
    if(keyQuery_pageSize){
        free(keyQuery_pageSize);
        keyQuery_pageSize = NULL;
    }
    if(valueQuery_pageSize){
        free(valueQuery_pageSize);
        valueQuery_pageSize = NULL;
    }
    if(keyPairQuery_pageSize){
        keyValuePair_free(keyPairQuery_pageSize);
        keyPairQuery_pageSize = NULL;
    }
    if(keyQuery_productId){
        free(keyQuery_productId);
        keyQuery_productId = NULL;
    }
    if(valueQuery_productId){
        free(valueQuery_productId);
        valueQuery_productId = NULL;
    }
    if(keyPairQuery_productId){
        keyValuePair_free(keyPairQuery_productId);
        keyPairQuery_productId = NULL;
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
    if(keyQuery_movementType){
        free(keyQuery_movementType);
        keyQuery_movementType = NULL;
    }
    if(valueQuery_movementType){
        free(valueQuery_movementType);
        valueQuery_movementType = NULL;
    }
    if(keyPairQuery_movementType){
        keyValuePair_free(keyPairQuery_movementType);
        keyPairQuery_movementType = NULL;
    }
    if(keyQuery_from){
        free(keyQuery_from);
        keyQuery_from = NULL;
    }
    if(keyPairQuery_from){
        keyValuePair_free(keyPairQuery_from);
        keyPairQuery_from = NULL;
    }
    if(keyQuery_to){
        free(keyQuery_to);
        keyQuery_to = NULL;
    }
    if(keyPairQuery_to){
        keyValuePair_free(keyPairQuery_to);
        keyPairQuery_to = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

