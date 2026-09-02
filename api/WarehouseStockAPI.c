#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "WarehouseStockAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


warehouse_stock_t*
WarehouseStockAPI_createWarehouseStock(apiClient_t *apiClient, char *warehouse_id, stock_adjustment_t *stock_adjustment)
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
    char *localVarPath = strdup("/api/v1/warehouses/{warehouse_id}/stock");

    if(!warehouse_id)
        goto end;


    // Path Params
    long sizeOfPathParams_warehouse_id = strlen(warehouse_id)+3 + sizeof("{ warehouse_id }") - 1;
    if(warehouse_id == NULL) {
        goto end;
    }
    char* localVarToReplace_warehouse_id = malloc(sizeOfPathParams_warehouse_id);
    sprintf(localVarToReplace_warehouse_id, "{%s}", "warehouse_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_warehouse_id, warehouse_id);



    // Body Param
    cJSON *localVarSingleItemJSON_stock_adjustment = NULL;
    if (stock_adjustment != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_stock_adjustment = stock_adjustment_convertToJSON(stock_adjustment);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_stock_adjustment);
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
    warehouse_stock_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *WarehouseStockAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = warehouse_stock_parseFromJSON(WarehouseStockAPIlocalVarJSON);
        cJSON_Delete(WarehouseStockAPIlocalVarJSON);
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
    free(localVarToReplace_warehouse_id);
    if (localVarSingleItemJSON_stock_adjustment) {
        cJSON_Delete(localVarSingleItemJSON_stock_adjustment);
        localVarSingleItemJSON_stock_adjustment = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
WarehouseStockAPI_deleteWarehouseStock(apiClient_t *apiClient, char *warehouse_id, char *product_id)
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
    char *localVarPath = strdup("/api/v1/warehouses/{warehouse_id}/stock/{product_id}");

    if(!warehouse_id)
        goto end;
    if(!product_id)
        goto end;


    // Path Params
    long sizeOfPathParams_warehouse_id = strlen(warehouse_id)+3 + strlen(product_id)+3 + sizeof("{ warehouse_id }") - 1;
    if(warehouse_id == NULL) {
        goto end;
    }
    char* localVarToReplace_warehouse_id = malloc(sizeOfPathParams_warehouse_id);
    sprintf(localVarToReplace_warehouse_id, "{%s}", "warehouse_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_warehouse_id, warehouse_id);

    // Path Params
    long sizeOfPathParams_product_id = strlen(warehouse_id)+3 + strlen(product_id)+3 + sizeof("{ product_id }") - 1;
    if(product_id == NULL) {
        goto end;
    }
    char* localVarToReplace_product_id = malloc(sizeOfPathParams_product_id);
    sprintf(localVarToReplace_product_id, "{%s}", "product_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_product_id, product_id);


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
    free(localVarToReplace_warehouse_id);
    free(localVarToReplace_product_id);

}

list_t*
WarehouseStockAPI_listWarehouseStock(apiClient_t *apiClient, char *warehouse_id)
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
    char *localVarPath = strdup("/api/v1/warehouses/{warehouse_id}/stock");

    if(!warehouse_id)
        goto end;


    // Path Params
    long sizeOfPathParams_warehouse_id = strlen(warehouse_id)+3 + sizeof("{ warehouse_id }") - 1;
    if(warehouse_id == NULL) {
        goto end;
    }
    char* localVarToReplace_warehouse_id = malloc(sizeOfPathParams_warehouse_id);
    sprintf(localVarToReplace_warehouse_id, "{%s}", "warehouse_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_warehouse_id, warehouse_id);


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
        cJSON *WarehouseStockAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(WarehouseStockAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, WarehouseStockAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( WarehouseStockAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
    }
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_warehouse_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

warehouse_stock_t*
WarehouseStockAPI_updateWarehouseStock(apiClient_t *apiClient, char *warehouse_id, char *product_id, stock_adjustment_t *stock_adjustment)
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
    char *localVarPath = strdup("/api/v1/warehouses/{warehouse_id}/stock/{product_id}");

    if(!warehouse_id)
        goto end;
    if(!product_id)
        goto end;


    // Path Params
    long sizeOfPathParams_warehouse_id = strlen(warehouse_id)+3 + strlen(product_id)+3 + sizeof("{ warehouse_id }") - 1;
    if(warehouse_id == NULL) {
        goto end;
    }
    char* localVarToReplace_warehouse_id = malloc(sizeOfPathParams_warehouse_id);
    sprintf(localVarToReplace_warehouse_id, "{%s}", "warehouse_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_warehouse_id, warehouse_id);

    // Path Params
    long sizeOfPathParams_product_id = strlen(warehouse_id)+3 + strlen(product_id)+3 + sizeof("{ product_id }") - 1;
    if(product_id == NULL) {
        goto end;
    }
    char* localVarToReplace_product_id = malloc(sizeOfPathParams_product_id);
    sprintf(localVarToReplace_product_id, "{%s}", "product_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_product_id, product_id);



    // Body Param
    cJSON *localVarSingleItemJSON_stock_adjustment = NULL;
    if (stock_adjustment != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_stock_adjustment = stock_adjustment_convertToJSON(stock_adjustment);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_stock_adjustment);
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
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    warehouse_stock_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *WarehouseStockAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = warehouse_stock_parseFromJSON(WarehouseStockAPIlocalVarJSON);
        cJSON_Delete(WarehouseStockAPIlocalVarJSON);
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
    free(localVarToReplace_warehouse_id);
    free(localVarToReplace_product_id);
    if (localVarSingleItemJSON_stock_adjustment) {
        cJSON_Delete(localVarSingleItemJSON_stock_adjustment);
        localVarSingleItemJSON_stock_adjustment = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

