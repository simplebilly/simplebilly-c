#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ShippingThresholdAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


shipping_threshold_t*
ShippingThresholdAPI_createShippingThreshold(apiClient_t *apiClient, shipping_threshold_create_t *shipping_threshold_create)
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
    char *localVarPath = strdup("/api/v1/shipping-thresholds");





    // Body Param
    cJSON *localVarSingleItemJSON_shipping_threshold_create = NULL;
    if (shipping_threshold_create != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_shipping_threshold_create = shipping_threshold_create_convertToJSON(shipping_threshold_create);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_shipping_threshold_create);
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
    shipping_threshold_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ShippingThresholdAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = shipping_threshold_parseFromJSON(ShippingThresholdAPIlocalVarJSON);
        cJSON_Delete(ShippingThresholdAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_shipping_threshold_create) {
        cJSON_Delete(localVarSingleItemJSON_shipping_threshold_create);
        localVarSingleItemJSON_shipping_threshold_create = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
ShippingThresholdAPI_deleteShippingThreshold(apiClient_t *apiClient, char *threshold_id)
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
    char *localVarPath = strdup("/api/v1/shipping-thresholds/{threshold_id}");

    if(!threshold_id)
        goto end;


    // Path Params
    long sizeOfPathParams_threshold_id = strlen(threshold_id)+3 + sizeof("{ threshold_id }") - 1;
    if(threshold_id == NULL) {
        goto end;
    }
    char* localVarToReplace_threshold_id = malloc(sizeOfPathParams_threshold_id);
    sprintf(localVarToReplace_threshold_id, "{%s}", "threshold_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_threshold_id, threshold_id);


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
    free(localVarToReplace_threshold_id);

}

deliverable_response_t*
ShippingThresholdAPI_getDeliverable(apiClient_t *apiClient, char *productId, char *warehouseId)
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
    char *localVarPath = strdup("/api/v1/shipping-thresholds/deliverable");





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
    deliverable_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ShippingThresholdAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = deliverable_response_parseFromJSON(ShippingThresholdAPIlocalVarJSON);
        cJSON_Delete(ShippingThresholdAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

shipping_threshold_t*
ShippingThresholdAPI_getShippingThreshold(apiClient_t *apiClient, char *threshold_id)
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
    char *localVarPath = strdup("/api/v1/shipping-thresholds/{threshold_id}");

    if(!threshold_id)
        goto end;


    // Path Params
    long sizeOfPathParams_threshold_id = strlen(threshold_id)+3 + sizeof("{ threshold_id }") - 1;
    if(threshold_id == NULL) {
        goto end;
    }
    char* localVarToReplace_threshold_id = malloc(sizeOfPathParams_threshold_id);
    sprintf(localVarToReplace_threshold_id, "{%s}", "threshold_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_threshold_id, threshold_id);


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
    shipping_threshold_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ShippingThresholdAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = shipping_threshold_parseFromJSON(ShippingThresholdAPIlocalVarJSON);
        cJSON_Delete(ShippingThresholdAPIlocalVarJSON);
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
    free(localVarToReplace_threshold_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
ShippingThresholdAPI_listShippingThresholds(apiClient_t *apiClient, int *page, int *page_size, char *product_id, char *warehouse_id, int *is_active)
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
    char *localVarPath = strdup("/api/v1/shipping-thresholds/");





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
    char *keyQuery_product_id = NULL;
    char * valueQuery_product_id = NULL;
    keyValuePair_t *keyPairQuery_product_id = 0;
    if (product_id)
    {
        keyQuery_product_id = strdup("product_id");
        valueQuery_product_id = strdup((product_id));
        keyPairQuery_product_id = keyValuePair_create(keyQuery_product_id, valueQuery_product_id);
        list_addElement(localVarQueryParameters,keyPairQuery_product_id);
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

    // query parameters
    char *keyQuery_is_active = NULL;
    char * valueQuery_is_active = NULL;
    keyValuePair_t *keyPairQuery_is_active = 0;
    if (is_active)
    {
        keyQuery_is_active = strdup("is_active");
        valueQuery_is_active = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_is_active, MAX_NUMBER_LENGTH, "%d", *is_active);
        keyPairQuery_is_active = keyValuePair_create(keyQuery_is_active, valueQuery_is_active);
        list_addElement(localVarQueryParameters,keyPairQuery_is_active);
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
        cJSON *ShippingThresholdAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ShippingThresholdAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ShippingThresholdAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ShippingThresholdAPIlocalVarJSON);
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
    if(keyQuery_product_id){
        free(keyQuery_product_id);
        keyQuery_product_id = NULL;
    }
    if(valueQuery_product_id){
        free(valueQuery_product_id);
        valueQuery_product_id = NULL;
    }
    if(keyPairQuery_product_id){
        keyValuePair_free(keyPairQuery_product_id);
        keyPairQuery_product_id = NULL;
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
    if(keyQuery_is_active){
        free(keyQuery_is_active);
        keyQuery_is_active = NULL;
    }
    if(valueQuery_is_active){
        free(valueQuery_is_active);
        valueQuery_is_active = NULL;
    }
    if(keyPairQuery_is_active){
        keyValuePair_free(keyPairQuery_is_active);
        keyPairQuery_is_active = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

shipping_threshold_t*
ShippingThresholdAPI_updateShippingThreshold(apiClient_t *apiClient, char *threshold_id, shipping_threshold_update_t *shipping_threshold_update)
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
    char *localVarPath = strdup("/api/v1/shipping-thresholds/{threshold_id}");

    if(!threshold_id)
        goto end;


    // Path Params
    long sizeOfPathParams_threshold_id = strlen(threshold_id)+3 + sizeof("{ threshold_id }") - 1;
    if(threshold_id == NULL) {
        goto end;
    }
    char* localVarToReplace_threshold_id = malloc(sizeOfPathParams_threshold_id);
    sprintf(localVarToReplace_threshold_id, "{%s}", "threshold_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_threshold_id, threshold_id);



    // Body Param
    cJSON *localVarSingleItemJSON_shipping_threshold_update = NULL;
    if (shipping_threshold_update != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_shipping_threshold_update = shipping_threshold_update_convertToJSON(shipping_threshold_update);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_shipping_threshold_update);
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
    shipping_threshold_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ShippingThresholdAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = shipping_threshold_parseFromJSON(ShippingThresholdAPIlocalVarJSON);
        cJSON_Delete(ShippingThresholdAPIlocalVarJSON);
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
    free(localVarToReplace_threshold_id);
    if (localVarSingleItemJSON_shipping_threshold_update) {
        cJSON_Delete(localVarSingleItemJSON_shipping_threshold_update);
        localVarSingleItemJSON_shipping_threshold_update = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

