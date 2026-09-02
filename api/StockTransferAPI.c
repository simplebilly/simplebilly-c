#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "StockTransferAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


stock_transfer_t*
StockTransferAPI_createStockTransfer(apiClient_t *apiClient, stock_transfer_t *stock_transfer)
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
    char *localVarPath = strdup("/api/v1/stock-transfers");





    // Body Param
    cJSON *localVarSingleItemJSON_stock_transfer = NULL;
    if (stock_transfer != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_stock_transfer = stock_transfer_convertToJSON(stock_transfer);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_stock_transfer);
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
    stock_transfer_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StockTransferAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = stock_transfer_parseFromJSON(StockTransferAPIlocalVarJSON);
        cJSON_Delete(StockTransferAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_stock_transfer) {
        cJSON_Delete(localVarSingleItemJSON_stock_transfer);
        localVarSingleItemJSON_stock_transfer = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
StockTransferAPI_deleteStockTransfer(apiClient_t *apiClient, char *stock_transfer_id)
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
    char *localVarPath = strdup("/api/v1/stock-transfers/{stock_transfer_id}");

    if(!stock_transfer_id)
        goto end;


    // Path Params
    long sizeOfPathParams_stock_transfer_id = strlen(stock_transfer_id)+3 + sizeof("{ stock_transfer_id }") - 1;
    if(stock_transfer_id == NULL) {
        goto end;
    }
    char* localVarToReplace_stock_transfer_id = malloc(sizeOfPathParams_stock_transfer_id);
    sprintf(localVarToReplace_stock_transfer_id, "{%s}", "stock_transfer_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_stock_transfer_id, stock_transfer_id);


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
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","No Content");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_stock_transfer_id);

}

stock_transfer_t*
StockTransferAPI_getStockTransfer(apiClient_t *apiClient, char *stock_transfer_id)
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
    char *localVarPath = strdup("/api/v1/stock-transfers/{stock_transfer_id}");

    if(!stock_transfer_id)
        goto end;


    // Path Params
    long sizeOfPathParams_stock_transfer_id = strlen(stock_transfer_id)+3 + sizeof("{ stock_transfer_id }") - 1;
    if(stock_transfer_id == NULL) {
        goto end;
    }
    char* localVarToReplace_stock_transfer_id = malloc(sizeOfPathParams_stock_transfer_id);
    sprintf(localVarToReplace_stock_transfer_id, "{%s}", "stock_transfer_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_stock_transfer_id, stock_transfer_id);


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
    stock_transfer_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StockTransferAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = stock_transfer_parseFromJSON(StockTransferAPIlocalVarJSON);
        cJSON_Delete(StockTransferAPIlocalVarJSON);
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
    free(localVarToReplace_stock_transfer_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
StockTransferAPI_listStockTransfers(apiClient_t *apiClient, int *page, int *page_size, char *status, char *warehouse_id)
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
    char *localVarPath = strdup("/api/v1/stock-transfers/");





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
    char *keyQuery_page_size = NULL;
    char * valueQuery_page_size = NULL;
    keyValuePair_t *keyPairQuery_page_size = 0;
    if (page_size)
    {
        keyQuery_page_size = strdup("page_size");
        valueQuery_page_size = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_page_size, MAX_NUMBER_LENGTH, "%d", *page_size);
        keyPairQuery_page_size = keyValuePair_create(keyQuery_page_size, valueQuery_page_size);
        list_addElement(localVarQueryParameters,keyPairQuery_page_size);
    }

    // query parameters
    char *keyQuery_status = NULL;
    char * valueQuery_status = NULL;
    keyValuePair_t *keyPairQuery_status = 0;
    if (status)
    {
        keyQuery_status = strdup("status");
        valueQuery_status = strdup((status));
        keyPairQuery_status = keyValuePair_create(keyQuery_status, valueQuery_status);
        list_addElement(localVarQueryParameters,keyPairQuery_status);
    }

    // query parameters
    char *keyQuery_warehouse_id = NULL;
    char * valueQuery_warehouse_id = NULL;
    keyValuePair_t *keyPairQuery_warehouse_id = 0;
    if (warehouse_id)
    {
        keyQuery_warehouse_id = strdup("warehouse_id");
        valueQuery_warehouse_id = strdup((warehouse_id));
        keyPairQuery_warehouse_id = keyValuePair_create(keyQuery_warehouse_id, valueQuery_warehouse_id);
        list_addElement(localVarQueryParameters,keyPairQuery_warehouse_id);
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
        cJSON *StockTransferAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(StockTransferAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, StockTransferAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( StockTransferAPIlocalVarJSON);
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
    if(keyQuery_page_size){
        free(keyQuery_page_size);
        keyQuery_page_size = NULL;
    }
    if(valueQuery_page_size){
        free(valueQuery_page_size);
        valueQuery_page_size = NULL;
    }
    if(keyPairQuery_page_size){
        keyValuePair_free(keyPairQuery_page_size);
        keyPairQuery_page_size = NULL;
    }
    if(keyQuery_status){
        free(keyQuery_status);
        keyQuery_status = NULL;
    }
    if(valueQuery_status){
        free(valueQuery_status);
        valueQuery_status = NULL;
    }
    if(keyPairQuery_status){
        keyValuePair_free(keyPairQuery_status);
        keyPairQuery_status = NULL;
    }
    if(keyQuery_warehouse_id){
        free(keyQuery_warehouse_id);
        keyQuery_warehouse_id = NULL;
    }
    if(valueQuery_warehouse_id){
        free(valueQuery_warehouse_id);
        valueQuery_warehouse_id = NULL;
    }
    if(keyPairQuery_warehouse_id){
        keyValuePair_free(keyPairQuery_warehouse_id);
        keyPairQuery_warehouse_id = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

stock_transfer_t*
StockTransferAPI_updateStockTransferStatus(apiClient_t *apiClient, char *stock_transfer_id, stock_transfer_status_update_t *stock_transfer_status_update)
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
    char *localVarPath = strdup("/api/v1/stock-transfers/{stock_transfer_id}/status");

    if(!stock_transfer_id)
        goto end;


    // Path Params
    long sizeOfPathParams_stock_transfer_id = strlen(stock_transfer_id)+3 + sizeof("{ stock_transfer_id }") - 1;
    if(stock_transfer_id == NULL) {
        goto end;
    }
    char* localVarToReplace_stock_transfer_id = malloc(sizeOfPathParams_stock_transfer_id);
    sprintf(localVarToReplace_stock_transfer_id, "{%s}", "stock_transfer_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_stock_transfer_id, stock_transfer_id);



    // Body Param
    cJSON *localVarSingleItemJSON_stock_transfer_status_update = NULL;
    if (stock_transfer_status_update != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_stock_transfer_status_update = stock_transfer_status_update_convertToJSON(stock_transfer_status_update);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_stock_transfer_status_update);
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
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
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
    stock_transfer_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *StockTransferAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = stock_transfer_parseFromJSON(StockTransferAPIlocalVarJSON);
        cJSON_Delete(StockTransferAPIlocalVarJSON);
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
    free(localVarToReplace_stock_transfer_id);
    if (localVarSingleItemJSON_stock_transfer_status_update) {
        cJSON_Delete(localVarSingleItemJSON_stock_transfer_status_update);
        localVarSingleItemJSON_stock_transfer_status_update = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

