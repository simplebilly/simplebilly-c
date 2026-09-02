#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "PriceTierAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


price_tier_t*
PriceTierAPI_createPriceTier(apiClient_t *apiClient, price_tier_create_t *price_tier_create)
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
    char *localVarPath = strdup("/api/v1/price-tiers");





    // Body Param
    cJSON *localVarSingleItemJSON_price_tier_create = NULL;
    if (price_tier_create != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_price_tier_create = price_tier_create_convertToJSON(price_tier_create);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_price_tier_create);
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
    price_tier_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *PriceTierAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = price_tier_parseFromJSON(PriceTierAPIlocalVarJSON);
        cJSON_Delete(PriceTierAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_price_tier_create) {
        cJSON_Delete(localVarSingleItemJSON_price_tier_create);
        localVarSingleItemJSON_price_tier_create = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

void
PriceTierAPI_deletePriceTier(apiClient_t *apiClient, char *price_tier_id)
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
    char *localVarPath = strdup("/api/v1/price-tiers/{price_tier_id}");

    if(!price_tier_id)
        goto end;


    // Path Params
    long sizeOfPathParams_price_tier_id = strlen(price_tier_id)+3 + sizeof("{ price_tier_id }") - 1;
    if(price_tier_id == NULL) {
        goto end;
    }
    char* localVarToReplace_price_tier_id = malloc(sizeOfPathParams_price_tier_id);
    sprintf(localVarToReplace_price_tier_id, "{%s}", "price_tier_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_price_tier_id, price_tier_id);


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
    free(localVarToReplace_price_tier_id);

}

price_tier_t*
PriceTierAPI_getPriceTier(apiClient_t *apiClient, char *price_tier_id)
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
    char *localVarPath = strdup("/api/v1/price-tiers/{price_tier_id}");

    if(!price_tier_id)
        goto end;


    // Path Params
    long sizeOfPathParams_price_tier_id = strlen(price_tier_id)+3 + sizeof("{ price_tier_id }") - 1;
    if(price_tier_id == NULL) {
        goto end;
    }
    char* localVarToReplace_price_tier_id = malloc(sizeOfPathParams_price_tier_id);
    sprintf(localVarToReplace_price_tier_id, "{%s}", "price_tier_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_price_tier_id, price_tier_id);


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
    price_tier_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *PriceTierAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = price_tier_parseFromJSON(PriceTierAPIlocalVarJSON);
        cJSON_Delete(PriceTierAPIlocalVarJSON);
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
    free(localVarToReplace_price_tier_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

resolved_price_response_t*
PriceTierAPI_getResolvedPrice(apiClient_t *apiClient, char *productId, long quantity, char *contactId)
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
    char *localVarPath = strdup("/api/v1/price-tiers/resolved");





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
    char *keyQuery_quantity = NULL;
    char * valueQuery_quantity ;
    keyValuePair_t *keyPairQuery_quantity = 0;
    {
        keyQuery_quantity = strdup("quantity");
        valueQuery_quantity = calloc(1,MAX_NUMBER_LENGTH_LONG);
        snprintf(valueQuery_quantity, MAX_NUMBER_LENGTH_LONG, "%d", quantity);
        keyPairQuery_quantity = keyValuePair_create(keyQuery_quantity, valueQuery_quantity);
        list_addElement(localVarQueryParameters,keyPairQuery_quantity);
    }

    // query parameters
    char *keyQuery_contactId = NULL;
    char * valueQuery_contactId = NULL;
    keyValuePair_t *keyPairQuery_contactId = 0;
    if (contactId)
    {
        keyQuery_contactId = strdup("contactId");
        valueQuery_contactId = strdup((contactId));
        keyPairQuery_contactId = keyValuePair_create(keyQuery_contactId, valueQuery_contactId);
        list_addElement(localVarQueryParameters,keyPairQuery_contactId);
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
    resolved_price_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *PriceTierAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = resolved_price_response_parseFromJSON(PriceTierAPIlocalVarJSON);
        cJSON_Delete(PriceTierAPIlocalVarJSON);
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
    if(keyQuery_quantity){
        free(keyQuery_quantity);
        keyQuery_quantity = NULL;
    }
    if(keyPairQuery_quantity){
        keyValuePair_free(keyPairQuery_quantity);
        keyPairQuery_quantity = NULL;
    }
    if(keyQuery_contactId){
        free(keyQuery_contactId);
        keyQuery_contactId = NULL;
    }
    if(valueQuery_contactId){
        free(valueQuery_contactId);
        valueQuery_contactId = NULL;
    }
    if(keyPairQuery_contactId){
        keyValuePair_free(keyPairQuery_contactId);
        keyPairQuery_contactId = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
PriceTierAPI_listPriceTiers(apiClient_t *apiClient, int *page, int *page_size, char *product_id, char *customer_group_id)
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
    char *localVarPath = strdup("/api/v1/price-tiers/");





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
    char *keyQuery_customer_group_id = NULL;
    char * valueQuery_customer_group_id = NULL;
    keyValuePair_t *keyPairQuery_customer_group_id = 0;
    if (customer_group_id)
    {
        keyQuery_customer_group_id = strdup("customer_group_id");
        valueQuery_customer_group_id = strdup((customer_group_id));
        keyPairQuery_customer_group_id = keyValuePair_create(keyQuery_customer_group_id, valueQuery_customer_group_id);
        list_addElement(localVarQueryParameters,keyPairQuery_customer_group_id);
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
        cJSON *PriceTierAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(PriceTierAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, PriceTierAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( PriceTierAPIlocalVarJSON);
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
    if(keyQuery_customer_group_id){
        free(keyQuery_customer_group_id);
        keyQuery_customer_group_id = NULL;
    }
    if(valueQuery_customer_group_id){
        free(valueQuery_customer_group_id);
        valueQuery_customer_group_id = NULL;
    }
    if(keyPairQuery_customer_group_id){
        keyValuePair_free(keyPairQuery_customer_group_id);
        keyPairQuery_customer_group_id = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

price_tier_t*
PriceTierAPI_updatePriceTier(apiClient_t *apiClient, char *price_tier_id, price_tier_update_t *price_tier_update)
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
    char *localVarPath = strdup("/api/v1/price-tiers/{price_tier_id}");

    if(!price_tier_id)
        goto end;


    // Path Params
    long sizeOfPathParams_price_tier_id = strlen(price_tier_id)+3 + sizeof("{ price_tier_id }") - 1;
    if(price_tier_id == NULL) {
        goto end;
    }
    char* localVarToReplace_price_tier_id = malloc(sizeOfPathParams_price_tier_id);
    sprintf(localVarToReplace_price_tier_id, "{%s}", "price_tier_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_price_tier_id, price_tier_id);



    // Body Param
    cJSON *localVarSingleItemJSON_price_tier_update = NULL;
    if (price_tier_update != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_price_tier_update = price_tier_update_convertToJSON(price_tier_update);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_price_tier_update);
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
    price_tier_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *PriceTierAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = price_tier_parseFromJSON(PriceTierAPIlocalVarJSON);
        cJSON_Delete(PriceTierAPIlocalVarJSON);
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
    free(localVarToReplace_price_tier_id);
    if (localVarSingleItemJSON_price_tier_update) {
        cJSON_Delete(localVarSingleItemJSON_price_tier_update);
        localVarSingleItemJSON_price_tier_update = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

